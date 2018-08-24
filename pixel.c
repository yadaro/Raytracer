/*
** pixel.c for raytracer in /home/Yadaro/raytracer1
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Sat Mar 11 14:19:54 2017 Yadaro YUN
** Last update Wed Mar 22 14:20:33 2017 Yadaro YUN
*/

#include "my.h"

void	put_pixel(sfUint8* pixels, sfVector2i screen_pos, sfColor color)
{
  pixels[(SCREEN_WIDTH * screen_pos.y + screen_pos.x) * 4] = color.r;
  pixels[(SCREEN_WIDTH * screen_pos.y + screen_pos.x) * 4 + 1] = color.g;
  pixels[(SCREEN_WIDTH * screen_pos.y + screen_pos.x) * 4 + 2] = color.b;
  pixels[(SCREEN_WIDTH * screen_pos.y + screen_pos.x) * 4 + 3] = color.a;
}

sfUint8*	create_pixel_buffer(int width, int height)
{
  int		i;
  sfUint8*	pixels;

  pixels = malloc(width * height * 4 * sizeof(*pixels));
    if (pixels == NULL)
    {
      exit(EXIT_FAILURE);
    }
  i = 0;
  while (i < width * height * 4)
    {
      pixels[i] = 0;
      i = i + 1;
    }
  return (pixels);
}
