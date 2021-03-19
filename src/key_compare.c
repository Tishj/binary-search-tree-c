/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_compare.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/19 16:21:18 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/19 17:20:59 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>

/*
**	compares at max min(elem1->size, elem2->size) bytes
**	sets 'less' and returns whether elem1 and elem2 are equal
*/
bool		compare(t_data *elem1, t_data *elem2, bool *greater, bool *less)
{
	size_t	compare_size;
	int		res;

	if (elem1->size > elem2->size)
		compare_size = elem2->size;
	else
		compare_size = elem1->size;
	res = util_memcmp(elem1->data, elem2->data, compare_size);
	if (greater)
		*greater = (res > 0);
	if (less)
		*less = (0 > res);
	return (!res);
}
