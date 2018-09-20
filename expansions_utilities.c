/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   expansions_utilities.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/20 18:53:06 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/20 22:00:08 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static void	free_rem_str(char **s1, char **s2)
{
	ft_strdel(s1);
	ft_strdel(s2);
}

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

int			dol_handle_full(char **token, size_t *i, char **env, size_t j)
{
	char	*buf;
	char	*var_env;
	size_t	token_size;

	if ((buf = ft_strndup(&((*token)[*i + 1]), j)) == NULL)
		return (1);
	var_env = ft_getenv(buf, env);
	if (var_env != NULL)
		token_size = ft_strlen(*token) - 1 - j + ft_strlen(var_env);
	else
		token_size = ft_strlen(*token) - 1 - j;
	ft_strdel(&(buf));
	if ((buf = (char *)malloc(token_size + 1)) == NULL)
		return (1);
	ft_strncpy(buf, *token, *i);
	ft_strcpy(&(buf[*i]), var_env);
	ft_strcpy(&(buf[*i + ft_strlen(var_env)]), &((*token)[*i + j + 1]));
	buf[token_size] = '\0';
	if (var_env == NULL)
		*i = *i == 0 ? 0 : *i - 1;
	else
		*i = *i == 0 ? ft_strlen(var_env) : *i + ft_strlen(var_env);
	free_rem_str(token, &var_env);
	*token = buf;
	return (0);
}
