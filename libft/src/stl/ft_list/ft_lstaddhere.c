/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddhere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:40:31 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/12 14:07:48 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.h"

/*
** Adds an item to the specified position.
**
** @param 		alst		head of list
** @param		new			new item
** @param		position	position to add
** @return		N/A
*/

void				ft_lstaddhere(t_list **alst, t_list *new, size_t position)
{
	while (*alst != NULL && position)
	{
		alst = &(*alst)->next;
		position--;
	}
	if (position == 0)
	{
		new->next = *alst;
		*alst = new;
	}
}