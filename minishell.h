/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/18 17:20:26 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 17:41:01 by jmarquet    ###    #+. /#+    ###.fr     */
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
# include <dirent.h>
# define BUF_SIZE 1024

/*
**	Parser
*/

size_t	count_tokens(const char *str_i);
int		parse_input(const char *str_i, char **tokens, char **env);

/*
**	Allocators
*/

char	**allocate_tokens(size_t ntoken);

/*
**	Helper
*/

int		is_metachar(char c);
char	**get_envpath_array(char **env);

/*
**	Expansions
*/

int		apply_expansion(char **token, char **env);
int		dol_handle_empty(char **token, size_t *i);
int		dol_handle_full(char **token, size_t *i, char **env, size_t j);

/*
**	Dispatcher
*/

int		dispatch_commands(char **tokens, char **env, char **err);

/*
**	Env
*/

char	**duplicate_env(char **env);

/*
**	Exec
*/

int		exec_builtins(char **token, char **env, char **err);

#endif
