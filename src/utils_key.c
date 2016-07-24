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
