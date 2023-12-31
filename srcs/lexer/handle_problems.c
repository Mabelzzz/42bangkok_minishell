/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_problems.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:11:40 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/05 22:45:38 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\v' || c == '\r' \
	|| c == '\n')
		return (1);
	return (0);
}

int	is_quote(char c)
{
	if (c == '\'')
		return (1);
	if (c == '\"')
		return (2);
	return (0);
}

int	is_tokens(char c)
{
	char	*tokens;
	int		i;

	i = 0;
	tokens = "<>";
	while (i < 2)
	{
		if (c == tokens[i])
			return (i);
		i++;
	}
	return (-1);
}

int	is_pipe(char c)
{
	if (c == '|')
		return (1);
	return (0);
}
