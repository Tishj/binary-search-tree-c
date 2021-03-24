/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_find.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 09:29:40 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/24 09:32:10 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree_int.h>

void	*bstree_find(t_bstree *bstree, void *key, size_t keysize)
{
	t_node	**node;

	node = node_find(bstree, key, keysize, NULL);
	if (!*node)
		return (NULL);
	return ((*node)->val);
}
