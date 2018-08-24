/*
** normal.h for raytracer in /home/Yadaro/raytracer1/include
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Fri Mar 17 17:43:14 2017 Yadaro YUN
** Last update Tue Mar 21 15:42:56 2017 Yadaro YUN
*/


#ifndef		_SCAL_H_
# define	_SCAL_H_

typedef	struct		s_scal
{
  sfVector3f		normal_sphere;
  sfVector3f		normal_cylinder;
  sfVector3f		normal_plane;
  sfVector3f		normal_cone;
  float			cos;
  float			cos2;
  float			cos3;
  float			cos4;
}			t_scal;


#endif		/* !_SCAL_H_ */
