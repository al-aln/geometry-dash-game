#include "game.h"
#include <raylib.h>

GameRenderInfo_t RenderInfo = {};
GameState_t GameState = {};
GameInput_t GameInput = {};

int main() {
  init_game(&GameState);

  InitWindow(RenderInfo.DisplaySettings.width, RenderInfo.DisplaySettings.height, "GDGame");

  SetTargetFPS(60);
  
   while (!WindowShouldClose()) {
    update_game(&GameState, &GameInput);
    render_game(&RenderInfo, &GameState);
  }
  CloseWindow();
  return 0;
}
