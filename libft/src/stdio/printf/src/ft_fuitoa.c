/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fuitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreiten <dbreiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 02:14:09 by dbreiten          #+#    #+#             */
/*   Updated: 2019/10/09 11:15:23 by dbreiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <inttypes.h>
#include <ft_string.h>
#include <ft_printf.h>

#define OCTAL  0
#define HEXL   1
#define HEXU   2
#define DEC    3

static const char *g_base[] = {
	"01234567",
	"0123456789abcdef",
	"0123456789ABCDEF",
	"0123456789",
};

static const char *g_octot[] = {
	"0",
	"0x",
	"0X",
	"",
};

static uintmax_t	get_base(int base)
{
	if (base == OCTAL)
		return (8);
	else if (base == HEXL || base == HEXU)
		return (16);
	else
		return (10);
}

static size_t		len_nb(uintmax_t nb, int base)
{
	int ret;

	if (!nb)
		return (1);
	ret = 0;
	while (nb)
	{
		ret++;
		nb /= base;
	}
	return (ret);
}

static void			set_arr_n
(
	uintmax_t n,
	char *str,
	uintmax_t base,
	const char *base_str
)
{
	if (n >= base)
		set_arr_n(n / base, str - 1, base, base_str);
	*str = base_str[n % base];
}

char				*ft_fuitoa(uintmax_t n, int base, int per, int octot)
{
	char		*res;
	size_t		len;
	uintmax_t	base_n;
	size_t		len_oct;

	base_n = get_base(base);
	len = len_nb(n, base_n);
	len_oct = octot ? ft_strlen(g_octot[base]) : 0;
	if (per > (int)len)
	{
		len = per;
		if (base == OCTAL)
			len_oct = 0;
	}
	if (!(res = (char*)malloc((len + 1 + len_oct))))
		return (NULL);
	res[len + len_oct] = 0;
	ft_memset(res, '0', len + len_oct);
	set_arr_n(n, res + len + len_oct - 1, base_n, g_base[base]);
	if (len_oct)
		ft_memcpy(res, g_octot[base], len_oct);
	return (res);
}
