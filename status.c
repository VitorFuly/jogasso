#include <stdio.h>
#include "main.h"


#include <stdio.h>
#include "main.h"
#include "SDL_ttf.h"
#include "SDL.h"
#include "SDL_image.h"

void init_status_vidas(GameState *game) {
	SDL_Color white = { 255,255,255,255 };
	SDL_Surface *tmp = TTF_RenderText_Blended(game->fonte, "Arret", white);
	game->labelw = tmp->w;
	game->labelh = tmp->h;
	game->label = SDL_CreateTextureFromSurface(game->renderer, tmp);
	SDL_FreeSurface(tmp); 

}
void draw_status_vidas(GameState *game) {
	SDL_Renderer *renderer = game->renderer;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderClear(game->renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_Rect textRect = { 320,240-game->labelw,game->labelw,game->labelh};
	SDL_RenderCopy(renderer, game->label, NULL, &textRect);

}
void shutdown_status_vidas(GameState *game) {
	SDL_DestroyTexture(game->label);
	game->label = NULL;

}
