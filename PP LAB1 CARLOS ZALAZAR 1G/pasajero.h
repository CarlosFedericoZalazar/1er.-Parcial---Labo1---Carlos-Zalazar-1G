#ifndef PASAJERO_H_INCLUDED
#define PASAJERO_H_INCLUDED


typedef struct{
    int id;
    char nombre[50];
    char sexo;
    int isEmpty;
}ePasajero;


#endif // PASAJERO_H_INCLUDED

int inicializarPasajero(ePasajero pasajero[], int tam);

int hardcodeoPasajeros(ePasajero pasajeros[], int tamPasajero, int* pId, int cantidad);
