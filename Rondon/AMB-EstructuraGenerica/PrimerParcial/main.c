#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 10
#include "EstrucParcial.h"
#include "EstrucProduc.h"


int main()
{
    eUsuario listadoUsuarios[CANTIDAD];
    eUsu_init(listadoUsuarios,CANTIDAD);

    eProducto listadoProductos[CANTIDAD];
    eProd_init(listadoProductos,CANTIDAD);

    // int isalpha(char)        printf(Ingrese edad);
    // int isdigit(char)        gets(auxString);
    // int issPace(char)        x=validaStringEntero(auxString);
    //                          if(x==1)
    //                          {   edad = atoi(auxString);}
    //                          else{ printf("error");}
    int id;
    int opcion;
    char resp='s';

    do{
        system("cls");
        printf("1-Alta\n2-Modificar\n3-Baja\n4-Publicar Producto\n5-Listado\n6-Salir");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                {
                    eUsu_alta(listadoUsuarios,CANTIDAD);
                    getch();
                break;
                }
            case 2:
                {
                    eUsu_mostrarListado(listadoUsuarios, CANTIDAD);
                    printf("\n Ingrese el usuario a modificar segun el ID: ");
                    scanf("%d",&id);
                    eUsu_modificacion(listadoUsuarios,CANTIDAD,id);
                    getch();
                    break;
                }
            case 3:
                {
                    eUsu_mostrarListado(listadoUsuarios, CANTIDAD);
                    printf("Ingrese el ID del usuario a dar de baja: ");
                    scanf("%d",&id);
                    eUsu_baja(listadoUsuarios, CANTIDAD,id);
                    getch();
                    break;
                }
            case 4:
                {
                    eProd_alta(listadoProductos,CANTIDAD);
                }
            case 5:
                {
                    eUsu_mostrarListado(listadoUsuarios,CANTIDAD);
                    getch();
                }
            case 6:
                {
                    resp='n';
                    break;
                }

            }

    }while(resp=='s');

    return 0;
}
