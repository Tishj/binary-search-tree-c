/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_new.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 09:45:54 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/24 09:46:55 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree_int.h>
#include <stdlib.h>

t_node	*node_new(void *key, size_t keysize, void *val, t_node *parent)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->key = util_memdup(key, keysize);
	if (!node->key)
	{
		free(node);
		return (NULL);
	}
	node->size = keysize;
	node->val = val;
	return (node);
}
