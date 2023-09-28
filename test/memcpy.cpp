#include "test.cpp"
#include <string.h>

class MemcpyTest: public Test {

	private:
		bool result;


	public:

		MemcpyTest() {
			result = true;
		}

		const char *getName() {
			return "MemcpyTest";
		}

		void test() {
			int offset = 2;
			int size = 10 + offset;
			int* arr = new int[size];
			for (int i = 0; i < 10; i++) {
				arr[i] = i + 1;
			}
			memmove(arr + ((unsigned int)offset), arr, 10 * sizeof(int));
			for (int i = 0; i < 10; i++) {
				if (arr[i + offset] != i + 1) {
					result = false;
				}
			}
			delete [] arr;
		}

		bool getResult() {
			return result;
		}


};
