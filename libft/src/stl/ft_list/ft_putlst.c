/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 09:53:17 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/12 14:07:12 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.h"
#include "ft_stdio.h"

/*
** Display linked list.
**
** @param 		alst	head of list
** @param 		print	function for printing content
** @return		N/A
*/

void				ft_putlst(t_list *alst, void (*print)(void *))
{
	size_t			i;

	i = 0;
	if (alst == NULL)
	{
		ft_printf("(empty list)\n");
		return ;
	}
	while (alst != NULL)
	{
		ft_printf("[%zu] content:\n[\n  ", i++);
		print(alst->content);
		ft_printf("\n]");
		ft_printf("\ncontent_size: %d\n\n", alst->content_size);
		alst = alst->next;
	}
}
