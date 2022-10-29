#include <stdio.h>
#include <stdlib.h>
#include"micros.h"
#include "destinos.h"
#include "tipo.h"
#include "validar.h"
#include <ctype.h>
#include <string.h>
#include "chofer.h"


int inicializarMicros(eMicro unMicro[], int tam)
{
    int todoOk = 0;

    if(unMicro != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            unMicro[i].isEmpty = 1;
        }

        todoOk = 1;
    }
    return todoOk;
}


int hardcodeoMicros(eMicro micro[], int tam, int* pId, int cantidad)
{
    int todoOk=0;

    eMicro Auxmicro[9] =  {{0,1000, 5000,20},
        {0,1001,5001, 30,1},
        {0,1002, 5003,45,2},
        {0,1003, 5004, 25,4},
        {0,1004, 5003,50,2},
        {0,1001,5004, 10,5},

    };

    if(micro!=NULL && tam>0 && cantidad<tam && pId!=NULL)
    {




        for(int i=0; i<cantidad; i++)
        {
            Auxmicro[i].id = *pId;
            Auxmicro[i].isEmpty=0;
            micro[i] = Auxmicro[i];
            (*pId)++;

        }
        todoOk=1;
    }

    return todoOk;
}


int buscarPosicionLibreMicro(eMicro micro[], int tam)
{
    int indice = -1;
    for (int i = 0 ; i < tam; i++)
    {
        if(micro[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaMicro(eMicro micro[], int tam, eEmpresa empresa[], int tamEmpresa, eTipo tipo [], int tamTipo, int* pId)
{
    int todoOk = 0;
    int indice;
    eMicro auxMicro;

    if(micro != NULL && tam > 0 && pId!=NULL)
    {
        indice = buscarPosicionLibreMicro(micro,tam);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            system("cls");
            printf("    ***** ALTA MICRO ******\n");

            auxMicro.id = *pId;
            (*pId)++;

            listarEmpresa(empresa,tamEmpresa,0);
            printf("\nIngrese ID EMPRESA: (1000/....) ");
            //scanf("%d", &auxMicro.idEmpresa);

            while(!scanf("%d", &auxMicro.idEmpresa) && !validarIdEmpresa(auxMicro.idEmpresa,empresa,tamEmpresa))
            {
                printf("Error. Ingrese ID EMPRESA valido: ");
                fflush(stdin);
                //scanf("%d", &auxMicro.idEmpresa);
            }
            listarTipo(tipo,tamTipo,0);
            printf("\nIngrese ID TIPO DE VIAJE (5000/...): ");
            scanf("%d", &auxMicro.idTipo);
            while(!validarIdTipoViaje(auxMicro.idTipo,tipo,tamTipo))
            {
                printf("Error. Ingrese ID TIPO DE VIAJE valido (5000/...): ");
                scanf("%d", &auxMicro.idTipo);
            }


            printf("\nIngrese Cantidad de Pasajeros (1/50): ");
            while(!scanf("%d", &auxMicro.capacidad) || !validarRango(auxMicro.capacidad,1,50))
            {
                fflush(stdin);
                printf("Ingrese Cantidad de Pasajeros VALIDO (1/50): ");
            }

            auxMicro.isEmpty = 0;
            micro[indice] = auxMicro;
            printf("\n** ALTA EXITOSA!!\n\n");
            system("pause");
            todoOk = 1;
        }
    }
    return todoOk;
}

int mostrarMicros(eMicro micro[], int tam, eEmpresa empresa[], int tamEmpresa, eTipo tipo[], int tamTipo, eChofer chofer[], int tamChofer)
{
    char cadenaNomEmpresa[15];
    char cadenaTipoServ[15];
    char cadenaNomChofer[15];
    int todoOk = 0;
    if(micro != NULL&& empresa!=NULL && tipo!=NULL && tam > 0)
    {
        system("cls");
        printf("\n                ***** LISTA DE MICROS *****\n\n");
        printf("************************************************************\n\n\n");
        printf(" ID MICRO      EMPRESA        CHOFER          ID TIPO  CAPACIDAD\n");

        for (int i = 0; i < tam; i++)
        {
            if(!micro[i].isEmpty)
            {
                funcionBuscarChofer(micro[i].idChofer,chofer, tamChofer, cadenaNomChofer);
                funcionBuscarEmpresa(micro[i].idEmpresa,empresa,tamEmpresa,cadenaNomEmpresa);
                funcionBuscarTipo(micro[i].idTipo,tipo,tamTipo,cadenaTipoServ);

                printf("    %2d       %-12s    %-15s   %-10s  %2d  \n", micro[i].id, cadenaNomEmpresa, cadenaNomChofer, cadenaTipoServ, micro[i].capacidad);
            }
        }
        todoOk = 1;
    }

    return todoOk;
}

int bajaMicro(eMicro micro[], int tamMicro, eEmpresa empresa[], int tamEmpresa, eTipo tipo[], int tamTipo, eChofer chofer[], int tamChofer)
{
    int indice;
    int todoOk = 0;
    int id;
    char confirma;
    if(micro != NULL && empresa!=NULL && tipo!=NULL && tamMicro > 0 && tamEmpresa > 0 && tamTipo>0)
    {
        system("cls");
        printf("                *** BAJA MICRO *** \n\n\n");
        mostrarMicros(micro,tamMicro,empresa,tamEmpresa, tipo, tamTipo, chofer, tamChofer);
        printf("\n\nIngrese id: \n");
        scanf("%d", &id);
        indice = (buscarMicroId(micro, tamMicro, id));
        if(indice == -1)
        {
            printf("El id: %d no esta registrado", id);
        }
        else
        {
            //mostrarPersona(unaLista[indice], equipo, sizeEquipo);
            printf("\nConfirma baja?");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                micro[indice].isEmpty = 1;


            }
            else
            {
                printf("Baja cancelada");
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarMicroId(eMicro micro[], int tam, int id)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(!micro[i].isEmpty && micro[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int modificarMicro(eMicro micro[], int tamMicro, eEmpresa empresa[], int tamEmpresa, eTipo tipo[], int tamTipo, eChofer chofer[], int tamChofer)
{
    int todoOk=0;
    int id;
    int indice;
    eMicro auxMicro;
    char rpta='n';
    char rptaSalir='n';

    if(micro!=NULL && empresa!=NULL && tipo!=NULL && tamMicro>0 && tamEmpresa>0 && tamTipo>0)
    {
        system("cls");
        printf("                    ****** MODIFICAR MICRO ******\n\n\n");
        ordenarMicros(micro,tamMicro, empresa, tamEmpresa,0);
        mostrarMicros(micro, tamMicro, empresa, tamEmpresa, tipo, tamTipo, chofer, tamChofer);


        if(!buscarMicroId(micro,tamMicro,id))
            printf("ERROR. NO SE HA PODIDO ACCEDER A LA FUNCION");
        printf("\n\nIngrese id: \n");
        scanf("%d", &id);
        indice = (buscarMicroId(micro, tamMicro, id));

        if(indice == -1)
        {
            printf("El id: %d no esta registrado", id);
        }
        else
        {
            do
            {
                system("cls");
                mostrarUnMicro(micro[indice],empresa,tamEmpresa, tipo, tamTipo, chofer, tamChofer);

                switch(menuModificarMicro())
                {
                case 1:
                    listarEmpresa(empresa,tamEmpresa,1);
                    printf("\nIngrese ID EMPRESA: (1000/....) ");
                    scanf("%d", &auxMicro.idEmpresa);
                    while(!validarIdEmpresa(auxMicro.idEmpresa,empresa,tamEmpresa))
                    {
                        printf("Error. Ingrese ID EMPRESA valido: ");
                        scanf("%d", &auxMicro.idEmpresa);
                    }
                    micro[indice].idEmpresa=auxMicro.idEmpresa;
                    break;
                case 2:
                    listarTipo(tipo,tamTipo,0);
                    printf("\nIngrese ID TIPO DE VIAJE (5000/...): ");
                    scanf("%d", &auxMicro.idTipo);
                    while(!validarIdTipoViaje(auxMicro.idTipo,tipo,tamTipo))
                    {
                        printf("Error. Ingrese ID TIPO DE VIAJE valido (5000/...): ");
                        scanf("%d", &auxMicro.idTipo);
                    }
                    micro[indice].idTipo=auxMicro.idTipo;
                    break;
                case 3:
                    printf("\nIngrese Cantidad de Pasajeros (1/50): ");
                    while(!scanf("%d", &auxMicro.capacidad) || !validarRango(auxMicro.capacidad,1,50))
                    {
                        fflush(stdin);
                        printf("Ingrese Cantidad de Pasajeros VALIDO (1/50): ");
                    }
                    micro[indice].capacidad=auxMicro.capacidad;
                    break;
                case 4:
                    fflush(stdin);
                    printf("CONFIRMA DESEA SALIR SIN MODIFICAR?");
                    rptaSalir = tolower(getchar());
                    while(rptaSalir!='s' && rptaSalir!='n')
                    {
                        fflush(stdin);
                        printf("\n**ERROR, CARACTER INVALIDO**\nDESEA SALIR? (S/N)");
                        rptaSalir = tolower(getchar());
                    }
                    break;
                default:
                    printf("OPCION INVALIDA");

                }

                if(rptaSalir!='s')
                {
                    fflush(stdin);
                    printf("\n DESEA MODIFICAR OTRO CAMPO? (S/N)");
                    rpta = tolower(getchar());
                    printf("%c",rpta);
                    while(rpta!='s' && rpta!='n')
                    {
                        fflush(stdin);
                        printf("\n**ERROR, CARACTER INVALIDO**\nDESEA MODIFICAR OTRO MICRO? (S/N)");
                        rpta = tolower(getchar());
                    }
                }
                else
                {
                    rpta='n';
                }
                printf("%c",rpta);
            }
            while(rpta=='s');


        }
        todoOk=1;
    }
    return todoOk;

}

int menuModificarMicro()
{
    int opcion;

    //system("cls");
    printf("\n\n1- MODIFICAR ID EMPRESA\n");
    printf("2- MODIFICAR ID TIPO\n");
    printf("3- MODIFICAR CAPACIDAD\n");

    printf("\n4- SALIR\n\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int ordenarMicros(eMicro micro[], int size, eEmpresa empresa[], int sizeEmpresa, int criterio)
{

    int todoOk=0;
    eMicro auxMicro;
    char cadenaNomEmpresaUno[50];
    char cadenaNomEmpresaDos[50];

    if(micro!=NULL && size>0)
    {

        for(int i=0; i<size-1; i++)
        {
            for(int j=i+1; j<size; j++)
            {
                if(micro[i].isEmpty !=1)
                {

                    funcionBuscarEmpresa(micro[i].idEmpresa,empresa,sizeEmpresa,cadenaNomEmpresaUno);
                    funcionBuscarEmpresa(micro[j].idEmpresa,empresa,sizeEmpresa,cadenaNomEmpresaDos);

                    if((((strcmp(cadenaNomEmpresaUno, cadenaNomEmpresaDos) == 0 && (micro[i].capacidad>micro[j].capacidad) ) || strcmp(cadenaNomEmpresaUno, cadenaNomEmpresaDos) > 0)&& criterio==1) ||
                            (micro[i].id>micro[j].id && criterio==0))
                    {
                        auxMicro = micro[i];
                        micro[i] = micro[j];
                        micro[j] = auxMicro;
                    }
                }
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int mostrarUnMicro(eMicro micro, eEmpresa empresa[], int tamEmpresa, eTipo tipo[], int tamTipo, eChofer chofer[], int tamChofer)
{
    char cadenaNomEmpresa[15];
    char cadenaTipoServ[15];
    char cadenaNombreChofer[15];
    int todoOk = 0;
    if(empresa!=NULL && tipo!=NULL && tamEmpresa > 0 && tamTipo>0)
    {
        if(!micro.isEmpty)
        {
            funcionBuscarChofer(micro.idChofer,chofer, tamChofer, cadenaNombreChofer);
            puts(cadenaNombreChofer);
            system("pause");
            funcionBuscarEmpresa(micro.idEmpresa,empresa,tamEmpresa,cadenaNomEmpresa);
            funcionBuscarTipo(micro.idTipo,tipo,tamTipo,cadenaTipoServ);
            printf("- Id Micro: %2d\n- Empresa: %-12s\n- \nChofer: %s\n- Tipo de Serv:%-10s\n- Capacidad:%2d\n", micro.id, cadenaNomEmpresa, cadenaNombreChofer, cadenaTipoServ, micro.capacidad);
        }
        todoOk = 1;
    }

    return todoOk;
}


int mostrarMicrosPorEmpresa(eMicro micro[], int tam, eEmpresa empresa[], int tamEmpresa, eTipo tipo[], int tamTipo, eChofer chofer[], int tamChofer)
{
    char cadenaNomEmpresa[15];
    char cadenaTipoServ[15];
    char cadenaNomChofer[15];
    int todoOk = 0;
    int idEmpresa;
    if(micro != NULL&& empresa!=NULL && tipo!=NULL && tam > 0)
    {

        listarEmpresa(empresa,tamEmpresa,1);
        printf("\nSeleccione ID EMPRESA de los Micros a listar (1000/....): ");
        scanf("%d", &idEmpresa);
        while(!validarIdEmpresa(idEmpresa,empresa,tamEmpresa))
        {
            printf("Error. Ingrese ID EMPRESA valido: ");
            scanf("%d", &idEmpresa);
        }
        funcionBuscarEmpresa(idEmpresa,empresa,tamEmpresa,cadenaNomEmpresa);
        system("cls");
        printf("EMPRESA: %s\n\n", cadenaNomEmpresa);
        printf("\n                ***** LISTA DE MICROS POR EMPRESA *****\n\n");
        printf("************************************************************\n\n\n");
        printf(" ID MICRO      EMPRESA        CHOFER          ID TIPO  CAPACIDAD\n");

        for (int i = 0; i < tam; i++)
        {
            if(!micro[i].isEmpty && micro[i].idEmpresa==idEmpresa)
            {
                funcionBuscarChofer(micro[i].idChofer,chofer, tamChofer, cadenaNomChofer);
                funcionBuscarEmpresa(micro[i].idEmpresa,empresa,tamEmpresa,cadenaNomEmpresa);
                funcionBuscarTipo(micro[i].idTipo,tipo,tamTipo,cadenaTipoServ);

                printf("    %2d       %-12s    %-15s   %-10s  %2d  \n", micro[i].id, cadenaNomEmpresa, cadenaNomChofer, cadenaTipoServ, micro[i].capacidad);
            }
        }
        todoOk = 1;
    }
    system("pause");

    return todoOk;
}


int mostrarMicrosTipoSeleccionado(eMicro micro[], int tam, eEmpresa empresa[], int tamEmpresa, eTipo tipo[], int tamTipo, eChofer chofer[], int tamChofer)
{
    char cadenaNomEmpresa[15];
    char cadenaTipoServ[15];
    char cadenaNomChofer[15];
    int todoOk = 0;
    int idTipo;
    if(micro != NULL&& empresa!=NULL && tipo!=NULL && tam > 0)
    {

        listarTipo(tipo,tamTipo,0);
        printf("\nIngrese ID TIPO DE VIAJE A LISTAR... (5000/...): ");
        scanf("%d", &idTipo);
        while(!validarIdTipoViaje(idTipo,tipo,tamTipo))
        {
            printf("Error. Ingrese ID TIPO DE VIAJE valido (5000/...): ");
            scanf("%d", &idTipo);
        }

        funcionBuscarTipo(idTipo,tipo,tamTipo,cadenaTipoServ);
        system("cls");
        printf("TIPO DE SERVICIO: %s\n\n", cadenaTipoServ);
        printf("\n                ***** LISTA DE MICROS POR EMPRESA *****\n\n");
        printf("************************************************************\n\n\n");
        printf(" ID MICRO      EMPRESA        CHOFER          ID TIPO  CAPACIDAD\n");

        for (int i = 0; i < tam; i++)
        {
            if(!micro[i].isEmpty && micro[i].idTipo==idTipo)
            {
                funcionBuscarChofer(micro[i].idChofer,chofer, tamChofer, cadenaNomChofer);
                funcionBuscarEmpresa(micro[i].idEmpresa,empresa,tamEmpresa,cadenaNomEmpresa);
                funcionBuscarTipo(micro[i].idTipo,tipo,tamTipo,cadenaTipoServ);

                printf("    %2d       %-12s    %-15s   %-10s  %2d  \n", micro[i].id, cadenaNomEmpresa, cadenaNomChofer, cadenaTipoServ, micro[i].capacidad);
            }
        }
        todoOk = 1;
    }
    system("pause");

    return todoOk;
}

int informePorcentajeVip(eMicro micro[], int tam, eTipo tipo[], int tamTipo)
{
    int contadorVip=0;
    int contadorMicros=0;
    float porcentajeVip;

    int todoOk = 0;

    if(micro != NULL && tipo!=NULL && tam > 0)
    {


        for (int i = 0; i < tam; i++)
        {
            if(!micro[i].isEmpty)
            {
                if(micro[i].idTipo==5004)
                {
                   contadorVip++;
                }
                contadorMicros++;
            }

        }

        if(contadorVip!=0){
            porcentajeVip = (float)(contadorVip * 100)/contadorMicros;
        }
        system("cls");
        printf("ITEM MENU INFORMES PUNTO 3\n\n\n");
        printf("--> EL PORCENTAJE DEL TIPO DE VIAJES VIP SOBRE EL TOTAL ES %.2f\n\n", porcentajeVip);


        todoOk = 1;
    }
    system("pause");

    return todoOk;
}

int mostrarMicrosSepPorEmpresa(eMicro micro[], int tam, eEmpresa empresa[], int tamEmpresa, eTipo tipo[], int tamTipo, eChofer chofer[], int tamChofer)
{
    char cadenaNomEmpresa[15];
    char cadenaTipoServ[15];
    char cadenaNomChofer[15];
    int todoOk = 0;

    if(micro != NULL&& empresa!=NULL && tipo!=NULL && tam > 0)
    {
        for(int j=0;j<tamEmpresa;j++)
        {
            if(!empresa[j].isEmpty)
            {
                system("cls");
                printf("EMPRESA: %s\n\n", empresa[j].descripcion);
                printf(" ID MICRO      EMPRESA        CHOFER          ID TIPO  CAPACIDAD\n");
                for (int i = 0; i < tam; i++)
                {
                    if(!micro[i].isEmpty && micro[i].idEmpresa==empresa[j].id)
                    {
                        funcionBuscarChofer(micro[i].idChofer,chofer, tamChofer, cadenaNomChofer);
                        funcionBuscarEmpresa(micro[i].idEmpresa,empresa,tamEmpresa,cadenaNomEmpresa);
                        funcionBuscarTipo(micro[i].idTipo,tipo,tamTipo,cadenaTipoServ);
                        printf("    %2d       %-12s    %-15s   %-10s  %2d  \n", micro[i].id, cadenaNomEmpresa, cadenaNomChofer, cadenaTipoServ, micro[i].capacidad);
                    }
                }
            printf("=====================================================================\n");
            }
        }
    system("pause");
    todoOk = 1;
    }
    return todoOk;
}
/*NO LLEGUE...
int informePorcentajeVip(eMicro micro[], int tamMicro, eEmpresa empresa[], int tamEmpresa,  eTipo tipo[], int tamTipo)
{
    int acumulador=0;
    int MayorCantidadPasajeros=0;


    int todoOk = 0;

    if(micro != NULL && tipo!=NULL && tam > 0)
    {



        for (int i = 0; i < tamEmpresa; i++)
        {
            for(int j=0;j<tamMicro;j++)
            {
                if(micro[i].idEmpresa == empresa[j].id)
                {
                  acumulador+=micro[i].capacidad;

                }
            }
            if(!flag){
               MayorCantidadPasajeros=acumulador;
               flag=1
            }
            if(MayorCantidadPasajeros<cantidad)
            {
                MayorCantidadPasajeros=acumulador;
            }
        }

             for (int i = 0; i < tamEmpresa; i++)
           {
              for(int j=0;j<tamMicro;j++)
              {
                if(micro[i].idEmpresa == empresa[j].id)
                {
                 acumulador+=micro[i].capacidad
                }
            }
            if(MayorCantidadPasajeros==cantidad)
            {
                printf("EMPRESA CON MAYOR CANTIDAD PASAJEROS LLEVA: %s",);
            }


        }


}

*/
