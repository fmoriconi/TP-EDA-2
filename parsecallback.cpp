/***********************************
 Función parseCallback
 ************************************/
#include "parser.h"
#include <stdlib.h>
#include <stdio.h>

#define CANTIDAD_OPCIONES 11
#define MAX_PARAM_SIZE 12
#define MAX_LSTART 600

int parseCallback(char *key, char *value, void *userdata)
{
    
    fractal_data * data = (fractal_data*)userdata; //Esto es redundante, pero visual studio no me dejaba desreferenciarlo bien si no lo hacía.
    
    
    int validez = 1; //Respuesta del callback
    char casehandler[MAX_PARAM_SIZE]; //String para trabajar con las mayusculas/minusculas.
    
    
    if (key == NULL) // Analizo parámetros
    {
        validez = 0;
    }
    else 
    {
        int i, j;
        int cerrarBucle = 0;
        
        if(strlen(&(key[1])) <= MAX_PARAM_SIZE)
		{
            strcpy(casehandler,&(key[1])); // para no tomar con el strcmp el OPTION_IDENTIFIER
        }
        
		if ((!(strcmp(strlower(casehandler), "type"))) && (data->flags[0] == 0))
		{
			if(!(strcmp(strlower(value), "poligono")))
			{
				data->type = poligono;
				data->flags[0] = 1;
			}
			else if(!(strcmp(strlower(value), "uniforme")))
			{
				data->type = uniforme;
				data->flags[0] = 1;
			}
			else if(!(strcmp(strlower(value), "mandelbrot")))
			{
				data->type = mandelbrot;
				data->flags[0] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else if ((!(strcmp(strlower(casehandler), "n"))) && (data->flags[1] == 0))
		{
			if(atoi(value) >= 3)
			{
				data->sides = atoi(value);
				data->flags[1] = 1;
			}
			else
			{
				validez = 0;	
			}
		}
		else if ((!(strcmp(strlower(casehandler), "lstart"))) && (data->flags[2] == 0))
		
			if((atoi(value) > 0) && (atoi(value) <= MAX_LSTART))
			{
				data->lStart = atoi(value);
				data->flags[2] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else if ((!(strcmp(strlower(casehandler), "lend"))) && (data->flags[3] == 0))
		{
			if((atoi(value) > 0) && (atoi(value) <= 100))
			{
				data->lEnd = atoi(value);
				data->flags[3] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else if ((!(strcmp(strlower(casehandler), "lconstant"))) && (data->flags[4] == 0))
		{
			if((atof(value) > 0) && (atof(value) < 1))
			{
				data->lConstant = atof(value);
				data->flags[4] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else if ((!(strcmp(strlower(casehandler), "leftangle"))) && (data->flags[5] == 0))
		{
			if(((atof(value) > 0) && (atof(value) <= 90)))
			{
				data->leftAngle = -atof(value);
				data->flags[5] = 1;
			}
			else if(((atof(value) >= -90) && (atof(value) < 0)))
			{
				data->rightAngle = atof(value);
				data->flags[6] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else if ((!(strcmp(strlower(casehandler), "rightangle"))) && (data->flags[6] == 0))
		{
			if((atof(value) > 0) && (atof(value) <= 90))
			{
				data->rightAngle = atof(value);
				data->flags[6] = 1;
			}
			else if(((atof(value) >= -90) && (atof(value) < 0)))
			{
				data->rightAngle = -atof(value);
				data->flags[6] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else if ((!(strcmp(strlower(casehandler), "x0"))) && (data->flags[7] == 0))
		{
			if((!(strcmp(value, "0"))) || (atof(value) != 0))
			{
				data->x0 = atof(value);
				data->flags[7] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else if ((!(strcmp(strlower(casehandler), "y0"))) && (data->flags[8] == 0))
		{
			if((!(strcmp(value, "0"))) || (atof(value) != 0))
			{
				data->y0 = atof(value);
				data->flags[8] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else if ((!(strcmp(strlower(casehandler), "xf"))) && (data->flags[9] == 0))
		{
			if((!(strcmp(value, "0"))) || (atof(value) != 0))
			{
				data->xf = atof(value);
				data->flags[9] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else if ((!(strcmp(strlower(casehandler), "yf"))) && (data->flags[10] == 0))
		{
			if((!(strcmp(value, "0"))) || (atof(value) != 0))
			{
				data->yf = atof(value);
				data->flags[10] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else  //ocurre en el caso en el que la clave no es valida, o si la clave es valida, pero no su valor
		{
			validez = 0;
		}
        
	}
	printf(" %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d \n", data->flags[0], data->flags[1], data->flags[2], data->flags[3], data->flags[4], data->flags[5], data->flags[6], data->flags[7], data->flags[8], data->flags[9], data->flags[10]);

	return validez;
}

/***********************************
 Función strlwr
 ************************************/

char* strlower(char str[])
{ 
    int i = 0; 
    
    while(str[i] != '\0') 
    { 
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + ('a' - 'A');
        }
        i++; 
    }
    return str;
} 