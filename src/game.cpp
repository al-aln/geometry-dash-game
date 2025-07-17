
#include "game.h"
#include <SDL3/SDL_render.h>

void update_game() {
  update_player_location();
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
