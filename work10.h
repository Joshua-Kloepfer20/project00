#ifndef WORK10_H
#define WORK10_H
struct food {char name[100]; float price; float weight; struct food * next;};
void print_list(struct food * node);
struct food * insert_front(struct food * node, char *name, float price, float weight);
struct food * free_list(struct food * node);
struct food* remove_node(struct food *node, float data);
#endif
