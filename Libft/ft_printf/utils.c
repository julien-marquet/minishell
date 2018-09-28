/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/31 22:07:32 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/15 17:43:40 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_flag_0d(char **res, t_arg_format *arg_format,
t_utilities *utilities, int shifted)
{
	char	*tmp;
	char	*tmpptr;

	if ((tmp = ft_memalloc(arg_format->field_width + 1 - shifted)) == NULL)
		return (0);
	tmp[arg_format->field_width - shifted] = '\0';
	tmp[0] = '-';
	tmpptr = &(tmp[utilities->negative]);
	ft_strnfill(&tmpptr, '0', ((arg_format->field_width -
utilities->content_size - shifted)));
	ft_memcpy(&(tmp[arg_format->field_width - shifted + utilities->negative -
(utilities->content_size)]), &((*res)[utilities->negative]),
utilities->content_size - utilities->negative);
	utilities->content_size = arg_format->field_width - shifted;
	free(*res);
	*res = tmp;
	return (1);
}

int		handle_flag_0x(char **res, t_arg_format *arg_format,
t_utilities *utilities, uintmax_t arg)
{
	char	*tmp;
	int		hasx;

	hasx = !!(ft_strchr(arg_format->flags, '#')) && arg != 0;
	if (arg_format->field_width - hasx * 2 >
(int)utilities->content_size)
	{
		if ((tmp = ft_memalloc(arg_format->field_width + 1)) == NULL)
			return (0);
		tmp[arg_format->field_width - hasx * 2] = '\0';
		ft_strnfill(&tmp, '0',
	(arg_format->field_width - utilities->content_size - hasx * 2));
		ft_memcpy(&(tmp[arg_format->field_width -
	utilities->content_size - hasx * 2]), *res,
	utilities->content_size);
		utilities->content_size = arg_format->field_width - hasx * 2;
		free(*res);
		*res = tmp;
	}
	return (1);
}

int		handle_flag_0p(char **res, t_arg_format *arg_format,
t_utilities *utilities)
{
	char	*tmp;
	int		hasx;

	hasx = 1;
	if (arg_format->field_width - hasx * 2 >
(int)utilities->content_size)
	{
		if ((tmp = ft_memalloc(arg_format->field_width + 1)) == NULL)
			return (0);
		tmp[arg_format->field_width - hasx * 2] = '\0';
		ft_strnfill(&tmp, '0',
	(arg_format->field_width - utilities->content_size - hasx * 2));
		ft_memcpy(&(tmp[arg_format->field_width -
	utilities->content_size - hasx * 2]), *res,
	utilities->content_size);
		utilities->content_size = arg_format->field_width - hasx * 2;
		free(*res);
		*res = tmp;
	}
	return (1);
}

char	*dispatch_format(t_arg_format *arg_format, t_utilities *utilities)
{
	char	*res;

	res = NULL;
	if (arg_format->conversion_character != '\0' &&
ft_strchr("cCsS", arg_format->conversion_character) != NULL)
		res = format_strings(utilities, arg_format);
	else if (arg_format->conversion_character != '\0' &&
ft_strchr("pdDioOuUxX", arg_format->conversion_character) != NULL)
		res = format_numbers(utilities, arg_format);
	else
	{
		utilities->content_size = 0;
		free_args(&arg_format);
		return (ft_strdup(""));
	}
	free_args(&arg_format);
	return (res);
}

int		iterator(const char *format, t_utilities *utilities,
const char **buf_start, size_t *buf_len)
{
	while (*format)
	{
		utilities->content_size = 0;
		utilities->bad_conv = 0;
		if (*format == '%')
		{
			if (handle_arg(&format, utilities, buf_start, buf_len) == 0)
				return (1);
		}
		else
		{
			(*buf_len) += 1;
			format++;
		}
	}
	return (0);
}
