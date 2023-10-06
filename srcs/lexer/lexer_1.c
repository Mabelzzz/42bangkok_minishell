/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnamwayk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:29:35 by wluedara          #+#    #+#             */
/*   Updated: 2023/08/06 00:31:53 by pnamwayk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

char	*my_split_lexer(char *s)
{
	char	*str;
	char	*s2;
	int		letter;
	int		i;
	int		j;

	s2 = ft_strtrim(s, " ");
	letter = count_letter_split(s2, 0);
	str = malloc(sizeof(char) * (letter + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s2[j] && j < letter)
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s2);
	return (str);
}

int	check_error(char *s)
{
	int	len;

	len = ft_strlen(s) - 1;
	if (len == 0)
		return (0);
	if (s[len] == '|')
	{
		print_str(BCYN"Pipe is at the end ¯\\_ಠ_ಠ_/¯\n"RESET);
		return (0);
	}
	else if (s[len] == '>' || s[len] == '<')
	{
		print_str(BMAG"Command is not complete ۹( ÒہÓ )۶\n"RESET);
		return (0);
	}
	return (1);
}

int	check_close(char *s)
{
	int		i;
	int		close;
	char	quote;

	i = 0;
	close = -1;
	while (s[i])
	{
		if (is_quote(s[i]))
		{
			if (close == -1)
				quote = s[i];
			if (close == 0 && s[i] == quote)
				close = -1;
			else
				close = 0;
		}
		i++;
	}
	return (close == -1);
}

int	check_quote_pair(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!check_close(s[i]))
		{
			printf(BYEL"ไอ้โง่! quote are not pair in lexer (ㆆ_ㆆ)\n"RESET);
			return (0);
		}
		i++;
	}
	return (1);
}
