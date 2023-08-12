#ifndef VECTOR_SANDBOX_ITERATOR_H
#define VECTOR_SANDBOX_ITERATOR_H


template <class T>
class Iterator {

	public: 
		Iterator() {};
		virtual bool hasNext() = 0;
		virtual T *getNext() = 0;
		virtual void remove() = 0;
		virtual ~Iterator() {};
};

#endif
