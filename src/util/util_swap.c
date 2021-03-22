/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   util_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/21 22:09:47 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/21 22:27:19 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>
#include <unistd.h>
#include <stdlib.h>

void	util_swap(void *a, void *b, size_t type_size)
{
	void	*tmp;

	tmp = malloc(type_size);
	if (!tmp)
		exit(1);
	util_memcpy(tmp, a, type_size);
	util_memcpy(a, b, type_size);
	util_memcpy(b, tmp, type_size);
	free(tmp);
}
