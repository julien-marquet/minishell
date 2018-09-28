/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   formatters_string.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/04 18:03:40 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 21:38:16 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char		*format_c(t_utilities *utilities, t_arg_format *arg_format,
		char provided)
{
	char	arg;
	char	*res;

	if (provided == 0)
		arg = va_arg(utilities->ap, int);
	else
		arg = provided;
	if ((res = ft_memalloc(1)) == NULL)
		return (NULL);
	res[0] = arg;
	utilities->content_size = 1;
	if (handle_flags_char(&res, arg_format, utilities) == 0)
		return (NULL);
	if (handle_width_d(&res, arg_format, utilities) == 0)
		return (NULL);
	return (res);
}

char		*format_cc(t_utilities *utilities, t_arg_format *arg_format)
{
	wint_t	wint;
	char	*res;

	wint = va_arg(utilities->ap, wint_t);
	if ((res = transform_wint(wint, utilities)) == NULL)
		return (NULL);
	utilities->content_size += utilities->wchar_len;
	utilities->wchar_len = 0;
	if (handle_flags_char(&res, arg_format, utilities) == 0)
		return (NULL);
	if (handle_width_d(&res, arg_format, utilities) == 0)
		return (NULL);
	return (res);
}

char		*format_s(t_utilities *utilities, t_arg_format *arg_format)
{
	char	*arg;
	char	*res;

	arg = va_arg(utilities->ap, char*);
	if (arg == NULL)
		res = create_null(utilities);
	else
	{
		if ((res = ft_memalloc(ft_strlen(arg) + 1)) == NULL)
			return (NULL);
		ft_strcpy(res, arg);
		utilities->content_size = ft_strlen(arg);
	}
	if (handle_prec_s(&res, arg_format, utilities) == 0)
		return (NULL);
	if (handle_flags_char(&res, arg_format, utilities) == 0)
		return (NULL);
	if (handle_width_d(&res, arg_format, utilities) == 0)
		return (NULL);
	return (res);
}

static int	handle_format_ss(char **res, wchar_t *arg,
t_arg_format *arg_format, t_utilities *utilities)
{
	int		prev_size;
	char	*str;

	if ((*res = ft_strdup("")) == NULL)
		return (0);
	prev_size = 0;
	while (*arg != L'\0' && (arg_format->precision == -1 ||
(int)utilities->content_size < arg_format->precision))
	{
		if ((str = transform_wint(*arg++, utilities)) == NULL)
		{
			free(*res);
			return (0);
		}
		if (arg_format->precision != -1 && (int)(utilities->content_size +
	utilities->wchar_len) > arg_format->precision)
			break ;
		utilities->content_size += utilities->wchar_len;
		utilities->wchar_len = 0;
		handle_format_ss_nested(res, &str, &prev_size, utilities);
	}
	return (1);
}

char		*format_ss(t_utilities *utilities, t_arg_format *arg_format)
{
	wchar_t	*arg;
	char	*res;

	arg = va_arg(utilities->ap, wchar_t*);
	if (arg == NULL)
	{
		res = create_null(utilities);
		if (handle_prec_s(&res, arg_format, utilities) == 0)
			return (NULL);
	}
	else
	{
		if (handle_format_ss(&res, arg, arg_format, utilities) == 0)
			return (NULL);
	}
	if (handle_flags_char(&res, arg_format, utilities) == 0)
		return (NULL);
	if (handle_width_d(&res, arg_format, utilities) == 0)
		return (NULL);
	return (res);
}
