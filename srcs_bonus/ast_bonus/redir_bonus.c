/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:10:10 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/19 05:42:46 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

int	heredoc(char *del)
{
	int		fd[2];
	char	*line;
	int		pid;

	pid = (pipe(fd), fork());
	if (pid == 0)
	{
		signal(SIGINT, heredoc_handler);
		while (1)
		{
			line = readline(">");
			if (!line || !ft_strcmp(del, line))
			{
				free_heredoc_line(line);
				break ;
			}
			write(fd[1], line, ft_strlen(line));
			write(fd[1], "\n", 1);
			free(line);
		}
		the_exit(0, 3);
	}
	signal(SIGINT, SIG_IGN);
	waitpid(pid, 0, 0);
	return (set_signal(), close(fd[1]), fd[0]);
}

t_tree	*get_redir(t_tree *next, char *filename, int redtype)
{
	t_redir	*node;

	node = ft_malloc(g_global.cur, sizeof(t_redir), 1);
	memset(node, 0, sizeof(t_redir));
	node->type = REDIR;
	node->redtype = redtype;
	node->next = next;
	node->src = STDIN_FILENO;
	node->mode = O_RDONLY;
	if (redtype == GREAT || redtype == DGREAT)
	{
		node->src = STDOUT_FILENO;
		if (redtype == GREAT)
			node->mode = O_CREAT | O_RDWR | O_TRUNC;
		else
			node->mode = O_CREAT | O_RDWR | O_APPEND;
	}
	if (redtype == DLESS)
		node->dst = heredoc(filename);
	node->filename = filename;
	return ((t_tree *)node);
}

void	get_rdr_utils(t_token **head, t_command **root)
{
	while (*head && ((*head)->type == VAR || (*head)->type == WORD))
	{
		append_in_cmdend(root, (*head)->str, (*head)->type);
		*head = get_right(*head);
	}
}

t_tree	*get_rdr(t_token **head, t_tree *n)
{
	t_tree	*next;
	t_tree	*ret;
	t_cmd	*next2;

	ret = NULL;
	if (!n)
	{
		next = get_cmdlist(head);
		next2 = (t_cmd *)next;
	}
	else
		next = n;
	while (*head && (*head)->type >= 1 && (*head)->type <= 4)
	{
		*head = get_right(*head);
		ret = get_redir(next, (*head)->str, get_left(*head)->type);
		next = ret;
		*head = get_right(*head);
		get_rdr_utils(head, &((t_cmd *)ret)->next);
	}
	if (ret)
		return (ret);
	else
		return (next);
	(void)next2;
}
