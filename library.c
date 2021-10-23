#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"
#include "library.h"
struct song_node ** make_lib() {
    srand(time(NULL));
    struct song_node ** library = malloc(27 * sizeof(struct song_node *));
    int i;
    for (i = 0; i < 27; i++) {
        library[i] = NULL;
    }
    return library;
}
void new_song(struct song_node **lib, char *name, char *artist) {
    char artist1;
    strncpy(&artist1, artist, 1);
    if (artist1 >= 97) {
        lib[artist1 - 97] = insert(lib[artist1 - 97], name, artist);
    }
    else {
        lib[artist1 - 65] = insert(lib[artist1 - 65], name, artist);
    }
}
void print_lib(struct song_node ** lib) {
    int i;
    for (i = 0; i < 27; i++) {
        if (lib[i] != NULL) {
            printf("%c: ", i + 97);
            print_list(lib[i]);
        }
    }
}
void print_lib_letter(struct song_node ** lib, char letter) {
    if (letter < 97) {
        letter += 32;
    }
    printf("%c: ", letter);
    print_list(lib[letter - 97]);
}
void print_lib_artist(struct song_node ** lib, char *artist) {
    char artist1;
    strncpy(&artist1, artist, 1);
    if (artist1 < 97) {
        artist1 += 32;
    }
    struct song_node * x = find_artist(lib[artist1 - 97], artist);
    printf("[ ");
    while (x != NULL && strcasecmp(x->artist, artist) == 0) {
        printf("{%s, %s} | ", x->name, x->artist);
        x = x->next;
    }
    printf("]\n");
}
void remove_song(struct song_node **lib, char *name, char *artist) {
    char artist1;
    strncpy(&artist1, artist, 1);
    if (artist1 < 97) {
        artist1 += 32;
    }
    lib[artist1 - 97] = remove_node(lib[artist1 - 97], name, artist);
}
struct song_node * find_song(struct song_node **lib, char *name, char *artist) {
    char artist1;
    strncpy(&artist1, artist, 1);
    if (artist1 < 97) {
        artist1 += 32;
    }
    return find_node(lib[artist1 - 97], name, artist);
}

void free_lib(struct song_node **lib) {
    int i;
    for (i = 0; i < 27; i++) {
        free_list(lib[i]);
        lib[i] = NULL;
    }
}

struct song_node * lib_find_artist(struct song_node **lib, char *artist) {
    char artist1;
    strncpy(&artist1, artist, 1);
    if (artist1 < 97) {
        artist1 += 32;
    }
    return find_artist(lib[artist1 - 97], artist);
}
void shuffle(struct song_node **lib) {
    srand(time(NULL));
    int i;
    struct song_node * y;
    for (i = 0; i < 3; i++) {
        int x = rand() % 26;
        y = find_random(lib[x]);
        printf("{%s, %s}\n", y->name, y->artist);
    }
}