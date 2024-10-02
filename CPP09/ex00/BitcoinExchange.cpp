#include "BitcoinExchange.hpp"
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <limits>

BitcoinExchange::BitcoinExchange(std::ifstream &databaseFile)
{
    loadDatabase(databaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : priceData(other.priceData) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        priceData = other.priceData;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(std::ifstream &db)
{
    std::string line;
    std::getline(db, line);

    while (std::getline(db, line))
    {
        std::istringstream iss(line);
        std::string date, priceStr;
        if (std::getline(iss, date, ',') && std::getline(iss, priceStr))
        {
            float price = static_cast<float>(std::atof(priceStr.c_str()));
            priceData[date] = price;
        }
    }
}

void BitcoinExchange::processInput(std::ifstream &inputFile)
{
    std::string line;
    std::getline(inputFile, line);

    while (std::getline(inputFile, line))
    {
        line.erase(0, line.find_first_not_of(" \t\n\r"));
        line.erase(line.find_last_not_of(" \t\n\r") + 1);

        if (line.empty())
            continue;

        size_t separator = line.find('|');
        if (separator == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, separator);
        std::string valueStr = line.substr(separator + 1);

        date.erase(0, date.find_first_not_of(" \t\n\r"));
        date.erase(date.find_last_not_of(" \t\n\r") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t\n\r"));
        valueStr.erase(valueStr.find_last_not_of(" \t\n\r") + 1);

        if (!validateDateFormat(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (!validateValue(valueStr))
        {
            continue;
        }
        evaluateQuery(date, valueStr);
    }
}

// Evaluate a single query
void BitcoinExchange::evaluateQuery(const std::string &date, const std::string &valueStr)
{
    float value = static_cast<float>(std::atof(valueStr.c_str()));

    std::map<std::string, float>::const_iterator it = priceData.lower_bound(date);

    if (it != priceData.end() && it->first == date)
    {
        std::cout << date << " => " << value << " = " << it->second * value << std::endl;
    }
    else if (it != priceData.begin())
    {
        --it;
        std::cout << date << " => " << value << " = " << it->second * value << std::endl;
    }
    else
    {
        std::cerr << "Error: Date " << date << " is before available data." << std::endl;
    }
}

bool BitcoinExchange::validateDateFormat(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;

    return true;
}

bool BitcoinExchange::validateValue(const std::string &valueStr) const
{
    if (valueStr.empty() || valueStr.find_first_not_of("0123456789.-") != std::string::npos)
    {
        std::cerr << "Error: bad input format." << std::endl;
        return false;
    }

    float value = static_cast<float>(std::atof(valueStr.c_str()));
    if (value < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}
