#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "main.h"
#include <stdio.h>
#include "SDL_ttf.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"


void init_status_menu(GameState *game) {

	

	SDL_Surface *menu = NULL;
	menu = IMG_Load("logo.png");
	if (menu == NULL) {
		printf("Nao foi possivel achar logo.png");
		SDL_Quit();
		exit(1);
	}
	game->logo = SDL_CreateTextureFromSurface(game->renderer, menu);

	SDL_FreeSurface(menu);


	SDL_Color white = { 255,255,255,255 };
	SDL_Color red = { 255,0,0,255 };
	SDL_Color black = { 0,0,0,0 };
	SDL_Surface *tmp = TTF_RenderText_Solid(game->fonte2, "Arret", red);
	game->labelw = tmp->w;
	game->labelh = tmp->h;
	game->label = SDL_CreateTextureFromSurface(game->renderer, tmp);
	SDL_FreeSurface(tmp);

	SDL_Surface *novoi = TTF_RenderText_Solid(game->fonte3, "Novo", black);
	game->novow = novoi->w;
	game->novoh = novoi->h;
	game->novo = SDL_CreateTextureFromSurface(game->renderer, novoi);
	SDL_FreeSurface(novoi);

	SDL_Surface *configi = TTF_RenderText_Solid(game->fonte3, "Config", black);
	game->configw = configi->w;
	game->configh = configi->h;
	game->config = SDL_CreateTextureFromSurface(game->renderer, configi);
	SDL_FreeSurface(configi);


	SDL_Surface *novo1 = TTF_RenderText_Solid(game->fonte3, "Novo", red);
	game->novow = novo1->w;
	game->novoh = novo1->h;
	game->novo1 = SDL_CreateTextureFromSurface(game->renderer, novo1);
	SDL_FreeSurface(novo1);

	SDL_Surface *config1 = TTF_RenderText_Solid(game->fonte3, "Config", red);
	game->configw = config1->w;
	game->configh = config1->h;
	game->config1 = SDL_CreateTextureFromSurface(game->renderer, config1);
	SDL_FreeSurface(config1);


	SDL_Surface *sair1 = TTF_RenderText_Solid(game->fonte3, "Sair", red);
	game->sairw = sair1->w;
	game->sairh = sair1->h;
	game->sair1 = SDL_CreateTextureFromSurface(game->renderer, sair1);
	SDL_FreeSurface(sair1);
	
		SDL_Surface *sairi = TTF_RenderText_Solid(game->fonte3, "Sair", black);
		game->sairw = sairi->w;
		game->sairh = sairi->h;
		game->sair = SDL_CreateTextureFromSurface(game->renderer, sairi);
		SDL_FreeSurface(sairi);

		SDL_Surface *credi = TTF_RenderText_Solid(game->fonte3, "Creditos", black);
		game->credw = credi->w;
		game->credh = credi->h;
		game->cred = SDL_CreateTextureFromSurface(game->renderer, credi);
		SDL_FreeSurface(credi);

		SDL_Surface *credi1 = TTF_RenderText_Solid(game->fonte3, "Creditos", red);
		game->cred1w = credi1->w;
		game->cred1h = credi1->h;
		game->cred1 = SDL_CreateTextureFromSurface(game->renderer, credi1);
		SDL_FreeSurface(credi1);

			SDL_Surface *menufundo = NULL;
			menufundo = IMG_Load("fundomenu.png");
			if (menufundo == NULL) {
				printf("Nao foi possivel achar fundofundo.png");
				SDL_Quit();
				exit(77);
			}
			game->logomenu = SDL_CreateTextureFromSurface(game->renderer, menufundo);

			SDL_FreeSurface(menufundo);

		
}
void draw_status_menu(GameState *game) {

	
	SDL_Renderer *renderer = game->renderer;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderClear(game->renderer);

	SDL_Rect fundomenuRect = { 0,0,1280,700 };
	SDL_RenderCopy(renderer, game->logomenu, NULL, &fundomenuRect);

	SDL_Rect logoRect = { 480,67,100,100 };
	SDL_RenderCopy(renderer, game->logo, NULL, &logoRect);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_Rect textRect = { 585,86,game->labelw+10,game->labelh };
	SDL_RenderCopy(renderer, game->label, NULL, &textRect);

	

	SDL_Rect novoRect = { 60,350,game->novow+50,game->novoh + 20 };
	SDL_RenderCopy(renderer, game->novo, NULL, &novoRect);

	SDL_Rect configRect = { 60,430,game->configw + 50,game->configh + 20 };
	SDL_RenderCopy(renderer, game->config, NULL, &configRect);


	SDL_Rect sairRect = { 60,590,game->sairw + 50,game->sairh + 20 };
	SDL_RenderCopy(renderer, game->sair, NULL, &sairRect);

	SDL_Rect credRect = { 60,510,game->credw + 50,game->credh + 20 };
	SDL_RenderCopy(renderer, game->cred, NULL, &credRect);


	if(game->sobnovo == 1 || game->sobconfig ==1 || game->sobsair==1 || game->sobcredi==1) {
		Mix_PlayChannel(-1, game->menusom, 0);
		
	}
	
	if (game->sobnovo >= 1) {
		SDL_Rect novo1Rect = { 59,351,game->novow + 52,game->novoh + 22 };
		SDL_RenderCopy(renderer, game->novo1, NULL, &novo1Rect);

	}
	if (game->sobconfig >= 1) {
		SDL_Rect config1Rect = { 59,431,game->configw + 52,game->configh + 22 };
		SDL_RenderCopy(renderer, game->config1, NULL, &config1Rect);

	}

	if (game->sobsair >= 1) {
		SDL_Rect sair1Rect = { 59,591,game->sairw + 52,game->sairh + 22 };
		SDL_RenderCopy(renderer, game->sair1, NULL, &sair1Rect);

	}
	if (game->sobcredi >= 1) {
		SDL_Rect menucreditosRect = { 59,511,game->cred1w + 52,game->cred1h + 22 };
		SDL_RenderCopy(renderer, game->cred1, NULL, &menucreditosRect);
	}



}
void shutdown_status_menu(GameState *game) {

			SDL_DestroyTexture(game->logomenu);
			game->logomenu = NULL;
			
			SDL_DestroyTexture(game->label);
			game->label = NULL;
			SDL_DestroyTexture(game->novo);
			game->novo = NULL;
			SDL_DestroyTexture(game->config);
			game->config = NULL;
			SDL_DestroyTexture(game->sair);
			game->sair = NULL;
			SDL_DestroyTexture(game->logo);
			game->logo = NULL;
			
			SDL_DestroyTexture(game->novo1);
			game->novo1 = NULL;
			SDL_DestroyTexture(game->config1);
			game->config1 = NULL;
			SDL_DestroyTexture(game->sair1);
			game->sair1 = NULL;
			SDL_DestroyTexture(game->menucred);
			game->menucred = NULL;
			SDL_DestroyTexture(game->cred);
			game->cred = NULL;
	
	}



void init_status_game1(GameState *game) {


	SDL_Surface *chao1 = NULL;
	chao1 = IMG_Load("chaomapa1.png");
	if (chao1 == NULL) {
		printf("Nao foi possivel achar logo.png");
		SDL_Quit();
		exit(1);
	}
	game->Chao2 = SDL_CreateTextureFromSurface(game->renderer, chao1);

	SDL_FreeSurface(chao1);



}

void draw_status_game1(GameState *game) {

	for (int i = 0; i < 20; i++) {
		game->piso1[i].h = 95;
		game->piso1[i].w = 160;
		game->piso1[i].x = i * 160.0;
		game->piso1[i].y = 650;

	}

	for (int i = 0; i < 75; i++)
	{

		SDL_Rect piso1Rect = { game->scrollx + game->piso1[i].x*1.0f, game->piso1[i].y*1.0f,game->piso1[i].w * 1.0f, game->piso1[i].h*1.0f };
		SDL_RenderCopy(game->renderer, game->Chao, NULL, &piso1Rect);

	}

}
void shutdown_status_game1(GameState *game) {

}



void init_status_cred(GameState *game) {

	//CORES

	SDL_Color white1 = { 255,255,255,255 };
	SDL_Color red1 = { 255,0,0,255 };
	SDL_Color black1 = { 0,0,0,0 };


	//CREDITOS 
	SDL_Surface *Creditos = TTF_RenderText_Solid(game->fonte2, "Creditos", red1);
	game->creditosw = Creditos->w;
	game->creditosh = Creditos->h;
	game->creditosi = SDL_CreateTextureFromSurface(game->renderer, Creditos);
	SDL_FreeSurface(Creditos);

	// DEVS
	SDL_Surface *devs = TTF_RenderText_Solid(game->fonte3, "Desenvolvedores", white1);
	game->devsw = devs->w;
	game->devsh = devs->h;
	game->devsi = SDL_CreateTextureFromSurface(game->renderer, devs);
	SDL_FreeSurface(devs);

	//GUILHERME
	SDL_Surface *guii = TTF_RenderText_Solid(game->fonte3, "Guilherme Lobo", black1);
	game->guilhermew = guii->w;
	game->guilhermeh = guii->h;
	game->guilhermei = SDL_CreateTextureFromSurface(game->renderer, guii);
	SDL_FreeSurface(guii);


	//RICARDO
	SDL_Surface *ricardo = TTF_RenderText_Solid(game->fonte3, "Ricardo Bianchi", black1);
	game->ricardow = ricardo->w;
	game->ricardoh = ricardo->h;
	game->ricardoi = SDL_CreateTextureFromSurface(game->renderer, ricardo);
	SDL_FreeSurface(ricardo);



	//VITOR
	SDL_Surface *vitor = TTF_RenderText_Solid(game->fonte3, "Vitor Fuly", black1);
	game->vitorw = vitor->w;
	game->vitorh = vitor->h;
	game->vitori = SDL_CreateTextureFromSurface(game->renderer, vitor);
	SDL_FreeSurface(vitor);



	//VOLTAR
	SDL_Surface *voltarmenu = TTF_RenderText_Solid(game->fonte3, "Voltar", black1);
	game->voltarmenuw = voltarmenu->w;
	game->voltarmenuh = voltarmenu->h;
	game->voltarmi = SDL_CreateTextureFromSurface(game->renderer, voltarmenu);
	SDL_FreeSurface(voltarmenu);

	SDL_Surface *voltarmenu1 = TTF_RenderText_Solid(game->fonte3, "Voltar", red1);
	game->voltarmenuw = voltarmenu->w;
	game->voltarmenuh = voltarmenu->h;
	game->voltarmi1 = SDL_CreateTextureFromSurface(game->renderer, voltarmenu1);
	SDL_FreeSurface(voltarmenu1);




}
void draw_status_cred(GameState *game) {
	//RENDERER

	SDL_Renderer *renderer = game->renderer;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(game->renderer);

	// FUNDO

	//ESCREVENDO OS TEXTOS EM PRETO
	SDL_Rect fundomenuRect = {0,0,1280,700};
	SDL_RenderCopy(renderer, game->logomenu, NULL, &fundomenuRect);

	SDL_Rect creditosRect = { 180,70,game->creditosw,game->creditosh };
	SDL_RenderCopy(renderer, game->creditosi, NULL, &creditosRect);

	SDL_Rect voltRect = { 80,350,game->voltarmenuw,game->voltarmenuh };
	SDL_RenderCopy(renderer, game->voltarmi, NULL, &voltRect);

	SDL_Rect devsRect = { 80,150,game->devsw,game->devsh };
	SDL_RenderCopy(renderer, game->devsi, NULL, &devsRect);

	SDL_Rect guiRect = { 80,200,game->guilhermew,game->guilhermeh };
	SDL_RenderCopy(renderer, game->guilhermei, NULL, &guiRect);

	SDL_Rect ricRect = { 80,250,game->ricardow,game->ricardoh };
	SDL_RenderCopy(renderer, game->ricardoi, NULL, &ricRect);

	SDL_Rect vitRect = { 80,300,game->vitorw,game->vitorh };
	SDL_RenderCopy(renderer, game->vitori, NULL, &vitRect);

	
	//FUNDO
	SDL_Surface *menufundo = NULL;
	menufundo = IMG_Load("fundomenu.png");
	if (menufundo == NULL) {
		printf("Nao foi possivel achar fundofundo.png");
		SDL_Quit();
		exit(77);
	}
	game->logomenu = SDL_CreateTextureFromSurface(game->renderer, menufundo);

	SDL_FreeSurface(menufundo);


	//ESCREVENDO OS TEXTOS EM VERMELHO 
	if (game->sobvoltar ==1) {
		Mix_PlayChannel(-1, game->menusom, 0);

	}



	if (game->sobvoltar >= 1) {
		SDL_Rect voltRect = { 79,349,game->voltarmenuw + 1,game->voltarmenuh + 1 };
		SDL_RenderCopy(renderer, game->voltarmi1, NULL, &voltRect);
	}

}
void shutdown_status_cred(GameState *game) {
	SDL_DestroyTexture(game->creditosi);
	game->creditosi = NULL;
	SDL_DestroyTexture(game->creditosi1);
	game->creditosi1 = NULL;
	SDL_DestroyTexture(game->devsi);
	game->devsi = NULL;
	SDL_DestroyTexture(game->devsi1);
	game->devsi1 = NULL;
	SDL_DestroyTexture(game->guilhermei);
	game->guilhermei = NULL;
	SDL_DestroyTexture(game->guilhermei1);
	game->guilhermei1 = NULL;
	SDL_DestroyTexture(game->ricardoi);
	game->ricardoi = NULL;
	SDL_DestroyTexture(game->ricardoi1);
	game->ricardoi1 = NULL;
	SDL_DestroyTexture(game->vitori);
	game->vitori = NULL;
	SDL_DestroyTexture(game->vitori1);
	game->vitori1 = NULL;
	SDL_DestroyTexture(game->voltarmi);
	game->voltarmi = NULL;
	SDL_DestroyTexture(game->voltarmi1);
	game->voltarmi1 = NULL;
	SDL_DestroyTexture(game->logomenu);
	game->logomenu = NULL;

}


void init_status_over(GameState *game) {



	
	SDL_Color white = { 255,255,255,255 };
	SDL_Color red = { 255,0,0,255 };
	SDL_Color black = { 0,0,0,0 };

	SDL_Surface *voltar=TTF_RenderText_Solid(game->fonte3, "Voltar", white);
	game->voltargoi = SDL_CreateTextureFromSurface(game->renderer, voltar);

	SDL_Surface *sairr = TTF_RenderText_Solid(game->fonte3, "Sair", white);
	game->sairgoi = SDL_CreateTextureFromSurface(game->renderer, sairr);


	SDL_Surface *voltargo1 = TTF_RenderText_Solid(game->fonte3, "Voltar", red);
	
	game->voltargoi1 = SDL_CreateTextureFromSurface(game->renderer, voltargo1);
	SDL_FreeSurface(voltargo1);


	SDL_Surface *sairgo1 = TTF_RenderText_Solid(game->fonte3, "Sair", red);

	game->sairgoi1 = SDL_CreateTextureFromSurface(game->renderer, sairgo1);
	SDL_FreeSurface(sairgo1);





	SDL_Surface *fundo1 = NULL;
	fundo1 = IMG_Load("gameover.png");
	if (fundo1 == NULL) {
		printf("nao foi possivel achar gameover.png");
		SDL_Quit();
		exit(88);
		}
	game->fundogo = SDL_CreateTextureFromSurface(game->renderer, fundo1);
	SDL_FreeSurface(fundo1);

	
	




}
void draw_status_over(GameState *game) {

	SDL_Renderer *renderer = game->renderer;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderClear(game->renderer);

	SDL_Rect fundogoRect = { 0,0,1280,700 };
	SDL_RenderCopy(game->renderer, game->fundogo, NULL, &fundogoRect);

	SDL_Rect sairgoRect = { 1040,560,100,100 };
	SDL_RenderCopy(game->renderer, game->sairgoi, NULL, &sairgoRect);

	SDL_Rect voltargoiRect = { 120,560,100,100 };
	SDL_RenderCopy(game->renderer, game->voltargoi, NULL, &voltargoiRect);

	

	if (game->sobvoltargo >= 1) {
		SDL_Rect voltRect = { 119,559,101,101 };
		SDL_RenderCopy(renderer, game->voltargoi1, NULL, &voltRect);
	}

	if (game->sobsairgo >= 1) {
		SDL_Rect sairgo1Rect = {1039,559,101,101 };
		SDL_RenderCopy(renderer, game->sairgoi1, NULL, &sairgo1Rect);
	}




}
void shutdown_status_over(GameState *game) {
	SDL_DestroyTexture(game->fundogo);
	game->fundogo = NULL;

	SDL_DestroyTexture(game->voltargoi);
	game->voltargoi = NULL;

	SDL_DestroyTexture(game->sairgoi);
	game->sairgoi = NULL;

	SDL_DestroyTexture(game->sairgoi1);
	game->sairgoi1 = NULL;

	SDL_DestroyTexture(game->voltargoi1);
	game->voltargoi1 = NULL;


	
	
	

}
