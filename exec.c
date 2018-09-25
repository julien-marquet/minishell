/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 16:29:18 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 21:53:35 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		exec_builtins(char **token, char **env, char **err)
{
	ft_printf("Exec builtins\n");
	return (0);
}

int		exec_file(char **token, char **env, char **err)
{
	pid_t	pid;
	int		stat_loc;

	ft_printf("Exec file\n");
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
			ft_printf("Child\n");
			execve(*token, token, env);
		}
		else
		{
			waitpid(pid, &stat_loc, WUNTRACED);
			ft_printf("Child terminated with status %d\n", stat_loc);
		}
	}
	return (0);
}
