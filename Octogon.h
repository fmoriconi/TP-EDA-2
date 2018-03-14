#define _USE_MATH_DEFINES
#ifndef M_PI
#define M_PI 3.14159265358979323846

#include "Mandelbrot.h"

#define RACONV (M_PI/180) //"Radian Conversion"

#define H  XMAX
#define W YMAX
#define X (H / 2)		//Centro (x,y)
#define Y (W / 2)


void octogon(double xa, double ya, int n, double len, double CurrAng);	//Dibuja un poligono dado el centro, cantidad de lados y largo
int recurs(double x, double y, int n, double len, double lim, float k); //recursividad que dibuja poligonos en los vertices del poligono acortando len hasta que un limite se cumple

#endif