/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins_setenv.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 16:30:42 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/26 16:34:37 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		builtins_setenv(char **tokens, char **env, char *err)
{
	size_t	i;

	i = 0;
	while (env[i] != NULL)
	{
		i++;
	}
	return (0);
}
