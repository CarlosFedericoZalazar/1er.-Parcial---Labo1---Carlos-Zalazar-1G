#include <stdio.h>
#include <stdlib.h>
#include"micros.h"
#include "destinos.h"
#include "tipo.h"
#include "empresa.h"
#include <string.h>
#include "validar.h"

int hardcodeoEmpresa(eEmpresa empresa[], int tam, int* pId, int cantidad)
{
    int todoOk=0;

    eEmpresa auxEmpresa[30] =
    {
        {0,"Plusmar"},
        {0,"Flecha Bus"},
        {0,"Tas"},
        {0,"El Rapido"},

    };

    if(empresa!=NULL && tam>0 && cantidad<tam && pId!=NULL)
    {

        for(int i=0; i<cantidad; i++)
        {

            auxEmpresa[i].id = *pId;
            auxEmpresa[i].isEmpty=0;
            empresa[i] = auxEmpresa[i];
            (*pId)++;
        }
    }

    todoOk=1;
    return todoOk;

}

int inicializarEmpresa(eEmpresa empresa[], int tam)
{
    int todoOk = 0;

    if(empresa != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            empresa[i].isEmpty = 1;
        }

        todoOk = 1;
    }
    return todoOk;
}

int funcionBuscarEmpresa(int idEmpresa, eEmpresa empresa[], int sizeEmpresa, char nombreEmpresa[])
{
    int todoOk=0;

    if(empresa!=NULL && sizeEmpresa>0)
    {

        for(int i=0; i<sizeEmpresa; i++)
        {
            if(empresa[i].id==idEmpresa)
            {
                strcpy(nombreEmpresa, empresa[i].descripcion);
            }
        }
    todoOk=1;
    }

    return todoOk;
}

int listarEmpresa(eEmpresa empresa[], int sizeEmpresa, int cleanScreen)
{
    int todoOk=0;
    if(cleanScreen)
        system("cls");
    if(empresa!=NULL)
    {
        printf("\n\nID EMPRESA     EMPRESA\n");
        for(int i=0; i<sizeEmpresa;i++){
            if(!empresa[i].isEmpty)
                printf("   %d      %-10s\n", empresa[i].id, empresa[i].descripcion);
        }
    todoOk=1;
    }
    return todoOk;
}


