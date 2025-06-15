/**
 * @file data.h
 * @brief Static data arrays for the DataGenerator application.
 * 
 * This file contains static arrays of data used by the generator functions,
 * including first names, last names, and phone number prefixes.
 * These arrays provide the source data for random generation.
 */

#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>

// Array of first names
const std::vector<std::string> FIRST_NAMES = {
    "James", "Mary", "John", "Patricia", "Robert", "Jennifer", "Michael", "Linda",
    "William", "Elizabeth", "David", "Barbara", "Richard", "Susan", "Joseph", "Jessica",
    "Thomas", "Sarah", "Charles", "Karen", "Christopher", "Nancy", "Daniel", "Lisa",
    "Matthew", "Betty", "Anthony", "Margaret", "Mark", "Sandra", "Donald", "Ashley",
    "Steven", "Kimberly", "Paul", "Emily", "Andrew", "Donna", "Joshua", "Michelle",
    "Kenneth", "Dorothy", "Kevin", "Carol", "Brian", "Amanda", "George", "Melissa"
};

// Array of last names
const std::vector<std::string> LAST_NAMES = {
    "Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson",
    "Moore", "Taylor", "Anderson", "Thomas", "Jackson", "White", "Harris", "Martin",
    "Thompson", "Garcia", "Martinez", "Robinson", "Clark", "Rodriguez", "Lewis", "Lee",
    "Walker", "Hall", "Allen", "Young", "Hernandez", "King", "Wright", "Lopez",
    "Hill", "Scott", "Green", "Adams", "Baker", "Gonzalez", "Nelson", "Carter",
    "Mitchell", "Perez", "Roberts", "Turner", "Phillips", "Campbell", "Parker", "Evans"
};

// Array of phone number prefixes (area codes)
const std::vector<std::string> PHONE_PREFIXES = {
    "050", "051", "052", "053", "054", "056", "057", "058","059",
};

#endif // DATA_H