
CPPFLAGS = -g -Wall -ansi
OBJECTS = principal.o FuncionesBusqueda.o ListasHanoi.o TorresHanoi.o

hanoi: FuncionesBusqueda.hpp ListasHanoi.hpp TorresHanoi.hpp $(OBJECTS)
	g++ -o hanoi $(OBJECTS)

principal.o: FuncionesBusqueda.hpp ListasHanoi.hpp TorresHanoi.hpp principal.cpp
	g++ -c $(CPPFLAGS) principal.cpp

FuncionesBusqueda.o: FuncionesBusqueda.hpp ListasHanoi.hpp TorresHanoi.hpp FuncionesBusqueda.cpp
	g++ -c $(CPPFLAGS) FuncionesBusqueda.cpp

ListasHanoi.o: FuncionesBusqueda.hpp ListasHanoi.hpp TorresHanoi.hpp ListasHanoi.cpp
	g++ -c $(CPPFLAGS) ListasHanoi.cpp

TorresHanoi.o: FuncionesBusqueda.hpp ListasHanoi.hpp TorresHanoi.hpp TorresHanoi.cpp
	g++ -c $(CPPFLAGS) TorresHanoi.cpp

clean:
	rm -f $(OBJECTS)
