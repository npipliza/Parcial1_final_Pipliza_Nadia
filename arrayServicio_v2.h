#ifndef ARRAYSERVICIO_V2_H_
#define ARRAYSERVICIO_V2_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayTrabajo_v2.h"
#include "arrayBicicleta_v2.h"
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
    int   idServicio;
    char  descripcion[25];
    float precioServicio;
    int   isEmpty;
}eServicio;


/********** FUNCIONES ABM ******************************************************************************/

void HardcodearServicios(eServicio listadoServicio[], int TAMs);

/***********************************************************************/

void InicializarServicio(eServicio listadoServicio[], int TAMs);

/***********************************************************************/

int  obtenerIDdeServicio(void);

/***********************************************************************/

int  obtenerUltimoIDdeServicio(void);

/***********************************************************************/

int obtenerIndexServicioLibre(eServicio listadoServicio[], int TAMs);

/***********************************************************************/

int buscarServiciosPorID(eServicio listadoServicio[], int TAMs, int ID);

/***********************************************************************/

eServicio cargarDatosServicio(void);

/***********************************************************************/

eServicio modificarUnServicio(eServicio servicio);

/***********************************************************************/

int altaServicio(eServicio listadoServicio[], int TAMs);

/***********************************************************************/

int bajaServicio(eServicio listadoServicio[], int TAMs);

/***********************************************************************/

int modificacionServicio(eServicio listadoServicio[], int TAMs);


/********** FUNCIONES MOSTRAR Y ORDENAR ****************************************************************/

void mostrarUnServicio(eServicio listadoServicio);

/***********************************************************************/

int mostrarTodosLosServicios(eServicio listadoServicio[], int TAMs);

//void informeTotalPreciosServicios(eTrabajo listadoTrabajo[], int TAM, eBicicleta listadoBicicleta[], int TAMb, eServicio listadoServicio[], int TAMs);
/********** SORT ***************************************************************************************/
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
//int ordenaEmpleadosPorApellido(eTrabajo listadoTrabajo[], int TAM, int criterio);

#endif /* ARRAYSERVICIO_H_ */
