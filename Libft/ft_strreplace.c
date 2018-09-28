/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strreplace.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 19:00:38 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/23 19:47:21 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_strreplace(char **str, char replaced, char new)
{
	int		i;

	if (!str || !*str)
		return ;
	i = 0;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == replaced)
			(*str)[i] = new;
		i++;
	}
}
