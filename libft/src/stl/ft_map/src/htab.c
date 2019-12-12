/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:34:12 by yquaro            #+#    #+#             */
/*   Updated: 2019/12/12 14:18:54 by yquaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stl.h"
#include <stdlib.h>
#include "ft_string.h"

t_htab				*init_htab(const char *key, void *value)
{
	t_htab			*htab;

	if ((htab = (t_htab *)malloc(sizeof(t_htab))) == NULL)
		return (NULL);
	if ((htab->key = ft_strdup(key)) == NULL)
	{
		free(htab);
		return (NULL);
	}
	htab->value = value;
	return (htab);
}
