#ifndef LIBRARY_H
#define LIBRARY_H
struct song_node ** make_lib();
void new_song(struct song_node **lib, char *name, char *artist);
void print_lib(struct song_node ** lib);
void print_lib_letter(struct song_node ** lib, char letter);
void print_lib_artist(struct song_node ** lib, char *artist);
void remove_song(struct song_node **lib, char *name, char *artist);
struct song_node * find_song(struct song_node **lib, char *name, char *artist);
struct song_node * lib_find_artist(struct song_node **lib, char *artist);
void free_lib(struct song_node **lib);
#endif