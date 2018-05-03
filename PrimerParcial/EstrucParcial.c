#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EstrucParcial.h"
#define TAMANIO 10
#define OCUPADO 0
#define LIBRE 1


int eUsu_init( eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;

        //retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].ID_Usuario= 0;
        }
    return retorno;
}

int eUsu_buscarLugarLibre(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;

        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    return retorno;
}

int eUsu_siguienteId(eUsuario listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].ID_Usuario>retorno)
                    {
                         retorno=listado[i].ID_Usuario;
                    }

            }
        }
    }

    return retorno+1;
}


int eUsu_buscarPorId(eUsuario listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].ID_Usuario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



void eUsu_mostrarUno(eUsuario parametro)
{
     printf("Nombre: %s \nID: %d \n",parametro.nombre,parametro.ID_Usuario);

}

void eUsu_mostrarListado(eUsuario listado[],int limite)
{
    //int retorno = -1;
    int i;

        //retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                eUsu_mostrarUno(listado[i]);
            }
        }
    //return retorno;
}


int eUsu_mostrarListadoConBorrados(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==LIBRE)
            {
                printf("\n[LIBRE]");
            }
            eUsu_mostrarUno(listado[i]);
        }
    }
    return retorno;
}

/*int eUsu_alta(eUsuario  listado[],int limite)
{
    int retorno = -1;
    char nombre[50];
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eUsu_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = eUsu_siguienteId(listado,limite);

            //if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            //{
                retorno = 0;
                strcpy(listado[indice].nombre);
                listado[indice].ID_Usuario = id;
                listado[indice].estado = OCUPADO;
            //}
        }
    }
    return retorno;
}*/

/*void eUsu_hardcodeo(eUsuario usuarios[])
{
    int i;
    char nombre[][50]={"Juan","Martin","Pedro"};

    for(i=0;i<3;i++)
    {
        usuarios[i].estado = 1;
        strcpy(usuarios[i].nombre,nombre[i]);
    }
}

int eUsu_modificacion(eUsuario[] ,int limite, int id){




}*/
