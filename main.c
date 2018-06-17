#include	<stdlib.h>
#include	"SDL.h"
#include	<stdio.h>
#include	"main.h"
#include  "satus.h"
#include <time.h>
#include "SDL_image.h"
#include "SDL_mixer.h"
#define	GRAVIDADE 0.2f




void LoadGame(GameState *game) {
	//carregar som

	game->menusom = Mix_LoadWAV("menusom.wav");
	if (!game->menusom) {
		printf("nao foi possivel encontrar a musica \n");
		exit(20);
	}
	else {
		Mix_VolumeChunk(game->menusom, 32);
	}



	// carregar imagens

	SDL_Surface *surface = NULL;

	surface = IMG_Load("paisagem.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar paisagem.png");
		SDL_Quit();
		exit(1);
	}
	game->paisa = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);

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
	game->Chao = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);
	//iniciando o tempo
	game->tempo = 0;

	//iniciando a fonte
	game->fonte = TTF_OpenFont("octagen.ttf", 105);
	if (!game->fonte) {
		printf("n foi possivel encontrar a fonte \n");
		exit(1);
	}

	game->fonte2 = TTF_OpenFont("crazy.ttf", 65);
	if (!game->fonte2) {
		printf("n foi possivel encontrar a fonte \n");
		exit(1);
	}
	game->fonte3 = TTF_OpenFont("crazy.ttf",37);
	if (!game->fonte3) {
		printf("n foi possivel encontrar a fonte \n");
		exit(1);
	}
	game->fonte4 = TTF_OpenFont("heartt.ttf", 50);
	if (!game->fonte4) {
		printf("n foi possivel encontrar a fonte \n");
		exit(1);
	}

	game->label = NULL;

	//carregar musicas 
	

	// iniciando personagem
	game->man.x = 20;
	game->man.y = 200;
	game->man.dx = 0;
	game->man.dy = 0;
	game->man.noChao = 0;
	game->man.mov = 0;
	game->man.aoContrario = 0;
	game->man.dimi = 0;
	game->man.vidas = 3;
	game->statusState = STATUS_STATE_VIDAS;
	game->scrollx = 0;
	game->sobconti = 0;
	init_status_vidas(game);

	//init piso
	for (int i = 0; i < 50; i++) {
		game->piso[i].h = 95;
		game->piso[i].w = 160;
		game->piso[i].x = i * 160.0;
		game->piso[i].y = 355;
	}
		game->piso[5].h = 70;
		game->piso[5].w = 160;
		game->piso[5].x =100;
		game->piso[5].y = 200;
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
			if (game->tempo % 8 == 0) {
				if (man->mov == 0) {
					man->mov = 1;
				}
				else {
					man->mov = 0;
				}
			}

		}
	

		man->dy += GRAVIDADE * 1.1;

	}
	game->scrollx = -game->man.x+300;
	if (game->scrollx > 0)
		game->scrollx = 0;

}
void colisaoDetect(GameState *game) {

	// checar colisao com algum piso
	for (int i = 0; i < 100; i++) {
		float mw = 53, mh = 52;
		float mx = game->man.x, my = game->man.y;
		float bx = game->piso[i].x-3, by = game->piso[i].y, bw = game->piso[i].w-3, bh = game->piso[i].h;

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

		case SDL_MOUSEMOTION:
		{
			if (game->tempo < 500 && event.motion.x >= 35 && event.motion.x <= 35 + game->contiw && event.motion.y >= 235 && event.motion.y <= 235 + game->contih) {
				game->sobconti = 1;
			}
			else {
				game->sobconti = 0;

			}
			if (game->tempo < 500 && event.motion.x >= 35 && event.motion.x <= 35 + game->novow && event.motion.y >= 270 && event.motion.y <= 270 + game->novoh) {
				game->sobnovo = 1;
			}
			else {
				game->sobnovo = 0;

			}
			if (game->tempo < 500 && event.motion.x >= 35 && event.motion.x <= 35 + game->configw && event.motion.y >= 305 && event.motion.y <= 305 + game->configh) {
				game->sobconfig = 1;
			}
			else {
				game->sobconfig = 0;

			}
			if (game->tempo < 500 && event.motion.x >= 35 && event.motion.x <= 35 + game->sairw && event.motion.y >= 340 && event.motion.y <= 340 + game->sairh) {
				game->sobsair = 1;
			}
			else {
				game->sobsair = 0;

			}

			break;
		}
		case SDL_MOUSEBUTTONDOWN:
			if (game->sobconti == 1) {
				game->tempo = 498;
				Mix_PlayChannel(-1, game->menusom, 0);
			}
		
			else if (game->sobsair == 1) {
				Mix_PlayChannel(-1, game->menusom, 0);
				SDL_Delay(80);
				done = 1;
			}
			break;
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
					game->man.dy = -7;
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
		game->man.dy -= 0.06f;


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

		//fundo
		SDL_Rect paisage = { 0, 0,800,600 };
		SDL_RenderCopy(renderer, game->paisa, NULL, &paisage);

		//piso
		for (int i = 0; i <50; i++)
		{

			SDL_Rect pisoRect = { game->scrollx+game->piso[i].x*1.0f, game->piso[i].y*1.0f,game->piso[i].w * 1.0f, game->piso[i].h*1.0f};
			SDL_RenderCopy(renderer, game->Chao, NULL, &pisoRect);
		}
		

		// desenha um retangulo no personagem
		SDL_Rect rect = { game->scrollx + game->man.x, game->man.y,50,50};
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
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	window = SDL_CreateWindow("Arret", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 400, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	//fonte
	TTF_Init();


	gameState.renderer = renderer;

	LoadGame(&gameState);

	Mix_Music *musicafundo;
	musicafundo = Mix_LoadMUS("awesomeness.wav");
	if (!musicafundo) {
		printf("nao foi possivel encontrar a musica \n");
		exit(20);
	}

	// Janela aberta: Loop
	Mix_PlayMusic(musicafundo, -1);
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
	SDL_DestroyTexture(gameState.paisa);
	SDL_DestroyTexture(gameState.Boneco[0]);
	SDL_DestroyTexture(gameState.Boneco[1]);
	SDL_DestroyTexture(gameState.Chao);

	if (gameState.label != NULL)
		SDL_DestroyTexture(gameState.label);
	TTF_CloseFont(gameState.fonte);
	//fecha e destroy a janela
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	Mix_FreeMusic(musicafundo);
	Mix_FreeChunk(gameState.menusom);
	Mix_CloseAudio();
	//Fecha o TTF

	TTF_Quit();
	//limpa
	SDL_Quit();
	return 0;
}


