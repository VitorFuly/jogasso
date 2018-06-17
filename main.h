#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

#define STATUS_STATE_VIDAS 0
#define STATUS_STATE_GAME 1	
#define STATUS_STATE_GAMEOVER 2

typedef struct {
	float logox, logoy;
}
Logo;

typedef struct {
	float x, y;
} Paisagem;
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
	float scrollx;
	//fundo
	Paisagem paisagem;
	//players
	Man man;
	//enfeite
	Piso piso[100];
	Logo logoi;

	//IMAGENS INGAME
	SDL_Texture *logomenu;
	SDL_Texture *logo;
	SDL_Texture *paisa;
	SDL_Texture *Boneco[2];
	SDL_Texture *Chao;
	SDL_Texture *Star;

	//MENU INICIAR
	SDL_Texture *label;
	SDL_Texture *conti;
	SDL_Texture *conti1;
	SDL_Texture *novo;
	SDL_Texture *novo1;
	SDL_Texture *config;
	SDL_Texture *config1;
	SDL_Texture *sair;
	SDL_Texture *sair1;
	int labelw, labelh;
	int contiw, contih;
	int sairw, sairh;
	int configw, configh;
	int novow, novoh;
	int logow, logoh;


	// MENU CONFIG
	

	// INFO DO MOUSE
	int mousex, mousey;
	int sobconti;
	int sobnovo;
	int sobconfig;
	int sobsair;
	// som
	
	Mix_Chunk *menusom;



	//Font
	TTF_Font *fonte;
	TTF_Font *fonte2;
	TTF_Font *fonte3;
	TTF_Font *fonte4;

	// tempo
	int tempo;
	int statusState;

	//renderer
	SDL_Renderer *renderer;
}
GameState;

//referencias
void doRender(SDL_Renderer *renderer, GameState *game);
