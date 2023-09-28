#ifndef VECTOR_SANDBOX_VECTOR_H
#define VECTOR_SANDBOX_VECTOR_H

#include "iterators/iterator.cpp"

template <typename T>
class DoubleLinkedListIterator;

template <typename T>
class DoubleLinkedList {
		friend class DoubleLinkedListIterator<T>;

		struct Link {
			Link *prev, *next;
			T *data;

			Link(Link *_prev, Link *_next, T *_data) {
				data = _data;
				prev = _prev;
				next = _next;
			}

		};

		Link *head, *tail;
		int _size;

	public:
		DoubleLinkedList() {
			head = 0;
			tail = 0;
			_size = 0;
		}

		int size() {
			return _size;
		}

		void addToEnd(T *data) {
			_size++;
			if (head == 0 && tail == 0) {
				Link *tmp = new Link(0, 0, data);
				head = tmp;
				tail = tmp;
				return;
			} 
			Link *newL = new Link(tail, 0, data);
			tail->next = newL;
			tail = newL;
		}

		void addToStart(T *data) {
			_size++;
			if (head == 0 && tail == 0) {
				Link *tmp = new Link(0,0, data);
				head = tmp;
				tail = tmp;
				return;
			}
			Link *newL = new Link(0, head, data);
			head->prev = newL;
			head = newL;
		}

		T *pop() {
			_size--;
			if (head == tail) {
				T *data = tail->data;
				delete tail;
				tail = 0;
				head = 0;
				return data;
			}
			Link *tmp = tail->prev;
			tmp->next = 0;
			T *data = tail->data;
			delete tail;
			tail = tmp;
			return data;
		}

		T *popStart() {
			_size--;
			if (head == tail) {
				T *data = tail->data;
				delete tail;
				tail = 0;
				head = 0;
				return data;
			}
			Link *tmp = head->next;
			tmp->prev = 0;
			T *data = head->data;
			delete head;
			head = tmp;
			return data;
		}

		Iterator<T> *iterator() {
			return new DoubleLinkedListIterator<T>(head);
		}


		~DoubleLinkedList() {
			Link *pointer = head;
			while (pointer != 0) {
				delete pointer->data;
				Link *tmp = pointer;
				pointer = pointer->next;
				delete tmp;
			}
		}

};

template <class T> 
class DoubleLinkedListIterator : public Iterator<T> {

	typename DoubleLinkedList<T>::Link *link, *prev;

	public: 
		DoubleLinkedListIterator(typename DoubleLinkedList<T>::Link *_link) {
			link = _link;
		}

		bool hasNext()  {
			return link != 0; 
		}

		T *getNext() {
			prev = link;
			link = link->next;
			return prev->data;
		}

		void remove() {
			// TODO pointers
			delete prev->data;
			delete prev;
		}

		~DoubleLinkedListIterator() {
		}

};

#endif
