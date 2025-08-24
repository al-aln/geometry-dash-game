#ifndef GAME_H
#define GAME_H


struct DisplaySettings_t {
  int width = 1280;
  int height = 720;
  int refresh_rate;
};

typedef struct GameInput_t {
    const bool *key;
    // bool keyState[SDL_SCANCODE_COUNT];
    // bool prevKeyState[SDL_SCANCODE_COUNT];
    // bool keyPressed[SDL_SCANCODE_COUNT];
    // bool keyReleased[SDL_SCANCODE_COUNT];

    float mouse_x;
    float mouse_y;
    float mouse_delta_x;
    float mouse_delta_y;
    bool mouse_left_pressed;
    bool mouse_left_released;
    bool mouse_right_pressed;
    bool mouse_right_released;
} GameInput_t;

struct GameRenderInfo_t {
  double frame_time;
  DisplaySettings_t DisplaySettings;
};

struct GameState_t {
  bool is_running;
  double frame_time;
  int delta_x;
  int delta_y;

  float player_speed;
  float x_pos;
  float y_pos;
};

void update_game(GameState_t *GameState, GameInput_t *GameInput);

void render_game(GameRenderInfo_t *RenderInfo, GameState_t *GameState);

void draw_player(GameRenderInfo_t *RenderInfo, GameState_t *GameState);

void update_player(GameState_t *GameState, GameInput_t *GameInput);

void init_game(GameState_t * GameState);

#endif