# 📁 File Explorer Application

[![C++](https://img.shields.io/badge/C%2B%2B-11%2F14%2F17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)](https://www.linux.org/)
[![License](https://img.shields.io/badge/License-MIT-blue.svg?style=for-the-badge)](LICENSE)
[![Build Status](https://img.shields.io/badge/Build-Passing-brightgreen?style=for-the-badge)](https://github.com/)
[![Version](https://img.shields.io/badge/Version-1.0.0-purple?style=for-the-badge)](https://github.com/)

<div align="center">
  <img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=30&pause=1000&color=36BCF7&center=true&vCenter=true&width=600&lines=Console+Based+File+Explorer;Built+with+C%2B%2B+for+Linux;Navigate+%7C+Create+%7C+Search+%7C+Manage" alt="Typing SVG" />
</div>

## 📋 Table of Contents

- [📖 About The Project](#-about-the-project)
- [✨ Features](#-features)
- [🎬 Demo](#-demo)
- [🚀 Getting Started](#-getting-started)
- [💻 Usage](#-usage)
- [📸 Screenshots](#-screenshots)
- [🏗️ Architecture](#️-architecture)
- [🧪 Testing](#-testing)
- [🤝 Contributing](#-contributing)
- [📝 License](#-license)
- [👨‍💻 Author](#-author)
- [🙏 Acknowledgments](#-acknowledgments)

---

## 📖 About The Project

<div align="center">
  <img src="https://img.shields.io/badge/Assignment-Linux%20OS%20Capstone%20Project-orange?style=for-the-badge" alt="Assignment Badge"/>
</div>

**File Explorer Application** is a powerful console-based file management system built in C++ for Linux operating systems. This project demonstrates system-level programming by interfacing directly with Linux OS through POSIX APIs to provide comprehensive file and directory management capabilities.

### 🎯 Project Objectives

- ✅ Develop a console-based file management system
- ✅ Interface with Linux OS using system calls
- ✅ Implement CRUD operations for files and directories
- ✅ Provide intuitive navigation and search functionality
- ✅ Display file permissions and metadata

### 🛠️ Built With

- **Programming Language:** C++ (Standard C++11/14/17)
- **Operating System:** Linux (Ubuntu/Debian)
- **System Libraries:** POSIX API, dirent.h, sys/stat.h
- **Development Tools:** g++ compiler, VS Code/Vim

---

## ✨ Features

<table>
<tr>
<td>

### 📂 **File Operations**
- 📄 Create new files with content
- 📋 Copy files (text & binary)
- 🗑️ Delete files safely
- 📊 Display file listings

</td>
<td>

### 🗂️ **Directory Management**
- 📁 Navigate directories
- ⬆️ Move to parent directory
- 📍 Track current location
- 🔄 Real-time path updates

</td>
</tr>
<tr>
<td>

### 🔍 **Search & Filter**
- 🔎 Search files by name
- 📝 Pattern matching
- 📊 Result counting
- 🏷️ Type identification

</td>
<td>

### 🔐 **File Information**
- 📏 File size display
- 🔑 Permission viewing (r/w/x)
- 📅 Modification timestamps
- ℹ️ Detailed metadata

</td>
</tr>
</table>

---

## 🎬 Demo

<div align="center">
  <img src="https://via.placeholder.com/800x400/1a1a2e/16213e?text=File+Explorer+Demo" alt="Demo GIF"/>
  <br>
  <em>File Explorer in action - Navigation, Creation, and Search</em>
</div>

---

## 🚀 Getting Started

### 📋 Prerequisites

Before you begin, ensure you have the following installed:

```bash
# Check if g++ is installed
g++ --version

# If not installed, run:
sudo apt update
sudo apt install g++ build-essential
