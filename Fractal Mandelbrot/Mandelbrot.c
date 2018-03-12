#include <stdio.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include "general.h"
#include "Mandelbrot.h"



void mandelrbot(double x0, double y0, double xf, double yf) {

	int row, col;													//variables para indicar el pixel apuntado
	double rad;

	if ((abs(xf) + abs(x0)) >= (abs(yf) + abs(y0))) {
		rad = ((abs(xf) + abs(x0)));
		}
	else
		rad = ((abs(yf) + abs(y0)) / 2);

	for (int row = 0; row < YMAX; row++) {
		for (int col = 0; col < XMAX; col++) {
			double c_re = (col - XMAX / 2.0)*(rad * 2) / XMAX;			//calculo de la constante real    
			double c_im = (row - YMAX / 2.0)*(rad * 2) / XMAX;			//calculo de la constante imaginaria
			double x = 0, y = 0;
			int iteration = 0;
			while (x*x + y * y <= (rad*2) && iteration < MAX) {
				double x_new = x * x - y * y + c_re;
				y = 2 * x*y + c_im;
				x = x_new;
				iteration++;
			}
			if (iteration < MAX)
				al_put_pixel(col, row, al_map_rgb((unsigned char(interaction/4), (unsigned char)(interaction/4), (unsigned char)(interraction/4));
			else
				al_put_pixel(col, row, al_map_rgb(255, 255, 255));
		}
	}

}