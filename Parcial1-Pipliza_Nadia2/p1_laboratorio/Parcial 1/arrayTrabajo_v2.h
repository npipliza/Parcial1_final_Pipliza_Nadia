#ifndef ARRAYTRABAJO_V2_H_
#define ARRAYTRABAJO_V2_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayBicicleta_v2.h"
#include "arrayServicio_v2.h"
#include "utn.h"
//#define MAX_CHARS_CADENAS 30
//#define T 10
#define VACIO 0
#define OCUPADO 1
#define BAJA -1

/********** ESTRUCTURAS ********************************************************************************/
//isEmpty 0 vacio - 1 ocupado
typedef struct
{
    int   idTrabajo;
    int   dia;
    int   mes;
    int   anio;
    int   idServicio; //(debe existir) Validar
    int   idBicicleta;
    int   isEmpty;
}eTrabajo;


/********** FUNCIONES ABM *****************************************************************************/

void InicializarTrabajo(eTrabajo listadoTrabajo[], int TAM);

/************************************************************************/

int  obtenerIDdeTrabajo(void);

/************************************************************************/

int  obtenerUltimoIDdeTrabajo(void);

/************************************************************************/

int  obtenerIndexTrabajoLibre(eTrabajo listadoTrabajo[], int TAM);

/************************************************************************/

int buscarTrabajosPorID(eTrabajo listadoTrabajo[], int TAM, int ID, eBicicleta listadoBicicleta[], int TamB);

/************************************************************************/
eTrabajo cargarDatosTrabajo(eServicio listadoServicio[], int TAMs);

/************************************************************************/

eTrabajo modificarUnTrabajo(eTrabajo trabajo, eBicicleta bicicleta);

/************************************************************************/

int altaTrabajo(eTrabajo listadoTrabajo[], int TAM, eServicio listadoServicio[], int TAMs);

/************************************************************************/

int bajaTrabajo(eTrabajo listadoTrabajo[], int TAM, eBicicleta listadoBicicleta[], int TamB, eServicio listadoServicio[], int TAMs);

/************************************************************************/

int modificacionTrabajo(eTrabajo listadoTrabajo[], int TAM, eBicicleta listadoBicicleta[], int TamB, eServicio listadoServicio[], int TamS);

/********** FUNCIONES MOSTRAR Y ORDENAR ****************************************************************/

void mostrarUnTrabajo(eTrabajo trabajo, eBicicleta bicicleta, eServicio servicio);

int mostrarTodosLosTrabajos(eTrabajo listadoTrabajo[], int TAM, eBicicleta listadoBicicleta[], int TamB, eServicio listadoServicio[], int TAMs);


/********** SORT ***************************************************************************************/
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
//int ordenaEmpleadosPorApellido(eTrabajo listadoTrabajo[], int TAM, int criterio);

#endif /* ARRAYTRABAJO_H_ */
