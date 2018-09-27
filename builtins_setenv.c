/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins_setenv.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 16:30:42 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/27 23:50:48 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			builtins_setenv(char **tokens, char ***env, char **err)
{
	size_t	i;

	i = 1;
	while (tokens[i] != NULL)
		i++;
	if (i == 1)
		return (builtins_env(tokens, *env));
	else if (i > 3)
	{
		*err = ft_construct_str(2, "setenv: ", "Too many arguments.");
		return (1);
	}
	if (!setenv_is_valid(tokens[1]))
	{
		*err = ft_construct_str(2, "setenv: ",
	"Variable name must contain alphanumeric characters.");
		return (1);
	}
	return (sh_setenv(tokens[1], tokens[2], env));
}
