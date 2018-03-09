#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include "Triangles.h"

int main()
{
	al_init();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY* display = al_create_display(1200, 1200);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	float lbase = 1000;
	float langle = 59.5;
	float rangle = 0;
	float x = 10;
	float y = 1000;
	float lend = 50;

	triFractal(x,y,lbase,langle,rangle,lend);

	al_flip_display();
	al_rest(5.0);
	return 0;
}