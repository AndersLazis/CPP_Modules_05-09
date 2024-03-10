
#include "includes/BitcoinExchange.hpp"

/*
$> ./btc
Error: could not open file. $> ./btc input.txt
2011-01-03 => 3 = 0.9 2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3 2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42 2012-01-11 => 1 = 7.1
Error: too large a number. $>
*/

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string &filename)
{   
    std::string database = "data.csv";

    if(!isFileExists(filename))
    {
        throw std::runtime_error("Error: could not open " + std::string(filename) + " file.\n");
    }
    if(!isInputValid(filename))
    {
        throw std::runtime_error("Error: " + filename + " is invalid.\n"); 
    }
    if(!isFileExists(database))
    {
        throw std::runtime_error("Error: could not open " + database + " file.\n");
    }
    if(!isDatabaseValid(database))
    {
        throw std::runtime_error("Error: " + database + " is invalid.\n"); 
    }
}

BitcoinExchange::~BitcoinExchange()
{}

bool BitcoinExchange::isInputValid(std::string &filename)
{   
    std::fstream file(filename);
    if(!file)
        throw std::runtime_error("Error: could not open file.\n");
    std::string line;
    int i = 0;
    std::getline(file, line);
    if(line != "date | value")
        throw std::runtime_error("Error: no 1st line in input file.\n");
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string word;
        i = 0;
        while (ss >> word)
        {
            //std::cout << word << std::endl;
            if(!IsLineValid(word, i))
            {
                return (false);
            }
            i++;
        }
    }
    file.close();
    return (true);
}

bool BitcoinExchange::isDatabaseValid(std::string &filename)
{   
    std::fstream file(filename);
    if(!file)
        throw std::runtime_error("Error: could not open file.\n");
    std::string line;

    std::getline(file, line);
    if(line != "date,exchange_rate")
        throw std::runtime_error("Error: no 1st line in database.\n");
    while (std::getline(file, line))
    {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            throw std::runtime_error("Error: no comma found.\n");
        std::string date = line.substr(0, pos);
        //std::cout << "date: " << date << std::endl;
        if(!std::isdigit(date.at(0)) || !std::isdigit(date.at(1)) || !std::isdigit(date.at(2)) ||
            !std::isdigit(date.at(3)) || date.at(4) != '-' || !std::isdigit(date.at(5)) ||
            !std::isdigit(date.at(6)) || date.at(7) != '-' || !std::isdigit(date.at(8)) ||
            !std::isdigit(date.at(9)) || date.length() != 10)
            throw std::runtime_error("Error: bad date.\n");
        std::string rate = line.substr(pos + 1);
        double double_num;
        std::istringstream iss(rate);
        if(!(iss >> double_num))
            throw std::runtime_error("Error: bad rate.\n");
        add
       //std::cout << "rate: " << rate << std::endl;
    }
    file.close();
    return (true);
}




bool BitcoinExchange::isFileExists(std::string &filename)
{
    std::ifstream database(filename.c_str());
    if(!database.good() || database.fail() || !database.is_open())
    {
        database.close();
        return (false);
    }
    if(database.peek() == std::ifstream::traits_type::eof()) 
    {
        database.close(); 
        return (false);
    }
    database.close(); 
    return (true);
}

bool  BitcoinExchange::IsLineValid(std::string &word, int &i)
{
    std::cout << "word: [" << i  << "]" << word << std::endl;
    int int_num;
    float float_num;
    switch (i)
    {
        case 0 :
            if(!std::isdigit(word.at(0)) || !std::isdigit(word.at(1)) || !std::isdigit(word.at(2)) ||
                !std::isdigit(word.at(3)) || word.at(4) != '-' || !std::isdigit(word.at(5)) ||
                !std::isdigit(word.at(6)) || word.at(7) != '-' || !std::isdigit(word.at(8)) ||
                !std::isdigit(word.at(9)) || word.length() != 10)
            {   std::cout << "1" << std::endl;
                return (false);
            }
            break;
        case 1 :
            if(word != "|")
            {   std::cout << "2" << std::endl;
                return (false);
            }
            break;
        case 2 :
            std::istringstream iss(word);
            if((!(iss >> int_num)) && (!(iss >> float_num)) && (word != "2147483648"))
            {   std::cout << "3" << std::endl;
                return (false);
            }
            break;
    }
    return (true);
}




