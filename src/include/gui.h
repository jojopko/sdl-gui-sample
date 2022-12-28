#ifndef _sdl_gui_h_
#define _sdl_gui_h_

#include <SDL2/SDL.h>

#include "gui_button.h"
#include "gui_block.h"
#include "gui_label.h"
#include "gui_layers.h"

extern SDL_Surface *GUI_LoadImage(const char *file);

#endif