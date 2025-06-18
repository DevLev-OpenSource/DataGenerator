/**
 * @file generator.cpp
 * @brief Implementation of data generation functionality.
 *
 * This file contains the implementations of functions declared in generator.h.
 * It handles the logic for generating random person data by selecting random
 * elements from data arrays defined in data.h.
 */

#include "generator.h"
#include <chrono>      // For std::chrono::system_clock
#include <iomanip>     // For std::setw, std::setfill
#include <random>      // For std::mt19937, std::uniform_int_distribution
#include <set>         // For std::set
#include <sstream>     // For std::stringstream
#include <string>
#include <vector>

 // --- Global Constants (replace with your actual definitions) ---
 // These would typically be defined in a header file or a dedicated constants file.
const std::vector<std::string> FIRST_NAMES = { "Alice", "Bob", "Charlie", "Diana", "Eve", "Frank", "Grace", "Heidi" };
const std::vector<std::string> LAST_NAMES = { "Smith", "Jones", "Williams", "Brown", "Davis", "Miller", "Wilson", "Moore" };
const std::vector<std::string> PHONE_PREFIXES = { "050-", "052-", "053-", "054-", "055-", "058-" };
// --- End Global Constants ---


// Random number generator instance.
// Seeded once when the program starts for good randomness.
static std::mt19937 rng(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));


// --- Single-Item Generation Functions (Originals) ---

std::string generateRandomFirstName() {
	std::uniform_int_distribution<size_t> dist(0, FIRST_NAMES.size() - 1);
	return FIRST_NAMES[dist(rng)];
}

std::string generateRandomLastName(std::set<std::string>& usedLastNames) {
	// If we've used all available last names, reset the set
	if (usedLastNames.size() >= LAST_NAMES.size()) {
		usedLastNames.clear();
	}

	// Find a last name that hasn't been used yet
	std::string lastName;
	std::uniform_int_distribution<size_t> dist(0, LAST_NAMES.size() - 1);
	do {
		lastName = LAST_NAMES[dist(rng)];
	} while (usedLastNames.count(lastName)); // Use .count() for checking existence

	// Add the selected name to the used set
	usedLastNames.insert(lastName);
	return lastName;
}

// Note: generateRandomFullName and generateFullRecord still need a 'usedLastNames' set from caller
std::string generateRandomFullName(std::set<std::string>& usedLastNames) {
	return generateRandomFirstName() + " " + generateRandomLastName(usedLastNames);
}

std::string generateRandomPhoneNumber() {
	// Select a random phone prefix
	std::uniform_int_distribution<size_t> prefixDist(0, PHONE_PREFIXES.size() - 1);
	std::string prefix = PHONE_PREFIXES[prefixDist(rng)];

	// Generate the 7-digit number part
	// Note: If you need to ensure the number is truly 7 digits (e.g., no leading zeros if converted to int then back to string)
	// you might want to generate digit by digit or use stringstream formatting.
	std::uniform_int_distribution<int> numberDist(0, 9999999);
	std::stringstream ss;
	ss << std::setw(7) << std::setfill('0') << numberDist(rng); // Ensure 7 digits with leading zeros

	return prefix + ss.str();
}

std::string generateRandomIDNumber() {
	// Generate a random 8-digit ID number
	std::uniform_int_distribution<int> dist(0, 99999999); // Generate up to 99,999,999
	std::stringstream ss;
	ss << std::setw(8) << std::setfill('0') << dist(rng); // Ensure 8 digits with leading zeros
	return ss.str();
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


std::string generateRandomFirstNames(int n) {
	std::stringstream ss;
	for (int i = 0; i < n; ++i) {
		ss << generateRandomFirstName() << "\n";
	}
	return ss.str();
}

std::string generateRandomLastNames(int n) {
	// Use a static set to maintain uniqueness across calls to this specific function
	static std::set<std::string> s_usedLastNamesForMany;
	std::stringstream ss;
	for (int i = 0; i < n; ++i) {
		ss << generateRandomLastName(s_usedLastNamesForMany) << "\n";
	}
	return ss.str();
}

std::string generateRandomFullNames(int n) {
	// Use a static set for uniqueness for full names
	static std::set<std::string> s_usedLastNamesForFullNames;
	std::stringstream ss;
	for (int i = 0; i < n; ++i) {
		ss << generateRandomFullName(s_usedLastNamesForFullNames) << "\n";
	}
	return ss.str();
}

std::string generateRandomPhoneNumbers(int n) {
	std::stringstream ss;
	for (int i = 0; i < n; ++i) {
		ss << generateRandomPhoneNumber() << "\n";
	}
	return ss.str();
}

std::string generateRandomIDNumbers(int n) {
	std::stringstream ss;
	for (int i = 0; i < n; ++i) {
		ss << generateRandomIDNumber() << "\n";
	}
	return ss.str();
}

std::string generateFullRecords(int n) {
	// Use a static set for uniqueness when generating full records
	static std::set<std::string> s_usedLastNamesForRecords;
	std::stringstream ss;
	for (int i = 0; i < n; ++i) {
		ss << generateFullRecord(s_usedLastNamesForRecords) << "\n";
	}
	return ss.str();
}