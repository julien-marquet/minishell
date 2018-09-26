/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins_unsetenv.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 20:32:46 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/26 21:54:32 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static int	shift_env(char **env)
{
	size_t	i;

	i = 0;
	while (env[i] != NULL)
	{
		env[i] = env[i + 1];
		i++;
	}
	return (0);
}

static int	remove_line(char *token, char **env)
{
	size_t	i;
	size_t	j;
	char	*err;

	i = 0;
	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] != '\0')
		{
			if (env[i][j] == '=')
				return (shift_env(&(env[i])));
			else if (token[j] != env[i][j])
				break ;
			j++;
		}
		i++;
	}
	return (0);
}

int			builtins_unsetenv(char **tokens, char **env)
{
	size_t	i;
	int		status;

	status = 0;
	i = 1;
	if (tokens[1] == NULL)
		return (setenv_handle_err("unsetenv", "Too few arguments"));
	else
	{
		while (tokens[i] != NULL)
		{
			status |= remove_line(tokens[i], env);
			i++;
		}
	}
	return (status);
}
