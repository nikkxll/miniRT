/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:25:03 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/14 12:18:23 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "MLX42.h"

typedef double	t_num;

typedef struct s_rgb3
{
	int	r;
	int	g;
	int	b;
}	t_rgb3;

typedef struct s_vec3d
{
	t_num	x;
	t_num	y;
	t_num	z;
}	t_vec3d;

typedef struct s_obj
{
	int				type;
	t_vec3d			r;
	int				opt;
	mlx_texture_t	*txr;
}	t_obj;

typedef struct s_screen
{
	int	type;
	int	width;
	int	height;
	int	blur;
}	t_screen;

typedef struct s_am_light
{
	int					type;
	t_num				ratio;
	t_rgb3				rgb;
}	t_am_light;

typedef struct s_camera
{
	int				type;
	t_vec3d			r;
	t_vec3d			n;
	t_num			fov;
	struct s_camera	*next;
}	t_camera;

typedef struct s_light
{
	int				type;
	t_vec3d			r;
	t_num			brt;
	t_rgb3			rgb;
	struct s_light	*next;
}	t_light;

typedef struct s_sphere
{
	int				type;
	t_vec3d			r;
	int				opt;
	mlx_texture_t	*txr;
	t_rgb3			rgb;
	struct s_sphere	*next;
	t_num			d;
	t_rgb3			rgb_ch;
	int				quan_ch;
}	t_sphere;

typedef struct s_plane
{
	int					type;
	t_vec3d				r;
	int					opt;
	mlx_texture_t		*txr;
	t_vec3d				n;
	t_rgb3				rgb;
	struct s_plane		*next;
	t_rgb3				rgb_ch;
	t_num				size_ch;
}	t_plane;

typedef struct s_cylinder
{
	int					type;
	t_vec3d				r;
	int					opt;
	mlx_texture_t		*txr;
	t_vec3d				n;
	t_rgb3				rgb;
	struct s_cylinder	*next;
	t_num				d;
	t_num				h;
	t_rgb3				rgb_ch;
	int					quan_ch;
}	t_cylinder;

typedef struct s_cone
{
	int					type;
	t_vec3d				r;
	int					opt;
	mlx_texture_t		*txr;
	t_vec3d				n;
	t_rgb3				rgb;
	struct s_cone		*next;
	t_num				d;
	t_num				h;
	t_rgb3				rgb_ch;
	int					quan_ch;
}	t_cone;

typedef struct s_parse
{
	char		*line;
	int			fd;
	t_screen	*screen;
	t_am_light	*aml;
	t_camera	*camera;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
	t_cone		*cone;
}	t_parse;

typedef struct s_dist_cc
{
	t_num	k1;
	t_num	k2;
	t_num	vn;
	t_num	cn;
	t_num	cv;
	t_num	c2;
	t_vec3d	cprime;
}	t_dist_cc;

typedef struct s_hit_data
{
	t_vec3d		ray;
	t_num		dist;
	int			type;
	t_obj		*obj;
	t_rgb3		rgb;
	t_vec3d		color;
	t_vec3d		n;
	t_vec3d		v;
	t_vec3d		l;
	t_vec3d		ll;
	t_vec3d		r;
	t_vec3d		temp;
	t_vec3d		texture;
	t_dist_cc	precalc;
	t_num		obst;
}	t_hit_data;

typedef struct s_viewport
{
	int			fov;
	int			n_x;
	int			n_y;
	int			size;
	t_hit_data	*hit;
}	t_viewport;

typedef struct s_minirt
{
	t_parse		*prs;
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_viewport	vp;
}	t_minirt;

#endif
