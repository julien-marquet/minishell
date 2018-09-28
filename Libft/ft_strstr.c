/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:28:52 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/20 14:44:52 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	len;
	char			*spos;

	spos = NULL;
	i = 0;
	len = ft_strlen(needle);
	if (haystack[0] == '\0')
		return (needle[0] == '\0' ? (char *)haystack : NULL);
	while (haystack[i])
	{
		if (ft_strnequ(&haystack[i], needle, len))
			return ((char *)&haystack[i]);
		i++;
	}
	return (spos);
}
