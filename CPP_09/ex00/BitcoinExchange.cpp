#include "BitcoinExchange.hpp"

// canonical orthodox

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& original)
{
	*this = original;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& original)
{
	if(this == &original)
		return *this;
	return *this;
}

// class functions

void BitcoinExchange::exchange(std::string input_db)
{
	try
    {
		this->validate_databases(input_db);	
    }
    catch(std::exception& e)
    {
		std::cerr << "Error: " << e.what() << ", exiting" << std::endl;
		return ;
    }
	this->start_exchange(input_db);
}

void BitcoinExchange::validate_databases(std::string input_db)
{
	std::ifstream	input;
	std::ifstream	data_base;
	std::string 	line;

	std::cout << "Inserted Database: " << input_db << std::endl;
	data_base.open("data.csv");
	if (!data_base.is_open())
		throw std::runtime_error("Database unavailable");
	input.open(input_db.c_str());
	if (!input.is_open())
		throw std::runtime_error("Input unavailable");
	this->initiate_db();
}

void BitcoinExchange::initiate_db()
{
	std::ifstream 	datacsv;
	std::string		line;
	std::string 	date;
	std::string		value;

    datacsv.open("data.csv");
	getline(datacsv, line);
	while (getline(datacsv, line))
	{
		date = line.substr(0, line.find(','));
		value = line.substr(line.find(',') + 1, line.length());
		this->database[date] = static_cast<float>(atof(value.c_str()));
	}
}

void BitcoinExchange::start_exchange(std::string input_db)
{
	std::ifstream 	input_database;
	std::string		line;
	std::string 	date;
	std::string		value;

    input_database.open(input_db.c_str());
	getline(input_database, line);
	while (getline(input_database, line))
	{
		if (line.empty())
        {
            std::cout << "Error: Empty line.\n";
            continue;
        }
		date = line.substr(0, line.find('|') - 1);
		value = line.substr(line.find('|') + 2, line.length());
		if(line.find('|') > line.length())
			std::cout << "Error: bad input : " << line << std::endl;
		else if (validate_date(date).length() > 1)
			std::cout << "Error: " << validate_date(date);
		else if(validate_value(value).length() > 1)
			std::cout << "Error: " << validate_value(value);
		else
			this->return_values(date, value);
	}
}

std::string BitcoinExchange::validate_date(std::string date)
{
	if (date.length() != 10 || ((date[4] != '-' || date[7] != '-')))
    {
        return "Invalid date format. Use 'YYYY-MM-DD'.\n";
    }
	for (unsigned long int i = 0; i < date.length(); i++)
        if (!std::isdigit(date[i]) && date[i] != '-')
			return("Error: Invalid date");
	
	std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
	
	int year = atoi(yearStr.c_str());
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());

	if(year < 2009)
		return "Invalid year: Bitcoin started in 2009\n";
	else if(year > 2024)
		return "Invalid year: Future date\n";
	if(month > 12)
		return "Invalid month\n";
	if(day > 31)
		return "Invalid day\n";
	if(month == 2 && day > 29)
		return "Invalid day\n";
	if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
    	return "Invalid day\n";
	return "";
}


std::string BitcoinExchange::validate_value(std::string value)
{
	if(value[0] == '-')
		return "not a positive number\n";
	for (unsigned long int i = 0; i < value.length(); i++)
        if (!std::isdigit(value[i]) && value[i] != '.')
            return "not a valid number\n";
	char *endptr;
	// float
	if(value.find('.') < value.length())
	{
		if(value.find('.') == value.length()-1)
			return "bad input\n";
		float floatValue = std::strtof(value.c_str(), &endptr);
		if (floatValue > 1000)
			return "too large a number.\n";
	}
	// int
	else
	{
		long intValue = std::strtol(value.c_str(), &endptr, 10);
		if (intValue > 1000)
			return "too large a number.\n";
	}
    return "";
}

void BitcoinExchange::return_values(std::string date, std::string value)
{
    std::map<std::string, float>::iterator j = this->database.lower_bound(date);
    char *endptr;
    float floatValue = std::strtof(value.c_str(), &endptr);

    if (this->database.find(date) != this->database.end())
       std::cout << date << " => " << value << " = " << this->database[date] * floatValue << std::endl;
    else
        std::cout << date << " => " << value << " = " << this->database[j->first] * floatValue << std::endl;
}

// testing functions

void BitcoinExchange::print_databases()
{
	std::map<std::string, float>::iterator it;
    for (it = this->database.begin(); it != this->database.end(); ++it)
       	std::cout << "Date: '" << it->first << "', Value: '" << it->second << "'" << std::endl;
}

