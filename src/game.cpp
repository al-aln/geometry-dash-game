
#include "game.h"
#include <SDL3/SDL_render.h>

void update_game(GameState_t *GameState, GameInput_t *GameInput) {
  update_player(GameState, GameInput);
  return;
}

void render_game(GameRenderInfo_t *RenderInfo, GameState_t *GameState) {
  SDL_SetRenderDrawColor(RenderInfo->Renderer, 180, 20, 255, 255);
  SDL_RenderClear(RenderInfo->Renderer);
  draw_player(RenderInfo, GameState);
  SDL_RenderPresent(RenderInfo->Renderer);
}

void draw_player(GameRenderInfo_t *RenderInfo, GameState_t *GameState) {
  SDL_FRect r;
  r.w = 40;
  r.h = 40;
  r.x = GameState->x_pos;
  r.y = GameState->y_pos;

  SDL_SetRenderDrawColor(RenderInfo->Renderer, 0, 200, 160, 255);
  SDL_RenderFillRect(RenderInfo->Renderer, &r);
}

void update_player(GameState_t *GameState, GameInput_t *Input) {
  if (GameState->y_pos < 500) {
    GameState->y_pos += 50.0F;
  }
  if (Input->keyPressed[SDL_SCANCODE_LEFT]) {
    GameState->x_pos -= GameState->frame_time * GameState->player_speed;
  }
  if (Input->keyPressed[SDL_SCANCODE_RIGHT]) {
    GameState->x_pos += GameState->frame_time * GameState->player_speed;
  }
  if (Input->keyPressed[SDL_SCANCODE_UP]) {
    GameState->y_pos -= GameState->frame_time * GameState->player_speed;
  }
  if (Input->keyPressed[SDL_SCANCODE_DOWN]) {
    GameState->y_pos += GameState->frame_time * GameState->player_speed;
  }
  if (1) {
    GameState->player_speed += 0.1;
  }
  
  return;
}

void init_game(GameState_t *GameState) {
  // init_game() <-- intializes all player variables
  GameState->player_speed = 100.0F;
  GameState->x_pos = 500;
  GameState->y_pos = 500;
  //
}