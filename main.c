/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/19 17:56:45 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/19 18:02:26 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>
#include <stdio.h>

int	main(void)
{
	t_bstree	bstree;
	t_node		**node;

	if (!bstree_init(&bstree, sizeof(char*), sizeof(int)))
		return (1);
	node = bstree_find(&bstree, (t_data){"hello", 5}, NULL);
	if (*node)
		printf("Found key \"hello\", containing value: %d\n", (int)(*node)->val.data);
	else
		printf("Did not find a node with key \"hello\"\n");
	if (!bstree_insert(&bstree, (t_data){"hello", 5}, (t_data){10, 4}, true))
		return (1);
	node = bstree_find(&bstree, (t_data){"hello", 5}, NULL);
	if (*node)
		printf("Found key \"hello\", containing value: %d\n", (int)(*node)->val.data);
	else
		printf("Did not find a node with key \"hello\"\n");
	return (0);
}
