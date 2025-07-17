#pragma once

struct SDL_Event;
struct GameRenderInfo_t;
struct GameState_t;

int initWindow(GameRenderInfo_t *RenderInfo);

void handleKeyboardEvent(GameState_t *GameState, const SDL_Event &Event);

void handleMouseEvent(GameState_t *GameState, const SDL_Event &Event);

void handleWindowEvent(GameRenderInfo_t *RenderInfo);

void handleEvents(GameState_t *GameState, GameRenderInfo_t *RenderInfo);
