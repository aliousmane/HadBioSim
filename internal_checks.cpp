//******************************************************************************
//  Project:		Quality test (WBSF)
//	Programmer:     Ousmane
// 
//  It under the terms of the GNU General Public License as published by
//     the Free Software Foundation
//  It is provided "as is" without express or implied warranty.
//******************************************************************************
#include "stdafx.h"
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<time.h>
#include<errno.h>
#include<exception>
#include<chrono>
#include<math.h>
#include <boost/tokenizer.hpp>
//#include"duplicate_months.h"
#include"station.h"
#include"internal_checks.h"
#include"utils.h"

using namespace std;
using namespace UTILS;
using namespace boost;
std::string LOG_OUTFILE_LOCS = "P:\\Travail\\Weather\\Data";
std::string CSV_DATA_LOCS = "P:\\Travail\\Weather\\PEI 2015-2016H";

void INTERNAL::read_file(char *file, vector<station> &station_info)
{
	/*
		Fonction pour lire le contenu du fichier candidate_stations.txt et affecter ses éléments aux attributs
		de la classe station
		*/
	
	ifstream input;
	stringstream sst;
	sst << file;
	string chaine = sst.str();
	try
	{
		input.open(chaine.c_str());
	}
	catch (std::exception e)
	{
		cout << e.what() << endl;
	}
	if (!input) exit(1);
	
	char_separator<char> sep(",");
	string  ligne = "";
	while (!input.eof())
	{
		getline(input, ligne);
		tokenizer<char_separator<char>> tokens(ligne, sep);
		int i = 0;
		string data[12] = { "0" };
		for (const string& t : tokens)
		{
			data[i] = t.c_str();
			i++;
		}
		station stat = station::station(data[0], data[1], atof(data[2].c_str()), atof(data[3].c_str()), atof(data[4].c_str()), data[7].c_str());
		station_info.push_back(stat);
	}
	

}
		
		

void INTERNAL::internal_checks(vector<station> &station_info,bool duplicate,bool second)
{
	bool first = !second;
	time_t now = time(0);
	int st = 0;
	vector<station>::iterator stat;
	for (stat = station_info.begin(); stat != station_info.end(); ++stat, st++)
	{
		char date[26];
		ctime_s(date, sizeof(date), &now);
		cout << date << endl;  //Date du jour au format Www Mmm dd hh:mm:ss yyyy\n
		cout << "Station Number :  " << st + 1 << " / " << station_info.size() << endl;
		cout << "Station Identifier:  " << (*stat).getId() << endl;
		// Ouverture du fichier en mode ecriture lors du premier appel de la fonction ou en mode append la seconde fois
		ofstream logfile;
		stringstream sst;
		sst << LOG_OUTFILE_LOCS << (*stat).getId() << ".log";
		
		if (first)
		{
			try
			{
				logfile.open(sst.str().c_str());
			}
			catch (std::exception e)
			{
				cout << e.what() << endl;
			}
			
		}
		else
		{
			try
			{
				logfile.open(sst.str().c_str(), ofstream::out | ofstream::app);
			}
			catch (std::exception e)
			{
				cout << e.what() << endl;
			}

		}
		logfile << date << endl;
		logfile << "Internal Checks" << endl;
		logfile << "Station Identifier : " << (*stat).getId() << endl;

		double process_start_time = chrono::duration_cast<chrono::duration<double>>(chrono::system_clock::now().time_since_epoch()).count();

		//Fermeture du fichier
		
		/* latitude and longitude check  */
		if (std::abs((*stat).getLat()) > 90.)
		{
			logfile << (*stat).getId() << "	Latitude check" << "  Unphysical latitude ";
			logfile.close();
			continue;
		}
		if (std::abs((*stat).getLon()) > 180.)
		{
			logfile << (*stat).getId() << "Longitude Check" << "  Unphysical longitude ";
			logfile.close();
			continue;
		}
		// if running through the first time
		if (first)
		{
			
			// tester si le fichier existe
			
			//unzipper le fichier .gz

			//lire dans le fichier netcdf
			logfile << "Total station record size  len(station.time.data)"<< endl; //len(station.time.data) n
			//match_to_compress = utils.create_fulltimes(station, process_vars, DATASTART, DATAEND, carry_thru_vars)
		}
		else if (second)
		{
			//lire le fichier _mask.nc
			//match_to_compress = utils.create_fulltimes(station, process_vars, DATASTART, DATAEND, carry_thru_vars)
		}
		if (duplicate)
		{
			//Appel à la fonction duplicate_months de qc_tests
		}

		//Write to file
		if (first)
		{ }
		else if (second)
		{

		}
		logfile << date << endl;
		logfile << "processing took " << chrono::duration_cast<chrono::duration<double>>(chrono::system_clock::now().time_since_epoch()).count() - process_start_time << "  s" << endl;
		if (logfile)
			logfile.close();
		cout << "Internal Checks completed" << endl;
	}
}






	