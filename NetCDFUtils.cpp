#include "stdafx.h"
#include"NetCDFUtils.h"
#include<fstream>
#include<sstream>
#include<string>


using namespace NETCDFUTILS;
using namespace std;



void CsvToNetCDF(string fichier)
{
	ifstream input;
	stringstream sst;
	sst << fichier;
	string chaine = sst.str();
	input.open(chaine.c_str());
	if (!input) exit(1);
}
void NetCDFtoCsv()
{
	
}