/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbreiten <dbreiten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 03:32:43 by dbreiten          #+#    #+#             */
/*   Updated: 2019/10/09 11:28:28 by dbreiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <ft_string.h>
# include <stdarg.h>
# include <inttypes.h>
# include <unistd.h>

# define MAX(a,b) ((a) > (b) ? (a) : (b))
# define MIN(a,b) ((a) < (b) ? (a) : (b))
# define OCTAL 0
# define HEXL 1
# define HEXU 2
# define DEC 3

enum
{
	NEG = (1 << 0),
	POS = (1 << 1),
	SPACE = (1 << 2),
	OCT = (1 << 3),
	ZERO = (1 << 4)
};

enum
{
	LLPRE,
	LPRE,
	HHPRE,
	HPRE,
	JPRE,
	ZPRE,
	BASE,
};

typedef struct	s_buff
{
	int			fd;
	void		*data;
	size_t		all_size;
	size_t		curr_size;
}				t_buff;

typedef struct	s_handle
{
	int			flags;
	int			width;
	int			per;
	int			size;
	int			base;
}				t_handle;

/*
**		BUFF
*/
t_buff			*create_buff(int fd, size_t size);
void			delete_buff(t_buff *buf);
ssize_t			write_buff(t_buff *buf, void *data, size_t size, size_t num);
ssize_t			clean_buff(t_buff *buf);
void			*ft_realloc(void *src, size_t curr_size, size_t new_size);

/*
**		PARSE MAIN
*/
int				parse_format(int fd, const char *format, va_list list);
t_buff			*parse_format_s(int fd, const char *format, va_list list);

/*
**		PARSE META INFO
*/

int				parse_flags(char **format);
int				parse_width(char **format, va_list list);
int				parse_per(char **format, va_list list);
int				parse_size(char **format);
ssize_t			parse_hndl_type(t_buff *buf, t_handle *hndl, char **format,
								va_list list);

/*
**		PARSE DIGITS
*/
ssize_t			parse_hndl_nb(t_buff *buf, t_handle *hndl, intmax_t nb);
ssize_t			parse_hndl_unb(t_buff *buf, t_handle *hndl, uintmax_t nb);
char			*ft_fitoa(intmax_t nb, int perm, int show_sign);
char			*ft_fuitoa(uintmax_t n, int base, int per, int octot);

/*
**		PARSE STRING/CHAR
*/

ssize_t			parse_hndl_str(t_buff *buf, t_handle *hndl, const char *str);
ssize_t			parse_hndl_sym(t_buff *buf, t_handle *hndl, char c);

#endif
