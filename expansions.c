/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   expansions.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/19 15:58:37 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 03:18:53 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static int		expand_dol(char **token, size_t *i, char **env, char *start)
{
	size_t	j;

	j = 0;
	while (start[j] && (ft_isalnum(start[j]) || start[j] == '_') &&
start[j] != '\'' && start[j] != '$' && start[j] != '~')
		j++;
	if (j == 0)
		return (dol_handle_empty(token, i));
	else
		return (dol_handle_full(token, i, env, j));
}

static int		expand_tild(char **token, size_t *i, char **env, char *start)
{
	char	*var_env;
	char	*tmp;
	size_t	len;

	if (*start == '/' || !(*start))
	{
		var_env = ft_getenv("HOME", env);
		len = var_env == NULL ? 0 : ft_strlen(var_env);
		if ((tmp = malloc(ft_strlen(*token) + len)) == NULL)
			return (1);
		ft_strncpy(tmp, *token, *i);
		if (var_env != NULL)
			ft_strcpy(&(tmp[*i]), var_env);
		ft_strcpy(&(tmp[*i + len]), &((*token)[*i + 1]));
		ft_strdel(token);
		*token = tmp;
	}
	else
		*i += 1;
	return (0);
}

int				apply_expansion(char **token, char **env)
{
	size_t	i;

	i = 0;
	while ((*token)[i] != '\0')
	{
		if ((*token)[i] == '$')
		{
			if (expand_dol(token, &i, env, &((*token)[i + 1])) != 0)
				return (1);
		}
		else if ((*token)[i] == '~' && i == 0)
		{
			if (expand_tild(token, &i, env, &((*token)[i + 1])) != 0)
				return (1);
		}
		else
			i++;
	}
	return (0);
}
