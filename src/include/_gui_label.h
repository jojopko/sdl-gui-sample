#ifndef _sdl_gui_label_h_
#define _sdl_gui_label_h_

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

struct SDL_Label{
    Uint16      *text;
    TTF_Font    *font;
    SDL_Rect     box;
    SDL_Color    fg;
    SDL_Color    bg;
};
typedef struct SDL_Label SDL_Label;

extern SDL_Label   *SDL_GUI_CreateLabel();
extern SDL_Label   *SDL_GUI_CreateLabels(int count);
extern void         SDL_GUI_SetLabelFont(TTF_Font *font, SDL_Label *label);
extern void         SDL_GUI_SetGlobalLabelFont(TTF_Font *font);
extern void         SDL_GUI_SetLabelText(Uint16 *str, SDL_Label *label);
extern int          SDL_GUI_SetLabelBox(int x, int y, SDL_Label *label);
extern void         SDL_GUI_SetLabelForeground(SDL_Color *fg, SDL_Label *label);
extern void         SDL_GUI_SetLabelBackground(SDL_Color *bg, SDL_Label *label);
extern void         SDL_GUI_PresentLabel(SDL_Renderer *render, SDL_Label *label, int bg);

#endif