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

        std::map<int, float> _database;
        bool _negative;
        bool _error;

        BitcoinExchange();
        bool isFileExists(std::string &filename);  
        //bool isInputValid(std::string &filename);
        void addToMap(std::string &date, float &float_num);
        bool IsWordValid(std::string &word, int &i);
        bool isDatabaseValid(std::string &filename);
        void findAndPrint(std::string &line, std::string &word);

    public:
        BitcoinExchange(std::string &filename);
        ~BitcoinExchange(); 
        void process(std::string &filename);

};

#endif