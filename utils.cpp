#include "stdafx.h"
#include <string>
#include <iostream>
#include "utils.h"
#include <boost/tokenizer.hpp>
using namespace std;
using namespace UTILS;

Metvar::Metvar(string name,string long_name)
{
	m_name = name;
	m_longname = long_name;
	
}
Metvar::~Metvar()
{
}
string Metvar::toString()
{
	return "Variable  :" + m_name + "  Long name  " + m_longname;

}
void CsvToNetCDF(){}

