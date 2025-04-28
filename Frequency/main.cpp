#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cstdint>
#include <algorithm>
#include <iomanip>


void syntax()
{
    std::cout 
        << "SYNTAX:\n\n"
        << "frequency <input file> <output file>\n\n"
        << "The program computes the frequency of every byte "
        << "in the input file\n";
    exit(EXIT_FAILURE);
}

void error(const std::string& msg)
{
    std::cout << "ERROR: " << msg << "\n";
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        syntax();
    }
    std::string input_filename = argv[1];
    std::string output_filename = argv[2];

    std::ifstream is(input_filename, std::ios::binary);
    if (!is) {
        error("Cannot open file " + input_filename);
    }

    std::array<int64_t, 256> count{ 0 };
    while (true) {
        int val = is.get();
        if (val == EOF) {
            break;
        }
        count[val]++;
    }

    std::ofstream os(output_filename);
    if (!os) {
        error("Cannot open file " + output_filename);
    }
    for (size_t i = 0; i < 256; ++i) {
        if (count[i] > 0) {
            os << std::hex 
                << std::setw(2)
                << std::setfill('0')
                << i 
                << std::dec;
            os << '\t' << count[i] << '\n';
        }
    }

    return EXIT_SUCCESS;
}