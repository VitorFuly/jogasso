#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL_mixer.h"


#define STATUS_STATE_MENU 0
#define STATUS_STATE_GAME 1	
#define STATUS_STATE_GAMEOVER 2
#define STATUS_STATE_CONFIG 3
#define STATUS_STATE_CREDITS 4
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
	SDL_Texture *logomenu1;
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
	SDL_Texture *menucred;
	SDL_Texture *novo1;
	SDL_Texture *config;
	SDL_Texture *config1;
	SDL_Texture *sair;
	SDL_Texture *sair1;
	SDL_Texture *cred;
	SDL_Texture *cred1;

	int labelw, labelh;
	int contiw, contih;
	int sairw, sairh;
	int configw, configh;
	int novow, novoh;
	int logow, logoh;
	int credw, credh;
	int cred1w, cred1h;

	// MENU CREDITOS
	SDL_Texture *creditosi;
	SDL_Texture *creditosi1;
	SDL_Texture *guilhermei;
	SDL_Texture *guilhermei1;
	SDL_Texture *ricardoi;
	SDL_Texture *ricardoi1;
	SDL_Texture *vitori;
	SDL_Texture *vitori1;
	SDL_Texture *voltarmi;
	SDL_Texture *voltarmi1;
	SDL_Texture *devsi;
	SDL_Texture *devsi1;



	int creditosw, creditosh;
	int vitorw, vitorh;
	int ricardow, ricardoh;
	int guilhermew, guilhermeh;
	int voltarmenuw, voltarmenuh;
	int devsw, devsh;


	

	// INFO DO MOUSE
	int mousex, mousey;

	//INFO DO MOUSE NO MENU
	int sobconti;
	int sobnovo;
	int sobconfig;
	int sobsair;
	int sobcredi;

	//INFO DO MOUSE NOS CREDITOS

	int sobvoltar;
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
