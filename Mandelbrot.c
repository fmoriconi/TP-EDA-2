#include <stdio.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>

#include "Mandelbrot.h"



void mandelbrot(double x0, double y0, double xf, double yf) {

	int row, col;													//variables para indicar el pixel apuntado
	double rad;

	if ((xf - x0) >= (yf - y0)){				//busco el lado mas largo
		rad = ((xf - x0) / 2);
		}
	else
		rad = ((yf - y0) / 2);

	for (int row = 0; row < (YMAX-1); row++) {
		for (int col = 0; col < (XMAX-1); col++) {
			double c_re = (col - XMAX / 2.0)*(rad * 2) / XMAX;			//calculo de la constante real    
			double c_im = (row - YMAX / 2.0)*(rad * 2) / XMAX;			//calculo de la constante imaginaria
			double x = 0, y = 0;
			int iteration = 0;
                        
                        iteration = recursive(x, y, &c_re, &c_im, &rad, iteration);
                        
			if (iteration > MAX)
                            al_draw_pixel(col, row, al_map_rgb(0, 0, 0));
			else
                            al_draw_pixel(col, row, al_map_rgb(255, 255, 255));
                        
                        if(col == 0)
                            al_flip_display();
                        
                        sleep(0.005);
		}
	}

}

int recursive(double x, double y, double * c_re, double * c_im, double * rad, int iteration) {
	if (x*x + y*y >= ((*rad) * 2) || iteration > MAX)
		return iteration;
	else {
		double x_new = x * x - y * y + (*c_re);
		y = 2 * x*y + (*c_im);
		x = x_new;
                iteration++;
		return recursive(x, y, c_re, c_im, rad, iteration);
	}
}