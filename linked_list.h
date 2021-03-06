#ifndef LINKED_LIST_H
#define LINKED_LIST_H
struct song_node {char name[100]; char artist[100]; struct song_node * next;};
void print_list(struct song_node * node);
struct song_node * insert_front(struct song_node * node, char *name, char *artist);
struct song_node * make_list(struct song_node * node, char *name, char *artist);
struct song_node * insert(struct song_node * node, char *name, char *artist);
struct song_node * free_list(struct song_node * node);
struct song_node * remove_node(struct song_node *node, char *name, char *artist);
struct song_node * find_node(struct song_node *node, char *name, char *artist);
struct song_node * find_artist(struct song_node *node, char *artist);
struct song_node * find_random(struct song_node *node);
int length(struct song_node *node);
#endif
