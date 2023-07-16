/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 21:13:32 by wluedara          #+#    #+#             */
/*   Updated: 2023/07/15 15:53:34 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int check_builtin(t_cmd *tmp);
int	into_builtin_parent(t_main *main, t_cmd *cmd);
int	into_builtin_child(t_main *main, t_cmd *cmd);

int	into_builtin_parent(t_main *main, t_cmd *cmd)
{
	(void) main;
	if (!ft_strncmp(cmd->command[0], "cd", 3))
		return (builtin_cd(main, cmd));
	else if (!ft_strncmp(cmd->command[0], "export", 7))
		return (builtin_export(main, cmd));
	// else if (!ft_strncmp(cmd->command[0], "unset", 6))
	// 	return (builtin_unset(cmd));
	// else if (!ft_strncmp(cmd->command[0], "exit", 5))
	// 	return (builtin_exit(cmd));
	return (-1);
}

int	into_builtin_child(t_main *main, t_cmd *cmd)
{
	if (!ft_strncmp(cmd->command[0], "echo", 5))
		return (builtin_echo(main, cmd));
	else if (!ft_strncmp(cmd->command[0], "pwd", 4))
		return (builtin_pwd(main, cmd));
	else if (!ft_strncmp(cmd->command[0], "env", 4))
		return (builtin_env(main, cmd));
	return (-1);
}

// void	into_builtin(t_main *main)
// {
// 	t_cmd	*tmp;
// 	int		j;

// 	tmp = main->cmd;
// 	while (tmp != NULL)
// 	{
// 		j = 0;
// 		while (tmp->command[0])
// 		{
// 			if(into_builtin2(main, tmp, j)
// 				j++;
// 		}
// 		tmp = tmp->next;
// 	}
// }

int check_builtin(t_cmd *tmp)
{
	if (!ft_strncmp(tmp->command[0], "echo", 5) ||
		!ft_strncmp(tmp->command[0], "pwd", 4) ||
		!ft_strncmp(tmp->command[0], "env", 4))
		return (1);
	if (!ft_strncmp(tmp->command[0], "cd", 3) ||
		!ft_strncmp(tmp->command[0], "export", 6) ||
		!ft_strncmp(tmp->command[0], "unset", 5) ||
		!ft_strncmp(tmp->command[0], "exit", 4))
		return (2);
	return (0);
}
