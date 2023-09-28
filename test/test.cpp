#ifndef TEST_H
#define TEST_H

class Test {

	public:
		virtual bool getResult() = 0;
		virtual void test() = 0;
		virtual const char* getName() = 0;
};

#endif
