/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_delete.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 21:49:59 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/22 21:03:29 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>

void	swap_data(t_data *a, t_data *b)
{
	t_data	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
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

	//Get the replacement node
	rep = replacement(node, true);
	//Swap the key and val between *node and *rep
	swap_data(&(*node)->key, &(*rep)->key);
	swap_data(&(*node)->val, &(*rep)->val);
	//If replacement has a child
	printf("replacement: %s : %d\n", (*rep)->key.data, (int)(unsigned long)(*rep)->val.data);
	if ((*rep)->left || (*rep)->right)
		delete_one_child(rep);
	//If it's a leaf node
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
	//Check if it even exists in the tree
	node = bstree_find(bstree, key, &parent);
	if (!*node)
		return (1);
	printf("Deleting %s\n", key.data);
	//Check if and how many children it has
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
