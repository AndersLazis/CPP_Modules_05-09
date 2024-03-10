#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#define INPUT 0
#define DATABASE 1

class BitcoinExchange
{
    private:
        BitcoinExchange();
        bool isFileExists(std::string &filename);  
        bool isInputValid(std::string &filename); 

        //std::map<int, float> _database;
        //_readLine();
        //_processLine(std::string line);

    public:
        BitcoinExchange(std::string &filename);
        ~BitcoinExchange();
        bool IsLineValid(std::string &word, int &i);
        bool isDatabaseValid(std::string &filename);
       
        
        //process();

};

#endif