/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memprepend.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/22 22:12:00 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 22:12:01 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memprepend(const void *str, size_t str_size,
		const void *pre, size_t pre_size)
{
	char		*res;
	const char	*strcast;
	const char	*precast;
	size_t		i;

	if (!str || !pre || (res = ft_memalloc(str_size + pre_size)) == NULL)
		return (NULL);
	i = 0;
	strcast = (const char*)str;
	precast = (const char*)pre;
	while (i < pre_size)
	{
		res[i] = precast[i];
		i++;
	}
	i = 0;
	while (i < str_size)
	{
		res[i + pre_size] = strcast[i];
		i++;
	}
	return (res);
}
