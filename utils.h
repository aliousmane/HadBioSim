//******************************************************************************
//  Project:		Weather-based simulation framework (WBSF)
//	Programmer:     Ousmane
// 
// Fonctions utilitaires pour effectuer les tests de validation sur les données

#ifndef __UTILS
#define __UTILS
#pragma once
#include "stdafx.h"
#include<string>
#include<iostream>

namespace UTILS
{
	
	//   Class for meteorological variable
	class Metvar
	{
		Metvar(std::string name,std::string long_name );
		~Metvar();
		std::string toString();
		std::string getName();
		std::string getLongName();
		
	private:
		std::string m_name;
		std::string m_longname;
	};
	void CsvToNetCDF();
	void set_MetVar_attributes(std::string, std::string long_name, std::string standard_name, std::string units, std::string mdi, std::string dtype);
	//expand the time axis of the variables
	void create_fulltimes(std::string station, std::string var_list, std::string start, std::string end, std::string opt_var_list, bool do_input_station_id, bool do_qc_flags, bool do_flagged_obs);
	void month_starts(int start,int end);
	void month_starts_in_pairs(int start, int end);
	void reporting_accuracy(std::string data, bool winddir);
	void reporting_frequency(std::string indata);
	double gaussian(double *X, double *p);
	double residuals_gaussian(double *p, double * Y, double *X);
	void gaussian(double *x, double *y, int norm,bool mu , bool sig );
	void apply_filter_flags(std::string st_var);
	void apply_flags_to_mask(std::string station, std::string  variable);
	void IQR(std::string data, double percentile = 0.25);
	void mean_absolute_deviation(std::string data, bool median = false);
	void winsorize(std::string data, double percent, bool idl = false);
	void print_flagged_obs_number(std::string logfile, std::string test, std::string variable, int  nflags, bool noWrite = false);
	void get_dist_and_bearing(double *coord1, double * coord2);
	void apply_flags_all_variables(std::string station, std::string  all_variables, int flag_col, std::string logfile, std::string test_name);
	void apply_windspeed_flags_to_winddir(std::string station);
	//void nearly_equal(a, b, sig_fig = 5) :   creer un template


}
#endif