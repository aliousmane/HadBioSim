//******************************************************************************
//  Project:		Quality test (WBSF)
//	Programmer:     Ousmane
// 
//  It under the terms of the GNU General Public License as published by
//     the Free Software Foundation
//  It is provided "as is" without express or implied warranty.
//******************************************************************************
#pragma once
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
#include<math.h>//#include"duplicate_months.h"
#include"station.h"



namespace  INTERNAL
{
	void read_file(char *file, std::vector<station> &station_info);
	
	void internal_checks(std::vector<station> &station_info, bool duplicate, bool second);
	
}


