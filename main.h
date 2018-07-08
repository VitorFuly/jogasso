#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

#define _CRT_SECURE_NO_WARNINGS
#define STATUS_STATE_MENU 0
#define STATUS_STATE_GAME 1	
#define STATUS_STATE_GAMEOVER 2
#define STATUS_STATE_CONFIG 3
#define STATUS_STATE_CREDITS 4
#define STATUS_STATE_CONTROLES 5
#define MAX_TIROS 10

typedef struct {
	float xv, yv, wv, hv, visivel;
}Vida;

typedef struct {
	float xe, ye, we, he, vivo,vidas, baseX, baseY, mode,dxe;
	int  aocontrario, phase,mov;

} Enemy;

typedef struct {
	float xt, yt,dxt,fimtiro;
}Tiro;


typedef struct {
	float x, y, h, w,baseX,baseY;
	int starviva,visivel,mode;
}Estrela;


typedef struct {
	float x, y, h, w;
} Plat;

typedef struct {
	float logox, logoy;
}Logo;

typedef struct {
	float x, y;
} Paisagem;
typedef struct {

	float x, y;
	float dx, dy;
	short vidas;
	char *name;
	int mov;
	int noChao, dimi, aoContrario,atirando,atirandocontrario;
} Man;
typedef struct {
	float x, y, w, h;
}Piso;

typedef struct {
	float x, y, w, h;
}HUD;


typedef struct {
	float scrollx;
	//fundo
	Paisagem paisagem;
	//players
	Man man;
	//enfeite
	Enemy inimigo[10];
	Vida heart[3];
	Piso piso[100];
	Plat plataform[100];
	Logo logoi;
	Estrela Star[100];
	

	Piso piso1[100];


	Tiro *shot[MAX_TIROS];

	SDL_Texture *tirotext;




	//IMAGENS INGAME mapa 1
	
	SDL_Texture *hudi;
	SDL_Texture *vidasti;
	SDL_Texture *vidasi;
	SDL_Texture *enemy[2];
	SDL_Texture *tiro[MAX_TIROS];
	SDL_Texture *logomenu1;
	SDL_Texture *logomenu;
	SDL_Texture *logo;
	SDL_Texture *paisa;
	SDL_Texture *Boneco[4];
	SDL_Texture *Chao;
	SDL_Texture *star;
	SDL_Texture *Plataforma;
	SDL_Texture *fundocontrole;
	SDL_Texture *estrela;
	SDL_Texture *scorei;


	// ingame mapa 2
	SDL_Texture *Chao2;



	//MENU INICIAR
	SDL_Texture *label;
	SDL_Texture *novo;
	SDL_Texture *menucred;
	SDL_Texture *novo1;
	SDL_Texture *config;
	SDL_Texture *config1;
	SDL_Texture *sair;
	SDL_Texture *sair1;
	SDL_Texture *cred;
	SDL_Texture *cred1;
	

	
	int iden;
	int labelw, labelh;
	int sairw, sairh;
	int configw, configh;
	int novow, novoh;
	int logow, logoh;
	int credw, credh;
	int cred1w, cred1h;
	int tempocred;
	int encontrado;


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




	// menu gameover
	SDL_Texture *voltargoi;
	SDL_Texture *sairgoi;
	SDL_Texture *fundogo;
	SDL_Texture *voltargoi1;
	SDL_Texture *sairgoi1;
	int sobvoltargo;
	int sobsairgo;



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
	int score;
	//renderer
	SDL_Renderer *renderer;
}GameState;

//referencias
void doRender(SDL_Renderer *renderer, GameState *game);
