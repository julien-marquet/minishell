/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bintree_traversal.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/26 23:30:37 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/05 13:35:54 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_bintree_traversal(t_bintree_node *node, void *params, int reverse,
int (*fun)(void *, void *))
{
	if (node == NULL)
		return (0);
	if (reverse == 0)
	{
		ft_bintree_traversal(node->left, params, reverse, fun);
		if (fun(node->content, params) == 0)
			return (0);
		ft_bintree_traversal(node->right, params, reverse, fun);
	}
	else
	{
		ft_bintree_traversal(node->right, params, reverse, fun);
		if (fun(node->content, params) == 0)
			return (0);
		ft_bintree_traversal(node->left, params, reverse, fun);
	}
	return (1);
}
