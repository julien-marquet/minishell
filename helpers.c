/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   helpers.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/18 18:11:33 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/27 23:33:59 by jmarquet    ###    #+. /#+    ###.fr     */
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

int		file_exist(char *filename)
{
	struct stat	buffer;

	if (stat(filename, &buffer) != 0)
		return (0);
	return (S_ISREG(buffer.st_mode) != 0);
}
