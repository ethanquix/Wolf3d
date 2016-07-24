/*
** main.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Tue May  3 19:34:05 2016 Dimitri Wyzlic
** Last update Sun Jul 24 16:08:10 2016 Dimitri Wyzlic
*/

#include <lapin.h>
#include "header.h"

void		set_bc(t_bunny_pixelarray *pix)
{
  int		i;
  unsigned	*pixels;

  i = 0;
  while (i < (S_HEIGHT * S_WIDTH) / 2)
    {
      pixels = (unsigned *)pix->pixels;
      pixels[i] = BLACK;
      i = i + 1;
    }
  while (i < S_HEIGHT * S_WIDTH)
    {
      pixels = (unsigned *)pix->pixels;
      pixels[i] = PINK;
      i = i + 1;
    }
}

t_bunny_response	key(t_bunny_event_state state, t_bunny_keysym key, void *p)
{
  t_ray			*ray;
  const bool		*keys;

  ray = p;
  keys = bunny_get_keyboard();
  if (keys == NULL)
    return (EXIT_ON_SUCCESS);
  if (state == GO_DOWN)
    {
      if (keys[BKS_C])
	ray->key_tab[5] = (ray->key_tab[5] == 1) ? 0 : 1;
      if (keys[BKS_B])
	ray->key_tab[4] = (ray->key_tab[4] == 1) ? 0 : 1;
      if ((key == BKS_ESCAPE) || (keys[BKS_RETURN] && put_block(ray) == 1) ||
	  (keys[BKS_T] && change_map(ray) == 1))
	return (EXIT_ON_SUCCESS);
      if (keys[BKS_SPACE])
	set_blank(ray->pix, ray);
      main_key(keys, ray);
    }
  return (GO_ON);
}

t_bunny_response	main_loop(void *p)
{
  t_ray			*ray;
  int			x;

  x = 0;
  ray = p;
  set_bc(ray->pix);
  starfield(ray->pix, ray->star, ray->nstar);
  while (x < S_WIDTH)
    {
      init_stru(&ray->st_pos, &ray->st_cam, ray, x);
      calcul_step(ray);
      do_dda(ray);
      my_verline(x, ray->drawStart, ray->drawEnd, ray->color, ray->pix);
      x = x + 1;
    }
  exe_key(ray->key_tab, ray);
  ray->key_tab = reset_key(ray->key_tab);
  do_disco(ray);
  display_minmap(ray);
  disp_cur_pos(ray);
  bunny_blit(&ray->window->buffer, &ray->pix->clipable, NULL);
  bunny_display(ray->window);
  return (GO_ON);
}

int	end_prg(t_ray *ray)
{
  bunny_delete_clipable(&ray->pix->clipable);
  bunny_delete_sound(&ray->disco->sound);
  bunny_delete_sound(&ray->gun_sound->sound);
  bunny_delete_sound(&ray->reload->sound);
  return (0);
}

int			main(int nb, char **arg)
{
  t_bunny_pixelarray	*pix;
  t_color		*color;
  t_cam			cam;
  t_pos			pos;
  t_ray			ray;

  bunny_set_maximum_ram(20971520);
  if (nb < 2)
    {
      my_putstr("Usage : ./wolf3d [map(.ini)]\nMaps can be found in maps/\n");
      return (1);
    }
  bunny_set_memory_check(true);
  color = bunny_malloc(2 * sizeof(t_color *));
  ray.window = bunny_start(S_WIDTH, S_HEIGHT, 0, "Wolf3d");
  pix = bunny_new_pixelarray(S_WIDTH, S_HEIGHT);
  if (pix == NULL || ray.window == NULL || color == NULL)
    return (1);
  ray.st_pos = pos;
  ray.st_cam = cam;
  ray.pix = pix;
  if (ini_ray(&ray, arg, color) == 1 || ini_set(&ray.st_pos, &ray.st_cam) == 1)
    return (1);
  bunny_set_key_response(key);
  bunny_set_loop_main_function(main_loop);
  bunny_loop(ray.window, 60, &ray);
  return (end_prg(&ray));
}
