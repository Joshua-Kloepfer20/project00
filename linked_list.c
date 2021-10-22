#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"
void print_list(struct song_node * node) {
    while (node != NULL) {
        printf("%s by %s\n", node->name, node->artist);
    	node = node->next;
}
}

struct song_node * insert_front(struct song_node * node, char *name, char *artist) {
    struct song_node *x = malloc(sizeof(struct song_node));
    strcpy(x->name, name);
    strcpy(x->artist, artist);
    x->next = node;
    return x;
}

struct song_node * free_list(struct song_node * node) {
    struct song_node *x = node;
    while (node != NULL) {
	x = node->next;
        printf("Freeing %s\n", node->name);
	free(node);
	node = x;
    }
    return node;
}

struct song_node * remove_node(struct song_node *node, char *name, char *artist) {
//    printf("attempting to remove song: %s by %s\n", name, artist);
    struct song_node *x = node;
    struct song_node *y = node;
    if (strcasecmp(node->name, name) == 0 && strcasecmp(node->artist, artist) == 0) {
        x = node->next;
        free(node);
//	printf("removed song: %s by %s\n", name, artist);
        return x;
    }
    while (x != NULL) {
        if (strcasecmp(x->name, name) == 0 && strcasecmp(x->artist, artist) == 0) {
            y->next = x->next;
            free(x);
//	    printf("removed song: %s by %s\n", name, artist);
            return node;
        }
        y = x;
        x = x->next;
    }
    return node;
}
struct song_node * find_node(struct song_node *node, char *name, char *artist) {
   while (node != NULL) {
       if (strcasecmp(node->name, name) == 0 && strcasecmp(node->artist, artist) == 0) {
           return node;
}
       node = node->next;
}
  return node;
}
