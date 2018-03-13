#ifndef MANDELBROT_H
#define	MANDELBROT_H

#define MAX 1000
#define XMAX 600
#define YMAX 400

/*********************
*     mandelBrot     *
**********************
*SYNTAX: funcion que dibuja en un display de allegro un fractal de mandelbrot.
*INPUT:
*	-x0 e y0: coordenada inferior izquierda del plano imaginario
*	-xf e yf: coordenada superior derecha del plano imaginario
*
*OUTPUT:
*	-un display con el dibujo creado
*/
void mandelbrot(double x0, double y0, double xf, double yf);

int recursive(double x, double y, double * c_re, double * c_im);

#endif
