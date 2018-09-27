/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins_setenv.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 16:30:42 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/27 16:35:01 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			builtins_setenv(char **tokens, char ***env)
{
	size_t	i;
	char	*err;

	i = 1;
	while (tokens[i] != NULL)
		i++;
	if (i == 1)
		return (builtins_env(tokens, *env));
	else if (i > 3)
		return (setenv_handle_err("setenv", "Too many arguments"));
	if (!setenv_is_valid(tokens[1]))
	{
		return (setenv_handle_err("setenv",
	"Variable name must contain alphanumeric characters"));
	}
	return (sh_setenv(tokens[1], tokens[2], env));
}
