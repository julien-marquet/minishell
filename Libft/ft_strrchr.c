/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:28:51 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 18:28:51 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*spos;

	spos = NULL;
	i = 0;
	while (s[i] != '\0' || c == '\0')
	{
		if (s[i] == (char)c)
			spos = (char*)&s[i];
		if (s[i] == '\0')
			return (spos);
		i++;
	}
	return (spos);
}
