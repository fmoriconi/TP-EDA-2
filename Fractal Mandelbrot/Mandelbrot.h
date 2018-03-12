#ifndef PARSE_CMD_LINE_H
#define	PARSE_CMD_LINE_H

#DEFINE MAX 1000

/*********************
*     mandelrbot     *
**********************
*SYNTAX: funcion que dibuja en un display de allegro un fractal de mandelbrot.
*INPUT:
*	-x0 e y0: coordenada inferior izquierda del plano imaginario
*	-xf e yf: coordenada superior derecha del plano imaginario
*
*OUTPUT:
*	-un display con el dibujo creado
*/
void mandelrbot(double x0, double y0, double xf, double yf);

#endif
