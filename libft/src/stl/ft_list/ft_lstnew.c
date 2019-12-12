/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:42:42 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/12 14:05:48 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.h"
#include <stdlib.h>

/*
** Create a new linked list item
**
** @param 		content
** @param		content_size	size of content
** @return		list			pointer to the item
*/

t_list				*ft_lstnew(void *content, size_t content_size)
{
	t_list				*list;

	if ((list = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->content = content;
	if (list->content != NULL)
		list->content_size = content_size;
	else
		list->content_size = 0;
	list->next = NULL;
	return (list);
}
