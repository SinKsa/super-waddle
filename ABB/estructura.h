#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H


typedef struct _nodo {
	_nodo *padre;
	_nodo *izq;
	_nodo *der;
	int valor;
} *arbol;

#endif
