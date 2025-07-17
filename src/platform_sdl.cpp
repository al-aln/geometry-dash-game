#include "game.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_scancode.h>
#include <SDL3/SDL_video.h>

#define GLOBAL static

GLOBAL SDL_Event event;

int init_window(GameRenderInfo_t *RenderInfo) {

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

  SDL_Window *window = SDL_CreateWindow(
      "Geometry dash game", RenderInfo->DisplaySettings.width,
      RenderInfo->DisplaySettings.height, SDL_WINDOW_RESIZABLE);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, 0);

  if (window && renderer) {
    RenderInfo->Window = window;
    RenderInfo->Renderer = renderer;
    return 0;
  }
  return -1;
}

void handle_keyboard_event(GameState_t *GameState, const SDL_Event &Event) {
  if (Event.key.scancode == SDL_SCANCODE_ESCAPE) {
    GameState->is_running = false;
  }
  if (Event.key.scancode == SDL_SCANCODE_LEFT) {
    GameState->x_pos -= GameState->player_speed;
  }
  if (Event.key.scancode == SDL_SCANCODE_RIGHT) {
    GameState->x_pos += GameState->player_speed;
  }
  if (Event.key.scancode == SDL_SCANCODE_UP) {
    GameState->y_pos -= GameState->player_speed;
  }
  if (Event.key.scancode == SDL_SCANCODE_DOWN) {
    GameState->y_pos += GameState->player_speed;
  }
}

void handle_mouse_event(GameState_t *GameState, const SDL_Event &Event) {
  switch (Event.type) {
  case SDL_EVENT_MOUSE_MOTION:
    GameState->delta_x = Event.motion.xrel;
    GameState->delta_y = Event.motion.yrel;
    break;
  case SDL_EVENT_KEY_DOWN:
  case SDL_EVENT_MOUSE_BUTTON_DOWN:
    break;
  default:
    break;
  }
}

void handle_window_event(GameRenderInfo_t *RenderInfo) {
  // Resize window
  SDL_GetWindowSize(RenderInfo->Window, &RenderInfo->DisplaySettings.width,
                    &RenderInfo->DisplaySettings.height);
  SDL_UpdateWindowSurface(RenderInfo->Window);
}

void handle_events(GameState_t *GameState, GameRenderInfo_t *RenderInfo) {
  while (SDL_PollEvent(&event)) {
    // ImGui_ImplSDL3_ProcessEvent(&event);
    switch (event.type) {
    case SDL_EVENT_QUIT:
      GameState->is_running = false;
      break;
    case SDL_EVENT_WINDOW_RESIZED:
      handle_window_event(RenderInfo);
      break;
    case SDL_EVENT_KEY_DOWN: /* FALLTHROUGH */
    case SDL_EVENT_KEY_UP:
      handle_keyboard_event(GameState, event);
      break;
    case SDL_EVENT_MOUSE_BUTTON_DOWN: /* FALLTHROUGH */
    case SDL_EVENT_MOUSE_BUTTON_UP:
    case SDL_EVENT_MOUSE_MOTION:
      handle_mouse_event(GameState, event);
      break;
    default:
      break;
    }
  }
}
