.SILENT:

Test1:	Test1.cpp ImageNG.o
		g++ Test1.cpp ImageNG.o -o Test1
		echo Compilation de Test2...

ImageNG.o:	ImageNG.cpp ImageNG.h
		g++ ImageNG.cpp -c
		echo Compilation de ImageNG.o...

clean:	
		rm -f *.o

clobber:	clean
		rm -f Test1
		echo Tout a été supprimé!