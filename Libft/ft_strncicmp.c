/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncicmp.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:28:49 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 18:28:49 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncicmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	d;
	size_t			i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		d = ft_tolower(s1[i]) - ft_tolower(s2[i]);
		if (d != 0)
			return (d);
		i++;
	}
	return (0);
}
