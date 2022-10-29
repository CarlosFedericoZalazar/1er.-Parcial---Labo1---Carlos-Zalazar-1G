#ifndef CHOFER_H_INCLUDED
#define CHOFER_H_INCLUDED

typedef struct{
    int id;
    char nombre[50];
    char sexo;
    int isEmpty;
}eChofer;


#endif // CHOFER_H_INCLUDED

int hardcodeoChofer(eChofer chofer[], int tamchofer);

int funcionBuscarChofer(int idChofer, eChofer chofer[], int sizChofer, char nombreChofer[]);

int inicializarChofer(eChofer chofer[], int tam);
