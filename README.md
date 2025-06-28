# DataGenerator

[![First-time Contributing Guide](https://img.shields.io/badge/First%20Time-Contributing%20Guide-blue.svg)](How_to_start.md)

## Table of Contents
- [Project Overview](#project-overview)
- [How to Contribute](#how-to-contribute)
- [Features](#features)
- [Getting Started](#getting-started)
- [Contributing Guidelines](#contributing-guidelines)
- [Learning Resources](#learning-resources)
- [Support & Contact](#support--contact)
- [About Us](#about-us)

## Project Overview

**DataGenerator** is an open-source C++ Data Generator built specifically for students in the **DEVLEV community**. This educational project provides hands-on experience in contributing to real open-source codebases, serving as a friendly stepping stone into collaborative software development.

The project's primary goal is to **keep growing and evolving** through student contributions. We actively encourage adding new features, datasets, and creative enhancements — making this a living, breathing project that reflects the community's creativity and learning journey.

Currently, DataGenerator offers two distinct interfaces to accommodate students at different skill levels:
- **Console Interface**: Perfect for beginners and students in lower years who want to focus on core C++ concepts
- **GUI Interface**: Built with ImGui and DirectX 11, ideal for advanced students interested in graphical user interfaces

While the current GUI implementation uses C++ with ImGui and DirectX (which can be complex for some contributors), we're planning to support more modern GUI stacks in the future. This makes the project worth following as it continues to evolve and become more accessible to contributors with different backgrounds.

## How to Contribute

Ready to make your first contribution? Here's how to get started:

📖 **First, check out our comprehensive contribution guide**: [How to start](How_to_start.md)

🚀 **Quick Setup Tip**: After cloning the repository, make sure to set the correct project (`DataGeneratorConsole` or `DataGeneratorGUI`) as your **Startup Project** in Visual Studio before building and running.

We **strongly encourage** students to:
- **Add as many features and datasets as you want** — creativity is welcomed!
- **Think outside the box** — fun additions, easter eggs, and even memes are part of the educational experience
- **Start small** — even adding a single name to the data arrays is a valuable contribution
- **Experiment freely** — this is your playground for learning open-source development

### For Beginners (Console Interface)
Perfect starting points for new contributors:
- Add more fields to the generator
- Implement new menu options in the console interface
- Add input validation improvements
- Create new simple generation functions
- **Get creative!** Add your favorite movie characters, book names, or local data from your region

### For Advanced Students (GUI Interface)  
More challenging contributions:
- Enhance the GUI with new windows and features
- Add data visualization capabilities (charts, graphs, statistics)
- Implement advanced export options (JSON, XML, databases)
- Add configuration settings and user preferences
- Improve the user experience with better UI elements
- **Think big!** Add themes, animations, or interactive data exploration features

### Contributing Guidelines

This project is specifically designed for **first-time contributors**! Here's how to get involved:

**🎉 We Welcome ALL Kinds of Creative Contributions!** 
Whether you want to add serious functionality, fun features, creative datasets, or even educational memes and easter eggs — your contribution helps make this project a better learning experience for everyone.

#### Contribution Rules

##### General Guidelines
- **Language**: C++17 standard
- **Naming Convention**: camelCase for functions and variables
- **File Naming**: PascalCase for headers, camelCase for source files
- **Documentation**: Doxygen-style comments for all public functions
- **Formatting**: All code must be formatted using visual studio (or something that achives the same result)
- **Separation**: Clear separation between UI logic and data generation

##### Pull Request Guidelines
- Follow these conventions when naming your Git branches:
   - Use `feat/` followed by a short, descriptive name for the feature you're adding(eg. feat/add_type).
   - Use `fix/` followed by a short description of the bug you're fixing (eg. fix/fix_typo).


We hope to see your bug fixes and improvments to out code!

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

DataGenerator provides two distinct user interfaces, each designed for different learning levels and contribution opportunities:

### Console Interface
- **Simple Menu-Driven Experience**: Perfect for beginners to understand C++ basics
- **Easy Data Generation**: Generate various types of personal data through text-based menus
- **Bulk Operations**: Create multiple records at once with customizable quantities
- **File Export**: Save generated data to CSV format for external use
- **Beginner-Friendly**: Ideal starting point for first-time contributors

### GUI Interface  
- **Modern Graphical Interface**: Built with ImGui library and DirectX 11 rendering
- **Interactive Experience**: Point-and-click interface for more advanced users
- **Visual Data Display**: Enhanced presentation of generated information
- **Advanced Features**: Extended functionality for complex data manipulation
- **Extensible Design**: Perfect platform for students to add creative UI enhancements

Both interfaces share the same powerful core generation engine, allowing students to contribute new data types, generation algorithms, and creative features that benefit the entire community. **We encourage contributors to add their own datasets, implement fun features, and even include easter eggs** — making this project a reflection of our community's creativity and learning spirit!

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

## Learning Resources

### For New Contributors
- [C++ Basics Tutorial](https://www.cplusplus.com/doc/tutorial/)
- [Git Version Control](https://git-scm.com/doc)
- [Visual Studio Guide](https://docs.microsoft.com/en-us/visualstudio/)

### For GUI Development
- [ImGui Documentation](https://github.com/ocornut/imgui)

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

## About Us

### The DEVLEV Community

**DEVLEV** is a vibrant community of students, developers, and mentors passionate about learning, contributing, and growing together in the world of software development. Our mission is to make open-source contribution accessible and enjoyable for students at all levels.

We believe that the best way to learn programming is through hands-on experience with real projects, collaborative development, and supportive mentorship. The DataGenerator project embodies these values by providing a safe, encouraging environment for students to make their first (or hundredth!) open-source contributions.

## License

This project is licensed under the MIT License - see the [LICENSE.txt](LICENSE.txt) file for details.

---

**Made with ❤️ by the DEVLEV Community**

*This project is designed to be a stepping stone for students entering the world of open source development. Every contribution, no matter how small, is valuable and appreciated!*
