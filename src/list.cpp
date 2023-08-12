
#ifndef LIST_H
#define LIST_H

template<class T>
class List {

	unsigned int size;
	unsigned int allowedSize;
	bool owner;
	T **data;

	public:
		void add(T *_data) {
			if (size >= allowedSize) {
				resize(size + 1);
			}
			data[size] = _data;
			size++;
		}

		List(bool _owner =true) {
			owner = _owner;
			data = 0;
			size = 0;
			allowedSize = 0;
		}

		T& operator[](int index) const {
			return *data[index];
		}

		~List() {
			if (owner) {
				for (int i = 0; i < allowedSize; i++) {
					delete data[i];
				}
			}
			delete[] data;
		}


	private:
		void resize(unsigned int newSize) {
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
};

/* template<class T*> */



#endif

