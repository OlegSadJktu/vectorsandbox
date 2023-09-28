#include <stdio.h>
#include <signal.h>
#include "double_list.cpp"
#include "test.cpp"
#include "growable_list.cpp"
#include "memcpy.cpp"

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_RESET   "\x1b[0m"


void segfault_sigaction(int signal, siginfo_t *si, void *arg) {
    printf("Caught segfault at address %p\n", si->si_addr);
    exit(0);
}

int main() {
	printf(COLOR_YELLOW "START\n" COLOR_YELLOW);
	/* Test* a = new GrowableListTest(); */
	Test *tests[] = {
		new DoubleListTest(10000000),
		new GrowableListTest(10000000),
		new MemcpyTest(),
	};
	auto size = sizeof(tests) / sizeof(*tests);

	int counter = 0;
	struct sigaction sa;
	memset(&sa, 0, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = segfault_sigaction;
	sa.sa_flags =  SA_SIGINFO;
	sigaction(SIGSEGV, &sa, NULL);


	for (unsigned long i = 0; i < size; i++) {
		auto test = tests[i];
		test->test();
		bool res = test->getResult();
		if (res) {
			counter += 1;
		}
		if (res) {
			printf(COLOR_GREEN "Test passed ");
		} else {
			printf(COLOR_RED "Test failed ");
		}
		printf("[%i/%li] ", counter, size);
		printf("%s\n", test->getName());
	}
	printf("\n");

	if (counter == 0) {
		printf(COLOR_RED);
	} else if (counter < size) {
		printf(COLOR_YELLOW);
	} else {
		printf(COLOR_GREEN);
	}

	printf("%i of %li tests passed\n", counter, size);



}
