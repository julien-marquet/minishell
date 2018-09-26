/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dispatchers.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/21 15:11:43 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/26 18:03:23 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		dispatch_commands(char **tokens, char ***env, char **err)
{
	int		res;
	size_t	i;

	i = 0;
	if (*tokens != NULL)
	{
		if (ft_strchr(*tokens, '/') == NULL)
		{
			res = search_builtins(tokens, env, err);
			if (res != 0)
				return (res == 1 ? 0 : res);
			return (search_envpath(tokens, *env, err));
		}
		else
			return (search_usrpath(tokens, *env, err));
	}
	return (0);
}
