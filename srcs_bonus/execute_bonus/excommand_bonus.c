/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excommand_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:14:46 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/19 02:12:01 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

void	check_extern(char **argv)
{
	int	pid;
	int	status;

	find_path(argv);
	pid = fork();
	g_global.running = 1;
	change_signal();
	if (pid == 0)
	{
		child_signal();
		execve(*argv, argv, transfer_env(g_global.env));
		ft_putstr_fd("execve: ", 1);
		ft_putstr_fd(argv[0], 1);
		ft_putstr_fd(": command not found\n", 1);
		the_exit(127, 3);
	}
	waitpid(pid, &status, 0);
	set_signal();
	g_global.status = getst(status);
	g_global.running = 0;
}

void	ex_cmd(t_cmd *cmd)
{
	char	**argv;

	expand_tokens(&cmd->next);
	argv = transfer(cmd->next);
	if (check_builtin(argv))
		return ;
	check_extern(argv);
}

int	ft_access(char *file)
{
	int	fd;

	fd = open(file, O_EXCL);
	if (fd == -1)
		return (1);
	return (0);
}

int	find_path(char **argv)
{
	char	*path;
	char	**spl;

	path = get_env_value("PATH");
	if (!path)
		return (0);
	spl = ft_split(path, ':');
	if (*spl == NULL)
		return (0);
	while (*spl)
	{
		*spl = ft_strjoin(*spl, "/");
		if (!ft_access(ft_strjoin(*spl, *argv)))
			return ((*argv = ft_strjoin(*spl, *argv)), 1);
		spl++;
	}
	return (0);
}

bool	check_builtin(char **argv)
{
	if (!*argv)
		return (true);
	if (!ft_strcmp(*argv, "echo"))
		return (ft_echo(argv), true);
	else if (!ft_strcmp(*argv, "unset"))
		return (ft_unset(argv), true);
	else if (!ft_strcmp(*argv, "cd"))
		return (ft_cd(argv), true);
	else if (!ft_strcmp(*argv, "exit"))
		return (ft_exit(argv), true);
	else if (!ft_strcmp(*argv, "export"))
		return (ft_export(argv), true);
	else if (!ft_strcmp(*argv, "pwd"))
		return (ft_pwd(1), true);
	else if (!ft_strcmp(*argv, "env"))
		return (ft_env(), true);
	return (false);
}
