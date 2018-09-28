/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/22 20:32:36 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 21:30:50 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_flags_d_nested(t_arg_format *arg_format, char **res,
t_utilities *utilities)
{
	if (ft_strchr(arg_format->flags, '+'))
	{
		if (secure_char_prepend(res, utilities, "+") == 0)
			return (0);
	}
	else if (ft_strchr(arg_format->flags, ' '))
	{
		if (secure_char_prepend(res, utilities, " ") == 0)
			return (0);
	}
	return (1);
}

void	handle_awkward_int(intmax_t *nbr, char **str, size_t *i)
{
	if (*nbr == -9223372036854775807 - 1 && ((*str)[0] = '-'))
	{
		(*str)[0] = '-';
		(*str)[*i] = '8';
		(*i) -= 1;
		*nbr = 922337203685477580;
	}
	else if (*nbr < 0)
	{
		(*str)[0] = '-';
		*nbr = -(*nbr);
	}
}

void	conversion_cluster_d(t_utilities *utilities,
t_arg_format *arg_format, intmax_t *arg)
{
	if (ft_strcmp(arg_format->length_modifier, "h") == 0)
		*arg = (short)va_arg(utilities->ap, int);
	else if (ft_strcmp(arg_format->length_modifier, "hh") == 0)
		*arg = (char)va_arg(utilities->ap, int);
	else if (ft_strcmp(arg_format->length_modifier, "l") == 0)
		*arg = va_arg(utilities->ap, long);
	else if (ft_strcmp(arg_format->length_modifier, "ll") == 0)
		*arg = va_arg(utilities->ap, long long);
	else if (ft_strcmp(arg_format->length_modifier, "j") == 0)
		*arg = va_arg(utilities->ap, intmax_t);
	else if (ft_strcmp(arg_format->length_modifier, "z") == 0)
		*arg = va_arg(utilities->ap, ssize_t);
	else if (ft_strcmp(arg_format->length_modifier, "t") == 0)
		*arg = va_arg(utilities->ap, ptrdiff_t);
}

void	conversion_cluster_ou(t_utilities *utilities,
t_arg_format *arg_format, uintmax_t *arg)
{
	if (ft_strcmp(arg_format->length_modifier, "h") == 0)
		*arg = (unsigned short)va_arg(utilities->ap, unsigned int);
	else if (ft_strcmp(arg_format->length_modifier, "hh") == 0)
		*arg = (unsigned char)va_arg(utilities->ap, unsigned int);
	else if (ft_strcmp(arg_format->length_modifier, "l") == 0)
		*arg = va_arg(utilities->ap, unsigned long);
	else if (ft_strcmp(arg_format->length_modifier, "ll") == 0)
		*arg = va_arg(utilities->ap, unsigned long long);
	else if (ft_strcmp(arg_format->length_modifier, "j") == 0)
		*arg = va_arg(utilities->ap, uintmax_t);
	else if (ft_strcmp(arg_format->length_modifier, "z") == 0)
		*arg = va_arg(utilities->ap, size_t);
	else if (ft_strcmp(arg_format->length_modifier, "t") == 0)
		*arg = va_arg(utilities->ap, ptrdiff_t);
}

int		handle_format_ss_nested(char **res, char **str,
int *prev_size, t_utilities *utilities)
{
	char	*tmp;

	if ((tmp = ft_memalloc(utilities->content_size)) == NULL)
		return (0);
	ft_memcpy(tmp, *res, *prev_size);
	ft_memcpy(&(tmp[*prev_size]), *str, utilities->content_size -
*prev_size);
	free(*str);
	*str = *res;
	*res = tmp;
	free(*str);
	*prev_size = utilities->content_size;
	return (1);
}
