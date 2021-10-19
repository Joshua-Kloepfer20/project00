#include <string.h>
#include <stdlib.h>
#include "work10.h"
int main() {
    struct food *x = malloc(sizeof(struct food));
    strcpy(x->name, "apples");
    x->price = 3.76;
    x->weight = 5.48;
    int i;
    x = insert_front(x, "oranges", 3.85, 6.75);
    x = insert_front(x, "lolypops", .99, .59);
    x = insert_front(x, "chocholate", 2.99, 1.34);
    x = insert_front(x, "cheerios", 5.34, 3.21);
    x = insert_front(x, "potatoes", 5.75, 3.64);
    x = remove_node(x, 5.75);
    x = remove_node(x, 3.76);
    x = remove_node(x, 2.99);
    print_list(x);
    free_list(x);
    return 0;
}