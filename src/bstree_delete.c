/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_delete.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 21:49:59 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/21 21:49:59 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

/*
**	Return the address of parent->(left/right) of the replacement node
*/
static t_node	**replacement(t_node **node, bool higher)
{
	if (higher)
	{
		node = &(*node)->right;
		while (*node && (*node)->left)
			node = &(*node)->left;
		return (node);
	}
	node = &(*node)->left;
	while (*node && ((*node)->right))
		node = &(*node)->right;
	return (node);
}

static void	delete_one_child(t_node **node)
{
	bool	right_child;
	t_node	*replacement;

	right_child = ((*node)->right != NULL);
	if (right_child)
		replacement = (*node)->right;
	else
		replacement = (*node)->left;
	replacement->parent = (*node)->parent;
	node_delete(node);
	*node = replacement;
}

static void	delete_two_children(t_node **node)
{
	t_node	**rep;

	rep = replacement(node, true);
	(*node)->key = (*rep)->key;
	(*node)->val = (*rep)->val;
	if ((*rep)->left || (*rep)->right)
		delete_one_child(rep);
	else
		node_delete(rep);
}

/*
**	if parent is NULL, the node is ROOT
**	node is &parent->(left/right)
*/
int	bstree_delete(t_bstree *bstree, t_data key)
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
	printf("Deleting %s\n", key.data);
	left_child = ((*node)->left != NULL);
	right_child = ((*node)->right != NULL);
	if (left_child && right_child)
		delete_two_children(node);
	else if (left_child || right_child)
		delete_one_child(node);
	else
		node_delete(node);
	bstree->size--;
	return (1);
}
