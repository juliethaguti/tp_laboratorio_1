#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validacion.h"

EMovie movie_cargaPelicula(EMovie arrayMovie[], int longitudArray)
{
    char bTitulo[20];
    char bGenero[20];
	char bDuracion[5];
    char bDescripcion[500];
	char bPuntaje [5];
    char blinkImagen[100];

    if(arrayMovie != NULL  && 0 < longitudArray)
    {
        if(val_getTitulo(bTitulo,"\nTitulo?","\nError, reingrese:\n",3,20)==0)
        {
            if(val_getNombre(bGenero,"\nGenero?","\nError, reingrese:\n",3,20)==0)
            {
                if(val_getUnsignedInt(bDuracion,"\nDuracion en min?","\nError, reingrese:\n",3,5)==0)
                {
                    if(val_getTitulo(bDescripcion,"\nDescripcion?","\nError, reingrese:\n",2,500)==0)
                    {
                        if(val_getUnsignedInt(bPuntaje,"\nPuntaje?","\nError, reingrese:\n",3,5)==0)
                        {
                            if(val_getLinkImagen(blinkImagen,"\nLink Imagen?","\nError, reingrese:\n",3,100)==0)
                            {
                                strncpy(arrayMovie->titulo,bTitulo,20);
                                strncpy(arrayMovie->genero,bGenero,20);
                                strncpy(arrayMovie->duracion,bDuracion,9);
                                strncpy(arrayMovie->descripcion,bDescripcion,500);
                                strncpy(arrayMovie->puntaje,bPuntaje,5);
                                strncpy(arrayMovie->linkImagen,blinkImagen,100);
                                arrayMovie->flagEstado = MOVIE_OCUPADO;
                            }
                        }
                    }
                }
            }
        }
    }
    return *arrayMovie;
}

int agregarPelicula(EMovie movie)
{
    int retorno = -1;
    int cantidadLeida;
    FILE *pArchivoPelicula;
    pArchivoPelicula = fopen("peliculas","a+b");
    if(pArchivoPelicula == NULL)
    {
        printf("El archivo no se pudo abrir");
    }

    fseek(pArchivoPelicula,0,SEEK_END);
    cantidadLeida = fwrite(&movie,sizeof(EMovie),1,pArchivoPelicula);
    if(cantidadLeida == 1)
    {
        retorno = 0;
    }
    fclose(pArchivoPelicula);
    return retorno;
}

/** \brief Imprime lista de peliculas
 *
 * \param EMovie *movies Puntero al array de peliculas
 * \param longitud Longitud del array de pantallas
 * \return (-)
 *
 */
void movie_printpeliculas(EMovie *movies)
{
    FILE *pArchivo;
    EMovie auxMovie;
    int cantidadLeida;

    if(movies != NULL)
    {
        pArchivo = fopen("peliculas","rb");
        if(pArchivo == NULL)
        {
            printf("No se pudo abrir el archivo!!");
        }
        while(!feof(pArchivo))
        {
            cantidadLeida= fread(&auxMovie,sizeof(EMovie),1,pArchivo);
            if(cantidadLeida == 1)
            {
                printf("\n%s\t%s\t%s\n",auxMovie.titulo,auxMovie.genero,auxMovie.duracion);
            }
        }
    }
    fclose(pArchivo);
}

int borrarPelicula(EMovie movie)
{

    FILE *PArchivo;
    FILE *pAuxArchivo;
    char bTitulo[20];
    int cantidadLeida;

    PArchivo = fopen("peliculas","rb");
    if(PArchivo == NULL)
    {
        printf("El archivo no se pudo abrir");
    }

    pAuxArchivo = fopen("auxPaliculas","wb");
    if(pAuxArchivo == NULL)
    {
        printf("\nEl archivo no se pudo abrir");
    }

    if(val_getTitulo(bTitulo,"\nTitulo de pelicula a dar de baja?","\nError, reingrese",3,20) == 0)
    {
        while(!feof(PArchivo))
        {
            cantidadLeida = fread(&movie,sizeof(EMovie),1,PArchivo);
            if(cantidadLeida == 1)
            {
                if(strcmp(bTitulo,movie.titulo) != 0)
                {
                    fwrite(&movie,sizeof(EMovie),1,pAuxArchivo);
                }
            }
        }
    }
    fclose(PArchivo);
    fclose(pAuxArchivo);
    remove("peliculas");
    rename("auxPaliculas","peliculas");
}

void generarPagina()
{
    FILE *pHTML;
    FILE *pArchivo;
    int cantidadLeida;
    EMovie movie;

    pHTML = fopen("index.html","w+b");
    if(pHTML == NULL)
    {
        printf("No se pudo abrir el archivo");
    }

    pArchivo = fopen("peliculas","rb");
    if(pArchivo == NULL)
    {
        printf("No se pudo abrir el archivo");
    }

    while(!feof(pArchivo))
    {
        cantidadLeida = fread(&movie,sizeof(EMovie),1,pArchivo);
        if(cantidadLeida == 1)
        {
            fprintf(pHTML,"<article class='col-md-4 article-intro'>\n<a href='#'>\
            \n<img class='img-responsive img-rounded' src='%s\
            \nalt=' '>\
            \n</a>\
            \n<h3>\
            \n<a href='#'>%s</a>\
            \n</h3>\
            \n<ul>\
            \n<li>Género:%s</li>\
            \n<li>Puntaje:%s</li>\
            \n<li>Duración:%s</li>\
            \n</ul>\
            \n <p>%s</p>\n</article>",movie.linkImagen,movie.titulo,movie.genero,movie.puntaje,movie.duracion);
        }
    }
    fclose(pArchivo);
    fclose(pHTML);
    return cantidadLeida;
}
