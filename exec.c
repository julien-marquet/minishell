/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 16:29:18 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/26 16:30:26 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		exec_builtins(char **token, char **env, char **err)
{
	if (ft_strcmp(*token, "echo") == 0)
		return (builtins_echo(token, env, err));
	else if (ft_strcmp(*token, "env") == 0)
		return (builtins_env(token, env, err));
	else if (ft_strcmp(*token, "setenv") == 0)
		return (builtins_setenv(token, env, err));
	return (0);
}

int		exec_file(char **token, char **env, char **err)
{
	pid_t	pid;
	int		stat_loc;

	if (access(*token, X_OK) != 0)
	{
		if ((*err = construct_error(*token, "Permission denied")) == NULL)
			return (1);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			execve(*token, token, env);
		}
		else
		{
			waitpid(pid, &stat_loc, WUNTRACED);
		}
	}
	return (0);
}
