/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:28:50 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 18:32:25 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*new;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	len = len > n ? n : len;
	if (!(new = (char*)malloc(len + 1)))
		return (0);
	i = 0;
	while (i < len)
	{
		new[i] = (char)s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
