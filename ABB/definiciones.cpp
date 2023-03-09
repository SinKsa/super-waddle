#include<iostream>
#include "definiciones.h"
#include "estructura.h"
using namespace std;

bool esVacio(arbol a){
	if(a == NULL){
		return true;
	}
	return false;
}

arbol CreoArbol() {
	return NULL;
}

void insertar(arbol &a, int valor) {
	if(esVacio(a)) {
		a = new _nodo;
		a->valor = valor;
		a->izq = NULL;
		a->der = NULL;
		a->padre = NULL;
		
	} else {
		if(valor > a->valor) {
			insertar(a->der, valor); 
			a->der->padre=a;
			
			
		} else {
			if(valor < a->valor) {
				insertar(a->izq, valor);
				a->izq->padre=a;
			}
		}
	}
}

void preOrden(arbol a){
	if(!esVacio(a)){
		cout << a->valor << " - ";
		preOrden(a->izq);
		preOrden(a->der);

	}
}

void inOrden(arbol a){
	if(!esVacio(a)){
		inOrden(a->izq);
		cout << a->valor << " - ";
		inOrden(a->der);
		
	}
}
	
void postOrden(arbol a){
	if(!esVacio(a)){
		postOrden(a->izq);
		postOrden(a->der);
		cout << a->valor << " - ";
		
	}
}
	
int valor(arbol a){
	return a->valor;
}
	
arbol hijoDerecho(arbol a){
	return a->der;
}
	
arbol hijoIzquierdo(arbol a){
	return a->izq;
}
	
arbol buscar(arbol a,int valor){
	if (!esVacio(a)){
			if(a->valor==valor)
				return a;
			else
				if(a->valor > valor)
					return buscar(a->izq,valor);
				else
					return buscar(a->der,valor);
		}else{
			return NULL;
		}
}

arbol buscarMinimo(arbol a){ //precondicion arbol existe
	if (esVacio(hijoIzquierdo(a))){
		return a;
	}else{
		return buscarMinimo(hijoIzquierdo(a));
	}
}

arbol buscarMaximo(arbol a){ //precondicion arbol existe
	if (esVacio(a->der)){
		return a;
	}else{
		return buscarMaximo(a->der);
	}
}
		
bool esHoja(arbol a){ //precondicion arbol existe
	if(esVacio(a->izq) && esVacio(a->der)){
		return true;
	}else{
		return false;
	}
}
	
void muestroHoja(arbol a){
	if(!esVacio(hijoDerecho(a)))
		muestroHoja(hijoDerecho(a));
	if(!esVacio(hijoIzquierdo(a)))
			muestroHoja(hijoIzquierdo(a));
		if(esVacio(hijoIzquierdo(a)) && esVacio(hijoDerecho(a)))
			cout << valor(a) << " ";
	cout << endl;
}

void eliminar(arbol &a,int n){
//asumo que el arbol no esta vacio
	arbol lugar, mayor;
	lugar = buscar(a,n);
	if(esVacio(lugar)){
		cout << "No existe nodo a borrar con ese valor"<<endl;
	}else{ //existe nodo
		if(esHoja(lugar)){
			if(esRaiz(lugar)){ //si es hoja y a la vez raiz
				delete lugar;
				a = NULL; //importante
			}else{
				eliminarHoja(lugar);
			}
		}else{ // entro a borrar un nodo que no es una hoja
			if (!esVacio(hijoDerecho(lugar)) && !esVacio(hijoIzquierdo(lugar))){//! caso tiene 2 hijos
				mayor = buscarMaximo(hijoIzquierdo(lugar));
				lugar->valor = mayor->valor;
				if(esHoja(mayor)){
					eliminarHoja(mayor);
				}else{
					//tiene un hijo izq.
					mayor->padre->izq = hijoIzquierdo(mayor);
					mayor->izq->padre = mayor->padre;
					delete mayor;
					//mayor = NULL;
				}
			}else{//! caso nodo solo tiene un hijo derecho.
				if (!esVacio(lugar->der)){
					if (esRaiz(lugar)){
						lugar->valor = lugar->der->valor;
						delete lugar->der;
						lugar->der = NULL;
					}else{
						lugar->padre->der = lugar->der;
						lugar->der->padre = lugar->padre;
						delete lugar;
					}
				}else{
					//nodo solo tiene un hijo izquierdo.
					if (esRaiz(lugar)){
						lugar->valor = lugar->izq->valor;
						delete lugar->izq;
						lugar->izq = NULL;
					}else{
						lugar->padre->izq = lugar->izq;
						lugar->izq->padre = lugar->padre;
						delete lugar;
					}
				}
			}
		}
	}
	
}
	
void eliminarHoja(arbol &a){
//asumo que existe el nodo y es una hoja.
	if(hijoIzquierdo(a->padre) == a)
		a->padre->izq=NULL;
	else
		a->padre->der=NULL;
	delete a;
}
	
bool esRaiz(arbol a){
	if (esVacio(a->padre)){
		return true;
	}else{
		return false;
	}
}

	/*
void borrarArbol(arbol &a){
	if (!esVacio(a)){
		borrarArbol(a->izq);
		borrarArbol(a->der);
		delete a;
	}else{
		a=NULL;
	}
}*/
