/*
** vector.h for raytracer in /home/Yadaro/raytracer1/include
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Fri Mar 17 17:37:11 2017 Yadaro YUN
** Last update Tue Mar 21 14:59:22 2017 Yadaro YUN
*/

#ifndef		_VECTOR_H_
# define	_VECTOR_H_

typedef	struct		s_vector
{
  sfVector3f		light_vector;
  sfVector3f		normal_vector;
  sfVector3f		dir_vector;
}			t_vector;

#endif		/* !_VECTOR_H_ */
