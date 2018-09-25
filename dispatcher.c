/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dispatcher.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/21 15:11:43 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 18:16:41 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		search_builtins(char **token, char **env, char **err)
{
	ft_printf("Search in builtins\n");
	if (ft_strcmp(*token, "echo") == 0 ||
	ft_strcmp(*token, "cd") == 0 ||
	ft_strcmp(*token, "setenv") == 0 ||
	ft_strcmp(*token, "unsetenv") == 0 ||
	ft_strcmp(*token, "env") == 0 ||
	ft_strcmp(*token, "exit") == 0)
	{
		ft_printf("found\n");
		if (exec_builtins(token, env, err) == 0)
			return (1);
		else
			return (-1);
	}
	ft_printf("Not found\n");
	return (0);
}

int		search_file_in_dir(const char *filename, const char *dirpath,
char **err)
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

int		file_exist(char *filename)
{
	struct stat	buffer;

	return (stat(filename, &buffer) == 0);
}

int		search_envpath(char **token, char **env, char **err)
{
	char	**envpath;
	size_t	i;
	int		res;

	i = 0;
	ft_printf("Search in env path\n");
	if ((envpath = get_envpath_array(env)) == NULL)
		return (1);
	while (envpath[i] != NULL)
	{
		res = search_file_in_dir(*token, envpath[i], err);
		if (res == 1)
		{
			ft_printf("found\n");
			// exec
			// free
			return (0);
		}
		else if (res == -1)
			return (1);
		i++;
	}
	// free envpath
	if ((*err = construct_error(*token, "command not found")) == NULL)
		return (1);
	ft_printf("not found\n");
	return (0);
}

int		search_usrpath(char **token, char **env, char **err)
{
	ft_printf("Search in usr path\n");
	int		res;

	res = file_exist(*token);
	if (res == 1)
	{
		ft_printf("found\n");
		// exec
		// free
		return (0);
	}
	else if (res == -1)
		return (1);
	if ((*err = construct_error(*token, "No such file or directory")) == NULL)
		return (1);
	ft_printf("Not found\n");
	return (0);
}

int		dispatch_commands(char **tokens, char **env, char **err)
{
	int		res;
	size_t	i;

	i = 0;
	ft_printf("tokens : \n");
	while (tokens[i] != NULL)
	{
		ft_printf("%s\n", tokens[i]);
		i++;
	}
	if (ft_strchr(*tokens, '/') == NULL)
	{
		res = search_builtins(tokens, env, err);
		if (res != 0)
			return (res);
		return (search_envpath(tokens, env, err));
	}
	else
		return (search_usrpath(tokens, env, err));
}
