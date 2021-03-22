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

#define BLACK true
#define RED false

typedef struct	s_data
{
	char		*data;
	size_t		size;
}				t_data;

typedef void (*t_destructor)(void *);
typedef int (*t_compare)(void *a, void *b, size_t size);

typedef struct s_node	t_node;

struct	s_node
{
	void		*key;
	size_t		size;
	void		*val;
	t_node		*right;
	t_node		*left;
	t_node		*parent;
};

typedef struct	s_bstree
{
	size_t			size;
	size_t			key_type_size;
	t_node			*root;
	// t_node			*low;
	// t_node			*high;
	t_compare		comp;
	t_destructor	del;
}				t_bstree;

void			bstree_clear(t_bstree *bstree);
int				bstree_delete(t_bstree *bstree, void *key, size_t keysize);
t_node			**bstree_find(t_bstree *bstree, void *key, size_t keysize, t_node **parent);
int				bstree_init(t_bstree *bstree, size_t key_type_size,
				t_compare comp, t_destructor del);
int				bstree_insert(t_bstree *bstree, void *key, size_t keysize,
				void *data, bool overwrite);

void			node_delete(t_node **node, t_destructor del);
t_node			*node_next(t_node *node);
t_node			*node_prev(t_node *node);
t_node			*node_lowest(t_bstree *bstree);
t_node			*node_highest(t_bstree *bstree);

bool			compare(t_data *elem1, t_data *elem2, bool *greater, bool *less);

int				util_atoi(char *str);
size_t			util_strlen(char *str);
void			util_bzero(void *dest, size_t n);
void			util_memcpy(void *dest, void *src, size_t n);
int				util_memcmp(void *dest, void *src, size_t n);
int				util_strncmp(char *str1, char *str2, size_t n);
char			*util_strdup(char *str);
size_t			util_strnlen(char *str, size_t n);
void			util_strncpy(char *dest, char *src, size_t n);
void			util_swap(void *a, void *b, size_t type_size);

#endif
