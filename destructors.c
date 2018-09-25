/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   destructors.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/18 18:17:13 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 19:57:27 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void	free_array_str(char **arr)
{
	size_t	i;

	i = 0;
	if (arr)
	{
		while (arr[i] != NULL)
		{
			free(arr[i]);
			arr[i] = NULL;
			i++;
		}
		free(arr);
		arr = NULL;
	}
}
