int check_values(fractal_data data)
{
	int return_value = 0;
	if(data.flags[0])
	{
		if(type == mandelbrot)
		{
			if((flags[1] == 0) && (flags[2] == 0) && (flags[3] == 0) && (flags[4] == 0) && (flags[5] == 0) && (flags[6] == 0) && (flags[7] == 1) && (flags[8] == 1) && (flags[9] == 1) && (flags[10] == 1))
			{
				return_value = 1;
			}
		}
		else if(type == poligono)
		{
			if((flags[1] == 1) && (flags[2] == 1) && (flags[3] == 1) && (flags[4] == 1) && (flags[5] == 0) && (flags[6] == 0) && (flags[7] == 0) && (flags[8] == 0) && (flags[9] == 0) && (flags[10] == 0))
			{
				return_value = 1;
			}
		}
		else if(type == uniforme)
		{
			if((flags[1] == 0) && (flags[2] == 1) && (flags[3] == 1) && (flags[4] == 0) && (flags[5] == 1) && (flags[6] == 1) && (flags[7] == 0) && (flags[8] == 0) && (flags[9] == 0) && (flags[10] == 0))
			{
				if((data.leftangle +data.rightangle) != 180)
				{
					return_value = 1;
				}
			}
		} 
	}
	return return_value;

}