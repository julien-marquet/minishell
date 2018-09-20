/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/18 16:45:54 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/20 21:43:25 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

int		apply_expansion(char **token, char **env)
{
	size_t	i;

	i = 0;
	while ((*token)[i] != '\0')
	{
		if ((*token)[i] == '$')
		{
			if (expand_dol(token, &i, env, &((*token)[i + 1])) != 0)
				return (1);
		}
		else if ((*token)[i] == '~' && i == 0)
		{
			if (expand_tild(token, &i, env, &((*token)[i + 1])) != 0)
				return (1);
		}
		else
			i++;
	}
	return (0);
}

void	remove_quotes(char **token)
{
	size_t	i;

	i = 0;
	while ((*token)[i])
	{
		if ((*token)[i] == '\'')
			ft_strcpy(&((*token)[i]), &((*token)[i + 1]));
		i++;
	}
}

char	*process_token(unsigned char *in_word,
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

static void	init_var(size_t *start, size_t *ntoken, unsigned char *in_word,
unsigned char *is_quoted)
{
	*start = 0;
	*ntoken = 0;
	*in_word = 0;
	*is_quoted = 0;
}

int		parse_input(const char *str_i, char **tokens, char **env)
{
	unsigned char	in_word;
	size_t			ntoken;
	unsigned char	is_quoted;
	size_t			start;
	size_t			i;

	i = 0;
	init_var(&start, &ntoken, &in_word, &is_quoted);
	while (str_i[i])
	{
		if (is_metachar(str_i[i]) && !is_quoted)
		{
			if (in_word > 0 && (tokens[ntoken - 1] = process_token(
		&in_word, &(str_i[start]), i - start, env)) == NULL)
				return (1);
		}
		else if (str_i[i] == '\'')
			is_quoted = !is_quoted;
		else if (in_word == 0 && ++ntoken && ++in_word)
			start = i;
		i++;
	}
	return (0);
}

size_t	count_tokens(const char *str_i)
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

int		main(int ac, char **av, char **env)
{
	char	buf[BUF_SIZE + 1];
	ssize_t ret;
	char	**tokens;

	while (1)
	{
		ret = read(0, buf, BUF_SIZE);
		if (ret == -1)
			return (1);
		buf[ret] = '\0';
		if ((tokens = allocate_tokens(count_tokens(buf))) == NULL)
			return (1);
		if (parse_input(buf, tokens, env) != 0)
			return (1);
		ret = 0;
		while (tokens[ret])
		{
			ft_printf("%s\n", tokens[ret]);
			ret++;
		}
	}


	/*
	**  PARSING
	*/
	// separate by metacharacter (' ','\t','\n') and form simple command
	// apply quotes modification
	// apply sign expansion
	// apply file expansion
	/*
	**  EXECUTION
	*/
	// execute
	// wait
	return (0);
}
