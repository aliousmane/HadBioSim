#pragma once
#include "stdafx.h"
#include<string>
#include<fstream>
#include<sstream>


namespace NETCDFUTILS
	{
	void CsvToNetCDF(std::string fichier);
	void NetCDFtoCsv();
}