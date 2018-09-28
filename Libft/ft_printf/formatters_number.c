/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   formatters_number.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/04 18:04:10 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 21:43:01 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_d(intmax_t arg, t_utilities *utilities,
t_arg_format *arg_format)
{
	char	*res;

	res = NULL;
	if ((res = intmax_convstr(arg, &(utilities->content_size))) == NULL)
		return (NULL);
	utilities->negative = arg < 0;
	if (handle_prec_d(&res, arg_format, utilities) == 0)
		return (NULL);
	if (handle_flags_d(&res, arg_format, utilities) == 0)
		return (NULL);
	if (handle_width_d(&res, arg_format, utilities) == 0)
		return (NULL);
	return (res);
}

char	*format_u(uintmax_t arg, t_utilities *utilities,
t_arg_format *arg_format)
{
	char	*res;

	res = NULL;
	if ((res = uintmax_convstr(arg, &(utilities->content_size))) == NULL)
		return (NULL);
	if (handle_prec_u(&res, arg_format, utilities) == 0)
		return (NULL);
	if (handle_flags_u(&res, arg_format, utilities) == 0)
		return (NULL);
	if (handle_width_d(&res, arg_format, utilities) == 0)
		return (NULL);
	return (res);
}

char	*format_o(uintmax_t arg, t_utilities *utilities,
t_arg_format *arg_format)
{
	char	*res;

	res = NULL;
	if ((res = ouintmax_convstr(arg, &(utilities->content_size))) == NULL)
		return (NULL);
	if (handle_prec_o(&res, arg_format, utilities) == 0)
		return (NULL);
	if (handle_flags_o(&res, arg_format, utilities) == 0)
		return (NULL);
	if (handle_width_d(&res, arg_format, utilities) == 0)
		return (NULL);
	return (res);
}

char	*format_x(uintmax_t arg, t_utilities *utilities,
t_arg_format *arg_format)
{
	char	*res;

	res = NULL;
	if ((res = xuintmax_convstr(arg, &(utilities->content_size),
arg_format->conversion_character == 'X')) == NULL)
		return (NULL);
	if (handle_prec_u(&res, arg_format, utilities) == 0)
		return (NULL);
	if (handle_flags_x(&res, arg_format, utilities, arg) == 0)
		return (NULL);
	if (handle_width_d(&res, arg_format, utilities) == 0)
		return (NULL);
	return (res);
}

int		format_p(t_utilities *utilities, t_arg_format *arg_format, char **res)
{
	void	*arg;
	char	*tmp;

	arg = va_arg(utilities->ap, void*);
	if ((*res = voidp_convstr(arg, &(utilities->content_size))) == NULL)
		return (0);
	if (handle_prec_u(res, arg_format, utilities) == 0)
		return (0);
	if (arg_format->flags != NULL && ft_strchr(arg_format->flags, '0') &&
arg_format->precision == -1 &&
!ft_strchr(arg_format->flags, '-'))
	{
		if (handle_flag_0p(res, arg_format, utilities) == 0)
			return (0);
	}
	tmp = *res;
	if ((*res = ft_memprepend(*res, utilities->content_size + 1,
"0x", 2)) == NULL)
		return (0);
	free(tmp);
	utilities->content_size += 2;
	return (handle_width_d(res, arg_format, utilities));
}
