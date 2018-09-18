/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/18 16:45:54 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/18 19:09:21 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "minishell.h"

char	*process_token(char *str_i, unsigned char *in_word,
size_t start, size_t i)
{
	*in_word = 0;
	ft_printf("%zu, %zu\n", start, i);
	return (NULL);
}

int		parse_input(char *str_i, char **tokens)
{
	unsigned char	in_word;
	size_t			ntoken;
	unsigned char	is_quoted;
	size_t			start;
	size_t			i;

	i = 0;
	start = 0;
	ntoken = 0;
	in_word = 0;
	is_quoted = 0;
	while (str_i[i++])
	{
		if (is_metachar(str_i[i]) && !is_quoted)
		{
			if (in_word > 0 && (tokens[ntoken] = process_token(str_i,
		&in_word, start, i - start)) == NULL)
				return (1);
		}
		else if (str_i[i] == '\'')
			is_quoted = !is_quoted;
		else if (in_word == 0 && ++ntoken && ++in_word)
			start = i;
	}
	return (0);
}

size_t	count_tokens(char *str_i)
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

int     main(void)
{
	char    buf[BUF_SIZE + 1];
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
		if (parse_input(buf, tokens) != 0)
			return (1);

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