/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bintree_free.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/26 23:58:52 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/02 00:33:20 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_bintree_free(t_bintree_node **root,
void (*destructor)(t_bintree_node **node))
{
	if (root == NULL || *root == NULL)
		return (0);
	if ((*root)->left != NULL)
		ft_bintree_free(&((*root)->left), destructor);
	if ((*root)->right != NULL)
		ft_bintree_free(&((*root)->right), destructor);
	destructor(root);
	return (1);
}
