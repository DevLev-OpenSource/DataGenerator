/**
 * @file main.cpp
 * @brief Main entry point for the DataGenerator application.
 * 
 * This file contains the menu system and user interaction logic.
 * It handles the command-line interface, processes user input,
 * and calls appropriate data generation functions.
 */

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <limits>
#include "../DataGenerator/generator.h"

// Function to clear input buffer
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Function to get valid number of items to generate (1-100)
int getItemCount() {
    int count = 0;
    bool validInput = false;
    
    do {
        std::cout << "How many items would you like to generate? (1-100): ";
        std::cin >> count;
        
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
        } else if (count < 1 || count > 100) {
            std::cout << "Please enter a number between 1 and 100.\n";
        } else {
            validInput = true;
        }
    } while (!validInput);
    
    return count;
}

int main()
{
    int choice = 0;
    
    std::cout << "=== Data Generator Application ===" << std::endl;
    
    do {
        // Display menu options
        std::cout << "\nMenu Options:" << std::endl;
        std::cout << "1. Generate First Names" << std::endl;
        std::cout << "2. Generate Last Names" << std::endl;
        std::cout << "3. Generate Full Names" << std::endl;
        std::cout << "4. Generate Phone Numbers" << std::endl;
        std::cout << "5. Generate ID Numbers" << std::endl;
        std::cout << "6. Generate Full Records" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        
        // Handle invalid input
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        
        // Process user choice
        switch(choice) {
            case 1: { // First Names
                int count = getItemCount();
                std::cout << "\nGenerating " << count << " random first names:\n";
                std::cout << "------------------------------------\n";
                
                for (int i = 0; i < count; i++) {
                    std::cout << i+1 << ". " << generateRandomFirstName() << std::endl;
                }
                break;
            }
            
            case 2: { // Last Names
                int count = getItemCount();
                std::cout << "\nGenerating " << count << " random last names (no repetition):\n";
                std::cout << "------------------------------------\n";
                
                std::set<std::string> usedLastNames;
                for (int i = 0; i < count; i++) {
                    std::cout << i+1 << ". " << generateRandomLastName(usedLastNames) << std::endl;
                }
                break;
            }
            
            case 3: { // Full Names
                int count = getItemCount();
                std::cout << "\nGenerating " << count << " random full names:\n";
                std::cout << "------------------------------------\n";
                
                std::set<std::string> usedLastNames;
                for (int i = 0; i < count; i++) {
                    std::cout << i+1 << ". " << generateRandomFullName(usedLastNames) << std::endl;
                }
                break;
            }
            
            case 4: { // Phone Numbers
                int count = getItemCount();
                std::cout << "\nGenerating " << count << " random phone numbers:\n";
                std::cout << "------------------------------------\n";
                
                for (int i = 0; i < count; i++) {
                    std::cout << i+1 << ". " << generateRandomPhoneNumber() << std::endl;
                }
                break;
            }
            
            case 5: { // ID Numbers
                int count = getItemCount();
                std::cout << "\nGenerating " << count << " random 8-digit ID numbers:\n";
                std::cout << "------------------------------------\n";
                
                for (int i = 0; i < count; i++) {
                    std::cout << i+1 << ". " << generateRandomIDNumber() << std::endl;
                }
                break;
            }
            
            case 6: { // Full Records
                int count = getItemCount();
                std::cout << "\nGenerating " << count << " random full records:\n";
                std::cout << "------------------------------------\n";
                
                std::set<std::string> usedLastNames;
                for (int i = 0; i < count; i++) {
                    std::cout << i+1 << ". " << generateFullRecord(usedLastNames) << std::endl;
                }
                break;
            }
            
            case 7: { // Exit
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
            }
            
            default: {
                std::cout << "Invalid choice. Please enter a number between 1 and 7." << std::endl;
                break;
            }
        }
    } while (choice != 7);
    
    return 0;
}