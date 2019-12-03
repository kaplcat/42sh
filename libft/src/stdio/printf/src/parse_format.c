/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreiten <dbreiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:50:14 by dbreiten          #+#    #+#             */
/*   Updated: 2019/10/09 11:31:19 by dbreiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int		buff_error(t_buff *buff)
{
	clean_buff(buff);
	delete_buff(buff);
	return (-1);
}

static t_buff	*buff_error_s(t_buff *buff)
{
	delete_buff(buff);
	return (NULL);
}

static int		parse_one_data(t_buff *buff, char **format, va_list list)
{
	t_handle ht;

	(*format)++;
	ht.flags = parse_flags(format);
	ht.width = parse_width(format, list);
	ht.per = parse_per(format, list);
	ht.size = parse_size(format);
	return (parse_hndl_type(buff, &ht, format, list));
}

int				parse_format(int fd, const char *format, va_list list)
{
	t_buff	*fd_buf;
	ssize_t	ret;

	fd_buf = create_buff(fd, 4096);
	if (fd_buf == NULL)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			if (parse_one_data(fd_buf, (char **)&format, list) == -1)
				return (buff_error(fd_buf));
		}
		else
		{
			if (write_buff(fd_buf, (void*)format, 1, 1) == -1)
				return (buff_error(fd_buf));
			format++;
		}
	}
	ret = clean_buff(fd_buf);
	delete_buff(fd_buf);
	return (ret);
}

t_buff			*parse_format_s(int fd, const char *format, va_list list)
{
	t_buff	*fd_buf;

	fd_buf = create_buff(fd, 4096);
	if (fd_buf == NULL)
		return (NULL);
	while (*format)
	{
		if (*format == '%')
		{
			if (parse_one_data(fd_buf, (char **)&format, list) == -1)
				return (buff_error_s(fd_buf));
		}
		else
		{
			if (write_buff(fd_buf, (void*)format, 1, 1) == -1)
				return (buff_error_s(fd_buf));
			format++;
		}
	}
	return (fd_buf);
}
