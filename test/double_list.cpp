#include <collections/double_list.cpp>
#include "test.cpp"

class DoubleListTest: public Test {
	private: 
		bool result;
		int size;

	public:
		DoubleListTest(int _size = 1000) {
			size = _size;
			result = true;
		}

		const char* getName() {
			return "DoubleListTest";
		}

		bool getResult() {
			return result;
		}

		void test() {

		}

};
