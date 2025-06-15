/**
 * @file generator.cpp
 * @brief Implementation of data generation functionality.
 *
 * This file contains the implementations of functions declared in generator.h.
 * It handles the logic for generating random person data by selecting random
 * elements from data arrays defined in data.h.
 */

#include "generator.h"
#include "data.h"
#include <random>
#include <fstream>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <iomanip>

 // Random number generator
std::mt19937 rng(static_cast<unsigned int>(std::time(nullptr)));

std::string generateRandomFirstName() {
    std::uniform_int_distribution<int> dist(0, FIRST_NAMES.size() - 1);
    return FIRST_NAMES[dist(rng)];
}

std::string generateRandomLastName(std::set<std::string>& usedLastNames) {
    // If we've used all available last names, reset the set
    if (usedLastNames.size() >= LAST_NAMES.size()) {
        usedLastNames.clear();
    }

    // Find a last name that hasn't been used yet
    std::string lastName;
    do {
        std::uniform_int_distribution<int> dist(0, LAST_NAMES.size() - 1);
        lastName = LAST_NAMES[dist(rng)];
    } while (usedLastNames.find(lastName) != usedLastNames.end());

    // Add the selected name to the used set
    usedLastNames.insert(lastName);
    return lastName;
}

std::string generateRandomFullName(std::set<std::string>& usedLastNames) {
    return generateRandomFirstName() + " " + generateRandomLastName(usedLastNames);
}

std::string generateRandomPhoneNumber() {
    // Select a random phone prefix
    std::uniform_int_distribution<int> prefixDist(0, PHONE_PREFIXES.size() - 1);
    std::string prefix = PHONE_PREFIXES[prefixDist(rng)];

    // Generate the 7-digit number part
    std::uniform_int_distribution<int> numberDist(1000000, 9999999);
    std::string number = std::to_string(numberDist(rng));

    // Return the formatted phone number
    return prefix + number;
}

std::string generateRandomIDNumber() {
    // Generate a random 8-digit ID number
    std::uniform_int_distribution<int> dist(10000000, 99999999);
    return std::to_string(dist(rng));
}

std::string generateFullRecord(std::set<std::string>& usedLastNames) {
    std::string firstName = generateRandomFirstName();
    std::string lastName = generateRandomLastName(usedLastNames);
    std::string phoneNumber = generateRandomPhoneNumber();
    std::string idNumber = generateRandomIDNumber();

    // Format: "FirstName LastName, Phone: XXX-XXXXXXX, ID: XXXXXXXX"
    std::stringstream ss;
    ss << firstName << " " << lastName << ", ";
    ss << "Phone: " << phoneNumber << ", ";
    ss << "ID: " << idNumber;

    return ss.str();
}

Person generateRandomPerson() {
    Person person;
    std::set<std::string> usedLastNames;

    // Generate all required fields
    person.firstName = generateRandomFirstName();
    person.lastName = generateRandomLastName(usedLastNames);
    person.phoneNumber = generateRandomPhoneNumber();
    person.idNumber = generateRandomIDNumber();

    return person;
}

std::vector<Person> generateMultiplePeople(int count) {
    std::vector<Person> people;
    people.reserve(count);
    std::set<std::string> usedLastNames;

    for (int i = 0; i < count; ++i) {
        Person person;
        person.firstName = generateRandomFirstName();
        person.lastName = generateRandomLastName(usedLastNames);
        person.phoneNumber = generateRandomPhoneNumber();
        person.idNumber = generateRandomIDNumber();

        people.push_back(person);
    }

    return people;
}

bool exportData(const std::vector<Person>& people, const std::string& filename) {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file for writing: " << filename << std::endl;
        return false;
    }

    // Write header
    outFile << "First Name,Last Name,Phone Number,ID Number\n";

    // Write each person's data
    for (const auto& person : people) {
        outFile << person.firstName << ","
            << person.lastName << ","
            << person.phoneNumber << ","
            << person.idNumber << "\n";
    }

    outFile.close();
    return true;
}