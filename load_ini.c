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
