/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utilities_builtins.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/26 20:13:57 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 05:10:05 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int			setenv_is_valid(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

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

static int	edit_line(char *var, char *val, char **l_env)
{
	char	*tmp;

	if ((tmp = create_line(var, val)) == NULL)
		return (1);
	ft_strdel(l_env);
	*l_env = tmp;
	return (0);
}

static int	add_line(char *var, char *val, char ***env)
{
	size_t	len;
	char	**tmp;

	len = 0;
	while ((*env)[len] != NULL)
		len++;
	if ((tmp = malloc((len + 2) * sizeof(char *))) == NULL)
		return (1);
	tmp[len + 1] = NULL;
	if ((tmp[len] = create_line(var, val)) == NULL)
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

int			sh_setenv(char *var, char *val, char ***env)
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
				return (edit_line(var, val, &((*env)[i])));
			else if (var[j] != (*env)[i][j])
				break ;
			j++;
		}
		i++;
	}
	return (add_line(var, val, env));
}
