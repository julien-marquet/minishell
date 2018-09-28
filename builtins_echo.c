/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins_echo.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 15:55:24 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 05:30:22 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		builtins_echo(char **tokens)
{
	size_t	i;

	i = 1;
	while (tokens[i] != NULL)
	{
		if (i != 1)
			ft_putchar(' ');
		ft_putstr(tokens[i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
