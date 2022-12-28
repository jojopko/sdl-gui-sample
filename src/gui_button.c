#include <SDL2/SDL.h>
#include <stdlib.h>

#include "include/gui_button.h"
#include "include/gui_macro.h"

GUI_Button *GUI_CreateButton(SDL_Rect *box, SDL_Surface *skin, void *func){
    GUI_Button *button;
    button = (GUI_Button *) calloc(1, sizeof(*button));

    if(!box){
        return NULL;
    }
    button->box = *box;

    if(!skin){
        return NULL;
    }
    button->skin = skin;

    button->func = func;

    return button;
}

int GUI_PresentButton(SDL_Renderer *render, GUI_Button *button){
    SDL_Texture *texture;

    if(!render){
        return -1;
    }

    if(!button){
        return -1;
    }

    texture = SDL_CreateTextureFromSurface(render, button->skin);
    if(!texture){
        return -1;
    }

    if(SDL_RenderCopy(render, texture, NULL, &button->box)){
        return -1;
    }

    return 0;
}

void GUI_DestroyButton(GUI_Button *button){
    GUI_free(button);
}

int GUI_IsButton(int X, int Y, GUI_Button *button){
    int x0 = button->box.x;
    int y0 = button->box.y;
    int x1 = button->box.w + x0;
    int y1 = button->box.h + y0;

    int isbutton = 0;

    if(X >= x0 && X <= x1){
        if(Y >= y0 && Y<= y1){
            isbutton = 1;
        }
    }

    return isbutton;
}