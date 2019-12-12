/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 21:38:19 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/12 14:05:08 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.h"

/*
** Deletes all the list
**
** @param 		lstnum			list number to delete
** @param		del
** @return		N/A
*/

void					ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while (*alst != NULL)
		ft_lstdelhead(alst, del);
}
