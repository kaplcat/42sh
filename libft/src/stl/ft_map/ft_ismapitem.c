/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ismapitem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:41:43 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/12 13:45:16 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.h"

/*
** Checks for a key in a hash table
**
** @param 		key
** @return		1/0
*/

int					ft_ismapitem(t_map *map, const char *key)
{
	if (ft_mapvalue(map, key) == NULL)
		return (0);
	return (1);
}
