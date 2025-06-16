# DataGenerator

[![First-time Contributing Guide](https://img.shields.io/badge/First%20Time-Contributing%20Guide-blue.svg)](https://github.com/firstcontributions/first-contributions)

## Project Overview

DataGenerator is an educational open-source project designed specifically for the **DEVLEV community** to provide students with hands-on experience in contributing to open source projects. This project serves as a friendly introduction to collaborative development, allowing students at different levels to contribute meaningfully to a real codebase.

The project generates random personal data (names, phone numbers, ID numbers) and provides both **Console** and **GUI interfaces** to accommodate students at different skill levels:
- **Console Interface**: Perfect for beginners and students in lower years
- **GUI Interface**: Ideal for advanced students who want to work with graphical user interfaces

## Project Architecture

The project follows a modular C++ architecture with clear separation of concerns:

```
DataGenerator/
├── DataGenerator/          # Core library (generation logic, static lib)
├── DataGeneratorConsole/   # Console application
├── DataGeneratorGUI/       # GUI application using Dear ImGui
│   └── imgui/              # ImGui library files
```

### Core Components

1. **DataGenerator Library** (`DataGenerator/`)
   - Compiled as a static library used by both interfaces

2. **Console Interface** (`DataGeneratorConsole/`)
   - Simple menu-driven interface
   - Perfect for beginners to understand basic C++ concepts

3. **GUI Interface** (`DataGeneratorGUI/`)
   - Modern graphical interface using ImGui library
   - DirectX 11 rendering backend

## Features

### Data Generation Capabilities
- **First Names**: Random selection from predefined list
- **Last Names**: Random selection with duplicate prevention
- **Full Names**: Combination of first and last names
- **Phone Numbers**: Israeli format (XXX-XXXXXXX)
- **ID Numbers**: 8-digit random numbers
- **Full Records**: Complete person data with all fields
- **Bulk Generation**: Generate multiple records at once (1-100 items)
- **Data Export**: Save generated data to CSV files

## Getting Started

### Prerequisites
- **Visual Studio 2019/2022** with C++ development tools
- **Windows 10/11** (required for DirectX 11 GUI support)
- **Git** for version control

### Building the Project

1. **Clone the repository**:
   ```bash
   git clone https://github.com/DevLev-OpenSource/DataGenerator.git
   cd DataGenerator
   ```
   
2. **Open in Visual Studio**:
   - Open `DataGenerator.sln` in Visual Studio
   - The solution contains 3 projects that will build automatically

3. **Build the solution**:
   - Press `Ctrl+Shift+B` or use Build → Build Solution
   - This will create both Console and GUI executables

## Code Conventions

### General Guidelines
- **Language**: C++17 standard
- **Naming Convention**: camelCase for functions and variables
- **File Naming**: PascalCase for headers, camelCase for source files
- **Documentation**: Doxygen-style comments for all public functions
- **Formatting**: All code must be formatted using visual studio (or something that achives the same result)
- **Separation**: Clear separation between UI logic and data generation

## Contributing Guidelines

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

We hope to see your bug fixes and improvments to out code!

### Debugging
- Use Visual Studio debugger for step-through debugging
- Console interface is easier for testing new generation logic

## Learning Resources

### For New Contributors
- [C++ Basics Tutorial](https://www.cplusplus.com/doc/tutorial/)
- [Git Version Control](https://git-scm.com/doc)
- [Visual Studio Guide](https://docs.microsoft.com/en-us/visualstudio/)

### For GUI Development
- [ImGui Documentation](https://github.com/ocornut/imgui)
- [DirectX 11 Tutorial](https://docs.microsoft.com/en-us/windows/win32/direct3d11/)

## Common Issues & Solutions

- **Missing DirectX SDK**: Install Windows SDK through Visual Studio Installer
- **Console input problems**: Verify input validation logic
- **Random data repetition**: Check random seed initialization

## Educational Goals

This project helps students learn:
- **C++ Programming**: Modern C++17 features and best practices
- **Project Structure**: How to organize larger codebases
- **Version Control**: Git workflow and collaboration
- **Documentation**: Writing clear, maintainable code
- **UI Development**: Both console and graphical interfaces
- **Open Source**: Contributing to collaborative projects

## Support & Contact

- **Issues**: Use GitHub Issues for bug reports and feature requests
- **Discussions**: Use GitHub Discussions for questions and ideas
- **DEVLEV Community**: Connect with other students and mentors

## License

This project is licensed under the MIT License - see the [LICENSE.txt](LICENSE.txt) file for details.

---

**Made with ❤️ by the DEVLEV Community**

*This project is designed to be a stepping stone for students entering the world of open source development. Every contribution, no matter how small, is valuable and appreciated!*
