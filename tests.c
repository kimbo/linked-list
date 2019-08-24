#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "linkedlist.h"

void linked_list_test()
{
	/* test creation of linked list */
	ll_type *ll = ll_create();
	assert(ll);
	assert(ll->size == 0);
	assert(ll->root == NULL);

	/* test isempty */
	assert(ll_isempty(ll));

	/* test insertion */
	int num = 10;
	ll_node_type *node = ll_append(ll, num);
	assert(node);
	assert(node->data == num);
	assert(ll->size == 1);
	assert(node->next == NULL);
	assert(ll->root);
	assert(ll->root == node);

	/* test clearing */
	ll_clear(ll);
	assert(ll);
	assert(ll->root == NULL);
	assert(ll->size == 0);

	/* test more insertion */
	node = ll_append(ll, 13);
	node = ll_append(ll, 3);
	node = ll_append(ll, 113);
	assert(ll->size == 3);
	print_ll(ll, NULL);

	/* test insertion at index */
	node = ll_insert(ll, 0, 100);
	print_ll(ll, NULL);
	assert(ll->size == 4);
	assert(ll->root->data == 100);
	assert(ll->root->next->data == 13);

	int i;
	for (i = 0; i < 100; i++)
		(void)ll_insert(ll, 0, i);
	assert(ll->size == 104);
	print_ll(ll, NULL);
	ll_clear(ll);

	/* this will make the program exit */
	//(void)ll_insert(ll, 1, 100);

	(void)ll_insert(ll, 0, 1);
	(void)ll_insert(ll, 0, 2);
	(void)ll_insert(ll, 0, 3);
	print_ll(ll, NULL);
	ll_clear(ll);

	(void)ll_insert(ll, 0, 0);
	(void)ll_insert(ll, 100, 100);
	(void)ll_insert(ll, 0, 3);
	(void)ll_insert(ll, 1, 4);
	(void)ll_insert(ll, -1, -1);
	print_ll(ll, NULL);
	ll_clear(ll);

	for (i = 0; i < 5; i++)
		ll_append(ll, i);
	print_ll(ll, NULL);
	ll_insert(ll, -1, -1);
	(void)ll_insert(ll, -2, -2);
	print_ll(ll, NULL);
	ll_clear(ll);

	for (i = 0; i < 5; i++)
		ll_append(ll, i);

	node = ll_get(ll, 1);
	assert(node);
	assert(node->data == 1);
	print_ll_node(node, NULL, 1);

	(void)ll_insert(ll, 4, 999);
	node = ll_at(ll, 4);
	assert(node);
	assert(node->data == 999);
	print_ll(ll, NULL);

	assert(ll->size == 6);
	int rc = ll_delete(ll, 999);
	assert(rc);
	assert(ll->size == 5);
	print_ll(ll, NULL);

	rc = ll_delete_at(ll, 0);
	assert(rc);
	assert(ll->size == 4);
	print_ll(ll, NULL);

	/* this will throw an index error */
	//rc = ll_delete_at(ll, 5);

	ll_free(ll);
}

int main(int argc, char *argv[])
{
	linked_list_test();
}	
