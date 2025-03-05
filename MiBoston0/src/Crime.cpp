/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/** 
 * @file Crime.cpp
 *  
 * Last modified on February 12, 20245, 15:13 PM
 */

#include "Crime.h"

using namespace std;

/*
 * Initialization of the static string that contains the value assigned to any 
 * string field (string) which is found empty in the data of a Crime
 */
const std::string Crime::UNKNOWN_VALUE = "UNKNOWN";

/*
 * Initialization of the static string that contain the default value for the
 * DateTime field in a Crime 
 */
const string Crime::DATETIME_DEFAULT = "2017-01-20 02:00:00";

/* 
 * Initialization of the static string with the default values for every field in 
 * a Crime
 */
const string Crime::CRIME_DEFAULT("0," + UNKNOWN_VALUE + "," + UNKNOWN_VALUE + "," +
        UNKNOWN_VALUE + "," + UNKNOWN_VALUE + "," + UNKNOWN_VALUE + "," + UNKNOWN_VALUE +
        "," + ((std::string)"1") + "," + Crime::DATETIME_DEFAULT + "," +
        UNKNOWN_VALUE + ",181,181");

Crime::Crime() {
    set (Crime::CRIME_DEFAULT);
}

Crime::Crime(const string &line) {
    set(line);
}

int Crime::getCounter() const {
    return _counter;
}

std::string Crime::getId() const {
    return _id;
}

std::string Crime::getCode() const {
    return _code;
}

std::string Crime::getGroup() const {
    return _group;
}

std::string Crime::getDescription() const {
    return _description;
}

std::string Crime::getDistrict() const {
    return _district;
}

std::string Crime::getStreet() const {
    return _street;
}

std::string Crime::getAreaReport() const {
    return _areaReport;
}

bool Crime::isShooting() const {
    return _shooting;
}

DateTime Crime::getDateTime() const {
    return _dateTime;
}

Coordinates Crime::getLocation() const {
    return _location;
}

bool Crime::isIDUnknown() const {
    return (_id == UNKNOWN_VALUE);
}

std::string Crime::toString() const {
    
    string shoot = "0";
    if (_shooting)
        shoot = "1";
        
    return (_counter + "," + _id + "," + _code + "," +
        _group + "," + _description + "," + _district + "," + _areaReport +
        "," + shoot + "," + _dateTime.toString() + "," +
        _street + _location.toString());
}

void Crime::setCounter(int c) {
    _counter = c;
}

void Crime::setId(const std::string &id) {
    _id = id;
}

void Crime::setCode(const std::string &code) {
    _code = code;
}

void Crime::setGroup(const std::string &group) {
    _group = group;
}

void Crime::setDescription(const std::string &description) {
    _description = description;
}

void Crime::setDistrict(const std::string &district) { 
    _district = district;
}

void Crime::setAreaReport(const std::string &areaReport) {
    _areaReport = areaReport;
}

void Crime::setStreet(const std::string &street) {
    _street = street;
}

void Crime::setShooting(bool shooting) {
    _shooting = shooting;
}

void Crime::setDateTime(const string & time) {
    _dateTime = time;
}

void Crime::setLocation(const Coordinates & coordinates) {
    _location = coordinates;
}

void Crime::set(const std::string & line) {
    const int NFIELDS = 12;
    string data;        //piece of data detached from line;
    size_t pos, posn;   // aux for the beginning of the fields
    int lat, lon;
 
    pos = 0;
    posn = line.find(',', pos); // beginning of the next field
    for (int nfield = 0; nfield < NFIELDS - 1 && posn != string::npos; nfield++) {
        data = line.substr(pos, posn - pos);
        pos = posn + 1;

        switch (nfield) {
            case 0: // counter
                setCounter(stoi(data));
                break;
            case 1: // ID
                setId(data);
                break;
            case 2: // code
                setCode(data);
                break;
            case 3: // group
                setGroup(data);
                break;
            case 4: // desc
                setDescription(data);
                break;
            case 5: // District alphaNumeric
                setDistrict(data);
                break;
            case 6: // Area report
                setAreaReport(data);
                break;
            case 7: // Shooting
                setShooting(data == "1");
                break;
            case 8: // Date
                setDateTime(data);
                break;
            case 9: // Street
                setStreet(data);
                break;
            case 10: // Latitude
                lat = stoi(data);
                break;
            case 11: // Longitude
                lon = stoi(data);
                break;
            }
        }
        setLocation (Coordinates(lat, lon));
} //end of set()

void Trim(string & myString) {
    myString.substr(myString.find_first_not_of(' '), 
                    myString.find_last_not_of(' '));
}

void Capitalize(string &myString) {
    string aux;
    for (int i = 0; 1 < myString.length(); i++) {
        char next = myString.at(i);
        
        if ((next > 'a') && (next < 'z'))
            next += ('A'-'a');
        
        aux += next;
    }
    myString = aux;
}

void Normalize(Crime & crime) {
    string data = crime.getId();
    Capitalize (data);
    crime.setId (data);
    
    data = crime.getCode();
    Capitalize (data);
    Trim (data);
    crime.setCode (data);
    
    data = crime.getGroup();
    Capitalize (data);
    Trim (data);
    crime.setGroup (data);
    
    data = crime.getDescription();
    Capitalize (data);
    Trim (data);
    crime.setDescription (data);
    
    data = crime.getDistrict();
    Capitalize (data);
    Trim (data);
    crime.setDistrict (data);
    
    data = crime.getAreaReport();
    Capitalize (data);
    Trim (data);
    crime.setAreaReport (data);
    
    data = crime.getStreet();
    Capitalize (data);
    Trim (data);
    crime.setStreet (data);
}
