/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 16:29:18 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 05:31:14 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		exec_builtins(char **token, char ***env, char **err, int *status)
{
	if (ft_strcmp(*token, "echo") == 0)
		*status = builtins_echo(token);
	else if (ft_strcmp(*token, "env") == 0)
		*status = builtins_env(*env);
	else if (ft_strcmp(*token, "setenv") == 0)
		*status = builtins_setenv(token, env, err);
	else if (ft_strcmp(*token, "unsetenv") == 0)
		*status = builtins_unsetenv(token, *env, err);
	else if (ft_strcmp(*token, "cd") == 0)
		*status = builtins_cd(token, env, err);
	else if (ft_strcmp(*token, "exit") == 0)
		return (-1);
	return (0);
}

int		exec_file(char **token, char **env, char **err, int *status)
{
	pid_t	pid;
	int		stat_loc;
	int		valid;

	valid = file_exist(*token);
	if (valid == -1)
		*err = ft_construct_str(3, *token, ": ", "is a directory.");
	else if (access(*token, X_OK) != 0)
		*err = ft_construct_str(3, *token, ": ", "Permission denied");
	else
	{
		pid = fork();
		if (pid == 0)
			execve(*token, token, env);
		else
		{
			waitpid(pid, &stat_loc, WUNTRACED);
			*status = WEXITSTATUS(stat_loc);
		}
	}
	return (0);
}
