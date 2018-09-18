/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   allocators.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/18 18:12:51 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/18 18:19:50 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char	**allocate_tokens(size_t ntoken)
{
	char	**res;

	if ((res = malloc(sizeof(char*) * (++ntoken))) == NULL)
		return (NULL);
	while (ntoken != 0)
	{
		res[ntoken - 1] = NULL;
		ntoken--;
	}
	return (res);
}
