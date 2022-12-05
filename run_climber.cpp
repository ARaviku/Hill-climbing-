#include <string>
#include"climber.h"

int main(int argc, char *argv[])
{
    std::string infilename = "input.txt";
    std::string outfilename = "output.txt";
    if (argc == 2) { 
        infilename = argv[1];
    }
    if (argc == 3) { 
        infilename = argv[1];
        outfilename = argv[2];
    }
    std::map<Coordinate, int> m;
    Coordinate start;

    read_input(m, start, infilename);

    climber_algorithm(m, start, outfilename);

    return EXIT_SUCCESS;
}
