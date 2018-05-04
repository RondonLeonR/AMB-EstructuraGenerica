#ifndef ESTRUCPRODUC_H_INCLUDED
#define ESTRUCPRODUC_H_INCLUDED
#include "EstrucParcial.h"
typedef struct{
int ID_Produc;
int ID_Usuario;
int estado;
char Nombre[50];
float Precio;
int Stock;
int Cantidad;

}eProducto;

void eProd_init(eProducto[],int limite);
int eProd_buscarPorId(eProducto[] ,int limite, int id);
int eProd_siguienteId(eProducto[] ,int limite);
int eProd_buscarLugarLibre(eProducto listado[],int limite);

void eProd_mostrarUno(eProducto parametro);
void eProd_mostrarListado(eProducto[] ,int limite);
int eProd_mostrarListadoConBorrados(eProducto[] ,int limite);

void eProd_alta(eProducto[] ,int limite);
void eProd_baja(eProducto[] ,int limite, int id);
void eProd_modificacion(eProducto[] ,int limite, int id);

#endif // ESTRUCPRODUC_H_INCLUDED
