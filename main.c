/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/18 16:45:54 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 15:53:33 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char	**duplicate_env(char **env)
{
	size_t	len;
	char	**tmp;

	while (env[len] != NULL)
		len++;
	if ((tmp = (char**)malloc((len  + 1) * sizeof(char*))) == NULL)
		return (NULL);
	tmp[len] = NULL;
	len = 0;
	while (env[len] != NULL)
	{
		if ((tmp[len] = ft_strdup(env[len])) == NULL)
		{
			while (len > 0)
			{
				len--;
				ft_strdel(&(tmp[len]));
			}
			free(tmp);
			return (NULL);
		}
		len++;
	}
	env = tmp;
	return (env);
}

int		main(int ac, char **av, char **env)
{
	char	buf[BUF_SIZE + 1];
	ssize_t ret;
	char	**tokens;

	if ((env = duplicate_env(env)) == NULL)
		return (1);
	while (1)
	{
		ret = read(0, buf, BUF_SIZE);
		if (ret == -1)
			return (1);
		buf[ret] = '\0';
		if ((tokens = allocate_tokens(count_tokens(buf))) == NULL)
			return (1);
		if (parse_input(buf, tokens, env) != 0)
			return (1);
		if (dispatch_commands(tokens, env) != 0)
			return (1);
	}
	return (0);
}
/*
	Bash provides several ways to manipulate the environment.

	On invocation, the shell scans its own environment and creates a parameter for each name found, automatically marking it for export to child processes.

	Executed commands inherit the environment.

	The export and ‘declare -x’ commands allow parameters and functions to be added to and deleted from the environment.

	If the value of a parameter in the environment is modified, the new value becomes part of the environment, replacing the old.

	The environment inherited by any executed command consists of the shell’s initial environment, whose values may be modified in the shell,
	less any pairs removed by the unset and ‘export -n’ commands, plus any additions via the export and ‘declare -x’ commands.
*/