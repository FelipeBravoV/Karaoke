#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>


void menu_login();
void menu_usuario(char);



int main(){
    menu_login();

    return 0;
}

void menu_login(){

    int op,i,pos,end,flag1=0,terminar_programa=0;
    char key,nick,new_nick;

    do{
    clrscr();
    pos = 0;
    end = 0;

        gotoxy(5,2);printf(" MENU DE USUARIO");
        highvideo();textbackground(GREEN);
        gotoxy(2,3);printf(" -INICIAR SESION");
        lowvideo();textbackground(BLACK);
        gotoxy(2,4);printf(" -REGISTRO");
        gotoxy(2,5);printf(" -TERMINAR PROGRAMA");
        do{
            key = getch();
            switch(key)
            {
                case 72: if (pos == 0)
                        pos = 2;
                        else pos--;
                        break;
                case 80: if (pos == 2) pos =0;
                        else pos++;
                        break;
                case 13: end = 1;
            }
            switch(pos)
            {
                case 0: gotoxy(5,2);printf(" MENU DE USUARIO");
                        highvideo();textbackground(GREEN);
                        gotoxy(2,3);printf(" -INICIAR SESION");
                        lowvideo();textbackground(BLACK);
                        gotoxy(2,4);printf(" -REGISTRO");
                        gotoxy(2,5);printf(" -TERMINAR PROGRAMA");
                        flag1=0;
                        break;

                case 1: gotoxy(5,2);printf(" MENU DE USUARIO");
                        gotoxy(2,3);printf(" -INICIAR SESION");
                        highvideo();textbackground(GREEN);
                        gotoxy(2,4);printf(" -REGISTRO");
                        lowvideo();textbackground(BLACK);
                        gotoxy(2,5);printf(" -TERMINAR PROGRAMA");
                        flag1=1;
                        break;

                case 2: gotoxy(5,2);printf(" MENU DE USUARIO");
                        gotoxy(2,3);printf(" -INICIAR SESION");
                        gotoxy(2,4);printf(" -REGISTRO");
                        highvideo();textbackground(GREEN);
                        gotoxy(2,5);printf(" -TERMINAR PROGRAMA");
                        lowvideo();textbackground(BLACK);
                        flag1=2;
                        break;
            }
        }while(!end);

    if(flag1==0){
        clrscr();
        printf(" \n INICIANDO SESION \n");
        printf(" \n -INGRESE SU NICK");
        printf(" : ");
        scanf("%s",&nick);
        menu_usuario(nick);
    }

    if(flag1==1){
        clrscr();
        printf(" \nCREANDO NUEVO USUARIO\n");
        printf(" \nINGRESE EL NICK QUE DESEA OCUPAR: ");
        scanf("%s",&new_nick);
    }

    if(flag1==2)
        terminar_programa=1;

    }while(terminar_programa != 1);
}

void menu_usuario(char nick){

    int op,i,pos,end,flag1=0,terminar_menu=0;
    char key,new_nick;
    clrscr();
    pos = 0;
    end = 0;
    do{
        clrscr();
        gotoxy(5,2);printf(" MENU DE CANCIONES");
        highvideo();textbackground(GREEN);
        gotoxy(2,3);printf(" -ELEGIR CANCION");
        lowvideo();textbackground(BLACK);
        gotoxy(2,4);printf(" -MOSTRAR CANCIONES POR ARTISTA");
        gotoxy(2,5);printf(" -MOSTRAR CANCIONES POR GENERO");
        gotoxy(2,6);printf(" -MOSTRAR CANCIONES POR TITULO");
        gotoxy(2,7);printf(" -SALIR");
        do{
            key = getch();
            switch(key)
            {
                case 72: if (pos == 0)
                        pos = 4;
                        else pos--;
                        break;
                case 80: if (pos == 4) pos =0;
                        else pos++;
                        break;
                case 13: end = 1;
            }
            switch(pos)
            {
                case 0: gotoxy(5,2);printf(" MENU DE CANCIONES");
                        highvideo();textbackground(GREEN);
                        gotoxy(2,3);printf(" -ELEGIR CANCION");
                        lowvideo();textbackground(BLACK);
                        gotoxy(2,4);printf(" -MOSTRAR CANCIONES POR ARTISTA");
                        gotoxy(2,5);printf(" -MOSTRAR CANCIONES POR GENERO");
                        gotoxy(2,6);printf(" -MOSTRAR CANCIONES POR TITULO");
                        gotoxy(2,7);printf(" -SALIR");
                        flag1=0;
                        break;

                case 1: gotoxy(5,2);printf(" MENU DE CANCIONES");
                        gotoxy(2,3);printf(" -ELEGIR CANCION");
                        highvideo();textbackground(GREEN);
                        gotoxy(2,4);printf(" -MOSTRAR CANCIONES POR ARTISTA");
                        lowvideo();textbackground(BLACK);
                        gotoxy(2,5);printf(" -MOSTRAR CANCIONES POR GENERO");
                        gotoxy(2,6);printf(" -MOSTRAR CANCIONES POR TITULO");
                        gotoxy(2,7);printf(" -SALIR");
                        flag1=1;
                        break;

                case 2: gotoxy(5,2);printf(" MENU DE CANCIONES");
                        gotoxy(2,3);printf(" -ELEGIR CANCION");
                        gotoxy(2,4);printf(" -MOSTRAR CANCIONES POR ARTISTA");
                        highvideo();textbackground(GREEN);
                        gotoxy(2,5);printf(" -MOSTRAR CANCIONES POR GENERO");
                        lowvideo();textbackground(BLACK);
                        gotoxy(2,6);printf(" -MOSTRAR CANCIONES POR TITULO");
                        gotoxy(2,7);printf(" -SALIR");
                        flag1=2;
                        break;

                case 3: gotoxy(5,2);printf(" MENU DE CANCIONES");
                        gotoxy(2,3);printf(" -ELEGIR CANCION");
                        gotoxy(2,4);printf(" -MOSTRAR CANCIONES POR ARTISTA");
                        lowvideo();textbackground(BLACK);
                        gotoxy(2,5);printf(" -MOSTRAR CANCIONES POR GENERO");
                        highvideo();textbackground(GREEN);
                        gotoxy(2,6);printf(" -MOSTRAR CANCIONES POR TITULO");
                        lowvideo();textbackground(BLACK);
                        gotoxy(2,7);printf(" -SALIR");
                        flag1=3;
                        break;
                case 4: gotoxy(5,2);printf(" MENU DE CANCIONES");
                        gotoxy(2,3);printf(" -ELEGIR CANCION");
                        gotoxy(2,4);printf(" -MOSTRAR CANCIONES POR ARTISTA");
                        lowvideo();textbackground(BLACK);
                        gotoxy(2,5);printf(" -MOSTRAR CANCIONES POR GENERO");
                        gotoxy(2,6);printf(" -MOSTRAR CANCIONES POR TITULO");
                        highvideo();textbackground(GREEN);
                        gotoxy(2,7);printf(" -SALIR");
                        lowvideo();textbackground(BLACK);
                        flag1=4;
                        break;


                }

        }while(!end);

        if(flag1==4)
            terminar_menu=1;

    }while(terminar_menu != 1);
}
