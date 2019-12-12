/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:42:42 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/12 14:05:29 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.h"

/*
** Deletes a list item
**
** @param		alst	head of list
** @param		del
** @return		N/A
*/

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst == NULL)
		return ;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
