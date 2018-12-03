/*#pragma once
#include "Movie.h"

typedef Movie TElement;
class DynamicVector
{
private:
	TElement * elems;
	int size;
	int cap;
public:
	// default constructor for a DynamicVector
	DynamicVector(int cap = 10);

	// copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& v);
	~DynamicVector();

	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& v);

	DynamicVector& operator+(const Movie& m);

	// Adds an element to the dynamicvector
	void add(const TElement& e);

	// Returns the position of the element e in elems and -1 otherwise
	//int find(const TElement& e);

	// Returns the position of the element in elems that has the same title as e and -1 otherwise
	int findByTitle(const TElement& e);

	// Removes an element from the dynamic vector
	void remove(const TElement& e);

	// Updates the element from the list of movies that has the same title
	// as the given element by filling the fields of that element with the
	// values found in the new elements fields
	void update(const TElement& e);

	// Gets the lenght of the dynamicvector
	int getSize() const;

	int getCapacity() const;

	// Returns the vector elems
	TElement* getAllElems() const;

	// Resizes the dynamicvector by enlargening its capacity with a scale given by the factor
	void resize(double factor = 2);

};

DynamicVector& operator+(const TElement& m, DynamicVector& v);
*/
