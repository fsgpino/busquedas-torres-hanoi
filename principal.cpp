#define LIMPIARPANTALLA       cout << "\33[2J" << "\33[2J"
#define LUGAR(x,y)   cout << "\033[" << (x) << ";" << (y) << "H"

#include <iostream>
#include <stdlib.h>
#include <cstdio>

#include "FuncionesBusqueda.hpp"

using namespace std;
using namespace Hanoi;

int main()
{
	int opcion; /*variable para opciones del menu */
	char seguro;
	int discos;
	char TorreInicio, TorreFinal;
	TorresHanoi Origen, Destino;

	/* Menu de opciones del programa  */
	do
	{
		do
		{
			opcion = menu();
		} while (opcion < 0 || opcion > 3); /* obliga a que la opcion sea correcta */

		if (opcion !=0)
		{
			do
			{
				do
				{
					LIMPIARPANTALLA;
					LUGAR(1,1);

					cout << " >* Introduzca un número de discos a meter en la torre (mínimo 3): ";
					cin >> discos;
					getchar();

				} while (discos<3);

				do
				{
			 	 	LIMPIARPANTALLA;
					LUGAR(1,1);

					cout << " >* Introduzca la torre que contendrá los discos al principio (a/b/c): ";
					scanf ("%c", &TorreInicio);
					getchar();

					cout << " >* Introduzca la torre que contendrá los discos al final (a/b/c): ";
					scanf ("%c", &TorreFinal);
					getchar();

				}while ((((TorreInicio!='a')&&(TorreInicio!='b')&&(TorreInicio!='c')))||((TorreFinal!='a')&&(TorreFinal!='b')&&(TorreFinal!='c'))||(TorreInicio==TorreFinal));

				// PROCESO DE CARGA DE DISCOS EN TORRE ORIGEN INTRODUCIDA POR EL USUARIO
				Origen.vaciarTorres();
				switch (TorreInicio)
				{
					case 'a':
						Origen.ponerXDiscosEnTorreA(discos);
						break;
					case 'b':
						Origen.ponerXDiscosEnTorreB(discos);
						break;
					case 'c':
						Origen.ponerXDiscosEnTorreC(discos);
						break;
				}
				// FIN DE PROCESO DE CARGA DE DISCOS EN TORRE ORIGEN INTRODUCIDA POR EL USUARIO

				// PROCESO DE CARGA DE DISCOS EN TORRE DESTINO INTRODUCIDA POR EL USUARIO
				Destino.vaciarTorres();
				switch (TorreFinal)
				{
					case 'a':
						Destino.ponerXDiscosEnTorreA(discos);
						break;
					case 'b':
						Destino.ponerXDiscosEnTorreB(discos);
						break;
					case 'c':
						Destino.ponerXDiscosEnTorreC(discos);
						break;
				}
				// FIN DE PROCESO DE CARGA DE DISCOS EN TORRE DESTINO INTRODUCIDA POR EL USUARIO

				LIMPIARPANTALLA;
				LUGAR(1,1);

				cout << " * El momento origen de las torres Hanoi será: " << endl;
				cout << Origen << endl;
				cout << " * El momento destino de las torres Hanoi será: " << endl;
				cout << Destino << endl;

				cout << endl <<" >* Pulse una tecla para continuar...";
		    	getchar();

				do
				{
					LIMPIARPANTALLA;
					LUGAR(1,1);

					if (discos>9)
						cout << " !* La altura de la torre es demasiado grande, pueden surgir errores." << endl << " !* Se recomienda una altura de torre menor que 10." << endl << endl;

					cout << " >* ¿Está seguro de que desea empezar? (s/n): ";
					scanf("%c", &seguro);
					getchar();

					if (seguro=='n')
						opcion=-1;

				} while(seguro!='s'&&seguro!='n'); /* obliga a que la opcion sea correcta */

			}while (seguro==0);

		}

		switch (opcion)
		{
		  case 1: /* Realizar busqueda en Profundidad */
		  {
		  	LIMPIARPANTALLA;
			LUGAR(1,1);

		    BusquedaEnProfundidad(Origen, Destino);

		    cout << endl <<" >* Pulse una tecla para continuar...";
		    getchar();

		    break;
		  }
		  case 2: /* Realizar busqueda en Anchura */
		  {
		  	LIMPIARPANTALLA;
			LUGAR(1,1);

		    BusquedaEnAnchura(Origen, Destino);

		    cout << endl <<" >* Pulse una tecla para continuar...";
		    getchar();

		    break;
		  }	 
		  case 3: /* Realizar busqueda Bidireccional */
		  {
		  	LIMPIARPANTALLA;
			LUGAR(1,1);

		    BusquedaBidireccional(Origen, Destino);

		    cout << endl <<" >* Pulse una tecla para continuar...";
		    getchar();

		    break;	  
		  }
		}

	} while (opcion != 0);

 	LIMPIARPANTALLA;
  	LUGAR(1,1);

	return 0;
}