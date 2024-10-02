#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile)
    {
        std::cerr << "Error: could not open input file." << std::endl;
        return 1;
    }

    std::ifstream btcDB("data.csv");
    if (!btcDB)
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return 1;
    }

    BitcoinExchange btc(btcDB);
    btc.processInput(inputFile);

    inputFile.close();
    btcDB.close();

    return 0;
}


