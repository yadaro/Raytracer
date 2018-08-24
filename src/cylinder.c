/*
** cylinder.c for raytracer in /home/Yadaro/raytracer1
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Mon Mar 13 18:35:05 2017 Yadaro YUN
** Last update Wed Mar 22 11:10:28 2017 Yadaro YUN
*/

#include "my.h"

float	intersect_cylinder(sfVector3f eye_pos,
			   sfVector3f dir_vector, float radius)
{
  float	a;
  float	b;
  float	k1;
  float	k2;
  float	dis;

  if (radius == 30)
    eye_pos.y = eye_pos.y + 10;
  b = 2* eye_pos.x * dir_vector.x + 2 * eye_pos.y * eye_pos.y;
  a = pow(dir_vector.x, 2) + pow(dir_vector.y, 2);
  dis = pow((2 * eye_pos.x * dir_vector.x + 2 * eye_pos.y * dir_vector.y), 2)
    - 4 * (pow(dir_vector.x, 2) + pow(dir_vector.y, 2))
    * (pow(eye_pos.x, 2) + pow(eye_pos.y, 2) - pow(radius, 2));
  if (dis == 0)
    {
      if ((k1 = -b / 2 * a) < 0)
	return (-1.0f);
      else
	return (k1);
    }
  else if (dis < 0 || a == 0)
    return (-1.0f);
  else if (dis > 0)
    {
      k1 = (-b + sqrt(dis)) / (2 * a);
      k2 = (-b - sqrt(dis)) / (2 * a);
      if (k1 < k2)
	return (k1);
      else
	return (k2);
    }
  else
    return (-1.0f);
}

sfVector3f	get_normal_cylinder(sfVector3f intersection_point)
{
  sfVector3f	normal_vec;

  normal_vec.x = intersection_point.x;
  normal_vec.y = intersection_point.y;
  normal_vec.z = 0;
  return (normal_vec);
}
