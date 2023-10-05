.SILENT:

EditionLiens = g++ Test3.cpp -o Test3 MyQT.o ImageNG.o Dimension.o -lSDL -lpthread -Wl,-O1 -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++ /usr/lib64/libQt5Widgets.so /usr/lib64/libQt5Gui.so /usr/lib64/libQt5Core.so /usr/lib64/libGL.so

CompilationMyQT = g++ -c MyQT.cpp -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB -I. -isystem /usr/include/qt5 -isystem /usr/include/qt5/QtWidgets -isystem /usr/include/qt5/QtGui -isystem /usr/include/qt5/QtCore -I. -I. -I/usr/lib64/qt5/mkspecs/linux-g++

CompilationImageNG = g++ -Wall ImageNG.cpp -c

CompilationDimension = g++ -Wall Dimension.cpp -c

SuppFile = rm -f

Test3:	Test3.cpp ImageNG.o MyQT.o Dimension.o
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

clean:	
		$(SuppFile) *.o

clobber:	clean
		$(SuppFile) Test3
		echo Suppression faite !
		
