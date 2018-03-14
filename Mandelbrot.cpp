#include <stdio.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>

#include "Mandelbrot.h"



void mandelbrotfun(double x0, double y0, double xf, double yf) {
	double rad;

	if ((xf - x0) >= (yf - y0)){				//busco el lado mas largo
		rad = ((xf - x0) / 2);
		}
	else
		rad = ((yf - y0) / 2);

	for (int row = 0; row < (YMAX-1); row++) {
		for (int col = 0; col < (XMAX-1); col++) {
			double c_re = (col - XMAX / 2.0)* (rad * 2) / XMAX;			//calculo de la constante real    
			double c_im = (row - YMAX / 2.0)* (rad * 2) / XMAX;			//calculo de la constante imaginaria
			double x = 0, y = 0;
			unsigned int iteration = 0;

			while ((x*x+y*y <= (rad * 2)) && iteration < MAX) {
           			double x_new = x*x - y*y + c_re;
         			y = 2*x*y + c_im;
         			x = x_new;
         			iteration++;
     		   	}
     		   	if (iteration < MAX)
				al_draw_pixel(col, row, color(iteration));
      		 	else
                            al_draw_pixel(col, row, al_map_rgb(0, 0, 0));

			if(col == 0)
                            al_flip_display();

			sleep(0.005);
		}
	}
}


/*
                        iteration = recursive(x, y, &c_re, &c_im, &rad, iteration);  //FORMA RECURSIVA COMENTADA. FUNCIONA IGUAL. EN CLASE DIJO QUE
                                                                                       //NO HACIA FALTA USARLA
			if (iteration > MAX)
                            al_draw_pixel(col, row, color(iteration));
			else
                            al_draw_pixel(col, row, al_map_rgb(255, 255, 255));
                        
                        if(col == 0)
                            al_flip_display();
                        
                        al_rest(0.005);
*/

/*
int recursive(double x, double y, double * c_re, double * c_im, double * rad, unsigned int iteration) {
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
*/


ALLEGRO_COLOR color(unsigned int iteration){	
	if(iteration < 5)
		return al_map_rgb(0, 0, 255);
	else if(iteration < 10)
		return al_map_rgb(0, 255, 0);
	else if(iteration < 30)
		return al_map_rgb(255, 255, 0);
	else if(iteration < 50)
		return al_map_rgb(150, 255, 0);
	else if(iteration < 90)
		return al_map_rgb(255, 0, 0);
	else if(iteration < 140)
		return al_map_rgb(255, 0, 255);
	else if(iteration < 190)
		return al_map_rgb(150, 0, 255);
	else
		return al_map_rgb(0, 255, 159);
}