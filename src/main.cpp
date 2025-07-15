#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

struct GameRenderInfo_t {
  SDL_Window *Window;
  SDL_Renderer *Renderer;
};

static GameRenderInfo_t RenderInfo = {};

int initWindow(GameRenderInfo_t *RenderInfo) {

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

  SDL_Window *window =
      SDL_CreateWindow("Geometry dash game", 1024, 720, SDL_WINDOW_RESIZABLE);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
  SDL_SetRenderVSync(renderer, 1);

  if (window && renderer) {
    RenderInfo->Window = window;
    RenderInfo->Renderer = renderer;
    return 0;
  }
  return -1;
}

int main() {
  initWindow(&RenderInfo);

  bool running = true;
  while (running) {
  }

  return 0;
}