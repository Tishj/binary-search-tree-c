/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/19 17:56:45 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/21 20:56:09 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void	find_element(t_bstree *bstree, t_data key)
{
	t_node **node;

	node = bstree_find(bstree, key, NULL);
	if (*node)
		printf("Found key \"%s\", containing value: %d\n", key.data, (int)(unsigned long)(*node)->val.data);
	else
		printf("Did not find a node with key \"%s\"\n", key.data);
}

void	iter_plusplus(t_node *node)
{
	while (node)
	{
		printf("key: %s\n", node->key.data);
		node = node_next(node);
	}
}

void	iter_minmin(t_node *node)
{
	while (node)
	{
		printf("key: %s\n", node->key.data);
		node = node_prev(node);
	}
}

int	main(void)
{
	t_bstree	bstree;
	t_node		**node;
	char		*keys[] = {
		"yeet",
		"chad",
		"nemo",
		"hila",
		"moth",
		"boom",
		"vogel",
		"afrika"
	};

	srand(time(NULL));
	if (!bstree_init(&bstree, sizeof(char*), sizeof(int)))
		return (1);
	find_element(&bstree, (t_data){"hello", 5});
	if (!bstree_insert(&bstree, (t_data){"hello", 5}, (t_data){(char*)-10, 4}, true))
		return (1);
	for (size_t i = 0; i < sizeof(keys) / sizeof(char*); i++)
		if (!bstree_insert(&bstree, (t_data){keys[i], sizeof(keys[i])}, (t_data){(char *)(rand() % 50), 4}, true))
			return (1);
	iter_plusplus(node_lowest(&bstree));
	printf("\n---\n");
	iter_minmin(node_highest(&bstree));
	if (!bstree_delete(&bstree, (t_data){"moth", 4}))
		return (1);
	if (!bstree_delete(&bstree, (t_data){"afrika", 7}))
		return (1);
	if (!bstree_delete(&bstree, (t_data){"hello", 5}))
		return (1);
	if (!bstree_delete(&bstree, (t_data){"hila", 4}))
		return (1);
	if (!bstree_delete(&bstree, (t_data){"yeet", 4}))
		return (1);
	if (!bstree_delete(&bstree, (t_data){"chad", 4}))
		return (1);
	if (!bstree_delete(&bstree, (t_data){"vogel", 5}))
		return (1);
	if (!bstree_delete(&bstree, (t_data){"boom", 4}))
		return (1);
	if (!bstree_delete(&bstree, (t_data){"nemo", 4}))
		return (1);
	if (!bstree_delete(&bstree, (t_data){"nemo", 4}))
		return (1);
	for (size_t i = 0; i < sizeof(keys) / sizeof(char*); i++)
		find_element(&bstree, (t_data){keys[i], strlen(keys[i])});
	find_element(&bstree, (t_data){"hello", 5});
	bstree_destroy(&bstree);
	return (0);
}
