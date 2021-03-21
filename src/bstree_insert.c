/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_insert.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 21:47:24 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/21 21:47:25 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

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

int	bstree_insert(t_bstree *bstree, t_data key, t_data val, bool overwrite)
{
	t_node	**node;
	t_node	*parent;

	node = bstree_find(bstree, key, &parent);
	if (!*node)
	{
		*node = node_new(key, val, parent);
		bstree->size++;
	}
	if (!*node)
		return (0);
	if (!overwrite)
		return (1);
	(*node)->val = val;
	return (1);
}
