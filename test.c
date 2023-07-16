# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// #include "hell.h"

// unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
// {
// 	unsigned int	i;
// 	unsigned int	x;

// 	i = 0;
// 	x = 0;
// 	while (src[x] != '\0')
// 		x++;
// 	if (size > 0)
// 	{
// 		while ((src[i] != '\0') && (i < size - 1))
// 		{
// 			dest[i] = src[i];
// 			i++;
// 		}
// 		dest[i] = '\0';
// 	}
// 	return (x);
// }


// int	main(void)
// {
// 	char **env;

// 	env = malloc(sizeof(char*) * 4);
// 	env[3] = NULL;
// 	if(!env)
// 		printf("Malloc Error\n");

// 	int i = -1;
// 	while (++i < 3)
// 	{
// 		env[i] = malloc(sizeof(char) * 5);
// 		// if (i == 2)
// 		// 	env[i] = NULL;
// 		if (i % 2)
// 			ft_strlcpy(env[i], "Hell", 5);
// 			// env[i] = "Hell";
// 		else
// 			ft_strlcpy(env[i], "Hola", 5);
// 			// env[i] = "Hola";
// 	}
// 	i = -1;
// 	while (++i < 3)
// 		printf("Before env[%d] = %s ----> %p\n", i, env[i], &env[i]);

// 	// env[1] = NULL;
// 	free(env[1]);
// 	env[1] = malloc(sizeof(char) * 10);
// 	ft_strlcpy(env[1], "ErrorArgv", 10);
// 	// env[1] = "ErrorArgv\0";
// 	i = -1;
// 	while (env[++i])
// 		printf("After env[%d] = %s ---> %p\n", i, env[i], &env[i]);
// 	// env[0] = NULL;
// 	// free(env[0]);
// 	i = 0;
// 	while (env[i])
// 	{
// 		free(env[i]);
// 		i++;
// 	}
// 	free(env);
// 	return (0);
// }

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


void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	main(int ac, char **av)
{
	char	**str;
	int		i = -1;

	ft_swap(&av[1], &av[2]);
	ft_swap(&av[3], &av[4]);

	str = ft_strdup2(av);
	while (str[++i])
		printf("str[%d] = %s\n", i, str[i]);
	return (0);
}
