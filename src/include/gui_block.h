#ifndef _gui_block_
#define _gui_block_

#include <SDL2/SDL.h>

#include "gui_macro.h"

struct GUI_Block{
    SDL_Rect     box;
    SDL_Surface *skin;
};
typedef struct GUI_Block GUI_Block;

extern GUI_Block    *GUI_CreateBlock(SDL_Rect *box, SDL_Surface *skin);
extern int           GUI_PresentBlock(SDL_Renderer *render, GUI_Block *block);
extern int           GUI_IsBlock(int X, int Y, GUI_Block *block);
extern void          GUI_DestroyBlock(GUI_Block *block);

/* Todo:
 *  create +
 *  present +
 *  free +
 *  detect (is block?) +
 */

#endif