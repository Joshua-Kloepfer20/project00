#ifndef LINKED_LIST_H
#define LINKED_LIST_H
struct song_node {char name[100]; char artist[100]; struct song_node * next;};
void print_list(struct song_node * node);
struct song_node * insert_front(struct song_node * node, char *name, char *artist);
struct song_node * free_list(struct song_node * node);
struct song_node* remove_node(struct song_node *node, char *name, char *artist);
#endif
