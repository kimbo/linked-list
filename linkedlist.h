#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define T 	int
#define T_FMT	"%d"

#include <stdio.h>

/* node in a linked list */
struct ll_node
{
	/* data for this node */
	T data;
	/* next node in the list */
	struct ll_node *next;	
};
typedef struct ll_node ll_node_type;

/* linked list structure */
struct linked_list
{
	/* root node */
	struct ll_node *root;

	/* size of linked list */
	int size;
};
typedef struct linked_list ll_type;

/* print out string representation of node to file.
 * print a newline at the end if specified.
 * if file is NULL, print to stdout
 */
void print_ll_node(ll_node_type *node, FILE *file, int newline);

/* print out contents of linked list to file
 * if file is NULL, print to stdout
 */
void print_ll(ll_type *ll, FILE *file);

/* initialize a linked list node with data */
ll_node_type *ll_node_init(T data);

/* create a linked list */
ll_type *ll_create();

/* free memory/resources for linked list */
void ll_free(ll_type *ll);

/* clear all nodes in a linked list */
void ll_clear(ll_type *ll);

/* check if linked list is empty */
int ll_isempty(ll_type *ll);

/* find if node with data exists in list.
 * return node if found, otherwise, return NULL
 */ 
ll_node_type *ll_get(ll_type *ll, T data);

/* get node at given index, or return NULL */
ll_node_type *ll_at(ll_type *ll, int index);

/* append node with data at the end of the list
 * and return the inserted node on success. 
 * otherwise, return NULL
 */
ll_node_type *ll_append(ll_type *ll, T data);

/* insert node at given index */
ll_node_type *ll_insert(ll_type *ll, int index, T data);

/* delete node with data in list (if exists).
 * return 1 if node was present and was deleted,
 * otherwise return 0
 */
int ll_delete(ll_type *ll, T data);

/* delete node at given index (if exists) */
int ll_delete_at(ll_type *ll, int index);

#endif /* LINKEDLIST_H */
