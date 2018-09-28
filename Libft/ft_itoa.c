/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:28:38 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 18:28:38 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_handle_negative(long *n, long *tmp_n, int *negative)
{
	if (*n < 0)
	{
		*negative = 1;
		*n = -(*n);
	}
	else
		*negative = 0;
	*tmp_n = *n;
}

char		*ft_itoa(int n)
{
	long			tmp_n;
	int				size;
	char			*new;
	int				negative;
	long			nl;

	nl = (long)n;
	ft_handle_negative(&nl, &tmp_n, &negative);
	size = 1;
	while (tmp_n > 9)
	{
		tmp_n /= 10;
		size++;
	}
	if (!(new = (char *)malloc(size + 1 + negative)))
		return (NULL);
	new[0] = '-';
	new[size + negative] = '\0';
	while (nl > 9)
	{
		new[--size + negative] = '0' + nl % 10;
		nl /= 10;
	}
	new[--size + negative] = '0' + nl;
	return (new);
}
