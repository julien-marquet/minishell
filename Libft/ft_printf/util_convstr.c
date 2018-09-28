/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util_convstr.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/01 23:00:16 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 21:04:42 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*intmax_convstr(intmax_t nbr, size_t *size)
{
	char	*str;
	size_t	i;

	i = getstrsize_intmax(nbr) - 1;
	*size = i + 1;
	if ((str = ft_memalloc(i + 2)) == NULL)
		return (NULL);
	str[i + 1] = '\0';
	handle_awkward_int(&nbr, &str, &i);
	while (nbr > 9)
	{
		str[i--] = (char)(48 + nbr % 10);
		nbr = nbr / 10;
	}
	str[i] = (char)(48 + nbr % 10);
	return (str);
}

char	*uintmax_convstr(uintmax_t nbr, size_t *size)
{
	char	*str;
	size_t	i;

	i = getstrsize_uintmax(nbr) - 1;
	*size = i + 1;
	if ((str = ft_memalloc(i + 2)) == NULL)
		return (NULL);
	str[i + 1] = '\0';
	while (nbr > 9)
	{
		str[i--] = (char)(48 + nbr % 10);
		nbr = nbr / 10;
	}
	str[i] = (char)(48 + nbr % 10);
	return (str);
}

char	*ouintmax_convstr(uintmax_t nbr, size_t *size)
{
	char	*str;
	size_t	i;

	*size = getstrsize_ouintmax(nbr);
	if ((str = (char*)malloc(*size + 1)) == NULL)
		return (NULL);
	str[*size] = '\0';
	i = 0;
	while (nbr > 7)
	{
		str[*size - i - 1] = (char)(48 + nbr % 8);
		nbr /= 8;
		i++;
	}
	str[0] = (char)(48 + nbr);
	return (str);
}

char	*xuintmax_convstr(uintmax_t nbr, size_t *size, int ismaj)
{
	char	*str;
	size_t	i;
	char	pool[17];

	if (ismaj)
		ft_strcpy(pool, "0123456789ABCDEF");
	else
		ft_strcpy(pool, "0123456789abcdef");
	*size = getstrsize_xuintmax(nbr);
	if ((str = (char*)malloc(*size + 1)) == NULL)
		return (NULL);
	str[*size] = '\0';
	i = 0;
	while (nbr > 15)
	{
		str[*size - i - 1] = pool[(unsigned char)(nbr % 16)];
		nbr /= 16;
		i++;
	}
	str[0] = pool[(unsigned char)nbr];
	return (str);
}

char	*voidp_convstr(void *buffer, size_t *size)
{
	char	*str;
	size_t	i;
	char	pool[17];
	long	cast;

	cast = (long)buffer;
	ft_strcpy(pool, "0123456789abcdef");
	*size = getstrsize_voidp(cast);
	if ((str = (char*)malloc(*size + 1)) == NULL)
		return (NULL);
	str[*size] = '\0';
	i = 0;
	while (cast > 15)
	{
		str[*size - i - 1] = pool[(unsigned char)(cast % 16)];
		cast /= 16;
		i++;
	}
	str[0] = pool[(unsigned char)cast];
	return (str);
}
