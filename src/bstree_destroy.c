/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_destroy.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 20:22:41 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/21 20:51:10 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>
#include <stdio.h>

/*
**	Go left or right until you hit a leaf node, delete the leaf node and
**	set node back to the '&parent->(left/right)' of its parent
*/
void	bstree_destroy(t_bstree *bstree)
{
	t_node	**node;
	t_node	**parent;

	node = &bstree->root;
	while (*node)
	{
		if ((*node)->left)
			node = &(*node)->left;
		else if ((*node)->right)
			node = &(*node)->right;
		else
		{
			if (*node == bstree->root || (*node)->parent == bstree->root)
				parent = &bstree->root;
			else if ((*node)->parent->parent->left == (*node)->parent)
				parent = &(*node)->parent->parent->left;
			else
				parent = &(*node)->parent->parent->right;
			node_delete(node);
			node = parent;
		}
	}
}
