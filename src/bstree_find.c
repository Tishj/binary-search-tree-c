/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_find.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 21:47:42 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/21 21:47:43 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

/*
**	return the address of the node, or the address of the variable
**	that the node should be inserted at.
**	sets 'parent' to the parent of the node
*/
t_node	**bstree_find(t_bstree *bstree, t_data key, t_node **parent)
{
	t_node	**node;
	bool	less;
	bool	equal;

	if (parent)
		*parent = NULL;
	node = &bstree->root;
	while (*node)
	{
		equal = compare(&key, &(*node)->key, NULL, &less);
		if (equal)
			return (node);
		if (parent)
			*parent = *node;
		if (less)
			node = &(*node)->left;
		else
			node = &(*node)->right;
	}
	return (node);
}
