#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <stdio.h>

struct Array {
        int a[100];
        int len;
};

// Stack
// ...
// Queue
// ...
// List
// ...


// Complete Binary Tree
struct CBTree {
        struct Array tree;
};
typedef struct CBTree CBTree;
#define cb_arr tree.a
#define cb_len tree.len

void cb_push(CBTree *, int);
int cb_left(const CBTree *, int);
int cb_right(const CBTree *, int);
int cb_search(const CBTree *, int);
void cb_ancestors(const CBTree *, int);
void cb_descendants(const CBTree *, int);
int cb_height(const CBTree *);
int cb_sibling(const CBTree *, int);
void cb_preorder(const CBTree *, int);
void cb_inorder(const CBTree *, int);
void cb_postorder(const CBTree *, int);
void cb_leaves(const CBTree *, int);
int cb_size(const CBTree *);
int cb_level(const CBTree *, int);

#endif
