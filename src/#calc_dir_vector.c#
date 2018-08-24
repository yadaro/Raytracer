/*
** calc_dir.c for raytracer1 in /home/Yadaro/raytracer1
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Tue Mar 14 16:16:29 2017 Yadaro YUN
** Last update Fri Mar 17 15:10:24 2017 Yadaro YUN
*/

#include "my.h"

sfVector3f	calc_dir_vector(float dist_to_plane,
				sfVector2i screen_size, sfVector2i screen_pos)
{
  sfVector3f	dir_vector;

  dir_vector.x = dist_to_plane;
  dir_vector.y = (screen_size.x / 2) - screen_pos.x;
  dir_vector.z = (screen_size.y / 2) - screen_pos.y;
  return (dir_vector);
}
