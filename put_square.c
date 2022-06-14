/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:16:33 by makacem           #+#    #+#             */
/*   Updated: 2022/06/14 11:21:04 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_square(int x0, int y0, void *test, int color)
{
	int x1;
	int y1;
	int distance;

	distance = 110;
	x0 = x0 - (distance/2);
	y0 = y0 - (distance/2);
	
	x1 = x0 + distance;
	y1 = y0 + distance; 
	while(x0 <= x1)
	{
		my_mlx_pixel_put(test, x0, y0, color);
		my_mlx_pixel_put(test, x0, y1, color);
		x0++;
	}
	x0 = x1 - distance;
	while(y0 <= y1)
	{
		my_mlx_pixel_put(test, x0, y0, color);
		my_mlx_pixel_put(test, x1, y0, color);
		y0++;
	}
}

int	click(int keycode, t_data *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	int red = 0x00FF0000;
	//int green = 0x0000FF00;
	// int	blue = 0x000000FF;
	//int	black = 0x00000000;
	
	t_data *img;
	img = (t_data *) param ;

	if(button == 1)
		put_square(x, y, param, red);

	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "put_square");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
	mlx_hook(img.mlx_win, 2, 0, click, &img);
	mlx_mouse_hook(img.mlx_win, mouse_hook, &img);
	
	mlx_loop(img.mlx);
}
