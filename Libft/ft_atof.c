/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atof.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:28:34 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 18:28:34 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int			ft_checkforspecials(const char *str, double *res)
{
	if (ft_strncicmp(str, "inf", 3) == 0 || ft_strncicmp(str, "+inf", 4) == 0)
	{
		*res = 1.0 / 0.0;
		return (1);
	}
	else if (ft_strncicmp(str, "-inf", 4) == 0)
	{
		*res = -1.0 / 0.0;
		return (1);
	}
	else if (ft_strncicmp(str, "nan", 3) == 0)
	{
		*res = 0.0 / 0.0;
		return (1);
	}
	else if (ft_strncicmp(str, "-nan", 4) == 0)
	{
		*res = -0.0 / 0.0;
		return (1);
	}
	else
		return (0);
}

static void			update_res(int *is_decimal, double *res,
	double *decimal, const char *str)
{
	if (*is_decimal == 0)
	{
		*res *= 10;
		*res += (double)*str - 48;
	}
	else if (*is_decimal > 0)
	{
		*decimal += (*str - 48) / ft_pow(10, (double)*is_decimal);
		*is_decimal += 1;
	}
}

static double		update_e_res(double res, double decimal,
	int is_negative, const char *str)
{
	res += decimal;
	decimal = ft_atof(str);
	if (decimal >= 0)
		res = is_negative * (res * ft_pow(10, decimal));
	else
		res = is_negative * (res / ft_pow(10, -decimal));
	return (res);
}

static double		handle_digit(const char *str, int is_negative, double res,
	double decimal)
{
	int				is_decimal;

	is_decimal = 0;
	while (ft_isdigit(*str) || *str == '.' || *str == 'E' || *str == 'e' ||
		(is_decimal < 0 && (*str == '-' || *str == '+')))
	{
		if (*str == '.')
		{
			if (decimal != 0)
				return (is_negative * (res + decimal));
			is_decimal = 1;
		}
		else if (*str == 'E' || *str == 'e')
			is_decimal = -1;
		else
		{
			if (is_decimal >= 0)
				update_res(&is_decimal, &res, &decimal, str);
			else
				return (update_e_res(res, decimal, is_negative, str));
		}
		str++;
	}
	return (is_negative * (res + decimal));
}

double				ft_atof(const char *str)
{
	unsigned int	i;
	double			res;
	int				is_negative;
	double			decimal;

	i = 0;
	res = 0;
	decimal = 0;
	if (!str)
		return (0.0);
	while (ft_isspace(str[i]))
		i++;
	if (ft_checkforspecials(&str[i], &res))
		return (res);
	is_negative = str[i] == '-' ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	return (handle_digit(&str[i], is_negative, res, decimal));
}
