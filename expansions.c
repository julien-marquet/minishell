/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   expansions.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/19 15:58:37 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/20 21:19:20 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			expand_dol(char **token, size_t *i, char **env, char *start)
{
	size_t	j;

	j = 0;
	while (start[j] && start[j] != '\'' && start[j] != '$' && start[j] != '~')
		j++;
	if (j == 0)
		return (dol_handle_empty(token, i));
	else
		return (dol_handle_full(token, i, env, j));
}

int			expand_tild(char **token, size_t *i, char **env, char *start)
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
		ft_strcpy(&(tmp[*i]), var_env);
		ft_strcpy(&(tmp[*i + len]), &((*token)[*i + 1]));
		ft_strdel(token);
		*token = tmp;
	}
	else
		*i += 1;
	return (0);
}
