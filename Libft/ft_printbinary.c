/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printbinary.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/01 21:18:30 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/29 20:45:03 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_printbinary(void *buffer, size_t size)
{
	size_t		i;
	char		mask;
	char		*cast;
	char		*cpy;

	mask = (char)128;
	cast = (char*)buffer;
	if ((cpy = malloc(size)) == NULL)
		return (0);
	cpy = ft_memcpy(cpy, cast, size);
	i = size * 8 - 1;
	while (i > 0)
	{
		if ((cpy[i / 8] & mask) == mask)
			ft_putchar('1');
		else
			ft_putchar('0');
		cpy[i / 8] = cpy[i / 8] << 1;
		i--;
	}
	free(cpy);
	return (1);
}
