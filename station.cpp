#include "stdafx.h"
#include<string>
#include<iostream>

#include "station.h"
using namespace std;

station::station(string id, string name, double lat, double lon, double elev, string wmo)
{
	m_id = id;
	m_lon = lon;
	m_lat = lat;
	m_elev = elev;
	m_name = name;
	m_wmoid = wmo;
}
station::~station()
{
}
string station::toString()
{
	return "station  :" + m_id + "  " + m_name + "+  Longitude: " + to_string(m_lon) + "  Latitude:  " + to_string(m_lat) + "  Elevation  :" + to_string(m_elev);

}
double station::getLat(){ return m_lat; }
double station::getLon(){ return m_lon; }
double station::getElev(){ return m_elev; }
string station::getId(){ return m_id; }
string station::getName(){ return m_name; }
string station::getWmoId(){ return m_wmoid; }