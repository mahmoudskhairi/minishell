/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:31:25 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/08/05 12:13:39 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

extern int	g_exit_status;

void	delete_env(t_env **env_l, char *var)
{
	t_env	*tmp;

	tmp = *env_l;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, var))
		{
			env_delone(env_l, tmp);
			return ;
		}
		tmp = tmp->next;
	}
}

int	mini_unset(t_env **env_l, char **cmd)
{
	int		i;
	bool	flag;

	i = 0;
	g_exit_status = EXIT_SUCCESS;
	while (cmd && cmd[++i])
	{
		if (check_key(cmd[i], &flag))
		{
			print_error("unset", ": not a valid identifier\n");
			g_exit_status = EXIT_FAILURE;
			continue ;
		}
		delete_env(env_l, cmd[i]);
	}
	return (g_exit_status);
}
