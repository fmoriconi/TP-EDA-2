#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_primitives.h>
#include<stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "Triangles.h"

#define RACONV (M_PI/180) //"Radian Conversion"



void triFractal(float x, float y, float lStart, float leftAngle, float rightAngle, float lEnd) {

	float x2 = x + lStart; //Coordenada del final de la base

	float topAngle = (180 - leftAngle + rightAngle); //Calculo el ángulo superior

	// Usando trigonometría, teniendo los tres ángulos y un lado podemos calcular los otros dos lados.
	
	float lSide = lStart * sin(-rightAngle * RACONV)/sin(topAngle * RACONV); //Calculamos el lado izquierdo del triángulo.
	float lSideX = lSide * cos(leftAngle * RACONV); // Con el angulo izquierdo calculamos el lado opuesto y adyacente del triangulo rectangulo que se forma...
	float lSideY = lSide * sin(leftAngle * RACONV); //...Si tomamos el lado izquierdo como una hipotenusa. 


	float x3 = x + lSideX ; //La coordenada X del tercer vértice.
	float y3 = y - lSideY ;//La coordenada Y del tercer vértice. sohcahTOA: Tan(langle)*adyacente = opuesto (altura).

	drawTriangle(x, x2, x3, y, y3); //Dibujamos el triangulo base.

	TriRecurs(x, x2, x3, y, y, y3, lEnd); //Función recursiva.

}

void drawTriangle(float x, float x2, float x3, float y, float y3) {

	al_draw_line(x, y, x2, y, al_map_rgb(0, 0, 255), 1); // Dibujo la base
	al_draw_line(x, y, x3, y3, al_map_rgb(0, 0, 255), 1); //Dibujo el lado izquierdo.
	al_draw_line(x2, y, x3, y3, al_map_rgb(0, 0, 255), 1); //Dibujo el lado derecho.
}

int TriRecurs(float x1,float x2,float x3,float y1,float y2,float y3,float lEnd) {

	float yv = (y1 + y2 + y3) / 3;
	float xv = (x1 + x2 + x3) / 3;

		if (
				(sqrt(pow((xv - x1), 2) + pow((yv - y1), 2))) < lEnd || //Si la distancia entre algun par de vertices a dibujar es menor a lEnd...
				(sqrt(pow((xv - x2), 2) + pow((yv - y2), 2))) < lEnd || //...entonces la recursividad termina ahí.
				(sqrt(pow((xv - x3), 2) + pow((yv - y3), 2))) < lEnd
				) {

			return 0;
		}

		else {
			al_draw_line(xv, yv, x1, y1, al_map_rgb(0, 50, 255), 1);
			al_draw_line(xv, yv, x2, y2, al_map_rgb(0, 50, 200), 1);
			al_draw_line(xv, yv, x3, y3, al_map_rgb(0, 50, 100), 1);


			if (lEnd <= 5) {
				al_flip_display();
				al_rest(0.000075); //Ponemos un delay muy chico para que el dibujo sea fluido pero no instantáneo.
			}
			else if (lEnd <= 10) {
				al_flip_display();
				al_rest(0.0015);
			}
			else if (lEnd <= 20) {
				al_flip_display();
				al_rest(0.0030);
			}
			else if (lEnd <= 40) {
				al_flip_display();
				al_rest(0.006);
			}
			else if (lEnd <= 100) {
				al_flip_display();
				al_rest(0.5);
			}
			else {
				al_flip_display();
				al_rest(0.75);
			}


			TriRecurs(xv, x1, x2, yv, y1, y2, lEnd); //La recursividad debe repetirse una vez por cada nuevo triangulo creado.
			TriRecurs(xv, x2, x3, yv, y2, y3, lEnd); //Las lineas que van desde los vertices hasta el centro de masa crean 3 nuevos triangulos.
			TriRecurs(xv, x1, x3, yv, y1, y3, lEnd); //Entonces se llama a la recursividad con las combinaciones de vertices de cada triangulo creado.

		}

		return 0;
}