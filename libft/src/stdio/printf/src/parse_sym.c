/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sym.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreiten <dbreiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 04:19:12 by dbreiten          #+#    #+#             */
/*   Updated: 2019/10/09 11:30:07 by dbreiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static ssize_t	write_with_margin(
t_buff *buff,
t_handle *hndl,
void *data,
size_t len_data)
{
	ssize_t tmp;
	ssize_t	ret;

	ret = 0;
	if (hndl->flags ^ NEG)
	{
		if ((tmp = write_buff(buff, " ", 1, hndl->width - (int)len_data)) == -1)
			return (-1);
		ret += tmp;
		if ((tmp = write_buff(buff, (void*)data, len_data, 1)) == -1)
			return (-1);
		ret += tmp;
	}
	else
	{
		if ((tmp = write_buff(buff, (void*)data, len_data, 1)) == -1)
			return (-1);
		ret += tmp;
		if ((tmp = write_buff(buff, " ", 1, hndl->width - (int)len_data)) == -1)
			return (-1);
		ret += tmp;
	}
	return (ret);
}

ssize_t			parse_hndl_str(t_buff *buff, t_handle *hndl, const char *str)
{
	const char	*data;
	size_t		len_data;
	ssize_t		tmp;
	ssize_t		ret;

	ret = 0;
	data = str;
	if (data == NULL)
		data = "<null>";
	len_data = ft_strlen(data);
	if (hndl->per != -1 && hndl->per < (int)len_data)
		len_data = hndl->per;
	if (hndl->width > (int)len_data)
	{
		if ((tmp = write_with_margin(buff, hndl, (void*)data, len_data)) == -1)
			return (-1);
		ret += tmp;
	}
	else
	{
		if ((tmp = write_buff(buff, (void*)data, len_data, 1)) == -1)
			return (-1);
		ret += tmp;
	}
	return (ret);
}

ssize_t			parse_hndl_sym(t_buff *buff, t_handle *hndl, char c)
{
	ssize_t tmp;
	ssize_t ret;

	ret = 0;
	if (hndl->width > 1)
	{
		if ((tmp = write_with_margin(buff, hndl, &c, 1)) == -1)
			return (-1);
		ret += tmp;
	}
	else
	{
		if ((tmp = write_buff(buff, &c, 1, 1)) == -1)
			return (-1);
		ret += tmp;
	}
	return (ret);
}
