INT=TrajetC.h TrajetS.h Trajet.h TTraj.h LChaine.h Maillon.h Catalogue.h Pile.h Sauvegarde.h
REAL=$(INT:.h=.cpp)
OBJ=$(INT:.h=.o)
EXE=trajet
LIBS=
CPPFLAGS= -Wall -ansi -pedantic -std=c++11
DMAP= #-DMAP
ECHO=@echo

%.o:%.cpp
	$(ECHO) "compilation de $<"
	g++ $(CPPFLAGS) $(DMAP) -c $< -o $@

$(EXE):$(OBJ)
	g++ -o $(EXE) $(OBJ) $(LIBS)

clean:
	rm -f *.o $(EXE)
