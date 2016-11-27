//
//  hash.c

#include "hash.h"

HashMap* create_hashmap(int size)
{
    int i;
    HashMap* new_map = (HashMap*)malloc(sizeof(HashMap));
    new_map->size=0;
    new_map->capac=size;
    new_map->current=0;
    new_map->hashArray=(HashElem**) malloc(sizeof(HashElem)*size);

    for(i=0;i<size;i++) new_map->hashArray[i]=NULL;
    return new_map;
}

void insert(HashMap* map, void* data, long key)
{
    //si la tabla esta al 70% hay que aumentar la capacidad.
    map->size++;
    if(map->size*100.0/map->capac>=70) enlarge(map);
    //se crea un nuevo elemento
    HashElem* new_elem=(HashElem*)malloc(sizeof(HashElem));
    new_elem->data=data;
    new_elem->key=key;
    //se inserta y si hay conflicto se resuelve la colicion.
    if (map->hashArray[hash(key,map->capac)]==NULL)
    {
        //printf("dato:%d  key:%d   puesto en un lugar vacio (%d)\n",new_elem->data,new_elem->key,hash(key,map->capac));
        map->hashArray[hash(key,map->capac)]=new_elem;
    }
    else
    {
        //printf("conflicto con posicion (%d)\n",hash(key,map->capac));
        solve_colition(map,new_elem);
    }
}
void erase(HashMap * map, long key)
{
    int pos=hash(key,map->capac);
    int max_pos=pos+map->capac;
    while(1)
    {
        if(pos>max_pos) //ya lo recorrio entero
        {
            //printf("no existe un elemento con llave %ld. \n",key);
            break;
        }

        if(map->hashArray[hash(pos,map->capac)]!=NULL)
        {
            if(map->hashArray[pos%map->capac]->key==key)

            {
                HashElem* delete = map->hashArray[pos%map->capac];
                map->hashArray[pos%map->capac]=NULL;
                free(delete);
                printf("elemento borrado\n");
                break;
            }
        }
        pos++;
    }
}

void* search(HashMap* map ,long key)
{
    int pos=hash(key,map->capac);
    int recorrido_entero=pos+map->capac;
    while(1)
    {
        if(pos>recorrido_entero) //ya lo recorrio entero
        {
            //printf("no existe un elemento con llave %ld. \n",key);
            break;
        }

        if(map->hashArray[pos%map->capac]!=NULL)
        {
            if(map->hashArray[pos%map->capac]->key==key)
            {
                //printf("dato encontrado y retornado!\n");
                return map->hashArray[pos%map->capac]->data;
            }
        }
        pos++;
    }
    return NULL;

}

void* first(HashMap* map)
{
    int i;
    for(i=0;i<map->capac;i++)
    {
        if(map->hashArray[i]!=NULL) return map->hashArray[i]->data;
    }
    printf("no hay datos en el hashmap\n");
    return NULL;
}

void* next(HashMap* map)
{
    int i;
    for(i=map->current;i<map->current+map->capac;i++)
    {
        if(map->hashArray[i%map->capac]!=NULL) return map->hashArray[i%map->capac]->data;
    }
    printf("no hay mas datos que current\n");
    return NULL;
}


void enlarge(HashMap* map)
{   //aumento del 75%
    int new_size=map->capac+map->capac*3/4;
    HashElem** new_array=malloc(sizeof(HashElem)*new_size);
    //salvar el array anterior para insertarlo al nuevo
    HashElem** old_array=map->hashArray;
    int old_array_cap=map->capac;
    //resetear el array viejo
    map->capac=new_size;
    map->size=0;
    map->current=0;
    //llenar el nuevo array de null y ponerlo en el mapa
    int i;
    for(i=0;i<new_size;i++) new_array[i]=NULL;
    map->hashArray=new_array;
    //llenar el mapa de nuevo con los datos que estaban en el antiguo
    for(i=0;i<old_array_cap;i++)
    {
        if(old_array[i]!=NULL)
        {
            if(old_array[i]->data!=NULL && old_array[i]->key/*!=NUL*/)
            {
                insert(map,old_array[i]->data,old_array[i]->key);
                free(old_array[i]);
            }
        }
    }
    free(old_array);
}

int hash(long key, int capac)
{
    int pos;
    //aqui la operacion matematica
    pos=(int)key%capac;
    return pos;
}

void solve_colition(HashMap* map,HashElem* element)
{
    int pos = hash(element->key,map->capac);
    while(1)
    {
        pos++;
        if(map->hashArray[pos%map->capac]==NULL)
        {
            map->hashArray[pos%map->capac]=element;
            //printf("dato:%d  key:%d   puesto en un lugar nuevo(pos:%d) \n",element->data,element->key,pos%map->capac);
            break;
        }
    }
}
