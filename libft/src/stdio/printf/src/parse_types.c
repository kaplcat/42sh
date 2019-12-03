/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreiten <dbreiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 04:21:10 by dbreiten          #+#    #+#             */
/*   Updated: 2019/10/09 11:18:25 by dbreiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static const char *g_types = "douxXsc%";

static ssize_t	parse_hndl_type_d(t_buff *buff, t_handle *hndl, va_list list)
{
	if (hndl->size == LLPRE)
		return (parse_hndl_nb(buff, hndl, va_arg(list, long long)));
	if (hndl->size == LPRE)
		return (parse_hndl_nb(buff, hndl, va_arg(list, long)));
	if (hndl->size == HHPRE)
		return (parse_hndl_nb(buff, hndl, (char)va_arg(list, int)));
	if (hndl->size == HPRE)
		return (parse_hndl_nb(buff, hndl, (short)va_arg(list, int)));
	if (hndl->size == JPRE)
		return (parse_hndl_nb(buff, hndl, va_arg(list, intmax_t)));
	return (parse_hndl_nb(buff, hndl, va_arg(list, int)));
}

static ssize_t	parse_hndl_type_u(t_buff *buff, t_handle *hndl, va_list list)
{
	if (hndl->size == LLPRE)
		return (parse_hndl_unb(buff, hndl, va_arg(list, unsigned long long)));
	if (hndl->size == LPRE)
		return (parse_hndl_unb(buff, hndl, va_arg(list, unsigned long)));
	if (hndl->size == HHPRE)
		return (parse_hndl_unb(buff, hndl, (unsigned char)va_arg(list, int)));
	if (hndl->size == HPRE)
		return (parse_hndl_unb(buff, hndl, (unsigned short)va_arg(list, int)));
	if (hndl->size == JPRE)
		return (parse_hndl_unb(buff, hndl, va_arg(list, uintmax_t)));
	if (hndl->size == ZPRE)
		return (parse_hndl_unb(buff, hndl, va_arg(list, size_t)));
	return (parse_hndl_unb(buff, hndl, va_arg(list, unsigned int)));
}

static ssize_t	parse_unsigned_types(
t_buff *buff,
t_handle *hndl,
va_list list,
char t)
{
	if (t == 'o')
		hndl->base = OCTAL;
	else if (t == 'x')
		hndl->base = HEXL;
	else if (t == 'X')
		hndl->base = HEXU;
	else
		hndl->base = DEC;
	return (parse_hndl_type_u(buff, hndl, list));
}

ssize_t			parse_hndl_type(
t_buff *buff,
t_handle *hndl,
char **format,
va_list list)
{
	int	ret;

	ret = 0;
	while (**format && !ft_strchr(g_types, **format))
		(*format)++;
	if (ft_strchr("ouxX", **format))
		ret = (parse_unsigned_types(buff, hndl, list, **format));
	if (**format == 'd')
		ret = parse_hndl_type_d(buff, hndl, list);
	if (**format == 's')
		ret = parse_hndl_str(buff, hndl, va_arg(list, const char *));
	if (**format == 'c')
		ret = parse_hndl_sym(buff, hndl, (char)va_arg(list, int));
	if (**format == '%')
		ret = parse_hndl_sym(buff, hndl, '%');
	(*format)++;
	return (ret);
}
