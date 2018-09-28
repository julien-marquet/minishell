/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:28:44 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 18:28:44 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	nl;

	nl = (long)n;
	if (nl < 0)
	{
		ft_putchar('-');
		nl = -nl;
	}
	if (nl > 9)
	{
		ft_putnbr((int)(nl / 10));
		ft_putchar((char)(48 + nl % 10));
	}
	else
		ft_putchar((char)(48 + nl));
}
