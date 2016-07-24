/*
** change_map.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Fri May 27 18:30:01 2016 Dimitri Wyzlic
** Last update Sat Jun  4 07:51:47 2016 Dimitri Wyzlic
*/

#include <lapin.h>
#include "header.h"

int	get_start_pos(t_ray *ray)
{
  int	i;
  int	j;

  i = 0;
  while (i < ray->map_height)
    {
      j = 0;
      while (j < ray->map_width)
	{
	  if (ray->map_data[i][j] == 42)
	    {
	      ray->st_pos.posX = i;
	      ray->st_pos.posY = j;
	      ray->map_data[i][j] = 0;
	      return (0);
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
  return (1);
}

char	**build_list_map()
{
  char	**out;

  out = bunny_malloc(sizeof(char *) * 5);
  if (out == NULL)
    return (NULL);
  out[0] = "level1.ini\0";
  out[1] = "level2.ini\0";
  out[2] = "level3.ini\0";
  out[3] = "level4.ini\0";
  out[4] = "level5.ini\0";
  return (out);
}

int	change_map(t_ray *ray)
{
  ray->map_id = ray->map_id + 1;
  if (ray->map_id > 4)
    ray->map_id = 0;
  reset_minmap(ray);
  if (main_parse_ini(ray, ray->map_id_name[ray->map_id], "level") == 1)
    return (1);
  return (0);
}
/*
** display_c_pos.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 06:44:17 2016 Dimitri Wyzlic
** Last update Sun Jun  5 22:15:20 2016 Dimitri Wyzlic
*/

#include "header.h"

void	disp_cur_pos(t_ray *ray)
{
  int	cposX;
  int	cposY;
  int	i;
  int	j;

  i = 0;
  cposX = (int)ray->st_pos.posX;
  cposY = (int)ray->st_pos.posY;
  while (i < ray->minmap_jx)
    {
      j = 0;
      while (j < ray->minmap_jy)
	{
	  my_tekpixel((i + (ray->minmap_jx * cposX)) % 200, (j
		      + (ray->minmap_jy* cposY)) % 200, ray->pix, TEAL);
	  j = j + 1;
	}
      i = i + 1;
    }
}
/*
** do_disco.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 05:23:02 2016 Dimitri Wyzlic
** Last update Sat Jun  4 18:34:00 2016 Dimitri Wyzlic
*/

#include "header.h"

void	play_disco(t_ray *ray)
{
  if (ray->disco == NULL)
    return;
  bunny_sound_volume(&ray->disco->sound, 30);
  bunny_sound_play(&ray->disco->sound);
}

void	stop_disco(t_ray *ray)
{
  if (ray->disco == NULL)
    return;
  bunny_sound_stop(&ray->disco->sound);
}

void		do_disco(t_ray *ray)
{
  int		i;
  int		j;
  unsigned	*pixels;

  pixels = (unsigned *)ray->pix->pixels;
  i = 0;
  while (i < S_HEIGHT)
    {
      j = 0;
      while (j < S_WIDTH)
	{
	  my_tekpixel(i, j, ray->pix, pixels[j + (i * S_WIDTH)]
		      + ray->color_modif);
	  j = j + 1;
	}
      i = i + 1;
    }
}

void	do_disco_key(t_ray *ray, int todo)
{
  if (todo == 1)
    {
      if (ray->color_modif == 0)
	play_disco(ray);
      ray->color_modif = ray->color_modif + 2;
    }
  else
    {
      if (ray->color_modif > 0)
	stop_disco(ray);
      ray->color_modif = 0;
    }
}
/*
** do_raycast.c for wolf3d in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon May  2 17:46:36 2016 Dimitri Wyzlic
** Last update Jan Jun 5 21:22:27 2016 Dimitri Wyzlic
*/

#include "header.h"

void	set_color(t_color *color, t_ray *ray)
{
  ray->mapX = ABS((ray->mapX + ray->map_height) % ray->map_height);
  ray->mapY = ABS((ray->mapY + ray->map_width) % ray->map_width);
  if (ray->map_data[ray->mapX][ray->mapY] == 1)
    color->full = RED;
  if (ray->map_data[ray->mapX][ray->mapY] == 8)
    color->full = GREEN;
  if (ray->map_data[ray->mapX][ray->mapY] == 3)
    color->full = BLUE;
  if (ray->map_data[ray->mapX][ray->mapY] == 4)
    color->full = WHITE;
  if (ray->side == 1)
    color->full = color->full / 2;
}

void	calcul_step(t_ray *ray)
{
  ray->hit = 0;
  if (ray->rayDirX < 0)
    {
      ray->stepX = -1;
      ray->sideDistX = (ray->rayPosX - ray->mapX) * ray->deltaDistX;
    }
  else
    {
      ray->stepX = 1;
      ray->sideDistX = (ray->mapX + 1.0 - ray->rayPosX) * ray->deltaDistX;
    }
  if (ray->rayDirY < 0)
    {
      ray->stepY = -1;
      ray->sideDistY = (ray->rayPosY - ray->mapY) * ray->deltaDistY;
    }
  else
    {
      ray->stepY = 1;
      ray->sideDistY = (ray->mapY + 1.0 - ray->rayPosY) * ray->deltaDistY;
    }
}

void	do_dda_next(t_ray *ray)
{
  if (ray->side == 0)
    ray->perpWallDist = (ray->mapX - ray->rayPosX + (1 - ray->stepX)
			 / 2) / ray->rayDirX;
  else
    ray->perpWallDist = (ray->mapY - ray->rayPosY + (1 - ray->stepY)
			 / 2) / ray->rayDirY;
  ray->lineHeight = (int)(S_HEIGHT / ray->perpWallDist);
  ray->drawStart = -(ray->lineHeight) / 2 + S_HEIGHT / 2;
  if (ray->drawStart < 0)
    ray->drawStart = 0;
  ray->drawEnd = ray->lineHeight / 2 + S_HEIGHT / 2;
  if (ray->drawEnd >= S_HEIGHT)
    ray->drawEnd = S_HEIGHT - 1;
  set_color(ray->color, ray);
}

void	do_dda(t_ray *ray)
{
  int	i;

  i = 0;
  while (ray->hit == 0 && i < ray->map_height * ray->map_width)
    {
      if (ray->sideDistX < ray->sideDistY)
        {
          ray->sideDistX += ray->deltaDistX;
          ray->mapX += ray->stepX;
          ray->side = 0;
        }
      else
        {
          ray->sideDistY += ray->deltaDistY;
          ray->mapY += ray->stepY;
          ray->side = 1;
        }
      if (ray->map_data[ABS((ray->mapX + ray->map_height)
			    % ray->map_height)][ABS((ray->mapY + ray->map_width)
						    % ray->map_width)] > 0)
	ray->hit = 1;
      i = i + 1;
    }
  do_dda_next(ray);
}
/*
** do_slomo.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 03:50:22 2016 Dimitri Wyzlic
** Last update Sat Jun  4 04:32:50 2016 Dimitri Wyzlic
*/

#include "header.h"

void	main_slowmo(t_ray *ray)
{
  if (ray->is_slowmo == 0)
    {
      ray->st_pos.moveSpeed = 0.02;
      ray->st_pos.rotSpeed = 0.002;
      ray->is_slowmo = 1;
    }
  else
    {
      ray->st_pos.moveSpeed = 0.1;
      ray->st_pos.rotSpeed = 0.01;
      ray->is_slowmo = 0;
    }
}
/*
** draw_gun.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 05:03:42 2016 Dimitri Wyzlic
** Last update Sat Jun  4 13:27:26 2016 Dimitri Wyzlic
*/

#include "header.h"

void	cross_hor(t_ray *ray)
{
 int	start;
 int	end;

 start = (S_WIDTH / 2 - S_WIDTH / 15) % S_WIDTH;
 if (start < 0)
   return;
 end = (S_WIDTH / 2 + S_WIDTH / 15) % S_WIDTH;
 while (start < end)
   {
     my_tekpixel(S_HEIGHT / 2, start, ray->pix, TEAL);
     start = start + 1;
   }
}

void	cross_ver(t_ray *ray)
{
 int	start;
 int	end;

 start = (S_HEIGHT / 2 - S_HEIGHT / 12) % S_HEIGHT;
 if (start < 0)
   return;
 end = (S_HEIGHT / 2 + S_HEIGHT / 12) % S_HEIGHT;
 while (start < end)
   {
     my_tekpixel(start, S_WIDTH / 2, ray->pix, TEAL);
     start = start + 1;
   }
}

void	draw_cross(t_ray *ray)
{
  cross_hor(ray);
  cross_ver(ray);
}
/*
** eff_starfield.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Tue May  3 21:21:46 2016 Dimitri Wyzlic
** Last update Sat Jun  4 08:46:27 2016 Dimitri Wyzlic
*/

#include <lapin.h>
#include "header.h"

t_bunny_star	*set_star(int nb)
{
  t_bunny_star	*star;
  int		i;

  i = 0;
  star = bunny_malloc(nb * (sizeof(t_bunny_star)));
  if (star == NULL)
    return (NULL);
  while (i < nb)
    {
      star[i].x = 50;
      star[i].y = 50;
      star[i].x_speed = -1 - (rand()%1000 / 100.0);
      i = i + 1;
    }
  return (star);
}

void			starfield(t_bunny_pixelarray *pix, t_bunny_star *star,
				  size_t nstar)
{
    unsigned		i;
    t_bunny_position	pos;
    t_color		*color;

    color = bunny_malloc(2 * sizeof(t_color *));
    if (color == NULL)
      return;
    color->full = WHITE;
    i = 0;
    while (i < nstar)
      {
	  star[i].y = star[i].y - star[i].x_speed;
	  if (star[i].y > S_HEIGHT / 2)
	    {
		star[i].y = 0;
		star[i].x = rand() % (S_WIDTH);
	    }
	  pos.x = star[i].x;
	  pos.y = star[i].y;
	  tekpixel(pix, &pos, color);
	  i = i + 1;
      }
    bunny_free(color);
}
/*
** fuck_const.c for dimitri in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Tue May 24 15:54:44 2016 Dimitri Wyzlic
** Last update Jan Jun 5 21:22:54 2016 Dimitri Wyzlic
*/

#include "header.h"

int	my_strlen_const(char const *src)
{
  int	i;

  i = 0;
  if (src == NULL)
    return (-1);
  while (src[i] != '\0')
    i = i + 1;
  return (i);
}

char	*fuck_const(char const *src)
{
  char	*out;
  int	i;
  int	j;

  i = my_strlen_const(src);
  out = bunny_malloc(sizeof(char *) * i);
  if (out == NULL)
    return (NULL);
  j = 0;
  while (i >= 0)
    {
      out[j] = src[j];
      i = i - 1;
      j = j + 1;
    }
  return (out);
}
/*
** get_field_ini.c for dimitri in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Tue May 24 15:36:23 2016 Dimitri Wyzlic
** Last update Jan Jun 5 21:27:29 2016 Dimitri Wyzlic
*/

#include <lapin.h>
#include "header.h"

int	count_ini(t_bunny_ini *ini, char *name_field, char *name)
{
  int	out;

  out = 0;
  while (bunny_ini_get_field(ini, name, name_field, out))
    out = out + 1;
  return (out);
}

int		get_field_int(t_bunny_ini *ini, char *cat, char *field)
{
  char const	*out;

  out = bunny_ini_get_field(ini, cat, field, 0);
  if (out == 0)
    return (0);
  return (my_getnbr(out));
}

char		*get_field_char(t_bunny_ini *ini, char *cat, char *field)
{
  char const	*out;

  out = bunny_ini_get_field(ini, cat, field, 0);
  if (out == 0)
    return (0);
  return (fuck_const(out));
}

int	*get_field_int_s(t_bunny_ini *ini, char *cat, char *field, int max)
{
  int	*out;
  int	i;

  i = 0;
  out = bunny_malloc(sizeof(int *) * max);
  if (out == NULL || max <= 0)
    return (NULL);
  while (i < max)
    {
      out[i] = my_getnbr(bunny_ini_get_field(ini, cat, field, i));
      if (out[i] == -1)
	return (NULL);
      i = i + 1;
    }
  return (out);
}
/*
** gunfire.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 07:00:07 2016 Dimitri Wyzlic
** Last update Sat Jun  4 13:58:46 2016 Dimitri Wyzlic
*/

#include "header.h"

void		set_blank(t_bunny_pixelarray *pix, t_ray *ray)
{
  int		i;
  unsigned	*pixels;

  i = 0;
  if (ray->bullets <= 0)
    {
      bunny_sound_play(&ray->reload->sound);
      ray->bullets = 5;
      return;
    }
  while (i < (S_HEIGHT * S_WIDTH))
    {
      pixels = (unsigned *)pix->pixels;
      pixels[i] = WHITE;
      i = i + 1;
    }
  bunny_sound_play(&ray->gun_sound->sound);
  ray->bullets = ray->bullets - 1;
  bunny_blit(&ray->window->buffer, &ray->pix->clipable, NULL);
  bunny_display(ray->window);
}
/*
** init_stru.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon May  2 18:33:27 2016 Dimitri Wyzlic
** Last update Sat Jun  4 13:56:20 2016 Dimitri Wyzlic
*/

#include <math.h>
#include "header.h"

int	ini_set(t_pos *pos, t_cam *cam)
{
  pos->dirX = 1;
  pos->dirY = 1;
  cam->planeX = 0;
  cam->planeY = 0.66;
  pos->time = 0;
  pos->oldTime = 0;
  pos->moveSpeed = 0.1;
  pos->rotSpeed = 0.01;
  return (0);
}

void	init_stru(t_pos *pos, t_cam *cam, t_ray *ray, int x)
{
  cam->cameraX = 2 * x / (double)S_WIDTH - 1;
  ray->rayPosX = pos->posX;
  ray->rayPosY = pos->posY;
  ray->rayDirX = pos->dirX + cam->planeX * cam->cameraX;
  ray->rayDirY = pos->dirY + cam->planeY * cam->cameraX;
  ray->mapX = (int)ray->rayPosX;
  ray->mapY = (int)ray->rayPosY;
  ray->deltaDistX = sqrt(1 + (ray->rayDirY * ray->rayDirY) /
			 (ray->rayDirX * ray->rayDirX));
  ray->deltaDistY = sqrt(1 + (ray->rayDirX * ray->rayDirX) /
			 (ray->rayDirY * ray->rayDirY));
  ray->hit = 0;
}

int	ini_ray(t_ray *ray, char **arg, t_bunny_color *color)
{
  ray->color = color;
  ray->is_slowmo = 0;
  ray->nstar = 200;
  ray->star = set_star(200);
  if (ray->star == NULL)
    return (1);
  ray->map_id = 0;
  ray->color_modif = 0;
  ray->key_tab = make_key_tab();
  ray->bullets = 5;
  if (ray->key_tab == NULL)
    return (1);
  if ((ray->map_id_name = build_list_map()) == NULL)
    return (1);
  if (make_minmap_grid(ray) == 1)
    return (1);
  if (main_parse_ini(ray, arg[1], "level") == 1)
    return (1);
  if (load_sound(ray) == 1)
    return (1);
  return (0);
}
/*
** load_ini.c for bay in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sun May  8 16:35:19 2016 Dimitri Wyzlic
** Last update Jan Jun 5 21:26:36 2016 Dimitri Wyzlic
*/

#include <lapin.h>
#include "header.h"

int	*parse_map_data_line(int *src, int width, int height)
{
  int	*out;
  int	i;

  i = 0;
  out = bunny_malloc(sizeof(int) * width);
  if (out == NULL)
    return (NULL);
  while (i < width)
    {
      out[i] = src[i + (height * width)];
      i = i + 1;
    }
  return (out);
}
int	**parse_map_data(int *src, int width, int height)
{
  int	**out;
  int	i;

  out = bunny_malloc(height * sizeof(int *));
  if (out == NULL || src == NULL || width == 0 || height == 0)
    return (NULL);
  i = 0;
  while (i < height)
    {
      out[i] = parse_map_data_line(src, width, i);
      if (out[i] == NULL)
	return (NULL);
      i = i + 1;
    }
  return (out);
}

int	main_parse_ini(t_ray *ray, char *name, char *name_cat)
{
  t_bunny_ini	*ini;

  if (name == NULL || name_cat == NULL)
    return (1);
  ini = bunny_load_ini(name);
  if (ini == NULL)
    return (1);
  ray->map_width = get_field_int(ini, name_cat, "width");
  ray->map_height = get_field_int(ini, name_cat, "height");
  ray->map_data = parse_map_data(get_field_int_s(
				     ini, name_cat, "data", ray->map_width
				     * ray->map_height) , ray->map_width,
				 ray->map_height);
  if (ray->map_data == NULL || get_start_pos(ray) == 1 ||
      ray->map_width < 10 || ray->map_height < 10)
    return (1);
  data_to_map(ray);
  return (0);
}
/*
** load_sound.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 07:16:55 2016 Dimitri Wyzlic
** Last update Sat Jun  4 13:53:55 2016 Dimitri Wyzlic
*/

#include "header.h"

int	load_sound(t_ray *ray)
{
  ray->disco = bunny_load_music("disco.ogg");
  if (ray->disco == NULL)
    return (1);
  ray->gun_sound = bunny_load_music("gun.ogg");
  if (ray->gun_sound == NULL)
    return (1);
  ray->reload = bunny_load_music("reload.ogg");
  if (ray->reload == NULL)
    return (1);
  bunny_sound_volume(&ray->gun_sound->sound, 30);
  bunny_sound_volume(&ray->reload->sound, 30);
  return (0);
}
/*
** main.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Tue May  3 19:34:05 2016 Dimitri Wyzlic
** Last update Sun Jun  5 22:24:39 2016 Dimitri Wyzlic
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
    return (1);
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
/*
** main_key.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 06:23:51 2016 Dimitri Wyzlic
** Last update Sat Jun  4 06:33:34 2016 Dimitri Wyzlic
*/

#include "header.h"

void	move_player(int key, t_ray *ray)
{
  if (key == 1)
    move_forward(&ray->st_pos, ray);
  if (key == 0)
    move_back(&ray->st_pos, ray);
}

void	rotate_player(int key, t_ray *ray)
{
  if (key == 1)
    rotate_right(&ray->st_pos, &ray->st_cam);
  if (key == 0)
    rotate_left(&ray->st_pos, &ray->st_cam);
}

void	strafe(int key, t_ray *ray)
{
  if (key == 1)
    strafe_left(&ray->st_pos, &ray->st_cam, ray);
  else
    strafe_right(&ray->st_pos, &ray->st_cam, ray);
}
/*
** minmap.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon May 30 11:26:10 2016 Dimitri Wyzlic
** Last update	Sat Jun 04 13:42:39 2016 Dimitri Wyzlic
*/

#include <lapin.h>
#include "header.h"

void	display_minmap(t_ray* ray)
{
  int		i;
  int		y;

  i = 0;
  while (i < 200)
    {
      y = 0;
      while (y < 200)
	{
	  if (ray->minmap[i][y] == 1)
	    my_tekpixel(i, y, ray->pix, WHITE);
	  if (ray->minmap[i][y] == 42)
	    my_tekpixel(i, y, ray->pix, RED);
	  if (ray->minmap[i][y] == 8)
	    my_tekpixel(i, y, ray->pix, GREEN);
	  if (ray->minmap[i][y] == 0)
	    my_tekpixel(i, y, ray->pix, BLUE);
	  y = y + 1;
	}
      i = i + 1;
    }
  return;
}

void	transfer_data_map(int nb, int x, int y, t_ray *ray)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < ray->minmap_jx && i < 200)
    {
      j = 0;
      while (j < ray->minmap_jy && j < 200)
	{
	  ray->minmap[i + (x * ray->minmap_jx)][j + (y * ray->minmap_jy)] = nb;
	  j = j + 1;
	}
      i = i + 1;
    }
}

void	data_to_map(t_ray *ray)
{
  int	x;
  int	y;

  if (ray->map_width > 200 || ray->map_height > 200 ||
      ray->map_width == 0 || ray->map_height == 0)
    return ;
  ray->minmap_jx = 200 / ray->map_height;
  ray->minmap_jy = 200 / ray->map_width;
  x = 0;
  while (x < ray->map_height)
    {
      y = 0;
      while (y < ray->map_width)
	{
	  if (ray->map_data[x][y] > 0 && ray->map_data[x][y] != 8)
	    transfer_data_map(1, x, y, ray);
	  if (ray->map_data[x][y] == 8)
	    transfer_data_map(8, x, y, ray);
	  if (ray->st_pos.posX == x && ray->st_pos.posY == y)
	    transfer_data_map(42, x, y, ray);
	  y = y + 1;
	}
      x = x + 1;
    }
}

char	*make_minmap_grid_line()
{
  char	*out;
  int	i;

  i = 0;
  out = bunny_malloc(sizeof(char) * 200);
  if (out == NULL)
    return (NULL);
  while (i < 200)
    {
      out[i] = 0;
      i = i + 1;
    }
  return (out);
}

int	make_minmap_grid(t_ray *ray)
{
  char	**out;
  int	i;

  out = bunny_malloc(sizeof(char *) * 200);
  if (out == NULL)
    return (1);
  i = 0;
  while (i < 200)
    {
      out[i] = make_minmap_grid_line();
      if (out[i] == NULL)
	return (1);
      i = i + 1;
    }
  ray->minmap = out;
  ray->minmap[0][0] = 3;
  return (0);
}
/*
** move_maths.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon May  2 13:46:22 2016 Dimitri Wyzlic
** Last update Sat Jun  4 20:17:24 2016 Dimitri Wyzlic
*/

#include <math.h>
#include "header.h"

void	move_forward(t_pos *pos, t_ray *ray)
{
  if (ray->map_data[ABS((((int)(pos->posX + pos->dirX * pos->moveSpeed))
		    + ray->map_height) % ray->map_height)]
      [ABS((((int)(pos->posY)) + ray->map_width) % ray->map_width)] == 0)
    pos->posX += pos->dirX * pos->moveSpeed;
  if (ray->map_data[ABS((((int)pos->posX) + ray->map_height) %
			ray->map_height)]
      [ABS((((int)(pos->posY + pos->dirY * pos->moveSpeed))
	    + ray->map_width) % ray->map_width)] == 0)
    pos->posY += pos->dirY * pos->moveSpeed;
}

void	move_back(t_pos *pos, t_ray *ray)
{
  if (ray->map_data[ABS((((int)(pos->posX - pos->dirX * pos->moveSpeed))
		    + ray->map_height) % ray->map_height)]
      [ABS((((int)(pos->posY)) + ray->map_width) % ray->map_width)] == 0)
    pos->posX -= pos->dirX * pos->moveSpeed;
  if (ray->map_data[ABS((((int)(pos->posX)) + ray->map_height)
			% ray->map_height)][ABS(
	    (((int)(pos->posY- pos->dirY* pos->moveSpeed)) + ray->map_width)
	    % ray->map_width)] == 0)
    pos->posY -= pos->dirY * pos->moveSpeed;
}

void		rotate_right(t_pos *pos, t_cam *cam)
{
  double	oldDirX;
  double	oldPlaneX;

  oldDirX = pos->dirX;
  oldPlaneX = cam->planeX;
  pos->dirX = pos->dirX * cos(-pos->rotSpeed) - pos->dirY * sin(-pos->rotSpeed);
  pos->dirY = oldDirX * sin(-pos->rotSpeed) + pos->dirY * cos(-pos->rotSpeed);
  cam->planeX = cam->planeX * cos(-pos->rotSpeed)
      - cam->planeY * sin(-pos->rotSpeed);
  cam->planeY = oldPlaneX * sin(-pos->rotSpeed)
      + cam->planeY * cos(-pos->rotSpeed);
}

void	rotate_left(t_pos *pos, t_cam *cam)
{
  double oldDirX;
  double oldPlaneX;

  oldDirX = pos->dirX;
  oldPlaneX = cam->planeX;
  pos->dirX = pos->dirX * cos(pos->rotSpeed) - pos->dirY * sin(pos->rotSpeed);
  pos->dirY = oldDirX * sin(pos->rotSpeed) + pos->dirY * cos(pos->rotSpeed);
  cam->planeX = cam->planeX * cos(pos->rotSpeed)
      - cam->planeY * sin(pos->rotSpeed);
  cam->planeY = oldPlaneX * sin(pos->rotSpeed)
      + cam->planeY * cos(pos->rotSpeed);
}
/*
** my_getnbr.c for fire in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sun May  8 17:01:40 2016 Dimitri Wyzlic
** Last update Jan Jun 5 21:22:16 2016 Dimitri Wyzlic
*/

#include "header.h"

static int	my_strlen(char const *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

int	my_getnbr(char const *str)
{
  int	nbr;
  int	i;
  int	pow;

  nbr = 0;
  pow = 1;
  if (str == NULL)
    {
      my_putstr("Error bad width or height\n");
      return (-1);
    }
  i = my_strlen(str) - 1;
  while (i >= 0)
    {
      nbr = nbr + pow * (str[i] - '0');
      pow = pow * 10;
      i = i - 1;
    }
  return (nbr);
}
/*
** my_line.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon May  2 12:36:34 2016 Dimitri Wyzlic
** Last update Sun Jun  5 22:07:18 2016 Dimitri Wyzlic
*/

#include <lapin.h>
#include "header.h"

void		my_tekpixel(int x, int y, t_bunny_pixelarray *pix,
			    unsigned int color)
{
  unsigned	*pixels;

  pixels = (unsigned *)pix->pixels;
  pixels[ABS((y + (x * S_WIDTH))) % (S_HEIGHT * S_WIDTH)] = color;
}

void	my_verline(int x, int a, int b, t_color *color,
		   t_bunny_pixelarray *pix)
{
  unsigned	*pixels;

  pixels = (unsigned *)pix->pixels;
  if (a > b)
    my_swap(&a, &b);
  if (a < 0 || b > S_HEIGHT)
    {
      a = 0;
      b = S_HEIGHT;
    }
  while (a < b)
    {
      pixels[ABS((x + (a * S_WIDTH)))] = color->full;
      a = a + 1;
    }
}

void	my_horline(int y, int a, int b, t_color *color,
		   t_bunny_pixelarray *pix)
{
  if (a > b)
    my_swap(&a, &b);
  while (a < b)
    {
      tekpixel_coord(pix, a, y, color);
      a = a + 1;
    }
}
/*
** my_putchar.c for lib in /home/wyzlic_a/blih/Piscine_C_LIB/c_files
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon Mar 14 12:03:59 2016 Dimitri Wyzlic
** Last update Sat May 28 11:09:25 2016 Dimitri Wyzlic
*/

#include <unistd.h>
#include "header.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
/*
** my_putstr.c for day04 in /home/wyzlic_a/rendu/j04
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Thu Mar  3 10:32:45 2016 Dimitri Wyzlic
** Last update Jan Jun 5 21:23:08 2016 Dimitri Wyzlic
*/

#include "header.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return 0;
  while (str[i] != '\0')
  {
    my_putchar(str[i]);
    i = i + 1;
  }
  return (0);
}
/*
** my_swap.c for day04 in /home/wyzlic_a/rendu/j04
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Thu Mar  3 10:22:39 2016 Dimitri Wyzlic
** Last update Sat Jun  4 08:56:14 2016 Dimitri Wyzlic
*/

#include <lapin.h>
#include "header.h"

void	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
}

void			swap_pos(t_bunny_position *a, t_bunny_position *b)
{
  t_bunny_position	temp;

  temp = *a;
  *a = *b;
  *b = temp;
}
/*
** put_block.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 07:40:20 2016 Dimitri Wyzlic
** Last update Sat Jun  4 20:23:50 2016 Dimitri Wyzlic
*/

#include "header.h"

void	get_pos_front(t_ray *ray, t_pos *pos)
{
  if (ray->map_data[ABS((((int)(pos->posX
			    + pos->dirX * pos->moveSpeed))
			 + ray->map_height) % ray->map_height)]
      [ABS((((int)(pos->posY)) + ray->map_width) % ray->map_width)] == 0)
    ray->posxfr = (int) (pos->dirX + pos->posX);
  if (ray->map_data[ABS((((int)pos->posX)
			 + ray->map_height) % ray->map_height)]
      [ABS((((int)(pos->posY + pos->dirY * pos->moveSpeed)) + ray->map_width)
	   % ray->map_width)] == 0)
    ray->posyfr = (int) (pos->dirY + pos->posY);
}

int		put_block(t_ray *ray)
{
  double	bcposx;
  double	bcposy;

  bcposx = ray->st_pos.posX;
  bcposy = ray->st_pos.posY;
  get_pos_front(ray, &ray->st_pos);
  if (((int)ray->st_pos.posX == ray->posxfr) &&
      ((int)ray->st_pos.posY == ray->posyfr))
    return (1);
  ray->map_data[ABS(ray->posxfr % ray->map_height)]
      [ABS(ray->posyfr % ray->map_width)] = 1;
  ray->st_pos.posX = bcposx;
  ray->st_pos.posY = bcposy;
  data_to_map(ray);
  return (0);
}
/*
** readme.c for readme in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 14:01:18 2016 Dimitri Wyzlic
** Last update Sat Jun  4 18:34:19 2016 Dimitri Wyzlic
*/

/*
**MAP :
** 42        = Start
** 0         = Void
** 1 / 3 / 4 = Wall
** 8         = Exit
** -----------------
** TOUCHES :
** ZQSD  = Move
** T     = Change map
** M     = Slowmo
** A/E   = Change FOV
** C     = Show cross
** B     = Discoooo
** Space = Fire
** Return = put block
*/
/*
** reset_minmap.c for map in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 03:42:04 2016 Dimitri Wyzlic
** Last update Sat Jun  4 03:46:00 2016 Dimitri Wyzlic
*/

#include "header.h"

void	reset_minmap(t_ray *ray)
{
  int	i;
  int	j;

  i = 0;
  while (i < 200)
    {
      j = 0;
      while (j < 200)
	{
	  ray->minmap[i][j] = 0;
	  j = j + 1;
	}
      i = i + 1;
    }
}
/*
** strafe.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat Jun  4 13:31:06 2016 Dimitri Wyzlic
** Last update Sat Jun  4 18:31:35 2016 Dimitri Wyzlic
*/

#include "header.h"

void	strafe_left(t_pos *pos, t_cam *cam, t_ray *ray)
{
  if (ray->map_data[(((int)(pos->posX + pos->dirX * pos->moveSpeed))
		    + ray->map_height) %
		   ray->map_height][(((int)(pos->posY))
				     + ray->map_width) % ray->map_width] == 0)
    cam->planeX += cam->planeX * pos->moveSpeed;
  if (ray->map_data[(((int)pos->posX) + ray->map_height)
		   % ray->map_height][(((int)(pos->posY
					      + pos->dirY * pos->moveSpeed))
				       + ray->map_width) % ray->map_width] == 0)
    cam->planeY += cam->planeY * pos->moveSpeed;
}

void	strafe_right(t_pos *pos, t_cam *cam, t_ray *ray)
{
  if (ray->map_data[(((int)(pos->posX + pos->dirX * pos->moveSpeed))
		    + ray->map_height) %
		   ray->map_height][(((int)(pos->posY)) + ray->map_width) %
				    ray->map_width] == 0)
    {
      cam->planeX -= cam->planeX * pos->moveSpeed;
    }
  if (ray->map_data[(((int)pos->posX) + ray->map_height) %
		   ray->map_height][(((int)(pos->posY
					    + pos->dirY* pos->moveSpeed))
				     + ray->map_width) % ray->map_width] == 0)
    {
      cam->planeY -= cam->planeY * pos->moveSpeed;
    }
}
/*
** utils_key.c for wolf in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Sat May 28 10:25:32 2016 Dimitri Wyzlic
** Last update Sat Jun  4 08:40:33 2016 Dimitri Wyzlic
*/

#include <lapin.h>
#include "header.h"

int	*reset_key(int *out)
{
  out[0] = 0;
  out[1] = 0;
  out[2] = 0;
  out[3] = 0;
  return (out);
}

void	exe_key(int *src, t_ray *ray)
{
  if (src[4] == 1)
    do_disco_key(ray, 1);
  if (src[4] == 0)
    do_disco_key(ray, 0);
  if (src[5] == 1)
    draw_cross(ray);

}

int	*make_key_tab()
{
  int	*out;

  out = bunny_malloc(sizeof(int) * 6);
  if (out == NULL)
    return (NULL);
  out[0] = 0;
  out[1] = 0;
  out[2] = 0;
  out[3] = 0;
  out[4] = 0;
  out[5] = 1;
  return (out);
}

void	main_key(const bool *keys, t_ray *ray)
{
  if (keys[BKS_A] || keys[BKS_E])
    strafe(((keys[BKS_A]) ? 1 : 0), ray);
  if (keys[BKS_Z] || keys[BKS_S])
    move_player(((keys[BKS_Z]) ? 1 : 0), ray);
  if (keys[BKS_Q] || keys[BKS_D])
    rotate_player(((keys[BKS_Q]) ? 1 : 0), ray);
  if (keys[BKS_M])
    main_slowmo(ray);

}
