//
// Created by Johan Chevet on 3/5/21.
//

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include "stdio.h"
# include <math.h>
# include <time.h>
# define SPEED 5
# define ON 1
# define OFF 0

typedef struct s_ipoint
{
	int	x;
	int	y;
}t_ipoint;

typedef struct s_point
{
	float	x;
	float	y;
}t_point;

typedef struct s_sprite_plan
{
	t_point	rotate90;
	t_point	n;
	t_point	p;
	float	vcob;
	float	vco;
	float	vdb;
	float	vda;
}t_plan;
typedef struct s_frame {
	t_ipoint	pixel;
	int			wall_height;
	int			wall_start;
	int			wall_end;
	int			sprite_height;
	int			sprite_start;
	int			sprite_end;
	float		fisheye;
}				t_frame;

typedef struct s_ememy
{
	t_ipoint		pos;
	int				hp;
	struct s_ememy	*next;
}t_enemy;

typedef struct s_collision
{
	t_ipoint	o;
	t_ipoint	p;
	t_ipoint	add_o;
	t_ipoint	sub_o;
}t_collision;

typedef struct s_img
{
	void	*img;
	char	*adrr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}t_img;

typedef struct s_texture
{
	void	*img;
	int		*adrr;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}t_texture;

typedef struct s_img_tex
{
	t_texture	tex;
	t_img		img;
}				t_img_tex;

typedef struct s_inventory
{
	int	drinks;
	int	c4;
	int	slot1;
	int	slot2;
	int	slot3;
}t_inventory;

typedef struct s_hud
{
	time_t		drinking_time;
	t_img_tex	can;
	t_img_tex	drinking;
	t_img_tex	heart;
	t_img_tex	c4;
	t_img_tex	cmd;
	t_img_tex	holding_gun;
	t_img_tex	shooting_gun;
	t_img_tex	c4inv;
	t_img_tex	spriteinv;
	t_img		filter;
}t_hud;

typedef struct s_sprite_list
{
	t_point					s;
	t_point					pos;
	t_texture				tex;
	float					mid_dist;
	struct s_sprite_list	*next;
}t_sprite_list;

typedef struct s_ray
{
	float		x;
	float		y;
	t_point		step;
	t_point		side;
	t_point		delta;
	t_ipoint	map;
	t_ipoint	m;
	int			hit;
	int			dir;
	float		dist;
	float		yo;
	float		xo;
	float		a;
}t_ray;

typedef struct s_movement
{
	int		w;
	int		s;
	int		left;
	int		right;
	int		strafe_left;
	int		strafe_right;
	int		crouch;
	float	speed;
	int		soundplaying;
	int		mouse;
	time_t	foot_time;
}t_movement;

typedef struct s_player
{
	float		x;
	float		y;
	t_ipoint	m;
	int			action;
	int			action2;
	int			keypress;
	int			drinking;
	int			plant;
	int			hp;
	char		direction;
	float		xdir;
	float		ydir;
	float		a;
	int			shooting;
	t_inventory	inv;
}t_player;

typedef struct s_map
{
	char		*path;
	char		**map;
	char		**mapcpy;
	int			x_max;
	int			y_max;
	t_ipoint	bombpos;
}t_map;

typedef struct s_settings
{
	int	f_color;
	int	c_color;
	int	res_height;
	int	res_width;
	int	mapstart;
	int	nb_enemy;
	int	sound;
	int	r;
	int	f;
	int	c;
	int	s;
	int	no;
	int	so;
	int	ea;
	int	we;
	int	s3;
	int	s4;
	int	s5;
}t_settings;

typedef struct s_sprite
{
	t_texture		tex2;
	t_texture		tex3;
	t_texture		tex4;
	t_texture		tex5;
	t_sprite_list	*list;
	float			impact_dist;
	float			dist;
	int				yes;
}t_sprite;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_frame		frame;
	t_texture	tex_to_put;
	t_texture	tex_s;
	t_texture	tex_n;
	t_texture	tex_e;
	t_texture	tex_w;
	t_texture	destructible_wall;
	t_texture	wallc4;
	t_texture	door;
	t_player	player;
	t_enemy		*enemy_list;
	t_map		map;
	t_settings	settings;
	t_ray		ray;
	t_movement	move;
	t_sprite	sprite;
	t_hud		hud;
	int			shot;
	int			up;
}t_mlx;

//free
void			map_not_valid(t_mlx *mlx, int y);
void			checkmap_error(t_map *map, t_mlx *mlx);
void			exit_error(t_mlx *mlx, int err);
void			second_rd_error(t_mlx *mlx, char **line, int y);
int				exit_sucess(t_mlx *mlx);
void			free_tex(t_mlx *mlx);
void			destroy_img_img(t_mlx *mlx);
void			destroy_tex_img(t_mlx *mlx);
void			print_err(int err);
void			free_map(t_mlx *mlx);

//init
void			init_all(t_mlx *mlx);
void			init_img_img(t_mlx *mlx);
void			init_tex_img(t_mlx *mlx);

int				get_settings(char *s, int start, t_mlx *mlx);
void			set_mlx(t_mlx *mlx);
void			set_player_dir(t_mlx *mlx);
void			first_rd_file(t_mlx *mlx);
void			second_rd_file2(t_mlx *mlx);
void			player_direction(char *str, t_mlx *mlx, int x, int y);
void			playermove(t_mlx *mlx);
void			init_mlx(t_mlx *mlx);

// display
void			put_gun(t_mlx *mlx);
void			put_shooting_gun(t_mlx *mlx);

//utils
int				skip_space(char *s);
int				intlen(int nb);
float			dist(float px, float py, float rx, float ry);
int				get_color_index(int x, int y, t_texture *tex);
int				create_trgb(int t, int r, int g, int b);
void			put_pixel(t_mlx *mlx, t_img img, t_ipoint p, int color);
void			fix_angle(float *a);
int				get_texture(t_mlx *mlx, t_texture *tex, char *s);
int				get_wall_color(t_mlx *mlx, t_texture *tex);
t_ipoint		p(int x, int y);
void			play_sound(t_mlx *mlx, char *cmd);

//Keyevents
int				key_press(int keycode, t_mlx *mlx);
int				key_release(int keycode, t_mlx *mlx);
void			action_keys(int keycode, t_mlx *mlx);
void			hud_keys(int keycode, t_mlx *mlx);
int				button(int but, int x, int y, t_mlx *mlx);

//hud
void			draw_hud(t_mlx *mlx, t_img_tex *data, int ratio);
void			put_hud(t_mlx *mlx);
void			draw_hud_images(t_mlx *mlx);
void			put_heart(t_mlx *mlx);
void			put_c4(t_mlx *mlx);
void			put_sprite(t_mlx *mlx);

//set
void			set_everything(t_mlx *mlx);

//list
t_enemy			*new_enemy(int x, int y);
t_enemy			*which_enemy(t_mlx *mlx, int x, int y);
int				add_front_enemy(t_enemy **lst, int i, int j);
void			free_enemy_list(t_mlx *mlx);
t_sprite_list	*new_elem(void);
void			add_front(t_sprite_list **lst, t_sprite_list *new);
void			free_sprite_list(t_mlx *mlx);

//action
void			action(t_mlx *mlx);
void			footstep(t_mlx *mlx);
void			plant_bomb(t_mlx *mlx);
void			trigger_bomb(t_mlx *mlx);
void			player_shooting(t_mlx *mlx);
void			pickup_sprite(t_mlx *mlx);
void			step_on_lego(t_mlx *mlx);

//raycast
void			ray_cast(t_mlx *mlx);
void			sprite_hit(t_mlx *mlx);
void			sprite_plan(t_mlx *mlx);
void			texture_to_put(t_mlx *mlx);
void			reset_ray(t_mlx *mlx);

//draw
void			draw_frame(t_mlx *mlx);
void			draw_sprite(t_mlx *mlx);
void			ft_shading(t_mlx *mlx, int x, int y, int color);
void			texture_to_put(t_mlx *mlx);
void			draw_bomb(t_mlx *mlx);
void			draw_minimap(t_mlx *mlx);

//mouvement
void			strafe_right(t_mlx *mlx, t_collision *c);
void			strafe_left(t_mlx *mlx, t_collision *c);
void			collision_offset(t_mlx *mlx, t_collision *c);
void			mousemove(t_mlx *mlx);

//parsing
void			parsing(t_mlx *mlx);
int				get_settings(char *s, int start, t_mlx *mlx);
int				check_settings(t_mlx *mlx);
int				check_res(t_mlx *mlx);
void			args(t_mlx *mlx, char *map);

int				create_bitmap(t_mlx *mlx);

#endif