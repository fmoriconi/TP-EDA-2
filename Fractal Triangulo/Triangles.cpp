#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include "Triangles.h"


void triFractal(float x, float y, float lbase, float langle, float rangle, float lend) {

	float x2 = x + lbase; //Coordenada del final de la base
	float x3 = x + lbase * (1 - cos(langle*3.14 / 180)); //La coordenada X del tercer vértice.
	float y3 = y - tan(langle*3.14 / 180)*x3; //La coordenada Y del tercer vértice. sohcahTOA: Tan(langle)*adyacente = opuesto (altura).


	drawTriangle(x, x2, x3, y, y3);


	TriRecurs(x, x2, x3, y, y, y3, lend);

}

void drawTriangle(float x, float x2, float x3, float y, float y3) {

	al_draw_line(x, y, x2, y, al_map_rgb(255, 255, 255), 1); // Dibujo la base
	al_draw_line(x, y, x3, y3, al_map_rgb(255, 255, 255), 1); //Dibujo el lado izquierdo.
	al_draw_line(x2, y, x3, y3, al_map_rgb(255, 255, 255), 1); //Dibujo el lado derecho.
}

int TriRecurs(float x1,float x2,float x3,float y1,float y2,float y3,float lend) {

	float yv = (y1 + y2 + y3) / 3;
	float xv = (x1 + x2 + x3) / 3;

		if (
				(sqrt(pow((xv - x1), 2) + pow((yv - y1), 2))) < lend ||
				(sqrt(pow((xv - x2), 2) + pow((yv - y2), 2))) < lend ||
				(sqrt(pow((xv - x3), 2) + pow((yv - y3), 2))) < lend
				) {
			return 0;
		}

		else {
				al_draw_line(xv, yv, x1, y1, al_map_rgb(255, 255, 255), 1);
				al_draw_line(xv, yv, x2, y2, al_map_rgb(255, 255, 255), 1);
				al_draw_line(xv, yv, x3, y3, al_map_rgb(255, 255, 255), 1);

				al_flip_display();
				

				TriRecurs(xv, x1, x2, yv, y1, y2, lend);
				TriRecurs(xv, x2, x3, yv, y2, y3, lend);
				TriRecurs(xv, x1, x3, yv, y1, y3, lend);
		}

		return 0;
}