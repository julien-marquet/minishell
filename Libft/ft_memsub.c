/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:28:52 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/05 03:47:51 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memsub(void const *b, unsigned int start, size_t len)
{
	char			*new;
	const char		*src;
	unsigned int	index;

	src = b;
	if (!b)
		return (NULL);
	if (!(new = (void*)malloc(len)))
		return (NULL);
	index = 0;
	while (index < len)
	{
		new[index] = src[start + index];
		index++;
	}
	return (new);
}
