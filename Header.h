#ifndef header
#define success 1
#define error 0




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
	int lstart;
	int lend;
	float lconstant;
	float left_angle;
	float right_angle;
	float x0;
	float y0;
	float xf;
	float yf;
} fractal_data;


#endif // !1