#ifndef EEMPRESA_H_INCLUDED
#define EEMPRESA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[50];
}eEmpresa;


#endif // EEMPRESA_H_INCLUDED

int hardcodeoTipo(eEmpresa empresa[], int tam, int* pId, int cantidad);
