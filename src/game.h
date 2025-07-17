#pragma once // this avoids including the file more than once

struct SDL_Window;
struct SDL_Renderer;

struct DisplaySettings_t {
  int width = 1280;
  int height = 720;
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

  float player_speed;
  float x_pos;
  float y_pos;
};

void update_game();

void render_game(GameRenderInfo_t *RenderInfo, GameState_t *GameState);

void draw_player(GameRenderInfo_t *RenderInfo, GameState_t *GameState);