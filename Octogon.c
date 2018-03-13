#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <stdio.h>
#include <math.h>

int recurs(double xa, double ya, int n, double len, double lim,float k)
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
			recurs(x, y, n, len*k, lim);

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
