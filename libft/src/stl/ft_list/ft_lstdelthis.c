/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelthis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:04:21 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/12 14:07:30 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.h"

/*
** Deletes a list item by its number
**
** @param 		lstnum			list number to delete
** @param		del
** @return		N/A
*/

void				ft_lstdelthis(t_list **alst, size_t lstnum, \
											void (*del)(void *, size_t))
{
	while (*alst != NULL && lstnum)
	{
		alst = &(*alst)->next;
		lstnum--;
	}
	if (lstnum == 0 && *alst != NULL)
		ft_lstdelhead(alst, del);
}
