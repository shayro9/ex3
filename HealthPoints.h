//
// Created by michalmaya on 29/05/2022.
//

#ifndef EX3_HEALTHPOINTS_H
#define EX3_HEALTHPOINTS_H
//Player& operator= (const Player& other) = default;
class HealthPoints{
public:
    HealthPoints(const int max=100);
    ~HealthPoints()= default;
    HealthPoints(const HealthPoints& other)= default;
    HealthPoints& operator= (const HealthPoints& other)= default;


private:
    int m_healthPoints;
    int m_max;
};

friend HealthPoints& operator+ (const int num);
friend HealthPoints& operator- (const int num);
HealthPoints& operator+= (const int num);
HealthPoints& operator-= (const int num);
friend bool operator== (const HealthPoints& other);
bool operator!= (const HealthPoints& other);
bool operator>= (const HealthPoints& other);
friend bool operator> (const HealthPoints& other);
bool operator<= (const HealthPoints& other);
bool operator< (const HealthPoints& other);
void operator<< ();

#endif //EX3_HEALTHPOINTS_H


