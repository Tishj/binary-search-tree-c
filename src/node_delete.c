/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   node_delete.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 20:24:20 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/21 20:30:25 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>
#include <stdlib.h>

void	node_delete(t_node **node)
{
	free(*node);
	*node = NULL;
}
