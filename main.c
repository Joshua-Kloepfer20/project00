#include <string.h>
#include <stdlib.h>
#include "linked_list.h"
#include <stdio.h>
int main() {
    struct song_node *x = malloc(sizeof(struct song_node));
    strcpy(x->name, "apples");
    strcpy(x->artist, "ilhgluref");
    int i;
    x = insert_front(x, "Dancing in the Dark", "Bruce Springsteen");
    x = insert_front(x, "Hungry Heart", "Bruce Springsteen");
    x = insert_front(x, "Piano Man", "Billy Joel");
    x = insert_front(x, "We Didn't Start the Fire", "Billy Joel");
    x = insert_front(x, "Don't Stop Believing", "Journey");
    struct song_node *y = find_node(x, "dancing in the dark", "bruce springsteen");
    printf("x points to %s", x->name);
    x = remove_node(x, "piano man", "billy joel");
    x = remove_node(x, "Hungry heArt", "Bruce Springsteen");
    x = remove_node(x, "Don't Stop believing", "Journey");
    print_list(x);
    printf("y is %s by %s\n", y->name, y->artist);
    free_list(x);
    return 0;
}
