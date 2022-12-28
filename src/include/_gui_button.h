#ifndef _sdl_gui_button_h_
#define _sdl_gui_button_h_

#include <SDL2/SDL.h>

struct GUI_Button{
    SDL_Rect    box;
    SDL_Surface *skin;
    void        (*func)(void);
};
typedef struct GUI_Button GUI_Button;

extern int SDL_GUI_IsButton(int mx, int my, GUI_Button *btn);

extern void SDL_GUI_PresentButton(SDL_Renderer *render, GUI_Button *btn);

extern GUI_Button *SDL_GUI_CreateButtons(int count);

extern GUI_Button *SDL_GUI_CreateButton();

extern void SDL_GUI_SetButtonBox(GUI_Button *btn, SDL_Rect *box);

extern void SDL_GUI_SetButtonSkin(GUI_Button *btn, SDL_Surface *skin);

extern void SDL_GUI_SetButtonFunc(GUI_Button *btn, void *func);

extern SDL_Rect *SDL_GUI_GetButtonBox(GUI_Button *btn);

extern SDL_Surface *SDL_GUI_GetButonSkin(GUI_Button *btn);

extern void *SDL_GUI_GetButtonFunc(GUI_Button *btn);

#endif