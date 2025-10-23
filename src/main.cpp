#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <nlohmann/json.hpp>

std::ifstream reader;
std::ofstream writer;
std::string filename;
using json = nlohmann::json;
json j;

int main(int argc, char* argv[]) {
	if (argc == 2) {
		reader.open(std::string(argv[1]));
		if (reader.fail()) {
			std::cout << "reader failed";
			return EXIT_FAILURE;
		} else {
			filename = std::string(argv[1]);
		}
	} else {
		std::cout << "filename >> ";
		std::cin >> filename;
		reader.open(filename);
		if (reader.fail()) {
			std::cout << "reader failed" << '\n';
			return EXIT_FAILURE;
		}
	}
	try {
		j = json::parse(reader);
	} catch (json::parse_error& e) {
		std::cout << "invalid json" << '\n';
		throw(e);
		return EXIT_FAILURE;
	}
	writer.open("extract" + filename);
	writer << std::setw(4) << j;
	return 0;
}