#include "test.cpp"
#include <collections/growable_list.h>
#include <random>

class GrowableListTest: public Test {

		bool result;
		int size;

	public :
		GrowableListTest(int _size = 1000) {
			size = _size;
			result = true;
		}

		const char* getName() {
			return "GrowableListTest";
		}


		bool getResult() {
			return result;
		}

		void test() {
			GrowableList<int> list;
			int* arr = new int[size];
			for (int i = 0; i < size; i++ ) {
				arr[i] = std::rand();
			}

			for (int i = 0; i < size; i++ ) {
				list.add(new int(arr[i]));
			}
			/* arr[5] += 1; */

			for (int i = 0; i < size; i++ ) {
				auto fromArr = arr[i];
				auto fromList = list[i];
				if (fromList != fromArr) {
					result = false;
				}
			}

			delete[] arr;
		}

};
