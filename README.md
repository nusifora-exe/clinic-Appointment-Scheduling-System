# 🏥 Clinic Appointment Scheduling System

<p align="center">
  <img src="https://img.shields.io/badge/Project-Academic%20Capstone-blue?style=for-the-badge" alt="Academic Capstone Project" />
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c" alt="C Language" />
  <img src="https://img.shields.io/badge/Standard-C99-orange?style=for-the-badge" alt="C99" />
  <img src="https://img.shields.io/badge/Compiler-GCC-green?style=for-the-badge&logo=gnu" alt="GCC" />
  <img src="https://img.shields.io/badge/Version%20Control-Git%20%26%20GitHub-black?style=for-the-badge&logo=github" alt="Git and GitHub" />
</p>

<p align="center">
  <b>A Console-Based Clinic Management and Appointment Scheduling Application</b>
  <br />
  Developed using C Programming and File Handling
</p>

---

## 📌 Table of Contents

- [About the Project](#-about-the-project)
- [Project Objectives](#-project-objectives)
- [Key Features](#-key-features)
- [System Modules](#-system-modules)
- [Technology Stack](#-technology-stack)
- [C Programming Concepts](#-c-programming-concepts)
- [Project Structure](#-project-structure)
- [Installation and Setup](#-installation-and-setup)
- [How to Run](#-how-to-run)
- [Data Storage](#-data-storage)
- [Future Improvements](#-future-improvements)
- [Project Team](#-project-team)
- [Project Supervisor](#-project-supervisor)
- [Academic Information](#-academic-information)

---

## 📖 About the Project

The **Clinic Appointment Scheduling System** is a console-based application developed in the C programming language to simplify and organize appointment management in clinics.

The project aims to provide an organized way to manage doctor information, patient records, doctor availability, and appointment scheduling.

By using file handling, the application can store and retrieve information locally, reducing the need for manual record-keeping.

This project is developed as an academic capstone project by **Team NOVA CORE**.

## 🎯 Project Objectives

- Simplify the clinic appointment scheduling process.
- Organize patient registration and information management.
- Maintain doctor profiles and specialization details.
- Manage doctor schedules and availability.
- Reduce scheduling conflicts and duplicate bookings.
- Store and retrieve records using file handling.
- Apply fundamental C programming concepts to a practical project.

## 🚀 Key Features

### 👨‍⚕️ Doctor Management
- Add doctor information.
- View registered doctors.
- Search for doctor records.
- Update doctor information.
- Manage doctor schedules.

### 🧑‍🤝‍🧑 Patient Management
- Patient registration.
- Store and manage patient information.
- Access patient-related records.

### 📅 Appointment Management
- Schedule clinic appointments.
- View appointment information.
- Search appointment records.
- Cancel appointments.
- Prevent duplicate or conflicting bookings where implemented.

### 💾 File Management
- Store records in local files.
- Retrieve previously saved information.
- Maintain data between program executions.

> **Note:** The final availability of each feature depends on the integration and completion of the corresponding team modules.

## 🧩 System Modules

The project is organized into separate functional modules to make development and maintenance easier.

| Module | Description |
|---|---|
| Admin Management | Administrative operations and record management |
| Patient Management | Patient registration and patient records |
| Doctor Management | Doctor information and profile management |
| Doctor Schedule Management | Doctor working days, time slots, and availability |
| Appointment Management | Appointment scheduling and record management |

## 🛠️ Technology Stack

<p>
  <img src="https://img.shields.io/badge/C-Programming%20Language-00599C?style=flat-square&logo=c" alt="C" />
  <img src="https://img.shields.io/badge/GCC-Compiler-A42E2B?style=flat-square&logo=gnu" alt="GCC" />
  <img src="https://img.shields.io/badge/VS%20Code-Code%20Editor-007ACC?style=flat-square&logo=visualstudiocode" alt="VS Code" />
  <img src="https://img.shields.io/badge/Git-Version%20Control-F05032?style=flat-square&logo=git" alt="Git" />
  <img src="https://img.shields.io/badge/GitHub-Collaboration-181717?style=flat-square&logo=github" alt="GitHub" />
</p>

| Technology | Purpose |
|---|---|
| C | Core programming language |
| C99 | C language standard |
| GCC / MinGW-w64 | C compiler |
| Visual Studio Code | Code editor |
| File Handling | Local data storage |
| Git | Version control |
| GitHub | Team collaboration and source code hosting |

## 🧠 C Programming Concepts

The project applies several fundamental concepts of C programming:

- Structures (`struct`)
- Arrays
- Functions
- Pointers
- Conditional statements
- Loops
- Strings
- File handling
- Modular programming

## 📁 Project Structure

The repository is organized into a main application and separate module directories.

```text
Clinic-Appointment-Scheduling-System/
│
├── .gitignore
├── LICENSE
├── README.md
├── main.c
│
└── Member2_DoctorSchedule/
    └── doctor_schedule.c
```

Additional module folders and source files may be added as the team integrates the remaining components.

Runtime data files are generated by the application when required and are not necessarily included in the repository.

## ⚙️ Installation and Setup

### Prerequisites

Before running the project, make sure you have:

- Windows, Linux, or macOS.
- GCC compiler installed.
- Visual Studio Code or another C code editor.
- Git installed (for cloning the repository).

### 1. Clone the Repository

Open a terminal and run:

```bash
git clone https://github.com/nusifora-exe/clinic-Appointment-Scheduling-System.git
```

### 2. Navigate to the Project Folder

```bash
cd clinic-Appointment-Scheduling-System
```

### 3. Compile the Main Application

When the team-integrated `main.c` is ready to build independently, compile it using:

```bash
gcc -std=c99 -Wall -Wextra main.c -o clinic
```

> If the integrated application uses multiple source files, include those source files in the compilation command as well.

## ▶️ How to Run

**Windows:**

```powershell
.\clinic.exe
```

**Linux / macOS:**

```bash
./clinic
```

For an individual module, compile its source file separately using the appropriate GCC command when that module is designed to run independently.

## 💾 Data Storage

The application uses C file handling to store and retrieve information locally.

Depending on the module, data files may contain:

- Patient information
- Doctor information
- Doctor schedule information
- Appointment records

This approach allows stored records to remain available after the program is closed, provided the application successfully saves them.

## 🔮 Future Improvements

Potential improvements for future development include:

- Patient login and authentication.
- Improved administrative authentication.
- More comprehensive date and time validation.
- Enhanced doctor availability management.
- Appointment reports and summaries.
- Automated appointment reminders.
- Graphical user interface (GUI).
- Database integration.

## 👥 Project Team — NOVA CORE

<p align="center">
  <b>Meet the team behind the project</b>
</p>

<table align="center">
  <tr>
    <td align="center">
      <a href="https://github.com/nusifora-exe">
        <img src="https://github.com/nusifora-exe.png" width="100" height="100" alt="Nusrat Shifa GitHub profile picture" />
        <br />
        <b>Nusrat Shifa</b>
      </a>
      <br />
      <sub>Team Leader</sub>
    </td>
    <td align="center">
      <a href="https://github.com/zmiramoni">
        <img src="https://github.com/zmiramoni.png" width="100" height="100" alt="Zannatul Mowya Iramoni GitHub profile picture" />
        <br />
        <b>Zannatul Mowya Iramoni</b>
      </a>
      <br />
      <sub>Member 2</sub>
    </td>
    <td align="center">
      <a href="https://github.com/shahabid75">
        <img src="https://github.com/shahabid75.png" width="100" height="100" alt="Shah Tasnim Abid GitHub profile picture" />
        <br />
        <b>Shah Tasnim Abid</b>
      </a>
      <br />
      <sub>Team Member</sub>
    </td>
  </tr>
  <tr>
    <td align="center">
      <a href="https://github.com/Rakibul78600">
        <img src="https://github.com/Rakibul78600.png" width="100" height="100" alt="Md. Rakibul Islam GitHub profile picture" />
        <br />
        <b>Md. Rakibul Islam</b>
      </a>
      <br />
      <sub>Team Member</sub>
    </td>
    <td align="center">
      <a href="https://github.com/sornabyte">
        <img src="https://github.com/sornabyte.png" width="100" height="100" alt="Shorna Islam GitHub profile picture" />
        <br />
        <b>Shorna Islam</b>
      </a>
      <br />
      <sub>Team Member</sub>
    </td>
    <td></td>
  </tr>
</table>

## 🎓 Project Supervisor

<p align="center">
  <a href="https://github.com/MehediHFaysal">
    <img src="https://github.com/MehediHFaysal.png" width="110" height="110" alt="Mehedi Hasan Faysal GitHub profile picture" />
    <br />
    <b>Mehedi Hasan Faysal</b>
  </a>
  <br />
  <sub>Project Supervisor</sub>
</p>

## 📚 Academic Information

| Category | Details |
|---|---|
| Project Name | Clinic Appointment Scheduling System |
| Team Name | NOVA CORE |
| Project Type | Academic Capstone Project |
| Programming Language | C |
| Course | Capstone Project |
| Supervisor | Mehedi Hasan Faysal |

---

## ❤️ Acknowledgement

This project is a collaborative effort by **Team NOVA CORE**. Through this project, the team aims to strengthen practical programming skills, teamwork, problem-solving, and software development knowledge.

<p align="center">
  <b>Built with dedication by Team NOVA CORE</b>
  <br />
  <sub>Clinic Appointment Scheduling System</sub>
</p>
