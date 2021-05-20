#ifndef ARRAYBICICLETA_V2_H_
#define ARRAYBICICLETA_V2_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayTrabajo_v2.h"
#include "arrayServicio_v2.h"
//#define T 10
#define VACIO 0
#define OCUPADO 1
#define BAJA -1
/********** ESTRUCTURAS ********************************************************************************/
//isEmpty 0 vacio - 1 ocupado
typedef struct
{
    int   idBicicleta;
    char  marcaBicicleta[25];
    float rodadoBicicleta;
    char  colorBicicleta[25];
    int   isEmpty;
}eBicicleta;

/********** FUNCIONES ABM ******************************************************************************/

void HardcodearBicicletas(eBicicleta listadoBicicleta[], int TamB);

/***********************************************************************/

void InicializarBicicleta(eBicicleta listadoBicicleta[], int TamB);

/***********************************************************************/

int obtenerIDdeBicicleta();

/***********************************************************************/

int obtenerUltimoIDdeBicicleta();

/***********************************************************************/

int obtenerIndexBicicletaLibre(eBicicleta listadoBicicleta[], int TamB);

/***********************************************************************/

int buscarBicicletasPorID(eBicicleta listadoBicicleta[], int TamB, int ID);

/***********************************************************************/

eBicicleta cargarDatosBicicleta(void);

/***********************************************************************/

eBicicleta modificarUnaBicicleta(eBicicleta bicicleta);

/***********************************************************************/

int altaBicicleta(eBicicleta listadoBicicleta[], int TamB);

/***********************************************************************/

int bajaBicicleta(eBicicleta listadoBicicleta[], int TamB);

/***********************************************************************/

int modificacionBIcicleta(eBicicleta listadoBicicleta[], int TamB);


/********** FUNCIONES MOSTRAR Y ORDENAR ****************************************************************/

void mostrarUnaBicicleta(eBicicleta bicicleta);

/***********************************************************************/

int mostrarTodasLasBicicletas(eBicicleta listadoBicicleta[], int TamB);

//void informeTotalPreciosServicios(eTrabajo listadoTrabajo[], int TAM, eServicio listadoServicio[], int TAMs);
/********** SORT ***************************************************************************************/
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
//int ordenaEmpleadosPorApellido(eTrabajo listadoTrabajo[], int TAM, int criterio);

#endif /* ARRAYBICICLETA_V2_H_ */
