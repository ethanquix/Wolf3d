/*
** header.h for wolf3d in /home/wyzlic_a
**
** Made by Dimitri Wyzlic
** Login   <wyzlic_a@epitech.net>
**
** Started on  Mon May  2 11:25:07 2016 Dimitri Wyzlic
** Last update Sat Jun  4 20:08:03 2016 Dimitri Wyzlic
*/

#include <lapin.h>

#ifndef HEADER_H_
# define HEADER_H_

# define S_WIDTH 1920
# define S_HEIGHT 1080
# define ABS(X) (((X) < 0) ? -(X) : (X))

typedef struct	s_bunny_star
{
  int		y;
  float		x;
  float		x_speed;
}		t_bunny_star;

typedef struct	s_pos
{
  double	posX;
  double	posY;
  double	dirX;
  double	dirY;
  int		**worldMap;
  double	moveSpeed;
  double	rotSpeed;
  double	time;
  double	oldTime;
}		t_pos;

typedef struct	s_cam
{
  double	cameraX;
  double	cameraY;
  double	planeX;
  double	planeY;
}		t_cam;

typedef struct		s_ray
{
  t_pos			st_pos;
  t_cam			st_cam;
  double		rayPosX;
  double		rayPosY;
  double		rayDirX;
  double		rayDirY;
  int			mapX;
  int			mapY;
  double		deltaDistX;
  double		deltaDistY;
  double		perpWallDist;
  double		sideDistX;
  double		sideDistY;
  int			stepX;
  int			stepY;
  int			hit;
  int			side;
  int			lineHeight;
  int			drawStart;
  int			drawEnd;
  t_bunny_pixelarray	*pix;
  t_bunny_window	*window;
  t_color		*color;
  t_bunny_star		*star;
  int			**map_data;
  int			map_width;
  int			map_height;
  char			*map_name;
  int			map_start_pos_x;
  int			map_start_pos_y;
  double		map_start_angle;
  size_t		nstar;
  int			map_id;
  char			**map_id_name;
  int			*key_tab;
  char			**minmap;
  char			is_slowmo;
  double		color_modif;
  t_bunny_music		*disco;
  t_bunny_music		*gun_sound;
  t_bunny_music		*reload;
  int			minmap_jx;
  int			minmap_jy;
  int			posxfr;
  int			posyfr;
  int			bullets;
}			t_ray;

void		tekline_pos(t_bunny_pixelarray *, t_bunny_position,
			    t_bunny_position, t_color *);
void		tekline(t_bunny_pixelarray *, t_bunny_position *, t_color *);
void		tekpixel(t_bunny_pixelarray *, t_bunny_position *, t_color *);
double		vecnorm(t_bunny_position *, t_bunny_position *);
void		swap_pos(t_bunny_position *, t_bunny_position *);
void		my_verline(int, int, int, t_color *, t_bunny_pixelarray *);
void		my_horline(int, int, int, t_color *, t_bunny_pixelarray *);
void		my_swap(int *, int *);
void		tekpixel_coord(t_bunny_pixelarray *, int, int, t_color *);
int		ini_set(t_pos *, t_cam *);
void		init_stru(t_pos *, t_cam *, t_ray *, int);
void		calcul_step(t_ray *);
void		do_dda(t_ray *);
void		do_dda_next(t_ray *);
void		set_color(t_color *, t_ray *);
void		move_forward(t_pos *, t_ray *);
void		move_back(t_pos *, t_ray *);
void		rotate_right(t_pos *, t_cam *);
void		rotate_left(t_pos *, t_cam *);
void		starfield(t_bunny_pixelarray *, t_bunny_star *, size_t);
t_bunny_star	*set_star(int);
int		*get_field_int_s(t_bunny_ini *, char *, char *, int);
char		*get_field_char(t_bunny_ini *, char *, char *);
int		get_field_int(t_bunny_ini *, char *, char *);
int		my_getnbr(char const *);
char		*fuck_const(char const *);
int		main_parse_ini(t_ray *, char *, char *);
char		**build_list_map();
int		change_map(t_ray *);
int		*make_key_tab();
void		exe_key(int *, t_ray *);
int		*reset_key(int *);
int		my_putstr(char *);
void		my_putchar(char);
void		display_minmap(t_ray *);
int		make_minmap_grid(t_ray *);
void		data_to_map(t_ray *);
void		my_tekpixel(int, int, t_bunny_pixelarray *, unsigned int);
int		get_start_pos(t_ray *);
void		reset_minmap(t_ray *);
void		main_slowmo(t_ray *);
void		strafe_left(t_pos *, t_cam *, t_ray *);
void		strafe_right(t_pos *, t_cam *, t_ray *);
void		draw_cross(t_ray *);
void		do_disco(t_ray *);
void		do_disco_key(t_ray *, int);
void		move_player(int, t_ray *);
void		rotate_player(int, t_ray *);
void		strafe(int, t_ray *);
void		disp_cur_pos(t_ray *);
void		set_blank(t_bunny_pixelarray *, t_ray *);
int		load_sound(t_ray *);
int		put_block(t_ray *);
int		ini_ray(t_ray *, char **, t_bunny_color *);
void		main_key(const bool *, t_ray *);

#endif /* !HEADER_H_ */
