#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "validacion.h"

#define MAX_INPUT_BUFFER 4096

static int val_validarNombre(char* buffer);
static int val_validarUnsignedInt(char* buffer);
static int val_validarTitulo(char* buffer);
static int val_validarLinkImagen(char* buffer);

/** \brief Solicita un dato tipo nombre
 *
 * \param destino Donde va a ser guardado el dato
 * \param mensaje Mensaje a mostrar para pedir el dato
 *\param mensajeError Mensaje a motrar por si ingresa un caracter invalido
 *\param intentos Veces en las q puede volver a intentar
 *\param limite Tamaño limite que puede tener la cadena de caracteres
 * \return Retorna (-1) si hay un Error - (0) si Ok
 *
 */
int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarNombre(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

void myFgets(char* buffer, int limite ,FILE* archivo)
{
    int i=0;

    fgets(buffer, limite ,archivo);
    buffer[limite-1] = '\0';

    while(buffer[i] != '\0')
    {
        if(buffer[i] == 10)//10 -> LF
        {
            buffer[i] = '\0';
            break;
        }
        i++;
    }
}

/** \brief Solicita un dato tipo entero sin signo
 *
 * \param destino Donde va a ser guardado el dato
 * \param mensaje Mensaje a mostrar para pedir el dato
 *\param mensajeError Mensaje a motrar por si ingresa un caracter invalido
 *\param intentos Veces en las q puede volver a intentar
 *\param limite Tamaño limite que puede tener la cadena de caracteres
 * \return Retorna (-1) si hay un Error - (0) si Ok
 *
 */
int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarUnsignedInt(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Valida una cadena de caracteres de tipo nombre
 *
 * \param buffer Cadena a validar
 * \param
 * \return Retorna (-1) si hay un Error - (0) si Ok
 *
 */
static int val_validarNombre(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z'))
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief Valida una cadena de caracteres de tipo entero sin signo
 *
 * \param buffer Cadena a validar
 * \param
 * \return Retorna (-1) si hay un Error - (0) si Ok
 *
 */
static int val_validarUnsignedInt(char* buffer)
{
    int i=0;
    int retorno = 0;
    int flagPunto = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] < '0' || buffer[i] > '9' )
        {
            retorno = -1;
            break;
        }
        else
        {
            if(buffer[i] == '-' && i != 0)
            {
                retorno = -1;
                break;
            }
            else if(buffer[i] == '.')
            {
                flagPunto++;
                if(flagPunto > 1)
                {
                    retorno = -1;
                    break;
                }
            }
        }
        i++;
    }
    return retorno;
}

/** \brief Solicita un dato tipo titulo
 *
 * \param destino Donde va a ser guardado el dato
 * \param mensaje Mensaje a mostrar para pedir el dato
 *\param mensajeError Mensaje a motrar por si ingresa un caracter invalido
 *\param intentos Veces en las q puede volver a intentar
 *\param limite Tamaño limite que puede tener la cadena de caracteres
 * \return Retorna (-1) si hay un Error - (0) si Ok
 *
 */
int val_getTitulo(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarTitulo(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Valida una cadena de caracteres de tipo titulo
 *
 * \param buffer Cadena a validar
 * \param
 * \return Retorna (-1) si hay un Error - (0) si Ok
 *
 */
static int val_validarTitulo(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && (buffer[i] != ' '))
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

/** \brief Solicita un dato tipo link
 *
 * \param destino Donde va a ser guardado el dato
 * \param mensaje Mensaje a mostrar para pedir el dato
 *\param mensajeError Mensaje a motrar por si ingresa un caracter invalido
 *\param intentos Veces en las q puede volver a intentar
 *\param limite Tamaño limite que puede tener la cadena de caracteres
 * \return Retorna (-1) si hay un Error - (0) si Ok
 *
 */
int val_getLinkImagen(char* destino, char* mensaje,char* mensajeError,int intentos,int limite)
{
    int retorno = -1;
    char buffer[MAX_INPUT_BUFFER];

    if(destino != NULL && limite > 0 && limite < MAX_INPUT_BUFFER)
    {
        printf(mensaje);
        for( ;intentos>0;intentos--)
        {

            myFgets(buffer, limite ,stdin);

            if(val_validarLinkImagen(buffer) == -1)
            {
                printf(mensajeError);
                continue;
            }
            else
            {
                strncpy(destino,buffer,limite);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Valida una cadena de caracteres de tipo titulo
 *
 * \param buffer Cadena a validar
 * \param
 * \return Retorna (-1) si hay un Error - (0) si Ok
 *
 */
static int val_validarLinkImagen(char* buffer)
{
    int i=0;
    int retorno = 0;
    while(buffer[i] != '\0')
    {
        if((buffer[i] < 'a' || buffer[i] > 'z') && (buffer[i] < 'A' || buffer[i] > 'Z') && (buffer[i] != '.') && (buffer[i] != '/') && (buffer[i] < '0' || buffer[i] > '9' ) && (buffer[i] != ':') && (buffer[i] != '_'))
        {
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}
