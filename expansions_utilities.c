/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   expansions_utilities.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/20 18:53:06 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 03:15:50 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			dol_handle_empty(char **token, size_t *i)
{
	size_t	token_size;
	char	*buf;

	token_size = ft_strlen(*token) - 1;
	if ((buf = (char *)malloc(token_size + 1)) == NULL)
		return (1);
	ft_strncpy(buf, *token, *i);
	ft_strcpy(&(buf[*i]), &((*token)[*i + 1]));
	buf[token_size] = '\0';
	ft_strdel(token);
	*token = buf;
	*i = *i == 0 ? 0 : *i;
	return (0);
}

static char	*handle_env_null(char **token, size_t *i, size_t j)
{
	size_t	token_size;
	char	*buf;

	token_size = ft_strlen(*token) - 1 - j;
	if ((buf = (char *)malloc(token_size + 1)) == NULL)
		return (NULL);
	ft_strncpy(buf, *token, *i);
	ft_strcpy(&(buf[*i]), &((*token)[*i + j + 1]));
	buf[token_size] = '\0';
	*i = *i == 0 ? 0 : *i - 1;
	return (buf);
}

static char	*handle_env_full(char **token, size_t *i, size_t j, char **var_env)
{
	size_t	token_size;
	char	*buf;
	size_t	len;

	len = ft_strlen(*var_env);
	token_size = ft_strlen(*token) - 1 - j + len;
	if ((buf = (char *)malloc(token_size + 1)) == NULL)
		return (NULL);
	ft_strncpy(buf, *token, *i);
	ft_strcpy(&(buf[*i]), *var_env);
	ft_strcpy(&(buf[*i + len]), &((*token)[*i + j + 1]));
	buf[token_size] = '\0';
	*i = *i == 0 ? len : *i + len;
	free(*var_env);
	return (buf);
}

int			dol_handle_full(char **token, size_t *i, char **env, size_t j)
{
	char	*buf;
	char	*var_env;

	if ((buf = ft_strndup(&((*token)[*i + 1]), j)) == NULL)
		return (1);
	var_env = ft_getenv(buf, env);
	ft_strdel(&(buf));
	if (var_env == NULL)
		buf = handle_env_null(token, i, j);
	else
		buf = handle_env_full(token, i, j, &var_env);
	ft_strdel(token);
	*token = buf;
	return (buf == NULL);
}
