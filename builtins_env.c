/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins_env.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 16:22:43 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/26 16:29:05 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		builtins_env(char **tokens, char **env, char *err)
{
	size_t	i;

	i = 0;
	while (env[i] != NULL)
	{
		ft_putendl(env[i]);
		i++;
	}
	return (0);
}
