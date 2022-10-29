#ifndef EEMPRESA_H_INCLUDED
#define EEMPRESA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[50];
    int isEmpty;
}eEmpresa;

#endif // EEMPRESA_H_INCLUDED
// FUNCION CARGA DE REGISTROS PARA LA PRUEBA EN EL PRGRAMA
int hardcodeoEmpresa(eEmpresa empresa[], int tam, int* pId, int cantidad);

/** \brief inicializa variable isEmpty en 1
 *
 * \param empresa[] eEmpresa - vector empresa.
 * \param tam int - tamaño vector empresa.
 * \return int 0 error de memoria, 1 todo ok.
 *
 */
int inicializarEmpresa(eEmpresa empresa[], int tam);

/** \brief
 *
 * \param idEmpresa int - recibe el id del nombre de la empresa que se busca
 * \param empresa[] eEmpresa - vector empresa.
 * \param sizeEmpresa int - tamaño vector empresa.
 * \param nombreEmpresa[] char - vector donde se copia el nombre de la empresa encontrado
 * \return int 0 error de memoria, 1 todo ok.
 *
 */
int funcionBuscarEmpresa(int idEmpresa, eEmpresa empresa[], int sizeEmpresa, char nombreEmpresa[]);

/** \brief muestra en lista el registro de empresas
 *
 * \param empresa[] eEmpresa - vector empresa.
 * \param sizeEmpresa int - tamaño vector empresa.
 * \param clean int - valor 1 limpia la pantalla
 * \return int 0 error de memoria, 1 todo ok.
 *
 */
int listarEmpresa(eEmpresa empresa[], int sizeEmpresa, int clean);
