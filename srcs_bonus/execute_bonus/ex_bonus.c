/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkwon <jiwkwon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:14:32 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/19 05:42:08 by jiwkwon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

void	pipe_ex_utils(int *fd, int i, t_tree *root)
{
	close(i);
	dup2(fd[i], i);
	close(fd[0]);
	close(fd[1]);
	cast_node(root);
	the_exit(g_global.status, 3);
}

void	ex_pipe(t_wp *root)
{
	int	pid;
	int	status;
	int	fd[2];

	if (pipe(fd) < 0)
		return ;
	pid = fork();
	if (!pid)
		pipe_ex_utils(fd, 1, root->left);
	pid = fork();
	if (!pid)
		pipe_ex_utils(fd, 0, root->right);
	close(fd[0]);
	close(fd[1]);
	pid = wait(&status);
	pid = wait(&status);
}

void	ex_redir(t_redir *root)
{
	int	fd;
	int	pid;
	int	status;

	fd = open(root->filename, root->mode, S_IRUSR | S_IWUSR);
	pid = fork();
	if (!pid)
	{
		if (root->redtype == GREAT || root->redtype == DGREAT)
			dup2(fd, 1);
		else if (root->redtype == LESS)
			dup2(fd, 0);
		else
			dup2(root->dst, 0);
		cast_node(root->next);
		exit(g_global.status);
	}
	waitpid(pid, &status, 0);
	close(fd);
	if (root->dst > 2)
		close(root->dst);
	g_global.status = getst(status);
}

void	cast_node(t_tree *root)
{
	if (root->type == SUB)
		cast_node(((t_sub *)root)->next);
	else if (root->type == CMD)
		ex_cmd((t_cmd *)root);
	if (root->type == REDIR)
		ex_redir((t_redir *)root);
	else if (root->type == T_AND)
	{
		cast_node(((t_wp *)root)->left);
		if (!g_global.status)
			cast_node(((t_wp *)root)->right);
	}
	else if (root->type == T_OR)
	{
		cast_node(((t_wp *)root)->left);
		if (g_global.status)
			cast_node(((t_wp *)root)->right);
	}
	else if (root->type >= T_PIPE)
		ex_pipe(((t_wp *)root));
}

int	getst(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (1);
}
