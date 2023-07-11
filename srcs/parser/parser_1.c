/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:49:47 by wluedara          #+#    #+#             */
/*   Updated: 2023/06/10 16:57:22 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	find_pipe(t_main *main)
{
	t_lexer	*tmp;
	int		num;

	tmp = main->lexer;
	num = 1;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->str, "|", 1) == 0)
		{
			num++;
			main->num_pipe++;
		}
		tmp = tmp->next;
	}
	return (num);
}

int	find_cmd_num(t_lexer *list)
{
	t_lexer	*tmp;
	int		cmd;

	tmp = list;
	cmd = 0;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->str, "|", 1) != 0)
			cmd++;
		else
			break ;
		tmp = tmp->next;
	}
	return (cmd);
}

void	next_cmd(t_lexer **list, int index)
{
	t_lexer	*tmp;

	tmp = *list;
	while (tmp != NULL)
	{
		if (tmp->index <= index)
			tmp = tmp->next;
		else
			break ;
	}
	insert_index(&tmp, stack_lenght(&tmp));
	*list = tmp;
}

t_cmd	*list_cmd(t_main *main)
{
	int			size;
	int			word;
	int			i;
	t_lexer		*new;

	size = find_pipe(main);
	i = 0;
	new = main->lexer;
	while (i < size)
	{
		create_list_cmd(&main->cmd, new);
		word = find_cmd_num(new);
		next_cmd(&new, word);
		i++;
	}
	return (main->cmd);
}
