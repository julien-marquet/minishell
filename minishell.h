/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/18 17:20:26 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/20 18:59:21 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "Libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# define BUF_SIZE 1024

int		is_metachar(char c);
char	**allocate_tokens(size_t ntoken);
int		expand_dol(char **token, size_t *i, char **env, char *start);
int		expand_tild(char **token, size_t *i, char **env, char *start);

int 	dol_handle_empty(char **token, size_t *i);
int	    dol_handle_full(char **token, size_t *i, char **env, size_t j);
#endif
