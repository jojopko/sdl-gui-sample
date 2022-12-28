#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "include/gui_macro.h"
#include "include/gui_label.h"
#include "include/gui_layers.h"

GUI_Label *GUI_CreateLabel(Uint16 *text, TTF_Font *font, SDL_Rect *box,
                            SDL_Color fg, SDL_Color bg, Uint8 doBg){
    GUI_Label *label;
    label = (GUI_Label*) calloc(1, sizeof(*label));

    if(!text){
        label->text = (Uint16 *)" ";
    }
    label->text = text;

    if(!font){
        return NULL;
    }
    label->font = font;

    if(!box){
        return NULL;
    }
    label->box = *box;
    TTF_SizeUNICODE(font, text, &label->box.w, &label->box.h);

    label->doBg = doBg;

    label->fg = fg;
    label->bg = bg;
    
    return label;
}

int GUI_PresentLabel(SDL_Renderer *render, GUI_Label *label){
    SDL_Texture *texture;
    SDL_Surface *surf_text;

    if(!render){
        return -1;
    }

    if(!label){
        return -1;
    }

    if(label->doBg == 0){
        surf_text = TTF_RenderUNICODE_Solid(label->font, label->text, label->fg);
    }
    else if(label->doBg == 1){
        surf_text = TTF_RenderUNICODE_Shaded(label->font, label->text,
                                            label->fg,   label->bg);
    }

    if(!surf_text){
        return -1;
    }

    texture = SDL_CreateTextureFromSurface(render, surf_text);
    if(!texture){
        return -1;
    }

    if(SDL_RenderCopy(render, texture, NULL, &label->box)){
        return -1;
    }

    return 0;
}

void GUI_DestroyLabel(GUI_Label *label){
    GUI_free(label);
}