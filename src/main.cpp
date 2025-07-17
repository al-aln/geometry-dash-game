#include "game.h"
#include "platform_sdl.h"
#include <SDL3/SDL_timer.h>


GameRenderInfo_t RenderInfo = {};
GameState_t GameState = {};

int main() {
  initWindow(&RenderInfo);
  GameState.is_running = true;
  double last_frame = 0.0F;
  while (GameState.is_running) {
    double current_frame = (double)SDL_GetTicks() / 1000;
    RenderInfo.frame_time = current_frame - last_frame;
    last_frame = current_frame;
    handleEvents(&GameState, &RenderInfo);
    update_game();
    render_game(&RenderInfo, &GameState);
  }
  return 0;
}
