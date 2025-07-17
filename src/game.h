#pragma once // this avoids including the file more than once

struct SDL_Window;
struct SDL_Renderer;

struct DisplaySettings_t {
  int width;
  int height;
  int refresh_rate;
};

struct GameRenderInfo_t {
  SDL_Window *Window;
  SDL_Renderer *Renderer;
  double frame_time;
  DisplaySettings_t DisplaySettings;
};

struct GameState_t {
  bool is_running;
  int delta_x;
  int delta_y;
};

void update_game();

void render_game(GameRenderInfo_t *RenderInfo, GameState_t *GameState);