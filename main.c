/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/18 16:45:54 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 01:14:43 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void	handle_error(char **err)
{
	if (*err != NULL)
	{
		ft_putstr_fd("-minishell: ", 2);
		ft_putendl_fd(*err, 2);
		ft_strdel(err);
	}
}

int		main(int ac, char **av, char **env)
{
	char	buf[BUF_SIZE + 1];
	ssize_t ret;
	char	**tokens;
	char	*err;
	int		status;
	int		sig_exit;

	status = 0;
	err = NULL;
	if ((env = duplicate_env(env)) == NULL)
		return (1);
	while (1)
	{
		ft_putstr("$> ");
		ret = read(0, buf, BUF_SIZE);
		if (ret == -1)
			return (1);
		buf[ret] = '\0';
		if ((tokens = allocate_tokens(count_tokens(buf))) == NULL)
			return (1);
		if (parse_input(buf, tokens, env) != 0)
			return (1);
		sig_exit = dispatch_commands(tokens, &env, &err, &status);
		if (sig_exit == -1)
			return (status);
		else if (sig_exit != 0)
			return (1);
		handle_error(&err);
	}
	return (status);
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