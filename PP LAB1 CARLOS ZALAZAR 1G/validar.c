#include <stdio.h>
#include <stdlib.h>
#include"micros.h"
#include "destinos.h"
#include "tipo.h"
#include "empresa.h"
#include "validar.h"
#include "viajes.h"

int validarIdEmpresa(int id, eEmpresa empresa[], int sizeEmpresa){
    int todoOk=0;

    for(int i=0; i<sizeEmpresa; i++)
    {
        if(empresa[i].id == id && empresa[i].isEmpty==0){
            todoOk=1;
            break;
        }
    }
    return todoOk;
}

int validarIdTipoViaje(int id, eTipo tipo[], int sizeTipo){
    int todoOk=0;

    for(int i=0; i<sizeTipo; i++)
    {
        if(tipo[i].id == id && tipo[i].isEmpty==0){
            todoOk=1;
            break;
        }

    }
    return todoOk;


}
int validarIdDestino(int id, eDestino destino[], int sizeDestino){
    int todoOk=0;

    for(int i=0; i<sizeDestino; i++)
    {
        if(destino[i].id == id && destino[i].isEmpty==0){
            todoOk=1;
            break;
        }
    }
    return todoOk;
}


int validarIdMicro(int id, eMicro micro[], int sizeMicro){
    int todoOk=0;

    for(int i=0; i<sizeMicro; i++)
    {
        if(micro[i].id == id && micro[i].isEmpty==0){
            todoOk=1;
            break;
        }
    }
    return todoOk;
}

int validarRango(int a, int b, int c){
    int todoOk=1;

    if(a<b || a>c){
        todoOk=0;
    }
 return todoOk;
}

int esSoloLetras(char str[]){
	int i=0;
	while(str[i]!='\0')
	{
		if((str[i]!=' ') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z'))
			return 0;
		i++;
	}
	return 1;
}

int esCaracter(char letra){
    int todoOk=1;
    if((letra<65 || letra>90) || (letra<97 || letra>122) )
    {
        todoOk=0;
    }
    return todoOk;
}
