//
//  karaoke.h
//

#ifndef karaoke_h
#define karaoke_h

#include <stdio.h>
#include "list.h"
#include "hash.h"

//karaoke struct
typedef struct{
    int song_total;
    HashMap * songs;
    HashMap * users;
}karaoke;
//!!Implementacion incompleta
karaoke * create_karaoke(int song_total);

//song struct
typedef struct{
    char title[30];
    char artist[30];
    char genre[30];
    int year;
    List * lyrics;
}song;
//!!No implementada
song * create_song();

//lyrics_node struct
typedef struct{
    //char line[150];
    //timestamp
}lyrics_node;
//!!No implementada
lyrics_node * create_lyrics_node();

//user struct
typedef struct{
    char nickname[30];
    List * songs_listened;
}user;
//!!No implementada
user * create_user();

//song_listened_node struct
typedef struct{
    char titulo[30];
    int times_heard;
}song_listened_node;
//!!No implementada
song_listened_node * create_song_listened_node();




/*--------------------MENUS PRINCIPALES-----------------------*/
//menu con opciones para iniciar sesion o crear un usuario
void menu_login(karaoke *k);

//menu con opciones que puede elegir el usuario cuando ya inicia sesion
//!! Es necesario que ya se haya verifado que el nick existe en la HashMap de usuarios
void menu_usuario(karaoke *k, char nick);

//menu que muestra opciones despues de tocar una cancion
void menu_postcancion(karaoke *k);

#endif /* karaoke_h */
