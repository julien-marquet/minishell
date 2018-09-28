/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/18 17:20:26 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 17:28:03 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define BUF_SIZE 1024
# include <errno.h>
# include "Libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <dirent.h>

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
**	Destructors
*/

void	free_array_str(char **arr);
void	freedom(char **env);

/*
**	Helper
*/

int		is_metachar(char c);
int		file_exist(char *filename);
int		shift_empty_array(char **tokens);
void	remove_quotes(char **token);
/*
**	Expansions
*/

int		apply_expansion(char **token, char **env);
int		dol_handle_empty(char **token, size_t *i);
int		dol_handle_full(char **token, size_t *i, char **env, size_t j);

/*
**	Dispatcher
*/

int		dispatch_commands(char **tokens, char ***env, char **err, int *status);

/*
**	Env
*/

char	**get_envpath_array(char **env);
char	**duplicate_env(char **env);

/*
**	Exec
*/

int		exec_builtins(char **token, char ***env, char **err, int *status);
int		exec_file(char **token, char **env, char **err, int *status);

/*
**	Searcher
*/

int		search_usrpath(char **token, char **env, char **err, int *status);
int		search_envpath(char **token, char **env, char **err, int *status);
int		search_builtins(char **token, char ***env, char **err, int *status);

/*
**	Builtins
*/

int		builtins_echo(char **tokens);
int		builtins_env(char **env);
int		builtins_setenv(char **tokens, char ***env, char **err);
int		builtins_unsetenv(char **tokens, char **env, char **err);
int		builtins_cd(char **tokens, char ***env, char **err);

/*
**	Builtins utilities
*/

int		sh_setenv(char *var, char *val, char ***env);
int		setenv_is_valid(char *str);

#endif
