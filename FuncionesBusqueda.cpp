#include "FuncionesBusqueda.hpp"

using namespace std;
using namespace Hanoi;

namespace Hanoi{

	//
	// PROTOTIPOS DE FUNCIONES DE MENUS
	//
	int menu()
	{
	  int opcion; 
	  LIMPIARPANTALLA;
	  LUGAR(1,1);
	  cout << "********************************************************\n";
	  cout << "*            Busquedas con torres de hanoi             *\n";
	  cout << "*               Por Francisco Gómez Pino               *\n";
	  cout << "********************************************************\n";  
	  cout << "** 1.  Realizar busqueda en profundidad.              **\n";
	  cout << "** 2.  Realizar busqueda en anchura.                  **\n";
	  cout << "** 3.  Realizar busqueda bidireccinal.                **\n";
	  cout << "** 0.  Salir del programa.                            **\n";
	  cout << "********************************************************\n";
	  cout << " \n >* Introduzca una opción: ";
	  cin >> opcion;
	  getchar();
	  return opcion;
	}

	//
	// FUNCIONES DE MEDIO NIVEL
	//
	void BusquedaEnProfundidad(TorresHanoi &Origen, TorresHanoi &Destino)
	{
		int iteracionesRealizadas=0;
		struct timeval tInicial, tFinal;
		ListaTorreshanoi *Frontera, *Explorados, *RutaEncontrada;
		NodoLista *Actual;

		Frontera = new ListaTorreshanoi;
		Explorados = new ListaTorreshanoi;
		Actual = NULL;

		Frontera->insertarAlPrincipio(Origen, 0, NULL);

		cout << " * Realizando busqueda en profundidad...";
		gettimeofday(&tInicial, NULL);
		while (!existeNodoEnLista(Destino, Frontera))
		{
			iteracionesRealizadas++;
			Frontera->cursorAlPrincipio();
			Actual = Frontera->obtenerCursor();
			Frontera->borrarActual(0);

			PosiblesJugadas(Actual, Frontera, Explorados);

			Explorados->insertarNodoAlFinal(Actual);
			Actual=NULL;
		}
		gettimeofday(&tFinal, NULL);
		cout << "...Completado" << endl;

		RutaEncontrada = new ListaTorreshanoi;
		Actual=buscarNodoEnListas(Destino,Frontera,Explorados);

		cout << " * Obteniendo camino de la busqueda...";
		while (Actual->padre!=NULL)
		{
			RutaEncontrada->insertarAlPrincipio(Actual->Momento, Actual->profundidad, NULL);
			Actual=Actual->padre;
		}
		RutaEncontrada->insertarAlPrincipio(Actual->Momento, Actual->profundidad, NULL);
		cout << "...Completado" << endl;

		cout << endl << " * Resultados estadisticos de la busqueda en profundidad: " << endl;
		MostrarEstadisticasAnchuraYProfundidad(Origen, Destino, Frontera, Explorados, iteracionesRealizadas, tInicial, tFinal, RutaEncontrada);
		cout << endl;

		delete Frontera;
		delete Explorados;
		delete RutaEncontrada;
	}

	void BusquedaEnAnchura(TorresHanoi &Origen, TorresHanoi &Destino)
	{
		int iteracionesRealizadas=0;
		struct timeval tInicial, tFinal;
		ListaTorreshanoi *Frontera, *Explorados, *RutaEncontrada;
		NodoLista *Actual;

		Frontera = new ListaTorreshanoi;
		Explorados = new ListaTorreshanoi;
		Actual = NULL;

		Frontera->insertarAlPrincipio(Origen, 0, NULL);

		cout << " * Realizando busqueda en anchura...";
		gettimeofday(&tInicial, NULL);
		while (!existeNodoEnLista(Destino, Frontera))
		{
			iteracionesRealizadas++;
			Frontera->cursorAlFinal();
			Actual = Frontera->obtenerCursor();
			Frontera->borrarActual(0);

			PosiblesJugadas(Actual, Frontera, Explorados);

			Explorados->insertarNodoAlFinal(Actual);
			Actual=NULL;
		}
		gettimeofday(&tFinal, NULL);
		cout << "...Completado" << endl;

		RutaEncontrada = new ListaTorreshanoi;
		Actual=buscarNodoEnListas(Destino,Frontera,Explorados);

		cout << " * Obteniendo camino de la busqueda...";
		while (Actual->padre!=NULL)
		{
			RutaEncontrada->insertarAlPrincipio(Actual->Momento, Actual->profundidad, NULL);
			Actual=Actual->padre;
		}
		RutaEncontrada->insertarAlPrincipio(Actual->Momento, Actual->profundidad, NULL);
		cout << "...Completado" << endl;

		cout << endl << " * Resultados estadisticos de la busqueda en anchura: " << endl;
		MostrarEstadisticasAnchuraYProfundidad(Origen, Destino, Frontera, Explorados, iteracionesRealizadas, tInicial, tFinal, RutaEncontrada);
		cout << endl;

		delete Frontera;
		delete Explorados;
		delete RutaEncontrada;
	}

	void MostrarEstadisticasAnchuraYProfundidad(TorresHanoi &Origen, TorresHanoi &Destino, ListaTorreshanoi *Frontera, ListaTorreshanoi *Explorados, int iteraciones, struct timeval tInicial, struct timeval tFinal, ListaTorreshanoi *RutaEncontrada)
	{
		int nNodosFrontera = Frontera->longitud();
		int nNodosExplorados = Explorados->longitud();
		int nNodosRutaEncontrada = RutaEncontrada->longitud();
		int nNodosTotales = nNodosFrontera+nNodosExplorados+nNodosRutaEncontrada;
		float MemoriaConsumidaAproximadaBytes = (sizeof(TorresHanoi)*nNodosTotales)+(sizeof(NodoLista)*nNodosTotales)+(sizeof(ListaTorreshanoi)*3);
		float MemoriaConsumidaAproximadaKiloBytes = MemoriaConsumidaAproximadaBytes/1024;
		float MemoriaConsumidaAproximadaMegaBytes = MemoriaConsumidaAproximadaKiloBytes/1024;
		int IteracionesRealizadas = iteraciones;
		float tiempoEstimadoEnMilisegundos = 0.001*((tFinal.tv_sec * 1000000.0 + tFinal.tv_usec) - (tInicial.tv_sec * 1000000.0 + tInicial.tv_usec));
		float tiempoEstimadoEnSegundos = 0.000001* ((tFinal.tv_sec * 1000000.0 + tFinal.tv_usec) - (tInicial.tv_sec * 1000000.0 + tInicial.tv_usec));
		char verLista;

		cout << "  - Número de nodos en memoria:   " << nNodosTotales << endl;
		cout << "    ^ En frontera:                " << nNodosFrontera << endl;
		cout << "    ^ En explorados:              " << nNodosExplorados << endl;
		cout << "    ^ En ruta encontrada:         " << nNodosRutaEncontrada << endl;

		cout << endl;
		cout << "  - Memoria consumida aproximada: " << MemoriaConsumidaAproximadaBytes << " Bytes" << endl;
		cout << "    ^ En KiloBytes:               "; printf("%.4f KiloBytes\n", MemoriaConsumidaAproximadaKiloBytes);
		cout << "    ^ En MegaBytes:               "; printf("%.4f MegaBytes\n", MemoriaConsumidaAproximadaMegaBytes);
		cout << endl;
		cout << "  - Iteraciones realizadas:       " << IteracionesRealizadas << endl;
		cout << endl;
		cout << "  - Tiempo estimado en busqueda:  "; printf("%.4f Milisegundos\n", tiempoEstimadoEnMilisegundos);
		cout << "    ^ En segundos:                "; printf("%.4f Segundos\n", tiempoEstimadoEnSegundos);

		do
		{
			cout << endl << " >* ¿Desea ver por pantalla el resultado de la ruta encontrada? (s/n): ";
			scanf("%c", &verLista);
			getchar();
		}while(verLista!='s'&&verLista!='n');

		if(verLista=='s')
			RutaEncontrada->verLista();
	}

	void BusquedaBidireccional(TorresHanoi &Origen, TorresHanoi &Destino)
	{
		int iteracionesRealizadas=0;
		struct timeval tInicial, tFinal;
		ListaTorreshanoi *FronteraProfundidad, *ExploradosProfundidad, *FronteraAnchura, *ExploradosAnchura, *RutaEncontrada;
		NodoLista *ActualProfundidad, *ActualAnchura, *NodoMedio;

		FronteraProfundidad = new ListaTorreshanoi;
		ExploradosProfundidad = new ListaTorreshanoi;
		FronteraAnchura = new ListaTorreshanoi;
		ExploradosAnchura = new ListaTorreshanoi;
		ActualProfundidad = NULL;
		ActualAnchura = NULL;

		FronteraProfundidad->insertarAlPrincipio(Origen, 0, NULL);
		FronteraAnchura->insertarAlPrincipio(Destino, 0, NULL);

		cout << " * Realizando busqueda bidireccional...";
		gettimeofday(&tInicial, NULL);
		while (!existeNodosIgualesEnListas(FronteraProfundidad, ExploradosProfundidad, FronteraAnchura, ExploradosAnchura))
		{
			iteracionesRealizadas++;
			FronteraProfundidad->cursorAlPrincipio();
			ActualProfundidad = FronteraProfundidad->obtenerCursor();
			FronteraProfundidad->borrarActual(0);

			PosiblesJugadas(ActualProfundidad, FronteraProfundidad, ExploradosProfundidad);

			ExploradosProfundidad->insertarNodoAlFinal(ActualProfundidad);
			ActualProfundidad=NULL;

			FronteraAnchura->cursorAlFinal();
			ActualAnchura = FronteraAnchura->obtenerCursor();
			FronteraAnchura->borrarActual(0);

			PosiblesJugadas(ActualAnchura, FronteraAnchura, ExploradosAnchura);

			ExploradosAnchura->insertarNodoAlFinal(ActualAnchura);
			ActualAnchura=NULL;
		}
		gettimeofday(&tFinal, NULL);
		cout << "...Completado" << endl;

		RutaEncontrada = new ListaTorreshanoi;
		NodoMedio = buscarNodosIgualesEnListas(FronteraProfundidad, ExploradosProfundidad, FronteraAnchura, ExploradosAnchura);
		ActualProfundidad = buscarNodoEnListas(NodoMedio->Momento, FronteraProfundidad, ExploradosProfundidad);
		ActualAnchura = buscarNodoEnListas(NodoMedio->Momento, FronteraAnchura, ExploradosAnchura);
		ActualAnchura = ActualAnchura->padre;
		
		cout << " * Obteniendo camino de la busqueda...";
		while (ActualProfundidad->padre!=NULL)
		{
			RutaEncontrada->insertarAlPrincipio(ActualProfundidad->Momento, ActualProfundidad->profundidad, NULL);
			ActualProfundidad=ActualProfundidad->padre;
		}
		RutaEncontrada->insertarAlPrincipio(ActualProfundidad->Momento, ActualProfundidad->profundidad, NULL);
		while (ActualAnchura->padre!=NULL)
		{
			RutaEncontrada->insertarAlFinal(ActualAnchura->Momento, ActualAnchura->profundidad, NULL);
			ActualAnchura=ActualAnchura->padre;
		}
		RutaEncontrada->insertarAlFinal(ActualAnchura->Momento, ActualAnchura->profundidad, NULL);
		cout << "...Completado" << endl;

		cout << endl << " * Resultados estadisticos de la busqueda bidireccional: " << endl;

		//INICIO DE RESUMEN ESTADISTICO PARA BIDIRECCIONAL
		int nNodosFronteraProfundidad = FronteraProfundidad->longitud();
		int nNodosExploradosProfundidad = ExploradosProfundidad->longitud();
		int nNodosFronteraAnchura = FronteraAnchura->longitud();
		int nNodosExploradosAnchura = ExploradosAnchura->longitud();
		int nNodosRutaEncontrada = RutaEncontrada->longitud();
		int nNodosTotales = nNodosFronteraProfundidad+nNodosExploradosProfundidad+nNodosFronteraAnchura+nNodosExploradosAnchura+nNodosRutaEncontrada;
		float MemoriaConsumidaAproximadaBytes = (sizeof(TorresHanoi)*nNodosTotales)+(sizeof(NodoLista)*nNodosTotales)+(sizeof(ListaTorreshanoi)*5);
		float MemoriaConsumidaAproximadaKiloBytes = MemoriaConsumidaAproximadaBytes/1024;
		float MemoriaConsumidaAproximadaMegaBytes = MemoriaConsumidaAproximadaKiloBytes/1024;
		int IteracionesRealizadas = iteracionesRealizadas;
		float tiempoEstimadoEnMilisegundos = 0.001*((tFinal.tv_sec * 1000000.0 + tFinal.tv_usec) - (tInicial.tv_sec * 1000000.0 + tInicial.tv_usec));
		float tiempoEstimadoEnSegundos = 0.000001* ((tFinal.tv_sec * 1000000.0 + tFinal.tv_usec) - (tInicial.tv_sec * 1000000.0 + tInicial.tv_usec));
		char verLista;

		cout << "  - Número de nodos en memoria:     " << nNodosTotales << endl;
		cout << "    ^ En frontera de profundidad:   " << nNodosFronteraProfundidad << endl;
		cout << "    ^ En explorados de profundidad: " << nNodosExploradosProfundidad << endl;
		cout << "    ^ En frontera de anchura:       " << nNodosFronteraAnchura << endl;
		cout << "    ^ En explorados de anchura:     " << nNodosExploradosAnchura << endl;
		cout << "    ^ En ruta encontrada:           " << nNodosRutaEncontrada << endl;

		cout << endl;
		cout << "  - Memoria consumida aproximada:   " << MemoriaConsumidaAproximadaBytes << " Bytes" << endl;
		cout << "    ^ En KiloBytes:                 "; printf("%.4f KiloBytes\n", MemoriaConsumidaAproximadaKiloBytes);
		cout << "    ^ En MegaBytes:                 "; printf("%.4f MegaBytes\n", MemoriaConsumidaAproximadaMegaBytes);
		cout << endl;
		cout << "  - Iteraciones realizadas:         " << IteracionesRealizadas << endl;
		cout << endl;
		cout << "  - Tiempo estimado en busqueda:    "; printf("%.4f Milisegundos\n", tiempoEstimadoEnMilisegundos);
		cout << "    ^ En segundos:                  "; printf("%.4f Segundos\n", tiempoEstimadoEnSegundos);

		do
		{
			cout << endl << " >* ¿Desea ver por pantalla el resultado de la ruta encontrada? (s/n): ";
			scanf("%c", &verLista);
			getchar();
		}while(verLista!='s'&&verLista!='n');

		if(verLista=='s')
			RutaEncontrada->verLista();
		//FUN DE RESUMEN ESTADISTICO PARA BIDIRECCIONAL
		cout << endl;

		delete FronteraProfundidad;
		delete ExploradosProfundidad;
		delete FronteraAnchura;
		delete ExploradosAnchura;
		delete RutaEncontrada;
	}

	//
	// PROTOTIPOS DE FUNCIONES DE BAJO NIVEL
	//
	bool existeNodoEnLista(TorresHanoi &Actual, ListaTorreshanoi *Frontera)
	{
		int contador;
		Frontera->cursorAlPrincipio();
		for (contador=0; contador < (Frontera->longitud());contador++)
		{
			if(TorresHanoiXesIgualQueTorresHanoiY(Actual, Frontera->obtenerMomento()))
			{
				return true;
			}
			Frontera->siguienteMomento();
		}
		return false;
	}

	bool existeNodosIgualesEnListas(ListaTorreshanoi *FronteraA, ListaTorreshanoi *ExploradosA, ListaTorreshanoi *FronteraB, ListaTorreshanoi *ExploradosB)
	{
		int contadorA, contadorB;
		FronteraA->cursorAlPrincipio();
		for (contadorA=0; contadorA < (FronteraA->longitud());contadorA++)
		{
			FronteraB->cursorAlPrincipio();
			for (contadorB=0; contadorB < (FronteraB->longitud());contadorB++)
			{
				if(TorresHanoiXesIgualQueTorresHanoiY(FronteraA->obtenerMomento(), FronteraB->obtenerMomento()))
				{
					return true;
				}
				FronteraB->siguienteMomento();
			}
			ExploradosB->cursorAlPrincipio();
			for (contadorB=0; contadorB < (ExploradosB->longitud());contadorB++)
			{
				if(TorresHanoiXesIgualQueTorresHanoiY(FronteraA->obtenerMomento(), ExploradosB->obtenerMomento()))
				{
					return true;
				}
				ExploradosB->siguienteMomento();
			}
			FronteraA->siguienteMomento();
		}
		return false;
	}

	NodoLista * buscarNodoEnListas(TorresHanoi &Actual, ListaTorreshanoi *Frontera, ListaTorreshanoi *Explorados)
	{
		int contador;
		Frontera->cursorAlPrincipio();
		for (contador=0; contador < (Frontera->longitud());contador++)
		{
			if(TorresHanoiXesIgualQueTorresHanoiY(Actual, Frontera->obtenerMomento()))
			{
				return Frontera->obtenerCursor();
			}
			Frontera->siguienteMomento();
		}
		Explorados->cursorAlPrincipio();
		for (contador=0; contador < (Explorados->longitud());contador++)
		{
			if(TorresHanoiXesIgualQueTorresHanoiY(Actual, Explorados->obtenerMomento()))
			{
				return Explorados->obtenerCursor();
			}
			Explorados->siguienteMomento();
		}
		return NULL;
	}

	NodoLista * buscarNodosIgualesEnListas(ListaTorreshanoi *FronteraA, ListaTorreshanoi *ExploradosA, ListaTorreshanoi *FronteraB, ListaTorreshanoi *ExploradosB)
	{
		int contadorA, contadorB;
		FronteraA->cursorAlPrincipio();
		for (contadorA=0; contadorA < (FronteraA->longitud());contadorA++)
		{
			FronteraB->cursorAlPrincipio();
			for (contadorB=0; contadorB < (FronteraB->longitud());contadorB++)
			{
				if(TorresHanoiXesIgualQueTorresHanoiY(FronteraA->obtenerMomento(), FronteraB->obtenerMomento()))
				{
					return FronteraA->obtenerCursor();
				}
				FronteraB->siguienteMomento();
			}
			ExploradosB->cursorAlPrincipio();
			for (contadorB=0; contadorB < (ExploradosB->longitud());contadorB++)
			{
				if(TorresHanoiXesIgualQueTorresHanoiY(FronteraA->obtenerMomento(), ExploradosB->obtenerMomento()))
				{
					return FronteraA->obtenerCursor();
				}
				ExploradosB->siguienteMomento();
			}
			FronteraA->siguienteMomento();
		}
		return NULL;
	}

	void PosiblesJugadas(NodoLista *Actual, ListaTorreshanoi *Frontera, ListaTorreshanoi *Explorados)
	{
		TorresHanoi * Jugada;
		NodoLista * Temporal;

		if (Actual->Momento.CheckDeTorreAaTorreB())
		{
			Jugada = new TorresHanoi;
			(*Jugada) = Actual->Momento;
			Jugada->MoverDeTorreAaTorreB();
			if ((!existeNodoEnLista(*Jugada, Frontera))&&((!existeNodoEnLista(*Jugada, Explorados))))
				Frontera->insertarAlPrincipio(*Jugada, (Actual->profundidad)+1, Actual);
			else
			{
				Temporal=buscarNodoEnListas(*Jugada,Frontera,Explorados);
				if ((Actual->profundidad)+1<Temporal->profundidad)
				{
					Temporal->profundidad=(Actual->profundidad)+1;
					Temporal->padre=Actual->padre;
				}else
					delete Jugada;
			}
		}

		if (Actual->Momento.CheckDeTorreAaTorreC())
		{
			Jugada = new TorresHanoi;
			(*Jugada) = Actual->Momento;
			Jugada->MoverDeTorreAaTorreC();
			if ((!existeNodoEnLista(*Jugada, Frontera))&&((!existeNodoEnLista(*Jugada, Explorados))))
				Frontera->insertarAlPrincipio(*Jugada, (Actual->profundidad)+1, Actual);
			else
			{
				Temporal=buscarNodoEnListas(*Jugada,Frontera,Explorados);
				if ((Actual->profundidad)+1<Temporal->profundidad)
				{
					Temporal->profundidad=(Actual->profundidad)+1;
					Temporal->padre=Actual->padre;
				}else
					delete Jugada;
			}
		}

		if (Actual->Momento.CheckDeTorreBaTorreA())
		{
			Jugada = new TorresHanoi;
			(*Jugada) = Actual->Momento;
			Jugada->MoverDeTorreBaTorreA();
			if ((!existeNodoEnLista(*Jugada, Frontera))&&((!existeNodoEnLista(*Jugada, Explorados))))
				Frontera->insertarAlPrincipio(*Jugada, (Actual->profundidad)+1, Actual);
			else
			{
				Temporal=buscarNodoEnListas(*Jugada,Frontera,Explorados);
				if ((Actual->profundidad)+1<Temporal->profundidad)
				{
					Temporal->profundidad=(Actual->profundidad)+1;
					Temporal->padre=Actual->padre;
				}else
					delete Jugada;
			}
		}

		if (Actual->Momento.CheckDeTorreBaTorreC())
		{
			Jugada = new TorresHanoi;
			(*Jugada) = Actual->Momento;
			Jugada->MoverDeTorreBaTorreC();
			if ((!existeNodoEnLista(*Jugada, Frontera))&&((!existeNodoEnLista(*Jugada, Explorados))))
				Frontera->insertarAlPrincipio(*Jugada, (Actual->profundidad)+1, Actual);
			else
			{
				Temporal=buscarNodoEnListas(*Jugada,Frontera,Explorados);
				if ((Actual->profundidad)+1<Temporal->profundidad)
				{
					Temporal->profundidad=(Actual->profundidad)+1;
					Temporal->padre=Actual->padre;
				}else
					delete Jugada;
			}
		}

		if (Actual->Momento.CheckDeTorreCaTorreA())
		{
			Jugada = new TorresHanoi;
			(*Jugada) = Actual->Momento;
			Jugada->MoverDeTorreCaTorreA();
			if ((!existeNodoEnLista(*Jugada, Frontera))&&((!existeNodoEnLista(*Jugada, Explorados))))
				Frontera->insertarAlPrincipio(*Jugada, (Actual->profundidad)+1, Actual);
			else
			{
				Temporal=buscarNodoEnListas(*Jugada,Frontera,Explorados);
				if ((Actual->profundidad)+1<Temporal->profundidad)
				{
					Temporal->profundidad=(Actual->profundidad)+1;
					Temporal->padre=Actual->padre;
				}else
					delete Jugada;
			}
		}

		if (Actual->Momento.CheckDeTorreCaTorreB())
		{
			Jugada = new TorresHanoi;
			(*Jugada) = Actual->Momento;
			Jugada->MoverDeTorreCaTorreB();
			if ((!existeNodoEnLista(*Jugada, Frontera))&&((!existeNodoEnLista(*Jugada, Explorados))))
				Frontera->insertarAlPrincipio(*Jugada, (Actual->profundidad)+1, Actual);
			else
			{
				Temporal=buscarNodoEnListas(*Jugada,Frontera,Explorados);
				if ((Actual->profundidad)+1<Temporal->profundidad)
				{
					Temporal->profundidad=(Actual->profundidad)+1;
					Temporal->padre=Actual->padre;
				}else
					delete Jugada;
			}
		}
	}
};