#include <stdio.h>
#include "main.h"
#include <stdio.h>
#include "main.h"
#include "SDL_ttf.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
void init_status_vidas(GameState *game) {



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

	SDL_Surface *conti = TTF_RenderText_Solid(game->fonte3, "Continue", black);
	game->contiw = conti->w;
	game->contih = conti->h;
	game->conti = SDL_CreateTextureFromSurface(game->renderer, conti);
	SDL_FreeSurface(conti);

	SDL_Surface *conti1 = TTF_RenderText_Solid(game->fonte3, "Continue", red);
	game->contiw = conti1->w;
	game->contih = conti1->h;
	game->conti1 = SDL_CreateTextureFromSurface(game->renderer, conti1);
	SDL_FreeSurface(conti1);

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
void draw_status_vidas(GameState *game) {

	SDL_Color red = { 255,0,0,255 };

	SDL_Renderer *renderer = game->renderer;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderClear(game->renderer);

	SDL_Rect fundomenuRect = { 0,0,800,600 };
	SDL_RenderCopy(renderer, game->logomenu, NULL, &fundomenuRect);

	SDL_Rect logoRect = { 176,72,63,63 };
	SDL_RenderCopy(renderer, game->logo, NULL, &logoRect);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_Rect textRect = { 250,71,game->labelw,game->labelh };
	SDL_RenderCopy(renderer, game->label, NULL, &textRect);

	SDL_Rect contiRect = { 35,235,game->contiw,game->contih };
	SDL_RenderCopy(renderer, game->conti, NULL, &contiRect);

	SDL_Rect novoRect = { 35,270,game->novow,game->novoh };
	SDL_RenderCopy(renderer, game->novo, NULL, &novoRect);

	SDL_Rect configRect = { 35,305,game->configw,game->configh };
	SDL_RenderCopy(renderer, game->config, NULL, &configRect);


	SDL_Rect sairRect = { 35,340,game->sairw,game->sairh };
	SDL_RenderCopy(renderer, game->sair, NULL, &sairRect);

	if(game->sobconti == 1) {
		SDL_Rect conti1Rect = { 33,234,game->contiw + 2,game->contih + 2 };
		SDL_RenderCopy(renderer, game->conti1, NULL, &conti1Rect);

	}
	if (game->sobnovo == 1) {
		SDL_Rect novo1Rect = { 33,272,game->novow + 2,game->novoh + 2 };
		SDL_RenderCopy(renderer, game->novo1, NULL, &novo1Rect);

	}
	if (game->sobconfig == 1) {
		SDL_Rect config1Rect = { 33,303,game->configw + 2,game->configh + 2 };
		SDL_RenderCopy(renderer, game->config1, NULL, &config1Rect);

	}
	if (game->sobsair == 1) {
		SDL_Rect sair1Rect = { 33,338,game->sairw + 2,game->sairh + 2 };
		SDL_RenderCopy(renderer, game->sair1, NULL, &sair1Rect);

	}




}
		



	
void shutdown_status_vidas(GameState *game) {
			SDL_DestroyTexture(game->logomenu);
			game->logomenu = NULL;
			SDL_DestroyTexture(game->conti);
			game->conti = NULL;
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
			SDL_DestroyTexture(game->conti1);
			game->conti1 = NULL;
			SDL_DestroyTexture(game->conti);
			game->conti = NULL;
			SDL_DestroyTexture(game->novo1);
			game->novo1 = NULL;
			SDL_DestroyTexture(game->config1);
			game->config1 = NULL;
			SDL_DestroyTexture(game->sair1);
			game->sair1 = NULL;
	
	}
