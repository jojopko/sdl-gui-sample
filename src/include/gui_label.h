#ifndef _gui_label_h_
#define _gui_label_h_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

struct GUI_Label{
    Uint16      *text;
    TTF_Font    *font;
    SDL_Rect     box;
    SDL_Color    fg;
    SDL_Color    bg;
    Uint8        doBg;
};
typedef struct GUI_Label GUI_Label;

extern GUI_Label        *GUI_CreateLabel(Uint16 *text, TTF_Font *font, SDL_Rect *box,
                                            SDL_Color fg, SDL_Color bg, Uint8 doBg);
extern int              GUI_PresentLabel(SDL_Renderer *render, GUI_Label *label);
extern void             GUI_DestroyLabel(GUI_Label *label);

#endif