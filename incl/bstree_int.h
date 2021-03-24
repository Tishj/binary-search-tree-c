/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bstree_int.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/24 09:19:53 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/24 09:26:11 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSTREE_INT_H
# define BSTREE_INT_H

#include <stddef.h>

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
	t_compare		comp;
	t_destructor	del;
}				t_bstree;

int				util_atoi(char *str);
size_t			util_strlen(char *str);
void			util_bzero(void *dest, size_t n);
void			util_memcpy(void *dest, void *src, size_t n);
int				util_memcmp(void *dest, void *src, size_t n);
void			*util_memdup(void *src, size_t size);
int				util_strncmp(char *str1, char *str2, size_t n);
char			*util_strdup(char *str);
size_t			util_strnlen(char *str, size_t n);
void			util_strncpy(char *dest, char *src, size_t n);
void			util_swap(void *a, void *b, size_t type_size);

void			node_delete(t_node **node, t_destructor del);
t_node			**node_find(t_bstree *bstree, void *key,
				size_t keysize, t_node **parent);

#endif
