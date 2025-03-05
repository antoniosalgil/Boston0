/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/** 
 * @file Coordinate.cpp  
 * 
 * Last modified on February 12, 20245, 15:03 PM
 */

#include "Coordinates.h"

const float Coordinates::INVALID_COORDINATE=181.0;

using namespace std;


Coordinates::Coordinates(float latitude, float longitude) {
    _latitude = latitude;
    _longitude = longitude;
}

float Coordinates::getLatitude() const {
    return _latitude;
}

float Coordinates::getLongitude() const {
    return _longitude;
}

bool Coordinates::isValid() const {
    return ((_latitude > 90) || (_latitude < -90) || (_longitude > 180) || 
            (_longitude < -180));
}

void Coordinates::set(float latitude, float longitude){
    _latitude = latitude;
    _longitude = longitude;
}

void Coordinates::setLatitude(float latitude) {
    _latitude = latitude;
}

void Coordinates::setLongitude(float longitude) {
    _longitude = longitude;
}

std::string Coordinates::toString() const {
    return (std::to_string(_latitude) + " , " + std::to_string(_longitude));
}

Coordinates Coordinates::length(const Coordinates &second) const{
    return (Coordinates(abs(second.getLatitude() - _latitude),
                        abs(second.getLongitude() - _longitude)));
}                        


bool Coordinates::isInsideArea(const Coordinates &bottomLeft, const Coordinates &topRight) const {
    
    return ((_latitude > bottomLeft.getLatitude()) &&
            (_longitude > bottomLeft.getLongitude()) &&
            (_latitude < topRight.getLatitude()) &&
            (_longitude < topRight.getLongitude()));
}  
