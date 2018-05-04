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
     printf("ID: %d ---- Nombre: %s \n",parametro.ID_Usuario,parametro.nombre);

}

void eUsu_mostrarListado(eUsuario listado[],int limite)
{
    int i;

        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                eUsu_mostrarUno(listado[i]);
            }
        }
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

void eUsu_alta(eUsuario  listado[],int limite)
{

    int id;
    int indice;

    indice = eUsu_buscarLugarLibre(listado,limite);

    printf("Ingrese nombre: ");
    scanf("%s",&listado[indice].nombre);

    printf("Ingrese password: ");
    scanf("%s",&listado[indice].password);

        if(indice >= 0)
        {

            id = eUsu_siguienteId(listado,limite);

            //if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            //{
                listado[indice].ID_Usuario = id;
                listado[indice].estado = OCUPADO;
                printf("\nUsuario %s ingresado.",listado[indice].nombre);
            //}
        }

}

void eUsu_modificacion(eUsuario listado[] ,int limite,int id)
{
    int i;
    char nomb[50];
    int pass[50];
    int idEncontrado;

    idEncontrado = eUsu_buscarPorId(listado,limite,id);


            printf("Usuario a modificar: %s \n", listado[idEncontrado].nombre);
            printf("Ingrese Nuevo Nombre: ");
            scanf("%s",&nomb);
            printf("Ingrese Nueva Password: ");
            scanf("%s",&pass);
            strcpy(listado[idEncontrado].nombre,nomb);
            strcpy(listado[idEncontrado].password,pass);


}

void eUsu_baja(eUsuario listado[] ,int limite, int id)
{
    int i;
    int idEncontrado;
    idEncontrado = eUsu_buscarPorId(listado,limite,id);

            printf("Usuario a dar de baja: %s %s",listado[idEncontrado].nombre, listado[idEncontrado].password);
            strcpy(listado[idEncontrado].nombre,"Ha sido borrado");
            strcpy(listado[idEncontrado].password,"");
}
