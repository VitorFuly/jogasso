#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>


#include	<stdlib.h>
#include	<stdio.h>
#include	"main.h"
#include  "status.h"
#include <time.h>
#include <math.h>
#define	GRAVIDADE 0.33f

typedef struct {
	float xt, yt, dxt, fimtiro, usada;
}Tiro;
Tiro *shot[MAX_TIROS] = { NULL };



void LoadGame(GameState *game) {
	//carregar som



	game->menusom = Mix_LoadWAV("menusom.wav");
	if (game->menusom==NULL) {
		printf("nao foi possivel encontrar a musica \n");
		exit(20);
	}
	else {
		Mix_VolumeChunk(game->menusom, 32);
	}

	game->hit = Mix_LoadWAV("Right_Hook-SoundBible.com-1406389182.wav");
	if (game->hit==NULL) {
		printf("nao foi possivel encontrar a musica \n");
		exit(77);
	}
	else {
		Mix_VolumeChunk(game->hit, 32);
	}



	// carregar imagens





	game->musicafundo = Mix_LoadMUS("Binrpilot_-_01_-_Goof.mp3");
	if (game->musicafundo == NULL) {
		printf("nao foi possivel encontrar a musica \n");
		exit(101);
	}


	// Janela aberta: Loop
	Mix_PlayMusic(game->musicafundo, -1);




	SDL_Surface *surface = NULL;



	surface = IMG_Load("corda2.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar corda2.png");
		SDL_Quit();
		exit(987);
	}
	game->corda = SDL_CreateTextureFromSurface(game->renderer, surface);

	SDL_FreeSurface(surface);



	surface = IMG_Load("placa5.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar placa5.png");
		SDL_Quit();
		exit(955);
	}
	game->placagas = SDL_CreateTextureFromSurface(game->renderer, surface);

	SDL_FreeSurface(surface);



	surface= IMG_Load("ceu_estrelado.png");

	if (surface == NULL) {
		printf("Nao foi possivel achar ceu_estrelado.jpg");
		SDL_Quit();
		exit(987);
	}
	game->historia = SDL_CreateTextureFromSurface(game->renderer, surface);

	SDL_FreeSurface(surface);



	surface = IMG_Load("placa3.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar logo.png");
		SDL_Quit();
		exit(444444);
	}
	game->placacorda = SDL_CreateTextureFromSurface(game->renderer, surface);

	SDL_FreeSurface(surface);



	surface = IMG_Load("nave.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar logo.png");
		SDL_Quit();
		exit(3);
	}
	game->navei = SDL_CreateTextureFromSurface(game->renderer, surface);

	SDL_FreeSurface(surface);



	surface = IMG_Load("chao2.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar logo.png");
		SDL_Quit();
		exit(66666);
	}
	game->chaomapa2 = SDL_CreateTextureFromSurface(game->renderer, surface);

	SDL_FreeSurface(surface);


	SDL_Surface *plata = NULL;

	plata = IMG_Load("plat2.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar logo.png");
		SDL_Quit();
		exit(888);
	}
	game->plataformamapa2 = SDL_CreateTextureFromSurface(game->renderer, plata);

	SDL_FreeSurface(plata);


	SDL_Surface *morc = NULL;

	morc = IMG_Load("morcego3.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar morcego3.png");
		SDL_Quit();
		exit(1);
	}
	game->morcego[1] = SDL_CreateTextureFromSurface(game->renderer, morc);

	SDL_FreeSurface(morc);


	SDL_Surface *morc2 = NULL;

	morc2 = IMG_Load("morcego4.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar morcego3.png");
		SDL_Quit();
		exit(1);
	}
	game->morcego[0] = SDL_CreateTextureFromSurface(game->renderer, morc2);

	SDL_FreeSurface(morc2);


	SDL_Surface *voa = NULL;

	voa = IMG_Load("voador.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar morcego3.png");
		SDL_Quit();
		exit(1);
	}
	game->voador[0] = SDL_CreateTextureFromSurface(game->renderer, voa);

	SDL_FreeSurface(voa);

	SDL_Surface *voa2 = NULL;

	voa2 = IMG_Load("voador2.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar morcego3.png");
		SDL_Quit();
		exit(1);
	}
	game->voador[1] = SDL_CreateTextureFromSurface(game->renderer, voa2);

	SDL_FreeSurface(voa2);


	SDL_Surface *fundo2 = NULL;

	fundo2 = IMG_Load("chaomapa1.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar logo.png");
		SDL_Quit();
		exit(99);
	}
	game->fundomapa2 = SDL_CreateTextureFromSurface(game->renderer, fundo2);

	SDL_FreeSurface(fundo2);



	surface = IMG_Load("fundomapa12.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar paisagem.png");
		SDL_Quit();
		exit(1);
	}
	game->paisa = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);


	surface = IMG_Load("fundo2.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar paisagem.png");
		SDL_Quit();
		exit(1);
	}
	game->paisa2 = SDL_CreateTextureFromSurface(game->renderer, surface);
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



	surface = IMG_Load("inimigo5.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar inimigo.png");
		SDL_Quit();
		exit(1);
	}
	game->enemy[4] = SDL_CreateTextureFromSurface(game->renderer, surface);
	SDL_FreeSurface(surface);

	surface = IMG_Load("inimigo4.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar inimigo.png");
		SDL_Quit();
		exit(1);
	}
	game->enemy[5] = SDL_CreateTextureFromSurface(game->renderer, surface);
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


	surface = IMG_Load("boneco7.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar boneco.png");
		SDL_Quit();
		exit(1);
	}
	game->Boneco[2] = SDL_CreateTextureFromSurface(game->renderer, surface);
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


	surface = IMG_Load("20.png");
	if (surface == NULL) {
		printf("Nao foi possivel achar estrela.png");
		SDL_Quit();
		exit(11);
	}
	game->gas = SDL_CreateTextureFromSurface(game->renderer, surface);
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
	game->fonte3 = TTF_OpenFont("04b_25__.ttf", 37);
	if (!game->fonte3) {
		printf("n foi possivel encontrar a fonte \n");
		exit(1);
	}
	game->fonte4 = TTF_OpenFont("04b_25__.ttf", 50);
	if (!game->fonte4) {
		printf("n foi possivel encontrar a fonte \n");
		exit(1);
	}








	SDL_Color white = { 255,255,255,255 };


	SDL_Surface *vidas = TTF_RenderText_Solid(game->fonte2, "Vidas: ", white);
	game->vidasti = SDL_CreateTextureFromSurface(game->renderer, vidas);
	SDL_FreeSurface(vidas);



	SDL_Surface *pontos = TTF_RenderText_Solid(game->fonte2, game->pontuacao, white);
	game->scorei = SDL_CreateTextureFromSurface(game->renderer, pontos);
	SDL_FreeSurface(pontos);


	game->label = NULL;

	//carregar musicas



	// iniciando personagem
	init_status_menu(game);
	game->statusState = STATUS_STATE_MENU;
	game->man.x = 20;
	game->man.y = 200;
	game->man.dx = 0;
	game->man.dy = 0;
	game->man.noChao = 0;
	game->man.mov = 0;
	game->man.aoContrario = 0;
	game->man.dimi = 0;
	game->man.vidas = 3;
	game->pont = 1;
	game->scrollx = 0;
	game->sobconti = 0;
	game->tempocred = 0;
	game->score = 1000;
	game->cordachao = 0;
	game->corda1.x = 2055;
	game->corda1.y = 295;
	game->gasolin.x = 7015;
	game->gasolin.y = 580;
	game->gasolina = 0;
	game->nave2.x = 10100;
	game->nave2.y = 580;
    game->tempohis=0;

	game->iden = -1;

	game->tempo = 0;
	game->sobsairgo = 0;
	game->sobvoltargo = 0;
	game->heart[1].visivel = 1;
	game->heart[0].visivel = 1;
	game->heart[2].visivel = 1;
	game->fase2 = 0;
	game->sobranking = 0;
	game->gasolina = 0;




	//init estrelas
	for (int i = 1; i < 8; i++) {
		game->Star[i].starviva = 1;
		game->Star[i].visivel = 1;
	}
	for (int i = 0; i <17; i++) {
		game->inimigo[i].vidas = 1;
		game->inimigo[i].vivo = 1;

	}





	for (int i = 0; i < 25; i++) {
		if (i == 5) {
			i++;
		}
		if (i == 6) {
			i++;
		}

		game->piso[i].h = 95;
		game->piso[i].w = 160;
		game->piso[i].x = i * (float) 160.0;
		game->piso[i].y = 650;



	}


	for (int i = 30; i < 65; i++) {
		game->piso2[i].h = 95;
		game->piso2[i].w = 160;
		game->piso2[i].x = i * (float) 160.0;
		game->piso2[i].y = 650;

	}

	for (int i = 30; i < 65; i++) {
		game->piso[i].h = 95;
		game->piso[i].w = 160;
		game->piso[i].x = i * (float) 160.0;
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



	game->plataform[6].h = 50;
	game->plataform[6].w = 160;
	game->plataform[6].x = 300 * 10;
	game->plataform[6].y = 490;






	// terceiro andar

	game->plataform[8].h = 50;
	game->plataform[8].w = 350;
	game->plataform[8].x = 300 * 11;
	game->plataform[8].y = 330;



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





	// MAPA 2
	game->plataform[50].h = 50;
	game->plataform[50].w = 160;
	game->plataform[50].x = 5200;
	game->plataform[50].y = 490;

	game->plataforma2[50].h = 50;
	game->plataforma2[50].w = 160;
	game->plataforma2[50].x = 5200;
	game->plataforma2[50].y = 490;

	game->plataform[51].h = 50;
	game->plataform[51].w = 160;
	game->plataform[51].x = 5800;
	game->plataform[51].y = 490;

	game->plataforma2[51].h = 50;
	game->plataforma2[51].w = 160;
	game->plataforma2[51].x = 5800;
	game->plataforma2[51].y = 490;

	game->plataform[53].h = 50;
	game->plataform[53].w = 160;
	game->plataform[53].x = 6400;
	game->plataform[53].y = 490;

	game->plataforma2[53].h = 50;
	game->plataforma2[53].w = 160;
	game->plataforma2[53].x = 6400;
	game->plataforma2[53].y = 490;

	game->plataform[53].h = 50;
	game->plataform[53].w = 160;
	game->plataform[53].x = 6400;
	game->plataform[53].y = 490;

	game->plataforma2[53].h = 50;
	game->plataforma2[53].w = 160;
	game->plataforma2[53].x = 6400;
	game->plataforma2[53].y = 490;

	game->plataform[55].h = 50;
	game->plataform[55].w = 160;
	game->plataform[55].x = 8000;
	game->plataform[55].y = 490;

	game->plataforma2[55].h = 50;
	game->plataforma2[55].w = 160;
	game->plataforma2[55].x = 8000;
	game->plataforma2[55].y = 490;

	game->plataform[58].h = 50;
	game->plataform[58].w = 160;
	game->plataform[58].x = 9000;
	game->plataform[58].y = 490;

	game->plataforma2[58].h = 50;
	game->plataforma2[58].w = 160;
	game->plataforma2[58].x = 9000;
	game->plataforma2[58].y = 490;

	game->plataform[57].h = 50;
	game->plataform[57].w = 160;
	game->plataform[57].x = 9745;
	game->plataform[57].y = 490;

	game->plataforma2[57].h = 50;
	game->plataforma2[57].w = 160;
	game->plataforma2[57].x = 9745;
	game->plataforma2[57].y = 490;


	game->plataform[52].h = 50;
	game->plataform[52].w = 160;
	game->plataform[52].x = 5497;
	game->plataform[52].y = 330;

	game->plataforma2[52].h = 50;
	game->plataforma2[52].w = 160;
	game->plataforma2[52].x = 5497;
	game->plataforma2[52].y = 330;



	game->plataform[54].h = 50;
	game->plataform[54].w = 160;
	game->plataform[54].x = 6860;
	game->plataform[54].y = 330;

	game->plataform[70].h = 50;
	game->plataform[70].w = 160;
	game->plataform[70].x = 6700;
	game->plataform[70].y = 330;



	game->plataforma2[54].h = 50;
	game->plataforma2[54].w = 800;
	game->plataforma2[54].x = 6700;
	game->plataforma2[54].y = 330;

	game->plataform[56].h = 50;
	game->plataform[56].w = 180;
	game->plataform[56].x = 8300;
	game->plataform[56].y = 330;

	game->plataforma2[56].h = 50;
	game->plataforma2[56].w = 180;
	game->plataforma2[56].x = 8300;
	game->plataforma2[56].y = 330;

	game->plataform[59].h = 50;
	game->plataform[59].w = 180;
	game->plataform[59].x = 9350;
	game->plataform[59].y = 330;

	game->plataforma2[59].h = 50;
	game->plataforma2[59].w = 180;
	game->plataforma2[59].x = 9350;
	game->plataforma2[59].y = 330;





	game->plataform[61].h = 50;
	game->plataform[61].w = 180;
	game->plataform[61].x = 4788 - 180;
	game->plataform[61].y = 650;

	game->plataforma2[61].h = 50;
	game->plataforma2[61].w = 180;
	game->plataforma2[61].x = 4788 - 180;
	game->plataforma2[61].y = 650;


	game->plataform[62].h = 50;
	game->plataform[62].w = 180;
	game->plataform[62].x = 4788 - 360;
	game->plataform[62].y = 650;

	game->plataforma2[62].h = 50;
	game->plataforma2[62].w = 180;
	game->plataforma2[62].x = 4788 - 360;
	game->plataforma2[62].y = 650;


	game->plataform[63].h = 50;
	game->plataform[63].w = 180;
	game->plataform[63].x = 4788 - 360;
	game->plataform[63].y = 650;

	game->plataform[64].h = 50;
	game->plataform[64].w = 180;
	game->plataform[64].x = 4788 - 360;
	game->plataform[64].y = 600;

	game->plataform[65].h = 50;
	game->plataform[65].w = 180;
	game->plataform[65].x = 4788 - 360;
	game->plataform[65].y = 550;

	game->plataform[66].h = 50;
	game->plataform[66].w = 180;
	game->plataform[66].x = 4788 - 360;
	game->plataform[66].y = 500;

	game->plataform[67].h = 50;
	game->plataform[67].w = 180;
	game->plataform[67].x = 4788 - 360;
	game->plataform[67].y = 450;

	game->plataform[67].h = 50;
	game->plataform[67].w = 180;
	game->plataform[67].x = 6835;
	game->plataform[67].y = 330;

	game->plataforma2[67].h = 50;
	game->plataforma2[67].w = 180;
	game->plataforma2[67].x = 6835;
	game->plataforma2[67].y = 330;


	game->plataform[68].h = 50;
	game->plataform[68].w = 180;
	game->plataform[68].x = 6835 + 180;
	game->plataform[68].y = 330;

	game->plataforma2[68].h = 50;
	game->plataforma2[68].w = 180;
	game->plataforma2[68].x = 6835 + 180;
	game->plataforma2[68].y = 330;


	game->plataform[69].h = 50;
	game->plataform[69].w = 180;
	game->plataform[69].x = 6835 + 360;
	game->plataform[69].y = 330;

	game->plataforma2[69].h = 50;
	game->plataforma2[69].w = 180;
	game->plataforma2[69].x = 6835 + 360;
	game->plataforma2[69].y = 330;


	//7083 550    8370  280




	game->Star[1].x = 920;
	game->Star[1].y = 165;
	game->Star[1].w = 40;
	game->Star[1].h = 40;
	game->Star[1].mode = 2;
	game->Star[1].baseX = game->Star[1].x;
	game->Star[1].baseY = game->Star[1].y;




	game->Star[2].x = 3460;
	game->Star[2].y = 270;
	game->Star[2].w = 40;
	game->Star[2].h = 40;
	game->Star[2].mode = 0;
	game->Star[2].baseX = game->Star[2].x;
	game->Star[2].baseY = game->Star[2].y;

	game->Star[4].x = 7050;
	game->Star[4].y = 250;
	game->Star[4].w = 40;
	game->Star[4].h = 40;
	game->Star[4].mode = 0;
	game->Star[4].baseX = game->Star[4].x;
	game->Star[4].baseY = game->Star[4].y;


	game->Star[5].x = 5560;
	game->Star[5].y = 250;
	game->Star[5].w = 40;
	game->Star[5].h = 40;
	game->Star[5].mode = 0;
	game->Star[5].baseX = game->Star[5].x;
	game->Star[5].baseY = game->Star[5].y;


	game->Star[6].x = 8650;
	game->Star[6].y = 250;
	game->Star[6].w = 40;
	game->Star[6].h = 40;
	game->Star[6].mode = 2;
	game->Star[6].baseX = game->Star[6].x;
	game->Star[6].baseY = game->Star[6].y;

	game->Star[7].x = 9425;
	game->Star[7].y = 250;
	game->Star[7].w = 40;
	game->Star[7].h = 40;
	game->Star[7].mode = 0;
	game->Star[7].baseX = game->Star[7].x;
	game->Star[7].baseY = game->Star[7].y;


	//inimigo

	game->inimigo[0].xe = 2280;
	game->inimigo[0].ye = 265;
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


	game->inimigo[2].xe = 1900;
	game->inimigo[2].ye = 265;
	game->inimigo[2].we = 40;
	game->inimigo[2].he = 60;
	game->inimigo[2].baseX = game->inimigo[2].xe;
	game->inimigo[2].baseY = game->inimigo[2].ye;
	game->inimigo[2].phase = 2;
	game->inimigo[2].mode = 0;
	game->inimigo[2].aocontrario = 0;
	game->inimigo[2].dxe = 10;
	game->inimigo[2].mov = 0;




	game->inimigo[3].xe = 2900;
	game->inimigo[3].ye = 420;
	game->inimigo[3].we = 40;
	game->inimigo[3].he = 60;
	game->inimigo[3].baseX = game->inimigo[3].xe;
	game->inimigo[3].baseY = game->inimigo[3].ye;
	game->inimigo[3].phase = 1;
	game->inimigo[3].mode = 0;
	game->inimigo[3].aocontrario = 0;
	game->inimigo[3].dxe = 10;
	game->inimigo[3].mov = 0;

	game->inimigo[4].xe = 2500;
	game->inimigo[4].ye = 580;
	game->inimigo[4].we = 40;
	game->inimigo[4].he = 60;
	game->inimigo[4].baseX = game->inimigo[4].xe;
	game->inimigo[4].baseY = game->inimigo[4].ye;
	game->inimigo[4].phase = 1;
	game->inimigo[4].mode = 0;
	game->inimigo[4].aocontrario = 0;
	game->inimigo[4].dxe = 10;
	game->inimigo[4].mov = 0;


	game->inimigo[5].xe = 5270;
	game->inimigo[5].ye = 420;
	game->inimigo[5].we = 40;
	game->inimigo[5].he = 60;
	game->inimigo[5].baseX = game->inimigo[5].xe;
	game->inimigo[5].baseY = game->inimigo[5].ye;
	game->inimigo[5].phase = 1;
	game->inimigo[5].mode = 0;
	game->inimigo[5].aocontrario = 0;
	game->inimigo[5].dxe = 10;
	game->inimigo[5].mov2 = 4;


	game->inimigo[7].xe =20000;
	game->inimigo[7].ye = 580;
	game->inimigo[7].we = 40;
	game->inimigo[7].he = 60;
	game->inimigo[7].baseX = game->inimigo[7].xe;
	game->inimigo[7].baseY = game->inimigo[7].ye;
	game->inimigo[7].phase = 1;
	game->inimigo[7].mode = 0;
	game->inimigo[7].aocontrario = 0;
	game->inimigo[7].dxe = 10;
	game->inimigo[7].mov2 = 4;


	game->inimigo[8].xe = 6900;
	game->inimigo[8].ye = 580;
	game->inimigo[8].we = 40;
	game->inimigo[8].he = 60;
	game->inimigo[8].baseX = game->inimigo[8].xe;
	game->inimigo[8].baseY = game->inimigo[8].ye;
	game->inimigo[8].phase = 2;
	game->inimigo[8].mode = 0;
	game->inimigo[8].aocontrario = 0;
	game->inimigo[8].dxe = 10;
	game->inimigo[8].mov2 = 4;


	game->inimigo[9].xe = 7190;
	game->inimigo[9].ye = 580;
	game->inimigo[9].we = 40;
	game->inimigo[9].he = 60;
	game->inimigo[9].baseX = game->inimigo[9].xe;
	game->inimigo[9].baseY = game->inimigo[9].ye;
	game->inimigo[9].phase = 1;
	game->inimigo[9].mode = 0;
	game->inimigo[9].aocontrario = 0;
	game->inimigo[9].dxe = 10;
	game->inimigo[9].mov2 = 4;


	game->inimigo[10].xe = 7000;
	game->inimigo[10].ye = 265;
	game->inimigo[10].we = 40;
	game->inimigo[10].he = 60;
	game->inimigo[10].baseX = game->inimigo[10].xe;
	game->inimigo[10].baseY = game->inimigo[10].ye;
	game->inimigo[10].phase = 2;
	game->inimigo[10].mode = 0;
	game->inimigo[10].aocontrario = 0;
	game->inimigo[10].dxe = 10;
	game->inimigo[10].mov2 = 4;


	game->inimigo[11].xe = 7400;
	game->inimigo[11].ye = 580;
	game->inimigo[11].we = 40;
	game->inimigo[11].he = 60;
	game->inimigo[11].baseX = game->inimigo[11].xe;
	game->inimigo[11].baseY = game->inimigo[11].ye;
	game->inimigo[11].phase = 2;
	game->inimigo[11].mode = 0;
	game->inimigo[11].aocontrario = 0;
	game->inimigo[11].dxe = 10;
	game->inimigo[11].mov2 = 4;



	game->inimigo[12].xe = 8600;
	game->inimigo[12].ye = 580;
	game->inimigo[12].we = 40;
	game->inimigo[12].he = 60;
	game->inimigo[12].baseX = game->inimigo[12].xe;
	game->inimigo[12].baseY = game->inimigo[12].ye;
	game->inimigo[12].phase = 2;
	game->inimigo[12].mode = 0;
	game->inimigo[12].aocontrario = 0;
	game->inimigo[12].dxe = 10;
	game->inimigo[12].mov2 = 4;


	game->inimigo[13].xe = 9065;
	game->inimigo[13].ye = 420;
	game->inimigo[13].we = 40;
	game->inimigo[13].he = 60;
	game->inimigo[13].baseX = game->inimigo[13].xe;
	game->inimigo[13].baseY = game->inimigo[13].ye;
	game->inimigo[13].phase = 1;
	game->inimigo[13].mode = 0;
	game->inimigo[13].aocontrario = 0;
	game->inimigo[13].dxe = 10;
	game->inimigo[13].mov2 = 4;



	game->inimigo[14].xe = 9810;
	game->inimigo[14].ye = 420;
	game->inimigo[14].we = 40;
	game->inimigo[14].he = 60;
	game->inimigo[14].baseX = game->inimigo[14].xe;
	game->inimigo[14].baseY = game->inimigo[14].ye;
	game->inimigo[14].phase = 2;
	game->inimigo[14].mode = 0;
	game->inimigo[14].aocontrario = 0;
	game->inimigo[14].dxe = 10;
	game->inimigo[14].mov2 = 4;



	game->inimigo[15].xe = 9600;
	game->inimigo[15].ye = 580;
	game->inimigo[15].we = 40;
	game->inimigo[15].he = 60;
	game->inimigo[15].baseX = game->inimigo[15].xe;
	game->inimigo[15].baseY = game->inimigo[15].ye;
	game->inimigo[15].phase = 1;
	game->inimigo[15].mode = 0;
	game->inimigo[15].aocontrario = 0;
	game->inimigo[15].dxe = 10;
	game->inimigo[15].mov2 = 4;


	game->inimigo[6].xe = 9200;
	game->inimigo[6].ye = 580;
	game->inimigo[6].we = 40;
	game->inimigo[6].he = 60;
	game->inimigo[6].baseX = game->inimigo[16].xe;
	game->inimigo[6].baseY = game->inimigo[16].ye;
	game->inimigo[6].phase = 2;
	game->inimigo[6].mode = 0;
	game->inimigo[6].aocontrario = 0;
	game->inimigo[6].dxe = 10;
	game->inimigo[6].mov2 = 4;










	game->morcego1[1].x = 5500;
	game->morcego1[1].y = 220;
	game->morcego1[1].w = 40;
	game->morcego1[1].h = 40;
	game->morcego1[1].baseX = game->morcego1[1].x;
	game->morcego1[1].baseY = game->morcego1[1].y;
	game->morcego1[1].phase = 1;
	game->morcego1[1].mode = 0;
	game->morcego1[1].aocontrario = 0;
	game->morcego1[1].dx = 10;
	game->morcego1[1].mov = 0;
	game->morcego1[1].vivo = 1;

	game->morcego1[2].x = 6300;
	game->morcego1[2].y = 350;
	game->morcego1[2].w = 40;
	game->morcego1[2].h = 40;
	game->morcego1[2].baseX = game->morcego1[2].x;
	game->morcego1[2].baseY = game->morcego1[2].y;
	game->morcego1[2].phase = 1;
	game->morcego1[2].mode = 0;
	game->morcego1[2].aocontrario = 0;
	game->morcego1[2].dx = 10;
	game->morcego1[2].mov = 0;
	game->morcego1[2].vivo = 1;

	game->morcego1[3].x = 7000;
	game->morcego1[3].y = 450;
	game->morcego1[3].w = 40;
	game->morcego1[3].h = 40;
	game->morcego1[3].baseX = game->morcego1[3].x;
	game->morcego1[3].baseY = game->morcego1[3].y;
	game->morcego1[3].phase = 1;
	game->morcego1[3].mode = 0;
	game->morcego1[3].aocontrario = 0;
	game->morcego1[3].dx = 10;
	game->morcego1[3].mov = 0;
	game->morcego1[3].vivo = 1;

	game->morcego1[4].x = 8200;
	game->morcego1[4].y = 220;
	game->morcego1[4].w = 40;
	game->morcego1[4].h = 40;
	game->morcego1[4].baseX = game->morcego1[4].x;
	game->morcego1[4].baseY = game->morcego1[4].y;
	game->morcego1[4].phase = 1;
	game->morcego1[4].mode = 0;
	game->morcego1[4].aocontrario = 0;
	game->morcego1[4].dx = 10;
	game->morcego1[4].mov = 0;
	game->morcego1[4].vivo = 1;

	game->morcego1[5].x = 8650;
	game->morcego1[5].y = 450;
	game->morcego1[5].w = 40;
	game->morcego1[5].h = 40;
	game->morcego1[5].baseX = game->morcego1[5].x;
	game->morcego1[5].baseY = game->morcego1[5].y;
	game->morcego1[5].phase = 1;
	game->morcego1[5].mode = 0;
	game->morcego1[5].aocontrario = 0;
	game->morcego1[5].dx = 10;
	game->morcego1[5].mov = 0;
	game->morcego1[5].vivo = 1;

	game->morcego1[6].x = 9500;
	game->morcego1[6].y = 220;
	game->morcego1[6].w = 40;
	game->morcego1[6].h = 40;
	game->morcego1[6].baseX = game->morcego1[6].x;
	game->morcego1[6].baseY = game->morcego1[6].y;
	game->morcego1[6].phase = 1;
	game->morcego1[6].mode = 0;
	game->morcego1[6].aocontrario = 0;
	game->morcego1[6].dx = 10;
	game->morcego1[6].mov = 0;
	game->morcego1[6].vivo = 1;




	game->sobvoltarfim = 0;
	game->sobsairfim = 0;




	game->voador1[1].x = 900;
	game->voador1[1].y = 220;
	game->voador1[1].w = 40;
	game->voador1[1].h = 40;
	game->voador1[1].baseX = game->voador1[1].x;
	game->voador1[1].baseY = game->voador1[1].y;
	game->voador1[1].phase = 1;
	game->voador1[1].mode = 0;
	game->voador1[1].aocontrario = 0;
	game->voador1[1].dx = 10;
	game->voador1[1].mov = 0;
	game->voador1[1].vivo = 1;

	game->voador1[2].x = 1500;
	game->voador1[2].y = 290;
	game->voador1[2].w = 40;
	game->voador1[2].h = 40;
	game->voador1[2].baseX = game->voador1[2].x;
	game->voador1[2].baseY = game->voador1[2].y;
	game->voador1[2].phase = 2;
	game->voador1[2].mode = 0;
	game->voador1[2].aocontrario = 0;
	game->voador1[2].dx = 10;
	game->voador1[2].mov = 0;
	game->voador1[2].vivo = 1;

	game->voador1[3].x = 3450;
	game->voador1[3].y = 250;
	game->voador1[3].w = 40;
	game->voador1[3].h = 40;
	game->voador1[3].baseX = game->voador1[3].x;
	game->voador1[3].baseY = game->voador1[3].y;
	game->voador1[3].phase = 2;
	game->voador1[3].mode = 0;
	game->voador1[3].aocontrario = 0;
	game->voador1[3].dx = 10;
	game->voador1[3].mov = 0;
	game->voador1[3].vivo = 1;

	game->voador1[4].x = 1100;
	game->voador1[4].y = 540;
	game->voador1[4].w = 40;
	game->voador1[4].h = 40;
	game->voador1[4].baseX = game->voador1[4].x;
	game->voador1[4].baseY = game->voador1[4].y;
	game->voador1[4].phase = 2;
	game->voador1[4].mode = 0;
	game->voador1[4].aocontrario = 0;
	game->voador1[4].dx = 10;
	game->voador1[4].mov = 0;
	game->voador1[4].vivo = 1;






}




void process(GameState *game) {
	//tempo




	if (game->statusState == STATUS_STATE_GAME)
	{

		game->tempo++;


		if (game->tempo % 60 == 0) {
			game->score-=10;
		}

		//movimentação do personagem

		game->man.x += game->man.dx;
		game->man.y += game->man.dy;

		if (game->man.x < 0) {
			game->man.x = 0;
		}
		if (game->man.x >10330) {
			game->man.x = 10330;
		}


		for (int i = 1; i<5; i++) {

			if (game->voador1[i].vivo == 1) {
				if (game->tempo % 8 == 0) {
					if (game->voador1[i].mov == 0) {
						game->voador1[i].mov = 1;
					}

					else {
						game->voador1[i].mov = 0;
					}
				}
			}
		}



		for (int i = 1; i<7; i++) {

			if (game->morcego1[i].vivo == 1) {
				if (game->tempo % 8 == 0) {
					if (game->morcego1[i].mov == 0) {
						game->morcego1[i].mov = 1;
					}

					else {
						game->morcego1[i].mov = 0;
					}
				}
			}
		}

		if (game->man.dx != 0 && game->man.noChao && !game->man.dimi) {
			if (game->tempo % 10 == 0) {
				if (game->man.mov == 0) {
					game->man.mov = 1;


				}
				else {
					game->man.mov = 0;
				}
			}

		}

		game->man.dy += GRAVIDADE * (float)1.2;


	}
	if (game->man.y + 55 > 630) {
		game->man.noChao = 0;
	}

	if ((game->man.x > 0 && game->man.x < 3100) || (game->man.x > 4920 && game->man.x <9400)) {
		game->scrollx = -game->man.x + 300;
		if (game->scrollx > 0)
			game->scrollx = 0;
	}
	if (game->man.y > 1000) {

		game->man.vidas =0;


	}
	if (game->man.vidas == 0 || game->score==0) {
		game->score = 0;
		SDL_Delay(150);

		game->statusState = STATUS_STATE_GAMEOVER;
		init_status_over(game);

	}


	if (game->statusState == STATUS_STATE_GAME) {
		for (int i = 1; i < 7; i++)
		{

			if (game->morcego1[i].vivo == 1) {
				game->morcego1[i].x = game->morcego1[i].baseX + sinf(100 + game->tempo*0.02f) * 250;

			}
                if (i == 1) {

				if (game->morcego1[i].x < 5270)
					game->morcego1[i].aocontrario = 0;
				// aaaaaa

				if (game->morcego1[i].x >5700)
					game->morcego1[i].aocontrario = 1;

			}


			if (i == 2) {

				if (game->morcego1[i].x < 6085)
					game->morcego1[i].aocontrario = 0;
				// aaaaaa

				if (game->morcego1[i].x >6525)
					game->morcego1[i].aocontrario = 1;

			}


			if (i == 3) {

				if (game->morcego1[i].x < 6768)
					game->morcego1[i].aocontrario = 0;
				// aaaaaa

				if (game->morcego1[i].x >7235)
					game->morcego1[i].aocontrario = 1;

			}

			if (i == 4) {

				if (game->morcego1[i].x < 7975)
					game->morcego1[i].aocontrario = 0;
				// aaaaaa

				if (game->morcego1[i].x >8426)
					game->morcego1[i].aocontrario = 1;

			}

			if (i == 5) {

				if (game->morcego1[i].x < 8459)
					game->morcego1[i].aocontrario = 0;
				// aaaaaa

				if (game->morcego1[i].x >8884)
					game->morcego1[i].aocontrario = 1;

			}

			if (i == 6) {

				if (game->morcego1[i].x < 9270)
					game->morcego1[i].aocontrario = 0;
				// aaaaaa

				if (game->morcego1[i].x >9730)
					game->morcego1[i].aocontrario = 1;

			}

		}

//-------------------------------------------------------------------------------------------------------------//

			for(int i=1;i<5;i++){
			if (game->voador1[i].vivo == 1) {
				game->voador1[i].x = game->voador1[i].baseX + sinf(100 + game->tempo*0.02f) * 250;

			}

			if (i == 1) {

				if (game->voador1[i].x < 675)
					game->voador1[i].aocontrario = 1;


				if (game->voador1[i].x > 1138)
					game->voador1[i].aocontrario = 0;

			}


			if (i == 2) {

				if (game->voador1[i].x < 1265)
					game->voador1[i].aocontrario = 1;


				if (game->voador1[i].x > 1727)
					game->voador1[i].aocontrario = 0;

			}

			if (i == 3) {

				if (game->voador1[i].x < 3225)
					game->voador1[i].aocontrario = 1;


				if (game->voador1[i].x > 3651)
					game->voador1[i].aocontrario = 0;

			}


			if (i == 4) {

				if (game->voador1[i].x < 875)
					game->voador1[i].aocontrario = 1;


				if (game->voador1[i].x > 1299)
					game->voador1[i].aocontrario = 0;

			}

			}




for(int i=0;i<16;i++){

			if (fabs(game->inimigo[i].xe - game->man.x) < 1350 && game->inimigo[i].vivo == 1) {




				game->inimigo[i].xe = game->inimigo[i].baseX + sinf(game->inimigo[i].phase + game->tempo*0.07f) * 75;

				if (game->inimigo[1].xe > 1600) {



					game->inimigo[1].aocontrario = 0;

				}

				if (game->inimigo[1].xe < 1530) {

					game->inimigo[1].aocontrario = 1;

				}

				if (i == 0) {

					game->inimigo[i].xe = game->inimigo[i].baseX + sinf(0 + game->tempo*0.07f) * 85;



					if (game->inimigo[0].xe > 22) {



						game->inimigo[0].aocontrario = 0;

					}

					if (game->inimigo[0].xe < 2310) {

						game->inimigo[0].aocontrario = 1;

					}

				}


				if (i == 2) {

					game->inimigo[i].xe = game->inimigo[i].baseX + sinf(2 + game->tempo*0.07f) * 85;



					if (game->inimigo[2].xe > 1980) {



						game->inimigo[2].aocontrario = 0;

					}

					if (game->inimigo[2].xe < 1826) {

						game->inimigo[2].aocontrario = 1;

					}

				}



				if (i == 3) {

					game->inimigo[i].xe = game->inimigo[i].baseX + sinf(3 + game->tempo*0.07f) * 65;

					if (game->inimigo[3].xe > 2770) {



						game->inimigo[3].aocontrario = 0;

					}

					if (game->inimigo[3].xe < 2910) {

						game->inimigo[3].aocontrario = 1;

					}

				}



				if (i == 4) {

					game->inimigo[i].xe = game->inimigo[i].baseX + sinf(4 + game->tempo*0.07f) * 95;

					if (game->inimigo[4].xe > 2560) {



						game->inimigo[4].aocontrario = 0;

					}

					if (game->inimigo[4].xe < 2440) {

						game->inimigo[4].aocontrario = 1;

					}

				}

				if (i == 5) {

					if (game->inimigo[i].xe > 5320) {
						game->inimigo[i].aocontrario = 0;

					}

					if (game->inimigo[i].xe < 5200) {
						game->inimigo[i].aocontrario = 1;

					}
				}

				if (i == 7) {

					if (game->inimigo[i].xe > 6210) {
						game->inimigo[i].aocontrario = 0;

					}

					if (game->inimigo[i].xe < 6120) {
						game->inimigo[i].aocontrario = 1;

					}
				}

				if (i == 8) {

					if (game->inimigo[i].xe > 6940) {
						game->inimigo[i].aocontrario = 0;

					}

					if (game->inimigo[i].xe < 6830) {
						game->inimigo[i].aocontrario = 1;

					}
				}

				if (i == 9) {

					if (game->inimigo[i].xe > 7246) {
						game->inimigo[i].aocontrario = 0;

					}

					if (game->inimigo[i].xe < 7120) {
						game->inimigo[i].aocontrario = 1;

					}
				}

				if (i == 10) {

					if (game->inimigo[i].xe > 7050) {
						game->inimigo[i].aocontrario = 0;

					}

					if (game->inimigo[i].xe < 6930) {
						game->inimigo[i].aocontrario = 1;

					}
				}

				if (i == 11) {

					if (game->inimigo[i].xe > 7455) {
						game->inimigo[i].aocontrario = 0;

					}

					if (game->inimigo[i].xe < 7343) {
						game->inimigo[i].aocontrario = 1;

					}
				}

				if (i == 12) {

					if (game->inimigo[i].xe > 8658) {
						game->inimigo[i].aocontrario = 0;

					}

					if (game->inimigo[i].xe < 8545) {
						game->inimigo[i].aocontrario = 1;

					}
				}

				if (i == 13) {

					if (game->inimigo[i].xe > 9118) {
						game->inimigo[i].aocontrario = 0;

					}

					if (game->inimigo[i].xe < 8998) {
						game->inimigo[i].aocontrario = 1;

					}
				}

				if (i == 14) {

					if (game->inimigo[i].xe > 9860) {
						game->inimigo[i].aocontrario = 0;

					}

					if (game->inimigo[i].xe < 9736) {
						game->inimigo[i].aocontrario = 1;

					}
				}

				if (i == 15) {

					if (game->inimigo[i].xe > 9645) {
						game->inimigo[i].aocontrario = 0;

					}

					if (game->inimigo[i].xe < 9545) {
						game->inimigo[i].aocontrario = 1;

					}
				}

				if (i == 6) {

					if (game->inimigo[i].xe > 9256) {
						game->inimigo[i].aocontrario = 0;

					}

					if (game->inimigo[i].xe < 9127) {
						game->inimigo[i].aocontrario = 1;

					}
				}

			}


		}

		for (int i = 1; i < 8; i++) {
			if (game->Star[i].mode == 2 && fabs(game->Star[i].x - game->man.x)<1350) {
				game->Star[i].y = game->Star[i].baseY + cosf(1 + game->tempo*0.06f) * 75;
			}
		}


	}

	for (int i = 0; i < 16; i++) {


			if (i >= 0 && i < 5) {
				if (game->tempo % 15 == 0) {
					if (game->inimigo[i].mov == 0) {
						game->inimigo[i].mov = 1;
					}
					else {
						game->inimigo[i].mov = 0;
					}
				}
			}

			if (i >= 5) {
				if (game->tempo % 15 == 0) {
					if (game->inimigo[i].mov2 == 4) {
						game->inimigo[i].mov2 = 5;
					}
					else {
						game->inimigo[i].mov2 = 4;
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
		game->score = 0;
		game->heart[0].visivel = 0;
		game->heart[1].visivel = 0;
		game->heart[2].visivel = 0;
	}




	if (game->statusState == STATUS_STATE_CONFIG) {

		draw_status_config(game);
	}

}

int collide2d(float x1, float y1, float x2, float y2, float wt1, float ht1, float wt2, float ht2)
{
	return (!((x1 > (x2 + wt2)) || (x2 > (x1 + wt1)) || (y1 > (y2 + ht2)) || (y2 > (y1 + ht1))));
}



void colisaoDetect(GameState *game) {

	//Check for collision with estrela
	for (int i = 1; i < 8; i++)
	{
		if (collide2d(game->man.x, game->man.y, game->Star[i].x, game->Star[i].y, 74, 94, 30, 40))
		{
			if (game->Star[i].starviva == 1)
			{
				game->score += 50;
				game->Star[i].starviva = 0;
				game->Star[i].visivel = 0;
			}

		}
	}

	for (int i = 0; i < 16; i++)
	{
		if (collide2d(game->man.x, game->man.y, game->inimigo[i].xe, game->inimigo[i].ye, 74, 94, 35, 55))
		{
			if (game->inimigo[i].vivo == 1)
			{
				game->score -= 100;
				game->inimigo[i].vivo = 0;
				game->man.vidas--;
				Mix_PlayChannel(-1, game->hit, 0);
				game->man.mov = 2;
				if (game->tempo % 8 == 0) {
					game->man.mov = 0;
				}



			}

		}
	}
	for (int i = 1; i < 8; i++)
	{
		if (collide2d(game->man.x, game->man.y, game->morcego1[i].x, game->morcego1[i].y, 74, 94, 40, 40))
		{
			if (game->morcego1[i].vivo == 1)
			{
				game->morcego1[i].vivo = 0;
				game->man.vidas--;
				game->score -= 100;
				Mix_PlayChannel(-1, game->hit, 0);
				game->man.mov = 2;
				if (game->tempo % 10 == 0) {
					game->man.mov = 0;

				}



			}

		}

	}

	for (int i = 1; i < 5; i++)
	{
		if ( game->voador1[i].vivo == 1 && collide2d(game->man.x, game->man.y, game->voador1[i].x, game->voador1[i].y, 74, 94, 40, 40))
		{

				game->score -= 100;
				game->voador1[i].vivo = 0;
				game->man.vidas--;
				Mix_PlayChannel(-1, game->hit, 0);
				game->man.mov = 2;
				if (game->tempo % 10 == 0) {
					game->man.mov = 0;

				}





		}


	}












	// checar colisao com algum piso
	for (int i = 0; i < 100; i++) {
		float mw = 54, mh = 74;
		float mx = game->man.x, my = game->man.y;
		float bx = game->piso[i].x - 2, by = game->piso[i].y - 2, bw = game->piso[i].w, bh = game->piso[i].h;
		float px = game->plataform[i].x, py = game->plataform[i].y - 7, pw = game->plataform[i].w, ph = game->plataform[i].h + 25;
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


			if (game->statusState == STATUS_STATE_MENU && event.motion.x >= 60 && event.motion.x <= 60 + game->novow + 50 && event.motion.y >= 360 && event.motion.y <= 360 + game->novoh + 20) {
				game->sobnovo++;
			}
			else {
				game->sobnovo = 0;

			}
			if (game->statusState == STATUS_STATE_MENU && event.motion.x >= 60 && event.motion.x <= 60 + game->configw + 50 && event.motion.y >= 420 && event.motion.y <= 420 + game->configh + 20) {
				game->sobconfig++;
			}
			else {
				game->sobconfig = 0;

			}

			if (game->statusState == STATUS_STATE_MENU && event.motion.x >= 60 && event.motion.x <= 60 + game->sairw + 50 && event.motion.y >= 600 && event.motion.y <= 600 + game->sairh + 20) {
				game->sobsair++;
			}
			else {
				game->sobsair = 0;

			}

			if (game->statusState == STATUS_STATE_MENU && event.motion.x >= 60 && event.motion.x <= 60 + game->credw + 50 && event.motion.y >= 480 && event.motion.y <= 480 + game->credh) {
				game->sobcredi++;
			}
			else {
				game->sobcredi = 0;

			}

			if (game->statusState == STATUS_STATE_MENU && event.motion.x >= 60 && event.motion.x <= 60 + game->recordew + 50 && event.motion.y >= 540 && event.motion.y <= 540 + game->recordeh + 20) {
				game->sobranking++;
			}
			else {
				game->sobranking = 0;

			}


			//AÇOES NO MENU DE CREDITOS

			if (game->statusState == STATUS_STATE_CREDITS && event.motion.x >= 40 && event.motion.x <= 40 + game->voltarmenuw && event.motion.y >= 630 && event.motion.y <= 630 + game->voltarmenuh) {
				game->sobvoltar++;
			}
			else {
				game->sobvoltar = 0;

			}


			// menu game over

			if (game->statusState == STATUS_STATE_GAMEOVER && event.motion.x >= 120 && event.motion.x <= 220 && event.motion.y >= 560 && event.motion.y <= 660) {
				game->sobvoltargo++;
			}
			else {
				game->sobvoltargo = 0;
			}

			if (game->statusState == STATUS_STATE_GAMEOVER && event.motion.x >= 1040 && event.motion.x <= 1140 && event.motion.y >= 560 && event.motion.y <= 660) {
				game->sobsairgo++;
			}
			else
			{
				game->sobsairgo = 0;
			}

			if (game->statusState == GAME_STATUS_FIM && event.motion.x >= 1040 && event.motion.x <= 1140 && event.motion.y >= 560 && event.motion.y <= 660) {
				game->sobsairfim++;
			}
			else
			{
				game->sobsairfim = 0;
			}
			if (game->statusState == GAME_STATUS_FIM && event.motion.x >= 120 && event.motion.x <= 220 && event.motion.y >= 560 && event.motion.y <= 660) {
				game->sobvoltarfim++;
			}
			else {
				game->sobvoltarfim = 0;
			}

			if (game->statusState == STATUS_STATE_CONFIG && event.motion.x >= 1040 && event.motion.x <= 1140 && event.motion.y >= 560 && event.motion.y <= 660) {
				game->sobsairm++;
			}
			else
			{
				game->sobsairm = 0;
			}
			if (game->statusState == STATUS_STATE_CONFIG && event.motion.x >= 120 && event.motion.x <= 220 && event.motion.y >= 560 && event.motion.y <= 660) {
				game->sobvoltarm++;
			}
			else {
				game->sobvoltarm = 0;
			}


			if (game->statusState == STATUS_STATE_CONFIG && event.motion.x >= 771 && event.motion.x <= 866 && event.motion.y >= 354 && event.motion.y <= 447) {
				game->sobtick++;
			}
			else {
				game->sobtick = 0;
			}




			break;
		}
		case SDL_MOUSEBUTTONDOWN:
			if (game->statusState == STATUS_STATE_MENU) {
				if (game->sobnovo >= 1) {
					Mix_PlayChannel(-1, game->menusom, 0);

					game->statusState = STATUS_STATE_HISTORIA;
					game->man.vidas = 3;
					game->sobnovo = 0;
				}


				if (game->sobcredi >= 1) {
					Mix_PlayChannel(-1, game->menusom, 0);
					SDL_Delay(80);
					init_status_cred(game);
					game->statusState = STATUS_STATE_CREDITS;
				}

				if (game->sobconfig >= 1) {
					Mix_PlayChannel(-1, game->menusom, 0);
					game->statusState = STATUS_STATE_CONFIG;
					init_status_config(game);


				}



				if (game->sobsair >= 1) {
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

			if (game->statusState == STATUS_STATE_GAMEOVER) {

				if (game->sobvoltargo >= 1) {
					Mix_PlayChannel(-1, game->menusom, 0);
					LoadGame(game);
					game->statusState = STATUS_STATE_MENU;

					game->sobvoltargo = 0;

				}
				if (game->sobsairgo >= 1) {
					Mix_PlayChannel(-1, game->menusom, 0);
					SDL_Delay(100);
					done = 1;
				}
			}

			if (game->statusState == GAME_STATUS_FIM) {

				if (game->sobvoltarfim >= 1) {
					Mix_PlayChannel(-1, game->menusom, 0);
					LoadGame(game);
					game->statusState = STATUS_STATE_MENU;

					game->sobvoltarfim = 0;
				}
				if (game->sobsairfim >= 1) {
					Mix_PlayChannel(-1, game->menusom, 0);
					SDL_Delay(100);
					done = 1;
				}
			}


			if (game->statusState == STATUS_STATE_CONFIG) {

				if (game->sobvoltarm >= 1) {
					Mix_PlayChannel(-1, game->menusom, 0);
					LoadGame(game);
					game->statusState = STATUS_STATE_MENU;

					game->sobvoltarm = 0;
				}
				if (game->sobsairm >= 1) {
					Mix_PlayChannel(-1, game->menusom, 0);
					SDL_Delay(100);
					done = 1;
				}

				if (game->sobtick >= 1) {
					if (game->pont == 1) {
						game->pont = 0;

						Mix_VolumeMusic(-0);
					}

					if (game->pont == 0) {
						game->pont = 1;
                Mix_VolumeMusic(5);
					}
				}

			}
			break;



		case SDL_WINDOWEVENT_CLOSE:

			if (window)
			{
				SDL_DestroyWindow(window);
				window = NULL;
				done = 1;
			}

			break;

		case SDL_QUIT:{

			done = 1;
			break;
		}


		case SDL_KEYDOWN:
		{
			switch (event.key.keysym.sym)
			{


			case SDLK_f:


                    printf("%f\n",game->man.x);
				if (game->statusState == STATUS_STATE_GAME) {
					if (game->man.x >= 2040 && game->man.x <= 2060 && game->man.y >= 230 && game->man.y <= 250) {
						game->cordachao = 1;

						break;
					}
					if (game->cordachao == 1 && game->man.x >= 3940 && game->man.x <= 3990 && game->man.y >= 570 && game->man.y <= 580) {
						game->man.x = 4940;
						game->man.y = 200;
						game->man.dx = 0;
						game->man.dy = 0;

						game->fase2 = 1;
						break;
					}


				}

				if (game->gasolina == 0 && game->man.x >= 6995 && game->man.x <= 7025 && game->man.y >= 570 && game->man.y <= 580) {

					game->gasolina = 1;
				}

				if (game->gasolina == 1 && game->man.x >= 10180 && game->man.x <= 10260 && game->man.y >= 450 && game->man.y <= 580) {

					game->statusState = GAME_STATUS_FIM;
					init_status_fim(game);
					draw_status_fim(game);
				}




				break;
			case SDLK_ESCAPE:
				done = 1;
				break;

			case SDLK_UP:
				if (game->statusState==STATUS_STATE_GAME && game->man.noChao == 1){
					game->man.dy = -10;
					game->man.noChao = 0;
                            game->man.vidas=game->man.vidas;
                            game->score = game->score;
				}
					break;

			case SDLK_RETURN:
				if (game->statusState == STATUS_STATE_HISTORIA) {
					game->statusState = STATUS_STATE_GAME;
                        break;
				}

				break;


			}
		}



		}
	}
	// pulo mais forte
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_UP] && game->statusState==STATUS_STATE_GAME)
	{
		game->man.dy -= 0.06f;
             game->man.vidas=game->man.vidas;
                game->score = game->score;
	}

	//ANDANDO
	if (state[SDL_SCANCODE_LEFT] && game->statusState==STATUS_STATE_GAME)
	{
		if ((game->man.x >= 0 && game->man.x <= 4300) || (game->man.x>4890)){
			game->man.dx -= 0.5;
		}
		if (game->man.dx < -6)
		{
			game->man.dx = -6;

		}
		game->man.aoContrario = 1;
		game->man.dimi = 0;


	}
	else if (state[SDL_SCANCODE_RIGHT] && game->statusState==STATUS_STATE_GAME) {


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



	if (game->statusState == STATUS_STATE_MENU) {

		draw_status_menu(game);
	}

if (game->statusState == STATUS_STATE_GAMEOVER) {
		game->score = 0;
		draw_status_over(game);






	}

	if (game->statusState == STATUS_STATE_CREDITS) {

		draw_status_cred(game);

	}

	if(game->statusState==STATUS_STATE_HISTORIA){

        SDL_Rect fundohist = {0,0,1280,700};
        SDL_RenderCopy(renderer,game->historia,NULL,&fundohist);


            game->tempohis++;
            if (game->tempohis == 2000)
			game->statusState = STATUS_STATE_GAME;


	}





	if (game->statusState == STATUS_STATE_GAME) {




		SDL_DestroyTexture(game->historia);
		game->historia = NULL;



		// drawing color azul
		SDL_SetRenderDrawColor(renderer, 128, 128, 255, 255);

		// limpa a janela
		SDL_RenderClear(renderer);

		// estabelece a cor branca para desenhar
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		//fundo

		if (game->fase2 == 0) {
			SDL_Rect paisage = { 0, 0,1280,700 };
			SDL_RenderCopy(renderer, game->paisa, NULL, &paisage);
		}
		else {
			SDL_Rect fundo2 = { 0,0,1280,700 };
			SDL_RenderCopy(renderer, game->paisa2, NULL, &fundo2);
		}

		for (int i = 0; i < 25; i++) {
			if (game->morcego1[i].vivo == 1) {
				SDL_Rect morcegoRect = { game->scrollx + game->morcego1[i].x,game->morcego1[i].y,(float)40,(float)40 };
				SDL_RenderCopyEx(renderer, game->morcego[game->morcego1[i].mov], NULL, &morcegoRect, 0, NULL, game->morcego1[i].aocontrario == 0);
			}
		}
		for (int i = 1; i < 5; i++) {
			if (game->voador1[i].vivo == 1) {
				SDL_Rect voador1Rect = { game->scrollx + game->voador1[i].x,game->voador1[i].y,(float)40,(float)40 };
				SDL_RenderCopyEx(renderer, game->voador[game->voador1[i].mov], NULL, &voador1Rect, 0, NULL, game->voador1[i].aocontrario == 0);
			}
		}


		if (game->man.vidas == 0) {
			game->score = 0;

		}
			sprintf(game->pontuacao, "SCORE:   %d", (int)game->score);
			SDL_Color white = { 255,255,255,255 };

			sprintf(game->pontuacao2, "SCORE:   0");



			SDL_Surface *pontos = TTF_RenderText_Solid(game->fonte2, game->pontuacao, white);
			game->scorei = SDL_CreateTextureFromSurface(game->renderer, pontos);
			SDL_FreeSurface(pontos);




			//piso


			for (int k = 0; k < 65; k++) {

				if (fabs(game->piso[k].x - game->man.x) < 1350) {
					SDL_Rect pisoRect = { game->scrollx + game->piso[k].x, game->piso[k].y,game->piso[k].w , game->piso[k].h};
					SDL_RenderCopy(renderer, game->Chao, NULL, &pisoRect);
				}
			}


			for (int u = 0; u < 70; u++) {
				if (fabs(game->plataform[u].x - game->man.x) < 1350) {
					SDL_Rect platRect = { game->scrollx + game->plataform[u].x, game->plataform[u].y,game->plataform[u].w + (float)10, game->plataform[u].h + (float)15 };
					SDL_RenderCopy(renderer, game->Plataforma, NULL, &platRect);
				}
			}


			for (int l = 30; l < 65; l++) {
				if (fabs(game->piso2[l].x - game->man.x) < 1350) {
					SDL_Rect piso1Rect = { game->scrollx + game->piso2[l].x, game->piso2[l].y,game->piso[l].w, game->piso[l].h };
					SDL_RenderCopy(game->renderer, game->chaomapa2, NULL, &piso1Rect);
				}
			}

			for (int p = 0; p < 70; p++) {


					SDL_Rect plat2Rect = { game->scrollx + game->plataforma2[p].x, game->plataforma2[p].y,game->plataform[p].w + (float)10, game->plataform[p].h + (float) 15 };
					SDL_RenderCopy(game->renderer, game->plataformamapa2, NULL, &plat2Rect);

			}


			for (int i = 1; i < 8; i++) {


				if (game->Star[i].visivel == 1 && fabs(game->Star[i].x - game->man.x) < 1350) {
					SDL_Rect starRect = { game->scrollx + game->Star[i].x, game->Star[i].y,game->Star[i].w, game->Star[i].h };
					SDL_RenderCopy(renderer, game->estrela, NULL, &starRect);
				}
			}
			for (int i = 0; i < 16; i++) {
				if (i < 5) {
					if (game->inimigo[i].vivo == 1 && fabs(game->inimigo[i].xe - game->man.x) < 1350) {
						SDL_Rect inimigoRect = { game->scrollx + game->inimigo[i].xe, game->inimigo[i].ye,(float)40,(float)70 };
						SDL_RenderCopyEx(renderer, game->enemy[game->inimigo[i].mov], NULL, &inimigoRect, 0, NULL, game->inimigo[i].aocontrario == 0);
					}
				}

					//mov2
					if (i >= 5) {
						if (game->inimigo[i].vivo == 1 && fabs(game->inimigo[i].xe - game->man.x) < 1350) {
							SDL_Rect inimigoRect = { game->scrollx + game->inimigo[i].xe, game->inimigo[i].ye,(float)40,(float)70 };
							SDL_RenderCopyEx(renderer, game->enemy[game->inimigo[i].mov2], NULL, &inimigoRect, 0, NULL, game->inimigo[i].aocontrario == 0);
						}
					}


			}


			if (game->cordachao == 0) {
				SDL_Rect cordatRect = { game->scrollx + game->corda1.x,game->corda1.y, 40,40 };
				SDL_RenderCopy(renderer, game->corda, NULL, &cordatRect);
			}







			SDL_Rect hudRect = { 0,0,1280,80 };
			SDL_RenderCopy(renderer, game->hudi, NULL, &hudRect);

			SDL_Rect placaRect = { game->scrollx + 3938,(float)565,(float)50,(float)50 };
			SDL_RenderCopy(renderer, game->placacorda, NULL, &placaRect);

            SDL_Rect placagasRect = { game->scrollx + 10050,(float)565,(float)50,(float)50 };
			SDL_RenderCopy(renderer, game->placagas, NULL, &placagasRect);



			for (int i = 0; i < 3; i++) {
				if (game->heart[i].visivel == 1) {

					if (i == 0) {
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

			SDL_Rect vidastRect = { 50,15,160,65 };
			SDL_RenderCopy(renderer, game->vidasti, NULL, &vidastRect);




			if (game->gasolina == 0) {

				SDL_Rect rects = { game->scrollx + 7015,(float)615,(float)40,(float)40 };
				SDL_RenderCopy(renderer, game->gas, NULL, &rects);



			}
			SDL_Rect hud13Rect = { game->scrollx + 10100,480,250,200 };
			SDL_RenderCopy(renderer, game->navei, NULL, &hud13Rect);


// desenha um retangulo no personagem
			SDL_Rect rect = { game->scrollx + game->man.x, game->man.y,(float)55,(float)85 };
			SDL_RenderCopyEx(renderer, game->Boneco[game->man.mov], NULL, &rect, 0, NULL, (game->man.aoContrario == 1));



			//desenha retangulo tiro



















		}


		if (game->pont == 0) {


			Mix_VolumeMusic(0);
			Mix_VolumeChunk(game->menusom, 0);
			Mix_VolumeChunk(game->hit, 0);
		}
		else
			Mix_VolumeMusic(5);
		Mix_VolumeChunk(game->menusom, 4);
		Mix_VolumeChunk(game->hit, 4);

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

	window = SDL_CreateWindow("Arret", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 700, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	//fonte
	TTF_Init();

	gameState.renderer = renderer;

	LoadGame(&gameState);


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

    SDL_DestroyTexture(gameState.placagas);
	SDL_DestroyTexture(gameState.gas);
	SDL_DestroyTexture(gameState.navei);
	SDL_DestroyTexture(gameState.voador[1]);
	SDL_DestroyTexture(gameState.voador[0]);
	SDL_DestroyTexture(gameState.corda);
	SDL_DestroyTexture(gameState.placacorda);
	SDL_DestroyTexture(gameState.morcego[1]);
	SDL_DestroyTexture(gameState.morcego[0]);
	SDL_DestroyTexture(gameState.hudi);
	SDL_DestroyTexture(gameState.vidasi);
	SDL_DestroyTexture(gameState.vidasti);
	SDL_DestroyTexture(gameState.enemy[0]);
	SDL_DestroyTexture(gameState.enemy[1]);
	SDL_DestroyTexture(gameState.enemy[5]);
	SDL_DestroyTexture(gameState.enemy[4]);
	SDL_DestroyTexture(gameState.paisa2);
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
	Mix_FreeMusic(gameState.musicafundo);
	Mix_FreeChunk(gameState.menusom);
	Mix_FreeChunk(gameState.hit);
	Mix_CloseAudio();
	//Fecha o TTF

	TTF_Quit();



	//limpa
	SDL_Quit();
	return 0;
}
