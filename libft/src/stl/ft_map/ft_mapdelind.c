/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdelind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:36:17 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/12 14:23:42 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.h"
#include "ft_string.h"

static void			dellst(void *content, size_t content_size)
{
	ft_strdel(&(((t_htab *)content)->key));
	content_size = 0;
	free(content);
	content = NULL;
}

/*
** Delete a hash table value by index 
**
** @param		index
** @return		N/A
*/

void				ft_mapdelind(t_map **map, size_t index)
{
	void			(*valuedel)(void **);
	t_list			**maplst;
	t_list			*tmp;

	if (index > (*map)->size)
		return ;
	if ((*map)->array[index] == NULL)
		return ;
	maplst = &((*map)->array[index]);
	valuedel = (*map)->valuedel_func;
	while (*maplst != NULL)
	{
		valuedel(&(((t_htab *)((*maplst)->content))->value));
		tmp = (*maplst)->next;
		ft_lstdelone(maplst, dellst);
		*maplst = tmp;
		(*map)->numof_items--;
	}
	(*map)->array[index] = NULL;
}
