#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>


#pragma once


void init_status_over(GameState *game);
void draw_status_over(GameState *game);
void shutdown_status_over(GameState *game);

void init_status_menu(GameState *gameState);

void draw_status_menu(GameState *gameState);

void shutdown_status_menu(GameState *gameState);

void init_status_cred(GameState *gameState);
void draw_status_cred(GameState *gameState);
void shutdown_status_cred(GameState *gameState);



void init_status_fim(GameState *game);
void draw_status_fim(GameState *game);
void shutdown_status_fim(GameState *game);


void init_status_config(GameState *game);
void draw_status_config(GameState *game);
void shutdown_status_config(GameState *game);



