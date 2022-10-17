/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshin <jshin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:02:20 by jiwkwon           #+#    #+#             */
/*   Updated: 2022/10/17 10:10:02 by jshin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

t_env	*new_node_env(char *key, char *value)
{
	t_env	*new;

	new = (t_env *)ft_malloc(g_global.cur, sizeof(t_env), 0);
	if (!new)
		return (NULL);
	new->value = value;
	new->key = key;
	new->next = NULL;
	return (new);
}

void	append_in_end_env(t_env **root, char *key, char *value)
{
	t_env	*tmp;
	t_env	*p;

	tmp = new_node_env(key, value);
	if (!*root)
		*root = tmp;
	else
	{
		p = *root;
		while (p->next)
			p = p->next;
		p->next = tmp;
	}
}

void	display_env(t_env *root)
{
	t_env	*temp;

	temp = root;
	if (!root)
		return ;
	else
	{
		temp = root;
		while (temp)
		{
			if (temp->value)
			{
				ft_putstr_fd(temp->key, 1);
				ft_putstr_fd("=", 1);
				ft_putstr_fd(temp->value, 1);
				ft_putstr_fd("\n", 1);
			}
			temp = temp->next;
		}
	}
}

void	get_env(char **env)
{
	char	**spl;

	while (*env)
	{
		spl = ft_split(*env, '=');
		append_in_end_env(&g_global.env, spl[0], spl[1]);
		env++;
	}
}

char	**transfer_env(t_env *env)
{
	int		i;
	int		n;
	char	*key;
	char	**argv;

	i = -1;
	n = envlstsize(env);
	argv = ft_malloc(g_global.cur, (n + 1) * sizeof(char *), 1);
	while (env)
	{
		key = ft_strjoin(env->key, "=");
		argv[++i] = ft_strjoin(key, env->value);
		env = env->next;
	}
	argv[n] = NULL;
	return (argv);
}
