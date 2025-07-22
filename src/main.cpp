#include "game.h"
#include "platform_sdl.h"
#include <SDL3/SDL_timer.h>


GameRenderInfo_t RenderInfo = {};
GameState_t GameState = {};
GameInput_t GameInput = {};

int main() {
  init_window(&RenderInfo);
  init_game(&GameState);

  GameState.is_running = true;
  double last_frame = 0.0F;
  while (GameState.is_running) {
    double current_frame = (double)SDL_GetTicks() / 1000;
    RenderInfo.frame_time = current_frame - last_frame;
    GameState.frame_time = RenderInfo.frame_time;
    last_frame = current_frame;
    handle_events(&GameState, &RenderInfo, &GameInput);
    update_game(&GameState ,&GameInput);
    render_game(&RenderInfo, &GameState);
  }
  return 0;
}
