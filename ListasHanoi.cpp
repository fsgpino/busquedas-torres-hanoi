#include "ListasHanoi.hpp"

using namespace std;
using namespace Hanoi;

namespace Hanoi{

	//
	// FUNCIONES DENTRO DE LA CLASE LISTASTORRESHANOI
	//

	//Constructor del elemento ListaTorresHanoi
	ListaTorreshanoi::ListaTorreshanoi()
	{
		_n=0;
		_cabeza = NULL;
		_cola = NULL;
		_cursor = NULL;
	}


	//Destructor del elemento TorresHanoi
	ListaTorreshanoi::~ListaTorreshanoi()
	{
		liberarMemoria();
	}


	//Funciones de lectura/Acceso
	bool ListaTorreshanoi::vacia() //Devuelve True o False dependiendo si la lista está vacia o no
	{
		if (longitud()==0)
			return true;
		else
			return false;
	}

	int ListaTorreshanoi::longitud() { return _n; } //Devuelve el tamaño de la lista

	TorresHanoi &ListaTorreshanoi::obtenerMomento() { return _cursor->Momento; } //Devuelve el elemento TorresHanoi que se encuentre en el cursor

	int ListaTorreshanoi::obtenerProfundidad() { return _cursor->profundidad; } //Devuelve la profundidad necesaria desde el orgigen hasta el nodo actual

	NodoLista * ListaTorreshanoi::obtenerPadre() { return _cursor->padre; } //Devuelve el puntero al nodo padre del nodo actual

	NodoLista * ListaTorreshanoi::obtenerCursor() { return _cursor; } //Devuelve el puntero del nodo actual

	//Funciones de Modificación
	void ListaTorreshanoi::liberarMemoria() // FUNCIÓN LIBERARMEMORIA (Funciones de Modificacion): LIMPIA LA LISTA
	{
		if (not vacia())
	    {
			while (_cabeza != NULL) // VA AVANZANLO LA CABEZA HACIA DELANTE, ELIMINANDO DEL PRINCIPIO AL FINAL DE LA COLA
			{
				_cursor = _cabeza;
				_cabeza = _cabeza->siguiente;
				delete _cursor;
			}

	        _n = 0;
			_cola = _cursor = NULL;
		}
	}

	void ListaTorreshanoi::guardarMomento(TorresHanoi &MomentoAGuardar, int profundidadAGuardar, NodoLista * padreAGuardar) //FUNCIÓN GUARDARMOMENTO (Funciones de Modificacion): CAMBIA EL VALOR DEL MOMENTO EN DONDE ESTÉ EL CURSOR
	{
			_cursor->Momento=MomentoAGuardar;
			_cursor->profundidad=profundidadAGuardar;
			_cursor->padre=padreAGuardar;
	}

	bool ListaTorreshanoi::insertarAlPrincipio(TorresHanoi &MomentoAGuardar, int profundidadAGuardar, NodoLista * padreAGuardar) //FUNCIÓN INSERTARALPRINCIPIO (Funciones de Modificación): INSERTA EN UN NUEVO NODO EL VALOR DE MOMENTO Y LO COLOCA AL PRINCIPIO DE LA LISTA
	{
		NodoLista *nuevo;

		nuevo = new NodoLista;

		if (nuevo == NULL) // Si no a podido reservarse la memoria se devuelve false
		{
	 		return false;
		}else{
			nuevo->Momento=MomentoAGuardar;
			nuevo->profundidad=profundidadAGuardar;
			nuevo->padre=padreAGuardar;

			if(vacia())
			{
				nuevo->siguiente=NULL;
				_cabeza=nuevo;
				_cursor=nuevo;
				_cola=nuevo;
				_n++;
			}else{
				 nuevo->siguiente=_cabeza;
				 _cabeza=nuevo;
				 _cursor=nuevo;
				 _n++;
			}
			return true;
		}
	}

	bool ListaTorreshanoi::insertarAlFinal(TorresHanoi &MomentoAGuardar, int profundidadAGuardar, NodoLista * padreAGuardar) //FUNCIÓN INTERTARALFINAL (Funciones de Modificacion): INSERTA EN UN NUEVO NODO EL VALOR DE MOMENTO Y LO COLOCA AL FINAL DE LA LISTA
	{
		NodoLista *nuevo;

		nuevo = new NodoLista;

		if (nuevo == NULL) // Si no a podido reservarse la memoria se devuelve false
		{
	 		return false;
		}else{
			nuevo->Momento=MomentoAGuardar;
			nuevo->profundidad=profundidadAGuardar;
			nuevo->padre=padreAGuardar;
			nuevo->siguiente=NULL;
			if(vacia())
			{
				_cabeza=nuevo;
				_cursor=nuevo;
				_cola=nuevo;
				_n++;
			}else{
				_cola->siguiente = nuevo;
				_cola=_cola->siguiente;
				_n++;
			}
			return true;
		}
	}

	bool ListaTorreshanoi::insertarNodoAlPrincipio(NodoLista *nuevo) //FUNCIÓN INSERTARALPRINCIPIO (Funciones de Modificación): INSERTA EN UN NUEVO NODO EL VALOR DE MOMENTO Y LO COLOCA AL PRINCIPIO DE LA LISTA
	{

		if (nuevo == NULL) // Si no a podido reservarse la memoria se devuelve false
		{
	 		return false;
		}else{
			if(vacia())
			{
				nuevo->siguiente=NULL;
				_cabeza=nuevo;
				_cursor=nuevo;
				_cola=nuevo;
				_n++;
			}else{
				 nuevo->siguiente=_cabeza;
				 _cabeza=nuevo;
				 _cursor=nuevo;
				 _n++;
			}
			return true;
		}
	}

	bool ListaTorreshanoi::insertarNodoAlFinal(NodoLista *nuevo) //FUNCIÓN INTERTARALFINAL (Funciones de Modificacion): INSERTA EN UN NUEVO NODO EL VALOR DE MOMENTO Y LO COLOCA AL FINAL DE LA LISTA
	{
		if (nuevo == NULL) // Si no a podido reservarse la memoria se devuelve false
		{
	 		return false;
		}else{
			nuevo->siguiente=NULL;
			if(vacia())
			{
				_cabeza=nuevo;
				_cursor=nuevo;
				_cola=nuevo;
				_n++;
			}else{
				_cola->siguiente = nuevo;
				_cola=_cola->siguiente;
				_n++;
			}
			return true;
		}
	}

	bool ListaTorreshanoi::borrarActual(int logico) //FUNCIÓN BORRAR (Funciones de Modificacion): BORRA EL ELEMENTO ACTUAL DE LA LISTA
	{
		if (vacia()) // Si la lista está vacia no se borra nada
		{
			return false;
		} else {
			NodoLista *buscado, *anterior;

			buscado = _cabeza;

			if (buscado == _cursor) // Se verifica si el elemento a eliminar está al principio de la lista (**)
			{
				if (buscado == _cola) // (**), si es así y tambien el el ultimo (osea, solo hay un elemento) se establece n a 0, se pone todo a NULL y se elimina
				{
					_cabeza = _cola = _cursor = NULL;
					_n = 0;
					if (logico==1)
						delete buscado;
					return true;
				} else { // (**), si es así y hay más elementos, entonces movemos la cabeza y el cursor al siguiente elemento, despues borramos el enlace con la lista, disminuimos n y borramos el nodo.
					_cabeza = _cabeza->siguiente;
					_cursor = _cabeza;
					buscado->siguiente = NULL;
					if (logico==1)
						delete buscado;
					_n--;
					return true;
	          	}
	        } else { //Se verifica que el elemento a eliminar no está al principio de la lista (^^)

				anterior = buscado; //anterior contiene la cabeza
				buscado = buscado->siguiente; //buscado contiene el 2º elemento de la lista
	 
				while(buscado!=NULL) //Mientras no se llegue al final de la lista estamos en bucle
				{
	            	if (buscado == _cursor) // Se verifica que ya estamos en la posición del cursor (¨¨) (^^)
	                {
			   			if (_cursor == _cola)  // Se verifica que el elemento es el ultimo (++) (¨¨) (^^)
			      		{
								// Si se cumple (++) (¨¨) (^^), entonces cola y cursor pasa a ser el anterior, se apunta el siguiente de cola a NULL, se borra buscado y se disminuye n
								_cola = anterior;
								_cola->siguiente = NULL;
	 							_cursor = anterior;
	 							if (logico==1)
									delete buscado;
								_n--;
								return true;
			     		} else { // Si se cumple (¨¨) (^^), pero el elemento no es el ultimo (osea, el cursor esta en medio de 2 nodos)
	                        	// Se mueve el cursor al siguiente y se apunta el puntero del nodo anterior a donde está el cursor, se borra buscado y de disminuye n
			  					_cursor = _cursor->siguiente;
			  					anterior->siguiente = _cursor;
			  					if (logico==1)
			   						delete buscado;
								_n--;
								return true;
						}
					} else { // Si todabía no se a llegado a donde está el cursor, se sigue desplazando a la siguiente posición
						anterior = buscado; 
	                    buscado = buscado->siguiente;
	                }
				}
	        }
		}
	 	return false; // Si el programa llega a este punto, no se a podido borrar		
	}

	void ListaTorreshanoi::cursorAlPrincipio() // FUNCIÓN CURSORALPRINCIPIO (Funciones de Modificacion): Mueve el cursor al principio de la lista
	{
		_cursor=_cabeza;
	}

	void ListaTorreshanoi::cursorAlFinal() // FUNCIÓN CURSORALFINAL (Funciones de Modificacion): Mueve el cursor al final de la lista
	{
		_cursor=_cola;
	}

	bool ListaTorreshanoi::siguienteMomento() // FUNCIÓN SIGUIENTE (Funciones de Modificacion): Mueve el cursor a la siguiente posición
	{
		if(!vacia()) //Si la lista no está vacía
		{
			if(_cursor==_cola) // Si se llega al final, se vuelve al principio de la lista
			{
				cursorAlPrincipio();
			} else { // Si no se llega al final, se desplaza a la siguiente posición
				_cursor = _cursor->siguiente;
			}
			return true;
		} else {
			return false;
		}
	}


	//Funciones de visualización
	void ListaTorreshanoi::verLista() // FUNCIÓN VERLISTA (Funciones de visualización): Muestra la lista completamente
	{
		if (!vacia()) // Si no está vacía
		{
			int n = longitud();

			cursorAlPrincipio();

			cout << endl << " * Resultado: " << endl << endl;
			for (int i = 1; i<= n; i++)
			{
				cout << obtenerMomento() << endl; // Se usa el extractor heredado de la clase TorresHanoi
				siguienteMomento();
			}
		}
		else
			cout << " !* La lista esta vacia." << endl;
	}

};