/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:06:25 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/12 14:19:08 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.h"
#include <stdlib.h>

/*
** Initialization of the hashtable structure.
**
** @param 		mapsize			initial size
** @param		valudel_func	pointer to delete function hash table value
** @return		map				pointer to hash table structure
*/

t_map				*ft_mapinit(size_t mapsize, void *hash_func, \
						void *valuedel_func)
{
	t_map			*map;
	size_t			i;

	if ((map = (t_map *)malloc(sizeof(t_map))) == NULL)
		return (NULL);
	map->size = mapsize;
	map->numof_items = 0;
	map->hashfunc = hash_func;
	if (hash_func == NULL)
		map->hashfunc = &hashfunction;
	map->valuedel_func = valuedel_func;
	if ((map->array = (t_list **)malloc(sizeof(t_list *) * (mapsize + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i <= mapsize)
		map->array[i++] = NULL;
	return (map);
}
