#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

void BitcoinExchange::acceptanceStation(std::string data, std::string input)
{
    int dataY, dataM, dataD, dataY, dataM, dataD;
    for (size_t i = 0; i < data.size(); i++)
    {
    }
    
}

BitcoinExchange::BitcoinExchange(char *av)
{
    (void)av;
    // std::string file_name = (std::string)av;
    // std::ifstream file(file_name);
    // std::stringstream buffer;
    // buffer << file.rdbuf();
    // this->_buffer = buffer.str();
    // file.close();
    returnData();
    returnInput();
    std::map<std::string, double>::iterator itInput = this->_Input.begin();
    std::map<std::string, double>::iterator itData = this->_Data.begin();
    while (itData != this->_Data.end())
    {
        // std::cout<<itData->first<< " = "<<itData->second<<std::endl;
        if (itInput->first == itData->first)
            std::cout << itInput->second * itData->second << std::endl;
        itData++;
    }
}

std::map<std::string, double> BitcoinExchange::getData()
{
    return (this->_Data);
}

std::map<std::string, double> BitcoinExchange::getInput()
{
    return (this->_Input);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::returnInput()
{
    this->_Input["0"] = 3;
    this->_Input["2011-01-03"] = 2;
    this->_Input["2011-01-03"] = 1;
    this->_Input["2011-01-03"] = 1.2;
    this->_Input["2011-01-09"] = 1;
    this->_Input["2012-01-12"] = -1;
    this->_Input["2012-01-11"] = 1;
    this->_Input["2012-01-11"] = 28;
}

void BitcoinExchange::returnData()
{
    this->_Data["0"] = 2;
    this->_Data["2013-01-03"] = 5;
    this->_Data["2013-01-03"] = 1;
    this->_Data["2013-01-03"] = 1.0;
    this->_Data["2013-01-09"] = 12;
    this->_Data["2013-01-11"] = -1;
    this->_Data["2001-42-42"] = 0;
    this->_Data["2012-01-11"] = 1;
    this->_Data["2012-01-11"] = 248;
    this->_Data["2011-01-13"] = 1;
    this->_Data["2011-01-04"] = 5;
    this->_Data["2011-01-04"] = 1;
    this->_Data["2011-01-04"] = 1.0;
    this->_Data["2011-01-08"] = 12;
    this->_Data["2012-01-11"] = -1;
    this->_Data["2001-42-42"] = 0;
    this->_Data["2012-01-11"] = 1;
    this->_Data["2012-01-11"] = 248;
    this->_Data["2009-01-14"] = 0;
    this->_Data["2009-01-17"] = 0;
    this->_Data["2009-01-20"] = 0;
    this->_Data["2009-01-23"] = 0;
    this->_Data["2009-01-26"] = 0;
    this->_Data["2009-01-29"] = 0;
    this->_Data["2009-02-01"] = 0;
    this->_Data["2009-02-04"] = 99;
    this->_Data["2009-02-07"] = 0;
    this->_Data["2009-02-10"] = 0;
    this->_Data["2009-02-13"] = 0;
    this->_Data["2009-02-16"] = 0;
    this->_Data["2009-02-19"] = 0;
    this->_Data["2009-02-22"] = 0;
    this->_Data["2009-02-25"] = 0;
    this->_Data["2009-02-28"] = 0;
    this->_Data["2009-03-03"] = 0;
    this->_Data["2009-03-06"] = 0;
    this->_Data["2009-03-09"] = 0;
    this->_Data["2009-03-12"] = 0;
    this->_Data["2009-03-15"] = 0;
    this->_Data["2018-06-21"] = 6760.83;
    this->_Data["2018-06-24"] = 6170.46;
    this->_Data["2018-06-27"] = 6097.46;
    this->_Data["2018-06-30"] = 6223.28;
    this->_Data["2018-07-03"] = 6626.44;
    this->_Data["2018-07-06"] = 6555.51;
    this->_Data["2018-07-09"] = 6724.04;
    this->_Data["2018-07-12"] = 6403.18;
    this->_Data["2018-07-15"] = 6248.84;
    this->_Data["2018-07-18"] = 7321.62;
    this->_Data["2018-07-21"] = 7334.99;
    this->_Data["2018-07-24"] = 7715.1;
    this->_Data["2018-07-27"] = 7939.81;
    this->_Data["2018-07-30"] = 8220.91;
    this->_Data["2018-08-02"] = 7607.7;
    this->_Data["2018-08-05"] = 7011.28;
    this->_Data["2018-08-08"] = 6718.23;
    this->_Data["2018-08-11"] = 6138.96;
    this->_Data["2018-08-14"] = 6252.13;
    this->_Data["2018-08-17"] = 6312.75;
    this->_Data["2018-08-20"] = 6486.58;
    this->_Data["2018-08-23"] = 6354.57;
    this->_Data["2018-08-26"] = 6738.27;
    this->_Data["2018-08-29"] = 7078.19;
    this->_Data["2018-09-01"] = 7018.78;
    this->_Data["2018-09-04"] = 7265.08;
    this->_Data["2018-09-07"] = 6501.19;
}