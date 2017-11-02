#include <stdio.h>
#include <stdlib.h>

#include "persona.h"

int main()
{
     sPersona arrayPersonas[TAMANIO] ;

    char auxDni[10];

    int indiceLibre,i;
    int indiceResultadoBusqueda;
    int personasMenor19=0;
    int personasMayor36 = 0;
    int personasEdad19_35 = 0;

    char seguir='s';
    int opcion=0;

    inicializarArrayPersonas(arrayPersonas,TAMANIO,LUGAR_LIBRE);

    while(seguir=='s')
    {
        //system("cls");

        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        printf("\nIngrese una opcion: ");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                indiceLibre=buscarOcurrencia(arrayPersonas,TAMANIO,LUGAR_LIBRE);
                if(indiceLibre==-1)
                {
                    printf("\nNo quedan lugares libres!!\n");
                    break;
                }
                    agregarPersona(arrayPersonas,indiceLibre,TAMANIO);

                break;
            case 2:
                if(getStringNumber("\nIngrese dni a borrar: ",auxDni) != -1)
                {
                    indiceResultadoBusqueda = buscarDni(arrayPersonas,TAMANIO,auxDni);
                    if(indiceResultadoBusqueda != -1)
                    {
                        if(borrarPersona(arrayPersonas,TAMANIO,indiceResultadoBusqueda) != -1)
                        {
                            printf("Dni borrado");
                        }
                    }

                }

                break;

            case 3:
                ordenarPorNombre(arrayPersonas,TAMANIO);
                break;
            case 4:
                for(i = 0;i <= TAMANIO;i++)
                {
                    if(arrayPersonas[i].estado==LUGAR_OCUPADO)
                    {

                        if(arrayPersonas[i].edad<19)
                        {
                            personasMenor19++;
                            //printf("%d\n",&totalCantidadEdadMenor19);
                        }
                        else if(arrayPersonas[i].edad>35)
                        {
                            personasMayor36++;
                        }
                        else
                        {
                            personasEdad19_35++;
                        }
                    }
                }
                graficar(personasMenor19,personasMayor36,personasEdad19_35);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
