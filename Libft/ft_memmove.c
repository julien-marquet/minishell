/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:28:42 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 18:28:42 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*p_dest;
	const char		*p_src;

	p_dest = (char*)dst;
	p_src = (const char*)src;
	if (p_src <= p_dest)
	{
		p_dest += len - 1;
		p_src += len - 1;
		while (len--)
			*p_dest-- = *p_src--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
