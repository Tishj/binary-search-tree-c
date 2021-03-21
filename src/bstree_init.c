/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 21:47:36 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/21 21:47:36 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>

int	bstree_init(t_bstree *bstree, size_t key_type_size, size_t val_type_size)
{
	bstree->key_type_size = key_type_size;
	bstree->val_type_size = val_type_size;
	bstree->root = NULL;
	bstree->size = 0;
	return (1);
}
