#include <stdlib.h>
#include <SDL2/SDL.h>

#include "include/gui_block.h"
#include "include/gui_macro.h"

GUI_Block *GUI_CreateBlock(SDL_Rect *box, SDL_Surface *skin){
    GUI_Block *block;

    block = (GUI_Block *) calloc(1, sizeof(*block));
    if(!block){
        GUI_free(block);
        return NULL;
    }

    if(!box){
        return NULL;
    }
    block->box  = *box;
    
    if(!skin){
        return NULL;
    }
    block->skin = skin;

    return block;
}

int GUI_PresentBlock(SDL_Renderer *render, GUI_Block *block){
    SDL_Texture *texture;

    if(!render){
        return -1;
    }

    if(!block){
        return -1;
    }

    texture = SDL_CreateTextureFromSurface(render, block->skin);
    if(!texture){
        return -1;
    }

    if(SDL_RenderCopy(render, texture, NULL, &block->box)){
        return -1;
    }

    return 0;
}

void GUI_DestroyBlock(GUI_Block *block){
    GUI_free(block);
}

int GUI_IsBlock(int X, int Y, GUI_Block *block){
    int x0 = block->box.x;
    int y0 = block->box.y;
    int x1 = block->box.w + x0;
    int y1 = block->box.h + y0;

    int isblock = 0;

    if(X >= x0 && X <= x1){
        if(Y >= y0 && Y<= y1){
            isblock = 1;
        }
    }

    return isblock;
}