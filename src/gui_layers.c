#include <SDL2/SDL.h>
#include <SDL2/SDL_stdinc.h>
#include <stdlib.h>

#include "include/gui_layers.h"
#include "include/gui_macro.h"

GUI_Layer *GUI_CreateLayer(Sint32 id){
    GUI_Layer *layer;

    layer = (GUI_Layer *) calloc(1, sizeof(*layer));

    if(id < -1){
        return NULL;
    }
    layer->id = id;

    layer->elem_cnt = 0;

    return layer;
}

int GUI_AddElementToLayer(GUI_Layer *layer, GUI_Element *element){
    GUI_Element **tmp;

    if(!layer){
        return -1;
    }

    tmp = (GUI_Element**) calloc(layer->elem_cnt+1, sizeof(**tmp));
    
    if(!layer->elem_cnt){
        for(int i = 0; i < layer->elem_cnt; i++){
            tmp[i] = layer->elements[i];
        }
    }

    if(!element){
        return -1;
    }

    tmp[layer->elem_cnt] = element;



    return 0;
}

void GUI_DestroyLayer(GUI_Layer *layer){
    GUI_free(layer);
}