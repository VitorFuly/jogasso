#include <stdio.h>
#include "main.h"


#include <stdio.h>
#include "main.h"
#include "SDL_ttf.h"
#include "SDL.h"
#include "SDL_image.h"

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
	SDL_Surface *tmp = TTF_RenderText_Blended(game->fonte2, "Arret", red);
	game->labelw = tmp->w;
	game->labelh = tmp->h;
	game->label = SDL_CreateTextureFromSurface(game->renderer, tmp);
	SDL_FreeSurface(tmp); 

	SDL_Surface *novoi = TTF_RenderText_Blended(game->fonte3,"Novo", black);
	game->novow = novoi->w;
	game->novoh = novoi->h;
	game->novo = SDL_CreateTextureFromSurface(game->renderer, novoi);
	SDL_FreeSurface(novoi);

	SDL_Surface *configi = TTF_RenderText_Blended(game->fonte3, "Config", black);
	game->configw = configi->w;
	game->configh = configi->h;
	game->config = SDL_CreateTextureFromSurface(game->renderer, configi);
	SDL_FreeSurface(configi);

	SDL_Surface *conti = TTF_RenderText_Blended(game->fonte3, "Continue", black);
	game->contiw = conti->w;
	game->contih = conti->h;
	game->conti = SDL_CreateTextureFromSurface(game->renderer, conti);
	SDL_FreeSurface(conti);

	SDL_Surface *sairi = TTF_RenderText_Blended(game->fonte3, "Sair", black);
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
	SDL_Renderer *renderer = game->renderer;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderClear(game->renderer);
	
	SDL_Rect fundomenuRect = {0,0,800,600 };
	SDL_RenderCopy(renderer, game->logomenu, NULL, &fundomenuRect);

	SDL_Rect logoRect = { 176,72,63,63 };
	SDL_RenderCopy(renderer, game->logo, NULL, &logoRect);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_Rect textRect = {250,71,game->labelw,game->labelh};
	SDL_RenderCopy(renderer, game->label, NULL, &textRect);

	SDL_Rect contiRect = { 35,235,game->contiw,game->contih };
	SDL_RenderCopy(renderer, game->conti, NULL, &contiRect);

	SDL_Rect novoRect = { 35,270,game->novow,game->novoh };
	SDL_RenderCopy(renderer, game->novo, NULL, &novoRect);

	SDL_Rect configRect = { 35,305,game->configw,game->configh };
	SDL_RenderCopy(renderer, game->config, NULL, &configRect);


	SDL_Rect sairRect = { 35,340,game->sairw,game->sairh };
	SDL_RenderCopy(renderer, game->sair, NULL, &sairRect);

	
	
	

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
	
}
