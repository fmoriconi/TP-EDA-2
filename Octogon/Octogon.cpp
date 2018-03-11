#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <stdio.h>
#include <math.h>

#define _USE_MATH_DEFINES
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define RACONV (M_PI/180) //"Radian Conversion"

const int H = 1000;
const int W = 1000;
const int n = 3;		//Numero de lados
double x = H / 2;		//Centro (x,y)
double y = W / 2;
double angn = ((360 / n) * RACONV); //angulo interior del poligono-n


void octogon(double xa, double ya, int n, double len);	//Dibuja un poligono dado el centro, cantidad de lados y largo
int recurs(double x, double y, int n, double len, double lim); //recursividad que dibuja poligonos en los vertices del poligono acortando len hasta que un limite se cumple

int main() {


	ALLEGRO_DISPLAY *display = NULL;
	if (!al_init()) {
		fprintf(stderr, "Couldn't initialize allegro!\n");
		return -1;
	}
	if (!al_init_primitives_addon()) {
		fprintf(stderr, "Couldn't initialize primitives addon!\n");
		return -1;
	}
	display = al_create_display(1000, 1000);
	if (!display) {
		fprintf(stderr, "Couldn't create allegro display!\n");
		return -1;
	}
	al_clear_to_color(al_map_rgb(0, 0, 0));

	double lim = 10;
	double len = 100;

	recurs(x, y, n, len, lim);


	al_flip_display();
	al_rest(5.0);
	return 0;
}

int recurs(double xa, double ya, int n, double len, double lim)
{

	octogon(xa, ya, n, len);
	

	if (len < lim)
		return 0;
	else
	{
		int i;
		double CurrAng = angn;
		double lado = tan(angn / 2) * len * 2; //largo de cada lado
		double x = xa + (lado / 2);
		double y = ya + len;					//esto esta dos veces, despues corregilo poniendolo arriba

	

		for (i = 0; i < (n); i++)
		{
			double x0 = cos(CurrAng) * lado;
			double y0 = sin(CurrAng) * lado;
			recurs(x, y, n, len/2, lim);

			x = x + x0;
			y = y - y0;
			CurrAng += angn;
		}

		return 0;
	}
}

void octogon(double xa, double ya, int n, double len)
{
		int i;
		double CurrAng = angn;
		double lado = tan(angn / 2) * len * 2; //largo de cada lado
		double x = xa + (lado / 2);
		double y = ya + len;

		for (i = 0; i < (n); i++)
		{
			double x0 = cos(CurrAng) * lado;
			double y0 = sin(CurrAng) * lado;
			al_draw_line(x, y, x + x0, y - y0, al_map_rgb(255, 5, 255), 1);

			CurrAng += angn;
			x = x + x0;
			y = y - y0;

			al_flip_display();
			//al_rest(0.5); //para ver como se hace cada lado de forma lenta
		}

}