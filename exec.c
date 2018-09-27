/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 16:29:18 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/27 16:40:00 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		exec_builtins(char **token, char ***env, char **err)
{
	if (ft_strcmp(*token, "echo") == 0)
		builtins_echo(token, *env);
	else if (ft_strcmp(*token, "env") == 0)
		builtins_env(token, *env);
	else if (ft_strcmp(*token, "setenv") == 0)
		builtins_setenv(token, env);
	else if (ft_strcmp(*token, "unsetenv") == 0)
		builtins_unsetenv(token, *env);
	else if (ft_strcmp(*token, "cd") == 0)
		builtins_cd(token, env);
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
