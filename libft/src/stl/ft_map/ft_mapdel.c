/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:34:56 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/04 22:05:57 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.h"

/*
** Frees the hash table structure.
**
** @param 		map		pointer to structure
** @return		N/A
*/

void				ft_mapdel(t_map **map)
{
	size_t			i;

	i = 0;
	while (i < (*map)->size)
		ft_mapdelind(map, i++);
	free((*map)->array);
	(*map)->array = NULL;
	(*map)->size = 0;
	(*map)->numof_items = 0;
	(*map)->valuedel_func = NULL;
	free(*map);
	*map = NULL;
}
