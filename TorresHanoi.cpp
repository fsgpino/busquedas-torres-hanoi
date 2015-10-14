#include "TorresHanoi.hpp"

using namespace std;
using namespace Hanoi;

namespace Hanoi{

	//
	// FUNCIONES DENTRO DE LA CLASE TORRESHANOI
	//

	//Constructor del elemento TorresHanoi
	TorresHanoi::TorresHanoi()
	{
		vaciarTorres();
	}


	//Destructor del elemento TorresHanoi
	TorresHanoi::~TorresHanoi()
	{
		vaciarTorres();
	}


	//Funciones de Consulta (Verifica si la pila está vacía)
	bool TorresHanoi::vaciaTorreA()
	{
		if (_TorreA.empty())
			return true;
		else
			return false;
	}

	bool TorresHanoi::vaciaTorreB()
	{
		if (_TorreB.empty())
			return true;
		else
			return false;
	}

	bool TorresHanoi::vaciaTorreC()
	{
		if (_TorreC.empty())
			return true;
		else
			return false;
	}

	//Funcion destructora (Elimina el contenido de las torres)
	void TorresHanoi::vaciarTorres()
	{
		_TorreA.erase(_TorreA.begin(),_TorreA.end());
		_TorreB.erase(_TorreB.begin(),_TorreB.end());
		_TorreC.erase(_TorreC.begin(),_TorreC.end());
	}

	//Funciones de Salida de Altura de la torre (Devuelve la altura de la Torre)
	int TorresHanoi::alturaDeTorreA() { return _TorreA.size(); }
	int TorresHanoi::alturaDeTorreB() { return _TorreB.size(); }
	int TorresHanoi::alturaDeTorreC() { return _TorreC.size(); }


	//Funciones de Salida (Obtiene el contenido Value de la posición más alta de la torre (Cima de la pila))
	int TorresHanoi::verCimaDeTorreA() { return _TorreA.back(); }
	int TorresHanoi::verCimaDeTorreB() { return _TorreB.back(); }
	int TorresHanoi::verCimaDeTorreC() { return _TorreC.back(); }


	//Funciones de Salida de la posición X (Obtiene el contenido Value de la posición X del vector (Si no existe devuelve 0))
	int TorresHanoi::verPosicionXdeTorreA(int x)
	{
		assert(x>=0);
		int y = _TorreA.size();
		if (x>=y)
			return 0;
		return _TorreA[x];
	}

	int TorresHanoi::verPosicionXdeTorreB(int x)
	{
		assert(x>=0);
		int y = _TorreB.size();
		if (x>=y)
			return 0;
		return _TorreB[x];
	}

	int TorresHanoi::verPosicionXdeTorreC(int x)
	{
		assert(x>=0);
		int y = _TorreC.size();
		if (x>=y)
			return 0;
		return _TorreC[x];
	}


	//Funciones de Salida y Eliminación (Obtiene el contenido Value de la posición más alta de la torre (Cima de la pila) y elimina su contenido)
	int TorresHanoi::sacarDeTorreA()
	{
		int aux;
		aux=_TorreA.back();
		_TorreA.pop_back();
		return aux;
	}

	int TorresHanoi::sacarDeTorreB()
	{
		int aux;
		aux=_TorreB.back();
		_TorreB.pop_back();
		return aux;
	}

	int TorresHanoi::sacarDeTorreC()
	{
		int aux;
		aux=_TorreC.back();
		_TorreC.pop_back();
		return aux;
	}


	//Funciones de Entrada de discos (Introduce un numeros de discos X en la Torre Y)
	void TorresHanoi::ponerXDiscosEnTorreA(int x)
	{
		int contador;
		for(contador=x;contador>0;contador--)
			ponerEnTorreA(contador);
	}
	void TorresHanoi::ponerXDiscosEnTorreB(int x)
	{
		int contador;
		for(contador=x;contador>0;contador--)
			ponerEnTorreB(contador);
	}
	void TorresHanoi::ponerXDiscosEnTorreC(int x)
	{
		int contador;
		for(contador=x;contador>0;contador--)
			ponerEnTorreC(contador);
	}


	//Funciones de Entrada (Introduce el contenido Value en la posición más alta de la torre (Cima de la pila))
	void TorresHanoi::ponerEnTorreA(int value) { assert(value>0); _TorreA.push_back(value); }
	void TorresHanoi::ponerEnTorreB(int value) { assert(value>0); _TorreB.push_back(value); }
	void TorresHanoi::ponerEnTorreC(int value) { assert(value>0); _TorreC.push_back(value); }


	//Funciones de Chequeo (Verifica si la jugada de una Torre X a una Torre Y es posible)
	bool TorresHanoi::CheckDeTorreAaTorreB()
	{
		if(!vaciaTorreA())
			if(vaciaTorreB())
				return true;

		if (!vaciaTorreA())
			if(verCimaDeTorreA()<verCimaDeTorreB())
				return true;

		return false;
	}

	bool TorresHanoi::CheckDeTorreAaTorreC()
	{
		if(!vaciaTorreA())
			if(vaciaTorreC())
				return true;

		if (!vaciaTorreA())
			if(verCimaDeTorreA()<verCimaDeTorreC())
				return true;

		return false;
	}

	bool TorresHanoi::CheckDeTorreBaTorreA()
	{
		if(!vaciaTorreB())
			if(vaciaTorreA())
				return true;

		if (!vaciaTorreB())
			if(verCimaDeTorreB()<verCimaDeTorreA())
				return true;

		return false;
	}

	bool TorresHanoi::CheckDeTorreBaTorreC()
	{
		if(!vaciaTorreB())
			if(vaciaTorreC())
				return true;

		if (!vaciaTorreB())
			if(verCimaDeTorreB()<verCimaDeTorreC())
				return true;

		return false;
	}

	bool TorresHanoi::CheckDeTorreCaTorreA()
	{
		if(!vaciaTorreC())
			if(vaciaTorreA())
				return true;

		if (!vaciaTorreC())
			if(verCimaDeTorreC()<verCimaDeTorreA())
				return true;

		return false;
	}

	bool TorresHanoi::CheckDeTorreCaTorreB()
	{
		if(!vaciaTorreC())
			if(vaciaTorreB())
				return true;

		if (!vaciaTorreC())
			if(verCimaDeTorreC()<verCimaDeTorreB())
				return true;

		return false;
	}


	//Función de Movimiento (Realiza el movimiento de un disco de la Torre X a la Torre Y)
	void TorresHanoi::MoverDeTorreAaTorreB() { ponerEnTorreB(sacarDeTorreA()); }
	void TorresHanoi::MoverDeTorreAaTorreC() { ponerEnTorreC(sacarDeTorreA()); }
	void TorresHanoi::MoverDeTorreBaTorreA() { ponerEnTorreA(sacarDeTorreB()); }
	void TorresHanoi::MoverDeTorreBaTorreC() { ponerEnTorreC(sacarDeTorreB()); }
	void TorresHanoi::MoverDeTorreCaTorreA() { ponerEnTorreA(sacarDeTorreC()); }
	void TorresHanoi::MoverDeTorreCaTorreB() { ponerEnTorreB(sacarDeTorreC()); }


	//Función que carga en las torres el contenido de la clase TorresHanoi X
	void TorresHanoi::CargarEnTorresHanoi(TorresHanoi &x)
	{
		vector <int>::iterator it;

		for(it = x._TorreA.begin(); it != x._TorreA.end(); it++)
			ponerEnTorreA(*it);
		for(it = x._TorreB.begin(); it != x._TorreB.end(); it++)
			ponerEnTorreB(*it);
		for(it = x._TorreC.begin(); it != x._TorreC.end(); it++)
			ponerEnTorreC(*it);
	}


	//Sobrecarga del operador << para salida en flujo stream
	ostream &operator<<(ostream &stream, TorresHanoi &p)
	{
		int contadorAnchura, contadorAltura, alturaMaxima, anchuraMaxima;

			alturaMaxima=p.alturaDeTorreA();
		if (alturaMaxima<p.alturaDeTorreB())
			alturaMaxima=p.alturaDeTorreB();
		if (alturaMaxima<p.alturaDeTorreC())
			alturaMaxima=p.alturaDeTorreC();

			anchuraMaxima=p.verPosicionXdeTorreA(0);
		if (anchuraMaxima<p.verPosicionXdeTorreB(0))
			anchuraMaxima=p.verPosicionXdeTorreB(0);
		if (anchuraMaxima<p.verPosicionXdeTorreC(0))
			anchuraMaxima=p.verPosicionXdeTorreC(0);

		stream << " ";
		for (contadorAnchura = 0; contadorAnchura < ((anchuraMaxima*6)+11);contadorAnchura++)
			stream << "*";
		stream << endl;

		for (contadorAltura = alturaMaxima; contadorAltura>=0; contadorAltura--)
		{
			stream << " **";
			if (p.verPosicionXdeTorreA(contadorAltura)!=0)
			{
				for (contadorAnchura = 1; contadorAnchura <= (anchuraMaxima - p.verPosicionXdeTorreA(contadorAltura)); contadorAnchura++)
					stream << " ";
			
				for (contadorAnchura = 1; contadorAnchura <= (p.verPosicionXdeTorreA(contadorAltura)); contadorAnchura++)
					stream << "-";

				stream << "-";

				for (contadorAnchura = 1; contadorAnchura <= (p.verPosicionXdeTorreA(contadorAltura)); contadorAnchura++)
					stream << "-";

				for (contadorAnchura = 1; contadorAnchura <= (anchuraMaxima - p.verPosicionXdeTorreA(contadorAltura)); contadorAnchura++)
					stream << " ";
			}else{
				for (contadorAnchura = 1; contadorAnchura <= anchuraMaxima; contadorAnchura++)
					stream << " ";

				stream << "|";

				for (contadorAnchura = 1; contadorAnchura <= anchuraMaxima; contadorAnchura++)
					stream << " ";
			}
			stream << "**";
			if (p.verPosicionXdeTorreB(contadorAltura)!=0)
			{
				for (contadorAnchura = 1; contadorAnchura <= (anchuraMaxima - p.verPosicionXdeTorreB(contadorAltura)); contadorAnchura++)
					stream << " ";
			
				for (contadorAnchura = 1; contadorAnchura <= (p.verPosicionXdeTorreB(contadorAltura)); contadorAnchura++)
					stream << "-";

				stream << "-";

				for (contadorAnchura = 1; contadorAnchura <= (p.verPosicionXdeTorreB(contadorAltura)); contadorAnchura++)
					stream << "-";

				for (contadorAnchura = 1; contadorAnchura <= (anchuraMaxima - p.verPosicionXdeTorreB(contadorAltura)); contadorAnchura++)
					stream << " ";
			}else{
				for (contadorAnchura = 1; contadorAnchura <= anchuraMaxima; contadorAnchura++)
					stream << " ";

				stream << "|";

				for (contadorAnchura = 1; contadorAnchura <= anchuraMaxima; contadorAnchura++)
					stream << " ";
			}
			stream << "**";
			if (p.verPosicionXdeTorreC(contadorAltura)!=0)
			{
				for (contadorAnchura = 1; contadorAnchura <= (anchuraMaxima - p.verPosicionXdeTorreC(contadorAltura)); contadorAnchura++)
					stream << " ";
			
				for (contadorAnchura = 1; contadorAnchura <= (p.verPosicionXdeTorreC(contadorAltura)); contadorAnchura++)
					stream << "-";

				stream << "-";

				for (contadorAnchura = 1; contadorAnchura <= (p.verPosicionXdeTorreC(contadorAltura)); contadorAnchura++)
					stream << "-";

				for (contadorAnchura = 1; contadorAnchura <= (anchuraMaxima - p.verPosicionXdeTorreC(contadorAltura)); contadorAnchura++)
					stream << " ";
			}else{
				for (contadorAnchura = 1; contadorAnchura <= anchuraMaxima; contadorAnchura++)
					stream << " ";

				stream << "|";

				for (contadorAnchura = 1; contadorAnchura <= anchuraMaxima; contadorAnchura++)
					stream << " ";
			}
			stream << "**" << endl;
		}
		stream << " ";
		for (contadorAnchura = 0; contadorAnchura < ((anchuraMaxima*6)+11);contadorAnchura++)
			stream << "*";
		stream << endl;
		return stream;
	}


	//
	// FUNCIONES FUERA DE LA CLASE TORRESHANOI
	//

	//Función de Comprobación si TorresHanoi X es igual que TorresHanoi Y
	bool TorresHanoiXesIgualQueTorresHanoiY(TorresHanoi &x, TorresHanoi &y)
	{
		int contador;

		if ((x.alturaDeTorreA()!=y.alturaDeTorreA())||(x.alturaDeTorreB()!=y.alturaDeTorreB())||(x.alturaDeTorreC()!=y.alturaDeTorreC()))
			return false;

		for (contador=0;contador<x.alturaDeTorreA();contador++)
			if (x.verPosicionXdeTorreA(contador)!=y.verPosicionXdeTorreA(contador))
				return false;

		for (contador=0;contador<x.alturaDeTorreB();contador++)
			if (x.verPosicionXdeTorreB(contador)!=y.verPosicionXdeTorreB(contador))
				return false;

		for (contador=0;contador<x.alturaDeTorreC();contador++)
			if (x.verPosicionXdeTorreC(contador)!=y.verPosicionXdeTorreC(contador))
				return false;

		return true;
	}
};
