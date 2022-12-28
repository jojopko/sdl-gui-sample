#include <SDL2/SDL.h>
#include <stdlib.h>

#include "include/gui_block.h"

SDL_Block *CreateContainer(SDL_Rect *cnter_box, SDL_Surface *cnter_skin){
    SDL_Block *container = malloc(sizeof(SDL_Block));
    container->box = cnter_box;
    container->skin = cnter_skin;

    return container;
}

void ContainerPresent(SDL_Renderer *render, SDL_Block *cnter){
    SDL_Texture *cnter_t;
    cnter_t = SDL_CreateTextureFromSurface(render, cnter->skin);
    SDL_RenderCopy(render, cnter_t, NULL, cnter->box);
    SDL_RenderPresent(render);
}