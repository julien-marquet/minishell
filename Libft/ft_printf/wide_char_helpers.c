/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wide_char_helpers.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/25 18:16:14 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 20:48:23 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*wchar_secure_allocate(size_t size, t_utilities *utilities)
{
	char	*res;

	if ((res = ft_memalloc(size)) == NULL)
		return (NULL);
	utilities->wchar_len = size;
	return (res);
}

static char	*allocate_wres_nested(wint_t wint, t_utilities *utilities,
char **res)
{
	if (wint <= 0xFFFF)
	{
		if (MB_CUR_MAX < 3 ||
	(*res = wchar_secure_allocate(3, utilities)) == NULL)
			return (NULL);
	}
	else if (wint <= 0x10FFFF)
	{
		if (MB_CUR_MAX < 4 ||
	(*res = wchar_secure_allocate(4, utilities)) == NULL)
			return (NULL);
	}
	return (*res);
}

static char	*allocate_wres(wint_t wint, t_utilities *utilities)
{
	char	*res;

	res = NULL;
	if (wint <= 0xFF)
	{
		if ((res = wchar_secure_allocate(1, utilities)) == NULL)
			return (NULL);
	}
	else if (wint <= 0x7FF)
	{
		if (MB_CUR_MAX < 2 ||
	(res = wchar_secure_allocate(2, utilities)) == NULL)
			return (NULL);
	}
	else
		return (allocate_wres_nested(wint, utilities, &res));
	return (res);
}

static char	*transform_wint_nested(wint_t wint, char **res)
{
	if (wint <= 0xFFFF)
	{
		(*res)[0] = (((wint & 0xF000) >> 12) + 0xE0);
		if (MB_CUR_MAX >= 2)
			(*res)[1] = (((wint & 0x0Fc0) >> 6) + 0x80);
		if (MB_CUR_MAX >= 3)
			(*res)[2] = ((wint & 0x003F) + 0x80);
	}
	else if (wint <= 0x10FFFF)
	{
		(*res)[0] = (((wint & 0x1c0000) >> 18) + 0xF0);
		if (MB_CUR_MAX >= 2)
			(*res)[1] = (((wint & 0x03F000) >> 12) + 0x80);
		if (MB_CUR_MAX >= 3)
			(*res)[2] = (((wint & 0x0Fc0) >> 6) + 0x80);
		if (MB_CUR_MAX >= 4)
			(*res)[3] = ((wint & 0x003F) + 0x80);
	}
	return (*res);
}

char		*transform_wint(wint_t wint, t_utilities *utilities)
{
	char	*res;

	if (wint < 0 || (wint >= 0xd800 && wint <= 0xdfff))
		return (NULL);
	if ((res = allocate_wres(wint, utilities)) == NULL)
		return (NULL);
	if (wint <= 0x7F)
		*res = wint;
	else if (wint <= 0xff)
		*res = (char)wint;
	else if (wint <= 0x7FF)
	{
		res[0] = (((wint & 0x07c0) >> 6) + 0xc0);
		if (MB_CUR_MAX >= 2)
			res[1] = ((wint & 0x003F) + 0x80);
	}
	else
		return (transform_wint_nested(wint, &res));
	return (res);
}
