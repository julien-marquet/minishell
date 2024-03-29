/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsers.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/20 21:48:19 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 17:23:32 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

static int		init_var(size_t *start, size_t *ntoken, unsigned char *in_word,
unsigned char *is_quoted)
{
	*start = 0;
	*ntoken = 0;
	*in_word = 0;
	*is_quoted = 0;
	return (0);
}

static char		*process_token(unsigned char *in_word,
const char *start, size_t i, char **env)
{
	char	*token;

	*in_word = 0;
	if ((token = ft_strndup(start, i)) == NULL)
		return (NULL);
	if (apply_expansion(&token, env) != 0)
		return (NULL);
	remove_quotes(&token);
	return (token);
}

size_t			count_tokens(const char *str_i)
{
	unsigned char	in_word;
	size_t			ntoken;
	unsigned char	is_quoted;

	ntoken = 0;
	in_word = 0;
	is_quoted = 0;
	while (*str_i)
	{
		if (is_metachar(*str_i) && !is_quoted)
		{
			if (in_word)
				in_word = 0;
		}
		else if (*str_i == '\'')
			is_quoted = !is_quoted;
		else if (!in_word && ntoken++)
			in_word = 1;
		str_i++;
	}
	return (ntoken);
}

void			handle_quote(unsigned char *in_word, size_t *i,
size_t *start, size_t *ntoken)
{
	if (*in_word == 0)
	{
		*start = *i;
		*in_word = 1;
		*ntoken += 1;
	}
}

int				parse_input(const char *str_i, char **tokens, char **env)
{
	unsigned char	in_word;
	size_t			ntoken;
	unsigned char	is_quoted;
	size_t			start;
	size_t			i;

	i = init_var(&start, &ntoken, &in_word, &is_quoted);
	while (str_i[i])
	{
		if (is_metachar(str_i[i]) && !is_quoted)
		{
			if (in_word > 0 && (tokens[ntoken - 1] = process_token(
		&in_word, &(str_i[start]), i - start, env)) == NULL)
				return (1);
		}
		else if (str_i[i] == '\'')
		{
			handle_quote(&in_word, &i, &start, &ntoken);
			is_quoted = !is_quoted;
		}
		else if (in_word == 0 && ++ntoken && ++in_word)
			start = i;
		i++;
	}
	return (shift_empty_array(tokens));
}
