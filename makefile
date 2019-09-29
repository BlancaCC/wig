wig.out: wig.cpp sistemaCarpetas.h open.h configuration.h initial.h end.h info.h statistics.h lazyGit.out git.h tools.h help.h remove.h
	g++ wig.cpp -o wig.out

lazyGit.out: lazyGit.cpp tools.h configuration.h
	g++ lazyGit.cpp -o lazyGit.out
	cp $@ /home/blanca/repositorios/escriturias/


clean:
	rm -rf *.out *~

remove_all:
	rm -rf *.out *~ 2*

file_clean:
	rm 2*

open:
	./wig.out open tomatico

fin:
	./wig.out end tomatico

info:
	./wig.out info -a
	./wig.out info -e
	./wig.out info -open

