/*
** main.c for raytracer1 in /home/Yadaro/raytracer1
** 
** Made by Yadaro YUN
** Login   <Yadaro@epitech.net>
** 
** Started on  Sat Mar 11 13:56:43 2017 Yadaro YUN
** Last update Wed Mar 22 11:00:47 2017 Yadaro YUN
*/

#include "my.h"
#include "sphere.h"
#include "windows.h"
#include "scal.h"
#include "vector.h"
#include "pos.h"

sfRenderWindow	*create_window(char* name, int width, int height)
{
  t_window	*window;
  sfVideoMode	mode;

  window = malloc(sizeof(t_window));
  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window->win = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window->win == NULL)
    return (0);
  return (window->win);
}


void		print_form(sfUint8* pixels, t_pos pos)
{
  sfVector2i	screen_pos;
  sfVector2i	screen_size;
  t_vector	vector;
  float		k1;
  float		k2;
  float		k3;
  float		k4;

  screen_pos.x = 0;
  screen_pos.y = 0;
  screen_size.x = SCREEN_WIDTH;
  screen_size.y = SCREEN_HEIGHT;
  while (screen_pos.y < SCREEN_HEIGHT)
    {
      while (screen_pos.x < SCREEN_WIDTH)
	{
	  vector.dir_vector = calc_dir_vector(500, screen_size, screen_pos);
	  k1 = intersect_sphere(pos.eye_pos, vector.dir_vector, 50);
	  k2 = intersect_plane(pos.eye_pos, vector.dir_vector);
	  k3 = intersect_cylinder(pos.eye_pos, vector.dir_vector, 30);
	  k4 = intersect_cone(pos.eye_pos, vector.dir_vector, 30);
	  if (k1 > 0)
	    put_pixel(pixels, screen_pos, put_color(1, k1, pos, vector));
	  if (k2 > 0)
	    put_pixel(pixels, screen_pos, put_color(2, k2, pos, vector));
	  if (k1 < k2 && k1 > 0)
	    put_pixel(pixels, screen_pos, put_color(1, k1, pos, vector));
	  if (k3 > 0)
	    put_pixel(pixels, screen_pos, put_color2(3, k3, pos, vector));
	  if (k1 < k3 && k1 > 0)
	    put_pixel(pixels, screen_pos, put_color(1, k1, pos, vector));
	  if (k4 > 0)
	    put_pixel(pixels, screen_pos, put_color2(4, k4, pos, vector));
	  if (k1 > k4 && k1 > 0)
	    put_pixel(pixels, screen_pos, put_color(1, k1, pos, vector));
	  screen_pos.x++;
	}
      screen_pos.x = 0;
      screen_pos.y++;
    }
}

int		loop_window(sfUint8 *pixels, t_window *window, t_pos pos)
{
  while (sfRenderWindow_isOpen(window->win))
    {
      while (sfRenderWindow_pollEvent(window->win, &(window->event)))
	{
	  if (window->event.type == sfEvtClosed)
	    sfRenderWindow_close(window->win);
	}
      pixels = create_pixel_buffer(SCREEN_WIDTH, SCREEN_HEIGHT);
      sfRenderWindow_clear(window->win, sfBlack);
      sfRenderWindow_drawSprite(window->win, window->sprite, NULL);
      sfRenderWindow_display(window->win);
      if (sfKeyboard_isKeyPressed(sfKeyR) == sfTrue)
	pos.eye_pos.z = pos.eye_pos.z + 7;
      if (sfKeyboard_isKeyPressed(sfKeyF) == sfTrue)
	pos.eye_pos.z = pos.eye_pos.z - 7;
      if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
	pos.eye_pos.x = pos.eye_pos.x + 7;
      if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
	pos.eye_pos.x = pos.eye_pos.x - 7;
      if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
	pos.eye_pos.y = pos.eye_pos.y + 7;
      if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
	pos.eye_pos.y = pos.eye_pos.y - 7;
      if (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue)
	pos.light_pos.z = pos.light_pos.z + 7;
      if (sfKeyboard_isKeyPressed(sfKeyM) == sfTrue)
	pos.light_pos.z = pos.light_pos.z - 7;
      if (sfKeyboard_isKeyPressed(sfKeyO) == sfTrue)
	pos.light_pos.y = pos.light_pos.y + 7;
      if (sfKeyboard_isKeyPressed(sfKeyL) == sfTrue)
	pos.light_pos.y = pos.light_pos.y - 7;
      print_form(pixels, pos);
      sfTexture_updateFromPixels(window->texture,
				 pixels, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
      free(pixels);
    }
  sfRenderWindow_destroy(window->win);
  return (0);
}

int		main()
{
  t_window	*window;
  sfUint8	*pixels;
  t_pos		pos;

  window = malloc(sizeof(t_window));
  pixels = NULL;
  pos.light_pos.x = -200;
  pos.light_pos.y = 100;
  pos.light_pos.z = 100;
  pos.eye_pos.x = -200;
  pos.eye_pos.y = 1;
  pos.eye_pos.z = 30;
  window->win = create_window("SFML Window", SCREEN_WIDTH, SCREEN_HEIGHT);
  window->sprite = sfSprite_create();
  window->texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(window->sprite, window->texture, sfTrue);
  loop_window(pixels, window, pos);
  return (0);
}
