#ifndef DEFINICIONES_H
#define DEFINICIONES_H
#include "estructura.h"

arbol CreoArbol();

bool esVacio(arbol a);

void insertar(arbol &a, int valor);

void preOrden(arbol a);
	
void inOrden(arbol a);

void postOrden(arbol a);

int valor(arbol a);

arbol hijoDerecho(arbol a);
	
arbol hijoIzquierdo(arbol a);

arbol buscar(arbol a, int valor);

arbol buscarMinimo(arbol a);

arbol buscarMaximo(arbol a);

bool esHoja(arbol a);

void muestroHoja(arbol a);

void eliminarHoja(arbol &a);

bool esRaiz(arbol a);

void borrarArbol(arbol &a);

void eliminar(arbol &a,int n);
	
#endif
