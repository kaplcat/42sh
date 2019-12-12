/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapdelkey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:20:57 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/12 14:24:07 by yquaro           ###   ########.fr       */
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
** Delete a hash table value by key 
**
** @param		key
** @return		N/A
*/

void				ft_mapdelkey(t_map **map, const char *key)
{
	int				(*hashfunc)(const char *, int );
	void			(*valuedel)(void **);
	t_list			**maplst;
	t_list			*tmp;

	hashfunc = (*map)->hashfunc;
	maplst = &((*map)->array[hashfunc(key, (*map)->size)]);
	valuedel = (*map)->valuedel_func;
	while (*maplst != NULL)
	{
		if (ft_strequ(((t_htab *)((*maplst)->content))->key, key))
		{
			valuedel(&(((t_htab *)((*maplst)->content))->value));
			tmp = (*maplst)->next;
			ft_lstdelone(maplst, dellst);
			*maplst = tmp;
			(*map)->numof_items--;
			return ;
		}
		maplst = &(*maplst)->next;
	}
}
