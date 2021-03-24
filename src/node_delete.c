/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_delete.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 20:24:20 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/24 09:28:13 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree_int.h>
#include <stdlib.h>

/*
**	Free the node and set its corresponding parent->(right/left) pointer to NULL
*/
void	node_delete(t_node **node, t_destructor del)
{
	if (del)
		del((*node)->val);
	free((*node)->key);
	free(*node);
	*node = NULL;
}
