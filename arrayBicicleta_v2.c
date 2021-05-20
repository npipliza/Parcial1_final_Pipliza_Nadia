#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayTrabajo_v2.h"
#include "arrayServicio_v2.h"
#include "arrayBicicleta_v2.h"
#include "utn.h"

//ID AUTOINCREMENTAL
int idIncrementalB = 24;
int idBicicleta;
int pedirDatos;
int modificarDatos;

/** INICIALIZAR ESTRUCTURAS ******************************************************************* */
void InicializarBicicleta(eBicicleta listadoBicicleta[], int TamB)
{
	int i;

	for (i = 0; i < TamB; i++)
	{
		listadoBicicleta[i].isEmpty = VACIO;
	}//fin for
}//fin funcion InicializarBicicleta

/** DATOS HARDCODEADOS DE ESTRUCTURAS */
/************************************************************************************/
void HardcodearBicicletas(eBicicleta listadoBicicleta[], int TamB)
{
	int   i;
	int   idBicicleta[]        = {25, 26, 27, 28, 29};
	char  marcaBicicleta[][25] = {"Raleigh","Venzo","Olmo","Vairo","TopMega"};
	float rodadoBicicleta[]    = {26, 29, 27, 28, 20};
	char  colorBicicleta[][25] = {"Negro","Plomo","Rojo","Verde","Blanco"};
	int   isEmpty[]            = {OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO};

	for(i = 0; i < TamB; i++)
	{
		listadoBicicleta[i].idBicicleta         = idBicicleta[i];
		strcpy(listadoBicicleta[i].marcaBicicleta,marcaBicicleta[i]);
		listadoBicicleta[i].rodadoBicicleta     = rodadoBicicleta[i];
		strcpy(listadoBicicleta[i].colorBicicleta,colorBicicleta[i]);
		listadoBicicleta[i].isEmpty             = isEmpty[i];
	}//fin for
}//fin funcion HardcodearBicicletas

/************************************************************************************/
int obtenerIDdeBicicleta()
{
	return idIncrementalB+=1;
}

/************************************************************************************/
int obtenerUltimoIDdeBicicleta()
{
	return idIncrementalB;
}

/************************************************************************************/
int obtenerIndexBicicletaLibre(eBicicleta listadoBicicleta[], int TamB)
{
	int rtn = -1;
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listadoBicicleta != NULL && TamB > 0)
	{
		for(i = 0; i < TamB; i++)
		{//PREGUNTO POR EL ESTADO "LIBRE"
			if(listadoBicicleta[i].isEmpty == VACIO)
			{//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

/************************************************************************************/
int altaBicicleta(eBicicleta listadoBicicleta[], int TamB)
{
	int rtn = 0;
	eBicicleta auxBicicleta;
	//BUSCO ESPACIO EN ARRAY
	int index = obtenerIndexBicicletaLibre(listadoBicicleta, TamB);

	if(index != -1)// == -1 array lleno, != -1 hay lugar.
	{
		auxBicicleta            = cargarDatosBicicleta();
		listadoBicicleta[index] = auxBicicleta;
		rtn                     = index;//case1//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
	}
	else
	{
		rtn = -1;
	}
	return rtn;
}

/************************************************************************************/
int buscarBicicletasPorID(eBicicleta listadoBicicleta[], int TamB, int ID)
{
	int rtn = -1;
	int i;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listadoBicicleta != NULL && TamB > 0)
	{
		for(i = 0; i < TamB; i++)
		{//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (listadoBicicleta[i].idBicicleta == ID && listadoBicicleta[i].isEmpty == OCUPADO)
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
void mostrarUnaBicicleta(eBicicleta bicicleta)
{
		if(bicicleta.isEmpty == OCUPADO)
		{
			printf("%2d %12s %8f %12s \n", bicicleta.idBicicleta,
										   bicicleta.marcaBicicleta,
										   bicicleta.rodadoBicicleta,
										   bicicleta.colorBicicleta);
		}
}

/************************************************************************************/
int mostrarTodasLasBicicletas(eBicicleta listadoBicicleta[], int TamB)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	printf("\t -----> LISTA DE BICICLETAS <----- \n");
	printf("\nID \t MARCA\t   RODADO\t COLOR\n");
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listadoBicicleta != NULL && TamB > 0)
	{
		for(i = 0; i < TamB; i++)
		{//PREGUNTO POR SU ESTADO "OCUPADO"
			if (listadoBicicleta[i].isEmpty == OCUPADO)
			{//MUESTRO UN SOLO TRABAJO
				mostrarUnaBicicleta(listadoBicicleta[i]);
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
eBicicleta cargarDatosBicicleta(void)
{
	eBicicleta auxiliar;

	auxiliar.idBicicleta = obtenerIDdeBicicleta();

	utn_getPalabra(auxiliar.marcaBicicleta ,sizeof(auxiliar.marcaBicicleta), "\nIngrese marca: ", "\nERROR: Ingrese hasta 25 letras. \n", 20);
	utn_getNumeroFlotante(&auxiliar.rodadoBicicleta,"Ingrese rodado: ","\nERROR: Ingrese rodado válido.\n",20,29,10);
	utn_getPalabra(auxiliar.colorBicicleta ,sizeof(auxiliar.colorBicicleta), "\nIngrese color: ", "\nERROR: Ingrese hasta 25 letras. \n", 20);

    auxiliar.isEmpty = OCUPADO;

	return auxiliar;
}

/************************************************************************************/
eBicicleta modificarUnaBicicleta(eBicicleta bicicleta)
{
	int mostrarOpciones;

	eBicicleta auxiliar = bicicleta;

	do//creo bucle del menu
	{
		printf("\nINGRESE OPCIÓN A MODIFICAR: ************************************\n"
			   "1. Marca.\n"
			   "2. Rodado.\n"
			   "3. Color.\n"
			   "0. SALIR\n"
			   "Elija una opción: \n");
		scanf("%d", &mostrarOpciones);

		switch(mostrarOpciones)
		{
			case 1:
				utn_getPalabra(auxiliar.marcaBicicleta ,sizeof(auxiliar.marcaBicicleta), "\nIngrese marca: ", "\nERROR: Ingrese hasta 25 letras. \n", 20);
			break;

			case 2:
				utn_getNumeroFlotante(&auxiliar.rodadoBicicleta,"Ingrese rodado: ","\nERROR: Ingrese rodado válido.\n",20,29,10);
			break;

			case 3:
				utn_getPalabra(auxiliar.colorBicicleta ,sizeof(auxiliar.colorBicicleta), "\nIngrese color: ", "\nERROR: Ingrese hasta 25 letras. \n", 20);
			break;
		}
	}while(mostrarOpciones != 0);

	auxiliar.isEmpty = OCUPADO;
	return auxiliar;

}

/************************************************************************************/
int modificacionBIcicleta(eBicicleta listadoBicicleta[], int TamB)
{
	int rtn = 0;
	int idBicicleta;
	int index;
	int opcion;
	int opcion1;
	int bandera = 0;
	eBicicleta auxiliar;

	//LISTO TODOS LOS TRABAJOS
	if(mostrarTodasLasBicicletas(listadoBicicleta, TamB) != 0)
	{//BANDERA EN 1 SI HAY TRABAJOS DADOS DE ALTA PARA LISTAR
		bandera = 1;
	}
	else
	{
		printf("\n * NO EXISTEN BICICLETAS DADAS DE ALTA.\n");
	}

	//SI HAY TRABAJOS PARA MODIFICAR
	if(bandera == 1)
	{//PIDO ID A MODIFICAR
		printf("\n***** OPCIÓN MODIFICAR ***** \n");
		do
		{
			opcion = 0;
			printf("INGRESE EL ID.\n");
			scanf("%d", &idBicicleta);

		//OBTENGO INDEX DEL ARRAY DE TRABAJOS A MODIFICAR
		index = buscarBicicletasPorID(listadoBicicleta, TamB, idBicicleta);

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
		auxiliar = modificarUnaBicicleta(listadoBicicleta[index]);
			printf("¿CONFIRMA LA MODIFICACIÓN DE BICICLETA? \n Confirmar: 1\n Cancelar:  2\n");
			scanf("%d", &opcion1);

			if(opcion1 == 1)
			{
				listadoBicicleta[index] = auxiliar;
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
int bajaBicicleta(eBicicleta listadoBicicleta[], int TamB)
{
	int rtn = 0;
	int idBicicleta;
	int index;
	int bandera = 0;
	int opcion;
	int opcion1;

	//LISTO TODOS LOS TRABAJOS
	if(mostrarTodasLasBicicletas(listadoBicicleta, TamB) != 0)
	{//BANDERA EN 1 SI HAY TRABAJOS DADOS DE ALTA PARA LISTAR
		bandera = 1;
	}
	else
	{
		printf("\n * NO EXISTEN BICICLETAS DADAS DE ALTA.\n");
	}
	//SI HAY TRABAJOS PARA DAR DE BAJA
	if(bandera == 1)
	{//PIDO ID A DAR DE BAJA
		printf("\n***** OPCIÓN BAJA ***** \n");
		do
		{
			opcion1 = 0;
			printf("ingrese el ID.\n");
			scanf("%d", &idBicicleta);

			//OBTENGO INDEX DEL ARRAY DE TRABAJOS A DAR DE BAJA
			index = buscarBicicletasPorID(listadoBicicleta, TamB, idBicicleta);

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
			printf("\nID \t MARCA\t   RODADO\t COLOR\n");
			mostrarUnaBicicleta(listadoBicicleta[index]);

			printf("\n¿Confirma la baja de bicicleta? \n  Confirmar: 1\n  Cancelar: 2\n");
			scanf("%d", &opcion);

			if(opcion == 1)
			{
				listadoBicicleta[index].isEmpty = BAJA;
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
/*
int ordenaEmpleadosPorApellido(eTrabajo listadoTrabajo[], int TAM, int criterio)
{
	int rtn = 0;
	int i;
	int j;
	eTrabajo aux;
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if(listadoTrabajo != NULL && TAM > 0)
	{
		switch(criterio)
		{
			case 1:
				for(i = 0; i < TAM - 1; i++)
				{
					for (j = i + 1; j < TAM; j++)
					{//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
						if(listadoTrabajo[i].isEmpty == OCUPADO && listadoTrabajo[j].isEmpty == OCUPADO)
						{//CRITERIO DE ORDENAMIENTO
							if(strcmp(listadoTrabajo[i].apellido, listadoTrabajo[j].apellido) == 1)
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
									c[i] = aux;
								}
							}
						}
					}
				}
				rtn = 1;
			break;

			case 2:
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
			break;

			default:
				//CRITERIO DE ORDENAMIENTO MAL INGRESADO
				printf("ERROR al cargar criterio de ordenamiento.\n");
				rtn = 0;
			break;
		}//fin funcion switch
	}
	return rtn;
}*/

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
