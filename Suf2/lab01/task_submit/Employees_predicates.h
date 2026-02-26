#pragma once

#include "Employee.h"


//===========
//  ПРЕДИКАТЫ
//===========

inline bool is_male(const Employee& e) {
    return e.gender == "М";
}

inline auto is_male_pensioner(const Employee &e) -> bool {
    return e.gender == "М" && e.age >= 65;
}


//============
//  КОМПАРАТОР
//============

inline bool is_older_male(const Employee& a, const Employee& b) {
    return a.gender == "М" &&
           b.gender == "М" &&
           a.age > b.age;
}