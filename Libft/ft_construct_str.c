/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_construct_str.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/27 19:28:53 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/27 23:49:49 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(size_t n, va_list ap)
{
	size_t		i;
	char		*tmp;
	size_t		len;
	va_list		apc;

	i = 0;
	len = 0;
	va_copy(apc, ap);
	while (i < n)
	{
		tmp = va_arg(apc, char*);
		if (tmp != NULL)
			len += ft_strlen(tmp);
		i++;
	}
	va_end(apc);
	return (len);
}

static char		*chain_concat(size_t n, char *str, va_list ap)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	i = 0;
	len = 0;
	while (i < n)
	{
		tmp = va_arg(ap, char*);
		if (tmp != NULL)
		{
			ft_strcpy(&(str[len]), tmp);
			len += ft_strlen(tmp);
		}
		i++;
	}
	return (str);
}

char			*ft_construct_str(size_t n, ...)
{
	size_t		i;
	va_list		ap;
	char		*str;
	size_t		len;

	str = NULL;
	i = 0;
	va_start(ap, n);
	len = get_size(n, ap);
	if ((str = malloc(len + 1)) == NULL)
		return (NULL);
	chain_concat(n, str, ap);
	va_end(ap);
	return (str);
}
