/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hndl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreiten <dbreiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 04:13:46 by dbreiten          #+#    #+#             */
/*   Updated: 2019/10/09 11:17:03 by dbreiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <ft_ctype.h>
#include <ft_stdlib.h>

static const char *g_flags = "-+ #0";

int	parse_flags(char **format)
{
	int	ret_flag;

	ret_flag = 0;
	while (ft_strchr(g_flags, **format))
	{
		if (**format == '-')
			ret_flag |= NEG;
		else if (**format == '+')
			ret_flag |= POS;
		else if (**format == ' ')
			ret_flag |= SPACE;
		else if (**format == '#')
			ret_flag |= OCT;
		else if (**format == '0')
			ret_flag |= ZERO;
		(*format)++;
	}
	return (ret_flag);
}

int	parse_width(char **format, va_list list)
{
	int	ret_width;

	ret_width = -1;
	while (**format == ' ')
		(*format)++;
	if (ft_isdigit(**format))
	{
		ret_width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '*')
	{
		ret_width = va_arg(list, int);
		(*format)++;
	}
	return (ret_width);
}

int	parse_per(char **format, va_list list)
{
	int	ret_per;

	ret_per = -1;
	while (**format == ' ')
		(*format)++;
	if (**format == '.')
	{
		(*format)++;
		if (ft_isdigit(**format))
		{
			ret_per = ft_atoi(*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
		else if (**format == '*')
		{
			ret_per = va_arg(list, int);
			(*format)++;
		}
		else
			ret_per = 0;
	}
	return (ret_per);
}

int	parse_size(char **format)
{
	int	ret_size;

	ret_size = 0;
	if (!ft_strncmp(*format, "ll", 2))
		ret_size = LLPRE;
	else if (!ft_strncmp(*format, "l", 1))
		ret_size = LPRE;
	else if (!ft_strncmp(*format, "hh", 2))
		ret_size = HHPRE;
	else if (!ft_strncmp(*format, "h", 1))
		ret_size = HPRE;
	else if (!ft_strncmp(*format, "j", 1))
		ret_size = JPRE;
	else if (!ft_strncmp(*format, "z", 1))
		ret_size = ZPRE;
	else
		ret_size = BASE;
	return (ret_size);
}
