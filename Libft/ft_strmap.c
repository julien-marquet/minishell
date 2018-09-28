/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:28:48 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 18:28:48 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*new;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (!(new = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	new[i] = '\0';
	while (i > 0)
	{
		i--;
		new[i] = (*f)(s[i]);
	}
	return (new);
}
