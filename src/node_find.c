/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_find.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 21:47:42 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/22 22:42:59 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree_int.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

static size_t	min(size_t a, size_t b)
{
	if (b > a)
		return (a);
	return (b);
}

/*
**	return the address of the node, or the address of the variable
**	that the node should be inserted at.
**	sets 'parent' to the parent of the node
*/
t_node	**node_find(t_bstree *bstree, void *key,
		size_t keysize, t_node **parent)
{
	t_node	**node;
	int		res;

	if (parent)
		*parent = NULL;
	node = &bstree->root;
	while (*node)
	{
		res = bstree->comp((*node)->key, key,
			bstree->key_type_size * min((*node)->size, keysize));
		if (!res)
			return (node);
		if (parent)
			*parent = *node;
		if (res < 0)
			node = &(*node)->left;
		else
			node = &(*node)->right;
	}
	return (node);
}
