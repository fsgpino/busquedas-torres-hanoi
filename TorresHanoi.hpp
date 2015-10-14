#ifndef _TORRESHANOI_H_
#define _TORRESHANOI_H_

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

namespace Hanoi {
	class TorresHanoi
	{
		private:
			vector <int> _TorreA;
			vector <int> _TorreB;
			vector <int> _TorreC;
		public:
			//Constructor del elemento TorresHanoi
			TorresHanoi();

			//Destructor del elemento TorresHanoi
			~TorresHanoi();

			//Funciones de Consulta si la torre está vacia (Verifica si la pila está vacía)
			bool vaciaTorreA();
			bool vaciaTorreB();
			bool vaciaTorreC();

			//Funcion destructora (Elimina el contenido de las torres)
			void vaciarTorres();

			//Funciones de Salida de Altura de la torre (Devuelve la altura de la Torre)
			int alturaDeTorreA();
			int alturaDeTorreB();
			int alturaDeTorreC();

			//Funciones de Salida de la Cima (Obtiene el contenido Value de la posición más alta de la torre (Cima de la pila))
			int verCimaDeTorreA();
			int verCimaDeTorreB();
			int verCimaDeTorreC();

			//Funciones de Salida de la posición X (Obtiene el contenido Value de la posición X del vector (Si no existe devuelve 0))
			int verPosicionXdeTorreA(int x);
			int verPosicionXdeTorreB(int x);
			int verPosicionXdeTorreC(int x);

			//Funciones de Salida y Eliminación de la Cima(Obtiene el contenido Value de la posición más alta de la torre (Cima de la pila) y elimina su contenido)
			int sacarDeTorreA();
			int sacarDeTorreB();
			int sacarDeTorreC();

			//Funciones de Entrada de discos (Introduce un numeros de discos X en la Torre Y)
			void ponerXDiscosEnTorreA(int x);
			void ponerXDiscosEnTorreB(int x);
			void ponerXDiscosEnTorreC(int x);

			//Funciones de Entrada (Introduce el contenido Value en la posición más alta de la torre (Cima de la pila))
			void ponerEnTorreA(int value);
			void ponerEnTorreB(int value);
			void ponerEnTorreC(int value);

			//Funciones de Chequeo (Verifica si la jugada de una Torre X a una Torre Y es posible)
			bool CheckDeTorreAaTorreB();
			bool CheckDeTorreAaTorreC();
			bool CheckDeTorreBaTorreA();
			bool CheckDeTorreBaTorreC();
			bool CheckDeTorreCaTorreA();
			bool CheckDeTorreCaTorreB();

			//Función de Movimiento (Realiza el movimiento de un disco de la Torre X a la Torre Y)
			void MoverDeTorreAaTorreB();
			void MoverDeTorreAaTorreC();
			void MoverDeTorreBaTorreA();
			void MoverDeTorreBaTorreC();
			void MoverDeTorreCaTorreA();
			void MoverDeTorreCaTorreB();

			//Función que carga en las torres el contenido de la clase TorresHanoi X
			void CargarEnTorresHanoi(TorresHanoi &x);

			//Sobrecarga de operador =
			inline TorresHanoi &operator=(TorresHanoi &x)
			{
				CargarEnTorresHanoi(x);
				return *this;
			}

			//Sobrecarga del operador << para salida en flujo stream
			friend ostream &operator<<(ostream &stream, TorresHanoi &p);
	};

	//Función de Comprobación si TorresHanoi X es igual que TorresHanoi Y
	bool TorresHanoiXesIgualQueTorresHanoiY(TorresHanoi &x, TorresHanoi &y);
}

#endif