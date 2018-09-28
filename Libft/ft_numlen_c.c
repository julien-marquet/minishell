/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_numlen_c.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/05 13:18:40 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/11 16:49:25 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

size_t	ft_numlen_c(char num)
{
	size_t	cpt;

	cpt = 1;
	if (num == CHAR_MIN)
		return (4);
	if (num < 0)
	{
		cpt = 2;
		num = -num;
	}
	while (num > 9)
	{
		cpt++;
		num /= 10;
	}
	return (cpt);
}
