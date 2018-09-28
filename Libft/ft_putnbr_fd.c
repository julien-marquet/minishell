/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:28:44 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 18:28:44 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nl;

	nl = (long)n;
	if (nl < 0)
	{
		ft_putchar_fd('-', fd);
		nl = -nl;
	}
	if (nl > 9)
	{
		ft_putnbr_fd((int)(nl / 10), fd);
		ft_putchar_fd((char)(48 + nl % 10), fd);
	}
	else
		ft_putchar_fd((char)(48 + nl), fd);
}
