#pragma once
#include<string>
#include "stdafx.h"
class station
{
public:
		
	station();
	station(std::string id, std::string name, double lat, double lon, double elev, std::string wmo);
	~station();
	std::string toString();
	std::string getId();
	std::string getName();
	std::string getWmoId();
	double getLat();
	double getLon();
	double getElev();
private:
	std::string m_id;
	std::string m_name;
	std::string m_wmoid;
	double m_lat;
	double m_lon;
	double m_elev;
};

