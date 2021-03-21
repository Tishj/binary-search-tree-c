/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_prev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 19:49:57 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/21 20:18:24 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>
#include <stdbool.h>

t_node	*node_prev(t_node *node)
{
	if (!node)
		return (NULL);
	if (node->left)
	{
		node = node->left;
		while (node && node->right)
			node = node->right;
		return (node);
	}
	if (node->parent && node->parent->right == node)
		return (node->parent);
	if (node->parent)
	{
		while (node->parent && node->parent->left == node)
			node = node->parent;
		return (node->parent);
	}
	return (NULL);
}
