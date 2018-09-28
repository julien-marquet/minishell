/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 17:36:41 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/15 17:43:28 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Parse args filling the arg format structure
*/

static t_arg_format	*parse_arg_format(const char **format,
t_utilities *utilities)
{
	t_arg_format *arg_format;

	if ((arg_format = init_arg_format()) == NULL)
		return (NULL);
	if ((arg_format->flags = parse_flags(format)) == NULL)
		return (NULL);
	arg_format->flags = ft_strcmp(arg_format->flags, "") == 0 ?
NULL : arg_format->flags;
	arg_format->field_width = parse_field_width(format, utilities,
&(arg_format->flags));
	arg_format->precision = parse_precision(format, utilities);
	if ((arg_format->length_modifier =
parse_length_modifier(format)) == NULL)
		return (NULL);
	arg_format->length_modifier = ft_strcmp(arg_format->length_modifier,
"") == 0 ? NULL : arg_format->length_modifier;
	arg_format->conversion_character = parse_conversion_character(format,
utilities);
	return (arg_format);
}

/*
**	Unstack the args using provided format
*/

static char			*unstack_args(const char **format, t_utilities *utilities)
{
	t_arg_format	*arg_format;
	char			*res;

	res = NULL;
	(*format)++;
	if ((arg_format = parse_arg_format(format, utilities)) == NULL)
	{
		free_args(&arg_format);
		return (NULL);
	}
	if (utilities->bad_conv != 0)
	{
		if ((res = format_c(utilities, arg_format,
	utilities->bad_conv)) == NULL)
		{
			free_args(&arg_format);
			return (NULL);
		}
		free_args(&arg_format);
	}
	else
		res = dispatch_format(arg_format, utilities);
	return (res);
}

/*
**	Get basic String + Call Unstack Arg + Append to list
*/

int					handle_arg(const char **format, t_utilities *utilities,
					const char **buf_start, size_t *buf_len)
{
	char	*arg_res;
	char	*tmp_buffer;

	if ((arg_res = unstack_args(format, utilities)) == NULL)
		return (0);
	if ((tmp_buffer = ft_memalloc(*buf_len + utilities->content_size)) == NULL)
		return (0);
	if (*buf_len > 0)
		ft_memcpy(tmp_buffer, *buf_start, *buf_len);
	ft_memcpy(&(tmp_buffer[*buf_len]), arg_res, utilities->content_size);
	free(arg_res);
	if (lst_append(&(utilities->o_buffer), tmp_buffer,
*buf_len + utilities->content_size) == 0)
		return (0);
	free(tmp_buffer);
	*buf_len = 0;
	*buf_start = *format;
	return (1);
}

static int			handle_result(t_utilities **utilities,
				const char *buf_start, size_t buf_len, int error)
{
	char	*sub;
	size_t	len;

	if (buf_len > 0 && error == 0)
	{
		if ((sub = ft_memsub(buf_start, 0, buf_len)) == NULL)
			return (-1);
		if ((lst_append(&((*utilities)->o_buffer), sub, buf_len)) == 0)
			return (-1);
		free(sub);
	}
	va_end((*utilities)->ap);
	len = lst_print((*utilities)->o_buffer);
	free_utilities(utilities);
	return (error == 1 ? -1 : len);
}

int					ft_printf(const char *format, ...)
{
	t_utilities	*utilities;
	const char	*buf_start;
	size_t		buf_len;
	int			error;

	buf_start = format;
	buf_len = 0;
	error = 0;
	if ((utilities = init_utilities()) == NULL)
		return (-1);
	va_start(utilities->ap, format);
	error = iterator(format, utilities, &buf_start, &buf_len);
	return (handle_result(&utilities, buf_start, buf_len, error));
}
