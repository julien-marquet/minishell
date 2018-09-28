/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins_env.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 16:22:43 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 05:31:02 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		builtins_env(char **env)
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
