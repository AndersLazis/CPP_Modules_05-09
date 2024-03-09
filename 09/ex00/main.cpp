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

#include "includes/BitcoinExchange.hpp"

void isFileExists(std::string filename)
{
    std::ifstream database(filename);
    if(!database.good() || database.fail() || !database.is_open())
    {
        database.close(); 
        throw std::runtime_error("Error: could not open " + filename + " file.\n");
    }
    if(database.peek() == std::ifstream::traits_type::eof()) 
    {
        database.close(); 
        throw std::runtime_error("Error: " + filename + " is empty.\n"); 
    }
    database.close(); 
}

void isInputValid(char *filename)
{
    std::fstream file(filename);
    if(!file)
        throw std::runtime_error("Error: could not open file.\n");
    std::string line;
    std::getline(file, line);
    if(line != "date | value")
        throw std::runtime_error("Error: no \"date | value\"\n");
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
        i++;
    }
}

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: no file." << std::endl;
        return (1);
    }
    try
    {
        isFileExists(av[1]);
        isFileExists("data.csv");
        isInputValid(av[1]);
       // isDatabaseValid("data.csv");
        //
        BitcoinExchange b;
        // b.process(char *av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    return (0);
}

