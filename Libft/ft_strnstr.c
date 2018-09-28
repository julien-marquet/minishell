/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:28:51 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 18:28:51 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	length;
	char			*spos;

	spos = NULL;
	i = 0;
	length = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (haystack[0] == '\0')
		return (needle[0] == '\0' ? (char *)haystack : NULL);
	while (haystack[i] && i + length - 1 < len)
	{
		if (ft_strnequ(&haystack[i], needle, length))
			return ((char *)&haystack[i]);
		i++;
	}
	return (spos);
}
