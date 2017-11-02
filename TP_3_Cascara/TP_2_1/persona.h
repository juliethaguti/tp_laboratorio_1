#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct{

    char nombre[51];
    char dni[10];
    int edad;
    int estado;

}sPersona;

#endif // PERSONA_H_INCLUDED

#define TAMANIO 10
#define LUGAR_LIBRE 0
#define LUGAR_OCUPADO 1

int buscarOcurrencia(sPersona arrayPersonas[],int cantidadElementos, int valor);
int inicializarArrayPersonas(sPersona arrayPersonas[],int cantidadElementos,int valor);
int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);
int agregarPersona(sPersona arrayPersonas[], int index,int longitudArray);
int getStringNumber(char mensaje[],char input[] );
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
int ordenarPorNombre (sPersona *arrayPersonas, int longitud);
int borrarPersona (sPersona arrayPersona[], int longitud,int indice);
int buscarDni (sPersona *arrayPersona, int longitud,char auxDni[]);
void graficar(int  cantidadEdadMenor19,int cantidadEdadMayor36,int cantidadEdad19a35);

