#include<stdio.h>
#include <allegro5\allegro5.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>

#include "Triangles.h"
#include "Mandelbrot.h"
#include "Octogon.h"
#include "header.h"
#include "parsecmdl.h"
#include "parser.h"

int install_allegro(ALLEGRO_DISPLAY * display, ALLEGRO_SAMPLE* sample);
void uninstall_allegro(ALLEGRO_DISPLAY * display, ALLEGRO_SAMPLE* sample);
int check_values(fractal_data * data);


int main (int argc, char * argv[])
{
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_SAMPLE * ThomasTheEngine = NULL;
	//ALLEGRO_SAMPLE * GuilleTheme;
	//ALLEGRO_SAMPLE * RickAstley;
	int i;


	fractal_data parameters = { 0 };

	for(i = 0; i < CANTIDAD_OPCIONES; i++)
	{
		parameters.flags[i] = 0;
	}


	if (install_allegro(display, ThomasTheEngine))
	{
		/* parameters.type = mandelbrot;
		parameters.sides = 9;
		parameters.lConstant = 0.5;
		parameters.leftAngle = 70;
		parameters.rightAngle = -70;
		parameters.x0 = 0;
		parameters.y0 = 2000;
		parameters.lStart = 1000;
		parameters.lEnd = 100;
		parameters.yf = 0;
		parameters.xf = 2000;
		*/ //Esto mati borralo despues, los deje aca por si queres forzarle parametros directamente. Comentá los ifs de abajo y mete el llamado del mandel aca.


		if(parseCmdLine(argc, argv, &parseCallback, &parameters))
		{
			if(check_values(&parameters))
			{
				if(parameters.type == poligono)
				{
					recurs(parameters.x0, parameters.y0, parameters.sides, parameters.lStart, parameters.lEnd, parameters.lConstant);
				}
				else if(parameters.type == uniforme)
				{
					triFractal(parameters.x0, parameters.y0, parameters.lStart, parameters.leftAngle, parameters.rightAngle, parameters.lEnd);
				}
				else if(parameters.type == mandelbrot)
				{
					mandelbrotfun(parameters.x0, parameters.y0, parameters.xf, parameters.yf);
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
		uninstall_allegro(display, ThomasTheEngine);
		
	}
	else
	{
		printf("Allegro instalation failed.\n");

	}
	getchar();
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
						if((sample = al_load_sample( "Thomas.wav" )) != NULL)
						{
							printf("Sample(s) loaded.\n");
							if((display = al_create_display(XMAX, YMAX)) != NULL)
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

int check_values(fractal_data * data)
{
	int return_value = 0;
	if (data->flags[0])
	{
		if (data->type == mandelbrot)
		{
			if ((data->flags[1] == 0) && (data->flags[2] == 0) && (data->flags[3] == 0) && (data->flags[4] == 0) && (data->flags[5] == 0) && (data->flags[6] == 0) && (data->flags[7] == 1) && (data->flags[8] == 1) && (data->flags[9] == 1) && (data->flags[10] == 1))
			{
				return_value = 1;

			}
		}
		else if (data->type == poligono)
		{
			if ((data->flags[1] == 1) && (data->flags[2] == 1) && (data->flags[3] == 1) && (data->flags[4] == 1) && (data->flags[5] == 0) && (data->flags[6] == 0) && (data->flags[7] == 1) && (data->flags[8] == 1) && (data->flags[9] == 0) && (data->flags[10] == 0))
			{
				return_value = 1;
			}
		}
		else if (data->type == uniforme)
		{
			if ((data->flags[1] == 0)  && (data->flags[2] == 1) && (data->flags[3] == 1) && (data->flags[4] == 0) && (data->flags[5] == 1) && (data->flags[6] == 1) && (data->flags[7] == 1) && (data->flags[8] == 1) && (data->flags[9] == 0) && (data->flags[10] == 0))
			{
				if ((data->leftAngle + data->rightAngle) != 180)
				{
					return_value = 1;

				}
			}
		}
	}
	return return_value;

}


