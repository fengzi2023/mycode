#pragma once

#ifdef __cplusplus
extern "C" {
#endif  

typedef struct _rbtree_node_t rbtree_node_t;
struct _rbtree_node_t {
    rbtree_node_t *left;
    rbtree_node_t *right;
    rbtree_node_t *parent;
    int col;
    int key;
    void * val;
};

typedef struct _rbtree_t rbtree_t;
struct _rbtree_t {
    rbtree_node_t *root;
    rbtree_node_t *nil;
};

#define Log(format, ...)  printf(format, ##__VA_ARGS__) 

#define UNCLE_R(n) (n)->parent->parent->right
#define UNCLE_L(n) (n)->parent->parent->left
#define G_PARENT(n) (n)->parent->parent

#define rbtree_col_red 1
#define rbtree_col_black 2

#define IS_RED(n) ((n)->col==rbtree_col_red)
#define IS_BLACK(n) ((n)->col==rbtree_col_black)

#define SET_RED(n) ((n)->col=rbtree_col_red)
#define SET_BLACK(n) ((n)->col=rbtree_col_black)

#define INIT_RBTREE_NODE(nil,n, key, val) do {  \
    (n)->right = (nil);                      \
    (n)->left = (nil);                       \
    (n)->parent = (nil);                     \
    (n)->col = rbtree_col_red;              \
} while (0)

#define root(t) (t)->root

rbtree_t *rbtree_create(void *);
void rbtree_destroy(rbtree_t *tree);

void rbtree_insert_node(rbtree_t *tree,rbtree_node_t *n);
void rbtree_del_node(rbtree_t *tree,rbtree_node_t *n);
//void rbtree_del_node(rbtree_t *tree);

void rbtree_min_node(rbtree_t *tree,rbtree_node_t *n);
void rbtree_max_node(rbtree_t *tree,rbtree_node_t *n);

#ifdef __cplusplus
}
#endif  
