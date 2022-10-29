#include <stdio.h>
#include <stdlib.h>
#include"micros.h"
#include "destinos.h"
#include "tipo.h"
#include "validar.h"
#include <ctype.h>
#include <string.h>
#include "chofer.h"

int inicializarChofer(eChofer chofer[], int tam)
{
    int todoOk = 0;

    if(chofer != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            chofer[i].isEmpty = 1;
        }

        todoOk = 1;
    }
    return todoOk;
}



int hardcodeoChofer(eChofer chofer[], int tamchofer)
{
    int todoOk=0;

    eChofer auxChofer[5] =
    {
        {1,"Carlos Zalazar", 'm'},
        {2,"Andrea Orzuza",'f'},
        {3,"Jazmin Alvarez",'f'},
        {4,"Rich Messina",'m'},
        {5,"Pepe Grillo", 'm'}
    };

    if(chofer!=NULL && tamchofer>0)
    {

        for(int i=0; i<5; i++)
        {
            auxChofer[i].isEmpty=0;
            chofer[i] = auxChofer[i];



        }
      todoOk=1;
    }
      return todoOk;
}

int funcionBuscarChofer(int idChofer, eChofer chofer[], int sizChofer, char nombreChofer[])
{
    int todoOk=0;


    if(chofer!=NULL && sizChofer>0)
    {

        for(int i=0; i<sizChofer; i++)
        {
            if(!chofer[i].isEmpty && chofer[i].id==idChofer)
            {

                strcpy(nombreChofer, chofer[i].nombre);

            }
        }
    todoOk=1;
    }

    return todoOk;
}
