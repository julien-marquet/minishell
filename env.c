/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/19 16:07:57 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 19:54:10 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char	**duplicate_env(char **env)
{
	size_t	len;
	char	**tmp;

	while (env[len] != NULL)
		len++;
	if ((tmp = (char**)malloc((len + 1) * sizeof(char*))) == NULL)
		return (NULL);
	tmp[len] = NULL;
	len = 0;
	while (env[len] != NULL)
	{
		if ((tmp[len] = ft_strdup(env[len])) == NULL)
		{
			while (len > 0)
			{
				len--;
				ft_strdel(&(tmp[len]));
			}
			free(tmp);
			return (NULL);
		}
		len++;
	}
	env = tmp;
	return (env);
}

char	**get_envpath_array(char **env)
{
	char	**envpath;
	char	*path;

	if ((path = ft_getenv("PATH", env)) == NULL)
		return (NULL);
	envpath = ft_strsplit(path, ':');
	free(path);
	return (envpath);
}
