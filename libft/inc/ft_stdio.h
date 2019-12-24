#ifndef FT_STDIO_H
# define FT_STDIO_H


int		ft_putchar(int c);
int		ft_putchar_fd(int c, int fd);
int		ft_putstr(const char *s);
int		ft_putstr_fd(const char *s, int fd);
int		ft_putendl(const char *s);
int		ft_putendl_fd(const char *s, int fd);

int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
char	*ft_sprintf(const char *format, ...);

#endif
