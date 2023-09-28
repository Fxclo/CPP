.SILENT:

Test2:	Test2.cpp Dimension.o ImageNG.o
		g++ Test2.cpp Dimension.o ImageNG.o -o Test2
		echo Compilation de Test2...

ImageNG.o:	ImageNG.cpp ImageNG.h
		g++ ImageNG.cpp -c
		echo Compilation de ImageNG.o...

Dimension.o: Dimension.cpp Dimension.h
		g++ Dimension.cpp -c 
		echo Compilation de Dimension.o...

clean:	
		rm -f *.o

clobber:	clean
		rm -f Test2
		echo Les fichiers .o et Test2 ont été supprimés! 