/*#include "DynamicVector.h"

DynamicVector::DynamicVector(int cap)
{
	this->size = 0;
	this->cap = cap;
	this->elems = new TElement[cap];
}

DynamicVector::DynamicVector(const DynamicVector& v)
{
	this->size = v.size;
	this->cap = v.cap;
	this->elems = new TElement[this->cap];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

DynamicVector::~DynamicVector()
{
	delete[] this->elems;
}

DynamicVector& DynamicVector::operator=(const DynamicVector& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->cap = v.cap;
	delete[] this->elems;
	this->elems = new TElement[this->cap];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
	return *this;
}

DynamicVector& DynamicVector::operator+(const TElement& m)
{
	if (this->size == this->cap)
		this->resize();
	this->elems[this->size] = m;
	this->size++;
	return *this;
}

int DynamicVector::find(const TElement& e)
{
for (int i = 0; i < this->size; i++)
if ((this->elems[i].getTitle() == e.getTitle()) && (this->elems[i].getGenre() == e.getGenre()) && (this->elems[i].getYear() == e.getYear()) && (this->elems[i].getLikes() == e.getLikes()) && (this->elems[i].getTrailer() == e.getTrailer()) )
return i;
return -1;
}


int DynamicVector::findByTitle(const TElement& e)
{
	for (int i = 0; i < this->size; i++)
		if (this->elems[i].getTitle() == e.getTitle())
			return i;
	return -1;
}

void DynamicVector::add(const TElement& e)
{


	if (this->size == this->cap)
		this->resize();
	this->elems[this->size] = e;
	this->size++;

}

void DynamicVector::remove(const TElement& e)
{
	if (this->findByTitle(e) == -1)
		return;

	DynamicVector el;
	el.size = this->size - 1;

	int p = 0;

	if (this->size == 0)
		return;

	for (int i = 0; i < findByTitle(e); i++)
		el.elems[p++] = this->elems[i];

	for (int i = findByTitle(e) + 1; i < this->size; i++)
		el.elems[p++] = this->elems[i];

	this->size = el.size;
	this->elems = new TElement[this->cap];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = el.elems[i];
}

void DynamicVector::update(const TElement& e)
{
	if (this->findByTitle(e) == -1)
		return;
	this->elems[this->findByTitle(e)].setGenre(e.getGenre());
	this->elems[this->findByTitle(e)].setYear(e.getYear());
	this->elems[this->findByTitle(e)].setLikes(e.getLikes());
	this->elems[this->findByTitle(e)].setTrailer(e.getTrailer());

}

void DynamicVector::resize(double factor)
{
	this->cap *= static_cast<int>(factor);
	TElement* el = new TElement[this->cap];
	for (int i = 0; i < this->size; i++)
		el[i] = this->elems[i];
	delete[] this->elems;
	this->elems = el;
}

TElement* DynamicVector::getAllElems() const
{
	return this->elems;
}

int DynamicVector::getSize() const
{
	return this->size;
}

int DynamicVector::getCapacity() const
{
	return this->cap;
}

DynamicVector& operator+(const TElement& m, DynamicVector& v)
{
	v.add(m);
	return v;
}
*/