/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsers.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/28 17:36:41 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 21:15:26 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

char	*parse_flags(const char **format)
{
	const char	*buf_start;
	int			buf_len;
	char		*flags;

	buf_start = *format;
	buf_len = 0;
	while (**format != '\0' && ft_strchr("-+ 0#", **format) != NULL)
	{
		buf_len++;
		(*format)++;
	}
	if (buf_len > 0)
	{
		if ((flags = ft_strndup(buf_start, buf_len)) == NULL)
			return (NULL);
		return (flags);
	}
	return ("");
}

int		parse_field_width(const char **format, t_utilities *utilities,
char **flags)
{
	const char	*buf_start;
	int			tmp;

	buf_start = *format;
	while (ft_isdigit(**format))
		(*format)++;
	if (**format == '*')
	{
		(*format)++;
		utilities->has_args |= 1;
		tmp = va_arg(utilities->ap, int);
		if (tmp < 0)
		{
			if (*flags != NULL)
				*flags = ft_memprepend(*flags, ft_strlen(*flags), "-", 1);
			else if ((*flags = ft_strdup("-")) == NULL)
				return (-1);
			tmp = -tmp;
		}
		return (tmp);
	}
	if (buf_start != *format)
		return (ft_atoi(buf_start));
	else
		return (-1);
}

int		parse_precision(const char **format, t_utilities *utilities)
{
	const char	*buf_start;
	int			tmp;

	if (**format == '.')
	{
		(*format)++;
		buf_start = *format;
		while (ft_isdigit(**format) || **format == '-')
			(*format)++;
		if (**format == '*')
		{
			(*format)++;
			tmp = va_arg(utilities->ap, int);
			if (tmp < 0)
				tmp = -1;
			return (tmp);
		}
		if (buf_start != *format)
		{
			tmp = ft_atoi(buf_start);
			return (tmp < 0 ? -1 : tmp);
		}
		return (0);
	}
	return (-1);
}

char	*parse_length_modifier(const char **format)
{
	char	*length_modifier;

	length_modifier = "";
	if (ft_strncmp(*format, "hh", 2) == 0 || ft_strncmp(*format, "ll", 2) == 0)
	{
		if ((length_modifier = ft_strndup(*format, 2)) == NULL)
			return (NULL);
		(*format) += 2;
	}
	else if (ft_strncmp(*format, "l", 1) == 0 ||
	ft_strncmp(*format, "h", 1) == 0 ||
	ft_strncmp(*format, "j", 1) == 0 ||
	ft_strncmp(*format, "z", 1) == 0 ||
	ft_strncmp(*format, "t", 1) == 0)
	{
		if ((length_modifier = ft_strndup(*format, 1)) == NULL)
			return (NULL);
		(*format)++;
	}
	return (length_modifier);
}

char	parse_conversion_character(const char **format, t_utilities *utilities)
{
	char	conversion_character;

	if (**format != '\0' && ft_strchr("sSpdDioOuUxXcC", **format) != NULL)
	{
		conversion_character = **format;
		(*format)++;
		utilities->has_args = 1;
		return (conversion_character);
	}
	else if (**format != '\0')
	{
		conversion_character = 'c';
		utilities->has_args = 1;
		utilities->bad_conv = **format;
		(*format)++;
		return (conversion_character);
	}
	else
	{
		utilities->has_args = 0;
		utilities->bad_conv = 0;
	}
	return (0);
}
