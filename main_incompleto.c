#include<stdio.h>
#include <allegro5\allegro5.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>

#include "Triangles.h"
#include "Mandelbrot.h"
#include "Octogon.h"
#include "header.h"


int install_allegro(ALLEGRO_DISPLAY* display, ALLEGRO_SAMPLE* sample);
void uninstall_allegro(ALLEGRO_DISPLAY* display, ALLEGRO_SAMPLE* sample);

int main (int argc, char * argv[])
{
	ALLEGRO_DISPLAY* display;
	ALLEGRO_SAMPLE* sample;
	fractal_data data;
	int i;
	for(i = 0; i <11; i++)
	{
		data.flags[i] = 0;
	}
	if (install_allegro(display, sample))
	{
		if(parseCmdLine(argc, argv[], pCallback p, void *userData))
		{
			if(check_values(data))
			{
				if(data.type == poligono)
				{
					recursive(data.x, y, &c_re, &c_im, &rad, iteration);
				}
				else if(data.type == uniforme)
				{
					triFractal(x, y, lStart, leftAngle, rightAngle, lEnd);
				}
				else if(data.type == mandelbrot)
				{
					mandelbrot(x0, y0, xf, yf);
				}
			}
			else
			{
				printf("Error found in parameters.\n");
			}
		}
		else
		{
			printf("Error found in parameters.\n");
		}
		uninstall_allegro(display, sample);
	}
	else
	{
		printf("Allegro instalation failed.\n");
	}
	return 0;
}



int install_allegro(ALLEGRO_DISPLAY* display, ALLEGRO_SAMPLE* sample)
{
	if(al_init())
	{
		printf("Allegro initialized.\n");
		if(al_init_primitives_addon())
		{
			printf("Allegro primitives addon initialized.\n");
			if(al_install_audio())
			{
				printf("Allegro audio module installed.\n");
				if(al_init_acodec_addon())
				{
					printf("Allegro acodec addon initialized.\n");
					if(al_reserve_samples(1))
					{
						printf("Sample(s) reserved.\n");
						if((sample = al_load_sample( SAMPLE_FILE_NAME )) != NULL)
						{
							printf("Sample(s) loaded.\n");
							if((display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT)) != NULL)
							{
								printf("Display created.\n");
								return success;
								//al_destroy_display(display);
							}
							else
							{
								printf("Could not create display.\n");
							}
							al_destroy_sample(sample);
						}
						else
						{
							printf("Could not load sample(s).\n");
						}
					}
					else
					{
						printf("Could not reserve sample(s).\n");
					}
				}
				else
				{
					printf("Could not install acodec addon.\n");
				}
				al_uninstall_audio();
			}
			else
			{
				printf("Could not install audio.\n");
			}
			al_shutdown_primitives_addon();
		}
		else
		{
			printf("Could not initiate primitives addon.\n");
		}
		al_uninstall_system();
	}
	else
	{
		printf("Could not initiate allegro.\n");
	}
	return error;
}

void uninstall_allegro(ALLEGRO_DISPLAY* display, ALLEGRO_SAMPLE* sample)
{
	al_destroy_display(display);
	al_destroy_sample(sample);
	al_uninstall_audio();
	al_shutdown_primitives_addon();
	al_uninstall_system();
}




