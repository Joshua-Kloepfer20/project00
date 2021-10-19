#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"
void print_list(struct song_node * node) {
    if (node != NULL) {
        printf("%s by %s", node->name, node->artist);
        print_list(node->next);
    }
}

struct song_node * insert_front(struct song_node * node, char *name, char *artist) {
    struct song_node *x = malloc(sizeof(struct song_node));
    strcpy(x->name, name);
    strcpy(x->artist, artist)
    x->next = node;
    return x;
}

struct song_node * free_list(struct song_node * node) {
    if (node != NULL) {
        return free_list(node->next);
        free(node);
    }
    else {
        return node;
    }
}

struct song_node * remove_node(struct song_node *node, float data) {
    struct song_node *x = node;
    struct song_node *y = node;
    if (strcmp(node->name, data) == 0) {
        x = node->next;
        free(node);
        return x;
    }
    while (x != NULL) {
        if (strcmp(x->name == data) == 0) {
            y->next = x->next;
            free(x);
            return node;
        }
        y = x;
        x = x->next;
    }
    return node;
}
