/*
** cone.c for raytracer in /home/Yadaro/raytracer1/src
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Fri Mar 17 19:19:34 2017 Yadaro YUN
** Last update Wed Mar 22 11:11:29 2017 Yadaro YUN
*/

#include "my.h"
#include "cone.h"

float		intersect_cone(sfVector3f eye_pos,
			       sfVector3f dir_vector, float semiangle)
{
  t_cone	cone;

  cone.a = pow(dir_vector.x, 2) + pow(dir_vector.y, 2) - pow(dir_vector.z, 2)
    * pow(tan(semiangle * M_PI / 180), 2);
  cone.b = 2 * eye_pos.x * dir_vector.x + 2 * eye_pos.y * dir_vector.y -
    ((2 * eye_pos.z * dir_vector.z) * pow(tan(semiangle * M_PI / 180), 2));
  cone.c = pow(eye_pos.x, 2) + pow(eye_pos.y, 2) -
    ((pow(eye_pos.z, 2) * pow(tan(semiangle * M_PI/ 180), 2)));
  cone.dis = pow(cone.b, 2) - 4 * cone.a * cone.c;
  if (cone.dis > 0)
    {
      cone.k1 = (-cone.b + sqrt(cone.dis)) / (2 * cone.a);
      cone.k2 = (-cone.b - sqrt(cone.dis)) / (2 * cone.a);
      if (cone.k1 < cone.k2)
	return (cone.k1);
      else
	return (cone.k2);
    }
  else if (cone.dis == 0)
    {
      if ((cone.k1 = -cone.b / 2 * cone.a) < 0)
	return (-1.0f);
      else
	return (cone.k1);
    }
   else if (cone.dis < 0 || cone.a == 0)
     return (-1.0f);
   else
     return (-1.0f);
}

sfVector3f	get_normal_cone(sfVector3f intersection_point, float semiangle)
{
  sfVector3f	normal_vec;

  normal_vec.x = intersection_point.x;
  normal_vec.y = intersection_point.y;
  normal_vec.z = -tan((semiangle * M_PI) / 180) * intersection_point.z;
  return (normal_vec);
}
