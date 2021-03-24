/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 21:47:36 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/24 09:28:13 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree_int.h>

int	bstree_init(t_bstree *bstree, size_t key_type_size,
	t_compare comp, t_destructor del)
{
	bstree->key_type_size = key_type_size;
	bstree->root = NULL;
	bstree->size = 0;
	if (comp)
		bstree->comp = comp;
	else
		bstree->comp = util_memcmp;
	bstree->del = del;
	return (1);
}
