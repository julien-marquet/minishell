/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/18 16:45:54 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 18:58:29 by jmarquet    ###    #+. /#+    ###.fr     */
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

static char		*handle_read(void)
{
	size_t	len;
	char	*tmp;
	ssize_t ret;
	char	buf[BUF_SIZE + 1];
	char	*res;

	res = NULL;
	ret = BUF_SIZE + 1;
	while (ret >= BUF_SIZE)
	{
		len = 0;
		ret = read(0, buf, BUF_SIZE);
		buf[ret] = '\0';
		if (ret == -1 || (tmp = ft_memalloc(len + ret + 1)) == NULL)
			return (NULL);
		if (ret == 0)
			break ;
		if (res != NULL)
			ft_strcpy(tmp, res);
		ft_strcpy(&(tmp[len]), buf);
		ft_strdel(&res);
		len += ret;
		res = tmp;
	}
	return (res);
}

static int		handle_input(char **tokens, int *status, char ***env)
{
	int		sig_exit;
	char	*err;
	char	*str;

	err = NULL;
	str = NULL;
	ft_putstr("$> ");
	if ((str = handle_read()) == NULL)
		return (1);
	if ((tokens = allocate_tokens(count_tokens(str))) == NULL)
		return (1);
	if (parse_input(str, tokens, *env) != 0)
		return (1);
	sig_exit = dispatch_commands(tokens, env, &err, status);
	free_array_str(tokens);
	handle_error(&err);
	ft_strdel(&str);
	return (sig_exit);
}

int				main(int ac, char **av, char **env)
{
	char	**tokens;
	int		status;
	int		sig_exit;

	tokens = NULL;
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
