#ifndef _FUNCIONESBUSQUEDA_H_
#define _FUNCIONESBUSQUEDA_H_

#define LIMPIARPANTALLA       cout << "\33[2J" << "\33[2J"
#define LUGAR(x,y)   cout << "\033[" << (x) << ";" << (y) << "H"

#include <iostream>
#include <time.h>
#include <sys/time.h>

#include "ListasHanoi.hpp"

using namespace std;

namespace Hanoi{
	//
	// PROTOTIPOS DE FUNCIONES DE MENUS
	//
	int menu();

	//
	// PROTOTIPOS DE FUNCIONES DE MEDIO NIVEL
	//
	void BusquedaEnProfundidad(TorresHanoi &Origen, TorresHanoi &Destino);
	void BusquedaEnAnchura(TorresHanoi &Origen, TorresHanoi &Destino);
	void MostrarEstadisticasAnchuraYProfundidad(TorresHanoi &Origen, TorresHanoi &Destino, ListaTorreshanoi *Frontera, ListaTorreshanoi *Explorados, int iteraciones, struct timeval tInicial, struct timeval tFinal, ListaTorreshanoi *RutaEncontrada);
	void BusquedaBidireccional(TorresHanoi &Origen, TorresHanoi &Destino);


	//
	// PROTOTIPOS DE FUNCIONES DE BAJO NIVEL
	//
	bool existeNodoEnLista(TorresHanoi &Actual, ListaTorreshanoi *Frontera);
	bool existeNodosIgualesEnListas(ListaTorreshanoi *FronteraA, ListaTorreshanoi *ExploradosA, ListaTorreshanoi *FronteraB, ListaTorreshanoi *ExploradosB);
	NodoLista * buscarNodoEnListas(TorresHanoi &Actual, ListaTorreshanoi *Frontera, ListaTorreshanoi *Explorados);
	NodoLista * buscarNodosIgualesEnListas(ListaTorreshanoi *FronteraA, ListaTorreshanoi *ExploradosA, ListaTorreshanoi *FronteraB, ListaTorreshanoi *ExploradosB);
	void PosiblesJugadas(NodoLista *Actual, ListaTorreshanoi *Frontera, ListaTorreshanoi *Explorados);
};
#endif
