/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   converters.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/04 18:02:13 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 21:13:34 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_x(t_utilities *utilities, t_arg_format *arg_format,
char **res)
{
	uintmax_t	arg;

	arg = 0;
	if (arg_format->length_modifier)
	{
		if (ft_strcmp(arg_format->length_modifier, "h") == 0)
			arg = (unsigned short)va_arg(utilities->ap, unsigned int);
		else if (ft_strcmp(arg_format->length_modifier, "hh") == 0)
			arg = (unsigned char)va_arg(utilities->ap, unsigned int);
		else if (ft_strcmp(arg_format->length_modifier, "l") == 0)
			arg = va_arg(utilities->ap, unsigned long);
		else if (ft_strcmp(arg_format->length_modifier, "ll") == 0)
			arg = va_arg(utilities->ap, unsigned long long);
		else if (ft_strcmp(arg_format->length_modifier, "j") == 0)
			arg = va_arg(utilities->ap, uintmax_t);
		else if (ft_strcmp(arg_format->length_modifier, "z") == 0)
			arg = va_arg(utilities->ap, size_t);
		else if (ft_strcmp(arg_format->length_modifier, "t") == 0)
			arg = va_arg(utilities->ap, ptrdiff_t);
	}
	else
		arg = va_arg(utilities->ap, unsigned int);
	if ((*res = format_x(arg, utilities, arg_format)) == NULL)
		return (0);
	return (1);
}

int		convert_d(t_utilities *utilities, t_arg_format *arg_format,
char **res)
{
	intmax_t arg;

	arg = 0;
	if (arg_format->conversion_character == 'D')
		arg = va_arg(utilities->ap, long);
	else if (arg_format->length_modifier)
		conversion_cluster_d(utilities, arg_format, &arg);
	else
		arg = va_arg(utilities->ap, int);
	if ((*res = format_d(arg, utilities, arg_format)) == NULL)
		return (0);
	return (1);
}

int		convert_u(t_utilities *utilities, t_arg_format *arg_format,
char **res)
{
	uintmax_t	arg;

	arg = 0;
	if (arg_format->conversion_character == 'U')
		arg = va_arg(utilities->ap, unsigned long);
	else if (arg_format->length_modifier)
		conversion_cluster_ou(utilities, arg_format, &arg);
	else
		arg = va_arg(utilities->ap, unsigned int);
	if ((*res = format_u(arg, utilities, arg_format)) == NULL)
		return (0);
	return (1);
}

int		convert_o(t_utilities *utilities, t_arg_format *arg_format,
char **res)
{
	uintmax_t	arg;

	arg = 0;
	if (arg_format->conversion_character == 'O')
		arg = va_arg(utilities->ap, unsigned long);
	else if (arg_format->length_modifier)
		conversion_cluster_ou(utilities, arg_format, &arg);
	else
		arg = va_arg(utilities->ap, unsigned int);
	if ((*res = format_o(arg, utilities, arg_format)) == NULL)
		return (0);
	return (1);
}
