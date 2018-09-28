/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bintree_insert.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/26 22:24:43 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/28 03:15:38 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	recursive(t_bintree_node *cursor, t_bintree_node *node,
void *params, int (*sort)(void *, void *, void *))
{
	int		sort_res;

	sort_res = sort(cursor->content, node->content, params);
	if (sort_res == 0)
	{
		if (cursor->left == NULL)
		{
			cursor->left = node;
			return (1);
		}
		else
			return (recursive(cursor->left, node, params, sort));
	}
	else
	{
		if (cursor->right == NULL)
		{
			cursor->right = node;
			return (1);
		}
		else
			return (recursive(cursor->right, node, params, sort));
	}
}

int			ft_bintree_insert(t_bintree_node **root, t_bintree_node *node,
void *params, int (*sort)(void *, void *, void *))
{
	t_bintree_node	*cursor;

	if (root == NULL || node == NULL)
		return (0);
	if (*root == NULL)
		*root = node;
	else
	{
		cursor = *root;
		recursive(cursor, node, params, sort);
	}
	return (1);
}
