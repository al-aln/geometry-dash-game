#include "game.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_scancode.h>
#include <SDL3/SDL_video.h>

#define INTERNAL static
#define GLOBAL static
GLOBAL SDL_Event event;

INTERNAL inline void update_input(GameInput_t *Input) {
  const bool *key = SDL_GetKeyboardState(NULL);

  const uint64_t *current = (const uint64_t *)key;
  uint64_t *previous = (uint64_t *)Input->prevKeyState;
  uint64_t *pressed = (uint64_t *)Input->keyPressed;
  uint64_t *released = (uint64_t *)Input->keyReleased;

  // Process 8 bytes (64 bools) at a time
  const int chunks = (SDL_SCANCODE_COUNT + 7) / 8; // Round up division

  for (int i = 0; i < chunks; ++i) {
    uint64_t curr = current[i];
    uint64_t prev = previous[i];

    // pressed = current AND NOT previous
    pressed[i] = curr & ~prev;

    // released = NOT current AND previous
    released[i] = ~curr & prev;

    // Update previous state
    previous[i] = curr;
  }
}

INTERNAL void process_input(GameInput_t *Input, GameState_t *GameState,
                            GameRenderInfo_t * /*RenderInfo*/) {
  update_input(Input);

  // TODO: move to game.cpp
  if (Input->keyPressed[SDL_SCANCODE_LALT]) {
  }
  if (Input->keyPressed[SDL_SCANCODE_ESCAPE]) {
    GameState->is_running = false;
  }

}

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

void handle_keyboard_event(GameInput_t *GameInput, GameState_t *GameState,
                           GameRenderInfo_t *RenderInfo) {
  process_input(GameInput, GameState, RenderInfo);
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

void handle_events(GameState_t *GameState, GameRenderInfo_t *RenderInfo,
                   GameInput_t *GameInput) {
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
      handle_keyboard_event(GameInput, GameState, RenderInfo);
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
