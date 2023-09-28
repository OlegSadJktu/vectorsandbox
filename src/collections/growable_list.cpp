#include "growable_list.h"

template<typename T>
void GrowableList<T>::add(T *_data) {
	if (size >= allowedSize) {
		resize(size + 1);
	}
	data[size] = _data;
	size++;
}

template<typename T>
GrowableList<T>::GrowableList(bool _owner) {
	owner = _owner;
	data = 0;
	size = 0;
	allowedSize = 0;
}

template<typename T>
T& GrowableList<T>::operator[](int index) const {
	return *data[index];
}

template<typename T>
GrowableList<T>::~GrowableList() {
	if (owner) {
		for (int i = 0; i < allowedSize; i++) {
			delete data[i];
		}
	}
	delete[] data;
}

template<typename T>
void GrowableList<T>::resize(unsigned int newSize) {
	unsigned int tmpSize = allowedSize == 0 ? 8 : allowedSize;
	while (tmpSize < newSize) tmpSize *= 2;
	T **tmp = new T*[tmpSize];
	for (int i = 0; i < size; i++) {
		tmp[i] = data[i];
	}
	delete[] data;
	allowedSize = tmpSize;
	data = tmp;
}





