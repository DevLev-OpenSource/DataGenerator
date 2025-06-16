# DataGenerator

[![First-time Contributing Guide](https://img.shields.io/badge/First%20Time-Contributing%20Guide-blue.svg)](https://github.com/firstcontributions/first-contributions)

## 🎯 Project Overview

DataGenerator is an educational open-source project designed specifically for the **DEVLEV community** to provide students with hands-on experience in contributing to open source projects. This project serves as a friendly introduction to collaborative development, allowing students at different levels to contribute meaningfully to a real codebase.

The project generates random personal data (names, phone numbers, ID numbers) and provides both **Console** and **GUI interfaces** to accommodate students at different skill levels:
- **Console Interface**: Perfect for beginners and students in lower years
- **GUI Interface**: Ideal for advanced students who want to work with graphical user interfaces

## 🏗️ Project Architecture

The project follows a modular C++ architecture with clear separation of concerns:

```
DataGenerator/
├── DataGenerator/          # Core library (static lib)
│   ├── generator.h/cpp     # Main generation logic
│   └── data.h             # Static data arrays
├── DataGeneratorConsole/   # Console application
│   └── main.cpp           # CLI interface
├── DataGeneratorGUI/       # GUI application  
│   ├── main.cpp           # GUI main entry point
│   ├── MainWindow.h/cpp   # GUI window logic
│   └── imgui/             # ImGui library files
└── x64/Debug/             # Build output directory
```

### Core Components

1. **DataGenerator Library** (`DataGenerator/`)
   - **generator.h/cpp**: Contains all data generation functions
   - **data.h**: Static arrays of names and phone prefixes
   - Compiled as a static library used by both interfaces

2. **Console Interface** (`DataGeneratorConsole/`)
   - Simple menu-driven interface
   - Perfect for beginners to understand basic C++ concepts
   - Handles user input validation and menu navigation

3. **GUI Interface** (`DataGeneratorGUI/`)
   - Modern graphical interface using ImGui library
   - DirectX 11 rendering backend
   - Advanced features like clipboard integration

## ⚙️ Features

### Data Generation Capabilities
- **First Names**: Random selection from predefined list
- **Last Names**: Random selection with duplicate prevention
- **Full Names**: Combination of first and last names
- **Phone Numbers**: Israeli format (XXX-XXXXXXX)
- **ID Numbers**: 8-digit random numbers
- **Full Records**: Complete person data with all fields
- **Bulk Generation**: Generate multiple records at once (1-100 items)
- **Data Export**: Save generated data to CSV files

### Interface Features
- **Console**: Menu-driven interface with input validation
- **GUI**: Modern interface with real-time generation and clipboard support

## 🚀 Getting Started

### Prerequisites
- **Visual Studio 2019/2022** with C++ development tools
- **Windows 10/11** (required for DirectX 11 GUI support)
- **Git** for version control

### Building the Project

1. **Clone the repository**:
   ```bash
   git clone [repository-url]
   cd DataGenerator
   ```

2. **Open in Visual Studio**:
   - Open `DataGenerator.sln` in Visual Studio
   - The solution contains 3 projects that will build automatically

3. **Build the solution**:
   - Press `Ctrl+Shift+B` or use Build → Build Solution
   - This will create both Console and GUI executables

### Running the Applications

#### Console Interface
```powershell
# Navigate to output directory
cd x64\Debug\

# Run the console application
.\DataGeneratorConsole.exe
```

**Console Menu Options**:
1. Generate First Names
2. Generate Last Names  
3. Generate Full Names
4. Generate Phone Numbers
5. Generate ID Numbers
6. Generate Full Records
7. Exit

#### GUI Interface
```powershell
# Navigate to output directory  
cd x64\Debug\

# Run the GUI application
.\DataGeneratorGUI.exe
```

**GUI Features**:
- Input field to specify number of items (1-100)
- Generate button or press Enter to generate
- Multi-line text box displaying results
- Copy button to copy results to clipboard

## 📋 Code Conventions

### General Guidelines
- **Language**: C++17 standard
- **Naming Convention**: camelCase for functions and variables
- **File Naming**: PascalCase for headers, camelCase for source files
- **Documentation**: Doxygen-style comments for all public functions

### Code Style
```cpp
// Function documentation example
/**
 * @brief Generate a random first name
 * @return A string containing a random first name
 */
std::string generateRandomFirstName();

// Variable naming
int itemCount = 0;
std::string phoneNumber;
std::vector<Person> generatedPeople;

// Constants
const int MAX_ITEMS = 100;
const std::vector<std::string> FIRST_NAMES = {...};
```

### File Organization
- **Headers**: Declarations only, include guards, proper includes
- **Source Files**: Implementation details, private helper functions
- **Separation**: Clear separation between UI logic and data generation

## 🤝 Contributing Guidelines

This project is specifically designed for **first-time contributors**! Here's how to get involved:

### For Beginners (Console Interface)
Perfect starting points for new contributors:
- Add new data to arrays in `data.h` (more names, cities, etc.)
- Implement new menu options in the console interface
- Add input validation improvements
- Create new simple generation functions

### For Advanced Students (GUI Interface)  
More challenging contributions:
- Enhance the GUI with new windows and features
- Add data visualization capabilities
- Implement advanced export options (JSON, XML)
- Add configuration settings and preferences
- Improve the user experience with better UI elements

### Contribution Process
1. **Fork** the repository
2. **Create** a feature branch (`git checkout -b feature/amazing-feature`)
3. **Make** your changes following the code conventions
4. **Test** your changes with both interfaces
5. **Commit** your changes (`git commit -m 'Add amazing feature'`)
6. **Push** to your branch (`git push origin feature/amazing-feature`)
7. **Open** a Pull Request

### What We're Looking For
- 🐛 **Bug fixes** and improvements
- 📝 **Documentation** enhancements
- ✨ **New features** for data generation
- 🎨 **UI/UX improvements** for the GUI
- 🧪 **Testing** and validation improvements
- 🌍 **Internationalization** support

## 📁 Project Structure Details

### DataGenerator Core Library
```cpp
// Main generation functions
std::string generateRandomFirstName();
std::string generateRandomLastName(std::set<std::string>& usedLastNames);
std::string generateRandomPhoneNumber();  
std::string generateRandomIDNumber();
std::string generateFullRecord(std::set<std::string>& usedLastNames);

// Advanced functions
Person generateRandomPerson();
std::vector<Person> generateMultiplePeople(int count);
bool exportData(const std::vector<Person>& people, const std::string& filename);
```

### Data Structures
```cpp
struct Person {
    std::string firstName;
    std::string lastName;  
    std::string phoneNumber;
    std::string idNumber;
};
```

## 🔧 Development Tips

### Adding New Data Types
1. Add new arrays to `data.h`
2. Create generation functions in `generator.cpp`
3. Add declarations to `generator.h`
4. Update both console and GUI interfaces

### Debugging
- Use Visual Studio debugger for step-through debugging
- Console interface is easier for testing new generation logic
- GUI interface requires DirectX 11 setup for debugging

### Performance Considerations
- Data arrays are loaded once at startup
- Random number generator is seeded once
- Duplicate prevention uses std::set for O(log n) lookups

## 📚 Learning Resources

### For New Contributors
- [C++ Basics Tutorial](https://www.cplusplus.com/doc/tutorial/)
- [Git Version Control](https://git-scm.com/doc)
- [Visual Studio Guide](https://docs.microsoft.com/en-us/visualstudio/)

### For GUI Development
- [ImGui Documentation](https://github.com/ocornut/imgui)
- [DirectX 11 Tutorial](https://docs.microsoft.com/en-us/windows/win32/direct3d11/)

## 🚨 Common Issues & Solutions

### Build Issues
- **Missing DirectX SDK**: Install Windows SDK through Visual Studio Installer
- **ImGui compile errors**: Ensure all ImGui files are included in project
- **Linking errors**: Check that DataGenerator library builds successfully first

### Runtime Issues  
- **GUI doesn't start**: Check DirectX 11 compatibility
- **Console input problems**: Verify input validation logic
- **Random data repetition**: Check random seed initialization

## 🎓 Educational Goals

This project helps students learn:
- **C++ Programming**: Modern C++17 features and best practices
- **Project Structure**: How to organize larger codebases
- **Version Control**: Git workflow and collaboration
- **Documentation**: Writing clear, maintainable code
- **UI Development**: Both console and graphical interfaces
- **Open Source**: Contributing to collaborative projects

## 📞 Support & Contact

- **Issues**: Use GitHub Issues for bug reports and feature requests
- **Discussions**: Use GitHub Discussions for questions and ideas
- **DEVLEV Community**: Connect with other students and mentors

## 📄 License

This project is licensed under the MIT License - see the [LICENSE.txt](LICENSE.txt) file for details.

---

**Made with ❤️ by the DEVLEV Community**

*This project is designed to be a stepping stone for students entering the world of open source development. Every contribution, no matter how small, is valuable and appreciated!*