/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:28:51 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 17:26:19 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int		ft_count_words(char const *s, char c)
{
	unsigned int	i;
	unsigned int	cpt;
	int				in_a_word;

	i = 0;
	cpt = 0;
	in_a_word = s[0] != '\0' && s[0] != c ? 1 : 0;
	while (s[i] != '\0')
	{
		if (in_a_word && s[i] == c)
		{
			cpt++;
			in_a_word = 0;
		}
		else if (!in_a_word && s[i] != c)
			in_a_word = 1;
		if (in_a_word && s[i + 1] == '\0')
			cpt++;
		i++;
	}
	return (cpt);
}

static unsigned int		ft_split_strlen(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static void				ft_free_allocated(char **array, unsigned int index)
{
	long	i;

	i = (long)index;
	i--;
	while (i >= 0)
		free(array[i--]);
	free(array);
}

static void				ft_fill_string(char **str, char const **src, char c)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while ((*src)[j] != '\0' && (*src)[j] == c)
		j++;
	while ((*src)[j] != '\0' && (*src)[j] != c)
	{
		(*str)[i] = (*src)[j];
		i++;
		j++;
	}
	(*str)[i] = '\0';
	while ((*src)[j] != '\0' && (*src)[j] == c)
	{
		i++;
		j++;
	}
	*src = (*src + j);
}

char					**ft_strsplit(char const *s, char c)
{
	char			**array;
	unsigned int	array_len;
	unsigned int	array_index;

	if (!s)
		return (NULL);
	array_len = ft_count_words(s, c);
	if (!(array = (char**)malloc(sizeof(char *) * (array_len + 1))))
		return (NULL);
	array_index = -1;
	while (++array_index < array_len)
	{
		if (!(array[array_index] = (char *)malloc(sizeof(char)
			* (ft_split_strlen(s, c) + 1))))
		{
			ft_free_allocated(array, array_index);
			return (NULL);
		}
		ft_fill_string(&array[array_index], &s, c);
	}
	array[array_len] = NULL;
	return (array);
}
