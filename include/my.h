/*
** my.h for print_commands in /home/Yadaro/bootcamp-minishell/print_commands
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Fri Jan 27 10:01:39 2017 Yadaro YUN
** Last update Wed Mar 22 16:17:03 2017 Yadaro YUN
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <math.h>
#include "vector.h"
#include "scal.h"
#include "pos.h"

#ifndef		_MY_H_
# define	_MY_H_

#define SCREEN_WIDTH 980
#define SCREEN_HEIGHT 640

void		my_putchar(char c);
void		my_putstr(char *s);
void		draw_square(sfUint8* pixels);
sfUint8		*create_pixel_buffer(int width, int height);
//float		calc(float a, float b, float x1, float dis);
int		process_game_loop(sfRenderWindow *window, sfSprite *sprite);
sfVector3f	calc_dir_vector(float dist_to_plane,
				sfVector2i screen_size, sfVector2i screen_pos);
float		calc_shadow(float k, sfVector3f eye_pos,
			    sfVector3f dir_vector,sfVector3f light_pos);
void		put_pixel(sfUint8* pixels, sfVector2i screen_pos, sfColor color);
sfVector3f	calc_vec_light(sfVector3f light_pos, sfVector3f inter_k);
float		get_light_coef(sfVector3f light_vector, sfVector3f normal_vector);
float		intersect_cylinder(sfVector3f eye_pos,
				   sfVector3f dir_vector, float radius);
float		intersect_sphere(sfVector3f eye_pos,
				 sfVector3f dir_vector, float radius);
float		intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector);
sfVector3f	get_normal_sphere(sfVector3f intersection_point);
sfVector3f	get_normal_plane(int upward);
sfVector3f	get_normal_cylinder(sfVector3f intersection_point);
sfVector3f	get_normal_cone(sfVector3f intersection_point, float semiangle);
float		intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector, float semiangle);
sfColor		put_color2(int form, float k, t_pos pos, t_vector vector);
sfColor		put_color(int form, float k, t_pos pos, t_vector vector);
t_scal		*calcul_scal(float k, t_pos pos, t_vector vector);

#endif		/* !_MY_H_ */
