/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_assign.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 09:44:43 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/24 09:45:33 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree_int.h>

int	bstree_assign(t_bstree *bstree, void *key, size_t keysize, void *val)
{
	t_node	**node;
	t_node	*parent;

	node = node_find(bstree, key, keysize, &parent);
	if (!*node)
	{
		*node = node_new(key, keysize, val, parent);
		bstree->size++;
		if (*node)
			return (1);
		return (0);
	}
	if (bstree->del)
		bstree->del((*node)->val);
	(*node)->val = val;
	return (1);
}
