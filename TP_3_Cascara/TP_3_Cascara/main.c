#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validacion.h"



int main()
{
    EMovie movies[CANTIDAD_MOVIES];
    FILE *pArchivoMovies;
    EMovie movie;
    char seguir='s';
    char bOpcion[3];

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        val_getUnsignedInt(bOpcion,"\nIngrese una opcion: ","\nError, reingrese",2,3);

        switch(atoi(bOpcion))
        {
            case 1:
                movie = movie_cargaPelicula(movies,CANTIDAD_MOVIES);
                agregarPelicula(movie);
                break;
            case 2:
                movie_printpeliculas(movies);
                borrarPelicula(movie);
                break;
            case 3:
                generarPagina();
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
