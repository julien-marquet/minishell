/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   freers.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 17:36:41 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/15 17:44:18 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_utilities(t_utilities **utilities)
{
	lst_free(&(*utilities)->o_buffer);
	free(*utilities);
}

void	free_args(t_arg_format **arg_format)
{
	ft_strdel(&(*arg_format)->flags);
	ft_strdel(&(*arg_format)->length_modifier);
	if (*arg_format)
		free(*arg_format);
}
