#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "include/_gui_label.h"

static TTF_Font *glabel_font;

SDL_Label *SDL_GUI_CreateLabels(int count){
    SDL_Label *labels = malloc(sizeof(SDL_Label) * count);
    return labels;
}

SDL_Label *SDL_GUI_CreateLabel(){
    SDL_Label *label = malloc(sizeof(SDL_Label));
    return label;
}

void SDL_GUI_SetLabelFont(TTF_Font *font, SDL_Label *label){
    label->font = font;
}

void SDL_GUI_SetGlobalLabelFont(TTF_Font *font){
    glabel_font = font;
}

void SDL_GUI_SetLabelText(Uint16 *str, SDL_Label *label){
    label->text = str;
}

int SDL_GUI_SetLabelBox(int x, int y, SDL_Label *label){
    label->box.x = x;
    label->box.y = y;
    if(!label->text){
        fprintf(stderr, "[e] label is empty!\n");
        return -1;
    }
    TTF_SizeUNICODE(label->font, label->text, &label->box.w, &label->box.h);
    return 0;
}

void SDL_GUI_SetLabelForeground(SDL_Color *fg, SDL_Label *label){
    label->fg = *fg;
}

void SDL_GUI_SetLabelBackground(SDL_Color *bg, SDL_Label *label){
    label->bg = *bg;
}

void SDL_GUI_PresentLabel(SDL_Renderer *render, SDL_Label *label, int bg){
    SDL_Texture *label_t = NULL;
    SDL_Surface *text_s = NULL;
    TTF_Font *font = NULL;

    fprintf(stderr, "%p\n", glabel_font);

    if(!glabel_font)
        font = label->font;
    else
        font = glabel_font;
    
    if(bg == 1)
        text_s = TTF_RenderUNICODE_Shaded(font, label->text, label->fg, label->bg);
    else
        text_s = TTF_RenderUNICODE_Solid(font, label->text, label->fg);
    
    label_t = SDL_CreateTextureFromSurface(render, text_s);
    SDL_RenderCopy(render, label_t, NULL, &label->box);
    SDL_DestroyTexture(label_t);
    SDL_FreeSurface(text_s);
}