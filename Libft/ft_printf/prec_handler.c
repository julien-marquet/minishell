/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   prec_handler.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 17:18:45 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 21:36:53 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_prec_s(char **res, t_arg_format *arg_format,
		t_utilities *utilities)
{
	char *tmp;

	if (arg_format->precision != -1 &&
arg_format->precision < (int)utilities->content_size)
	{
		if ((tmp = ft_memalloc(arg_format->precision)) == NULL)
			return (0);
		ft_strncpy(tmp, *res, arg_format->precision);
		free(*res);
		*res = tmp;
		utilities->content_size = arg_format->precision;
	}
	return (1);
}

int		handle_prec_d(char **res, t_arg_format *arg_format,
		t_utilities *utilities)
{
	char	*tmp;
	char	*tmpptr;

	if (arg_format->precision > 0 &&
arg_format->precision + utilities->negative > (int)utilities->content_size)
	{
		if ((tmp = ft_memalloc(arg_format->precision +
	utilities->negative + 1)) == NULL)
			return (0);
		tmp[0] = '-';
		tmp[arg_format->precision + utilities->negative] = '\0';
		tmpptr = &(tmp[utilities->negative]);
		ft_strnfill(&tmpptr, '0',
	(arg_format->precision - utilities->content_size + utilities->negative));
		ft_memcpy(&(tmp[arg_format->precision - utilities->content_size +
	(utilities->negative * 2)]), &((*res)[utilities->negative]),
	utilities->content_size - utilities->negative);
		utilities->content_size = arg_format->precision + utilities->negative;
		free(*res);
		*res = tmp;
	}
	else if (arg_format->precision == 0 && ft_strcmp(*res, "0") == 0)
		return (create_empty(res, utilities));
	return (1);
}

int		handle_prec_u(char **res, t_arg_format *arg_format,
		t_utilities *utilities)
{
	char	*tmp;

	if (arg_format->precision != -1 &&
arg_format->precision > (int)utilities->content_size)
	{
		if ((tmp = ft_memalloc(arg_format->precision + 1)) == NULL)
			return (0);
		tmp[arg_format->precision] = '\0';
		ft_strnfill(&tmp, '0',
	(arg_format->precision - utilities->content_size));
		ft_memcpy(&(tmp[arg_format->precision - utilities->content_size]), *res,
	utilities->content_size);
		utilities->content_size = arg_format->precision;
		free(*res);
		*res = tmp;
	}
	else if (arg_format->precision == 0 && ft_strcmp(*res, "0") == 0)
	{
		if (create_empty(res, utilities) == 0)
			return (0);
	}
	return (1);
}

int		handle_prec_o_nested(t_arg_format *arg_format, t_utilities *utilities,
char **res)
{
	char	*tmp;

	if ((tmp = ft_memalloc(arg_format->precision + 1)) == NULL)
		return (0);
	tmp[arg_format->precision] = '\0';
	ft_strnfill(&tmp, '0',
(arg_format->precision - utilities->content_size));
	ft_memcpy(&(tmp[arg_format->precision - utilities->content_size]), *res,
utilities->content_size);
	utilities->content_size = arg_format->precision;
	free(*res);
	*res = tmp;
	return (1);
}

int		handle_prec_o(char **res, t_arg_format *arg_format,
		t_utilities *utilities)
{
	if (ft_strcmp(*res, "0") == 0 && ((arg_format->flags != NULL &&
ft_strchr(arg_format->flags, '#')) || arg_format->precision == 0))
	{
		if (create_empty(res, utilities) == 0)
			return (0);
	}
	if (arg_format->flags != NULL && ft_strchr(arg_format->flags, '#'))
	{
		if (secure_char_prepend(res, utilities, "0") == 0)
			return (0);
	}
	if (arg_format->precision != -1 &&
arg_format->precision > (int)utilities->content_size)
	{
		if (handle_prec_o_nested(arg_format, utilities, res) == 0)
			return (0);
	}
	return (1);
}
