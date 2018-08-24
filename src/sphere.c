/*
** sphere.c for raytracer1 in /home/Yadaro/raytracer1
**
** Made by Yadaro YUN
** Login   <yadaro.yun@epitech.eu>
**
** Started on  Mon Feb 27 14:24:34 2017 Yadaro YUN
** Last update Wed Mar 22 16:27:43 2017 Yadaro YUN
*/

#include "my.h"
#include "sphere.h"


float		intersect_sphere(sfVector3f eye_pos,
				 sfVector3f dir_vector, float radius)
{
  t_my_sphere	sphere;
  
  if (radius == 50)
    eye_pos.z = eye_pos.z - 100;
  sphere.a = powf(dir_vector.x, 2) +
    powf(dir_vector.y, 2) + powf(dir_vector.z, 2);
  if (sphere.a == 0)
    return (-1.0f);
  sphere.b = 2 * (eye_pos.x * dir_vector.x + dir_vector.y
		  * eye_pos.y + eye_pos.z * dir_vector.z);
  if (sphere.b == 0)
    return (-1.0f);
  sphere.c = (powf(eye_pos.x, 2) + powf(eye_pos.y, 2) + powf(eye_pos.z, 2)
	      - powf(radius, 2));
  if (sphere.c == 0)
    return (-1.0f);
  sphere.dis = powf(sphere.b, 2) - 4 * sphere.a * sphere.c;
   if (sphere.a < 0 || sphere.dis < 0)
    return (-1.0f);
  else if (sphere.dis == 0)
    {
      if ((sphere.k1 = (-sphere.b / (2.0f * sphere.a)) >= 0))
	return (sphere.k1);
      else
	return (-1.0f);
    }
   if (sphere.dis > 0)
     {
       sphere.k1 = (-sphere.b + sqrt(sphere.dis)) / (2 * sphere.a);
       sphere.k2 = (-sphere.b - sqrt(sphere.dis)) / (2 * sphere.a);
       if (sphere.k2 < 0 && sphere.k1 < 0)
	 return (-1.0f);
       else if (sphere.k2 > sphere.k1 && sphere.k1 > 0)
	 {
	   if (sphere.k1 < 0)
	     return (-1.0f);
	   else
	     return (sphere.k1);
	 }
       else if (sphere.k2 < sphere.k1 && sphere.k2 > 0)
	 {
	   if (sphere.k2 < 0)
	     return (-1.0f);
	   else
	     return (sphere.k2);
	 }
     }
   return (-1.0f);
}

sfVector3f	get_normal_sphere(sfVector3f intersection_point)
{
  sfVector3f	normal_vec;

  normal_vec.x = intersection_point.x;
  normal_vec.y = intersection_point.y;
  normal_vec.z = intersection_point.z;
  return (normal_vec);
}
