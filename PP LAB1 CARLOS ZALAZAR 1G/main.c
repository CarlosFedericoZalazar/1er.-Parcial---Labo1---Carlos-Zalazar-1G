#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TAM_MICRO 1000
#define TAM_DESTINOS 100
#define TAM_TIPO 15
#define TAM_EMPRESA 15
#define TAM_VIAJE 1000
#include"micros.h"
#include "destinos.h"
#include "tipo.h"
#include "empresa.h"
#include "validar.h"
#include "viajes.h"
#include "chofer.h"
#define ORDEN_ID_MICRO 0
#define ORDEN_EMPRESA_MICRO 1
#define TAM_CHOFER 5

int menu();

int funcionInformes(eMicro micros[], int tamMicros, eEmpresa empresa[], int tamEmpresa, eTipo tipoviaje[], int tamTipo, eChofer chofer[], int tamChofer);

int menuFunciones();

int main()
{

    int idMicro=1;
    int idTipo=5000;
    int idDest=20000;
    int idViaje=1;
    int idEmpresa = 1000;
    char rpta = 'n';

    eMicro eMicros[TAM_MICRO];
    eDestino eDestinos[TAM_DESTINOS];
    eTipo eTipoViaje[TAM_TIPO];
    eEmpresa empresa[TAM_EMPRESA];
    eViaje viaje[TAM_VIAJE];
    eChofer chofer[TAM_CHOFER];

    if(!inicializarMicros(eMicros, TAM_MICRO))
    {
        printf("Problemas al inicializar");
    }


    if(!inicializarViaje(viaje, TAM_VIAJE))
    {
        printf("Problemas al inicializar");
    }

    if(!inicializarMicros(eMicros, TAM_MICRO))
    {
        printf("Problemas al inicializar");
    }

    if(!inicializarDestino(eDestinos, TAM_DESTINOS))
    {
        printf("Problemas al inicializar");
    }
    if(!inicializarTipo(eTipoViaje, TAM_TIPO))
    {
        printf("Problemas al inicializar");
    }
    if(!inicializarEmpresa(empresa, TAM_EMPRESA))
    {
        printf("Problemas al inicializar");
    }

    if(!inicializarChofer(chofer, TAM_CHOFER))
    {
        printf("Problemas al inicializar");
    }
    hardcodeoMicros(eMicros,TAM_MICRO,&idMicro,4);
    hardcodeoEmpresa(empresa, TAM_EMPRESA, &idEmpresa,4);
    hardcodeoTipo(eTipoViaje, TAM_TIPO, &idTipo,4);
    hardcodeoDestino(eDestinos, TAM_DESTINOS,&idDest,4);
    hardcodeoViajes(viaje, TAM_VIAJE, &idViaje,4);
    hardcodeoChofer(chofer,TAM_CHOFER);

    do
    {
        switch(menu())
        {
        case 1:
            if(!altaMicro(eMicros, TAM_MICRO, empresa, TAM_EMPRESA, eTipoViaje, TAM_TIPO,&idMicro))
            {
                printf("Problemas al inicializar");
            }
            break;

        case 2:
            if(!modificarMicro(eMicros, TAM_MICRO, empresa, TAM_EMPRESA, eTipoViaje, TAM_TIPO, chofer, TAM_CHOFER))
            {
                printf("Problemas al inicializar");
            }

            printf("OPCION MODIFICAR MICRO");
            break;

        case 3:
            if(!bajaMicro(eMicros,TAM_MICRO,empresa, TAM_EMPRESA,eTipoViaje, TAM_TIPO, chofer, TAM_CHOFER))
            {
                printf("Problemas al inicializar");
            }
            break;

        case 4:
            ordenarMicros(eMicros,TAM_MICRO, empresa, TAM_EMPRESA,ORDEN_EMPRESA_MICRO);
            if(!mostrarMicros(eMicros, TAM_MICRO, empresa, TAM_EMPRESA, eTipoViaje, TAM_TIPO, chofer, TAM_CHOFER))
            {
                printf("Problemas al inicializar");
            }
            system("pause");

            break;

        case 5:
            if(!listarEmpresa(empresa,TAM_EMPRESA, 1))
            {
                printf("Problemas al inicializar");
            }

            system("pause");
            break;

        case 6:
            if(!listarTipo(eTipoViaje,TAM_TIPO,0))
            {
                printf("Problemas al inicializar");
            }
            system("pause");
            break;

        case 7:

            if(!listarDestinos(eDestinos,TAM_DESTINOS))
            {
                printf("Problemas al inicializar");
            }
            system("pause");
            break;

        case 8:
            altaViaje(eMicros,TAM_MICRO, eDestinos,TAM_DESTINOS, empresa, TAM_EMPRESA, eTipoViaje,TAM_TIPO, viaje, TAM_VIAJE, &idViaje, chofer, TAM_CHOFER);
            //printf("OPCION ALTA VIAJE:");
            break;

        case 9:
            mostrarViajes(eMicros,TAM_MICRO,empresa,TAM_EMPRESA, eTipoViaje,TAM_TIPO, viaje,TAM_VIAJE, eDestinos,TAM_DESTINOS);
            system("pause");
            break;

        case 10:
            if(!funcionInformes(eMicros,TAM_MICRO,empresa,TAM_EMPRESA,eTipoViaje, TAM_TIPO, chofer, TAM_CHOFER))
            {
                printf("Problemas al inicializar");
            }
            break;
        case 11:

            fflush(stdin);
            printf("\nConfirma Salir?...(s/n):");
            rpta = tolower(getchar());
            printf("%c",rpta);
            while(rpta!='s' && rpta!='n')
            {
                fflush(stdin);
                printf("\n**ERROR, CARACTER INVALIDO**\nDESEA SALIR DEL PROGRAMA? (S/N)");
                rpta = tolower(getchar());
            }

            break;

        default:
            printf("* OPCION INVALIDA\n");
            system("pause");

        }


    }
    while (rpta != 's');

    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("\n                *** ABM MICROS *** \n\n\n\n");
    printf("1- ALTA DE MICROS\n");
    printf("2- MODIFICAR MICROS\n");
    printf("3- BAJA MICROS\n");
    printf("4- LISTAR MICROS\n");
    printf("5- LISTAR EMPRESAS\n");
    printf("6- LISTAR TIPOS\n");
    printf("7- LISTAR DESTINOS\n");
    printf("8- ALTA VIAJE\n");
    printf("9- LISTAR VIAJES\n\n");
    printf("10- INFORMES\n\n");

    printf("11- salir\n\n\n");
    printf("Ingrese opcion: \n");
    //scanf("%d", &opcion)
    while(!scanf("%d", &opcion))// || !validarRango(opcion,1,10))
    {
        printf("Error, digito invalido. Ingrese OPCION  (1/10): \n");
        fflush(stdin);
    }

    return opcion;
}

int funcionInformes(eMicro micros[], int tamMicros, eEmpresa empresa[], int tamEmpresa, eTipo tipoviaje[], int tamTipo, eChofer chofer[], int tamChofer)
{

    char rpta = 'n';

    do
    {
        switch(menuFunciones())
        {
        case 1:
            if(!mostrarMicrosPorEmpresa(micros, tamMicros, empresa, tamEmpresa, tipoviaje, tamTipo, chofer, tamChofer))
            {
                printf("Problemas al inicializar");
            }
            break;
        case 2:
            if(!mostrarMicrosTipoSeleccionado(micros, tamMicros, empresa, tamEmpresa, tipoviaje, tamTipo, chofer, tamChofer))
            {
                printf("Problemas al inicializar");
            }
            break;

        case 3:

             if(!informePorcentajeVip(micros, tamMicros, tipoviaje, tamTipo))
            {
                printf("Problemas al inicializar");
            }
            break;


         case 4: //hacer

             if(!mostrarMicrosSepPorEmpresa(micros, tamMicros, empresa, tamEmpresa, tipoviaje, tamTipo, chofer, tamChofer))
            {
                printf("Problemas al inicializar");
            }
            break;
        case 5:




            fflush(stdin);
            printf("\nConfirma Salir?...(s/n):");
            rpta = tolower(getchar());
            printf("%c",rpta);
            while(rpta!='s' && rpta!='n')
            {
                fflush(stdin);
                printf("\n**ERROR, CARACTER INVALIDO**\nDESEA SALIR DEL PROGRAMA? (S/N)");
                rpta = tolower(getchar());
            }

            break;
        default:
            printf("* OPCION INVALIDA\n");
            system("pause");

        }
    }
    while (rpta != 's');
    return 0;
}

int menuFunciones()
{

    int opcion;
    system("cls");
    printf("\n                *** ABM MICROS *** \n\n\n\n");
    printf("1- MOSTRAR MICORS DE EMPRESA SELECCIONADOS POR USUARIO\n");
    printf("2- MOSTRAR MICROS POR TIPO\n");
    printf("3- PORCENTAJE MICROS VIP\n");
    printf("4- MOSTRAR MICROS POR EMPRESA\n");
    printf("5- salir\n\n\n");
    printf("Ingrese opcion: ");
    //scanf("%d", &opcion)
    while(!scanf("%d", &opcion))// || !validarRango(opcion,1,10))
    {
        printf("Error, digito invalido. Ingrese OPCION  (1/10): \n");
        fflush(stdin);
    }

    return opcion;
}
