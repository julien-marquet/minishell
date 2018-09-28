/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   initializers.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 17:36:41 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/11 21:49:52 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

t_utilities		*init_utilities(void)
{
	t_utilities	*utilities;

	utilities = (t_utilities*)malloc(sizeof(t_utilities));
	utilities->o_buffer = NULL;
	utilities->content_size = 0;
	utilities->width_difference = 0;
	utilities->has_args = 0;
	utilities->negative = 0;
	utilities->wchar_len = 0;
	utilities->flags_length = 0;
	utilities->bad_conv = 0;
	return (utilities);
}

t_arg_format	*init_arg_format(void)
{
	t_arg_format	*arg_format;

	if ((arg_format = (t_arg_format*)malloc(sizeof(t_arg_format))) == NULL)
		return (NULL);
	arg_format->flags = NULL;
	arg_format->field_width = -1;
	arg_format->precision = -1;
	arg_format->length_modifier = NULL;
	arg_format->conversion_character = 0;
	return (arg_format);
}
