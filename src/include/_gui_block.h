#ifndef _sdl_gui_block_h_
#define _sdl_gui_block_h_

#include <SDL2/SDL.h>

struct SDL_Block{
    SDL_Rect    *box;
    SDL_Surface *skin;
};
typedef struct SDL_Block SDL_Block;

extern SDL_Block *CreateContainer(SDL_Rect *ctner_box, SDL_Surface *ctner_skin);
extern void ContainerPresent(SDL_Renderer *render, SDL_Block *ctner);

#endif