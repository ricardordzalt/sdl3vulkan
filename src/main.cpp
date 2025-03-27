#include <SDL3/SDL.h>
#include <iostream>

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;

int main()
{
    bool isSdlVideoInitialized = SDL_InitSubSystem(SDL_INIT_VIDEO);
    if (!isSdlVideoInitialized)
    {
        const char *sdlInitError = SDL_GetError();
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Error al inicializar SDL3: %s", sdlInitError);
        return 1;
    }

    SDL_Window *sdlWindow = SDL_CreateWindow("Ventana SDL3", 800, 600, SDL_WINDOW_RESIZABLE);
    if (!sdlWindow)
    {
        const char *sdlWindowError = SDL_GetError();

        SDL_LogError(SDL_LOG_CATEGORY_VIDEO, "Error al crear la ventana: %s", sdlWindowError);
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *sdlRenderer = SDL_CreateRenderer(sdlWindow, nullptr);
    if (!sdlRenderer)
    {
        const char *sdlRendererError = SDL_GetError();

        SDL_LogError(SDL_LOG_CATEGORY_RENDER, "Error al crear el renderer: %s", sdlRendererError);
        SDL_DestroyWindow(sdlWindow);
        SDL_Quit();
        return 1;
    }

    SDL_Event event;
    bool isRunning = true;

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                isRunning = false;
            }
        }

        SDL_RenderClear(sdlRenderer);
        SDL_RenderPresent(sdlRenderer);

        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(sdlWindow);
    SDL_Quit();

    return 0;
}
