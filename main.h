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
#define GAME_STATUS_FIM 6
#define MAX_TIROS 10

typedef struct {
	float xv, yv, wv, hv, visivel;
}Vida;

typedef struct {
	float xe, ye, we, he, vivo,vidas, baseX, baseY, mode,dxe;
	int  aocontrario, phase,mov,mov2;

} Enemy;

typedef struct {
	float x, y, w, h, vivo, vidas, baseX, baseY, mode, dx;
	int  aocontrario, phase, mov;
} Morcego;

typedef struct {
	float x, y, h, w,baseX,baseY;
	int starviva,visivel,mode;
}Estrela;

typedef struct {
	float x, y;
} Corda ;

typedef struct {
	float x, y;
} Gaso;



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
	float x, y, w, h;
}Nave;


typedef struct {
	float x, y, w, h, vivo, vidas, baseX, baseY, mode, dx;
	int  aocontrario, phase, mov;
}Passaro;


FILE *f;

typedef struct {
	float scrollx;



	
	Nave nave2;
	Passaro voador1[10];

	Gaso gasolin;

	Corda corda1;
	//fundo
	Paisagem paisagem;
	//players
	Man man;
	//enfeite
	Enemy inimigo[20];
	Vida heart[3];
	Piso piso[100];
	Plat plataform[100];
	Logo logoi;
	Estrela Star[100];
	Morcego morcego1[50];

	Piso piso2[100];
	Piso plataforma2[100];
	char pontuacao[100];
	
	SDL_Texture *navei;
	SDL_Texture *tirotext;
	SDL_Texture *gas;
	int gasolina;
	int n, n1, n2, n3, aux;

	//IMAGENS INGAME mapa 1
	SDL_Texture *sairgoi3;
	SDL_Texture *voltarfim;
	SDL_Texture *pontof1i2;
	SDL_Texture *sairgoi4;
	SDL_Texture *voltargoi2;
	SDL_Texture *fundofim;

	SDL_Texture *nave;
	SDL_Texture *pontof1i;
	SDL_Texture *pontof2i;
	SDL_Texture *corda;
	SDL_Texture *placacorda;
	SDL_Texture *hudi;
	SDL_Texture *vidasti;
	SDL_Texture *vidasi;
	SDL_Texture *enemy[6];
	SDL_Texture *tiro[MAX_TIROS];
	SDL_Texture *logomenu1;
	SDL_Texture *logomenu;
	SDL_Texture *logo;
	SDL_Texture *paisa;
	SDL_Texture *paisa2;
	SDL_Texture *Boneco[3];
	SDL_Texture *Chao;
	SDL_Texture *star;
	SDL_Texture *Plataforma;
	SDL_Texture *fundocontrole;
	SDL_Texture *estrela;
	SDL_Texture *scorei;
	
	SDL_Texture *voador[2];
	// ingame mapa 2
	SDL_Texture *chaomapa2;
	SDL_Texture *plataformamapa2;
	SDL_Texture *fundomapa2;
	SDL_Texture *morcego[2];
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
	SDL_Texture *rankingi;
	SDL_Texture *rankingi1;
	int fase2;
	

	int loadtext;

	int iden;
	int labelw, labelh;
	int sairw, sairh;
	int configw, configh;
	int novow, novoh;
	int logow, logoh;
	int credw, credh;
	int cred1w, cred1h;
	int tempocred;
	int sobaudio;
	int cordachao;
	int sobvoltarfim;
	int sobsairfim;

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
	SDL_Texture *sairconfig;
	SDL_Texture *voltarconfig;
	SDL_Texture *configfundo;
	SDL_Texture *tick;
	SDL_Texture *voltarconfig1;
	SDL_Texture *sairconfig1;

	int sobtick;
	int pont;
	int sobsairm, sobvoltarm;
	int creditosw, creditosh;
	int vitorw, vitorh;
	int ricardow, ricardoh;
	int guilhermew, guilhermeh;
	int voltarmenuw, voltarmenuh;
	int devsw, devsh;
	int recordeh, recordew;


	SDL_Texture *audioi;
	// menu gameover
	SDL_Texture *textoi;
	SDL_Texture *voltargoi;
	SDL_Texture *sairgoi;
	SDL_Texture *fundogo;
	SDL_Texture *voltargoi1;
	SDL_Texture *sairgoi1;
	int sobvoltargo;
	int sobsairgo;
	
	 char text[10];
	
	Sint32 cursor;
	 Sint32 selection_len;


	 Mix_Music *musicafundo;

	// INFO DO MOUSE
	int mousex, mousey;

	//INFO DO MOUSE NO MENU
	int sobconti;
	int sobnovo;
	int sobconfig;
	int sobsair;
	int sobcredi;
	int sobranking;
	//INFO DO MOUSE NOS CREDITOS

	int sobvoltar;
	// som
	
	Mix_Chunk *menusom;

	Mix_Chunk *hit;

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
