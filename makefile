
HOME = .
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
BIN = $(HOME)/bin
OBJ = $(HOME)/obj
LIB = $(HOME)/lib

$(BIN)/wig.out: $(SRC)/wig.cpp $(INCLUDE)/sistemaCarpetas.h $(INCLUDE)/open.h $(INCLUDE)/configuration.h $(INCLUDE)/initial.h $(INCLUDE)/end.h \
	             $(INCLUDE)/info.h $(INCLUDE)/statistics.h $(INCLUDE)/git.h $(INCLUDE)/tools.h $(INCLUDE)/help.h $(INCLUDE)/remove.h
	g++ $(SRC)/wig.cpp -o $(BIN)/wig.out -I$(INCLUDE)

$(BIN)/lazyGit.out: $(SRC)lazyGit.cpp $(INCLUDE)tools.h $(INCLUDE)configuration.h
	g++ $(SRC)lazyGit.cpp -o $(BIN)lazyGit.out -I$(INCLUDE)
	-cp $@ ($HOME)/repositorios/escriturias/


clean:
	-rm -rf $(BIN)/*.out *~

remove_all:
	-rm -rf $(BIN)/*.out *~ 2*

file_clean:
	-rm 2*

open:
	-./wig.out open tomatico

fin:
	-./wig.out end tomatico

info:
	-./wig.out info -a
	-./wig.out info -e
	-./wig.out info -open
