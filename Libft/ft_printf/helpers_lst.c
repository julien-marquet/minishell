/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   helpers_lst.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/22 20:29:38 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/22 20:29:53 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		lst_append(t_list **alst, char *content, size_t content_size)
{
	t_list	*lst;
	t_list	*lst_cursor;

	if ((lst = ft_lstnew(content, content_size)) == NULL)
		return (0);
	if (alst == NULL || *alst == NULL)
		*alst = lst;
	else
	{
		lst_cursor = *alst;
		while (lst_cursor->next)
			lst_cursor = lst_cursor->next;
		lst_cursor->next = lst;
	}
	return (1);
}

void	lst_free(t_list **alst)
{
	t_list	*cursor;
	t_list	*prev;

	cursor = *alst;
	prev = NULL;
	while (cursor)
	{
		if (cursor->content)
			free(cursor->content);
		prev = cursor;
		cursor = cursor->next;
		free(prev);
	}
}

int		lst_print(t_list *alst)
{
	int		sum;

	sum = 0;
	if (alst)
	{
		while (alst)
		{
			write(1, alst->content, alst->content_size);
			sum += alst->content_size;
			alst = alst->next;
		}
	}
	return (sum);
}
