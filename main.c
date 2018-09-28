/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/18 16:45:54 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 05:25:16 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static void		handle_error(char **err)
{
	if (*err != NULL)
	{
		ft_putstr_fd("-minishell: ", 2);
		ft_putendl_fd(*err, 2);
		ft_strdel(err);
	}
}

static int		handle_input(char **tokens, int *status, char ***env)
{
	char	buf[BUF_SIZE + 1];
	ssize_t ret;
	int		sig_exit;
	char	*err;

	err = NULL;
	ft_putstr("$> ");
	ret = read(0, buf, BUF_SIZE);
	if (ret == -1)
		return (1);
	buf[ret] = '\0';
	if ((tokens = allocate_tokens(count_tokens(buf))) == NULL)
		return (1);
	if (parse_input(buf, tokens, *env) != 0)
		return (1);
	sig_exit = dispatch_commands(tokens, env, &err, status);
	free_array_str(tokens);
	handle_error(&err);
	return (sig_exit);
}

int				main(int ac, char **av, char **env)
{
	char	**tokens;
	int		status;
	int		sig_exit;

	ac = av[0][0];
	status = 0;
	if ((env = duplicate_env(env)) == NULL)
		return (1);
	while (1)
	{
		sig_exit = handle_input(tokens, &status, &env);
		if (sig_exit == 1)
			status = 1;
		if (sig_exit != 0)
			break ;
	}
	freedom(env);
	return (status);
}
