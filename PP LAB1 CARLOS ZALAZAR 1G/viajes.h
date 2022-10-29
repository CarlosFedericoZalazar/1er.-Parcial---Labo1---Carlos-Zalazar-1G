#include "fecha.h"

#ifndef VIAJES_H_INCLUDED
#define VIAJES_H_INCLUDED

typedef struct{

    int id;
    int idMicro;
    int idDestino;
    int isEmpty;
    eFecha fecha;
}eViaje;


#endif // VIAJES_H_INCLUDED


/** \brief
 *
 * \param micro[] eMicro
 * \param sizeMicro int
 * \param destino[] eDestino
 * \param tamDestino int
 * \param empresa[] eEmpresa
 * \param sizeEmpresa int
 * \param tipo[] eTipo
 * \param sizeTipo int
 * \param viaje[] eViaje
 * \param sizeViaje int
 * \param id int*
 * \return int
 *
 */
int altaViaje(eMicro micro[], int sizeMicro, eDestino destino[], int tamDestino, eEmpresa empresa[],int sizeEmpresa, eTipo tipo[], int sizeTipo, eViaje viaje[], int sizeViaje, int *id, eChofer chofer[], int tamChofer);

int buscarPosicionLibreViaje(eViaje viaje[], int tam);

int inicializarViaje(eViaje viaje[], int tamViaje);

int mostrarViajes(eMicro micro[], int tam, eEmpresa empresa[], int tamEmpresa, eTipo tipo[], int tamTipo, eViaje viaje[], int tamViaje, eDestino destino[], int tamDestino);

int funcionBuscarEmpresaIdMicro(int idMicro, eMicro micro[], int sizeMicro, eEmpresa empresa[], int sizeEmpresa, char nombreNomEmpresa[]);

int hardcodeoViajes(eViaje viajes[], int tamViaje, int* pId, int cantidad);



