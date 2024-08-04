/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:15:02 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/08/04 16:18:03 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

extern int	g_exit_status;

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	check_args(char **cmd)
{
	if (!cmd[1])
		exit(0);
	if (is_number(cmd[1]))
	{
		dprintf(2, " numeric argument required\n");
		exit(255);
	}
	if (cmd[1] && cmd[2])
	{
		dprintf(2, " too many arguments\n");
		g_exit_status = EXIT_FAILURE;
		return (EXIT_FAILURE);
	}
	return (0);
}

int	mini_exit(char **cmd)
{
	int	check_errors;

	printf("exit\n");
	check_errors = check_args(cmd);
	if (check_errors)
		return (1);
	g_exit_status = ft_atoi(cmd[1]);
	exit(g_exit_status);
	return (0);
}
