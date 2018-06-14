#include	<stdlib.h>
#include	"SDL.h"
#include	<stdio.h>
#include	"main.h"
#include  "satus.h"
#include <time.h>
#include "SDL_image.h"
#define	GRAVIDADE 0.20f




void LoadGame(GameState *game) {
	// carregar imagens


	SDL_Surface *surface = NULL;
	

		//boneco
		surface = IMG_Load("personagem.png");
		if (surface == NULL) {
			printf("Nao foi possivel achar boneco.png");
			SDL_Quit();
			exit(1);
		}
		game->Boneco[0] = SDL_CreateTextureFromSurface(game->renderer, surface);
		SDL_FreeSurface(surface);
		// boneco 2
		surface = IMG_Load("boneco2.png");
		if (surface == NULL) {
			printf("Nao foi possivel achar boneco.png");
			SDL_Quit();
			exit(1);
		}
		game->Boneco[1] = SDL_CreateTextureFromSurface(game->renderer, surface);
		SDL_FreeSurface(surface);
		//piso
		surface = IMG_Load("piso.png");
		if (surface == NULL) {
			printf("Nao foi possivel achar piso.png");
			SDL_Quit();
			exit(1);
		}
		game->Chao[0] = SDL_CreateTextureFromSurface(game->renderer, surface);
		SDL_FreeSurface(surface);
		//iniciando o tempo
		game->tempo = 0;

		//iniciando a fonte
		game->fonte = TTF_OpenFont("crazy.ttf", 35);
		if (!game->fonte) {
			printf("n foi possivel encontrar a fonte \n");
			exit(1);
		}

		game->label = NULL;


		// iniciando personagem
		game->man.x = 50;
		game->man.y = 200;
		game->man.dx = 0;
		game->man.dy = 0;
		game->man.noChao = 0;
		game->man.mov = 0;
		game->man.aoContrario = 0;
		game->man.dimi = 0;
		game->man.vidas = 3;
		game->statusState = STATUS_STATE_VIDAS;


		init_status_vidas(game);

		//init piso
		for (int i = 0; i < 5; i++) {
			game->piso[i].h = 90;
			game->piso[i].w = 160;
			game->piso[i].x = i * 160;
			game->piso[i].y = 350;
		}

	}

void process(GameState *game) {

	//tempo
	game->tempo++;

	if (game->tempo > 500) {
		shutdown_status_vidas(game);
		game->statusState = STATUS_STATE_GAME;
	}	
	if (game->statusState == STATUS_STATE_GAME) 
	{

		//movimentação do personagem
		Man *man = &game->man;
		man->x += man->dx;
		man->y += man->dy;

		if (man->dx != 0 && man->noChao && !man->dimi) {
			if (game->tempo % 20 == 0) {
				if (man->mov == 0) {
					man->mov = 1;
				}
				else {
					man->mov = 1;
				}
			}

		}


		man->dy += GRAVIDADE;
		
	}


}
void colisaoDetect(GameState *game) {

	// checar colisao com algum piso
	for (int i = 0; i < 100; i++) {
		float mw = 48, mh = 48;
		float mx = game->man.x, my = game->man.y;
		float bx = game->piso[i].x, by = game->piso[i].y, bw = game->piso[i].w, bh = game->piso[i].h;

		if (mx + mh / 2 > bx && mx + mw / 2 < bx + bw) {
			//esta batendo em cima?
			if (my < by + bh && my>by && game->man.dy < 0) {

				//correct y
				game->man.y = by + bh;
				my = by + bh;

				//batendo a cabeça
				game->man.dy = 0;
				game->man.noChao = 1;
			}
		}
		if (mx + mw > bx && mx < bx + bw) {
			// aterrissando?
			if (my + bh > by && my < by && game->man.dy >0) {
				//correct y
				game->man.y = by - mh;
				my = by - mh;

				// se aterrissar, para o movimento
				game->man.dy = 0;
				game->man.noChao = 1;
			}
		}


		if (my + mh > by && my < by + bh) {
			//encostando no lado direito
			if (mx < bx + bw && mx + mw >bx + bw && game->man.dx < 0) {
				//correct x
				game->man.x = bx + bw;
				mx = bx + bw;

				game->man.dx = 0;
			}
			//encostando no lado esquerdo

			else if (mx + mw > bx && mx < bx && game->man.dx >0) {
				// correct x
				game->man.x = bx - mw;
				mx = bx - mw;

				game->man.dx = 0;
			}
		}
	}
	
}

int processEvents(SDL_Window *window, GameState *game) {
	SDL_Event event;
	int done = 0;

	while (SDL_PollEvent(&event)) 
	{
		switch (event.type) {
		case SDL_WINDOWEVENT_CLOSE: 
		{
			if (window) 
			{
				SDL_DestroyWindow(window);
				window = NULL;
				done = 1;
			}
		}
									break;
		case SDL_KEYDOWN: 
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				done = 1;
				break;

			case SDLK_UP:
				if (game->man.noChao)
				{
					game->man.dy = -6;
					game->man.noChao = 0;

				}
				break;
			}
		}
						  break;

		case SDL_QUIT:
			//fecha o jogo
			done = 1;
			break;
		}
	}
	// pulo mais forte
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_UP])
	{
		game->man.dy -= 0.04f;
		

	}
	//ANDANDO
	if (state[SDL_SCANCODE_LEFT])
	{
		game->man.dx -= 0.5;
		if (game->man.dx< -6)
		{
			game->man.dx = -6;

		}
		game->man.aoContrario = 1;
		game->man.dimi = 0;
	}
	else if (state[SDL_SCANCODE_RIGHT]) {
		game->man.dx += 0.5;
		if (game->man.dx > 6) {
			game->man.dx = 6;
		}
		game->man.aoContrario = 0;
		game->man.dimi = 0;
	}
	else {
		game->man.mov = 0;
		game->man.dx *= 0.8f;
		game->man.dimi = 1;
		if (fabsf(game->man.dx) < 0.1f) {
			game->man.dx = 0;
		}
	}


	return done;
}


void doRender(SDL_Renderer *renderer, GameState *game)
{
	if (game->statusState == STATUS_STATE_VIDAS) {
		draw_status_vidas(game);
	}
	else if (game->statusState == STATUS_STATE_GAME) {


		// drawing color azul
		SDL_SetRenderDrawColor(renderer, 128, 128, 255, 255);

		// limpa a janela
		SDL_RenderClear(renderer);

		// estabelece a cor branca para desenhar
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		//piso
		for (int i = 0; i < 100; i++)
		{

			SDL_Rect pisoRect = { game->piso[i].x, game->piso[i].y,game->piso[i].w, game->piso[i].h };
			SDL_RenderCopy(renderer, game->Chao[0], NULL, &pisoRect);
		}

		// desenha um retangulo no personagem
		SDL_Rect rect = { game->man.x, game->man.y,70,70 };
		SDL_RenderCopyEx(renderer, game->Boneco[game->man.mov], NULL, &rect, 0, NULL, (game->man.aoContrario == 1));


	}
	
	// mostra a oq foi desenhado
	SDL_RenderPresent(renderer);
}




int main(int args, char *argsv[])
{
	GameState gameState;
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	


	SDL_Init(SDL_INIT_EVERYTHING);


	window = SDL_CreateWindow("Arret", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 400, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	//fonte
	TTF_Init();


	gameState.renderer = renderer;

	LoadGame(&gameState);



	// Janela aberta: Loop

	int done = 0;
	//Loop
	while (!done)
	{
		//checar eventos
		done = processEvents(window, &gameState);

		//colisão
		process(&gameState);
		colisaoDetect(&gameState);

		// Render display
		doRender(renderer, &gameState);




	}
	// limpa a memoria
	SDL_DestroyTexture(gameState.Boneco[0]);
	SDL_DestroyTexture(gameState.Boneco[1]);
	SDL_DestroyTexture(gameState.Chao[0]);

	if (gameState.label != NULL)
		SDL_DestroyTexture(gameState.label);
	TTF_CloseFont(gameState.fonte);

	//fecha e destroy a janela
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	//Fecha o TTF

	TTF_Quit();
	//limpa
	SDL_Quit();
	return 0;
}


