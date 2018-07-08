#define _CRT_SECURE_NO_WARNINGS
#include	<stdlib.h>
#include	"SDL.h"
#include	<stdio.h>
#include	"main.h"
#include  "status.h"
#include <time.h>
#include "SDL_image.h"
#include "SDL_mixer.h"
#define	GRAVIDADE 0.33f




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

	surface = IMG_Load("fundomapa12.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar paisagem.png");
		SDL_Quit();
		exit(1);
	}
	game->paisa = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("hud.png");
	if (surface == NULL)
	{
		printf("Cannot find hud.png\n\n");
		SDL_Quit();
		exit(1);
	}

	game->hudi = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);




	surface = IMG_Load("inimigo.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar inimigo.png");
		SDL_Quit();
		exit(1);
	}
	game->enemy[0] = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("inimigo2.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar inimigo.png");
		SDL_Quit();
		exit(1);
	}
	game->enemy[1] = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);



	surface = IMG_Load("controles.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar controles.png");
		SDL_Quit();
		exit(8);
	}
	game->fundocontrole = SDL_CreateTextureFromSurface(game->renderer, surface);
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
	surface = IMG_Load("chaomapa1.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar chaomapa1.png");
		SDL_Quit();
		exit(1);
	}
	game->Chao = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("coracao.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar coracao.png");
		SDL_Quit();
		exit(1);
	}
	game->vidasi = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);


	//plataforma
	surface = IMG_Load("plataformamapa1.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar boneco.png");
		SDL_Quit();
		exit(1);
	}
	game->Plataforma = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);

	// estrela
	surface = IMG_Load("estrela.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar estrela.png");
		SDL_Quit();
		exit(11);
	}
	game->estrela = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);


	surface = IMG_Load("raio.png");
	if (surface == NULL) {
		printf("nao foi possivel achar raio.png");
		SDL_Quit();
		exit(22);
	}
	game->tirotext = SDL_CreateTextureFromSurface(game->renderer, surface);
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
	game->fonte3 = TTF_OpenFont("crazy.ttf", 37);
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
	game->statusState = STATUS_STATE_MENU;
	game->scrollx = 0;
	game->sobconti = 0;
	game->tempocred = 0;
	game->score = 0;
	init_status_menu(game);
	game->shot[MAX_TIROS] = NULL;
	game->iden = -1;
	game->encontrado = -1;
	game->tempo=0;
	game->sobsairgo = 0;
	game->sobvoltargo = 0;
	game->heart[1].visivel = 1;
	game->heart[0].visivel = 1;
	game->heart[2].visivel = 1;
	


	//init estrelas
	for (int i = 0; i < 5; i++) {
		game->Star[i].starviva = 1;
		game->Star[i].visivel = 1;
	}
	for (int i = 0; i < 10; i++) {
		game->inimigo[i].vidas = 2;
		game->inimigo[i].vivo = 1;
	}





	//primeiro 
	for (int i = 0; i < 25; i++) {
		if (i == 5) {
			i++;
		}
		if (i == 6) {
			i++;
		}

		game->piso[i].h = 95;
		game->piso[i].w = 160;
		game->piso[i].x = i * 160.0;
		game->piso[i].y = 650;



	}
	//segundo

	game->plataform[1].h = 50;
	game->plataform[1].w = 160;
	game->plataform[1].x = 210;
	game->plataform[1].y = 490;



	game->plataform[2].h = 50;
	game->plataform[2].w = 160;
	game->plataform[2].x = 300;
	game->plataform[2].y = 490;

	game->plataform[3].h = 50;
	game->plataform[3].w = 160;
	game->plataform[3].x = 300 * 2;
	game->plataform[3].y = 490;

	game->plataform[3].h = 50;
	game->plataform[3].w = 160;
	game->plataform[3].x = 300 * 5;
	game->plataform[3].y = 490;


	game->plataform[4].h = 50;
	game->plataform[4].w = 160;
	game->plataform[4].x = 300 * 9;
	game->plataform[4].y = 490;

	game->plataform[5].h = 50;
	game->plataform[5].w = 160;
	game->plataform[5].x = 300 * 9.5;
	game->plataform[5].y = 490;

	





	// terceiro andar
	game->plataform[9].h = 50;
	game->plataform[9].w = 160;
	game->plataform[9].x = 150 * 4;
	game->plataform[9].y = 330;

	game->plataform[10].h = 50;
	game->plataform[10].w = 160;
	game->plataform[10].x = 160 * 7;
	game->plataform[10].y = 330;

	game->plataform[11].h = 50;
	game->plataform[11].w = 160;
	game->plataform[11].x = 160 * 11;
	game->plataform[11].y = 330;

	game->plataform[12].h = 50;
	game->plataform[12].w = 160;
	game->plataform[12].x = 160 * 12;
	game->plataform[12].y = 330;

	game->plataform[13].h = 50;
	game->plataform[13].w = 160;
	game->plataform[13].x = 160 * 13;
	game->plataform[13].y = 330;

	game->plataform[14].h = 50;
	game->plataform[14].w = 160;
	game->plataform[14].x = 160 * 14;
	game->plataform[14].y = 330;
	int j = 0;
	for (int i = 15; i < 50; i++) {
		
		game->plataform[i].h = 50;
		game->plataform[i].w = 160;
		game->plataform[i].x = j *160;
		game->plataform[i].y = 15;
		j++;
	
}


		game->Star[1].x = 920;
		game->Star[1].y = 165;
		game->Star[1].w = 40;
		game->Star[1].h = 40;
		game->Star[1].mode = 2;
		game->Star[1].baseX = game->Star[1].x;
		game->Star[1].baseY = game->Star[1].y;


		game->Star[2].x = 2055;
		game->Star[2].y = 270;
		game->Star[2].w = 40;
		game->Star[2].h = 40;
		game->Star[2].mode = 0;
		game->Star[2].baseX = game->Star[1].x;
		game->Star[2].baseY = game->Star[1].y;




		//inimigo

		game->inimigo[0].xe = 2180;
		game->inimigo[0].ye = 250;
		game->inimigo[0].we = 40;
		game->inimigo[0].he = 60;
		game->inimigo[0].baseX = game->inimigo[0].xe;
		game->inimigo[0].baseY = game->inimigo[0].ye;
		game->inimigo[0].phase = 1;
		game->inimigo[0].mode = 0;
		game->inimigo[0].aocontrario = 0;
		game->inimigo[0].dxe = 10;
		game->inimigo[0].mov = 0;

		game->inimigo[1].xe = 1555;
		game->inimigo[1].ye = 420;
		game->inimigo[1].we = 40;
		game->inimigo[1].he = 60;
		game->inimigo[1].baseX = game->inimigo[1].xe;
		game->inimigo[1].baseY = game->inimigo[1].ye;
		game->inimigo[1].phase = 1;
		game->inimigo[1].mode = 0;
		game->inimigo[1].aocontrario = 0;
		game->inimigo[1].dxe = 10;
		game->inimigo[1].mov = 0;


		game->inimigo[2].xe = 1820;
		game->inimigo[2].ye = 250;
		game->inimigo[2].we = 40;
		game->inimigo[2].he = 60;
		game->inimigo[2].baseX = game->inimigo[2].xe;
		game->inimigo[2].baseY = game->inimigo[2].ye;
		game->inimigo[2].phase = 2;
		game->inimigo[2].mode = 0;
		game->inimigo[2].aocontrario = 0;
		game->inimigo[2].dxe = 10;
		game->inimigo[2].mov = 0;

}




void process(GameState *game) {
	//tempo
	game->tempo++;

	if (game->statusState == STATUS_STATE_GAME)
	{

		//movimentação do personagem
		Man *man = &game->man;
		man->x += man->dx;
		man->y += man->dy;

		if (man->dx != 0 && man->noChao && !man->dimi) {
			if (game->tempo % 10 == 0) {
				if (man->mov == 0) {
					man->mov = 1;
				}
				
				else {
					man->mov = 0;
				}
			}

		}


		man->dy += GRAVIDADE * 1.2;


	}
	game->scrollx = -game->man.x + 300;
	if (game->scrollx > 0)
		game->scrollx = 0;

	if (game->man.y > 850) {
		game->man.vidas = 0;
		
	}
	if (game->man.vidas == 0) {
		SDL_Delay(150);
		game->statusState = STATUS_STATE_GAMEOVER;
	}

	
	if (game->statusState == STATUS_STATE_GAME) {
		for (int i = 0; i < 5; i++)
		{
		

			if (game->inimigo[i].mode == 0) {

				if(i==0){
					game->inimigo[i].xe = game->inimigo[i].baseX + sinf(game->inimigo[i].phase + game->tempo*0.07f) * 75;

				if (game->inimigo[i].xe > 1600) {

					game->inimigo[i].aocontrario = 0;
				}
				if (game->inimigo[i].xe < 1530) {
					game->inimigo[i].aocontrario = 1;
				}
							
			}


				if (i == 2) {

					game->inimigo[i].xe = game->inimigo[i].baseX + sinf(game->inimigo[i].phase + game->tempo*0.07f) * 65;

					if (game->inimigo[i].xe > 1600) {

						game->inimigo[i].aocontrario = 0;
					}
					if (game->inimigo[i].xe < 1530) {
						game->inimigo[i].aocontrario = 1;
					}
				}

					else {

						game->inimigo[i].xe = game->inimigo[i].baseX + sinf(game->inimigo[i].phase + game->tempo*0.06f) * 65;

						if (game->inimigo[i].xe > 1600) {

							game->inimigo[i].aocontrario = 0;
						}
						if (game->inimigo[i].xe < 1530) {
							game->inimigo[i].aocontrario = 1;
						}

					
				}
			}
			
		}

		for (int i = 0; i < 5; i++) {
			if (game->Star[i].mode == 2) {
				game->Star[i].y = game->Star[i].baseY + cosf(1 + game->tempo*0.06f) * 75;
			}
		}


	}
	
	for (int i = 0; i < 5; i++) {
		
		if (game->inimigo[i].dxe == 10)
		{
			if (game->tempo % 20 == 0) {
				if (game->inimigo[i].mov == 0) {
					game->inimigo[i].mov = 1;
				}
				else {
					game->inimigo[i].mov = 0;
				}
			}
		}
	}
	
	if (game->man.vidas == 3) {
		game->heart[0].visivel = 1;
		game->heart[1].visivel = 1;
		game->heart[2].visivel = 1;
	}
	if (game->man.vidas == 2) {
		game->heart[0].visivel = 1;
		game->heart[1].visivel = 1;
		game->heart[2].visivel = 0;
	}
	if (game->man.vidas == 1) {
		game->heart[0].visivel = 1;
		game->heart[1].visivel = 0;
		game->heart[2].visivel = 0;
	}
	if (game->man.vidas == 0) {
		game->heart[0].visivel = 0;
		game->heart[1].visivel = 0;
		game->heart[2].visivel = 0;
	}




}

int collide2d(float x1, float y1, float x2, float y2, float wt1, float ht1, float wt2, float ht2)
{
	return (!((x1 > (x2 + wt2)) || (x2 > (x1 + wt1)) || (y1 > (y2 + ht2)) || (y2 > (y1 + ht1))));
}



void colisaoDetect(GameState *game) {

	//Check for collision with estrela
	for (int i = 0; i < 5; i++)
	{
		if (collide2d(game->man.x, game->man.y, game->Star[i].x, game->Star[i].y, 74, 94, 30, 40))
		{
			if (game->Star[i].starviva==1)
			{
				game->score += 20;
				game->Star[i].starviva = 0;
				game->Star[i].visivel = 0;
			}
			break;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (collide2d(game->man.x, game->man.y, game->inimigo[i].xe, game->inimigo[i].ye, 74, 94, 35, 55))
		{
			if (game->inimigo[i].vivo == 1)
			{	
				game->inimigo[i].vivo = 0;
				game->man.vidas --;
				


			}
			break;
		}
	}



	// checar colisao com algum piso
	for (int i = 0; i < 100; i++) {
		float mw = 54, mh = 74;
		float mx = game->man.x, my = game->man.y;
		float bx = game->piso[i].x - 2, by = game->piso[i].y - 2, bw = game->piso[i].w, bh = game->piso[i].h;
		float px = game->plataform[i].x, py = game->plataform[i].y-7, pw = game->plataform[i].w, ph = game->plataform[i].h+25;
		if (mx + mh / 2 > bx && mx + mw / 2 < bx + bw) {
			//esta batendo em cima?
			if (my < by + bh && my>by && game->man.dy < 0) {

				//correct y
				game->man.y = by + bh;
				my = by + bh;

				//batendo a cabeça
				game->man.dy = 0;
				game->man.noChao = 0;
			}
		}
		if (mx + mh / 2 > px && mx + mw / 2 < px + pw) {
			//esta batendo em cima?
			if (my < py + ph && my>py && game->man.dy < 0) {

				//correct y
				game->man.y = py + ph;
				my = py + ph;

				//batendo a cabeça

				game->man.dy = 0;
				game->man.noChao = 0;

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

		if (mx + mw > px && mx < px + pw) {
			// aterrissando?
		
			if (my + ph > py && my < py && game->man.dy >0) {
				//correct y
				game->man.y = py - mh;
				my = py - mh;

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

			if (my + mh > py && my < py + ph) {
				//encostando no lado direito
				if (mx < px + pw && mx + mw >px + pw && game->man.dx < 0) {
					//correct x
					game->man.x = px + pw;
					mx = px + pw;

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
			else if (mx + mw > px && mx < px && game->man.dx >0) {
				// correct x
				game->man.x = px - mw;
				mx = px - mw;

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
			//AÇOES NO MENU PRINCIPAL
			
	
			if (game->statusState == STATUS_STATE_MENU && event.motion.x >= 60 && event.motion.x <= 60 + game->novow+50 && event.motion.y >= 350 && event.motion.y <= 350 + game->novoh+20) {
				game->sobnovo ++;
			}
			else {
				game->sobnovo = 0;

			}
			if (game->statusState == STATUS_STATE_MENU && event.motion.x >= 60 && event.motion.x <= 60 + game->configw+50 && event.motion.y >= 430 && event.motion.y <= 430 + game->configh+20) {
				game->sobconfig ++;
			}
			else {
				game->sobconfig = 0;

			}

			if ( game->statusState== STATUS_STATE_MENU && event.motion.x >= 60 && event.motion.x <= 60 + game->sairw + 50 && event.motion.y >= 590 && event.motion.y <= 590 + game->sairh + 20) {
				game->sobsair++;
			}
			else {
				game->sobsair = 0;

			}

			if (game->statusState == STATUS_STATE_MENU && event.motion.x >= 60 && event.motion.x <= 60 + game->credw +50 && event.motion.y >= 510 && event.motion.y <= 510 + game->credh+20) {
				game->sobcredi ++;
			}
			else {
				game->sobcredi = 0;

			}
			
			//AÇOES NO MENU DE CREDITOS

			if (game->statusState == STATUS_STATE_CREDITS && event.motion.x >= 80 && event.motion.x <= 80 + game->voltarmenuw && event.motion.y >= 350 && event.motion.y <= 350 + game->voltarmenuh) {
				game->sobvoltar ++;
			}
			else {
				game->sobvoltar = 0;

			}


			// menu game over

			if (game->statusState == STATUS_STATE_GAMEOVER && event.motion.x >= 120 && event.motion.x <= 220 && event.motion.y >= 560 && event.motion.y <= 660) {
				game->sobvoltargo ++;
			}
			else {
				game->sobvoltargo = 0;
			}

			if (game->statusState == STATUS_STATE_GAMEOVER && event.motion.x >= 1040 && event.motion.x <= 1140 && event.motion.y >= 560 && event.motion.y <= 660) {
				game->sobsairgo ++;
			}
			else
			{
				game->sobsairgo = 0;
			}
			



			break;
		}
		case SDL_MOUSEBUTTONDOWN:
			if (game->statusState == STATUS_STATE_MENU) {
				if (game->sobnovo >= 1) {
					Mix_PlayChannel(-1, game->menusom, 0);

					game->statusState = STATUS_STATE_CONTROLES;
					game->man.vidas = 3;
				}


				if (game->sobcredi >= 1) {
					Mix_PlayChannel(-1, game->menusom, 0);
					SDL_Delay(80);
					init_status_cred(game);
					game->statusState = STATUS_STATE_CREDITS;
				}

				if (game->sobsair >= 1 ) {
					Mix_PlayChannel(-1, game->menusom, 0);
					SDL_Delay(80);
					done = 1;
				}
			}
				if (game->statusState == STATUS_STATE_CREDITS && game->sobvoltar >= 1) {
					Mix_PlayChannel(-1, game->menusom, 0);
					SDL_Delay(80);
					game->statusState = STATUS_STATE_MENU;
				}
			
				if (game->statusState == STATUS_STATE_GAMEOVER && game->sobvoltargo >= 1) {
						Mix_PlayChannel(-1, game->menusom, 0);
						SDL_Delay(80);
						
						game->statusState = STATUS_STATE_MENU;
					}
					if  (game->statusState == STATUS_STATE_GAMEOVER && game->sobsairgo >= 1) {
						Mix_PlayChannel(-1, game->menusom, 0);
						SDL_Delay(100);
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
				if (game->man.noChao==1)
				{
					game->man.dy = -10;
					game->man.noChao = 0;
					game->score++;
					

				}
				break;
				game->man.atirando = 0;
			case SDLK_SPACE:
				
				if (game->statusState == STATUS_STATE_GAME) {
					game->man.atirando = 1;
					
				}
				break;
				
			}
		case SDLK_RETURN:
			if (game->statusState == STATUS_STATE_CONTROLES)
				game->statusState = STATUS_STATE_GAME;
			break;

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

void addtiro(GameState *game) {
	
	
	if (game->man.atirando == 1) {
		for (int i = 0; i < MAX_TIROS; i++) {
			if (game->shot[i] == NULL) {
				game->encontrado = 1;
				break;
			}
		}
		if (game->encontrado >= 0) {
			int i = game->encontrado;
			game->shot[i] = malloc(sizeof(Tiro));
			game->shot[i]->xt = game->man.x + 80;
			game->shot[i]->yt = game->man.y + 30;
			game->shot[i]->dxt = 3;
		}

	}

	for (int k = 0; k < MAX_TIROS; k++) {
		if (game->shot[k]) {
			game->shot[k]->xt += game->shot[k]->dxt;
			if (game->shot[k]->xt <= 0 || game->shot[k]->xt >= 1200) {
				game->shot[k]->fimtiro = 1;
				game->iden = k;
			}

		}
	}

}

void removetiro(GameState *game) {
	int i = game->iden;
	if (game->shot[i]->fimtiro == 1) {
		free(game->shot[i]);
		game->shot[i] = NULL;


	}
}

void doRender(SDL_Renderer *renderer, GameState *game)
{

	

	if (game->statusState == STATUS_STATE_MENU) {
		draw_status_menu(game);
	}

	else if (game->statusState == STATUS_STATE_GAMEOVER) {
		init_status_over(game);
		draw_status_over(game);
	}

	else if (game->statusState == STATUS_STATE_CREDITS) {
		draw_status_cred(game);
	}
	else if (game->statusState == STATUS_STATE_CONTROLES) {
		SDL_Rect fundoconRect = { 0,0,1280,700 };
		SDL_RenderCopy(renderer, game->fundocontrole, NULL, &fundoconRect);
		game->tempocred++;
		if (game->tempocred == 200)
			game->statusState = STATUS_STATE_GAME;


	}

	else if (game->statusState == STATUS_STATE_GAME) {


		

		SDL_DestroyTexture(game->fundocontrole);
		game->fundocontrole = NULL;

	

		// drawing color azul
		SDL_SetRenderDrawColor(renderer, 128, 128, 255, 255);

		// limpa a janela
		SDL_RenderClear(renderer);

		// estabelece a cor branca para desenhar
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		//fundo
		SDL_Rect paisage = { 0, 0,1280,700};
		SDL_RenderCopy(renderer, game->paisa, NULL, &paisage);

		char pontuaçao[100] = "";
		sprintf(pontuaçao, "SCORE:   %d", (int)game->score);
		SDL_Color white = { 255,255,255,255 };

		SDL_Surface *pontos = TTF_RenderText_Solid(game->fonte2, pontuaçao, white);
		game->scorei = SDL_CreateTextureFromSurface(game->renderer, pontos);
		SDL_FreeSurface(pontos);

		SDL_Surface *vidas = TTF_RenderText_Solid(game->fonte2,"Vidas: ", white);
		game->vidasti = SDL_CreateTextureFromSurface(game->renderer, vidas);
		SDL_FreeSurface(vidas);



		//piso
		for (int i = 0; i < 75; i++)
		{

			SDL_Rect pisoRect = { game->scrollx + game->piso[i].x*1.0f, game->piso[i].y*1.0f,game->piso[i].w * 1.0f, game->piso[i].h*1.0f };
			SDL_RenderCopy(renderer, game->Chao, NULL, &pisoRect);

			SDL_Rect platRect = { game->scrollx + game->plataform[i].x*1.0f, game->plataform[i].y*1.0f,game->plataform[i].w+10 * 1.0f, game->plataform[i].h+15*1.0f };
			SDL_RenderCopy(renderer, game->Plataforma, NULL, &platRect);


			if (game->Star[i].visivel == 1) {
				SDL_Rect starRect = { game->scrollx + game->Star[i].x*1.0f, game->Star[i].y*1.0f,game->Star[i].w, game->Star[i].h };
				SDL_RenderCopy(renderer, game->estrela, NULL, &starRect);
			}

			if (game->inimigo[i].vivo == 1) {
				SDL_Rect inimigoRect = { game->scrollx + game->inimigo[i].xe*1.0f, game->inimigo[i].ye*1.0f,40,70 };
				SDL_RenderCopyEx(renderer, game->enemy[game->inimigo[1].mov], NULL, &inimigoRect, 0, NULL, game->inimigo[i].aocontrario == 0);
			}

			SDL_Rect hudRect = { 0,0,1280,80 };
			SDL_RenderCopy(renderer, game->hudi, NULL, &hudRect);
			for (int i = 0; i < 3; i++) {
				if (game->heart[i].visivel == 1) {

					if (i==0) {
						SDL_Rect heartRect = { 220,28,50,50 };
						SDL_RenderCopy(renderer, game->vidasi, NULL, &heartRect);
					}
					if (i == 1) {
						SDL_Rect heartRect = { 280,28,50,50 };
						SDL_RenderCopy(renderer, game->vidasi, NULL, &heartRect);

					}
					if (i == 2) {
						SDL_Rect heartRect = { 330,28,50,50 };
						SDL_RenderCopy(renderer, game->vidasi, NULL, &heartRect);

					}

				}
			}
			
			SDL_Rect pontosRect = { 1000,15,160,65 };
			SDL_RenderCopy(renderer, game->scorei, NULL, &pontosRect);

			
			

		}


		SDL_Rect vidastRect = { 50,15,160,65 };
		SDL_RenderCopy(renderer, game->vidasti, NULL, &vidastRect);


		// desenha um retangulo no personagem
		SDL_Rect rect = { game->scrollx + game->man.x, game->man.y,55,85 };
		SDL_RenderCopyEx(renderer, game->Boneco[game->man.mov], NULL, &rect, 0, NULL, (game->man.aoContrario == 1));



		//desenha retangulo tiro
			for (int i = 0; i < MAX_TIROS; i++) if(game->shot[i]){

				SDL_Rect laser = { game->man.x + 40,game->man.y + 50,50,50 };
				SDL_RenderCopy(renderer, game->tirotext, NULL, &laser);
			

		}

		

		

		
		
		
		
			
		


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

	window = SDL_CreateWindow("Arret", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,1280, 700, SDL_WINDOW_SHOWN);

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

	

	SDL_DestroyTexture(gameState.hudi);
	SDL_DestroyTexture(gameState.vidasi);
	SDL_DestroyTexture(gameState.vidasti);
	SDL_DestroyTexture(gameState.enemy[0]);
	SDL_DestroyTexture(gameState.enemy[1]);

	SDL_DestroyTexture(gameState.paisa);
	SDL_DestroyTexture(gameState.Boneco[0]);
	SDL_DestroyTexture(gameState.Boneco[1]);
	SDL_DestroyTexture(gameState.Chao);
	SDL_DestroyTexture(gameState.estrela);
	SDL_DestroyTexture(gameState.scorei);
	TTF_CloseFont(gameState.fonte);
	TTF_CloseFont(gameState.fonte2);
	TTF_CloseFont(gameState.fonte3);
	TTF_CloseFont(gameState.fonte4);
		SDL_DestroyTexture(gameState.tirotext);
	

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
