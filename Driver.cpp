#include "Game.h"
#include <iostream>

using std::cout, std::cin, std::endl;

int main() {
	Game test("Setup.dat");
	test.print();
	cout << test.move(0, 2, 2, 4) << endl;
	test.print();
	return 0;
}