#ifndef header
#define header

#define success 1
#define error 0

#define CANTIDAD_OPCIONES 11
typedef enum
{
	poligono,
	uniforme,
	mandelbrot
} fractal_type_num;

typedef struct
{
	int flags[11];
	fractal_type_num type;
	int sides;
	int lStart;
	int lEnd;
	float lConstant;
	float leftAngle;
	float rightAngle;
	float x0;
	float y0;
	float xf;
	float yf;
} fractal_data;


#endif // !1