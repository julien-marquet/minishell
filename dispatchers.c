/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dispatcher.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/21 15:11:43 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 18:18:21 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		dispatch_commands(char **tokens, char **env, char **err)
{
	int		res;
	size_t	i;

	i = 0;
	ft_printf("tokens : \n");
	while (tokens[i] != NULL)
	{
		ft_printf("%s\n", tokens[i]);
		i++;
	}
	if (ft_strchr(*tokens, '/') == NULL)
	{
		res = search_builtins(tokens, env, err);
		if (res != 0)
			return (res);
		return (search_envpath(tokens, env, err));
	}
	else
		return (search_usrpath(tokens, env, err));
}
