#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED



#endif // VALIDAR_H_INCLUDED


/** \brief - verifica que el id de la empresa enviada como parametro sea existente en el vector
 *
 * \param id int - id de la empresa a verificar existencia
 * \param empresa[] eEmpresa - vector empresa
 * \param sizeEmpresa int - tamaño del vector empresa
 * \return int 0 si es inexistente, 1 si existente
 *
 */
int validarIdEmpresa(int id, eEmpresa empresa[], int sizeEmpresa);

/** \brief  id del tipo de viaje a verificar existencia
 *
 * \param id int - id del tipo servicio de viaje a verificar existencia
 * \param tipo[] eTipo - vector tipo de servicio
 * \param sizeTipo int - tamaño del vector empresa
 * \return int 0 si es inexistente, 1 si existente
 *
 */
int validarIdTipoViaje(int id, eTipo tipo[], int sizeTipo);

/** \brief id del micro a verificar existencia
 *
 * \param id int - id del micro a verificar existencia
 * \param micro[] eMicro - vector micro
 * \param sizeMicro int - tamaño del vector empresa
 * \return int 0 si es inexistente, 1 si existente
 *
 */
int validarIdMicro(int id, eMicro micro[], int sizeMicro);

/** \brief
 *
 * \param id del destino a verificar existencia
 * \param destino[] eDestino - vector destinos
 * \param sizeDestino int - tamaño del vector empresa
 * \return int 0 si es inexistente, 1 si existente
 *
 */
int validarIdDestino(int id, eDestino destino[], int sizeDestino);

/** \brief valida el rango de un valor entre otros dos
 *
 * \param a int valor a validar
 * \param b int primer valor del rango
 * \param c int segundo valor el rango
 * \return int 0 si se encuengtra fuera de rango, 1 si esta dentro del rango
 *
 */
int validarRango(int a, int b, int c);

int esSoloLetras(char str[]);

int esCaracter(char letra);
