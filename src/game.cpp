
#include "game.h"
#include "raylib.h"
#include "render.h"

void update_game(GameState_t *GameState, GameInput_t *GameInput) {}

void render_game(GameRenderInfo_t *RenderInfo, GameState_t *GameState) {
  BeginDrawing();

  ClearBackground(RAYWHITE);

  // rendering background
  {
    Texture2D background = LoadTexture("../assets/textures/bkg1.png");
    DrawTextureEx(background, (Vector2){0, 0}, 0.0f, 2.0f, WHITE);
  }

  EndDrawing();
}

void draw_player(GameRenderInfo_t *RenderInfo, GameState_t *GameState) {}

void update_player(GameState_t *GameState, GameInput_t *Input) {}

void init_game(GameState_t *GameState) {
  // init_game() <-- intializes all player variables
  GameState->player_speed = 100.0F;
  GameState->x_pos = 500;
  GameState->y_pos = 500;
  GameState->is_running = true;
  //
}