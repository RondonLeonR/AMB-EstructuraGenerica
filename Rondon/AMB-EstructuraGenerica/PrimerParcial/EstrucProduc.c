#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EstrucProduc.h"
#define TAMANIO 10
#define OCUPADO 0
#define LIBRE 1

void eProd_init( eProducto listado[],int limite)
{
    int i;

        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].ID_Produc= 0;
        }
}

int eProd_buscarLugarLibre(eProducto listado[],int limite)
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

int eProd_siguienteId(eProducto listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].ID_Produc>retorno)
                    {
                         retorno=listado[i].ID_Produc;
                    }
            }
        }
    }

    return retorno+1;
}


int eProd_buscarPorId(eProducto listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].ID_Produc == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


void eProd_mostrarUno(eProducto parametro)
{
     printf("ID: %d -- Nombre: %s -- Precio: %f -- Stock: %d\n",parametro.ID_Produc,parametro.Nombre,parametro.Precio,parametro.Stock);

}

void eProd_mostrarListado(eProducto listado[],int limite)
{
    int i;

        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                eProd_mostrarUno(listado[i]);
            }
        }
}

int eProd_mostrarListadoConBorrados(eProducto listado[],int limite)
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
            eProd_mostrarUno(listado[i]);
        }
    }
    return retorno;
}

void eProd_alta(eProducto  listado[],int limite)
{

    int id;
    int indice;

    printf("Ingrese el ID de usuario: ");
    scanf("%d",&id);

    indice = eProd_buscarLugarLibre(listado,limite);

    printf("Ingrese nombre del Producto: ");
    scanf("%s",&listado[indice].Nombre);

    printf("Ingrese precio del producto: ");
    scanf("%f",&listado[indice].Precio);

    printf("Stock disponible: ");
    scanf("%d",&listado[indice].Stock);

    //listado.ID_Produc=listado.ID_Usuario;

        if(indice >= 0)
        {
            id = eProd_siguienteId(listado,limite);
            //if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            //{
                listado[indice].ID_Produc = id;
                listado[indice].estado = OCUPADO;
                printf("\nEl Producto %s ha sido ingresado.",listado[indice].Nombre);
            //}
        }
}

/*void eProd_modificacion(eProducto listado[] ,int limite,int id)
{
    int i;
    char nomb[50];
    int pass[50];


    for(i=0 ; i<limite ;i++)
    {

        if(listado[i].ID_Usuario==id)
        {
            printf("Usuario a modificar: %s \n", listado[i].nombre);
            printf("Ingrese Nuevo Nombre: ");
            scanf("%s",&nomb);
            printf("Ingrese Nueva Password: ");
            scanf("%s",&pass);
            strcpy(listado[i].nombre,nomb);
            strcpy(listado[i].password,pass);
            break;
        }
    }


}

void eProd_baja(eProducto listado[] ,int limite, int id)
{
    int i;

    for(i=0;i<limite;i++)
    {
        if(listado[i].ID_Usuario==id)
        {
            printf("Usuario a dar de baja: %s %s",listado[i].nombre, listado[i].password);
            strcpy(listado[i].nombre,"Ha sido borrado");
            strcpy(listado[i].password,"");
        }
    }
}*/

