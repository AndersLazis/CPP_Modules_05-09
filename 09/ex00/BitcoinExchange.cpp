
#include "includes/BitcoinExchange.hpp"
#include <fcntl.h>
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

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(std::string &filename) : _error(false)
{   
    std::string database = "data.csv";

    if(!isFileExists(filename))
        throw std::runtime_error("Error: could not open " + std::string(filename) + " file.\n");
    if(!isFileExists(database))
        throw std::runtime_error("Error: could not open " + database + " file.\n");
    if(!isDatabaseValid(database))
        throw std::runtime_error("Error: " + database + " is invalid.\n"); 
}


bool BitcoinExchange::isFileExists(std::string &filename)
{
    std::ifstream database(filename.c_str());
    if(!database.good() || database.fail() || !database.is_open())
        return (false);
    if(database.peek() == std::ifstream::traits_type::eof()) 
        return (false);
    return (true);
}


bool BitcoinExchange::isDatabaseValid(std::string &filename)
{   
    
    std::fstream file(filename.c_str());
    std::string line;

    if(!file)
        throw std::runtime_error("Error: could not open database file.\n");

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
        if( date.length() != 10 || !std::isdigit(date.at(0)) || !std::isdigit(date.at(1)) || !std::isdigit(date.at(2)) ||
            !std::isdigit(date.at(3)) || date.at(4) != '-' || !std::isdigit(date.at(5)) ||
            !std::isdigit(date.at(6)) || date.at(7) != '-' || !std::isdigit(date.at(8)) ||
            !std::isdigit(date.at(9)))
            throw std::runtime_error("Error: bad date.\n");
        std::string rate = line.substr(pos + 1);
        int i = 0;
        if(rate[i] == '0')
        {   
            while (rate[i] == '0')
            {
                if(isdigit(rate[++i]) && rate[i] != '0')
                    throw std::runtime_error("Error: bad rate.\n");
            }
        }
        float float_num;
        std::istringstream iss(rate);
        if(!(iss >> float_num) || float_num < 0)
            throw std::runtime_error("Error: bad rate.\n");
        addToMap(date, float_num);
       //std::cout << "rate: " << rate << std::endl;
     
    }
    return (true);
}


void BitcoinExchange::addToMap(std::string &date, float &float_num)
{
    std::istringstream iss(date);
    int year, month, day;
    char minus_sign;

    iss >> year >> minus_sign >> month >> minus_sign >> day;
    if(year < 1990 || year > 2100 || month <1 || month > 12 || day < 1 || day > 31 || float_num < 0)
        throw std::runtime_error("Error: invalid input in database.csv.\n");
    int date_int = year * 10000 + month * 100 + day;
    //std::cout << "date_int: " << date_int << std::endl;
    _database[date_int] = float_num;
}


void BitcoinExchange::process(std::string &filename)
{
    std::fstream file(filename.c_str());
    
    if(!file)
        throw std::runtime_error("Error: could not open file.\n");
    std::string line;
    int i = 0;
    std::getline(file, line);
    if(line != "date | value")
        throw std::runtime_error("Error: no 1st line in input file.\n");
    while (std::getline(file, line))
    {   _error = false;
        std::istringstream iss(line);
        std::string word;
        i = 0;
        while (iss >> word)
        {   //std::cout << word << std::endl;
            if(!IsWordValid(word, i))
            {   
                _error = true;
                break;
            }
            i++;
        }
        if(i != 3 && _error == false)
            std::cout << "Error: bad input => " << line << std::endl;         
        else if(_error == false)
            findAndPrint(line, word);
    }
    return;
}


bool  BitcoinExchange::IsWordValid(std::string &word, int &i)
{
    //std::cout << "word: [" << i  << "]" << word << std::endl;
    float float_num = 0;
    std::istringstream iss(word);
    
    //std::cout << "word: [" << i  << "]" << word << std::endl;
    switch (i)
    {
        case 0 :
            if(word.length() != 10 || !std::isdigit(word.at(0)) || !std::isdigit(word.at(1)) ||
                !std::isdigit(word.at(2)) || !std::isdigit(word.at(3)) || word.at(4) != '-' || 
                !std::isdigit(word.at(5)) || !std::isdigit(word.at(6)) || word.at(7) != '-' ||
                !std::isdigit(word.at(8)) || !std::isdigit(word.at(9)))
            {   
                std::cout << "Error: bad input => " << word << std::endl;
                return (false);
            }
            int year, month, day;
            char minus_sign;
            iss >> year >> minus_sign >> month >> minus_sign >> day;
            if(year < 1990 || year > 2100 || month <1 || month > 12 || day < 1 || day > 31)
            {
                std::cout << "Error: invalid date input => " << word << std::endl;
                return (false);
            }
            break;
        case 1 :
            if(word != "|")
                return (false);
            break;
        case 2 :
            std::istringstream iss(word);
            if(!(iss >> float_num))
            {
                std::cout << "Error: cannot convert => " + word << std::endl;
                return (false);   
            }     
            else if((float_num > 1000))
            {    
                std::cout << "Error: too large a number." << std::endl;
                return (false);
            }
            else if(float_num < 0)
            {
                std::cout << "Error: not a positive number." << std::endl;
                return (false); 
            }   
            break;
    }
    return (true);
}



void BitcoinExchange::findAndPrint(std::string &line, std::string &word)
{
    std::istringstream iss(line);
    int year, month, day;
    char minus_sign;
    iss >> year >> minus_sign >> month >> minus_sign >> day;
    int date_int = year * 10000 + month * 100 + day;
    float float_num = 0;
    std::istringstream iss2(word);
    iss2 >> float_num;

    std::map<int, float>::const_iterator it = _database.find(date_int);
    if(it != _database.end())
        std::cout << line << " => " << it->second * float_num << std::endl;
    else
    {
        std::map<int, float>::iterator itr = _database.lower_bound(date_int);
        if(itr == _database.begin())        
            (itr->second)  = 0;
        else
            --itr;
        std::cout << line << " => " << itr->second * float_num << std::endl;
    }
}


