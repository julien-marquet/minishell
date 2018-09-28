/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/09 15:44:12 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/27 21:22:21 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <locale.h>
# include <wchar.h>
# include <stddef.h>

# include "../libft.h"

typedef struct	s_utilities
{
	va_list ap;
	t_list	*o_buffer;
	size_t	content_size;
	int		negative;
	size_t	width_difference;
	int		has_args;
	char	bad_conv;
	size_t	flags_length;
	size_t	wchar_len;
}				t_utilities;

typedef struct	s_arg_format
{
	char	*flags;
	int		field_width;
	int		precision;
	char	*length_modifier;
	char	conversion_character;
}				t_arg_format;

/*
**	Initializers
*/
t_arg_format	*init_arg_format(void);
t_utilities		*init_utilities(void);
/*
**	Freers
*/
void			free_utilities(t_utilities **utilities);
void			free_args(t_arg_format **arg_format);
/*
**	Parsers
*/
char			*parse_flags(const char **format);
int				parse_field_width(const char **format, t_utilities *utilities,
				char **flags);
int				parse_precision(const char **format, t_utilities *utilities);
char			*parse_length_modifier(const char **format);
char			parse_conversion_character(const char **format,
t_utilities *utilities);
/*
**	Formatters
*/
char			*format_strings(t_utilities *utilities,
				t_arg_format *arg_format);
char			*format_numbers(t_utilities *utilities,
				t_arg_format *arg_format);
char			*format_c(t_utilities *utilities, t_arg_format *arg_format,
				char provided);
char			*format_cc(t_utilities *utilities, t_arg_format *arg_format);
char			*format_s(t_utilities *utilities, t_arg_format *arg_format);
char			*format_ss(t_utilities *utilities, t_arg_format *arg_format);
int				format_p(t_utilities *utilities, t_arg_format *arg_format,
				char **res);
char			*format_d(intmax_t arg, t_utilities *utilities,
				t_arg_format *arg_format);
char			*format_u(uintmax_t arg, t_utilities *utilities,
				t_arg_format *arg_format);
char			*format_o(uintmax_t arg, t_utilities *utilities,
				t_arg_format *arg_format);
char			*format_x(uintmax_t arg, t_utilities *utilities,
				t_arg_format *arg_format);
/*
** Handler
*/
void			handle_width_char(char **res, t_arg_format
				*arg_format, t_utilities *utilities);
int				handle_width_d(char **res, t_arg_format
				*arg_format, t_utilities *utilities);
int				handle_flags_char(char **res, t_arg_format *arg_format,
				t_utilities *utilities);
int				handle_prec_s(char **res, t_arg_format *arg_format,
				t_utilities *utilities);
int				handle_prec_d(char **res, t_arg_format *arg_format,
				t_utilities *utilities);
int				handle_flags_d(char **res, t_arg_format *arg_format,
				t_utilities *utilities);
int				handle_prec_u(char **res, t_arg_format *arg_format,
				t_utilities *utilities);
int				handle_flags_u(char **res, t_arg_format *arg_format,
				t_utilities *utilities);
int				handle_flags_o(char **res, t_arg_format *arg_format,
				t_utilities *utilities);
int				handle_flags_x(char **res, t_arg_format *arg_format,
				t_utilities *utilities, uintmax_t arg);
int				handle_prec_o(char **res, t_arg_format *arg_format,
				t_utilities *utilities);
/*
**	Converters
*/
int				convert_x(t_utilities *utilities, t_arg_format *arg_format,
				char **res);
int				convert_d(t_utilities *utilities, t_arg_format *arg_format,
				char **res);
int				convert_u(t_utilities *utilities, t_arg_format *arg_format,
				char **res);
int				convert_o(t_utilities *utilities, t_arg_format *arg_format,
				char **res);
/*
**	Helpers
*/
int				handle_format_ss_nested(char **res, char **str,
				int *prev_size, t_utilities *utilities);
void			conversion_cluster_d(t_utilities *utilities,
				t_arg_format *arg_format, intmax_t *arg);
void			conversion_cluster_ou(t_utilities *utilities,
				t_arg_format *arg_format, uintmax_t *arg);
void			handle_awkward_int(intmax_t *nbr, char **str, size_t *i);
int				handle_flags_d_nested(t_arg_format *arg_format, char **res,
				t_utilities *utilities);
int				iterator(const char *format, t_utilities *utilities,
				const char **buf_start, size_t *buf_len);
int				handle_arg(const char **format, t_utilities *utilities,
				const char **buf_start, size_t *buf_len);
int				lst_append(t_list **alst, char *content, size_t content_size);
int				lst_print(t_list *alst);
void			lst_free(t_list **alst);
char			*transform_wint(wint_t wint, t_utilities *utilities);
int				handle_flag_0d(char **res, t_arg_format *arg_format,
				t_utilities *utilities, int has_space);
int				handle_flag_0x(char **res, t_arg_format *arg_format,
				t_utilities *utilities, uintmax_t arg);
int				handle_flag_0p(char **res, t_arg_format *arg_format,
				t_utilities *utilities);
int				secure_char_prepend(char **res, t_utilities *utilities,
				char *insert);
size_t			getstrsize_intmax(intmax_t nbr);
char			*intmax_convstr(intmax_t nbr, size_t *size);
size_t			getstrsize_uintmax(uintmax_t nbr);
char			*uintmax_convstr(uintmax_t nbr, size_t *size);
size_t			getstrsize_ouintmax(uintmax_t nbr);
char			*ouintmax_convstr(uintmax_t nbr, size_t *size);
size_t			getstrsize_xuintmax(uintmax_t nbr);
char			*xuintmax_convstr(uintmax_t nbr, size_t *size, int ismaj);
size_t			getstrsize_voidp(long address);
char			*voidp_convstr(void *address, size_t *size);
int				create_empty(char **res, t_utilities *utilities);
char			*create_null(t_utilities *utilities);
char			*dispatch_format(t_arg_format *arg_format,
				t_utilities *utilities);

#endif
