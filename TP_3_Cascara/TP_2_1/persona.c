#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "persona.h"

static int getStringLetras(char mensaje[],char input[]);
static int esSoloLetras(char str[]);
static void getString(char mensaje[],char input[]);
static int esNumerico(char str[]);

int buscarOcurrencia(sPersona arrayPersonas[],int cantidadElementos, int valor)
{
    int retorno = -1;
    int i;
    if(arrayPersonas != NULL && cantidadElementos > 0)
    {
        for(i=0;i<cantidadElementos;i++)
        {
            if(arrayPersonas[i].estado == valor)
            {
                retorno = i;
            }
        }
    }
    return retorno;
}

 int inicializarArrayPersonas(sPersona arrayPersonas[],int cantidadElementos,int valor)
{
         int i;
         int retorno = -1;
         if(arrayPersonas != NULL && cantidadElementos > 0)
         {
             for(i=0;i<cantidadElementos;i++)
            {
                arrayPersonas[i].estado=valor;
            }
            retorno = 0;
        }
        return retorno;
}

static int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

static int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

static void getString(char mensaje[],char input[])
{
    printf(mensaje);
    scanf("%s",input);
}

int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps)
{
    int i;
    int retorno=-1;
    char buffer[1024];

    for(i=0;i<attemps;i++)
    {
        if (!getStringLetras(requestMessage,buffer))
        {
            printf ("%s",errorMessage);
            continue;
        }
        if(strlen(buffer) >= maxLenght)
        {
            printf ("%s",errorMessageLenght);
            continue;

        }
        retorno=0;
        strcpy(input,buffer);
        break;
    }
    return retorno;
}

int agregarPersona(sPersona arrayPersonas[], int index,int longitudArray)
{
    int retorno = -1;
    char bNombre [51];
    char bDni [10];
    char bEdad[5];


    if(arrayPersonas != NULL && index >= 0 && index<longitudArray)
    {
        if(getValidString("\n\tNombre?","Ingrese solo letras","Excedio la cantidad permitida de caracteres",bNombre,100,2)== 0)
        {
            //printf(bNombre);

                if(getStringNumber("\n\tIngrese dni: ",bDni) == 0)
                {

                    if (buscarOcurrencia(arrayPersonas,TAMANIO,bDni) != -1)
                    {
                        printf("\nLa persona ya está en el sistema\n");
                    }
                    //printf("Dni Ok");
                    if(getStringNumber("\n\tIngrese edad: ",bEdad) == 0)
                    {

                        strncpy(arrayPersonas[index].nombre,bNombre,51);
                        strncpy(arrayPersonas[index].dni,bDni,10);
                        arrayPersonas[index].edad = atoi(bEdad);
                        arrayPersonas[index].estado = LUGAR_OCUPADO;
                        retorno = 0;
                    }
                }
            }

        }
    return retorno;
}

int getStringNumber(char mensaje[],char input[] )
 {
     int retorno = -1;

     char aux[256];
     getString(mensaje,aux);
     if(esNumerico(aux))
     {
         strcpy(input,aux);
         retorno = 0;
     }
     return retorno;
 }

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
 {
     char auxStr[256];
     int auxInt;
     while(1)
     {
         if(!(getStringNumber(requestMessage,auxStr)))
         {
             printf("%s\n",errorMessage);
             continue;
         }
         auxInt=atoi(auxStr);
         if(auxInt<lowLimit || auxInt>hiLimit)
         {
             printf("El numero debe der mayor a %d y menor a %d\n",lowLimit,hiLimit);
             continue;
         }
         return auxInt;
     }
 }

static int esNumerico(char str[])
  {
      int i=0;
      while(str[i] !='\0')
      {
          if(str[i]<'0' || str[i]>'9')
            return 0;
          i++;
      }
      return 1;
  }

int ordenarPorNombre (sPersona *arrayPersonas, int longitud)
{
    sPersona auxPersona;

    int i,j;
    int retorno = -1;

    if(arrayPersonas != NULL && longitud > 0)
    {
        for(i=0;i<longitud-1;i++)
                {
                    if(arrayPersonas[i].estado == LUGAR_LIBRE)
                    {
                        continue;
                    }
                    for(j=i+1;j<longitud;j++)
                    {
                        if(arrayPersonas[j].estado == LUGAR_LIBRE)
                        {
                            continue;
                        }
                        if(strcmp(arrayPersonas[i].nombre,arrayPersonas[j].nombre)>0)
                        {
                            auxPersona=arrayPersonas[i];
                            arrayPersonas[i]=arrayPersonas[j];
                            arrayPersonas[j]=auxPersona;
                            retorno = 0;
                        }
                    }
                }
                printf("\n\n\tNombre\t\t\tEdad\tDni");
                for(i=0;i<longitud;i++)
                {
                    if(arrayPersonas[i].estado == LUGAR_OCUPADO)
                    {
                        printf("\n\n\t%s\t\t\t%d\t%s\n",arrayPersonas[i].nombre,arrayPersonas[i].edad,arrayPersonas[i].dni);
                    }
                }
    }
  return retorno;
}

int borrarPersona (sPersona arrayPersona[], int longitud,int indice)
{
    int retorno = -1;
    int i;

    if(arrayPersona != NULL && longitud > 0)
    {
        arrayPersona[indice].estado = LUGAR_LIBRE;
        retorno = 0;
    }

    return retorno;
}

int buscarDni (sPersona *arrayPersona, int longitud,char auxDni[])
{
    int i;
    int retorno = -1;

    if(arrayPersona != NULL && 0 < longitud)
    {
        for(i=0;i<longitud;i++)
        {
            if(strcmp(arrayPersona[i].dni,auxDni) == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void graficar(int  cantidadEdadMenor19,int cantidadEdadMayor36,int cantidadEdad19a35)
{
    int mayor,i;

    if(cantidadEdadMenor19>cantidadEdad19a35)
    {
        mayor=cantidadEdadMenor19;
        if(cantidadEdadMenor19>cantidadEdadMayor36)
        {
            mayor=cantidadEdadMenor19;
        }
        else
        {
            mayor=cantidadEdadMayor36;
        }
    }
    else
    {
        mayor=cantidadEdad19a35;
        if(cantidadEdad19a35<cantidadEdadMayor36)
        {
            mayor=cantidadEdadMayor36;
        }
    }

     char matrizGrafica[mayor][3];
     for(i=0;i<mayor;i++)
     {
         if(matrizGrafica[i]==mayor)
         {
             printf("*");
         }
         else
         {
             printf(" ");
         }
     }

}
