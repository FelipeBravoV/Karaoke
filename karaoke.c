//
//  karaoke.c
//
#include <stdlib.h>
#include <conio2.h>

#include "karaoke.h"
#include "list.h"
#include "hash.h"

/*----------------FUNCIONES "create..."-----------*/
karaoke * create_karaoke(int song_total){
    karaoke * k = malloc(sizeof(karaoke));
    k->songs = create_hashmap(song_total*2);
    k->users = create_hashmap(50);
    k->song_total = song_total;
    return k;
}
//create_...
//create_...

/*-------------------MENUS PRINCIPALES------------*/
void menu_login(karaoke *k){

    int op,i,pos,end,flag1=0,terminar_programa=0;
    char key,nick,new_nick;                          //declaracion de variables

    do{
        clrscr();
        pos = 0;
        end = 0;

        gotoxy(5,2);printf(" MENU DE USUARIO");
        highvideo();textbackground(RED);
        gotoxy(2,3);printf(" -INICIAR SESION");
        lowvideo();textbackground(BLACK);
        gotoxy(2,4);printf(" -REGISTRO");
        gotoxy(2,5);printf(" -TERMINAR PROGRAMA");
        do{
            key = getch();
            //recibe una entrada por teclado
            //evalua que tecla se apreto y dependiendo de eso cambia la opcion marcada en el menu
            switch(key){
                case 72: if (pos == 0)
                        pos = 2;
                        else pos--;
                        break;
                case 80: if (pos == 2) pos =0;
                        else pos++;
                        break;
                case 13: end = 1;
            }
            switch(pos){
                case 0: gotoxy(5,2);printf(" MENU DE USUARIO");
                        highvideo();textbackground(RED);
                        gotoxy(2,3);printf(" -INICIAR SESION");
                        lowvideo();textbackground(BLACK);
                        gotoxy(2,4);printf(" -REGISTRO");
                        gotoxy(2,5);printf(" -TERMINAR PROGRAMA");
                        flag1=0;
                        break;

                case 1: gotoxy(5,2);printf(" MENU DE USUARIO");
                        gotoxy(2,3);printf(" -INICIAR SESION");
                        highvideo();textbackground(RED);
                        gotoxy(2,4);printf(" -REGISTRO");
                        lowvideo();textbackground(BLACK);
                        gotoxy(2,5);printf(" -TERMINAR PROGRAMA");
                        flag1=1;
                        break;

                case 2: gotoxy(5,2);printf(" MENU DE USUARIO");
                        gotoxy(2,3);printf(" -INICIAR SESION");
                        gotoxy(2,4);printf(" -REGISTRO");
                        highvideo();textbackground(RED);
                        gotoxy(2,5);printf(" -TERMINAR PROGRAMA");
                        lowvideo();textbackground(BLACK);
                        flag1=2;
                        break;
            }
        }while(end != 1);

        switch(flag1){

            case 0: clrscr();
                    printf(" \n INICIANDO SESION \n");
                    printf(" \n -INGRESE SU NICK");
                    printf(" : ");
                    scanf("%s",&nick);
                    //!!AQUI ANTES DE IMPRIMIR EL MENU
                    //!!DEBERIA IR UNA FUNCION QUE VALIDE SI NICK ESTA EN EL ARCHIVO, Y DEPENDIENDO DE ESO SE LLAMA A MENU USUARIO
                    menu_usuario(k, nick);
                    break;

            case 1: clrscr();
                    printf(" \n CREANDO NUEVO USUARIO\n");
                    printf(" \n INGRESE EL NICK QUE DESEA OCUPAR: ");
                    scanf("%s",&new_nick);                      //AQUI DEBE IR TAMBIEN UNA FUNCION QUE VALIDE SI EL NUEVO NICK INGRESADO NO ESTE YA EN EL ARCHIVO
                    break;

            case 2: terminar_programa=1;
                    break;
        }

    }while(terminar_programa != 1);
}

void menu_usuario(karaoke *k, char nick){

    int op,i,pos,end,flag2=0,terminar_menu=0;
    char key,new_nick,song_name;
    clrscr();

    do{
        pos = 0;
        end = 0;

        clrscr();

        gotoxy(5,2);printf(" MENU DE CANCIONES");
        highvideo();textbackground(RED);
        gotoxy(2,3);printf(" -ELEGIR CANCION");
        lowvideo();textbackground(BLACK);
        gotoxy(2,4);printf(" -MOSTRAR CANCIONES POR ARTISTA");
        gotoxy(2,5);printf(" -MOSTRAR CANCIONES POR GENERO");
        gotoxy(2,6);printf(" -MOSTRAR CANCIONES POR TITULO");
        gotoxy(2,7);printf(" -SALIR");
        do{
            key = getch();

            switch(key){
                case 72: if (pos == 0)
                        pos = 4;
                        else pos--;
                        break;
                case 80: if (pos == 4) pos =0;
                        else pos++;
                        break;
                case 13: end = 1;
            }

            switch(pos){
                case 0: gotoxy(5,2);printf(" MENU DE CANCIONES");
                        highvideo();textbackground(RED);
                        gotoxy(2,3);printf(" -ELEGIR CANCION");
                        lowvideo();textbackground(BLACK);
                        gotoxy(2,4);printf(" -MOSTRAR CANCIONES POR ARTISTA");
                        gotoxy(2,5);printf(" -MOSTRAR CANCIONES POR GENERO");
                        gotoxy(2,6);printf(" -MOSTRAR CANCIONES POR TITULO");
                        gotoxy(2,7);printf(" -SALIR");
                        flag2=0;
                        break;

                case 1: gotoxy(5,2);printf(" MENU DE CANCIONES");
                        gotoxy(2,3);printf(" -ELEGIR CANCION");
                        highvideo();textbackground(RED);
                        gotoxy(2,4);printf(" -MOSTRAR CANCIONES POR ARTISTA");
                        lowvideo();textbackground(BLACK);
                        gotoxy(2,5);printf(" -MOSTRAR CANCIONES POR GENERO");
                        gotoxy(2,6);printf(" -MOSTRAR CANCIONES POR TITULO");
                        gotoxy(2,7);printf(" -SALIR");
                        flag2=1;
                        break;

                case 2: gotoxy(5,2);printf(" MENU DE CANCIONES");
                        gotoxy(2,3);printf(" -ELEGIR CANCION");
                        gotoxy(2,4);printf(" -MOSTRAR CANCIONES POR ARTISTA");
                        highvideo();textbackground(RED);
                        gotoxy(2,5);printf(" -MOSTRAR CANCIONES POR GENERO");
                        lowvideo();textbackground(BLACK);
                        gotoxy(2,6);printf(" -MOSTRAR CANCIONES POR TITULO");
                        gotoxy(2,7);printf(" -SALIR");
                        flag2=2;
                        break;

                case 3: gotoxy(5,2);printf(" MENU DE CANCIONES");
                        gotoxy(2,3);printf(" -ELEGIR CANCION");
                        gotoxy(2,4);printf(" -MOSTRAR CANCIONES POR ARTISTA");
                        gotoxy(2,5);printf(" -MOSTRAR CANCIONES POR GENERO");
                        highvideo();textbackground(RED);
                        gotoxy(2,6);printf(" -MOSTRAR CANCIONES POR TITULO");
                        lowvideo();textbackground(BLACK);
                        gotoxy(2,7);printf(" -SALIR");
                        flag2=3;
                        break;

                case 4: gotoxy(5,2);printf(" MENU DE CANCIONES");
                        gotoxy(2,3);printf(" -ELEGIR CANCION");
                        gotoxy(2,4);printf(" -MOSTRAR CANCIONES POR ARTISTA");
                        gotoxy(2,5);printf(" -MOSTRAR CANCIONES POR GENERO");
                        gotoxy(2,6);printf(" -MOSTRAR CANCIONES POR TITULO");
                        highvideo();textbackground(RED);
                        gotoxy(2,7);printf(" -SALIR");
                        lowvideo();textbackground(BLACK);
                        flag2=4;
                        break;


                }

        }while(end != 1);

        switch(flag2){

            case 0: clrscr();
                    printf(" \n INGRESE EL NOMBRE DE LA CANCION");  //se recibe una palabra para buscar una cancion
                    printf(" \n : ");
                    scanf("%s",&song_name);
                    menu_postcancion(k);
                    break;

            case 1: clrscr(); //MUESTRA LAS CANCIONES ORDENADAS POR ARTISTA
                    break;

            case 2: clrscr();  //MUESTRA LAS CANCIONES ORDENADAS POR GENERO
                    break;

            case 3: clrscr();  //MUESTRA LAS CANCIONES ORDENADAS POR TITULO
                    break;

            case 4: terminar_menu=1;  //PARA DEVOLVERSE AL MENU DE LOGIN
                    break;
        }

    }while(terminar_menu != 1);
}

void menu_postcancion(karaoke *k){

    int op,i,pos,end,flag3=0,terminar_menu2=0;
    char key;                          //declaracion de variables

    do{
    clrscr();
    pos = 0;
    end = 0;

        gotoxy(5,2);printf(" MENU DE CANCION FINALIZADA");
        highvideo();textbackground(RED);
        gotoxy(2,3);printf(" -REPRODUCIR CANCION NUEVAMENTE");
        lowvideo();textbackground(BLACK);
        gotoxy(2,4);printf(" -REPRODUCIR CANCION SUGERIDA 1");
        gotoxy(2,5);printf(" -REPRODUCIR CANCION SUGERIDA 2");
        gotoxy(2,6);printf(" -SALIR");
        do{
            key = getch();
            switch(key){                           //recibe una entrada por teclado, evalua que tecla se apreto y dependiendo de eso cambia la opcion marcada en el menu
                case 72: if (pos == 0)
                        pos = 3;
                        else pos--;
                        break;
                case 80: if (pos == 3) pos =0;
                        else pos++;
                        break;
                case 13: end = 1;
            }
            switch(pos){
                case 0: gotoxy(5,2);printf(" MENU DE CANCION FINALIZADA");
                        highvideo();textbackground(RED);
                        gotoxy(2,3);printf(" -REPRODUCIR CANCION NUEVAMENTE");
                        lowvideo();textbackground(BLACK);
                        gotoxy(2,4);printf(" -REPRODUCIR CANCION SUGERIDA 1");
                        gotoxy(2,5);printf(" -REPRODUCIR CANCION SUGERIDA 2");
                        gotoxy(2,6);printf(" -SALIR");
                        flag3=0;
                        break;

                case 1: gotoxy(5,2);printf(" MENU DE CANCION FINALIZADA");
                        gotoxy(2,3);printf(" -REPRODUCIR CANCION NUEVAMENTE");
                        highvideo();textbackground(RED);
                        gotoxy(2,4);printf(" -REPRODUCIR CANCION SUGERIDA 1");
                        lowvideo();textbackground(BLACK);
                        gotoxy(2,5);printf(" -REPRODUCIR CANCION SUGERIDA 2");
                        gotoxy(2,6);printf(" -SALIR");
                        flag3=1;
                        break;

                case 2: gotoxy(5,2);printf(" MENU DE CANCION FINALIZADA");
                        gotoxy(2,3);printf(" -REPRODUCIR CANCION NUEVAMENTE");
                        gotoxy(2,4);printf(" -REPRODUCIR CANCION SUGERIDA 1");
                        highvideo();textbackground(RED);
                        gotoxy(2,5);printf(" -REPRODUCIR CANCION SUGERIDA 2");
                        lowvideo();textbackground(BLACK);
                        gotoxy(2,6);printf(" -SALIR");
                        flag3=2;
                        break;

                case 3: gotoxy(5,2);printf(" MENU DE CANCION FINALIZADA");
                        gotoxy(2,3);printf(" -REPRODUCIR CANCION NUEVAMENTE");
                        gotoxy(2,4);printf(" -REPRODUCIR CANCION SUGERIDA 1");
                        gotoxy(2,5);printf(" -REPRODUCIR CANCION SUGERIDA 2");
                        highvideo();textbackground(RED);
                        gotoxy(2,6);printf(" -SALIR");
                        lowvideo();textbackground(BLACK);
                        flag3=3;
            }
        }while(end != 1);

        switch(flag3){

            case 0: break;    //OPCION PARA VOLVER A REPRODUCIR LA CANCION

            case 1: break;   //OPCION PARA TOCAR UNA CANCION SUGERIDA

            case 2: break;    //OPCION PARA TOCAR UNA CANCION SUGERIDA

            case 3: terminar_menu2=1;   //VOLVER AL MENU DE USUARIO
                    break;
        }

    }while(terminar_menu2 != 1);

}
