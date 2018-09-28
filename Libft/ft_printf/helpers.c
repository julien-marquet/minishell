/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   helpers.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 17:36:41 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 20:31:37 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		secure_char_prepend(char **res, t_utilities *utilities, char *insert)
{
	char	*tmp;

	tmp = NULL;
	if ((tmp = ft_memprepend(*res, utilities->content_size + 1,
insert, 1)) == NULL)
		return (0);
	ft_strdel(res);
	*res = tmp;
	utilities->content_size += 1;
	return (1);
}

int		create_empty(char **res, t_utilities *utilities)
{
	char	*tmp;

	if ((tmp = ft_strdup("")) == NULL)
		return (0);
	utilities->content_size = 0;
	free(*res);
	*res = tmp;
	return (1);
}

char	*create_null(t_utilities *utilities)
{
	char	*res;

	if ((res = ft_strdup("(null)")) == NULL)
		return (NULL);
	utilities->content_size = 6;
	return (res);
}
