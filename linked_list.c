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
    struct song_node *x = node;
    struct song_node *y = node;
    if (strcasecmp(node->name, name) == 0 && strcasecmp(node->artist, artist)) {
        x = node->next;
        free(node);
        return x;
    }
    while (x != NULL) {
        if (strcasecmp(x->name, name) == 0 && strcasecmp(x->artist, artist)) {
            y->next = x->next;
            free(x);
            return node;
        }
        y = x;
        x = x->next;
    }
    return node;
}
