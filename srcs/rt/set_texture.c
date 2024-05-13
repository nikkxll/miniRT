#include "../../includes/minirt.h"

t_rgb3	texture_selector(t_hit_data *data, t_rgb3 c2)
{
	t_num	x;
	t_num	y;
	mlx_texture_t *txr;

	x = data->texture.x;
	y = data->texture.y;
	x = x - floor(x);
	y = y - floor(y);
	txr = data->obj->txr;
	if (data->obj->opt == 2 && txr)
	{
		printf("bump x=%lf, y=%lf\n", x, y);
		x *= (t_num)txr->width * 2; // / 2;
		y *= (t_num)txr->height * 2; // / 2;
		printf("bump x=%d, y=%d\n", (int)x, (int)y);
		return (get_bump_pixel(txr, (int)x, (int)y));
	}
		//return ((t_rgb3){0,0,0});

	if (data->obj->opt != 1)
		return (data->rgb);
	if ((x <= 0.5 && y <= 0.5) || (x > 0.5 && y > 0.5))
		return (data->rgb);
	return (c2);
}

void	set_texture_plane(t_hit_data *data)
{
	t_plane	*pl;
	t_vec3d	ab[2];
	t_vec3d	m;

	pl = (t_plane *)data->obj;
	m = vec_sub(data->v, pl->r);
	if (is_epsilon(pl->n.z))
	{
		ab[0] = cross((t_vec3d){0, 0, 1}, pl->n);
		ab[1] = (t_vec3d){0, 0, 1};
	}
	else
	{
		ab[0] = cross((t_vec3d){1, 0, 0}, pl->n);
		ab[1] = cross((t_vec3d){0, 1, 0}, pl->n);
	}
	data->texture = (t_vec3d){dot(ab[0], m), dot(ab[1], m), 0};
	if (data->obj->opt == 1)
		data->texture = vec_scale(1 / pl->size_ch, data->texture);
	data->rgb = texture_selector(data, pl->rgb_ch);
}

void	set_texture_sphere(t_hit_data *data)
{
	t_sphere	*sp;
	t_vec3d		m;

	sp = (t_sphere *)data->obj;
	m = vec_unit(vec_sub(data->v, sp->r));
	data->texture = (t_vec3d){acos(m.y) / M_PI,
		acos(m.x / sqrt(1 - m.y * m.y)) / M_PI, 0};
	//data->texture.x = sp->quan_ch * acos(m.y) / M_PI;
	//data->texture.y = sp->quan_ch * acos(m.x / sqrt(1 - m.y * m.y)) / M_PI;
	if (data->obj->opt == 1)
		data->texture = vec_scale(sp->quan_ch, data->texture);
	data->rgb = texture_selector(data, sp->rgb_ch);
}

//	data->texture.y = cy->quan_ch * (dot(rr, cy->n) + cy->h / 2) / cy->h;
//	if (!cy->n.x)
//		axis = cross(cy->n, (t_vec3d){1, 0, 0});
	//else if (!cy->n.y)
//	data->texture.x *= (t_num) 1 / 2 / M_PI;
void	set_texture_cyliner(t_hit_data *data)
{
	t_cylinder	*cy;
	t_vec3d		rr;
	t_vec3d		axis;

	cy = (t_cylinder *)data->obj;
	rr = vec_sub(data->v, cy->r);
	data->texture = (t_vec3d){0, (dot(rr, cy->n) + cy->h / 2) / cy->h, 0};
	if (cy->type == CYLINDER)
		rr = data->n;
	else if (cy->type == CONE)
		rr = vec_sub(rr, vec_scale(dot(rr, cy->n), cy->n));
	if (!cy->n.y)
		axis = cross(cy->n, (t_vec3d){0, 1, 0});
	else if (!cy->n.z)
		axis = cross(cy->n, (t_vec3d){0, 0, 1});
	else
		axis = vec_unit(cross(cy->n, (t_vec3d){1, 0, 0}));
	data->texture.x = acos(vec_cos(rr, axis)) / 2 / M_PI;
	if (dot(cross(rr, axis), cy->n) < 0)
		data->texture.x = 1 - data->texture.x;
	if (data->obj->opt == 1)
		data->texture = vec_scale(cy->quan_ch, data->texture);
	data->rgb = texture_selector(data, cy->rgb_ch);
}

void	set_checkerboard_texture(t_minirt *rt)
{
	int			i;
	t_hit_data	*data;

	i = -1;
	while (++i < rt->vp.size)
	{
		data = &(rt->vp.hit[i]);
		if (data->type == TYPE_OBJ_NONE || data->obj->opt == 0)
			continue ;
		if (data->type == PLANE)
			set_texture_plane(data);
		if (data->type == SPHERE)
			set_texture_sphere(data);
		if (data->type == CYLINDER || data->type == CONE)
			set_texture_cyliner(data);
	}
}
