#include <stdio.h>
#include <stdlib.h>
#include"micros.h"
#include "destinos.h"
#include "tipo.h"
#include "validar.h"
#include "viajes.h"
#include <string.h>



int altaViaje(eMicro micro[], int sizeMicro, eDestino destino[], int sizeDestino, eEmpresa empresa[],int sizeEmpresa, eTipo tipo[], int sizeTipo, eViaje viaje[], int sizeViaje, int*idViaje, eChofer chofer[], int tamChofer)
{
    int todoOk=0;
    int indice;
    eViaje auxViaje;


    if(micro!=NULL && sizeMicro>0 && destino!=NULL && sizeDestino>0)
    {
        indice = buscarPosicionLibreViaje(viaje,sizeViaje);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            system("cls");

            printf("\n                *** ALTA VIAJES *** \n\n\n\n");
            ordenarMicros(micro,sizeMicro, empresa, sizeEmpresa,0);
            mostrarMicros(micro, sizeMicro, empresa, sizeEmpresa, tipo, sizeTipo,chofer, tamChofer);
            printf("* Ingrese Micro (Id):");
            scanf("%d", &auxViaje.idMicro);
            while(!validarIdMicro(auxViaje.idMicro,micro,sizeMicro))
            {
                printf("Error. Ingrese ID MICRO valido: (en lista) ");
                scanf("%d", &auxViaje.idMicro);
            }
            listarDestinos(destino,sizeDestino);
            printf("* Ingrese Destino (Id):");
            scanf("%d", &auxViaje.idDestino);
            while(!validarIdDestino(auxViaje.idDestino,destino,sizeDestino))
            {
                printf("Error. Ingrese ID DESTINO (existente en lista): ");
                scanf("%d", &auxViaje.idDestino);
            }
            printf("INGRESE FECHA DE VIAJE (dd/mm/aaaa):");
            scanf("%d/%d/%d", &auxViaje.fecha.dia,
                  &auxViaje.fecha.mes,
                  &auxViaje.fecha.anio);

            while(!validarFecha(auxViaje.fecha)){
                  printf("ERROR. INGRESE UNA FECHA DE VIAJE VALIDA (dd/mm/aaaa):");
                  scanf("%d/%d/%d", &auxViaje.fecha.dia,
                  &auxViaje.fecha.mes,
                  &auxViaje.fecha.anio);
            }
        }


        viaje[indice] = auxViaje;
        viaje[indice].id = (*idViaje);
        viaje[indice].isEmpty=0;
        printf("\n*ALTA DE VIAJE EXITOSA!!!\n\n");
        system("pause");
        (*idViaje)++;
        todoOk=1;

    }
    return todoOk;
}

int buscarPosicionLibreViaje(eViaje viaje[], int tam)  // SEGUIR CON ESTO
{
    int indice = -1;
    for (int i = 0 ; i < tam; i++)
    {
        if(viaje[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int inicializarViaje(eViaje viaje[], int tamViaje)
{
    int todoOk = 0;

    if(viaje != NULL && tamViaje > 0)
    {
        for (int i = 0; i < tamViaje; i++)
        {
            viaje[i].isEmpty = 1;
        }

        todoOk = 1;
    }
    return todoOk;
}


int mostrarViajes(eMicro micro[], int tam, eEmpresa empresa[], int tamEmpresa, eTipo tipo[], int tamTipo, eViaje viaje[], int tamViaje, eDestino destino[], int tamDestino)
{
    char cadenaEmpresaMicro[15];
    //char cadenaTipoServ[15];
    char cadenaDestino[15];

    int todoOk = 0;
    int flag=0;

    if(micro != NULL&& empresa!=NULL && tipo!=NULL && tam > 0)
    {
        system("cls");
        printf("\n                ***** LISTA DE VIAJES *****\n\n");
        printf("************************************************************\n\n\n");
        printf("ID VIAJE    DESTINO     ID MICRO     EMPRESA      FECHA VIAJE    \n");

        for (int i = 0; i < tamViaje; i++)
        {
            if(!viaje[i].isEmpty)
            {
                flag=1;


                funcionBuscarEmpresaIdMicro(viaje[i].idMicro,micro, tam, empresa,tamEmpresa, cadenaEmpresaMicro);


                funcionBuscarDestino(viaje[i].idDestino, destino, tamDestino, cadenaDestino );

                printf("\n  %2d       %-12s     %d        %-12s  %d/%d/%d\n",viaje[i].id, cadenaDestino, viaje[i].idMicro, cadenaEmpresaMicro, viaje[i].fecha.dia, viaje[i].fecha.mes, viaje[i].fecha.anio);

            }
        }
        todoOk = 1;
    if(!flag)
        printf("\n\n * NO SE HAN REGISTRADO VIAJES\n");
    }

    return todoOk;

}




int funcionBuscarEmpresaIdMicro(int idMicro, eMicro micro[], int sizeMicro, eEmpresa empresa[], int sizeEmpresa, char nombreNomEmpresa[])
{
    int todoOk=0;

    if(micro!=NULL && sizeMicro>0)
    {

        for(int i=0; i<sizeMicro; i++)
        {
            if(!micro[i].isEmpty && micro[i].id == idMicro)
            {
               funcionBuscarEmpresa(micro[i].idEmpresa,empresa,sizeEmpresa,nombreNomEmpresa);
            }
        }
    todoOk=1;
    }
    return todoOk;
}


int hardcodeoViajes(eViaje viajes[], int tamViaje, int* pId, int cantidad)
{
    int todoOk=0;

    eViaje AuxViajes[30] =
    {
        {0,1, 20000,0,{21,10,2022}},
        {0,1,20002,0,{30,11,2022}},
        {0,1, 20003,0,{02,11,2022}},
        {0,2, 20005,0,{01,12,2022}}
    };

    if(viajes!=NULL && tamViaje>0 && pId!=NULL)
    {

        for(int i=0; i<cantidad; i++)
        {
            AuxViajes[i].id = *pId;
            AuxViajes[i].isEmpty=0;
            viajes[i] = AuxViajes[i];
            (*pId)++;

        }
      todoOk=1;
    }
      return todoOk;
}







