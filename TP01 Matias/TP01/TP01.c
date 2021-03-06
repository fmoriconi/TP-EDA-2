/**************************************************************
*TP01.c : Defines the entry point for the console application.*
**************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parseCmdLine.h"

#define MAX_COLOR 5


/**********************
*    parseCALLBACK    *
***********************
*SYNTAX: chequea que los valores ingresados por el usuario sean correctos y actualiza la estructura userData apropiadamente con la informaciòn correspondiente.
*INPUT:
*	-key : puede ser tanto una clave como un parámetro según si el parser detectó una opción o un parámetro.
*	-value : valor correspondiente a la clave para esa opción. NULL si key corresponde a un parámetro.
*	-userData : puntero a void a una estructura en la cual se aloja la información de la data ingresada por usuario.
*
*OUTPUT:
*	- si la interpretación de las opciones y/o parámetros es correcta, se devolverá un 1. En caso de que el procesamiento deba detenerse debido
*     al hallazgo de una opción o parámetro inválido, se devolverá un 0.
*/
int parseCallback(char *key, char *value, void *userData);


/******************
*    TYPEDEF´S    *
******************/
typedef struct
{
	int color;
	int cantidad;
	int param1;
	int param2;

}infoType;					//Estructura para trabajar con las keys y params

typedef int(*pCallback) (char *, char*, void *);


/*************
*    MAIN    *
*************/
int main(int argc, char *argv[])
{
	infoType myData = { 0, 0, 0, 0 };
	pCallback functionPtr = &parseCallback;
	printf("%d\n", parseCmdLine(argc, argv, functionPtr, &myData));
	//printf("%d, %d, %d, %d\n", myData.cantidad, myData.color, myData.param1, myData.param2);    //used for test purposes
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int parseCallback(char *key, char *value, void *userData)
{

	infoType *myData = (infoType *)userData;

	int validInput = 0;

	if (key != NULL)				//si recibe key y valor
	{
		if (!strcmp(key, "color"))               //filtra los keys validos
		{
			if ((atoi(value) <= MAX_COLOR) && (atoi(value) >= 0))        //solo existe un codigo de colores que va del 0 al MAX_COLOR
			{
				myData->color = atoi(value);       //en caso valido se guarda el valor del key en myData
				validInput = 1;
			}
			else
				validInput = 0;
		}
		else if (!strcmp(key, "cantidad"))
		{
			if (atoi(value) >= 0)                          //cantidad positivas nadamas
			{
				myData->cantidad = atoi(value);
				validInput = 1;
			}
			else
				validInput = 0;
		}
		else
			validInput = 0;
	}
	else                                            //en caso de podeer el key en NULL, es un parametro
	{
		if (!(myData->param1))                         //esta funcion de callback esta programada para solamente recibir dos parametros
		{                                           //al recibir el primero modifica el bool en myData
			myData->param1 = 1;
			validInput = 1;
		}
		else if (!(myData->param2))
		{
			myData->param2 = 1;
			validInput = 1;
		}
		else
			validInput = 0;		//recibi un parametro ya teniendo los lugares posibles ocupados
	}
	return validInput;
}