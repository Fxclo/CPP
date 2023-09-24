all:	ImageNG.o 
		g++ -Wall Test1.cpp ImageNG.o -o Test1
ImageNG.o:	
		g++ -Wall ImageNG.cpp -c
clean:	
		rm -f *.o