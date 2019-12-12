#ifndef FT_STL_H
# define FT_STL_H

#include <stdlib.h>
/*
** ft_list
*/

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

t_list					*ft_lstnew(void *content, size_t content_size);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstaddhere(t_list **alst, t_list *new, size_t position);
void					ft_lstpushback(t_list **alst, t_list *new);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelthis(t_list **alst, size_t lstnum, \
													void (*del)(void *, size_t));
void					ft_lstdelhead(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdeltail(t_list **alst, void (*del)(void *, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_putlst(t_list *alst, void (*print)(void *));
size_t					ft_lstsize(t_list *alst);

/*
** ft_map
*/

# define EXPANSION_COEFFICIENT 4

typedef struct			s_htab
{
	char				*key;
	void				*value;
}						t_htab;

int						hashfunction(const char *str, int size);
t_htab					*init_htab(const char *key, void *value);
void					print_htab(t_htab *htab, void (*printvalue)(void *));

typedef struct			s_map
{
	t_list				**array;
	size_t				size;
	size_t				numof_items;
	void				*hashfunc;
	void				*valuedel_func;
}						t_map;

void				map_reindexing(t_map **map);

t_map				*ft_mapinit(size_t mapsize, void *hash_func, \
						void *valuedel_func);
void				ft_mapinsert(t_map **map, const char *key, void *value);
int					ft_ismapitem(t_map *map, const char *key);
const void			*ft_mapvalue(t_map *map, const char *key);
void				ft_mapdel(t_map **map);
void				ft_mapdelind(t_map **map, size_t index);
void				ft_mapdelkey(t_map **map, const char *key);
void				ft_putmap(t_map *map, void (*printvalue)(void *));

#endif