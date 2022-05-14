#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


SDL_Surface *Image = NULL;
SDL_Surface *Backbuffer = NULL;
SDL_Window *Window = NULL;

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 800;

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    Window = SDL_CreateWindow("hello", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_ALLOW_HIGHDPI);

    SDL_Renderer *renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_PRESENTVSYNC);

    SDL_RenderSetLogicalSize(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);

    IMG_Init(IMG_INIT_PNG);
    Image = IMG_Load("media/graphics/background_cityscape.png");
    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, Image);

    SDL_Event event;

    bool running = true;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;

            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    running = false;
                    break;
                default:
                    break;
                }
            }

            SDL_RenderClear(renderer);

            SDL_RenderCopy(renderer, tex, NULL, NULL);

            SDL_RenderPresent(renderer);
        }
    }
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(Window);
    SDL_FreeSurface(Image);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
