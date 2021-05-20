/* ============================================================================
    Parcial1 Labo.: parte dos
    Division      : 1ro B
    Alumna        : Pipliza Nadia
   ============================================================================ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayTrabajo_v2.h"
#include "arrayServicio_v2.h"
#include "arrayBicicleta_v2.h"
#include "utn.h"
#define TamT 10
#define TamS 10
#define TamB 10
int main()
{
    eTrabajo   listadoTrabajo[TamT];
    eServicio  listadoServicio[TamS];
    eBicicleta listadoBicicleta[TamB];

	int mostrarOpciones;
	int opcionesServicio;
	int opcionesBicicleta;
	int indexUltimoT;
	int indexUltimoS;
	int indexUltimoB;
	int criterioDeOrdenamiento;

    setbuf(stdout, NULL);

    InicializarServicio(listadoServicio,TamS);
    InicializarTrabajo(listadoTrabajo,TamT);
    HardcodearServicios(listadoServicio,TamS);
    HardcodearBicicletas(listadoBicicleta,TamS);

    printf("INICIO... \n");
	do//creo bucle del menu
	{
		mostrarOpciones = PedirEntero("\nINGRESE UNA OPCIÓN: ***********************************************\n"
									  "1. ALTA Trabajo.\n"
									  "2. BAJA Trabajo.\n"
									  "3. MODIFICAR Trabajo.\n"
									  "4. LISTA Trabajos.\n"
									  "5. LISTA Servicios.\n"
									  "6. INFORME Recaudación Servicios.\n"
									  "7. MENÚ ABM SERVICIOS.\n"
									  "8. MENÚ ABM BICICLETAS.\n"
									  "0. SALIR\n"
									  "Elija una opción: ","\nError. Ingrese número de opción: ");

		switch(mostrarOpciones)
		{
			//ALTA TRABAJO
			case 1:
				indexUltimoT = altaTrabajo(listadoTrabajo, TamT, listadoServicio, TamS);
				if(indexUltimoT != -1)
				{
					printf("\n * TRABAJO DADO DE ALTA EXITOSAMENTE\n");
					printf("\nID \t MARCA\t   RODADO\t FECHA\t    SERVICIO\n");
					//mostrarUnTrabajo(listadoTrabajo[indexUltimoT], listadoBicicleta[indexUltimoB], listadoServicio[indexUltimoS]);
				}
				else
				{
					printf("\n * ERROR. SIN ESPACIO PARA ALMACENAR MAS TRABAJOS\n");
				}
				system("pause");
			break;

			//BAJA TRABAJO
			case 2:
				if(bajaTrabajo(listadoTrabajo, TamT, listadoBicicleta, TamB, listadoServicio, TamS) == 1)
				{
					printf("\n * BAJA DE TRABAJO EXITOSA\n");
					mostrarTodosLosTrabajos(listadoTrabajo, TamT, listadoBicicleta, TamB, listadoServicio, TamS);
				}
				else
				{
					printf("\n * BAJA DE TRABAJO CANCELADA\n");
				}
				system("pause");
			break;

			//MODIFICACION TRABAJO
			case 3:
				if(modificacionTrabajo(listadoTrabajo, TamT, listadoBicicleta, TamB, listadoServicio, TamS) == 1)
				{
					printf("\n * MODIFICACION DE TRABAJO EXITOSA\n");
					mostrarTodosLosTrabajos(listadoTrabajo, TamT, listadoBicicleta, TamB, listadoServicio, TamS);
				}
				else
				{
					printf("\n * MODIFICACION DE TRABAJO CANCELADA\n");
				}
				system("pause");
			break;

			//LISTA TRABAJOS
			case 4:
				mostrarTodosLosTrabajos(listadoTrabajo, TamT, listadoBicicleta, TamB, listadoServicio, TamS);
				system("pause");
			break;

			//LISTA SERVICIOS
			case 5:
				mostrarTodosLosServicios(listadoServicio, TamS);
				system("pause");
			break;

			//INFORMAR PRECIO TOTAL SERVICIOS
			case 6://F. TOTAL en pesos por los servicios prestados.
				informeTotalPreciosServicios(listadoTrabajo, TamT, listadoBicicleta, TamB, listadoServicio, TamS);
				system("pause");
			break;

			//ABM SERVICIOS
			case 7:
			    printf("\nINICIO ABM SERVICIOS... \n");
				do//creo bucle del menu
				{
					opcionesServicio = PedirEntero("\nINGRESE UNA OPCIÓN: ***********************************************\n"
												  "1. ALTA Servicio.\n"
												  "2. BAJA Servicio.\n"
												  "3. MODIFICAR Servicio.\n"
												  "4. LISTA Servicios.\n"
												  "0. SALIR\n"
												  "Elija una opción: ","\nError. Ingrese número de opción: ");
					switch(opcionesServicio)
					{	//ALTA SERVICIO
						case 1:
							indexUltimoS = altaServicio(listadoServicio, TamS);
							if(indexUltimoS != -1)
							{
								printf("\n * SERVICIO DADO DE ALTA EXITOSAMENTE\n");
								printf("\nID \tSERVICIO     PRECIO\n");
								mostrarTodosLosServicios(listadoServicio, TamS);
							}
							else
							{
								printf("\n * ERROR. SIN ESPACIO PARA ALMACENAR MAS SERVICIOS\n");
							}
							system("pause");
						break;

						//BAJA SERVICIO
						case 2:
							if(bajaServicio(listadoServicio, TamS) == 1)
							{
								printf("\n * BAJA DE SERVICIO EXITOSA\n");
								mostrarTodosLosServicios(listadoServicio, TamS);;
							}
							else
							{
								printf("\n * BAJA DE SERVICIO CANCELADA\n");
							}
							system("pause");
						break;

						//MODIFICACION SERVICIO
						case 3:
							if(modificacionServicio(listadoServicio, TamS) == 1)
							{
								printf("\n * MODIFICACION DE SERVICIO EXITOSA\n");
								mostrarTodosLosServicios(listadoServicio, TamS);
							}
							else
							{
								printf("\n * MODIFICACION DE SERVICIO CANCELADA\n");
							}
							system("pause");
						break;

						//LISTA SERVICIOS
						case 4:
							mostrarTodosLosServicios(listadoServicio, TamS);
							system("pause");
						break;
					}//fin switch opcionesServicio
				}while(opcionesServicio != 0);
				printf("\n...ABM SERVICIOS FINALIZADO.\n");
				system("pause");
			break;

			//ABM BICICLETAS
			case 8:
				printf("\nINICIO ABM BICICLETAS... \n");
				do//creo bucle del menu
				{
					opcionesBicicleta = PedirEntero("\nINGRESE UNA OPCIÓN: ***********************************************\n"
												  "1. ALTA Bicicleta.\n"
												  "2. BAJA Bicicleta.\n"
												  "3. MODIFICAR Bicicleta.\n"
												  "4. LISTA Bicicleta.\n"
												  "0. SALIR\n"
												  "Elija una opción: ","\nError. Ingrese número de opción: ");
					switch(opcionesBicicleta)
					{	//ALTA BICICLETA
						case 1:
							indexUltimoB = altaBicicleta(listadoBicicleta, TamB);
							if(indexUltimoB != -1)
							{
								printf("\n * BICICLETA DADA DE ALTA EXITOSAMENTE\n");
								printf("\nID \tSERVICIO     PRECIO\n");
								mostrarTodasLasBicicletas(listadoBicicleta, TamB);
							}
							else
							{
								printf("\n * ERROR. SIN ESPACIO PARA ALMACENAR MAS BICICLETAS\n");
							}
							system("pause");
						break;

						//BAJA BICICLETA
						case 2:
							if(bajaBicicleta(listadoBicicleta, TamB) == 1)
							{
								printf("\n * BAJA DE BICICLETA EXITOSA\n");
								mostrarTodasLasBicicletas(listadoBicicleta, TamB);;
							}
							else
							{
								printf("\n * BAJA DE BICICLETA CANCELADA\n");
							}
							system("pause");
						break;

						//MODIFICACION BICICLETA
						case 3:
							if(modificacionBIcicleta(listadoBicicleta, TamB) == 1)
							{
								printf("\n * MODIFICACION DE BICICLETA EXITOSA\n");
								mostrarTodasLasBicicletas(listadoBicicleta, TamB);
							}
							else
							{
								printf("\n * MODIFICACION DE BICICLETA CANCELADA\n");
							}
							system("pause");
						break;

						//LISTA BICICLETAS
						case 4:
							mostrarTodasLasBicicletas(listadoBicicleta, TamB);
							system("pause");
						break;
					}//fin switch opcionesBicicleta
				}while(opcionesBicicleta != 0);
				printf("\n...ABM BICICLETAS FINALIZADO.\n");
				system("pause");
			break;

			//1. Listado de todos los trabajos ordenados por marca de la bicicleta.
			//2. El o los servicios con más trabajos realizados.
			//3. Listado de servicios con los datos de las bicicletas que se lo realizaron.
			//4. La cantidad de biciletas de color Rojo que realizaron un servicio
			//elegido por el usuario.
			//ABM BICICLETAS
		/*	case 9:
				if(criterioDeOrdenamiento != 0)
				{
					trabajosOrdenadosPorMarca(listadoBicicleta, TamB);
				}
				else
				{
					printf("\n * CANCELADO\n");
				}
				system("pause");
			break;*/

		}//fin switch mostrarOpciones
	}while(mostrarOpciones != 0);

	printf("\n...PROGRAMA FINALIZADO.");

	return EXIT_SUCCESS;
}//fin funcion main
