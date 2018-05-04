#ifndef ESTRUCPARCIAL_H_INCLUDED
#define ESTRUCPARCIAL_H_INCLUDED
typedef struct{

int ID_Usuario;
char nombre[50];
char password[50];
int estado;

}eUsuario;

int eUsu_init(eUsuario[],int limite);
int eUsu_buscarPorId(eUsuario[] ,int limite, int id);
int eUsu_siguienteId(eUsuario[] ,int limite);
int eUsu_buscarLugarLibre(eUsuario listado[],int limite);

void eUsu_mostrarUno(eUsuario parametro);
void eUsu_mostrarListado(eUsuario[] ,int limite);
int eUsu_mostrarListadoConBorrados(eUsuario[] ,int limite);

void eUsu_alta(eUsuario[] ,int limite);
void eUsu_baja(eUsuario[] ,int limite, int id);
void eUsu_modificacion(eUsuario[] ,int limite, int id);


#endif // ESTRUCPARCIAL_H_INCLUDED
