/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strswapfree.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 11:04:17 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/20 15:05:51 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_strswapfree(char **buffer, char *str)
{
	char	*tmp;

	if (buffer == NULL || *buffer == NULL || str == NULL)
		return (0);
	tmp = *buffer;
	*buffer = str;
	free(tmp);
	return (1);
}
