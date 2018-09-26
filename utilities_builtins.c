/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utilities_builtins.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 20:13:57 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/26 20:19:17 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		setenv_is_valid(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

int		setenv_handle_err(const char *target, const char *error)
{
	char	*err;

	if (!(err = construct_error(target, error)))
		return (1);
	ft_putendl_fd(err, 2);
	ft_strdel(&err);
	return (1);
}
