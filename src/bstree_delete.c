/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_delete.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 21:49:59 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/24 09:28:13 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree_int.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

void	swap_keyval(t_node *a, t_node *b)
{
	void	*tmp;

	tmp = a->key;
	a->key = b->key;
	b->key = tmp;

	tmp = a->val;
	a->val = b->val;
	b->val = tmp;
}

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

static void	delete_one_child(t_node **node, t_destructor del)
{
	bool	right_child;
	t_node	*replacement;

	right_child = ((*node)->right != NULL);
	if (right_child)
		replacement = (*node)->right;
	else
		replacement = (*node)->left;
	replacement->parent = (*node)->parent;
	node_delete(node, del);
	*node = replacement;
}

static void	delete_two_children(t_node **node, t_destructor del)
{
	t_node	**rep;

	rep = replacement(node, true);
	swap_keyval(*node, *rep);
	if ((*rep)->left || (*rep)->right)
		delete_one_child(rep, del);
	else
		node_delete(rep, del);
}

/*
**	if parent is NULL, the node is ROOT
**	node is &parent->(left/right)
*/
int	bstree_delete(t_bstree *bstree, void *key, size_t keysize)
{
	t_node	**node;
	t_node	*parent;
	bool	left_child;
	bool	right_child;

	if (!bstree->size)
		return (1);
	node = node_find(bstree, key, keysize, &parent);
	if (!*node)
		return (1);
	left_child = ((*node)->left != NULL);
	right_child = ((*node)->right != NULL);
	if (left_child && right_child)
		delete_two_children(node, bstree->del);
	else if (left_child || right_child)
		delete_one_child(node, bstree->del);
	else
		node_delete(node, bstree->del);
	bstree->size--;
	return (1);
}
