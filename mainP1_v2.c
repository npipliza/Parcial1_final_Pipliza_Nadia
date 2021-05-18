/* ============================================================================
    Parcial1 Labo.: 2
    Division      : 1ro B
    Alumna        : Pipliza Nadia
   ============================================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayServicio_v2.h"
#include "arrayTrabajo_v2.h"
#include "utn.h"

#define TamS 4
#define TamT 10

int main()
{
    eServicio listadoServicio[TamS];
    eTrabajo  listadoTrabajo[TamT];

	int mostrarOpciones;
	int criterioDeOrdenamiento;
	int indexUltimo;
	int opciones;

	//ver
	int idServElegido;
	int IdIncremental;
	int id = 0;
	int banderaDeCompletado=0;
	int retorno;

    setbuf(stdout, NULL);

    InicializarServicio(listadoServicio,TamS);
    InicializarTrabajo(listadoTrabajo,TamT);

    HardcodearServicios(listadoServicio,TamS);
	//agregarServicio(arrayServicios,4,0, 20000, "Limpieza",250);
	//agregarServicio(arrayServicios,4,1, 20001, "Parche",300);
	//agregarServicio(arrayServicios,4,2, 20002, "Centrado",400);
	//agregarServicio(arrayServicios,4,3, 20003, "Cadena",350);

    printf("INICIO... \n");
	do//creo bucle del menu
	{
		mostrarOpciones = PedirEntero("\nINGRESE UNA OPCIÓN: ***********************************************\n"
									  "1. ALTA Trabajo.\n"
									  "2. BAJA Trabajo.\n"
									  "3. MODIFICAR Trabajo.\n"
									  "4. MOSTRAR TOTAL Trabajos.\n"
									  "5. MOSTRAR Trabajos ordenados por fecha.\n"
									  "6. INFORME Trabajos.\n"
									  "0. SALIR\n"
									  "Elija una opción: ","\nError. Ingrese número de opción: ");

		switch(mostrarOpciones)
		{
			//ALTA EMPLEADOS
			case 1:

				indexUltimo = altaTrabajo(listadoTrabajo, TamT);
				if(indexUltimo != -1)
				{
					printf("\n * TRABAJO DADO DE ALTA EXITOSAMENTE\n");
					printf("\nID \t MARCA\t\t RODADO\t FECHA\t \tSERVICIO\n");
					mostrarUnEmpleado(listadoTrabajo[indexUltimo], listadoServicio[indexUltimo]);
				}
				else
				{
					printf("\n * ERROR. SIN ESPACIO PARA ALMACENAR MAS EMPLEADOS\n");
				}
				system("pause");
			break;

			//BAJA EMPLEADO
			case 2:
			/*	if(bajaEmpleado(listadoTrabajo, TamT) == 1)
				{
					printf("\n * BAJA DE EMPLEADO EXITOSA\n");
					mostrarTodosLosEmpleados(listadoTrabajo, TamT, listadoServicio, TamS);
				}
				else
				{
					printf("\n * BAJA DE EMPLEADO CANCELADA\n");
				}
				system("pause");*/
			break;

			//MODIFICACION EMPLEADOS
			case 3:
			/*	if(modificacionEmpleado(listadoTrabajo, TamT) == 1)
				{
					printf("\n * MODIFICACION DE EMPLEADO EXITOSA\n");
					mostrarTodosLosEmpleados(listadoTrabajo, TamT, listadoServicio, TamS);
				}
				else
				{
					printf("\n * MODIFICACION DE EMPLEADO CANCELADA\n");
				}
				system("pause");*/
			break;

			//MOSTRAR TOTAL EMPLEADOS
			case 4:
				mostrarTodosLosEmpleados(listadoTrabajo, TamT, listadoServicio, TamS);
				system("pause");
			break;

			//MOSTRAR EMPLEADOS ORDENADOS POR APELLIDO
			case 5://1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
				printf("\n * SELECCIONE: \n 1: A-Z \n 2: Z-A \n");
				scanf("%d", &opciones);

				criterioDeOrdenamiento = opciones;

				if(criterioDeOrdenamiento != 0)
				{
				//	ordenaEmpleadosPorApellido(listadoTrabajo, TamT, criterioDeOrdenamiento);
					mostrarTodosLosEmpleados(listadoTrabajo, TamT, listadoServicio, TamS);
				}
				else
				{
					printf("\n * CANCELADO\n");
				}
				system("pause");
			break;

			//INFORMAR TOTAL Y PROMEDIO DE SALARIOS / CANTIDAD DE EMPLEADOS QUE SUPERAN EL PROMEDIO.
			case 6:
				//int retorno;

				if(criterioDeOrdenamiento != 0)
				{
					//informeSalarios(listadoTrabajo, TamT);
				}
				else
				{
					printf("\n * CANCELADO\n");
				}
				system("pause");
			break;
		}//fin switch mostrarOpciones
	}while(mostrarOpciones != 0);

	printf("\n...PROGRAMA FINALIZADO.");

	return EXIT_SUCCESS;
}//fin funcion main
