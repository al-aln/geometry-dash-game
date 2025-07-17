#include "game.h"
#include "platform_sdl.h"
#include <SDL3/SDL_timer.h>


GameRenderInfo_t RenderInfo = {};
GameState_t GameState = {};

int main() {
  init_window(&RenderInfo);

  // init_game() <-- intializes all player variables
  GameState.player_speed = 5.0F;
  GameState.x_pos = 500;
  GameState.y_pos = 500;
  // 

  GameState.is_running = true;
  double last_frame = 0.0F;
  while (GameState.is_running) {
    double current_frame = (double)SDL_GetTicks() / 1000;
    RenderInfo.frame_time = current_frame - last_frame;
    last_frame = current_frame;
    handle_events(&GameState, &RenderInfo);
    update_game();
    render_game(&RenderInfo, &GameState);
  }
  return 0;
}
