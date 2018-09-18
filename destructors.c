/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   destructors.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/18 18:17:13 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/18 18:21:03 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(char **tokens)
{
	size_t	i;

	i = 0;
	if (tokens)
	{
		while (tokens[i] != NULL)
		{
			free(tokens[i]);
			i++;
		}
		free(tokens);
	}
}
