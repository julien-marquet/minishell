/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   formatters_main.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 17:36:41 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/09 20:52:55 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*format_numbers(t_utilities *utilities, t_arg_format *arg_format)
{
	char		*res;

	res = NULL;
	if ((arg_format->conversion_character == 'd' ||
arg_format->conversion_character == 'i') ||
arg_format->conversion_character == 'D')
		convert_d(utilities, arg_format, &res);
	else if (arg_format->conversion_character == 'p')
	{
		if (format_p(utilities, arg_format, &res) == 0)
			return (NULL);
	}
	else if (arg_format->conversion_character == 'o' ||
arg_format->conversion_character == 'O')
		convert_o(utilities, arg_format, &res);
	else if (arg_format->conversion_character == 'u' ||
arg_format->conversion_character == 'U')
		convert_u(utilities, arg_format, &res);
	else if (arg_format->conversion_character == 'x' ||
arg_format->conversion_character == 'X')
		convert_x(utilities, arg_format, &res);
	return (res);
}

char	*format_strings(t_utilities *utilities, t_arg_format *arg_format)
{
	char	*res;

	res = NULL;
	if (arg_format->conversion_character == 'c' &&
!(arg_format->length_modifier &&
ft_strcmp(arg_format->length_modifier, "l") == 0))
		res = format_c(utilities, arg_format, 0);
	else if (arg_format->conversion_character == 'C' ||
(arg_format->conversion_character == 'c' && arg_format->length_modifier &&
ft_strcmp(arg_format->length_modifier, "l") == 0))
		res = format_cc(utilities, arg_format);
	else if (arg_format->conversion_character == 's' &&
!(arg_format->length_modifier &&
ft_strcmp(arg_format->length_modifier, "l") == 0))
		res = format_s(utilities, arg_format);
	else if (arg_format->conversion_character == 'S' ||
(arg_format->conversion_character == 's' &&
(arg_format->length_modifier &&
ft_strcmp(arg_format->length_modifier, "l") == 0)))
		res = format_ss(utilities, arg_format);
	return (res);
}
