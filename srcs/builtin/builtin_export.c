
#include "hell.h"

int	builtin_export(t_main *main, t_cmd *cmd, char *str, int i)
{
	(void) cmd;
	(void) main;

	char *first;

	first = ft_strtrim(str, "=");
	// if (i < )
	// if (environ[i + 1])
	// 	compare = ft_strtrim(environ[i + 1], "=");
	// if (ft_strncmp(first, compare, ft_strlen(first)) < 0)

	return (0);
	// return (exit(0));
}

int	sort_env(char **str)
{
	int		i;
	int		j;

	i = -1;
	// str[i] = ft_strtrim(str, "=");
	while (str[++i])
	{
		j = -1;
		while (str[++j])
		{
			if (ft_strncmp(str[i], str[j], ft_min_len(str[i], str[j])) > 0)
				ft_swap(str[i], str[j]);
		}
	}
}

size_t	ft_len_trim(char *str, char trm)
{
	size_t	len;

	len = 0;
	while (str[len] != trm && str[len] != 0)
		len++;
	return (len);
}

size_t	ft_min_len(char *s1, char *s2)
{
	size_t	a;
	size_t	b;


}

char	**ft_strdup2(char **str)
{
	int		i;
	int		j;
	char	**new;

	i = -1;
	while (str[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	new[i] = NULL;
	i = -1;
	while (str[++i])
	{
		j = 0;
		while (str[i][j])
			j++;
		new[i] = malloc(sizeof(char) * (j + 1));
		new[i][j] = 0;
		j = -1;
		while (str[i][++j])
			new[i][j] = str[i][j];
	}
	return (new);
}

void free_2d(char **str)
{
	int		i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

