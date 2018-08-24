/*
** light.c for raytracer in /home/Yadaro/raytracer1
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Wed Mar 15 17:22:48 2017 Yadaro YUN
** Last update Tue Mar 21 21:25:25 2017 Yadaro YUN
*/

#include "my.h"

float		get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
{
  float		cos;
  float		norm_light;
  float		norm_normal;
  float		scal;
  float		dis;

  norm_light = sqrt(powf(light_vector.x, 2) +
		    powf(light_vector.y, 2) + powf(light_vector.z, 2));
  norm_normal = sqrt(powf(normal_vector.x, 2) +
		     powf(normal_vector.y, 2) + powf(normal_vector.z, 2));
  scal = (light_vector.x * normal_vector.x) +
    (light_vector.y * normal_vector.y) + (light_vector.z * normal_vector.z);
  dis = norm_light * norm_normal;
  cos = scal / dis;
  if (cos < 0)
    return (0.0f);
  return (cos);
}

sfVector3f	calc_vec_light(sfVector3f light_pos, sfVector3f inter_k)
{
  sfVector3f	light_vec;

  light_vec.x = light_pos.x - inter_k.x;
  light_vec.y = light_pos.y - inter_k.y;
  light_vec.z = light_pos.z - inter_k.z;
  return (light_vec);
}
