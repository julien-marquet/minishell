/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_getenv.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/19 16:12:40 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 03:15:33 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getenv(const char *name, char **env)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] != '\0')
		{
			if (name[j] == '=')
				break ;
			else if (env[i][j] == '=' && name[j] == '\0')
				return (ft_strdup(&(env[i][j + 1])));
			else if (name[j] != env[i][j])
				break ;
			j++;
		}
		i++;
	}
	return (NULL);
}
