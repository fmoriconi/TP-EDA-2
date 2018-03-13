/***********************************
 Función parseCallback
 ************************************/
#include "parser.h"


int parseCallback(char *key, char *value, void *userdata)
{
    
    userdata_t * data = (fractal_data*)userData; //Esto es redundante, pero visual studio no me dejaba desreferenciarlo bien si no lo hacía.
    
    
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
        
        for (i = 0; (i < CANTIDAD_OPCIONES) && (cerrarBucle == 0); i++) //ciclo el arreglo de opciones hasta hallar la clave igual
        {
		if ((!(strcmp(strlwr(casehandler), "type"))) && (userdata.flags[0] == 0))
		{
			if(!(strcmp(stlwr(value), "poligono")))
			{
				userdata.type = poligono;
				userdata.flags[0] = 1;
			}
			else if(!(strcmp(stlwr(value), "uniforme")))
			{
				userdata.type = uniforme;
				userdata.flags[0] = 1;
			}
			else if(!(strcmp(stlwr(value), "mandelbrot")))
			{
				userdata.type = mandelbrot;
				userdata.flags[0] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else if ((!(strcmp(strlwr(casehandler), "n"))) && (userdata.flags[1] == 0))
		{
			if(atoi(value) > 3)
			{
				userdata.sides = atoi(value);
				userdata.flags[1] = 1;
			}
			else
			{
				validez = 0;	
			}
		}
		else if ((!(strcmp(strlwr(casehandler), "lstart"))) && (userdata.flags[2] == 0))
		{
			if((atoi(value) > 0) && (atoi(value) <= 100))
			{
				userdata.lstart = atoi(value);
				userdata.flags[2] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else if ((!(strcmp(strlwr(casehandler), "lend"))) && (userdata.flags[3] == 0))
		{
			if((atoi(value) > 0) && (atoi(value) < 100))
			{
				userdata.lend = atoi(value);
				userdata.flags[3] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else if ((!(strcmp(strlwr(casehandler), "lconstant"))) && (userdata.flags[4] == 0))
		{
			if((atof(value) > 0) && (atof(value) < 1))
			{
				userdata.lconstant = atof(value);
				userdata.flags[4] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else if ((!(strcmp(strlwr(casehandler), "leftangle"))) && (userdata.flags[5] == 0))
		{
			if(((atof(value) > 0) && (atof(value) <= 90)))
			{
				userdata.leftangle = -atof(value);
				userdata.flags[5] = 1;
			}
			else if(((atof(value) >= -90) && (atof(value) < 0)))
			{
				userdata.rightangle = atof(value);
				userdata.flags[6] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else if ((!(strcmp(strlwr(casehandler), "rightangle"))) && (userdata.flags[6] == 0))
		{
			if((atof(value) > 0) && (atof(value) <= 90))
			{
				userdata.rightangle = atof(value);
				userdata.flags[6] = 1;
			}
			else if(((atof(value) >= -90) && (atof(value) < 0)))
			{
				userdata.rightangle = -atof(value);
				userdata.flags[6] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else if ((!(strcmp(strlwr(casehandler), "x0"))) && (userdata.flags[7] == 0))
		{
			if((!(strcmp(value, "0"))) || (atof(value) != 0))
			{
				userdata.x0 = atof(value);
				userdata.flags[7] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else if ((!(strcmp(strlwr(casehandler), "y0"))) && (userdata.flags[8] == 0))
		{
			if((!(strcmp(value, "0"))) || (atof(value) != 0))
			{
				userdata.y0 = atof(value);
				userdata.flags[8] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else if ((!(strcmp(strlwr(casehandler), "xf"))) && (userdata.flags[9] == 0))
		{
			if((!(strcmp(value, "0"))) || (atof(value) != 0))
			{
				userdata.xf = atof(value);
				userdata.flags[9] = 1;
			}
			else
			{
				validez = 0;
			}
		}
		else if ((!(strcmp(strlwr(casehandler), "yf"))) && (userdata.flags[10] == 0))
		{
			if((!(strcmp(value, "0"))) || (atof(value) != 0))
			{
				userdata.yf = atof(value);
				userdata.flags[10] = 1;
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
        
	}
    
    return validez;
}

/***********************************
 Función strlwr
 ************************************/

char* strlwr(char str[])
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