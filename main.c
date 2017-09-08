#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "funcionesTP.h"

int main()
{
 char seguir='s';
    int opcion=0;
    float A=0;
    float B=0;
    float suma;
    float resta;
    float multiplicacion;
    float division;
    int factoria;
    int enteroA;
    int aux;
    int flag=0;


    while(seguir=='s')
    {
        system("cls");

        printf("\t***************************************\n");
        printf("\t\t---> MENU CALCULADORA <---\n");
        printf("\t***************************************\n");

        printf("\n\t1- Ingresar 1er operando (A=%.2f)\n",A);
        printf("\t2- Ingresar 2do operando (B=%.2f)\n",B);
        printf("\t3- Calcular la suma (A+B)\n");
        printf("\t4- Calcular la resta (A-B)\n");
        printf("\t5- Calcular la division (A/B)\n");
        printf("\t6- Calcular la multiplicacion (A*B)\n");
        printf("\t7- Calcular el factorial (A!)\n");
        printf("\t8- Calcular todas las operaciones\n");
        printf("\t9- Salir\n");
        if(flag==0)
        {
            printf("\n\tPara empezar digite 1\n\n");
        flag=1;
        }

        scanf("%d",&opcion);
        fflush(stdin);

            switch(opcion)
            {
                case 1:
                    aux=(pedirNumero("\nIngrese el primer numero\n ","\n\nSolo ingrese numeros\n",&A));

                    break;
                case 2:
                    if(aux!='0')
                    {
                        pedirNumero("\nIngrese el segundo numero \n","\n\nSolo ingrese numeros!!\n",&B);
                    }
                    break;
                case 3:
                    suma=sumar(A,B);
                    printf("\nLa suma es: %f \n\n",suma);
                    break;
                case 4:
                    resta=restar(A,B);
                    printf("\nLa resta es: %f \n\n",resta);
                    break;
                case 5:
                    division=dividir(A,B);
                    if(B!=0){
                        printf("\nLa division es: %f \n\n",division);
                    }
                    else{
                        printf("\nNo se puede dividir entre cero\n\n");
                    }
                    break;
                case 6:
                    multiplicacion=multiplicar(A,B);
                    printf("\nLa multiplicacion es: %f \n\n",multiplicacion);
                    break;
                case 7:
                    enteroA=(int) A;

                    if (enteroA>0 && enteroA<13){

                        factoria=factorial(enteroA);
                        printf("\nLa factorial del primer numero entero es: %d \n\n",factoria);
                    }
                    else{
                        printf("\nNo se puede sacar factorial de numero menor o igual a 0\n o mayor a 13");
                    }
                    break;
                case 8: suma=sumar(A,B);
                    printf("\nLa suma es: %f \n",suma);
                    resta=restar(A,B);
                    printf("La resta es: %f \n",resta);
                    division=dividir(A,B);
                    printf("La division es: %f \n",division);
                    multiplicacion=multiplicar(A,B);
                    printf("La multiplicacion es: %f \n",multiplicacion);

                    break;
                case 9:
                    seguir = 'n';
                    break;

        }
        Sleep(1000);
    }
    seguir='s';
    return 0;
}
