/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   searchers.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 18:18:10 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 05:29:32 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static int		add_path(char **tokens, char *path)
{
	char	*tmp;
	size_t	lent;
	size_t	lenp;
	size_t	has_slash;

	lent = ft_strlen(*tokens);
	lenp = ft_strlen(path);
	has_slash = path[lenp - 1] == '/';
	if ((tmp = malloc(lent + lenp + 1 + !has_slash)) == NULL)
		return (1);
	ft_strcpy(tmp, path);
	if (!has_slash)
		ft_strcpy(&(tmp[lenp]), "/");
	ft_strcpy(&(tmp[lenp + !has_slash]), *tokens);
	ft_strdel(tokens);
	*tokens = tmp;
	return (0);
}

static int		search_file_in_dir(const char *filename, const char *dirpath)
{
	DIR				*dirp;
	size_t			len;
	struct dirent	*dp;

	dirp = opendir(dirpath);
	if (dirp == NULL)
		return (1);
	len = ft_strlen(filename);
	while ((dp = readdir(dirp)) != NULL)
	{
		if (dp->d_namlen == len && ft_strcmp(dp->d_name, filename) == 0)
		{
			closedir(dirp);
			return (1);
		}
	}
	closedir(dirp);
	return (0);
}

int				search_builtins(char **token, char ***env, char **err,
int *status)
{
	if (ft_strcmp(*token, "echo") == 0 ||
	ft_strcmp(*token, "cd") == 0 ||
	ft_strcmp(*token, "setenv") == 0 ||
	ft_strcmp(*token, "unsetenv") == 0 ||
	ft_strcmp(*token, "env") == 0 ||
	ft_strcmp(*token, "exit") == 0)
	{
		if (exec_builtins(token, env, err, status) == 0)
			return (1);
		else
			return (-1);
	}
	return (0);
}

int				search_envpath(char **tokens, char **env, char **err,
int *status)
{
	char	**envpath;
	size_t	i;
	int		res;

	i = 0;
	if ((envpath = get_envpath_array(env)) != NULL)
	{
		while (envpath[i] != NULL)
		{
			res = search_file_in_dir(*tokens, envpath[i]);
			if (res == 1)
			{
				add_path(tokens, envpath[i]);
				exec_file(tokens, env, err, status);
				free_array_str(envpath);
				return (0);
			}
			else if (res == -1)
				return (1);
			i++;
		}
		free_array_str(envpath);
	}
	*err = ft_construct_str(3, *tokens, ": ", "command not found.");
	return (0);
}

int				search_usrpath(char **token, char **env, char **err,
int *status)
{
	int		res;

	res = file_exist(*token);
	if (res == 1)
		return (exec_file(token, env, err, status));
	else if (res == -1)
		*err = ft_construct_str(3, *token, ": ", "is a directory.");
	else
		*err = ft_construct_str(3, *token, ": ", "No such file or directory.");
	return (0);
}
