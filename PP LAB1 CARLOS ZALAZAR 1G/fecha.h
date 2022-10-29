#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{

    int dia;
    int mes;
    int anio;
}eFecha;



#endif // FECHA_H_INCLUDED

/** \brief
 *
 * \param fecha eFecha recibe los parametros a validar
 * \return int 0 error de memoria, 1 ok.
 *
 */
int validarFecha(eFecha fecha);


