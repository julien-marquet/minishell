/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins_cd.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 22:02:48 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/27 23:46:59 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		check_access(char *path, char **err)
{
	struct stat buffer;

	if (stat(path, &buffer) != 0)
	{
		*err = ft_construct_str(4, "cd: ", path, ": ",
	"No such file or directory");
		return (1);
	}
	else if (S_ISDIR(buffer.st_mode) != 1)
	{
		*err = ft_construct_str(4, "cd: ", path, ": ", "Not a directory");
		return (1);
	}
	else if (access(path, R_OK) != 0)
	{
		*err = ft_construct_str(4, "cd: ", path, ": ", "Permission denied");
		return (1);
	}
	return (0);
}

int		change_directory(char *path, char ***env, char **err)
{
	char		*pwd;
	char		cwd[__DARWIN_MAXPATHLEN];
	size_t		status;

	status = 0;
	if (check_access(path, err) != 0)
		return (1);
	if (chdir(path) != 0)
		return (1);
	if (getcwd(cwd, __DARWIN_MAXPATHLEN) == NULL)
		return (1);
	pwd = ft_getenv("PWD", *env);
	if (pwd == NULL || ft_strcmp(cwd, pwd) != 0)
	{
		status |= sh_setenv("OLDPWD", pwd, env);
		status |= sh_setenv("PWD", cwd, env);
	}
	ft_strdel(&pwd);
	return (status);
}

int		builtins_cd(char **tokens, char ***env, char **err)
{
	char	*v_env;
	int		status;

	if (tokens[1] == NULL || tokens[1][0] == '\0' ||
ft_strcmp(tokens[1], "--") == 0)
	{
		if ((v_env = ft_getenv("HOME", *env)) == NULL)
			return (1);
		status = change_directory(v_env, env, err);
		ft_strdel(&v_env);
	}
	else if (ft_strcmp(tokens[1], "-") == 0)
	{
		if ((v_env = ft_getenv("OLDPWD", *env)) == NULL)
			return (1);
		status = change_directory(v_env, env, err);
		ft_putendl(v_env);
		ft_strdel(&v_env);
	}
	else
		status = change_directory(tokens[1], env, err);
	return (status);
}
