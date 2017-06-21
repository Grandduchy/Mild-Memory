#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <random>
#include <iostream>
using std::vector; using std::string; using std::cout; using std::cin; using std::endl; using std::flush;

int main() {
	std::cout << "Make sure you have a file named 'LD.txt' containing all the goals\n" <<
	"Also make sure to have another file named 'LDToday.txt' where we will put the goals of today.\n" <<
	"Press enter to begin."<< std::endl;
	std::cin.ignore();
	//getting time//
	struct tm tms;
	struct tm* tmsPTR = &tms;
	time_t tme;
	time_t* tmePTR = &tme;
	time(&tme);
	localtime_s(tmsPTR, tmePTR);
	char l[26];
	asctime_s(l, sizeof l , tmsPTR);
	//getting time//
	std::ifstream Ld("LD.txt");
	vector<string> goals;
	string goal;
	while (getline(Ld, goal)) {
	goals.push_back(goal);
	}
	std::ofstream oLd("LDToday.txt");
	int x = 1;
	oLd << l;
	srand(time(NULL));
	while (x != 5) {
	int rdm = rand() % (goals.size()-1);
	oLd << " " << x << ". "<< goals[rdm] << std::endl;
	x++;
	}
	std::ifstream main("newdata.txt");
	vector<string> g;
	string l;
	while (getline(main, l)) {
		g.push_back(l);
	}
	cout << g.size() << endl;
	return 0;
}