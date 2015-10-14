#ifndef _LISTASHANOI_H_
#define _LISTASHANOI_H_

#define LIMPIARPANTALLA       cout << "\33[2J" << "\33[2J"
#define LUGAR(x,y)   cout << "\033[" << (x) << ";" << (y) << "H"

#include <iostream>

#include "TorresHanoi.hpp"

using namespace std;

namespace Hanoi{
	struct NodoLista
	{
		TorresHanoi Momento;
		int profundidad;
		NodoLista *padre;
		NodoLista *siguiente;
	};

	class ListaTorreshanoi
	{
		private:
			int _n;
			NodoLista *_cabeza;
			NodoLista *_cola;
			NodoLista *_cursor;
		public:
			//Constructor del elemento ListaTorresHanoi
			ListaTorreshanoi();

			//Destructor del elemento TorresHanoi
			~ListaTorreshanoi();

			//Funciones de lectura/Acceso
			bool vacia(); //Devuelve True o False dependiendo si la lista está vacia o no
			int longitud(); //Devuelve el tamaño de la lista
			TorresHanoi &obtenerMomento(); //Devuelve el elemento TorresHanoi que se encuentre en el cursor
			int obtenerProfundidad(); //Devuelve la profundidad necesaria desde el orgigen hasta el nodo actual
			NodoLista * obtenerPadre(); //Devuelve el puntero al nodo padre del nodo actual
			NodoLista * obtenerCursor(); //Devuelve el puntero del nodo actual

			//Funciones de Modificación
			void liberarMemoria();
			void guardarMomento(TorresHanoi &MomentoAGuardar, int profundidadAGuardar, NodoLista * padreAGuardar);
			bool insertarAlPrincipio(TorresHanoi &MomentoAGuardar, int profundidadAGuardar, NodoLista * padreAGuardar);
			bool insertarAlFinal(TorresHanoi &MomentoAGuardar, int profundidadAGuardar, NodoLista * padreAGuardar);
			bool insertarNodoAlPrincipio(NodoLista *nuevo);
			bool insertarNodoAlFinal(NodoLista *nuevo);
			bool borrarActual(int logico); //Si logico es 1 elimina el nodo de la memoria, en caso contrario solo lo saca de la lista
			void cursorAlPrincipio();
			void cursorAlFinal();
			bool siguienteMomento();

			//Funciones de visualización
			void verLista();
	};
}

#endif