/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:28:48 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 13:27:05 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	global;
	char			*new;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	global = len1 + len2;
	if (!(new = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (NULL);
	len2 = 0;
	while (len2 < len1)
	{
		new[len2] = s1[len2];
		len2++;
	}
	len2 = 0;
	while (len1 < global)
		new[len1++] = s2[len2++];
	new[len1] = '\0';
	return (new);
}
