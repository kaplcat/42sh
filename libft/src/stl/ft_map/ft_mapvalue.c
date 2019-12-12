/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:30:09 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/12 14:23:16 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.h"
#include "ft_string.h"

/*
** Returns the value of the hash table by key.
** Returns NULL if the key does not exist.
**
** @param 		key
** @return		pointer to hashtable value
*/

const void			*ft_mapvalue(t_map *map, const char *key)
{
	t_list			*maplst;
	int				(*hashfunc)(const char *, int );

	hashfunc = map->hashfunc;
	maplst = map->array[hashfunc(key, map->size)];
	while (maplst != NULL)
	{
		if (ft_strequ(((t_htab *)(maplst->content))->key, key))
			return ((const void *)((t_htab *)(maplst->content))->value);
		maplst = maplst->next;
	}
	return (NULL);
}
