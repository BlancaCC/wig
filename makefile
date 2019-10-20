wig: wig.cpp sistemaCarpetas.h open.h configuration.h initial.h end.h info.h statistics.h .lazyGit.out git.h tools.h help.h remove.h 
	g++ wig.cpp -o wig

.lazyGit.out: lazyGit.cpp tools.h configuration.h
	g++ lazyGit.cpp -o .lazyGit.out
	#cp $@ /home/blanca/repositorios/escriturias/


clean:
	rm -rf *.out *~ wig .lazyGit.out

remove_all:
	rm -rf *.out *~ 2* wig

file_clean:
	rm 2*

open:
	./wig open tomatico

fin:
	./wig end tomatico

info:
	./wig info -a
	./wig info -e
	./wig info -open

install: wig .lazyGit.out
	bash install.sh


unistall:
	sudo rm /usr/bin/wig
	sudo rm /usr/bin/wigit
	sudo rm $HOME/.config/wig.conf	


