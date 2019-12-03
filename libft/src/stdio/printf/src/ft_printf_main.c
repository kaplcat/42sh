/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreiten <dbreiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 23:54:01 by dbreiten          #+#    #+#             */
/*   Updated: 2019/11/19 19:33:52 by dbreiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <ft_printf.h>

int			ft_printf(const char *format, ...)
{
	va_list	list;
	int		res;

	va_start(list, format);
	res = parse_format(STDOUT_FILENO, format, list);
	va_end(list);
	return (res);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list	list;
	int		res;

	va_start(list, format);
	res = parse_format(fd, format, list);
	va_end(list);
	return (res);
}

char		*ft_sprintf(const char *format, ...)
{
	va_list	list;
	t_buff	*buff;
	char	*ret;

	va_start(list, format);
	buff = parse_format_s(-1, format, list);
	if (buff == NULL)
		return (NULL);
	ret = malloc(buff->curr_size + 1);
	if (ret == NULL)
	{
		delete_buff(buff);
		return (NULL);
	}
	ft_memcpy(ret, buff->data, buff->curr_size);
	ret[buff->curr_size] = 0;
	delete_buff(buff);
	return (ret);
}
