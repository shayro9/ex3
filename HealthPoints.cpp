//
// Created by michalmaya on 29/05/2022.
//

#include "HealthPoints.h"

HealthPoints::HealthPoints(const int max) {
    m_healthPoints= max;
    m_max= max;
}

HealthPoints& HealthPoints:: operator+(const int num){
    m_healthPoints += num;
    if (m_healthPoints > m_max){
        m_healthPoints= m_max;
    }
}

HealthPoints& HealthPoints::operator-(const int num){
    m_healthPoints -= num;
    if (m_healthPoints < 0){
        m_healthPoints=0;
    }
}

HealthPoints& HealthPoints::operator+= (const int num){
    this= this + num;
}

HealthPoints& HealthPoints::operator-= (const int num){
    this = this - num;
}

bool HealthPoints::operator== (const HealthPoints& other){
    if (m_healthPoints==other.m_healthPoints){
        return true;
    }
    return false;
}

bool HealthPoints::operator!= (const HealthPoints& other){
    if (this==other){
        return false;
    }
    return true;
}

bool HealthPoints::operator>= (const HealthPoints& other){
    if( this > other || this == other){
        return true;
    }
    return false;
}

bool HealthPoints::operator> (const HealthPoints& other){
    if (m_healthPoints > other.m_healthPoints){
        return true;
    }
    return false;
}

bool HealthPoints::operator<= (const HealthPoints& other){
    if( this > other){
        return false;
    }
    return true;
}

bool HealthPoints::operator< (const HealthPoints& other){
    if(this>=other){
        return false;
    }
    return true;
}

void HealthPoints::operator<<(){

}

