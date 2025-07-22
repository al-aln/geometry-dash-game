#pragma once

struct SDL_Event;
struct GameRenderInfo_t;
struct GameState_t;
struct GameState_t;
struct GameRenderInfo_t;
struct GameInput_t;




int init_window(GameRenderInfo_t *RenderInfo);

void handle_keyboard_event(GameInput_t *GameInput, GameState_t *GameState,
                           GameRenderInfo_t *RenderInfo);

void handle_mouse_event(GameState_t *GameState, const SDL_Event &Event);

void handle_window_event(GameRenderInfo_t *RenderInfo);

void handle_events(GameState_t *GameState, GameRenderInfo_t *RenderInfo,
                   GameInput_t *GameInput);
