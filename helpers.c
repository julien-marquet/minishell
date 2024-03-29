/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   helpers.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/18 18:11:33 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 17:15:00 by jmarquet    ###    #+. /#+    ###.fr     */
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

int		shift_empty_array(char **tokens)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (tokens[i] != NULL)
	{
		if (ft_strlen(tokens[i]) == 0)
		{
			j = 0;
			ft_strdel(&(tokens[i]));
			while (tokens[i + j + 1] != NULL)
			{
				tokens[i + j] = tokens[i + j + 1];
				j++;
			}
			tokens[i + j] = NULL;
		}
		i++;
	}
	return (0);
}

void	remove_quotes(char **token)
{
	size_t	i;

	i = 0;
	while ((*token)[i])
	{
		if ((*token)[i] == '\'')
		{
			if ((*token)[i + 1] == '\0')
				(*token)[i] = '\0';
			else
				ft_strcpy(&((*token)[i]), &((*token)[i + 1]));
		}
		else
			i++;
	}
}
