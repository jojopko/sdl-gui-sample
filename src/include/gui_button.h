#ifndef _gui_button_h_
#define _gui_button_h_

#include <SDL2/SDL.h>

struct GUI_Button{
    SDL_Rect    box;
    SDL_Surface *skin;
    void        (*func)(void *dateptr);
};
typedef struct GUI_Button GUI_Button;

extern GUI_Button   *GUI_CreateButton(SDL_Rect *box, SDL_Surface *skin, void *func);
extern int           GUI_PresentButton(SDL_Renderer *render, GUI_Button *button);
extern void          GUI_DestroyButton(GUI_Button *button);
extern int           GUI_IsButton(int X, int Y, GUI_Button *button);

#endif