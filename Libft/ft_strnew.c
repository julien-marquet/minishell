/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:28:51 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 18:28:51 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char		*new;
	size_t		i;

	if (!(new = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = -1;
	while (++i < size + 1)
		new[i] = '\0';
	return (new);
}
