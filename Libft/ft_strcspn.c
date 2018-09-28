/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcspn.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/24 10:30:45 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 11:56:48 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	si;
	size_t	ri;

	if (!s || !reject)
		return (0);
	si = 0;
	while (s[si] != '\0')
	{
		ri = 0;
		while (reject[ri] != '\0')
		{
			if (s[si] == reject[ri])
				return (si);
			ri++;
		}
		si++;
	}
	return (si);
}
