/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:29:35 by wluedara          #+#    #+#             */
/*   Updated: 2023/06/12 16:39:00 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

int	check_quote(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = ft_strlen(s[i]);
		if (is_quote(s[i][0]) == 1 && is_quote(s[i][j - 1]) != 1)
			return (0);
		else if (is_quote(s[i][0]) == 2 && is_quote(s[i][j - 1]) != 2)
			return (0);
		i++;
	}
	return (1);
}

char	*my_split_lexer(char *s)
{
	char	*str;
	char	*s2;
	int		letter;
	int		i;
	int		j;

	s2 = ft_strtrim(s, " ");
	i = 0;
	letter = count_letter_split(s2, i);
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

int	check_error(char **s)
{
	int	len;

	len = find_len_split(s) - 1;
	if (!ft_strncmp(s[len], "|", 1))
	{
		print_str(BCYN"Pipe is at the end ¯\\_ಠ_ಠ_/¯\n"RESET);
		return (0);
	}
	else if (!ft_strncmp(s[len], "<", 1) || !ft_strncmp(s[len], ">", 1) || \
	!ft_strncmp(s[len], ">>", 2) || !ft_strncmp(s[len], "<<", 2))
	{
		print_str(BCYN"Command is not complete ۹( ÒہÓ )۶\n"RESET);
		return (0);
	}
	return (1);
}

char	**cut_cmd(char *s)
{
	char	**new;
	int		word;
	int		i;
	int		j;
	int		letter;

	i = 0;
	word = check_word_lexer(s, ft_strlen(s), i);
	new = malloc(sizeof(char *) * (word + 1));
	if (!new)
		return (0);
	i = 0;
	j = 0;
	while (i < word)
	{
		new[i++] = my_split_lexer(&s[j]);
		letter = count_letter_lexer(&s[j]);
		j += letter;
	}
	new[i] = NULL;
	return (new);
}
