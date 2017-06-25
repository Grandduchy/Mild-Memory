#include <thread>
#include <iostream>
#include "StandardEntries.hpp"
#include "Functions.hpp"
#include "Class.hpp"
 using std::cout; using std::cin; using std::endl; using std::flush;


int main() {
	cout << "\t\tMild and Prospective memory entries" << endl;
	runProgram();
	cout << "Program exiting in 20 seconds. " << endl;
	std::this_thread::sleep_for(std::chrono::seconds(20));
	return 0;
}
