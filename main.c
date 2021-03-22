/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/19 17:56:45 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/03/22 22:36:14 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <bstree.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

void	find_element(t_bstree *bstree, void *key, size_t keysize)
{
	t_node **node;

	node = bstree_find(bstree, key, keysize, NULL);
	if (*node)
//		printf("Found key \"%s\", containing value: %d\n", key.data, (int)(unsigned long)(*node)->val.data);
		printf("Found key \"%s\", containing value: %s\n", (char*)key, (char*)(*node)->val);
	else
		printf("Did not find a node with key \"%s\"\n", (char *)key);
}

void	iter_plusplus(t_node *node)
{
	while (node)
	{
		printf("key: %s - val: %s\n", (char *)node->key, (char*)node->val);
		node = node_next(node);
	}
}

void	iter_minmin(t_node *node)
{
	while (node)
	{
//		printf("key: %s - val: %d\n", node->key.data, (int)(unsigned long)node->val.data);
		printf("key: %s - val: %s\n", (char *)node->key, (char*)node->val);
		node = node_prev(node);
	}
}

char	**str2dup(char **original, size_t amount)
{
	char	**dup;
	size_t	i;

	dup = malloc(sizeof(char *) * (amount + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < amount)
	{
		dup[i] = util_strdup(original[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
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
	char		**dup;
	size_t		len;

	len = (sizeof(keys) / sizeof(char*));
	dup = str2dup(keys, len);
	if (!dup)
		return (1);
	srand(time(NULL));
	if (!bstree_init(&bstree, sizeof(char), util_memcmp, free))
		return (1);
	find_element(&bstree, "hello", 5);
	if (!bstree_insert(&bstree, "hello", strlen("hello"), strdup("yeet"), true))
		return (1);
	for (size_t i = 0; i < len; i++)
		if (!bstree_insert(&bstree, keys[i], strlen(keys[i]), dup[i], true))
			return (1);
	printf("yeet\n");
	iter_plusplus(node_lowest(&bstree));
	printf("\n---\n");
	iter_minmin(node_highest(&bstree));
	// if (!bstree_delete(&bstree, "moth", 4))
	// 	return (1);
	if (!bstree_delete(&bstree, "afrika", 6))
		return (1);
	if (!bstree_delete(&bstree, "hello", 5))
		return (1);
	if (!bstree_delete(&bstree, "hila", 4))
		return (1);
	// if (!bstree_delete(&bstree, "yeet", 4))
	// 	return (1);
	if (!bstree_delete(&bstree, "chad", 4))
		return (1);
	// if (!bstree_delete(&bstree, "vogel", 5))
	// 	return (1);
	if (!bstree_delete(&bstree, "boom", 4))
		return (1);
	// if (!bstree_delete(&bstree, "nemo", 4))
	// 	return (1);
	// if (!bstree_delete(&bstree, "nemo", 4))
	// 	return (1);
	for (size_t i = 0; i < sizeof(keys) / sizeof(char*); i++)
		find_element(&bstree, keys[i], strlen(keys[i]));
	find_element(&bstree, "hello", 5);
	bstree_clear(&bstree);
	free(dup);
	return (0);
}
