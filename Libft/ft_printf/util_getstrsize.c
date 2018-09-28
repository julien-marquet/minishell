/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util_getstrsize.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/01 22:58:24 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/09 22:17:44 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	getstrsize_intmax(intmax_t nbr)
{
	size_t	i;

	i = 1;
	if (nbr == -9223372036854775807 - 1)
		return (20);
	else if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

size_t	getstrsize_ouintmax(uintmax_t nbr)
{
	size_t	size;

	size = 1;
	while (nbr > 7)
	{
		nbr /= 8;
		size++;
	}
	return (size);
}

size_t	getstrsize_uintmax(uintmax_t nbr)
{
	size_t	i;

	i = 1;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

size_t	getstrsize_xuintmax(uintmax_t nbr)
{
	size_t	size;

	size = 1;
	while (nbr > 15)
	{
		nbr /= 16;
		size++;
	}
	return (size);
}

size_t	getstrsize_voidp(long nbr)
{
	size_t	size;

	size = 1;
	while (nbr > 15)
	{
		nbr /= 16;
		size++;
	}
	return (size);
}
