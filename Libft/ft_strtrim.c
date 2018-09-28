/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
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

char	*ft_strtrim(char const *s)
{
	unsigned int	len;
	char			*new;
	unsigned int	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (*s != '\0' && (*s == ' ' || *s == '\n' || *s == '\t'))
	{
		len--;
		s++;
	}
	while (len > 0 && s[len - 1] != '\0' && (s[len - 1] == ' ' ||
		s[len - 1] == '\n' || s[len - 1] == '\t'))
		len--;
	if (!(new = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
