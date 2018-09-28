/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   width_handler.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/12 20:39:35 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 20:57:47 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_width_char(char **res, t_arg_format *arg_format,
		t_utilities *utilities)
{
	char	*tmp_buffer;

	if (arg_format->field_width > (int)utilities->content_size)
	{
		utilities->width_difference = (size_t)arg_format->field_width -
	utilities->content_size;
		if ((tmp_buffer = ft_memalloc(utilities->content_size +
		arg_format->field_width)) == NULL)
			exit(1);
		ft_strnfill(&tmp_buffer, ' ', arg_format->field_width -
	utilities->content_size);
		ft_memcpy(&(tmp_buffer[arg_format->field_width -
	utilities->content_size]), *res, utilities->content_size);
		utilities->content_size = arg_format->field_width;
		free(*res);
		*res = tmp_buffer;
	}
}

void		prepend_width_d(char **tmp_buffer, t_arg_format *arg_format,
t_utilities *utilities, char **res)
{
	ft_strnfill(tmp_buffer, ' ', arg_format->field_width -
utilities->content_size);
	ft_memcpy(&((*tmp_buffer)[arg_format->field_width -
utilities->content_size]), *res, utilities->content_size);
}

int			handle_width_d(char **res, t_arg_format *arg_format,
		t_utilities *utilities)
{
	char	*tmp_buffer;
	char	*tmp_ptr;

	if (arg_format->field_width > (int)utilities->content_size)
	{
		if ((tmp_buffer = ft_memalloc(arg_format->field_width + 1)) == NULL)
			return (0);
		if (arg_format->flags && ft_strchr(arg_format->flags, '-'))
		{
			tmp_ptr = &(tmp_buffer[utilities->content_size]);
			ft_memcpy(tmp_buffer, *res, utilities->content_size);
			ft_strnfill(&tmp_ptr, ' ', arg_format->field_width -
		utilities->content_size);
		}
		else
			prepend_width_d(&tmp_buffer, arg_format, utilities, res);
		utilities->content_size = arg_format->field_width;
		free(*res);
		*res = tmp_buffer;
	}
	return (1);
}
