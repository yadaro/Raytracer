/*
** color.c for raytracer in /home/Yadaro/raytracer1
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Tue Mar 21 14:48:38 2017 Yadaro YUN
** Last update Tue Mar 21 15:44:15 2017 Yadaro YUN
*/

#include "my.h"

t_scal		*calcul_scal(float k, t_pos pos, t_vector vector)
{
  sfVector3f	intersec_point;
  t_scal	*scal;

  scal = malloc(sizeof(t_scal));
  intersec_point.x = vector.dir_vector.x * k + pos.eye_pos.x;
  intersec_point.y = vector.dir_vector.y * k + pos.eye_pos.y;
  intersec_point.z = vector.dir_vector.z * k + pos.eye_pos.z;
  vector.light_vector = calc_vec_light(pos.light_pos, intersec_point);
  scal->normal_sphere = get_normal_sphere(intersec_point);
  scal->normal_plane = get_normal_plane(0);
  scal->normal_cylinder = get_normal_cylinder(intersec_point);
  scal->normal_cone = get_normal_cone(intersec_point, 30);
  scal->cos = get_light_coef(vector.light_vector, scal->normal_sphere);
  scal->cos2 = get_light_coef(vector.light_vector, scal->normal_plane);
  scal->cos3 = get_light_coef(vector.light_vector, scal->normal_cylinder);
  scal->cos4 = get_light_coef(vector.light_vector, scal->normal_cone);
  return (scal);
}

sfColor		put_color2(int form, float k, t_pos pos, t_vector vector)
{
  sfColor	color;
  t_scal	*scal;

  scal = calcul_scal(k, pos, vector);
  if (form == 3)
     {
      color.r = 255 * scal->cos3;
      color.g = 0;
      color.b = 0;
      color.a = 255;
    }
   if (form == 4)
     {
       color.r = 120 * scal->cos4;
       color.g = 120 * scal->cos4;
       color.b = 0;
       color.a = 255;
     }
   return (color);
}

sfColor		put_color(int form, float k, t_pos pos, t_vector vector)
{
  sfColor	color;
  t_scal	*scal;

  scal = calcul_scal(k, pos, vector);
  if (form == 1)
    {
      color.r = 0;
      color.g = 0;
      color.b = 255 * scal->cos;
      color.a = 255;
    }
  if (form == 2)
    {
      color.r = 0;
      color.g = 255 * scal->cos2;
      color.b = 0;
      color.a = 255;
    }
  return (color);
}
