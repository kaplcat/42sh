/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreiten <dbreiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 00:02:30 by dbreiten          #+#    #+#             */
/*   Updated: 2019/10/09 11:28:19 by dbreiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>
#include <ft_string.h>
#include <unistd.h>

#define MINCHNK 4096

t_buff	*create_buff(int fd, size_t size)
{
	t_buff	*new;

	new = malloc(sizeof(t_buff));
	if (new == NULL)
		return (NULL);
	new->data = malloc(size);
	if (new->data == NULL)
	{
		free(new);
		return (NULL);
	}
	new->fd = fd;
	new->all_size = size;
	new->curr_size = 0;
	return (new);
}

void	delete_buff(t_buff *buff)
{
	free(buff->data);
	free(buff);
}

void	*ft_realloc(void *src, size_t curr_size, size_t new_size)
{
	void	*new;

	new = malloc(new_size);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, src, curr_size);
	free(src);
	return (new);
}

ssize_t	write_buff(t_buff *buff, void *data, size_t size, size_t num)
{
	size_t	i;

	while (buff->all_size - buff->curr_size < size * num)
	{
		buff->data = ft_realloc(buff->data,
								buff->curr_size,
								buff->all_size + MINCHNK);
		if (buff->data == NULL)
			return (-1);
		buff->all_size += MINCHNK;
	}
	i = 0;
	while (i < num)
	{
		ft_memcpy(buff->data + buff->curr_size, data, size);
		buff->curr_size += size;
		i++;
	}
	return (size * num);
}

ssize_t	clean_buff(t_buff *buff)
{
	size_t	ret;

	ret = write(buff->fd, buff->data, buff->curr_size);
	buff->curr_size = 0;
	return (ret);
}
