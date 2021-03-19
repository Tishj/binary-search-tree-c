/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_delete.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/19 16:20:11 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/19 16:23:52 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>
#include <stdlib.h>
#include <stdbool.h>

//return the address of parent->(left/right) of the leaf node
static t_node		**leaf(t_node **node, bool higher)
{
	if (higher)
	{
		node = &(*node)->right;
		while (*node && ((*node)->left))
			node = &(*node)->left;
		return (node);
	}
	node = &(*node)->left;
	while (*node && ((*node)->right))
		node = &(*node)->right;
	return (node);
}

static void	delete(t_node **node)
{
	t_node *delete;

	delete = *node;
	*node = NULL;
	free(delete);
}

static void delete_one_child(t_node **node)
{
	bool	right_child;
	t_node	*replacement;

	right_child = ((*node)->right != NULL);
	if (right_child)
		replacement = (*node)->right;
	else
		replacement = (*node)->left;
	replacement->parent = (*node)->parent;
	delete(node);
	*node = replacement;
}

static void delete_two_children(t_node **node)
{
	t_node	**replacement;

	replacement = leaf(node, true);
	(*node)->key = (*replacement)->key;
	(*node)->val = (*replacement)->val;
	delete(replacement);
}

//if parent is NULL, the node is ROOT
//*node is parent->(left/right)
int		bstree_delete(t_bstree *bstree, t_data key)
{
	t_node	**node;
	t_node	*parent;
	bool	left_child;
	bool	right_child;

	if (!bstree->size)
		return (1);
	node = bstree_find(bstree, key, &parent);
	if (!*node)
		return (1);
	left_child = ((*node)->left != NULL);
	right_child = ((*node)->right != NULL);
	if (left_child && right_child)
		delete_two_children(node);
	else if (left_child || right_child)
		delete_one_child(node);
	else
		delete(node);
	bstree->size--;
	return (1);
}
