#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strstr(const char *s1, const char *s2);
size_t	ft_strnlen(const char *s, size_t n);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strncat(char *dest, const char *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
size_t	ft_strspn(const char *s1, const char *s2);
size_t	ft_strcspn(const char *s1, const char *s2);
char	*ft_strpbrk(const char *s1, const char *s2);
char    *ft_strdup(const char *s);
char    *ft_strndup(const char *s);
size_t  ft_strlcpy(char *dest, const char *src, size_t n);
size_t  ft_strlcat(char *dest, const char *src, size_t n);
char    **ft_strsplit(const char *s, int sep);

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memrchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_mempcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

#endif
