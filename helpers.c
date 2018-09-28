/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   helpers.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/18 18:11:33 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 02:57:26 by jmarquet    ###    #+. /#+    ###.fr     */
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
	struct stat buffer;

	if (stat(filename, &buffer) != 0)
		return (0);
	if (S_ISDIR(buffer.st_mode) != 0)
		return (-1);
	return (1);
}
