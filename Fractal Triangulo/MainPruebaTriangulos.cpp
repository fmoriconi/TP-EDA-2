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

	float lStart = 1000;
	float leftAngle = 60;
	float rightAngle = -60;
	float x = 100;
	float y = 1100;
	float lEnd = 101.000000;
	triFractal(x,y,lStart,leftAngle,rightAngle,lEnd);

	al_flip_display();
	al_rest(5.0);
	return 0;
}