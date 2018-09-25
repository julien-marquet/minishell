/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dispatcher.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/21 15:11:43 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 16:53:18 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		search_builtins(char **token, char **env)
{
	if (ft_strcmp(*token, "echo") == 0 ||
	ft_strcmp(*token, "cd") == 0 ||
	ft_strcmp(*token, "setenv") == 0 ||
	ft_strcmp(*token, "unsetenv") == 0 ||
	ft_strcmp(*token, "env") == 0 ||
	ft_strcmp(*token, "exit") == 0)
	{
		if (exec_builtins(token, env) == 0)
			return (1);
		else
			return (-1);
	}
	return (0);
}

int		search_envpath(char **token, char **env)
{
	ft_printf("Search in env path\n");
	return (0);
}

int		search_usrpath(char **token, char **env)
{
	ft_printf("Search in usr path\n");
	return (0);
}

int		dispatch_commands(char **tokens, char **env)
{
	int		res;
	size_t	i;

	i = 0;
	ft_printf("tokens : \n");
	while (tokens[i] != NULL)
	{
		ft_printf("%s\n", tokens[i]);
		i++;
	}
	res = search_builtins(tokens, env);
	if (res != 0)
		return (res);
	if (ft_strchr(*tokens, '/') == NULL)
		return (search_envpath(tokens, env));
	else
		return (search_usrpath(tokens, env));
}
