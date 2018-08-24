/*
** windows.h for raytracer in /home/Yadaro/raytracer1
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Fri Mar 10 10:22:15 2017 Yadaro YUN
** Last update Thu Mar 16 14:08:17 2017 Yadaro YUN
*/

#include "my.h"

#ifndef		_WINDOW_H_
# define	_WINDOW_H_

typedef	struct		s_window
{
  sfRenderWindow*	win;
  sfTexture*		texture;
  sfSprite*		sprite;
  sfEvent		event;
}			t_window;

#endif		/* !_WINDOW_H_ */
