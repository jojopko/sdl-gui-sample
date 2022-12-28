#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/_gui_button.h"
#include "include/gui.h"

int SDL_GUI_IsButton(int mx, int my, GUI_Button *btn){
    /* Vertex of button */
    int vx0 = btn->box.x, vx1 = btn->box.x + btn->box.w;
    int vy0 = btn->box.y, vy1 = btn->box.y + btn->box.h;
    
    if(mx >= vx0 && mx < vx1){
        if(my >= vy0 && my < vy1){
            return 1;
        }
    }

    return 0;
}

int SDL_GUI_ButtonClick(int mx, int my){
    return 0;
}

void SDL_GUI_PresentButton(SDL_Renderer *render, GUI_Button *btn){
    SDL_Texture *btn_t;
    btn_t = SDL_CreateTextureFromSurface(render, btn->skin);
    SDL_RenderCopy(render, btn_t, NULL, &btn->box);
    SDL_DestroyTexture(btn_t);
}

GUI_Button *SDL_GUI_CreateButtons(int count){
    GUI_Button *btn = malloc(sizeof(GUI_Button) * count);
    return btn;
}

GUI_Button *SDL_GUI_CreateButton(){
    GUI_Button *btn = malloc(sizeof(GUI_Button));
    return btn;
}

void SDL_GUI_SetButtonBox(GUI_Button *btn, SDL_Rect *box){
    btn->box = *box;
}

void SDL_GUI_SetButtonSkin(GUI_Button *btn, SDL_Surface *skin){
    btn->skin = skin;
}

void SDL_GUI_SetButtonFunc(GUI_Button *btn, void *func){
    btn->func = func;
}

SDL_Rect *SDL_GUI_GetButtonBox(GUI_Button *btn){
    return &btn->box;
}

SDL_Surface *SDL_GUI_GetButonSkin(GUI_Button *btn){
    return btn->skin;
}

void *SDL_GUI_GetButtonFunc(GUI_Button *btn){
    return btn->func;
}
