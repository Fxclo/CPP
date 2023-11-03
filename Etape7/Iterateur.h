#ifndef ITERATEUR_H
#define ITERATEUR_H

template<class T> 
struct Cellule;

template<class T>
class ArrayList;

template<class T>
class Iterateur 
{
	private:

	ArrayList<T>& liste;
    Cellule<T> *pCur;

	public:

    Iterateur(ArrayList<T>& list);
    void reset();
    bool end() const;
    bool operator++();
    bool operator++(int);
    operator T();
    T& operator&();
};


#endif