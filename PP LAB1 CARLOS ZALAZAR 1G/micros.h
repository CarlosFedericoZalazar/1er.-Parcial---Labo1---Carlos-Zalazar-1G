#include "empresa.h"
#include "tipo.h"
#include "chofer.h"

#ifndef MICROS_H_INCLUDED
#define MICROS_H_INCLUDED

typedef struct
{
    int id;
    int idEmpresa;
    int idTipo;
    int capacidad;
    int idChofer;
    int isEmpty;
} eMicro;


#endif // MICROS_H_INCLUDED
// FUNCION PARA CARGA DE ELEMENTOS DE PRUEBA EN EL PROGRAMA
int hardcodeoMicros(eMicro micro[], int tam, int* pId, int cantidad);

/** \brief inicializa variable isEmpty en 1
 *
 * \param unMicro[] eMicro - vector micros.
 * \param tam int - tamaño vector micros.
 * \return int 0 error de memoria, 1 ok.
 *
 */
int inicializarMicros(eMicro unMicro[], int tam);

/** \brief busca posicion para guardar un nuevo registro micro
 *
 * \param unMicro[] eMicro - vector micros.
 * \param tam int - tamaño vector micros.
 * \return int indice - devuelve posicion en vector micro disponible para utilizar.
 *
 */
int buscarPosicionLibreMicro(eMicro micro[], int tam);

/** \brief
 *
 * \param unMicro[] eMicro - vector micros.
 * \param tam int - tamaño vector micros.
 * \param empresa[] eEmpresa - vector empresa.
 * \param tamEmpresa int - tamaño vector empresa.
 * \param tipo[] eTipo - vector tipo de servicio.
 * \param tamTipo int - tamaño vector tipo.
 * \return int 0 error de memoria, 1 todo ok.
 *
 */
int mostrarMicros(eMicro micro[], int tam, eEmpresa empresa[], int tamEmpresa, eTipo tipo[], int tamTipo, eChofer chofer[], int tamChofer);

/** \brief crea nuevo registro de micro
 *
 * \param unMicro[] eMicro - vector micros.
 * \param tam int - tamaño vector micros.
 * \param empresa[] eEmpresa - vector empresa.
 * \param tamEmpresa int - tamaño vector empresa.
 * \param tipo[] eTipo - vector tipo de servicio.
 * \param tamTipo int - tamaño vector tipo.
 * \param pId int* - puntero referencia a identificador autoincremental micros.
* \return int 0 error de memoria, 1 todo ok.
 *
 */
int altaMicro(eMicro micro[], int tam, eEmpresa empresa[], int tamEmpresa, eTipo tipo [], int tamTipo, int* pId);

/** \brief da de baja un registro micro
 *
 * \param unMicro[] eMicro - vector micros.
 * \param tamMicro int - tamaño vector micros.
 * \param empresa[] eEmpresa - vector empresa.
 * \param tamEmpresa int - tamaño vector empresa.
 * \param tipo[] eTipo - vector tipo de servicio.
 * \param sizeTipo int tamaño vector tipo.
* \return int 0 error de memoria, 1 todo ok.
 *
 */
int bajaMicro(eMicro micro[], int tamMicro, eEmpresa empresa[], int tamEmpresa, eTipo tipo[], int sizeTipo, eChofer chofer[], int tamChofer);

/** \brief
 *
 * \param micro[] eMicro - vector micros.
 * \param tam int - tamaño vector micros.
 * \param id int - id a buscar
 * \return int indice- retorna subindice de la posicion en el vector del id buscado
 *
 */
int buscarMicroId(eMicro micro[], int tam, int id);

/** \brief brinda opciones a modificar en un registro micro
 *
 * \return int opcion - opcion elegida en menu
 */
int menuModificarMicro(void);

/** \brief modifica un registro micro
 *
 * \param unMicro[] eMicro - vector micros.
 * \param tamMicro int - tamaño vector micros.
 * \param empresa[] eEmpresa - vector empresa.
 * \param tamEmpresa int - tamaño vector empresa.
 * \param tipo[] eTipo - vector tipo de servicio.
 * \param tamTipo int tamaño vector tipo.
* \return int 0 error de memoria, 1 todo ok.
 *
 */
int modificarMicro(eMicro micro[], int tamMicro, eEmpresa empresa[], int tamEmpresa, eTipo tipo[], int tamTipo, eChofer chofer[], int tamChofer);

/** \brief
 *
* \param unMicro[] eMicro - vector micros.
 * \param size int tamaño vector micros.
 * \param empresa[] eEmpresa - vector empresa.
 * \param sizeEmpresa int - tamaño vector empresa.
 * \param criterio int - 0 si criterio de ordenamiento es id creciente, 1 por empresa y paajeros
* \return int 0 error de memoria, 1 todo ok.
 *
 */
int ordenarMicros(eMicro micro[], int size, eEmpresa empresa[], int sizeEmpresa, int criterio);

/** \brief
 *
 * \param micro eMicro  - registro micro
 * \param empresa[] eEmpresa - vector empresa.
 * \param tamEmpresa int - tamaño vector empresa.
 * \param tipo[] eTipo - vector tipo de servicio.
 * \param tamTipo int tamaño vector tipo.
* \return int 0 error de memoria, 1 todo ok.
 *
 */
int mostrarUnMicro(eMicro micro, eEmpresa empresa[], int tamEmpresa, eTipo tipo[], int tamTipo, eChofer chofer[], int tamChofer);

int mostrarMicrosPorEmpresa(eMicro micro[], int tam, eEmpresa empresa[], int tamEmpresa, eTipo tipo[], int tamTipo, eChofer chofer[], int tamChofer);

int mostrarMicrosTipoSeleccionado(eMicro micro[], int tam, eEmpresa empresa[], int tamEmpresa, eTipo tipo[], int tamTipo, eChofer chofer[], int tamChofer);

int informePorcentajeVip(eMicro micro[], int tam, eTipo tipo[], int tamTipo);

int mostrarMicrosSepPorEmpresa(eMicro micro[], int tam, eEmpresa empresa[], int tamEmpresa, eTipo tipo[], int tamTipo, eChofer chofer[], int tamChofer);
