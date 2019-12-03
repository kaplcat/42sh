/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreiten <dbreiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 03:47:43 by dbreiten          #+#    #+#             */
/*   Updated: 2019/10/09 11:28:49 by dbreiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <inttypes.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static ssize_t	write_with_margin(t_buff *buff, t_handle *hndl, char *data)
{
	size_t	len_data;

	len_data = ft_strlen(data);
	if (hndl->flags ^ NEG && hndl->width > (int)len_data)
	{
		if (write_buff(buff, " ", 1, hndl->width - (int)len_data) == -1)
			return (-1);
	}
	if (write_buff(buff, data, len_data, 1) == -1)
		return (-1);
	if (hndl->flags & NEG && hndl->width > (int)len_data)
	{
		if (write_buff(buff, " ", 1, hndl->width - (int)len_data) == -1)
			return (-1);
	}
	return (MAX((int)len_data, hndl->width));
}

static int		get_signsyn(t_handle *hndl)
{
	int	sign;

	sign = 0;
	if (hndl->per != -1 || hndl->flags & NEG)
		hndl->flags &= ~ZERO;
	if (hndl->flags & POS)
	{
		hndl->flags &= ~SPACE;
		sign = 1;
	}
	else if (hndl->flags & SPACE)
		sign = 2;
	return (sign);
}

static int		get_lenoctot(t_handle *hndl, uintmax_t nb)
{
	int	len_octot;

	len_octot = 0;
	hndl->flags &= ~POS;
	hndl->flags &= ~SPACE;
	if (hndl->per != -1 || hndl->flags & NEG)
		hndl->flags &= ~ZERO;
	if (nb == 0)
		hndl->flags &= ~OCT;
	if ((hndl->flags & OCT) && (hndl->base == HEXL || hndl->base == HEXU))
		len_octot = 2;
	return (len_octot);
}

ssize_t			parse_hndl_nb(t_buff *buff, t_handle *hndl, intmax_t nb)
{
	char	*data;
	int		sign;
	size_t	len_data;
	int		ret;

	sign = get_signsyn(hndl);
	if (hndl->flags & ZERO)
	{
		data = ft_fitoa(nb, hndl->width - !!sign, sign);
		if (data == NULL)
			return (-1);
		len_data = ft_strlen(data);
		ret = write_buff(buff, data, len_data, 1);
		free(data);
		return (ret);
	}
	data = ft_fitoa(nb, hndl->per, sign);
	if (data == NULL)
		return (-1);
	ret = write_with_margin(buff, hndl, data);
	free(data);
	return (ret);
}

ssize_t			parse_hndl_unb(t_buff *buff, t_handle *hndl, uintmax_t nb)
{
	char		*data;
	size_t		len_data;
	size_t		len_octot;
	ssize_t		ret;

	len_octot = get_lenoctot(hndl, nb);
	if (hndl->flags & ZERO)
	{
		data = ft_fuitoa(nb, hndl->base, hndl->width - len_octot,
						hndl->flags & OCT);
		if (data == NULL)
			return (-1);
		len_data = ft_strlen(data);
		ret = write_buff(buff, data, len_data, 1);
		free(data);
		return (ret);
	}
	data = ft_fuitoa(nb, hndl->base, hndl->per, hndl->flags & OCT);
	if (data == NULL)
		return (-1);
	ret = write_with_margin(buff, hndl, data);
	free(data);
	return (ret);
}
