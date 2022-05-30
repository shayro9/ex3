//
// Created by michalmaya on 29/05/2022.
//

#include "HealthPoints.h"

HealthPoints::HealthPoints(const int max)
{
    if (max <= 0){
        throw InvalidArgument();
    }
    m_max = max;
    m_healthPoints = max;
}

HealthPoints &HealthPoints::operator=(int num) {
    if(num < 0)
        throw InvalidArgument();
    m_max = num;
    m_healthPoints = num;
    return *this;
}

HealthPoints& HealthPoints::operator+= (const int num){
    int sum = m_healthPoints + num;

    if(sum < 0)
        sum = 0;
    if(sum >= m_max)
        sum = m_max;

    m_healthPoints = sum;
    return *this;
}

HealthPoints& HealthPoints::operator-= (const int num){
    int sum = m_healthPoints - num;

    if(sum < 0)
        sum = 0;
    if(sum >= m_max)
        sum = m_max;

    m_healthPoints = sum;
    return *this;
}

HealthPoints HealthPoints::operator-(const int num){
    return HealthPoints(*this) -= num;
}

HealthPoints operator+ (const HealthPoints h, const int num)
{
    return HealthPoints(h) += num;
}

HealthPoints operator+ (const int num, const HealthPoints h)
{
    return HealthPoints(h) += num;
}

bool operator==(const HealthPoints& h1, const HealthPoints& h2){
    if (h1.m_healthPoints == h2.m_healthPoints){
        return true;
    }
    return false;
}

bool operator< (const HealthPoints& h1, const HealthPoints& h2){
    if(h1.m_healthPoints < h2.m_healthPoints)
        return true;
    return false;
}

bool operator!= (const HealthPoints& h1, const HealthPoints& h2){
    return !(h1==h2);
}

bool operator>= (const HealthPoints& h1, const HealthPoints& h2){
    return h2 < h1 || h1 == h2;
}

bool operator> (const HealthPoints& h1, const HealthPoints& h2){
    return h2 < h1;
}

bool operator<= (const HealthPoints& h1, const HealthPoints& h2){
    return h1 < h2 || h1 == h2;
}

ostream& operator<<(ostream& os, const HealthPoints& health)
{
    os << health.m_healthPoints << '(' << health.m_max << ')';
    return os;
}



