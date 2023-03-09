#include<iostream>
using namespace std;
#include "definiciones.h"
#include "estructura.h"


/*                   50
                 4       60
			   3  10       70
             2        

					10
				4		60
			3				70
		2

					10
				3		60
			2				70
*/
int main (int argc, char *argv[]) {
	arbol a;
	a = CreoArbol();
	insertar(a, 50);
	insertar(a, 4);
	insertar(a, 60);
	insertar(a, 3);
	insertar(a, 2);
	insertar(a, 70);
	insertar(a, 10);
	insertar(a,55);
	insertar(a,40);
	preOrden(a);
	cout << endl;
	eliminar(a, 50);
	preOrden(a);
	cout << endl;
	eliminar(a, 10);
	preOrden(a);
	cout << endl;
	
	/*eliminar(a, 60);
	preOrden(a);
	cout << endl;
	eliminar(a, 2);
	preOrden(a);
	cout << endl;
	eliminar(a,4);
	preOrden(a);
	cout << endl;
	eliminar(a, 3);
	preOrden(a);
	cout << endl;
	eliminar(a, 55);
	preOrden(a);
	cout << endl;
	eliminar(a, 70);
	preOrden(a);
	cout << endl;
	eliminar(a, 40);
	preOrden(a);
	cout << endl;
	*/
	cout << "Recorrida en PreOrden: ";
	preOrden(a);
	cout << endl;
	cout << "Recorrida en InOrden: ";
	inOrden(a);
	cout << endl;
	cout << "Recorrida en postOrden: ";
	postOrden(a);
	cout << endl;
	if (buscar(a,5)){
		cout << valor(buscar(a,5))<<endl;
	}else{
		cout << "No se encuentra dicho valor"<<endl;
	}
	cout << valor(a)<<endl;
	cout << valor(buscarMinimo(a))<<endl;
	cout << valor(buscarMaximo(a))<<endl;
	cout << "Valor del hijo izquierdo  "<<hijoIzquierdo(buscar(a,3))<<endl;
	cout << "el mayor del sub arbol izquierdo "<<valor(buscarMaximo(a->izq))<<endl;
	//asumo que el nodo esta
	cout << "El nodo cuyo valor es 3, ¿es hoja?: ";
	if (esHoja(buscar(a,3))){
		cout << "Es hoja "<<endl;
	}else{
		cout << "No es hoja"<<endl;
	}
	cout << "Las hojas del arbol son: ";
	muestroHoja(a);
	cout << endl;
	
	arbol aux;
	aux = buscar(a,2);
	eliminarHoja(aux);
	preOrden(a);
	cout << endl;
	
	if(esVacio(aux)){
		cout << "ARBOL VACIO";
		a=NULL;
	}else
		preOrden(a);
	cout << endl;
	
	insertar(a,20);
	preOrden(a);
	cout << endl;
	
	return 0;
}

