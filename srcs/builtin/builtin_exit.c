/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:32:38 by pnamwayk          #+#    #+#             */
/*   Updated: 2023/08/06 18:32:41 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int		builtin_exit(t_main *main, t_cmd *cmd);
void	error_msg_exit(char *msg, int err);
int		check_nbr(char *str);
int		cal_exit_code(char *str);

int	cal_exit_code(char *str)
{
	int	nbr;

	nbr = ft_atoi(str);
	return (nbr % 256);
}

int	builtin_exit(t_main *main, t_cmd *cmd)
{
	(void) main;
	if (!cmd->command[1])
		exit(0);
	else
	{
		if (check_nbr(cmd->command[1]))
		{
			if (!cmd->command[2])
			{
				write(STDERR_FILENO, "exit\n", 5);
				exit(cal_exit_code(cmd->command[1]));
			}
			else
				error_msg_exit(cmd->command[2], 2);
		}
		else
		{
			write(STDERR_FILENO, "exit\n", 5);
			error_msg_exit(cmd->command[1], 1);
			exit(255);
		}
	}
	return (0);
}

void	error_msg_exit(char *msg, int err)
{
	if (err == 1)
	{
		write(STDERR_FILENO, "mini(s)hell: exit: ", 19);
		write(STDERR_FILENO, msg, ft_strlen(msg));
		write(STDERR_FILENO, ": numeric argument required\n", 28);
	}
	if (err == 2)
		write(STDERR_FILENO, "mini(s)hell: exit: too many arguments\n", 38);
}

int	check_nbr(char *str)
{
	int		i;
	int		nbr;

	nbr = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = 1;
		i++;
	}
	if (nbr == 1 && str[i] == '\0')
		return (1);
	return (0);
}
