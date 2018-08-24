/*
** plane.c for rayracer in /home/Yadaro/raytracer1
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Sat Mar 11 12:20:44 2017 Yadaro YUN
** Last update Wed Mar 22 14:42:30 2017 Yadaro YUN
*/

#include "my.h"

float	intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float	k;

  if (dir_vector.z != 0)
    k = -eye_pos.z / dir_vector.z;
  else
    return (-1.0f);
  if (k < 0)
    return (-1.0f);
  return (k);
}

sfVector3f	get_normal_plane(int upward)
{
  sfVector3f	normal;

  normal.x = upward;
  normal.y = upward;
  normal.z = 100;

  return (normal);
}
