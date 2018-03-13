#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>

#include "Mandelbrot.h"


int main(void){
    al_init();
    al_init_primitives_addon();
    ALLEGRO_DISPLAY * display = al_create_display(XMAX, YMAX);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    
    double x0 = -2.0;
    double y0 = -2.0;
    double xf = 2.0;
    double yf = 2.0;

    mandelbrot(x0, y0, xf, yf);
    
    al_flip_display();
    al_rest(5.0);
    
    return 0;
}