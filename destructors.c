/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   destructors.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/18 18:17:13 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 04:00:49 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void	freedom(char **env)
{
	free_array_str(env);
}

void	free_array_str(char **arr)
{
	size_t	i;

	if (arr != NULL)
	{
		i = 0;
		while (arr[i] != NULL)
		{
			ft_strdel(&(arr[i]));
			++i;
		}
		free(arr);
		arr = NULL;
	}
}
