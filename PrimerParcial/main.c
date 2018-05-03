#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 10
#include "EstrucParcial.h"


int main()
{
    eUsuario listadoUsuarios[CANTIDAD];
    //eProduc listadoProductos[CANTIDAD];


    int opcion;
    char resp='s';

    do{
        printf("1-Alta:\n2-Modificar:\n3-Baja:\n4-Salir");
        scanf("%d",&opcion);
        switch(opcion){
            case(1):
                {


                break;
                }
            case(2):
                {

                    break;
                }
            case(3):
                {

                    break;
                }
            case(4):
                {
                    resp='n';
                    break;
                }

                }

    }while(resp=='s');
    //eUsu_init(listadoUsuarios,CANTIDAD);
    //
    eUsu_hardcodeo(listadoUsuarios);


    //eUsu_alta(listadoUsuarios,CANTIDAD);


    eUsu_mostrarListado(listadoUsuarios, CANTIDAD);
    getch();

    //Modificar:





    return 0;
}
