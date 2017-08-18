// HadISD.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Basic\HourlyDatabase.h"
#include <tchar.h>
#include <vector>
#include "station.h"
#include "internal_checks.h"
#include "Utils.h"|

using namespace std;
using namespace WBSF;
using namespace HOURLY_DATA;
using namespace INTERNAL;

int _tmain(int argc, _TCHAR* argv[])
{
	
	//ASSERT(AfxGetResourceHandle());
	//CDynamicResources::set(AfxGetResourceHandle());
	
	//fichier d'entrée
	char* file = "P:\\Project\\wbsTools\\HadISD\\Weather\\PEI 2015-2016.HourlyHdr.csv";
	vector<station> station_info;
	INTERNAL::read_file(file, station_info);
	bool second = false;
	for (size_t i = 0, len = station_info.size(); i < len; i++)
		cout << station_info.at(i).toString() << endl;
	bool duplicate = true;
	UTILS::CsvToNetCDF();
	INTERNAL::internal_checks(station_info, duplicate, second);
	
	CHourlyDatabase DB;

	ERMsg msg;

	msg = DB.Open("P:\\Travail\\Weather\\PEI 2015-2016.HourlyDB");
	if (msg)
	{
		CWeatherStation station; 

		msg = DB.Get(station, 1, -999);
		cout << station << endl;
		if (msg)
		{
			CTRef TRef(2016, JANUARY, DAY_01);
			int year = 2016;
			float Tair = station[year][JANUARY][DAY_01][0][H_TAIR2];
			int h;
			h = 0;
		}
	}
	


	system("PAUSE");
	
	return 0;
}

