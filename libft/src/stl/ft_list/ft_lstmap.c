/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:56:42 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/12 14:08:25 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.h"

/*
** Applies function to each item in a list and 
** returns a pointer to a new linked list.
**
** @param 		lst			head of list
** @param		f			pointer to function
** @return		newlst		pointer to the new head
*/

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*newlst;

	while (lst != NULL)
	{
		if ((newlst = f(lst)) == NULL)
			return (NULL);
		ft_lstpushback(&newlst, f(lst));
		lst = lst->next;
	}
	return (newlst);
}
