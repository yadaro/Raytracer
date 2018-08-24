/*
** cone.h for raytracer in /home/Yadaro/raytracer1/include
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Fri Mar 17 19:22:14 2017 Yadaro YUN
** Last update Fri Mar 17 19:24:17 2017 Yadaro YUN
*/

#include "my.h"

#ifndef		_CONE_H_
# define	_CONE_H_

typedef	struct	s_cone
{
  float		a;
  float		b;
  float		c;
  float		k1;
  float		k2;
  float		dis;
}		t_cone;

#endif		/* !_CONE_H_ */
