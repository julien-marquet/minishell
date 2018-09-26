/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   helpers.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/18 18:11:33 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/26 15:15:00 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		is_metachar(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char	*construct_error(const char *target, const char *error)
{
	size_t	lent;
	size_t	lene;
	char	*res;

	lent = ft_strlen(target);
	lene = ft_strlen(error);
	if ((res = malloc(lent + lene + 3)) == NULL)
		return (NULL);
	ft_strcpy(res, target);
	ft_strcpy(&(res[lent]), ": ");
	ft_strcpy(&(res[lent + 2]), error);
	return (res);
}

int		file_exist(char *filename)
{
	struct stat	buffer;

	if (stat(filename, &buffer) != 0)
		return (0);
	return (S_ISREG(buffer.st_mode) != 0);
}
