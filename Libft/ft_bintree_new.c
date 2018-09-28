/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bintree_new.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jmarquet <jmarquet@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/26 22:22:25 by jmarquet     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/20 15:04:04 by jmarquet    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_bintree_node	*ft_bintree_new(void *content, size_t content_size)
{
	t_bintree_node	*new;

	if (!(new = (t_bintree_node*)malloc(sizeof(t_bintree_node))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = content;
		new->content_size = content_size;
	}
	new->left = NULL;
	new->right = NULL;
	return (new);
}
