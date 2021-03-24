/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_int.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/19 14:36:14 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/19 16:35:23 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSTREE_H
# define BSTREE_H

#include <bstree_int.h>
#include <stdbool.h>

void			bstree_clear(t_bstree *bstree);
int				bstree_delete(t_bstree *bstree, void *key, size_t keysize);
int				bstree_init(t_bstree *bstree, size_t key_type_size,
				t_compare comp, t_destructor del);
void			*bstree_find(t_bstree *bstree, void *key, size_t keysize);
int				bstree_insert(t_bstree *bstree, void *key, size_t keysize,
				void *data, bool overwrite);

t_node			*node_next(t_node *node);
t_node			*node_prev(t_node *node);
t_node			*node_lowest(t_bstree *bstree);
t_node			*node_highest(t_bstree *bstree);

#endif
