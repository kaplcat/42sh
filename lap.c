#include <stdlib.h>


# define TYPE_PIPE 1
# define TYPE_CMND 2
# define TYPE_SUFFIX 3
# define TYPE_WORD 4
# define TYPE_REDIR 5


typedef struct s_tree{
	struct s_tree *parent;
	struct s_tree *left;
	struct s_tree *right;
	t_token		*current;
	char		**argv;
	int			args;
	int			cur;
	int t_pipes;
	int t_semis;
	int in;
	int out;
	int type;   // 1 = pipe; 2 = command; 3 = suffix; 4 = word;
	int exe;
	int fd;         // o;      r;        n;
}t_tree;

t_hash *g_table;
char **g_my_env;

typedef struct s_hash_node{
	char *path;
	char *name;
	struct s_hash_node *next;
}t_hash_node;

typedef struct s_hash{
	int quant;
	t_hash_node **node;
}t_hash;

typedef struct s_tokens{
	int type;                 // 1 = |        2 = ;         3 = redirect         4 = aggregation
	char *buf;
	struct s_tokens *next;
}t_token;

void	splitterok(t_token **list, t_token **right)
{
	t_token *temp;

	temp = *list;
	*right = NULL;
	if (temp == NULL)
	{
		return ;
	}
	if (temp->next)
	{
		*right = temp->next;
		temp->next = NULL;
	}
}

t_tree	*create_node(t_token *list, int type, t_tree *parent)
{
	t_tree *res;

	//res = ft_memalloc(sizeof(t_tree));
	res = (t_tree *)malloc(sizeof(t_tree) * 1);

	res->left = NULL;
	res->right = NULL;
	res->in = 0;
	res->out = 1;
	res->t_pipes = 0;
	res->t_semis = 0;
	res->argv = NULL;
	res->args = 0;
	res->cur = 0;
	res->exe = 0;
	res->fd = 0;
	res->parent = parent;
	res->current = list;
	if (list == NULL)
		res->type = 0;
	else
		res->type = type;
	return (res);
}

void	split_list(t_token **list, t_token **right, t_tree *ast, int type)
{
	t_token *temp;

	temp = *list;
	if (temp == NULL)
		return ;
	while (temp->next)
	{
		if (temp->next && temp->next->type == type)
		{
			ast->t_pipes -= 1;
			if (ast->t_pipes == 0)
			{
				*right = temp->next->next;
				free(temp->next->buf);
				free(temp->next);
				temp->next = NULL;
				break ;
			}
		}
		temp = temp->next;
	}
}

void	split_semicolomn(t_token **left, t_token **right)
{
	t_token *list;

	list = *left;
	if (list == NULL)
		return ;
	while (list->next && list->next->type != TYPE_CMND)
		list = list->next;
	if (list->next && list->next->next)
	{
		*right = list->next->next;
		free(list->next->buf);
		free(list->next);
	}
	else
		*right = NULL;
	list->next = NULL;
}

int		count_token_types(t_token *list, int type)
{
	int i;

	i = 0;
	while (list)
	{
		if (list->type == type)
			i++;
		list = list->next;
	}
	return (i);
}

void	create_tree_type_two(t_tree *ast, t_token *left, t_token *right)
{
	if (ast->t_pipes == 0 && ast->t_semis == 0)
		ast->type = 3;
	else if (ast->t_semis == 0 && ast->t_pipes > 0)
		ast->type = 1;
	else
	{
		split_semicolomn(&left, &right);
		ast->left = create_node(left, 2, ast);
		ast->right = create_node(right, 2, ast);
		create_tree(ast->left);
		create_tree(ast->right);
	}
}

void	create_tree_type_one(t_tree *ast, t_token *left, t_token *right)
{
	if (ast->t_pipes == 0)
		ast->type = 3;
	else
	{
		split_list(&left, &right, ast, 1);
		ast->left = create_node(left, 1, ast);
		ast->right = create_node(right, 2, ast);
		create_tree(ast->left);
		create_tree(ast->right);
	}
}

void	create_tree(t_tree *ast)
{
	t_token *left;
	t_token *right;

	left = ast->current;
	right = NULL;
	if (ast == NULL)
		return ;
	ast->t_pipes = count_token_types(ast->current, 1);
	ast->t_semis = count_token_types(ast->current, 2);
	if (ast->type == 2) //2 means i will search for ;
		create_tree_type_two(ast, left, right);
	if (ast->type == 1) // 1 means i will search for |
		create_tree_type_one(ast, left, right);
	if (ast->type == 3)
	{
		if (ast->current->type >= 3 && ast->current->type <= 9)
			ast->type = 5;
		else
		{
			splitterok(&left, &right);
			ast->left = create_node(left, 4, ast);
			ast->right = create_node(right, 3, ast);
			create_tree(ast->right);
		}
	}
}


int		type(char *buf)
{
	if (ft_strcmp(buf, "|") == 0)
		return (1);
	if (ft_strcmp(buf, ";") == 0)
		return (2);
	if (ft_strcmp(buf, ">") == 0)
		return (3);
	if (ft_strcmp(buf, "<") == 0)
		return (4);
	if (ft_strcmp(buf, ">>") == 0)
		return (3);
	if (ft_strcmp(buf, "<<") == 0)
		return (6);
	if (ft_strcmp(buf, "<&") == 0)
		return (7);
	if (ft_strcmp(buf, ">&") == 0)
		return (8);
	return (0);
}

void	append(t_token **head, t_token *new)
{
	t_token *tmp;

	tmp = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int		buf_word_len(char *cmd)
{
	int i;

	i = 0;
	while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t' && cmd[i] != ';'
	&& cmd[i] != '|' && cmd[i] != '>' && cmd[i] != '<'
	&& cmd[i] != '"' && cmd[i] != 39)
		i++;
	return (i);
}

char	*create_buf(char *cmd)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = buf_word_len(cmd);
	res = NULL;
	if (len > 0)
	{
		res = (char *)malloc(sizeof(char) * (len + 1));
		while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t' && cmd[i] != ';'
		&& cmd[i] != '|' && cmd[i] != '<' && cmd[i] != '>'
		&& cmd[i] != '"' && cmd[i] != 39)
		{
			res[i] = cmd[i];
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}

t_token	*create_token_new(char *buf)
{
	t_token *new;

	new = (t_token *)malloc(sizeof(t_token) * 1);
	new->buf = buf;
	new->type = type(buf);
	new->next = NULL;
	return (new);
}

char	*create_token_buf(char *cmd, size_t i, size_t cmd_len)
{
	char *buf;

	buf = NULL;
	if (i < cmd_len && i + 1 < cmd_len && cmd[i] == '>' && cmd[i + 1] == '>')
		buf = ft_strdup(">>");
	else if (i < cmd_len && i + 1 < cmd_len
	&& cmd[i] == '<' && cmd[i + 1] == '<')
		buf = ft_strdup("<<");
	else if (i < cmd_len && i + 1 < cmd_len
	&& cmd[i] == '<' && cmd[i + 1] == '&')
		buf = ft_strdup("<&");
	else if (i < cmd_len && i + 1 < cmd_len
	&& cmd[i] == '>' && cmd[i + 1] == '&')
		buf = ft_strdup(">&");
	else if (cmd[i] && cmd[i] == ';')
		buf = ft_strdup(";");
	else if (cmd[i] && cmd[i] == '|')
		buf = ft_strdup("|");
	else if (cmd[i] && cmd[i] == '>')
		buf = ft_strdup(">");
	else if (cmd[i] && cmd[i] == '<')
		buf = ft_strdup("<");
	return (buf);
}

t_token	*create_token(char *cmd, size_t i, size_t cmd_len)
{
	t_token	*new;
	char	*buf;

	buf = NULL;
	new = NULL;
	buf = create_token_buf(cmd, i, cmd_len);
	if (buf != NULL)
		new = create_token_new(buf);
	return (new);
}

t_token	*create_new(char *cmd, size_t i, size_t cmd_len)
{
	t_token	*new;
	char	*buf;

	new = NULL;
	buf = create_buf(&cmd[i]);
	if (buf != NULL)
	{
		new = (t_token *)malloc(sizeof(t_token) * 1);
		new->buf = buf;
		new->next = NULL;
		new->type = type(buf);
	}
	else
		new = create_token(cmd, i, cmd_len);
	return (new);
}

size_t	lexer_count_i(char *cmd, int i)
{
	if (cmd[i + 1] && cmd[i] == '>' && cmd[i + 1] == '>')
		i += 2;
	else if (cmd[i + 1] && cmd[i] == '<' && cmd[i + 1] == '<')
		i += 2;
	else if (cmd[i + 1] && cmd[i] == '<' && cmd[i + 1] == '&')
		i += 2;
	else if (cmd[i + 1] && cmd[i] == '>' && cmd[i + 1] == '&')
		i += 2;
	else if (cmd[i] == ';' || cmd[i] == '|' || cmd[i] == '>' || cmd[i] == '<')
		i++;
	else
		while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\t' && cmd[i] != ';'
		&& cmd[i] != '|' && cmd[i] != '>' && cmd[i] != '<')
			i++;
	return (i);
}

t_token	*lexer(char *cmd)
{
	t_token	*head;
	t_token *new;
	size_t	i;
	size_t	len;

	len = ft_strlen(cmd);
	i = 0;
	head = NULL;
	while (cmd[i])
	{
		while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'
		|| cmd[i] == '"' || cmd[i] == 39))
			i++;
		if (cmd[i] == '\0')
			break ;
		new = create_new(cmd, i, len);
		append(&head, new);
		i = lexer_count_i(cmd, i);
	}
	return (head);
}


char	*sub_line_stuf(char *parse)
{
	char *res;

	if (ft_strlen(parse) == 1)
		res = ft_strdup("$");
	else
		res = ft_strdup(" ");
	return (res);
}

char	*sub_line_dollar(char *parse)
{
	char *res;
	char *seek;

	seek = ft_getenv(&parse[1]);
	if (seek == NULL)
	{
		res = sub_line_stuf(parse);
		free(parse);
	}
	else
	{
		res = ft_strdup(seek);
		free(parse);
	}
	return (res);
}

char	*sub_line(char *parse)
{
	char *seek;
	char *res;

	res = parse;
	if (parse[0] == '$')
		res = sub_line_dollar(parse);
	else if (parse[0] == '~')
	{
		seek = ft_getenv("HOME");//
		if (seek == NULL)
			res = NULL;
		else
		{
			res = ft_strjoin(seek, &parse[1]);
			free(parse);
		}
	}
	return (res);
}

int		semantics_semicolomn(t_token *list)
{
	if (list->type == 2)
	{
		if (list->next && list->next->type == 2)
		{
			//perror_cmnd(SHELLNAME, NULL, PARSEERR_SEMICOLS);
			return (1);
		}
	}
	return (0);
}

int		semantics(t_token *list)
{
	int first;

	first = 1;
	if (list && list->next == NULL)
	{
		if (list->type == 2)
			return (1);
	}
	while (list)
	{
		if (list->type != 1)
			first = 0;
		if (semantics_semicolomn(list))
			return (1);
		if (list->type == 1)
		{
			if ((list->next && list->next->type == 1) || first == 1)
			{
			//	perror_cmnd(SHELLNAME, NULL, PARSEERR_PIPE);
				return (1);
			}
		}
		list = list->next;
	}
	return (0);
}

void	update_lexer(t_token **list)
{
	t_token *temp;
	t_token *head;

	head = *list;
	if (head)
	{
		if (head->type == 2 && head->next && head->next->type != 2) {
			temp = *list;
			*list = (*list)->next;
			free(temp->buf);
			free(temp);
		}
		head = *list;
		while (head) {
			if (head->next && head->next->type == 8) {
				head->type = 9;
				if (head->next->next)
					head->next->next->type = 9;
			}
			head->buf = sub_line(head->buf);
			head = head->next;
		}
	}
}

void	print_tree(t_tree *ast)
{
	if (ast == NULL)
		return ;
	ft_putnbr(ast->type);
	ft_putchar('\n');
	print_tree(ast->left);
	print_tree(ast->right);
}

void	action(char *cmd)
{
	t_token	*list;
	t_tree	*ast;

	list = lexer(cmd);
	update_lexer(&list);
	if (semantics(list) == 1)
	{
		free_token_list(&list);
		return ;
	}
	ast = create_node(list, 2, NULL);
	create_tree(ast);
}