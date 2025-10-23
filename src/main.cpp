#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <nlohmann/json.hpp>

std::ifstream reader;
std::ofstream writer;
std::string filename;
std::string target;
bool targetSet = false;
using json = nlohmann::json;
json j;

int main(int argc, char* argv[]) {
	if (argc >= 2) {
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
		std::cout << "target filename >> ";
		std::cin >> target;
		targetSet = true;
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
	if (argc > 2 and std::string(argv[2]) == "-t") {
		writer.open(std::string(argv[3]));
		if (writer.fail()) {
			std::cerr << "writer failed, writing to 'extract" << filename << "'\n";
			targetSet = false;
		}
	} else {
		if (argc == 3) {
			std::cout << "target filename >> ";
			std::cin >> target;
			targetSet = true;
		}
	}
	if (targetSet and not writer.is_open()) {
		writer.open(target);
	} else {
		if (not writer.is_open())
			writer.open("extract" + filename);
	}
	if (writer.bad()) {
		std::cout << "writer failed";
		return EXIT_FAILURE;
	}
	writer << std::setw(4) << j;
	writer.close();
	return 0;
}