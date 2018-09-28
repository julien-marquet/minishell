/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:28:52 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 18:28:52 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	index;

	if (!s)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	index = 0;
	while (index < len)
	{
		new[index] = s[start + index];
		index++;
	}
	new[index] = '\0';
	return (new);
}
