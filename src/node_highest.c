/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_highest.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 19:46:41 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/21 20:18:49 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>
#include <stdbool.h>

t_node	*node_highest(t_bstree *bstree)
{
	t_node	*iter;

	iter = bstree->root;
	while (iter && iter->right)
		iter = iter->right;
	return (iter);
}
