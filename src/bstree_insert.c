/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_insert.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 21:47:24 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/22 22:40:24 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static t_node	*node_new(void *key, size_t keysize, void *val, t_node *parent)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->key = key;
	node->size = keysize;
	node->val = val;
	return (node);
}

//do we want to del() the previous value in node? when overwriting
int	bstree_insert(t_bstree *bstree, void *key, size_t keysize, void *val, bool overwrite)
{
	t_node	**node;
	t_node	*parent;

	node = bstree_find(bstree, key, keysize, &parent);
	if (!*node)
	{
		*node = node_new(key, keysize, val, parent);
		bstree->size++;
		return (1);
	}
	if (!*node)
		return (0);
	if (!overwrite)
		return (1);
	if (bstree->del)
		bstree->del((*node)->val);
	(*node)->val = val;
	return (1);
}
