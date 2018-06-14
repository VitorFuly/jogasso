#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"

#define STATUS_STATE_VIDAS 0
#define STATUS_STATE_GAME 1	
#define STATUS_STATE_GAMEOVER 2


typedef struct {

	float x, y;
	float dx, dy;
	short vidas;
	char *name;
	int mov;
	int noChao, dimi, aoContrario;
}
Man;
typedef struct {
	float x, y, w, h;
}
Piso;
typedef struct {
	//players
	Man man;
	//enfeite
	Piso piso[100];


	//imagens
	SDL_Texture *Boneco[2];
	SDL_Texture *Chao[100];
	SDL_Texture *Star;
	SDL_Texture *label;
	int labelw, labelh;


	//Font
	TTF_Font *fonte;
	// tempo
	int tempo;
	int statusState;
	//renderer
	SDL_Renderer *renderer;
}
GameState;

//referencias
void doRender(SDL_Renderer *renderer, GameState *game);
