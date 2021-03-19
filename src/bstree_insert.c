/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_insert.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/19 15:36:06 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/19 16:19:32 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>
#include <stdlib.h>
#include <stdbool.h>

static t_node	*node_new(t_data key, t_data val, t_node *parent)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->key = key;
	node->val = val;
	return (node);
}

int		bstree_insert(t_bstree *bstree, t_data key, t_data val, bool overwrite)
{
	t_node	**node;
	t_node	*parent;

	node = bstree_find(bstree, key, &parent);
	if (!*node)
		*node = node_new(key, val, parent);
	if (!*node)
		return (0);
	if (!overwrite)
		return (1);
	(*node)->val = val;
	return (1);
}
