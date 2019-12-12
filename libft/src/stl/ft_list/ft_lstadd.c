/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:29:25 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/12 14:06:00 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.h"
/*
** Adds an item to the top of the list.
**
** @param 		alst		head of list
** @param		new			new item
** @return		N/A
*/

void				ft_lstadd(t_list **alst, t_list *new)
{
	if (new == NULL)
		return ;
	new->next = *alst;
	*alst = new;
}
