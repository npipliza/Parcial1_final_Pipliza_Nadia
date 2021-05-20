#include "arrayTrabajo_v2.h"
#include "arrayBicicleta_v2.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayServicio_v2.h"

//ID AUTOINCREMENTAL
int idIncremental = 20003;
int idServicio;
//int pedirDatos;
//int modificarDatos;

/** INICIALIZAR ESTRUCTURAS */
/************************************************************************************/
void InicializarServicio(eServicio listadoServicio[], int TAMs)
{
	int i;

	for (i = 0; i < TAMs; i++)
	{
		listadoServicio[i].isEmpty = VACIO;
	}//fin for
}//fin funcion InicializarServicio

/** DATOS HARDCODEADOS DE ESTRUCTURAS */
/************************************************************************************/
void HardcodearServicios(eServicio listadoServicio[], int TAMs)
{//Servicios (Limpieza: $250, Parche: $300, Centrado: $400, Cadena: $350)
	int   i;
	int   idServicio[]      = {20000, 20001, 20002, 20003};
	float precioServicio[]  = {250, 250, 250, 250};
	char  Descripcion[][25] = {"Limpieza","Parche","Centrado","Cadena"};
	int   isEmpty[]         = {OCUPADO, OCUPADO, OCUPADO, OCUPADO};

	for(i = 0; i < TAMs; i++)
	{
		listadoServicio[i].idServicio       = idServicio[i];
		strcpy(listadoServicio[i].descripcion,Descripcion[i]);
		listadoServicio[i].precioServicio   = precioServicio[i];
		listadoServicio[i].isEmpty          = isEmpty[i];
	}//fin for
}//fin funcion HardcodearServicios

/************************************************************************************/
int obtenerIDdeServicio()
{
	return idIncremental+=1;
}

/************************************************************************************/
int obtenerUltimoIDdeServicio()
{
	return idIncremental;
}

/************************************************************************************/
void mostrarUnServicio(eServicio listadoServicio)
{
		if(listadoServicio.isEmpty == OCUPADO)
		{
			printf("%2d %10s %10.2f \n", listadoServicio.idServicio,
										 listadoServicio.descripcion,
										 listadoServicio.precioServicio);
		}
}

/************************************************************************************/
int mostrarTodosLosServicios(eServicio listadoServicio[], int TAMs)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	printf("\t -----> LISTA DE SERVICIOS <----- \n");
	printf("\nID \tSERVICIO     PRECIO\n");
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listadoServicio != NULL && TAMs > 0)
	{
		for(i = 0; i < TAMs; i++)
		{//PREGUNTO POR SU ESTADO "OCUPADO"
			if (listadoServicio[i].isEmpty == OCUPADO)
			{//MUESTRO UN SOLO SERVICIO
				//HardcodearServicios(listadoServicio, TAMs);
				mostrarUnServicio(listadoServicio[i]);
				//CONTADOR DE SERVICIO
				cantidad++;
			}
		}
	}
	//SI CANTIDAD == 0 - NO HUBO SERVICIOS PARA MOSTRAR (ARRAY SIN ALTAS)
	if(cantidad > 0)
	{
		rtn = 1;
	}
	return rtn;
}
/************************************************************************************/
eServicio cargarDatosServicio(void)
{
	eServicio auxiliar;

	auxiliar.idServicio = obtenerIDdeServicio();

	utn_getPalabra(auxiliar.descripcion ,sizeof(auxiliar.descripcion), "\nIngrese descripción: ", "\nERROR: Ingrese hasta 25 letras. \n", 20);
	utn_getNumeroFlotante(&auxiliar.precioServicio,"Ingrese precio: ","\nERROR: Ingrese precio válido.\n",1,999999,10);

    auxiliar.isEmpty = OCUPADO;

	return auxiliar;
}

/************************************************************************************/
int obtenerIndexServicioLibre(eServicio listadoServicio[], int TAMs)
{
	int rtn = -1;
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listadoServicio != NULL && TAMs > 0)
	{
		for(i = 0; i < TAMs; i++)
		{//PREGUNTO POR EL ESTADO "LIBRE"
			if(listadoServicio[i].isEmpty == VACIO)
			{//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

/************************************************************************************/
int altaServicio(eServicio listadoServicio[], int TAMs)
{
	int rtn = 0;
	eServicio auxServicio;
	//BUSCO ESPACIO EN ARRAY
	int index = obtenerIndexServicioLibre(listadoServicio, TAMs);

	if(index != -1)// == -1 array lleno, != -1 hay lugar.
	{
		auxServicio            = cargarDatosServicio();
		listadoServicio[index] = auxServicio;
		rtn                    = index;//case1//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
	}
	else
	{
		rtn = -1;
	}
	return rtn;
}

/************************************************************************************/
eServicio modificarUnServicio(eServicio servicio)
{
	int mostrarOpciones;

	eServicio auxiliar = servicio;

	do//creo bucle del menu
	{
		printf("\nINGRESE OPCIÓN A MODIFICAR: ************************************\n"
			   "1. Descripción.\n"
			   "2. Precio.\n"
			   "0. SALIR\n"
			   "Elija una opción: \n");
		scanf("%d", &mostrarOpciones);

		switch(mostrarOpciones)
		{
			case 1:
				utn_getPalabra(auxiliar.descripcion ,sizeof(auxiliar.descripcion), "\nIngrese descripción: ", "\nERROR: Ingrese hasta 25 letras. \n", 20);
			break;

			case 2:
				utn_getNumeroFlotante(&auxiliar.precioServicio,"Ingrese precio: ","\nERROR: Ingrese precio válido.\n",1,999999,10);
			break;
		}
	}while(mostrarOpciones != 0);

	auxiliar.isEmpty = OCUPADO;
	return auxiliar;

}

/************************************************************************************/
int buscarServiciosPorID(eServicio listadoServicio[], int TAMs, int ID)
{
	int rtn = -1;
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listadoServicio != NULL && TAMs > 0)
	{
		for(i = 0; i < TAMs; i++)
		{//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (listadoServicio[i].idServicio == ID && listadoServicio[i].isEmpty == OCUPADO)
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
int modificacionServicio(eServicio listadoServicio[], int TAMs)
{
	int rtn = 0;
	int idServicio;
	int index;
	int opcion;
	int opcion1;
	int bandera = 0;
	eServicio auxiliar;

	//LISTO TODOS LOS SERVICIOS
	if(mostrarTodosLosServicios(listadoServicio, TAMs) != 0)
	{//BANDERA EN 1 SI HAY SERVICIOS DADOS DE ALTA PARA LISTAR
		bandera = 1;
	}
	else
	{
		printf("\n * NO EXISTEN SERVICIOS DADOS DE ALTA.\n");
	}

	//SI HAY SERVICIOS PARA MODIFICAR
	if(bandera == 1)
	{//PIDO ID A MODIFICAR
		printf("\n***** OPCIÓN MODIFICAR ***** \n");
		do
		{
			opcion = 0;
			printf("INGRESE EL ID.\n");
			scanf("%d", &idServicio);

		//OBTENGO INDEX DEL ARRAY DE SERVICIOS A MODIFICAR
		index = buscarServiciosPorID(listadoServicio, TAMs, idServicio);

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
			//LLAMO A FUNCION QUE MODIFICA SERVICIOS
			auxiliar = modificarUnServicio(listadoServicio[index]);
			printf("¿CONFIRMA LA MODIFICACIÓN DEL SERVICIO? \n Confirmar: 1\n Cancelar:  2\n");
			scanf("%d", &opcion1);

			if(opcion1 == 1)
			{
				listadoServicio[index] = auxiliar;
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
int bajaServicio(eServicio listadoServicio[], int TAMs)
{
	int rtn = 0;
	int idServicio;
	int index;
	int bandera = 0;
	int opcion;
	int opcion1;

	//LISTO TODOS LOS SERVICIOS
	if(mostrarTodosLosServicios(listadoServicio, TAMs) != 0)
	{//BANDERA EN 1 SI HAY SERVICIOS DADOS DE ALTA PARA LISTAR
		bandera = 1;
	}
	else
	{
		printf("\n * NO EXITEN TRABAJOS DADOS DE ALTA.\n");
	}
	//SI HAY SERVICIOS PARA DAR DE BAJA
	if(bandera == 1)
	{//PIDO ID A DAR DE BAJA
		printf("\n***** OPCIÓN BAJA ***** \n");
		do
		{
			opcion1 = 0;
			printf("ingrese el ID.\n");
			scanf("%d", &idServicio);

			//OBTENGO INDEX DEL ARRAY DE SERVICIOS A DAR DE BAJA
			index = buscarServiciosPorID(listadoServicio, TAMs, idServicio);

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
			printf("\nID \tSERVICIO     PRECIO\n");
			mostrarUnServicio(listadoServicio[index]);

			printf("\n¿Confirma la baja del servicio? \n  Confirmar: 1\n  Cancelar: 2\n");
			scanf("%d", &opcion);

			if(opcion == 1)
			{
				listadoServicio[index].isEmpty = BAJA;
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
void informeTotalPreciosServicios(eTrabajo listadoTrabajo[], int TAM, eBicicleta listadoBicicleta[], int TamB, eServicio listadoServicio[], int TamS)
{
	int i;
	int j;
	float acumulador = 0;

	for(i = 0; i < TAM; i++)
	{//PREGUNTO POR EL ESTADO "LIBRE"
		for(j = 0; j < TamS; j++)
		{//PREGUNTO POR EL ESTADO "LIBRE"
			if(listadoTrabajo[i].isEmpty == VACIO && (listadoTrabajo[i].idServicio == listadoServicio[i].idServicio))
			{//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				acumulador = listadoServicio[i].precioServicio + acumulador;
 			}
		}
	}
	printf("\nEl acumulado de los servicios es: %.2f\n", acumulador);
}

