/*
 * utn.h
 *
 *  Created on: 15 may. 2021
 *      Author: npipliza
 */

#ifndef TP_LABORATORIO_2_TRABAJO_PRACTICO_2_UTN_H_
#define TP_LABORATORIO_2_TRABAJO_PRACTICO_2_UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);


/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos);

/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int myGets(char* cadena, int longitud);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
int esFlotante(char* cadena, int limite);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
int getFloat(float* pResultado);

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
int esNumerica(char* cadena, int limite);

/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
int getInt(int* pResultado);

/**
 * @fn int esString(char*, int)
 * @brief
 * verifica si la cadena ingresada es string
 * @param cadena cadena de caracteres a ser analizada
 * @param longitud longitud maxima de la cadena
 * @return retorna 1 si la cadena es una cadena de caracteres, 0 si no lo es
 */
int esString(char* cadena, int longitud);

/**
 * @fn int getString(char*, int)
 * @brief
 * obtiene una cadena de caracteres
 * @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param longitud tamaño maximo de la cadena
 * @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
int getString(char* pResultado, int longitud);



/**
 * @fn int utn_getString(char*, int, char[], char[], int)
 * @brief
 * solicita una cadena al usuario, luego de verificarlo devuelve el resultado
 * @param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param longitud longitud maxima de la cadena
 * @param mensaje mensaje a ser mostrado
 * @param mensajeError mensaje a mostrar en caso de error
 * @param reintentos numero de veces que el usuario puede volver a intentar
 * ingresar la cadena en caso de error
 * @return retorna 0 si se obtuvo una cadena y -1 si no
 */
int utn_getString(char* pResultado, int longitud, char mensaje[], char mensajeError[], int reintentos);

/**
 * @fn int getPalabra(char*, int)
 * @brief
 * obtiene una cadena de caracteres sin posibilidad de añadir espacios entre los mismos
 * @param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param longitud tamaño maximo de la cadena
 * @return retorna 0 si se obtiene una cadena de caracteres, -1 si no
 */
int getPalabra(char* pResultado,int longitud);

/**
 * @fn int esPalabra(char*, int)
 * @brief
 * verifica si la cadena ingresada es string sin espacios
 * @param palabra cadena de caracteres a ser analizada
 * @param longitud tamaño maximo de la cadena
 * @return retorna 0 si obtiene una cadena de caracteres, -1 si no
 */
int esPalabra(char* palabra, int longitud);

/**
 * @fn int utn_getPalabra(char*, int, char[], char[], int)
 * @brief
 * solicita una cadena de caracteres al usuario(sin espacios), luego de verificarla devuelve el resultado
 * @param pResultado puntero a la direccion de memoria donde se guardara el resultado de la funcion
 * @param longitud tamaño maximo de la cadena
 * @param mensaje mensaje que se mostrara al usuario
 * @param mensajeError mensaje que se mostrara al usuario en caso de error
 * @param reintentos cantidad de veces que el usuario puede reintentar en caso de error
 * @return retorna 0 si obtiene una cadena de caracteres, -1 si no
 */
int utn_getPalabra(char* pResultado, int longitud, char mensaje[], char mensajeError[], int reintentos);

int PedirEntero(char mensaje[],char mensajeError[]);

int ValidarNumero(char numero[]);


#endif /* TP_LABORATORIO_2_TRABAJO_PRACTICO_2_UTN_H_ */
