.SILENT:

EditionLiens = g++ Test7.cpp -o Test7 MyQT.o ImageNG.o Dimension.o Image.o Couleur.o ImageRGB.o ImageB.o Exception.o RGBException.o XYException.o ArrayList.o Iterateur.o -lSDL -lpthread -Wl,-O1 -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so

CompilationMyQT = g++ -c MyQT.cpp -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++

CompilationImageNG = g++ -Wall ImageNG.cpp -c

CompilationDimension = g++ -Wall Dimension.cpp -c

CompilationImage = g++ -Wall Image.cpp -c

CompilationCouleur = g++ -Wall Couleur.cpp -c

CompilationImageRGB = g++ -Wall ImageRGB.cpp -c

CompilationImageB = g++ -Wall ImageB.cpp -c

CompilationException = g++ -Wall Exception.cpp -c

CompilationRGBException = g++ -Wall RGBException.cpp -c

CompilationXYException = g++ -Wall XYException.cpp -c

CompilationArrayList = g++ -Wall ArrayList.cpp -c

CompilationIterateur = g++ -Wall Iterateur.cpp -c

SuppFile = rm -f

Test7:	Test7.cpp ImageNG.o MyQT.o Dimension.o Image.o Couleur.o ImageRGB.o ImageB.o Exception.o RGBException.o XYException.o ArrayList.o Iterateur.o
		$(EditionLiens)
		echo Edition des liens...

MyQT.o:	MyQT.cpp MyQT.h
		$(CompilationMyQT)
		echo Compilation de MyQT...

ImageNG.o:	ImageNG.cpp ImageNG.h
		$(CompilationImageNG)
		echo Compilation de ImageNG.o...

Dimension.o:	Dimension.cpp Dimension.h
		$(CompilationDimension)
		echo Compilation de Dimension.o...

Image.o:	Image.cpp Image.h
		$(CompilationImage)
		echo Compilation de Image.o...

Couleur.o:	Couleur.cpp Couleur.h
		$(CompilationCouleur)
		echo Compilation de Couleur.o...

ImageRGB.o:	ImageRGB.cpp ImageRGB.h
		$(CompilationImageRGB)
		echo Compilation de ImageRGB.o...

ImageB.o:	ImageB.cpp ImageB.h
		$(CompilationImageB)
		echo Compilation de ImageB.o...

Exception.o:	Exception.cpp Exception.h
		$(CompilationException)
		echo Compilation de Exception.o...

RGBException.o:	RGBException.cpp RGBException.h
		$(CompilationRGBException)
		echo Compilation de RGBException.o...

XYException.o:	XYException.cpp XYException.h
		$(CompilationXYException)
		echo Compilation de XYException.o...

ArrayList.o:	ArrayList.cpp ArrayList.h
		$(CompilationArrayList)
		echo Compilation de ArrayList.o...

Iterateur.o:	Iterateur.cpp Iterateur.h
		$(CompilationIterateur)
		echo Compilation de Iterateur.o...

clean:	
		$(SuppFile) *.o

clobber:	clean
		$(SuppFile) Test7
		echo Suppression faite !
		
