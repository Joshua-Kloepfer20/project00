#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"
void print_list(struct song_node * node) {
    printf("[ ");
    while (node != NULL) {
        printf("{%s, %s} | ", node->name, node->artist);
    	node = node->next;
}
    printf("]\n");
}
struct song_node * make_list(struct song_node * node, char *name, char *artist) {
    srand(time(NULL));
    struct song_node *x = malloc(sizeof(struct song_node));
    strcpy(x->name, name);
    strcpy(x->artist, artist);
    x->next = NULL;
    return x;
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
    printf("this song does not exist\n");
    return NULL;
}
struct song_node * insert(struct song_node * node, char *name, char *artist) {
    if (node == NULL) {
        return make_list(node, name, artist);
    }
    struct song_node *x = node;
    if (strcasecmp(x->artist, artist) > 0 || (strcasecmp(x->artist, artist) == 0 && strcasecmp(x->name, name) > 0)) {
        struct song_node *newNode = malloc(sizeof(struct song_node));
        strcpy(newNode->name, name);
        strcpy(newNode->artist, artist);
        newNode->next = node;
        return newNode;
    }
    while (x->next != NULL) {
        if (strcasecmp(x->next->artist, artist) > 0 || (strcasecmp(x->next->artist, artist) == 0 && strcasecmp(x->next->name, name) > 0)) {
            struct song_node *newNode = malloc(sizeof(struct song_node));
            strcpy(newNode->name, name);
            strcpy(newNode->artist, artist);
            newNode->next = x->next;
            x->next = newNode;
            return node;
        }
        x = x->next;
    }
    struct song_node *newNode = malloc(sizeof(struct song_node));
    strcpy(newNode->name, name);
    strcpy(newNode->artist, artist);
    x->next = newNode;
    newNode->next = NULL;
    return node;
}
struct song_node * find_artist(struct song_node *node, char *artist) {
    while (node != NULL) {
       if (strcasecmp(node->artist, artist) == 0) {
           return node;
}
       node = node->next;
}
  return node;
}
int length(struct song_node *node) {
    int x = 0;
    while (node != NULL) {
        x += 1;
        node = node->next;
    }
    return x;
}
struct song_node * find_random(struct song_node *node) {
    int x = rand() % length(node);
    while (x > 0) {
        node = node->next;
        x -= 1;
    }
    return node;
}