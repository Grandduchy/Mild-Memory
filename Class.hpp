#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <random>
#include "StandardEntries.hpp"
using std::string;

class DataEntries {
	using entry_ptr = std::unique_ptr < const std::array<const char*, sESize >>;
	using entry_array = std::array<const char*, sESize>;
public:
	DataEntries(const std::array<const char*, sESize>& arr) : entries(&arr) {};

	void addEntries(std::vector<string>& vec);
	std::vector<string> returnEntries(const int& i) const;
	~DataEntries();
private:
	entry_ptr entries;
	std::unique_ptr<std::vector<string>> new_entries;
};

void DataEntries::addEntries(std::vector<string>&vec) {
	new_entries.reset(&vec);
}
std::vector<string> DataEntries::returnEntries(const int& entry_count) const {
	std::default_random_engine eng(time(0));
	std::uniform_int_distribution<int> roll(1, sESize  + ( new_entries == nullptr ? 0 :  new_entries->size()  )     );
	std::vector<string> return_entry;
	for (int x = entry_count; x > 0; x--) {
		int rn = roll(eng);
		try {
			if (rn <= sESize) {
				if (std::find(return_entry.begin(), return_entry.end(), entries->at(rn-1)) == return_entry.end())//here
					return_entry.push_back(entries->at(rn-1));
				else
					x--;
			}
			else {
				if (std::find(return_entry.begin(), return_entry.end(), new_entries->at(rn-1)) == return_entry.end())
					return_entry.push_back(new_entries->at(rn-1));
				else
					x--;
			}
		}
		catch (std::exception& e) { 
			rn = roll(eng); //retry with different values
			int x = entry_count - return_entry.size();
			continue;
		}
		
	}
	return return_entry;
}

DataEntries::~DataEntries() {
	entries.release(); // dont delete static members 
	new_entries.release(); // just remove the ownership
}
