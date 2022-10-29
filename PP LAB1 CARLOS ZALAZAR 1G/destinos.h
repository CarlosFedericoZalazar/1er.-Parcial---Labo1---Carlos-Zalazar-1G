

#ifndef DESTINOS_H_INCLUDED
#define DESTINOS_H_INCLUDED

typedef struct{

    int id;
    char descripcion[15];
    float precio;
    int isEmpty;

}eDestino;

#endif // DESTINOS_H_INCLUDED
// FUNCION PARA CARGA DE ELEMENTOS DE PRUEBA EN EL PROGRAMA
int hardcodeoDestino(eDestino destino[], int tam, int* pId, int cantidad);

/** \brief inicializa variable isEmpty en 1
 *
 * \param unDestino[] eDestino - vector destino
 * \param tam int - tamaño vector destino
 * \return int 0 error de memoria, 1 ok.
 *
 */
int inicializarDestino(eDestino unDestino[], int tam);

/** \brief muestra lista de registro de destinos
 *
 * \param destino[] eDestino - vector destino
 * \param tam int - tamaño vector destino
 * \return int 0 error de memoria, 1 ok.
 *
 */
int listarDestinos(eDestino destino[], int tam);


/** \brief
 *
 * \param idDestino int recibe el id del nombre del destino a buscar
 * \param destino[] eDestino  - vector destino
 * \param sizeDestino int - tamaño vector destino
 * \param nombreDestino[] char - vector donde se copia el nombre del destino encontrado
 * \return int 0 error de memoria, 1 ok.
 *
 */
int funcionBuscarDestino(int idDestino, eDestino destino[], int sizeDestino, char nombreDestino[]);


