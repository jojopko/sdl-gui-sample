#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "src/include/gui.h"
#include "src/include/gui_label.h"
#include "src/include/gui_layers.h"

SDL_Window   *win;
SDL_Renderer *render;

void button_click(void *dateptr){
    int *list = (int*)dateptr;
    fprintf(stderr, "[i] [0]=%d [1]=%d [2]=%d\n", list[0], list[1], list[2]);
}

int main(){
    if(SDL_Init(SDL_INIT_EVERYTHING))
        fprintf(stderr, "[e] SDL init fail!\n");
    
    if(TTF_Init()){
        fprintf(stderr, "[e] TTF init fail!\n");
    }
    
    win = SDL_CreateWindow("\0", 0, 0, 640, 640, 0);
    if(!win)
        fprintf(stderr, "[e] Window create fail!\n");
    
    render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    if(!render)
        fprintf(stderr, "[e] Render create fail!\n");
    
    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    SDL_RenderClear(render);
    SDL_RenderPresent(render);

#if 1 /* Layer test */
    GUI_Layer *layer;
    GUI_Element *element;
    element = (GUI_Element*) calloc(1,sizeof(*element));

    Uint16 text[] = {'j','o','j','o',' ','e','t','o',' ','n','e',' ','s','v','i','n','\'','y','a','!',0};
    TTF_Font *font = TTF_OpenFont("/home/gamerat/.local/share/fonts/19888.ttf\0", 34);
    SDL_Rect box = {50,100,0,0};
    SDL_Color fg = {255,0,0};
    SDL_Color bg = {0,0,0};

    element->element.label = *GUI_CreateLabel(text, font, &box, fg, bg, 1);
    element->id = 0;
    element->type = GUI_ELEMENT_LABEL;
    layer = GUI_CreateLayer(-1);
    

    GUI_AddElementToLayer(layer, element);
    GUI_PresentLabel(render, &element->element.label);
#endif

#if 0 /* Label test */
    GUI_Label *label;
    Uint16 text[] = {'j','o','j','o',' ','e','t','o',' ','n','e',
                     ' ','s','v','i','n','\'','y','a','!',0};
    TTF_Font *font = TTF_OpenFont("/home/gamerat/.local/share/fonts/19888.ttf\0", 34);
    SDL_Rect box = {50,100,0,0};
    SDL_Color fg = {255,0,0};
    SDL_Color bg = {0,0,0};

    label = GUI_CreateLabel(text, font, &box, fg, bg, 1);
    if(!label){
        fprintf(stderr, "[e] Create label fail!\n");
    }

    if(GUI_PresentLabel(render, label)){
        fprintf(stderr, "[e] Present label fail!\n");
    }

    fprintf(stderr, "[i] label: text{%s} font{%p} box{%p} fg{%p} bg{%p}\n",
            (char*)label->text, label->font, &label->box, &label->fg, &label->bg);
#endif

#if 0 /* Button test */
    GUI_Button *button;
    SDL_Rect box = {0,0,32,32};
    SDL_Surface *skin = GUI_LoadImage("../assets/img/ico/adm-up.png\0");
    button = GUI_CreateButton(&box, skin, button_click);
    if(!button){
        fprintf(stderr, "[e] Create button fail! {%p}\n", button);
    }

    if(GUI_PresentButton(render, button)){
        fprintf(stderr, "[e] Present button fail!\n");
    }

#endif

#if 0 /* Block Test for ... */
    SDL_Rect boxs[3];
    SDL_Surface *skins[3];
    GUI_Block *blocks[3];
    
    int s = 8;

    boxs[0].x=0  * s, boxs[0].y=0 * s, boxs[0].w=16 * s, boxs[0].h=16 * s;
    boxs[1].x=16 * s, boxs[1].y=0 * s, boxs[1].w=16 * s, boxs[1].h=16 * s;
    boxs[2].x=32 * s, boxs[2].y=0 * s, boxs[2].w=16 * s, boxs[2].h=16 * s;

    skins[0] = GUI_LoadImage("../assets/img/ico/adm-up.png\0");
    skins[1] = GUI_LoadImage("../assets/img/ico/mil-up.png\0");
    skins[2] = GUI_LoadImage("../assets/img/ico/dip-up.png\0");

    if(!skins[0] || !skins[1] || !skins[2]){
        fprintf(stderr, "[e] Skin's download fail! (%p)\n", skins);
    }

    int fail = 0;

    blocks[0] = GUI_CreateBlock(&boxs[0], skins[0]);
    blocks[1] = GUI_CreateBlock(&boxs[1], skins[1]);
    blocks[2] = GUI_CreateBlock(&boxs[2], skins[2]);

    fail |= !blocks[0];
    fail |= !blocks[1];
    fail |= !blocks[2];

    if(fail){
        fprintf(stderr, "[e] Create block's is fail!\n");
    }

    fail |= GUI_PresentBlock(render, blocks[0]);
    fail |= GUI_PresentBlock(render, blocks[1]);
    fail |= GUI_PresentBlock(render, blocks[2]);

    if(fail){
        fprintf(stderr, "[e] Present block's fail!\n");
    }

#endif

#if 0 /* Block test for one block */
    /* \ one block test / */

    GUI_Block *block;
    SDL_Rect box = {0,0,256,429};
    SDL_Surface *skin = GUI_LoadImage("../assets/img/containers/prov-info-container.png\0");
    // SDL_Surface *skin = GUI_LoadImage("/home/gamerat/Desktop/sdl_gui/assets/img/containers/prov-info-container.png\0");
    fprintf(stderr, "[i] skin: %p\n", skin);

    block = GUI_CreateBlock(&box, skin);
    if(!block){
        fprintf(stderr, "[e] GUI: Block create fail!\n");
    }

    if(GUI_PresentBlock(render, block)){
        fprintf(stderr, "[e] GUI: Block present fail!\n");
    };

#endif

    SDL_RenderPresent(render);

#if 1   /* IO */
    SDL_Event e;
    int mx = 0, my = 0;
    int isRun = 1;
    while(isRun){
        SDL_WaitEvent(&e);
        SDL_GetMouseState(&mx, &my);
        fprintf(stderr, "[i] mouse: motion: x:%d y:%d\n", mx, my);
        
        if(e.type == SDL_QUIT){
            isRun = 0;
            fprintf(stderr, "[i] shutdown!\n");
        }
    }
#endif

    return 0;
}