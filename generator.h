/**
 * @file generator.h
 * @brief Header file for data generation functionality.
 * 
 * This file contains the declarations of functions used for
 * generating random data such as names, phone numbers, 
 * addresses, and other person-related information.
 */

#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>
#include <vector>
#include <set>

/**
 * @struct Person
 * @brief Structure to hold generated person data
 */
struct Person {
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string idNumber;
    // Add more fields as needed
};

/**
 * @brief Generate a random first name
 * @return A string containing a random first name
 */
std::string generateRandomFirstName();

/**
 * @brief Generate a random last name
 * @param usedLastNames Set of already used last names to avoid repetition
 * @return A string containing a random last name not in the usedLastNames set
 */
std::string generateRandomLastName(std::set<std::string>& usedLastNames);

/**
 * @brief Generate a random full name (first + last)
 * @param usedLastNames Set of already used last names to avoid repetition
 * @return A string containing a random full name
 */
std::string generateRandomFullName(std::set<std::string>& usedLastNames);

/**
 * @brief Generate a random phone number in format XXX-XXXXXXX
 * @return A string containing a random phone number
 */
std::string generateRandomPhoneNumber();

/**
 * @brief Generate a random 8-digit ID number
 * @return A string containing a random 8-digit ID
 */
std::string generateRandomIDNumber();

/**
 * @brief Generate a full record containing name, phone, and ID
 * @param usedLastNames Set of already used last names to avoid repetition
 * @return A string containing the full record data
 */
std::string generateFullRecord(std::set<std::string>& usedLastNames);

/**
 * @brief Generate a single random person
 * @return Person structure with randomly generated data
 */
Person generateRandomPerson();

/**
 * @brief Generate multiple random people
 * @param count Number of people to generate
 * @return Vector of Person structures
 */
std::vector<Person> generateMultiplePeople(int count);

/**
 * @brief Export generated data to a file
 * @param people Vector of Person structures to export
 * @param filename Name of the file to export to
 * @return true if export successful, false otherwise
 */
bool exportData(const std::vector<Person>& people, const std::string& filename);

#endif // GENERATOR_H