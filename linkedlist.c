#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "linkedlist.h"

void print_ll_node(ll_node_type *node, FILE *file, int newline)
{
	if (!file)
		file = stdout;
	fprintf(file, T_FMT, node->data);
	if (newline)
		fprintf(file, "\n");
}

void print_ll(ll_type *ll, FILE *file)
{
	if (!file)
		file = stdout;
	ll_node_type *node = ll->root;
	fprintf(file, "[");
	while (node) {
		print_ll_node(node, file, 0);
		if (node->next)
			fprintf(file, ", ");
		node = node->next;
	}
	fprintf(file, "]\n");
}

ll_type *ll_create()
{
	ll_type *ll = (ll_type *) malloc(sizeof(ll_type));
	ll->size = 0;
	ll->root = NULL;
	return ll;
}

void ll_free(ll_type *ll)
{
	ll_node_type *node = ll->root;
	while (node) {
		ll_node_type *next = node->next;
		free(node);
		node = next;
	}
	free(ll);
}

void ll_clear(ll_type *ll)
{
	ll_node_type *node = ll->root;
	while (node) {
		ll_node_type *next = node->next;
		free(node);
		node = next;
	}
	ll->size = 0;
	ll->root = NULL;
}

int ll_isempty(ll_type *ll)
{
	return ll->size == 0;
}

ll_node_type *ll_node_init(T data)
{
	ll_node_type *node = (ll_node_type *) malloc(sizeof(ll_node_type));
	node->data = data;
	node->next = NULL;
	return node;
}

ll_node_type *ll_append(ll_type *ll, T data)
{
	ll_node_type *new_node = ll_node_init(data);
	ll_node_type *node = ll->root;
	ll_node_type *prev;
	while (node) {
		prev = node;
		node = node->next;
	}
	if (!ll->root)
		ll->root = new_node;
	else
		prev->next = new_node;
	ll->size++;
	return new_node;
}

ll_node_type *ll_insert(ll_type *ll, int index, T data)
{
	if (index < 0) {
		index = ll->size + index;
	}
	if (index > ll->size) {
		index = ll->size;
	}

	ll_node_type *new_node = ll_node_init(data);
	if (index == 0) {
		ll_node_type *old_root = ll->root;
		ll->root = new_node;
		new_node->next = old_root;
	} else {
		ll_node_type *node = ll->root;
		ll_node_type *prev;
		int i;
		for (i = 0; i < index; i++) {
			prev = node;
			node = node->next;
		}
		prev->next = new_node;
		new_node->next = node;
	}
	ll->size++;
	return new_node;
}

ll_node_type *ll_get(ll_type *ll, T data)
{
	if (ll_isempty(ll))
		return NULL;
	ll_node_type *node = ll->root;
	while (node) {
		if (node->data == data) {
			return node;
		}
		node = node->next;
	}
	return NULL;
}

ll_node_type *ll_at(ll_type *ll, int index)
{
	if (ll_isempty(ll))
		return NULL;
	if (index < 0)
		index = ll->size + index;
	if (index > ll->size)
		error("%s:%d: index %d out of bounds", __FILE__, __LINE__, index);	
	if (index == 0)
		return ll->root;
	ll_node_type *node = ll->root;
	int i;
	for (i = 0; i < index; i++)
		node = node->next;
	return node;
}

int ll_delete(ll_type *ll, T data)
{
	if (ll_isempty(ll))
		return 0;
	ll_node_type *node = ll->root;
	ll_node_type *prev;
	while (node) {
		if (node->data == data) {
			prev->next = node->next;
			free(node);
			ll->size--;
			return 1;
		}
		prev = node;
		node = node->next;
	}
	return 0;
}

int ll_delete_at(ll_type *ll, int index)
{
	if (ll_isempty(ll))
		return 0;
	if (index < 0)
		index = ll->size + index;
	if (index > ll->size)
		error("%s:%d: index %d out of bounds", __FILE__, __LINE__, index);	
	if (index == 0) {
		ll_node_type *root = ll->root;
		ll->root = ll->root->next;
		free(root);
		ll->size--;
		return 1;
	}
	ll_node_type *node = ll->root;
	ll_node_type *prev;
	int i;
	for (i = 0; i < index; i++) {
		prev = node;
		node = node->next;
	}
	if (!prev)
		prev = ll->root;
	prev->next = node->next;
	free(node);
	ll->size--;
	return 1;
}
