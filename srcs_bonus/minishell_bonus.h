/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:56:49 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/19 04:08:50 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BONUS_H
# define MINISHELL_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <dirent.h>
# include <stdbool.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

# define VAR 0
# define DGREAT 1
# define DLESS 2
# define LESS 3
# define GREAT 4
# define WORD 5
# define WSPACE 6
# define SQUOTE 7
# define DQUOTE 8
# define OPAR 9
# define WILD 10
# define TILD 11
# define AND 12
# define OR 13
# define PIPE 14
# define CPAR 15
// node_tree
# define SUB 16
# define CMD 17
# define REDIR 18
# define T_PIPE 19
# define T_AND 20
# define T_OR 21

typedef struct s_token
{
	struct s_token	*prev;
	char			*str;
	int				type;
	struct s_token	*next;
}	t_token;

typedef struct s_tree
{
	int				type;
}	t_tree;

typedef struct s_command
{
	int					type;
	char				*content;
	struct s_command	*next;
}	t_command;

typedef struct s_cmd
{
	int					type;
	struct s_command	*next;
}	t_cmd;

typedef struct s_sub
{
	int				type;
	struct s_tree	*next;
}	t_sub;

typedef struct s_wp
{
	int				type;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_wp;

typedef struct s_redir
{
	int				type;
	int				redtype;
	char			*filename;
	int				src;
	int				dst;
	int				mode;
	struct s_tree	*next;	
}	t_redir;

typedef struct s_collector
{
	void				*adr;
	int					key;
	struct s_collector	*next;
}	t_collector;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_global
{
	t_collector	*adrs;
	t_collector	**cur;
	t_env		*env;
	int			status;
	int			running;
}	t_global;

t_global	g_global;

// 1. ENV
void		get_env(char **env);
void		append_in_end_env(t_env **root, char *key, char *value);
t_env		*new_node_env(char *key, char *value);
void		display_env(t_env *root);
t_env		*get_env_node(char *str);
char		*get_env_value(char *str);
void		delete_env(t_env **root, t_env *deleted);
int			envlstsize(t_env *root);
char		**transfer_env(t_env *env);

// 2. PARSER
t_tree		*token(int (**fp)(char *, t_token **, const bool *), char *str, \
			t_token **root, const bool *comp);
int			check_char2(char *str, t_token **root);
int			take_word(char *str, t_token **root, const bool *comp);
int			take_word2(char *str, t_token **root);
int			take_space(char *str, t_token **root, const bool *comp);
int			take_var(char *str, t_token **root, const bool *comp);
int			take_var2(char *str, t_token **root);
int			take_colon(char *str, t_token **root, const bool *comp);
int			take_colon2(char *str, t_token **root);
int			take_dquote(char *str, t_token **root);
int			check_closed_dq(t_token **root, char *str, int i, int last);
int			take_less_more(char *str, t_token **root, const bool *comp);
int			take_wp(char *str, t_token **root, const bool *comp);
int			take_par(char *str, t_token **root, const bool *comp);
int			take_par2(char *str, t_token **root);
void		append_in_end(t_token **root, char *str, int flag);
t_token		*new_node(char *str, int flag);
void		display_node(t_token *root);
void		clr_lst(t_token **root, t_token *node);
void		*add_item(char *start, char *end, int flag, t_token **root);
void		unclosed_quote(t_token **root);
int			invalid_token(t_token **root, char *str);
int			get_last(char *str);
int			calc_size(char *start, char *end);
int			check_flag(char *str, int q);
int			add_item_int(char *str, t_token **root, const bool *comp);

// 3. SYNTAX
int			check_syntax(t_token **root);
int			check_begin(t_token *root);
int			check_list(t_token *root);
int			check_wp(t_token *root);
int			check_cpar(t_token *root);
int			check_red(t_token *root);
int			check_bal_par(t_token **root);
void		syntax_error(void);
t_token		*get_left(t_token *root);
t_token		*get_right(t_token *root);

// 4. AST
t_tree		*get_full(t_token **head);
t_tree		*get_block(t_token **head);
t_tree		*get_pipe(t_token **head);
t_tree		*get_command(t_token **head);
t_tree		*get_rdr(t_token **head, t_tree *n);
t_tree		*get_cmdlist(t_token **head);
t_tree		*get_cmdlist2(t_token **head, t_cmd	*ret, char **join);
int			get_cmdlist_utils(t_token **head, t_command **root, char **join);
int			get_cmdlist_utils2(t_token **head, t_command **root, char **join);
int			heredoc(char *del);
t_tree		*get_redir(t_tree *next, char *filename, int redtype);
t_command	*new_nodecommand(char *str, int flag);
void		append_in_cmdend(t_command **root, char *str, int type);
t_tree		*get_wp(int type, t_tree *left, t_tree *right);
t_tree		*get_cmdnode(t_cmd *next);
t_tree		*get_sub(t_tree *next);
int			get_type(t_token *head);
t_command	*get_nodelist(char *content);
void		display_tree(t_tree *tree, int in);
void		display_nodetree(t_command *root);
int			cmdlstsize(t_command *root);
void		delete_quotes(t_token **root);
t_token		*link_nodes(t_token **root, t_token *deleted);
void		delete_node_commnd(t_command **root, t_command *deleted);

// 5. EXECUTE
void		cast_node(t_tree *root);
void		ex_redir(t_redir *root);
void		ex_pipe(t_wp *root);
void		ex_cmd(t_cmd *cmd);
void		expand_tokens(t_command **root);
void		check_token_type(t_command **root, t_command *node);
void		get_wild_value(t_command **root, t_command *node);
char		**transfer(t_command *root);
int			getst(int status);
bool		check_builtin(char **argv);
int			find_path(char **argv);
int			ft_access(char *file);
bool		is_slash(char *argv);

// 6. BUILTINS
void		ft_cd(char **argv);
void		check_dir(char **argv, int s, char *cur);
int			ft_echo(char **argv);
int			get_echo_flag(int flag);
int			new_line(char *str);
void		the_exit(int status, int d_flag);
int			ft_exit(char **argv);
void		free_heredoc_line(char *line);
int			ft_pwd(int fd);
void		ft_unset(char **argv);
void		ft_env(void);
void		ft_export(char **argv);
void		display_exports(void);
char		**ft_split_exp(char *line);

// 7. ETC
void		set_signal(void);
void		handler(int sig);
void		handler2(int sig);
void		handler3(int signal);
void		change_signal(void);
void		child_signal(void);
void		heredoc_handler(int sig);
void		*ft_malloc(t_collector **root, size_t size, int key);
t_collector	**append_adr(t_collector **root, void *adr, int key);
t_collector	*new_node_adr(void *adr, int key);
void		ft_collect(t_collector **root, t_collector *node, int key);
int			check_history(char *str);
void		set_fp_n_comp(int (**fp)(char *, t_token **, const bool *), \
			bool *comp, unsigned int i);
void		set_fp_n_comp2(int (**fp)(char *, t_token **, const bool *), \
			bool *comp, unsigned int i);

// 8. UTILS
char		*ft_itoa(int n);
int			ft_is_separator(char c, char cr);
int			ft_words(char *str, char c);
void		ft_write_word(char *dest, char *src, char c);
int			ft_write_split(char **split, char *str, char c);
char		**ft_split(char const *s, char c);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(char *s1);

#endif
