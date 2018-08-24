/*
** framebuffer.h for zeiof in /home/Yadaro/Pingouin/bootstrap_pingouin_csfml
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Fri Feb 10 14:56:14 2017 Yadaro YUN
** Last update Fri Mar 17 16:44:58 2017 Yadaro YUN
*/

#include "my.h"

#ifndef		_FRAMEBUFFER_H_
# define	_FRAMEBUFFER_H_

typedef struct	s_my_framebuffer
{
  sfUint8	*pixels;
  int		width;
  int		height;
}		t_my_framebuffer;


#endif		/* !_FRAMEBUFFER_H_ */
