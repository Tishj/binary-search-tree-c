/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/19 14:36:14 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/19 16:35:23 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSTREE_H
# define BSTREE_H

#include <stddef.h>
#include <stdbool.h>

typedef struct	s_data
{
	size_t		size;
	char		*data;
}				t_data;

typedef struct s_node	t_node;

struct	s_node
{
	t_data		key;
	t_data		val;
	t_node		*right;
	t_node		*left;
	t_node		*parent;
};

typedef struct	s_bstree
{
	size_t		size;
	size_t		key_type_size;
	size_t		val_type_size;
	t_node		*root;
}				t_bstree;

int				bstree_delete(t_bstree *bstree, t_data key);
void			**bstree_find(t_bstree *bstree, t_data key, t_node **parent);
int				bstree_init(t_bstree *bstree, size_t key_type_size, size_t val_type_size);
int				bstree_insert(t_bstree *bstree, t_data key, t_data val, bool overwrite);

bool			compare(t_data *elem1, t_data *elem2, bool *greater, bool *less);

#endif
