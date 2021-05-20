#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayTrabajo_v2.h"
#include "arrayServicio_v2.h"
#include "arrayBicicleta_v2.h"
#include "utn.h"
//#define TamS 10
//ID AUTOINCREMENTAL
int idIncrementalT = 0;
int idTrabajo;

int pedirDatos;
int modificarDatos;

//eServicio servicio[TamS];
/** INICIALIZAR ESTRUCTURAS ******************************************************************* */
void InicializarTrabajo(eTrabajo listadoTrabajo[], int TamT)
{
	int i;

	for (i = 0; i < TamT; i++)
	{
		listadoTrabajo[i].isEmpty = VACIO;
	}//fin for
}//fin funcion InicializarTrabajo

/************************************************************************************/
int obtenerIDdeTrabajo()
{
	return idIncrementalT+=1;
}

/************************************************************************************/
int obtenerUltimoIDdeTrabajo()
{
	return idIncrementalT;
}

/************************************************************************************/
int obtenerIndexTrabajoLibre(eTrabajo listadoTrabajo[], int TAM)
{
	int rtn = -1;
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listadoTrabajo != NULL && TAM > 0)
	{
		for(i = 0; i < TAM; i++)
		{//PREGUNTO POR EL ESTADO "LIBRE"
			if(listadoTrabajo[i].isEmpty == VACIO)
			{//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

/************************************************************************************/
int altaTrabajo(eTrabajo listadoTrabajo[], int TAM, eServicio listadoServicio[], int TAMs)
{
	int rtn = 0;
	eTrabajo auxTrabajo;
	//BUSCO ESPACIO EN ARRAY
	int index = obtenerIndexTrabajoLibre(listadoTrabajo, TAM);

	if(index != -1)// == -1 array lleno, != -1 hay lugar.
	{
		auxTrabajo            = cargarDatosTrabajo(listadoServicio, TAMs);
		listadoTrabajo[index] = auxTrabajo;
		rtn                   = index;//case1//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
	}
	else
	{
		rtn = -1;
	}
	return rtn;
}

/************************************************************************************/
int buscarTrabajosPorID(eTrabajo listadoTrabajo[], int TAM, int ID, eBicicleta listadoBicicleta[], int TamB)
{
	int rtn = -1;
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listadoTrabajo != NULL && TAM > 0)
	{
		for(i = 0; i < TAM; i++)
		{//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (listadoTrabajo[i].idTrabajo == ID && listadoTrabajo[i].isEmpty == OCUPADO)
			{//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

/************************************************************************************/
void mostrarUnTrabajo(eTrabajo trabajo, eBicicleta bicicleta, eServicio servicio)
{
		if(trabajo.isEmpty == OCUPADO)
		{
		   printf("%2d %12s %8.2f %8d/%d/%d %12s \n", trabajo.idTrabajo,
													  bicicleta.marcaBicicleta,
													  bicicleta.rodadoBicicleta,
													  trabajo.dia,
													  trabajo.mes,
												   	  trabajo.anio,
													  servicio.descripcion);
		}
}

/************************************************************************************/
int mostrarTodosLosTrabajos(eTrabajo listadoTrabajo[], int TAM, eBicicleta listadoBicicleta[], int TamB, eServicio listadoServicio[], int TAMs)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	printf("\t -----> LISTA DE TRABAJOS <----- \n");
	printf("\nID \t MARCA\t   RODADO\t FECHA\t    SERVICIO\n");
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listadoTrabajo != NULL && TAM > 0)
	{
		for(i = 0; i < TAM; i++)
		{//PREGUNTO POR SU ESTADO "OCUPADO"
			if (listadoTrabajo[i].isEmpty == OCUPADO)
			{//MUESTRO UN SOLO TRABAJO
				mostrarUnTrabajo(listadoTrabajo[i], listadoBicicleta[i], listadoServicio[i]);
				//CONTADOR DE TRABAJO
				cantidad++;
			}
		}
	}
	//SI CANTIDAD == 0 - NO HUBO TRABAJOS PARA MOSTRAR (ARRAY SIN ALTAS)
	if(cantidad > 0)
	{
		rtn = 1;
	}
	return rtn;
}

/************************************************************************************/
eTrabajo cargarDatosTrabajo(eServicio listadoServicio[], int TAMs)
{
	eTrabajo   auxiliar;
	eBicicleta auxBicicleta;
	//eServicio  auxServicio;

	auxiliar.idTrabajo       = obtenerIDdeTrabajo();
	auxBicicleta.idBicicleta = obtenerIDdeBicicleta();
	//auxServicio.idServicio   = obtenerIDdeServicio();

	utn_getPalabra(auxBicicleta.marcaBicicleta ,sizeof(auxBicicleta.marcaBicicleta), "\nIngrese marca: ", "\nERROR: Ingrese hasta 25 letras. \n", 20);
	utn_getNumeroFlotante(&auxBicicleta.rodadoBicicleta,"Ingrese rodado: ","\nERROR: Ingrese rodado válido.\n",20,29,10);
	utn_getNumero(&auxiliar.dia,"Ingrese dia: ","\nERROR: Ingrese dia válido.\n",1,31,5);
	utn_getNumero(&auxiliar.mes,"Ingrese mes: ","\nERROR: Ingrese mes válido.\n",1,12,5);
	utn_getNumero(&auxiliar.anio,"Ingrese año: ","\nERROR: Ingrese año válido.\n",1990,2021,5);
	mostrarTodosLosServicios(listadoServicio, TAMs);
	utn_getNumero(&auxiliar.idServicio,"Ingrese servicio: ","\nERROR: Ingrese servicio válido.\n",20000,20010,5);

    auxiliar.isEmpty = OCUPADO;

	return auxiliar;
}

/************************************************************************************/
eTrabajo modificarUnTrabajo(eTrabajo trabajo, eBicicleta bicicleta)
{
	int mostrarOpciones;

	eTrabajo auxiliar       = trabajo;
	eBicicleta auxBicicleta = bicicleta;

	do//creo bucle del menu
	{
		printf("\nINGRESE OPCIÓN A MODIFICAR: ************************************\n"
			   "1. Marca.\n"
			   "2. Rodado.\n"
			   "3. Fecha.\n"
			   "0. SALIR\n"
			   "Elija una opción: \n");
		scanf("%d", &mostrarOpciones);

		switch(mostrarOpciones)
		{
			case 1:
				utn_getPalabra(auxBicicleta.marcaBicicleta ,sizeof(auxBicicleta.marcaBicicleta), "\nIngrese marca: ", "\nERROR: Ingrese hasta 25 letras. \n", 20);
			break;

			case 2:
				utn_getNumeroFlotante(&auxBicicleta.rodadoBicicleta,"Ingrese rodado: ","\nERROR: Ingrese rodado válido.\n",20,29,10);
			break;

			case 3:
				utn_getNumero(&auxiliar.dia,"Ingrese dia: ","\nERROR: Ingrese dia válido.\n",1,31,5);
				utn_getNumero(&auxiliar.mes,"Ingrese mes: ","\nERROR: Ingrese mes válido.\n",1,12,5);
				utn_getNumero(&auxiliar.anio,"Ingrese año: ","\nERROR: Ingrese año válido.\n",1990,2021,5);
			break;
		}
	}while(mostrarOpciones != 0);

	auxiliar.isEmpty = OCUPADO;
	return auxiliar;

}

/************************************************************************************/
int modificacionTrabajo(eTrabajo listadoTrabajo[], int TAM, eBicicleta listadoBicicleta[], int TamB, eServicio listadoServicio[], int TamS)
{
	int rtn = 0;
	int idTrabajo;
	int index;
	int opcion;
	int opcion1;
	int bandera = 0;
	eTrabajo auxiliar;

	//LISTO TODOS LOS TRABAJOS
	if(mostrarTodosLosTrabajos(listadoTrabajo, TAM, listadoBicicleta, TamB, listadoServicio, TamS) != 0)
	{//BANDERA EN 1 SI HAY TRABAJOS DADOS DE ALTA PARA LISTAR
		bandera = 1;
	}
	else
	{
		printf("\n * NO EXISTEN TRABAJOS DADOS DE ALTA.\n");
	}

	//SI HAY TRABAJOS PARA MODIFICAR
	if(bandera == 1)
	{//PIDO ID A MODIFICAR
		printf("\n***** OPCIÓN MODIFICAR ***** \n");
		do
		{
			opcion = 0;
			printf("INGRESE EL ID.\n");
			scanf("%d", &idTrabajo);

		//OBTENGO INDEX DEL ARRAY DE TRABAJOS A MODIFICAR
		index = buscarTrabajosPorID(listadoTrabajo, TAM, idTrabajo, listadoBicicleta, TamB);

			//BUSCO INDEX POR ID EN ARRAY
			if(index == -1)
			{
				printf("NO EXISTE ID.\n");

			printf("¿INGRESAR OTRO ID? \n SI: 1\n NO: 2\n");
			scanf("%d", &opcion);

				if(opcion == 2)
				{
					return rtn;
				}
			}
		}while(opcion == 1);



		if(index != -1)
		{
			//LLAMO A FUNCION QUE MODIFICA TRABAJO
		auxiliar = modificarUnTrabajo(listadoTrabajo[index], listadoBicicleta[index]);
			printf("¿CONFIRMA LA MODIFICACIÓN DEL TRABAJO? \n Confirmar: 1\n Cancelar:  2\n");
			scanf("%d", &opcion1);

			if(opcion1 == 1)
			{
				listadoTrabajo[index] = auxiliar;
				rtn = 1;//1 modificó ok
			}
			if(opcion1 == 2)
			{
				return rtn;
			}
		}
	}
	return rtn;
}

/************************************************************************************/
int bajaTrabajo(eTrabajo listadoTrabajo[], int TAM, eBicicleta listadoBicicleta[], int TamB, eServicio listadoServicio[], int TAMs)
{
	int rtn = 0;
	int idTrabajo;
	int index;
	int bandera = 0;
	int opcion;
	int opcion1;

	//LISTO TODOS LOS TRABAJOS
	if(mostrarTodosLosTrabajos(listadoTrabajo, TAM, listadoBicicleta, TamB, listadoServicio, TAMs) != 0)
	{//BANDERA EN 1 SI HAY TRABAJOS DADOS DE ALTA PARA LISTAR
		bandera = 1;
	}
	else
	{
		printf("\n * NO EXITEN TRABAJOS DADOS DE ALTA.\n");
	}
	//SI HAY TRABAJOS PARA DAR DE BAJA
	if(bandera == 1)
	{//PIDO ID A DAR DE BAJA
		printf("\n***** OPCIÓN BAJA ***** \n");
		do
		{
			opcion1 = 0;
			printf("ingrese el ID.\n");
			scanf("%d", &idTrabajo);

			//OBTENGO INDEX DEL ARRAY DE TRABAJOS A DAR DE BAJA
			index = buscarTrabajosPorID(listadoTrabajo, TAM, idTrabajo, listadoBicicleta, TamB);

			//BUSCO INDEX POR ID EN ARRAY
			if(index == -1)
			{
				printf("NO EXISTE ID.\n");
				printf("¿Ingresar otro ID? \n SI: 1\n NO: 2\n");
				scanf("%d", &opcion1);

				if(opcion1 == 2)
				{
					return rtn;
				}
			}
		}while(opcion1 == 1);

		if(index != -1)
		{
			printf("\nID \t MARCA\t   RODADO\t FECHA\t    SERVICIO\n");
			mostrarUnTrabajo(listadoTrabajo[index], listadoBicicleta[index], listadoServicio[index]);

			printf("\n¿Confirma la baja del trabajo? \n  Confirmar: 1\n  Cancelar: 2\n");
			scanf("%d", &opcion);

			if(opcion == 1)
			{
				listadoTrabajo[index].isEmpty = BAJA;
				rtn = 1;//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
			}
			if(opcion == 2)
			{
				return rtn;
			}
		}
	}
	return rtn;
}

/************************************************************************************/
int trabajosOrdenadosPorMarca(eBicicleta listadoBicicleta[], int TamB, int criterio)
{
	int rtn = 0;
	int i;
	int j;

	eBicicleta aux;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listadoBicicleta != NULL && TamB > 0)
	{
		switch(criterio)
		{
			case 1:
				for(i = 0; i < TamB - 1; i++)
				{
					for (j = i + 1; j < TamB; j++)
					{//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
						if(listadoBicicleta[i].isEmpty == OCUPADO && listadoBicicleta[j].isEmpty == OCUPADO)
						{//CRITERIO DE ORDENAMIENTO
							if(strcmp(listadoBicicleta[i].marca, listadoBicicleta[j].marca) == 1)
							{//INTERCAMBIO POSICIONES EN ARRAY
								aux                 = listadoBicicleta[i];
								listadoBicicleta[i] = listadoBicicleta[j];
								listadoBicicleta[j] = aux;
							}
						/*	else
							{
								if(listadoBicicleta[j].sector > listadoBicicleta[i].sector)
								{
									aux               = listadoBicicleta[j];
									listadoBicicleta[j] = listadoBicicleta[i];
									c[i] = aux;
								}
							}*/
						}
					}
				}
				rtn = 1;
			break;

			/*case 2:
				for(i = 0; i < TAM - 1; i++)
				{
					for(j = i + 1; j < TAM; j++)
					{//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
						if(listadoTrabajo[i].isEmpty == OCUPADO && listadoTrabajo[j].isEmpty == OCUPADO)
						{//CRITERIO DE ORDENAMIENTO
							if(strcmp(listadoTrabajo[i].apellido, listadoTrabajo[j].apellido) == -1)
							{//INTERCAMBIO POSICIONES EN ARRAY
								aux               = listadoTrabajo[i];
								listadoTrabajo[i] = listadoTrabajo[j];
								listadoTrabajo[j] = aux;
							}
							else
							{
								if(listadoTrabajo[j].sector > listadoTrabajo[i].sector)
								{
									aux               = listadoTrabajo[j];
									listadoTrabajo[j] = listadoTrabajo[i];
									listadoTrabajo[i] = aux;
								}
							}
						}
					}
				}
				rtn = 1;
			break;*/

			default:
				//CRITERIO DE ORDENAMIENTO MAL INGRESADO
				printf("ERROR al cargar criterio de ordenamiento.\n");
				rtn = 0;
			break;
		}//fin funcion switch
	}
	return rtn;
}

/************************************************************************************/
/*
int informeSalarios(eTrabajo listadoTrabajo[], int len)
{
	int rtn              = 0;
	int   i;
	float acumuladorS    = 0;
	int   contadorE      = 0;
	int   superaPromedio = 0;
	float promedio;

	if(listadoTrabajo != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(listadoTrabajo[i].isEmpty == OCUPADO)
			{
				acumuladorS = acumuladorS + listadoTrabajo[i].salario;
				contadorE ++;
			}
		}
	}

	promedio = acumuladorS / contadorE;

	printf("\nPROMEDIO DE SALARIOS: $ %.2f\n", promedio);
	printf("SUMA TOTAL DE SALARIOS: $ %.2f\n", acumuladorS);

	for(i = 0; i < len; i++)
	{
		if(listadoTrabajo[i].salario > promedio)
		{
			superaPromedio ++;
		}
	}
	printf("TRABAJOS CON SUELDO POR ENCIMA DEL PROMEDIO: %d \n", superaPromedio);

	return rtn;
}*/
