//
// Created by michalmaya on 29/05/2022.
//

#ifndef EX3_HEALTHPOINTS_H
#define EX3_HEALTHPOINTS_H

#include "ostream"
typedef std::ostream ostream;

class HealthPoints{

public:

    HealthPoints(int max=100);
    ~HealthPoints()= default;
    HealthPoints(const HealthPoints& other)= default;

    HealthPoints& operator= (const HealthPoints& other)= default;
    HealthPoints& operator= (int num);

    HealthPoints operator+= (int num);
    HealthPoints operator-= (int num);
    HealthPoints operator- (int num);

    friend bool operator== (const HealthPoints&, const HealthPoints&);
    friend bool operator< (const HealthPoints&, const HealthPoints&);
    friend ostream& operator<<(ostream& os, const HealthPoints& health);

    //Exceptions
    class InvalidArgument{};

private:
    int m_healthPoints;
    int m_max;
};


HealthPoints operator+ (HealthPoints h, int num);
HealthPoints operator+ (int num, HealthPoints h);
bool operator!= (const HealthPoints&, const HealthPoints&);
bool operator>= (const HealthPoints&, const HealthPoints&);
bool operator> (const HealthPoints&, const HealthPoints&);
bool operator<= (const HealthPoints&, const HealthPoints&);

class InvalidArgument{};



#endif //EX3_HEALTHPOINTS_H