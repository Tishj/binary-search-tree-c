/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_find.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/19 15:41:21 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/19 16:21:49 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>
#include <stdbool.h>
#include <stddef.h>

/*
**	return the address of the node, or the address of the variable
**	that the node should be inserted at.
**	sets 'parent' to the parent of the node
*/
void	**bstree_find(t_bstree *bstree, t_data key, t_node **parent)
{
	t_node	**node;
	bool	less;
	bool	equal;

	if (parent)
		*parent = NULL;
	node = &bstree->root;
	while (*node)
	{
		equal = compare(&(*node)->key, &key, NULL, &less);
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
