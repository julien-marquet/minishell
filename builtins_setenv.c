/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins_setenv.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 16:30:42 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/26 20:39:03 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static char	*create_line(char *var, char *val)
{
	char	*tmp;
	size_t	len_var;
	size_t	len_val;

	len_var = ft_strlen(var);
	len_val = val == NULL ? 0 : ft_strlen(val);
	if ((tmp = malloc(len_val + len_var + 2)) == NULL)
		return (NULL);
	ft_strcpy(tmp, var);
	ft_strcpy(&(tmp[len_var]), "=");
	if (val != NULL)
		ft_strcpy(&(tmp[len_var + 1]), val);
	return (tmp);
}

static int	edit_line(char **tokens, char **l_env)
{
	char	*tmp;

	if ((tmp = create_line(tokens[1], tokens[2])) == NULL)
		return (1);
	ft_strdel(l_env);
	*l_env = tmp;
	return (0);
}

static int	add_line(char **tokens, char ***env)
{
	size_t	len;
	char	**tmp;

	len = 0;
	while ((*env)[len] != NULL)
		len++;
	if ((tmp = malloc((len + 2) * sizeof(char *))) == NULL)
		return (1);
	tmp[len + 1] = NULL;
	if ((tmp[len] = create_line(tokens[1], tokens[2])) == NULL)
		return (1);
	while (len > 0)
	{
		len--;
		if ((tmp[len] = ft_strdup((*env)[len])) == NULL)
			return (1);
	}
	free_array_str(*env);
	*env = tmp;
	return (0);
}

static int	i_setenv(char **tokens, char ***env)
{
	size_t	i;
	size_t	j;
	char	*err;

	i = 0;
	while ((*env)[i] != NULL)
	{
		j = 0;
		while ((*env)[i][j] != '\0')
		{
			if ((*env)[i][j] == '=')
				return (edit_line(tokens, &((*env)[i])));
			else if (tokens[1][j] != (*env)[i][j])
				break ;
			j++;
		}
		i++;
	}
	return (add_line(tokens, env));
}

int			builtins_setenv(char **tokens, char ***env)
{
	size_t	i;
	char	*err;

	i = 1;
	while (tokens[i] != NULL)
		i++;
	if (i == 1)
		return (builtins_env(tokens, *env));
	else if (i > 3)
		return (setenv_handle_err("setenv", "Too many arguments"));
	if (!setenv_is_valid(tokens[1]))
	{
		return (setenv_handle_err("setenv",
	"Variable name must contain alphanumeric characters"));
	}
	return (i_setenv(tokens, env));
}
