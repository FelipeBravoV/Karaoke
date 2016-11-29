//
//  karaoke.h
//

#ifndef karaoke_h
#define karaoke_h

#include <stdio.h>
#include "list.h"
#include "hash.h"



/*--------------------MENUS PRINCIPALES-----------------------*/
//menu con opciones para iniciar sesion o crear un usuario
void menu_login();

//menu con opciones que puede elegir el usuario cuando ya inicia sesion
//!! Es necesario que ya se haya verifado que el nick existe en la HashMap de usuarios
void menu_usuario(char nick);

//menu que muestra opciones despues de tocar una cancion
void menu_postcancion();

#endif /* karaoke_h */
