/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:28:40 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 18:28:40 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*dest;
	const char	*source;

	dest = dst;
	source = src;
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		if ((unsigned char)c == ((unsigned char)source[i]))
			return ((void*)&dst[i + 1]);
		i++;
	}
	return (NULL);
}
