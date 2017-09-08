#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesTP.h"

/** \brief Pide un numero.
 * \param Es el mensaje que pide el numero
 * \param
 * \return Retorna el número
 *
 */
int pedirNumero(char mensaje[], char mensajeError[],float* primerNumero)
{

    char auxiliar[256];
    float aux;

    pedirDato(mensaje,auxiliar);

    if(verificaSiEsNumero(auxiliar) == 1)
    {
        aux=atof(auxiliar);
        *primerNumero=aux;

        //strncpy(arrayNumeros,auxiliar,255);
        return 1;
    }
    else
    {
        printf(mensajeError);
    }
    return 0;
}

    /** \brief suma dos números
     *
     * \param primer operando
     * \param segundo operando
     * \return retorna la suma de los parametros
     *
     */
float sumar(float x,float y)
 {
     float resultado;
    resultado=x+y;
    return resultado;
}

/** \brief Resta dos numeros
 *
 * \param primer operando
 * \param segundo operando
 * \return retorna la resta de los parametros
 *
 */
float restar(float x,float y)
 {
    float resultado;
    resultado=x-y;
    return resultado;
}

/** \brief multiplica dos numeros
 *
 * \param primer numero
 * \param segundo numero
 * \return retorna la multiplicación de los numeros
 *
 */

float multiplicar(float x,float y)
 {
    float resultado;
    resultado=x*y;
    return resultado;
}

/** \brief divide dos numeros
 *
 * \param primer numero
 * \param segundo numero
 * \return la división de dos numeros
 *
 */
float dividir(float x,float y)
 {
    float resultado;
    if(y!=0){
    resultado=x/y;
    return resultado;
}
    else{
        return 0.0;
    }
 }

 /** \brief Da el resultado de la factorial de un numero
  *
  * \param El numero a operar
  * \param
  * \return El factorial
  *
  */
int factorial(int x){
    int rta;

        if(x==1){
            rta=1;
        }
        else{
            rta=x*factorial(x-1);
        }
        return rta;
}

/** \brief Valida un caracter numérico
 * \param array, es el array a verificar si es numerico
 * \param
 * \return 0 si no es numérico ó 1 si lo es
 *
 */
int verificaSiEsNumero (char arrayNumeros[])
{
    int i=0;
    while(arrayNumeros[i]!='\0')
    {
        if(arrayNumeros[i]>'0' && arrayNumeros[i]<'9' && arrayNumeros[i]=='.')
        {
            return 0;
        }
        i++;
    }
    return 1;
}
/** \brief
 * \param
 * \param
 * \return
 *
 */
void pedirDato(char mensaje[],char arrayString[])
 {
     printf(mensaje);
     scanf("%s",arrayString);
 }



