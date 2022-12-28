#ifndef _gui_layers_h_
#define _gui_layers_h_

#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>
#include "gui_block.h"
#include "gui_button.h"
#include "gui_label.h"

#include "gui_macro.h"

enum GUI_ELEMENT_TYPE{
    GUI_ELEMENT_BLOCK,
    GUI_ELEMENT_BUTTON,
    GUI_ELEMENT_LABEL
};

union GUI_UElement{
    GUI_Block           block;
    GUI_Button          button;
    GUI_Label           label;
};
typedef union GUI_UElement GUI_UElement;

struct GUI_Element{
    int                 id;
    int                 type;
    GUI_UElement        element;
};
typedef struct GUI_Element GUI_Element;

struct GUI_Layer{
    Sint32              id;       /* Number of layer                */
    GUI_Element       **elements; /* Array of elements              */
    Uint32              elem_cnt; /* Count of elements in .elements */
};
typedef struct GUI_Layer GUI_Layer;

extern GUI_Layer       *GUI_CreateLayer(Sint32 id);
extern void             GUI_DestroyLayer(GUI_Layer *layer);
extern int              GUI_AddElementToLayer(GUI_Layer *layer, GUI_Element *element);

/* Добавить функции:
 *  1. Добавление елемента 
 *  2. Удаление елемента
 *  3. Вывод изображения
 *  4. Создание GUI_Layer 
 *  5. Удаление GUI_Layer 
 */

#endif