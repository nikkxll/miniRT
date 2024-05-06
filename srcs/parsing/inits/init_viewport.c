/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_viewport.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnikifor <dnikifor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:49:17 by dnikifor          #+#    #+#             */
/*   Updated: 2024/05/05 12:12:17 by dnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minirt.h"

static t_viewport	*new_viewport_node(char *entities[ARGS_MAX], t_minirt *rt)
{
	t_viewport	*node;

    node = (t_viewport *)ft_calloc(1, sizeof(t_viewport));
    if (node)
    {
        node->type = VIEWPORT;
        node->width = protected_atoi(entities[1], rt);
        if (node->width < 1 || node->width > VP_SIZE_MAX)
            node->width = VP_WIDTH_DEFAULT;
        node->height = protected_atoi(entities[2], rt);
        if (node->height < 1 || node->height > VP_SIZE_MAX)
            node->height = VP_HEIGHT_DEFAULT;
        return (node);
    }
	else
		generic_errors_handler(MALLOC_ERR_MSG, MALLOC_ERR, rt);
	return (NULL);
}

void	init_r(char *entities[ARGS_MAX], t_minirt *rt)
{
	if (!rt->prs->viewport && ft_arrlen((void **)entities) == VP_PARAMS)
	{
		rt->prs->viewport = new_viewport_node(entities, rt);
	}
	else
		generic_errors_handler(CONF_FORMAT_ERR_MSG, CONF_ERR, rt);
}