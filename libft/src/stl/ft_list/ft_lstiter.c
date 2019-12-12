/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:57:23 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/12 13:43:33 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.h"

/*
** Applies function to each item in a list and 
**
** @param 		lst			head of list
** @param		f			pointer to function
** @return		N/A
*/

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	while (lst != NULL)
	{
		f(lst);
		lst = lst->next;
	}
}
