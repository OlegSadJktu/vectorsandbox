#ifndef LIST_H
#define LIST_H

template<typename T>
class GrowableList {

	unsigned int size;
	unsigned int allowedSize;
	bool owner;
	T **data;

	public:
		void add(T *_data) ;

		GrowableList(bool _owner =true) ;

		T& operator[](int index) const ;

		~GrowableList();


	private:
		void resize(unsigned int newSize);
};

/* #include "growable_list.cpp" */

#endif
