#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED




typedef struct
{
    int id;
    char descripcion[15];
    int isEmpty;
} eTipo;


#endif // DESTINOS_H_INCLUDED
// FUNCION PARA CARGA DE ELEMENTOS DE PRUEBA EN EL PROGRAMA
int hardcodeoTipo(eTipo tipo[], int tam, int* pId, int cantidad);


/** \brief inicializa variable isEmpty en 1
 *
 * \param unTipo[] eTipo - vector tipo de servicio de viajes
 * \param tam int - tamaño vector tipo.
* \return int 0 error de memoria, 1 todo ok.
 *
 */
int inicializarTipo(eTipo unTipo[], int tam);

/** \brief
 *
 * \param idTipo int recibe el id del nombre del tipo a buscar
 * \param tipo[] eTipo - vector tipo de servicio de viajes
 * \param sizeTipo int - tamaño vector tipo.
 * \param nombreTipo[] char - vector donde se copia el nombre del tipo de servicio encontrado
 * \return int 0 error de memoria, 1 ok.
 *
 */
int funcionBuscarTipo(int idTipo, eTipo tipo[], int sizeTipo, char nombreTipo[]);

/** \brief muestra lista de registro de tipo de servicio
 *
 * \param idTipo int recibe el id del nombre del tipo a buscar
 * \param tipo[] eTipo - vector tipo de servicio de viajes
 * \param clean int 1 limpia la pantalla
 * \return int 0 error de memoria, 1 ok.
 *
 */
int listarTipo(eTipo tipo[], int sizeTipo, int clean);


