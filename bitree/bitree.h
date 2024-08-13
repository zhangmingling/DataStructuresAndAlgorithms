#ifndef _BITREE_H_
#define _BITREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef char data_t;
typedef struct node_t
{
	data_t data;
	struct node_t *left, *right;
} bitree;

bitree *tree_create();
void preorder(bitree *r);
void inorder(bitree *r);
void postorder(bitree *r);
void layerorder(bitree *r);

#endif