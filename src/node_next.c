/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_next.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 19:49:57 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/21 20:16:42 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>
#include <stdbool.h>

t_node	*node_next(t_node *node)
{
	if (!node)
		return (NULL);
	if (node->right)
	{
		node = node->right;
		while (node && node->left)
			node = node->left;
		return (node);
	}
	if (node->parent && node->parent->left == node)
		return (node->parent);
	if (node->parent)
	{
		while (node->parent && node->parent->right == node)
			node = node->parent;
		return (node->parent);
	}
	return (NULL);
}
