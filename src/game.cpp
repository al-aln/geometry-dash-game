
#include "game.h"
#include <SDL3/SDL_render.h>

void update_game() {}

void render_game(GameRenderInfo_t *RenderInfo, GameState_t *GameState) {
  SDL_SetRenderDrawColor(RenderInfo->Renderer, 180, 20, 255, 255);
  SDL_RenderClear(RenderInfo->Renderer);
  {
    SDL_FRect r;
    r.w = 20;
    r.h = 20;
    r.x = RenderInfo->DisplaySettings.width / 2;
    r.y = RenderInfo->DisplaySettings.height / 2;

    SDL_RenderFillRect(RenderInfo->Renderer, &r);
    SDL_SetRenderDrawColor(RenderInfo->Renderer, 100, 50, 0, 255);
  }

  SDL_RenderPresent(RenderInfo->Renderer);
}