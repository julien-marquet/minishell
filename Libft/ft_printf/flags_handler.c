/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flags_handler.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/23 15:21:13 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 21:42:17 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_flags_char(char **res, t_arg_format *arg_format,
		t_utilities *utilities)
{
	char	*tmp;

	if (arg_format->flags != NULL && ft_strchr(arg_format->flags, '0') &&
!ft_strchr(arg_format->flags, '-') &&
utilities->content_size < (size_t)arg_format->field_width)
	{
		if ((tmp = ft_memalloc(arg_format->field_width + 1)) == NULL)
			return (0);
		tmp[0] = (*res)[0];
		tmp[arg_format->field_width] = '\0';
		ft_strnfill(&tmp, '0',
	(arg_format->field_width - utilities->content_size));
		ft_memcpy(&(tmp[arg_format->field_width -
	utilities->content_size]), *res, utilities->content_size);
		utilities->content_size = arg_format->field_width;
		free(*res);
		*res = tmp;
	}
	return (1);
}

int		handle_flags_d(char **res, t_arg_format *arg_format,
t_utilities *utilities)
{
	int		will_shift;

	if (arg_format->flags != NULL)
	{
		will_shift = (ft_strchr(arg_format->flags, '+') ||
		ft_strchr(arg_format->flags, ' ')) && !utilities->negative;
		if (ft_strchr(arg_format->flags, '0') &&
	!ft_strchr(arg_format->flags, '-') && (int)utilities->content_size <
	arg_format->field_width - will_shift && arg_format->precision == -1)
		{
			if (handle_flag_0d(res, arg_format, utilities, will_shift) == 0)
				return (0);
		}
		if (!utilities->negative)
			return (handle_flags_d_nested(arg_format, res, utilities));
	}
	return (1);
}

int		handle_flags_u(char **res, t_arg_format *arg_format,
t_utilities *utilities)
{
	char	*tmp;

	if (arg_format->flags != NULL)
	{
		if (ft_strchr(arg_format->flags, '0') &&
	!ft_strchr(arg_format->flags, '-') && (int)utilities->content_size <
	arg_format->field_width && arg_format->precision == -1)
		{
			if ((tmp = ft_memalloc(arg_format->field_width + 1)) == NULL)
				return (0);
			tmp[0] = (*res)[0];
			tmp[arg_format->field_width] = '\0';
			ft_strnfill(&tmp, '0',
		(arg_format->field_width - utilities->content_size));
			ft_memcpy(&(tmp[arg_format->field_width -
		utilities->content_size]), *res, utilities->content_size);
			utilities->content_size = arg_format->field_width;
			free(*res);
			*res = tmp;
		}
	}
	return (1);
}

int		handle_flags_o(char **res, t_arg_format *arg_format,
t_utilities *utilities)
{
	char	*tmp;

	if (arg_format->flags != NULL)
	{
		if (ft_strchr(arg_format->flags, '0') &&
	!ft_strchr(arg_format->flags, '-') && arg_format->field_width != -1 &&
	utilities->content_size < (size_t)arg_format->field_width &&
	arg_format->precision == -1)
		{
			if ((tmp = ft_memalloc(arg_format->field_width + 1)) == NULL)
				return (0);
			tmp[0] = (*res)[0];
			tmp[arg_format->field_width] = '\0';
			ft_strnfill(&tmp, '0',
	(arg_format->field_width - utilities->content_size));
			ft_memcpy(&(tmp[arg_format->field_width -
	utilities->content_size]), *res, utilities->content_size);
			utilities->content_size = arg_format->field_width;
			free(*res);
			*res = tmp;
		}
	}
	return (1);
}

int		handle_flags_x(char **res, t_arg_format *arg_format,
t_utilities *utilities, uintmax_t arg)
{
	char	*tmp;

	if (arg_format->flags != NULL)
	{
		if (ft_strchr(arg_format->flags, '0') && arg_format->precision == -1 &&
	!ft_strchr(arg_format->flags, '-'))
		{
			if (handle_flag_0x(res, arg_format, utilities, arg) == 0)
				return (0);
		}
		if (ft_strchr(arg_format->flags, '#') && arg != 0)
		{
			tmp = *res;
			if ((*res = ft_memprepend(*res, utilities->content_size + 1,
		arg_format->conversion_character == 'X' ? "0X" : "0x", 2)) == NULL)
				return (0);
			free(tmp);
			utilities->content_size += 2;
		}
	}
	return (1);
}
