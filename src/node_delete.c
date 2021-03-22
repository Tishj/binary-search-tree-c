/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_delete.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 20:24:20 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/22 20:40:16 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>
#include <stdlib.h>

/*
**	Free the node and set its corresponding parent->(right/left) pointer to NULL
*/
void	node_delete(t_node **node)
{
	free(*node);
	*node = NULL;
}
