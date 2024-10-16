#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
public:
    BitcoinExchange(std::ifstream &databaseFile);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void processInput(std::ifstream &inputFile);

private:
    std::map<std::string, float> priceData;

    void loadDatabase(std::ifstream &db);
    void evaluateQuery(const std::string &date, const std::string &valueStr);
    bool validateDateFormat(const std::string &date) const;
    bool validateValue(const std::string &valueStr) const;
    bool isLeapYear(int year) const;
};

#endif




