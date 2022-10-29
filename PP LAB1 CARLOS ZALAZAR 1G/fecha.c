#include <stdio.h>
#include <stdlib.h>
#include"micros.h"
#include "destinos.h"
#include "tipo.h"
#include <string.h>
#include "validar.h"
#include "fecha.h"


int validarFecha(eFecha fecha){
    int todoOk=1;

    if((fecha.dia<1 || fecha.dia>31) || (fecha.dia>28 && fecha.mes==2) ||
                                            (fecha.mes<1 || fecha.mes>12) ||
                                            (fecha.anio<2022 || fecha.anio>2030)){
            todoOk=0;
        }

    return todoOk;
}

