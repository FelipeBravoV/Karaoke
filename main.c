#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

#include "karaoke.h"
#include "list.h"
#include "hash.h"

int main(){
    karaoke * k = create_karaoke(10);
    menu_login(k);
    return 0;
}


