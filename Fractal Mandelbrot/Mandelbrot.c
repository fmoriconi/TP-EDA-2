#include <stdio.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include "general.h"
#include "Mandelbrot.h"



void mandelrbot(double x0, double y0, double xf, double yf) {

	int row, col;													//variables para indicar el pixel apuntado
	double rad;

	if ((abs(xf) + abs(x0)) >= (abs(yf) + abs(y0))) {				//busco el lado mas largo
		rad = ((abs(xf) + abs(x0)) / 2);
		}
	else
		rad = ((abs(yf) + abs(y0)) / 2);

	for (int row = 0; row < YMAX; row++) {
		for (int col = 0; col < XMAX; col++) {
			double c_re = (col - XMAX / 2.0)*(rad * 2) / XMAX;			//calculo de la constante real    
			double c_im = (row - YMAX / 2.0)*(rad * 2) / XMAX;			//calculo de la constante imaginaria
			double x = 0, y = 0;
			recursive(x, y, &c_re, &c_im);
			if (iteration < MAX)
				al_put_pixel(col, row, al_map_rgb((unsigned char(interaction/4), (unsigned char)(interaction/4), (unsigned char)(interraction/4));
			else
				al_put_pixel(col, row, al_map_rgb(255, 255, 255));
		}
	}

}

int recursive(double x, double y, double * c_re, double * c_im) {
	if (x*x + y * y <= (rad * 2) && iteration < MAX)
		return;
	else {
		double x_new = x * x - y * y + (*c_re);
		y = 2 * x*y + (*c_im);
		x = x_new;
		return 1 + recursive(x, y, c_re, c_im);
	}
}