
# 🏥 Clinic Appointment Scheduling System

A console-based clinic appointment management application developed using C programming and file handling.

---

## 📌 Project Overview

The **Clinic Appointment Scheduling System** is a C-based application designed to simplify and organize the appointment management process in clinics.

The system provides administrative and patient-oriented functionalities for managing doctor information, patient records, and appointment schedules. It allows users to register patients, view doctor information, book appointments, and manage existing appointment records.

The application uses C file handling to store and retrieve information locally, helping maintain records even after the program is closed.

---

## 🎯 Project Objectives

- Simplify clinic appointment scheduling.
- Maintain patient registration records.
- Manage doctor information and availability.
- Provide administrative and patient-oriented interfaces.
- Prevent duplicate appointment bookings.
- Store and retrieve records using C file handling.
- Reduce manual work in appointment management.

---

## 🚀 Key Features

- **Administrative Module:** Manage doctor information and clinic records.
- **Patient Registration:** Register patients and maintain their information.
- **Doctor Management:** Add and view doctor information.
- **Doctor Availability:** Display doctor availability information.
- **Appointment Scheduling:** Book available appointments.
- **Double Booking Prevention:** Check whether an appointment slot has already been booked.
- **Appointment Cancellation:** Cancel existing appointments.
- **Appointment Search:** Search and view appointment records.
- **File Handling:** Store patient, doctor, and appointment information in local files.

---

## 🛠️ Technology Stack

| Component | Technology |
|---|---|
| Programming Language | C |
| Language Standard | C99 |
| Compiler | GCC / MinGW-w64 |
| Code Editor | Visual Studio Code |
| Data Storage | C File Handling |
| Version Control | Git |
| Collaboration Platform | GitHub |

### C Programming Concepts

- Structures (`struct`)
- Arrays
- Functions
- Pointers
- Conditional Statements
- Loops
- String Manipulation
- File Handling

---

## 👨‍💼 Administrative Module

The administrator can:

1. Access the administrative interface.
2. Add and manage doctor information.
3. View doctor records.
4. Manage patient information.
5. View and manage appointment records.

---

## 🧑‍⚕️ Patient Interface

The patient-oriented functionalities include:

1. Register patient information.
2. View available doctors.
3. Check appointment information.
4. Book an appointment.
5. Search appointment details.
6. Cancel an appointment.

---

## 📂 Project Structure

```text
Clinic-Appointment-Scheduling-System/
│
├── main.c
├── README.md
├── LICENSE
│
└── Data Files (Generated Automatically)
    ├── patients.dat
    ├── doctors.dat
    └── appointments.dat
```

**Note:** Data files are generated automatically by the program when records are saved, if they do not already exist.

---

## ⚙️ How to Run

### Using Visual Studio Code

1. Install Visual Studio Code.
2. Install the C/C++ extension.
3. Install GCC compiler (MinGW-w64).
4. Download or clone this repository.
5. Extract the project folder and open it in VS Code.
6. Open the integrated terminal.
7. Compile the program:

```bash
gcc -std=c99 -Wall -Wextra main.c -o clinic
```

8. Run the program on Windows:

```powershell
.\clinic.exe
```

9. Follow the on-screen menu instructions.

### Using GCC

Compile the program:

```bash
gcc -std=c99 -Wall -Wextra main.c -o clinic
```

Run on Windows:

```powershell
.\clinic.exe
```

Run on Linux or macOS:

```bash
./clinic
```

---

## 🔒 Double Booking Prevention

The system checks the selected doctor's appointment slot before confirming a booking.

- If the slot is available, the appointment can be confirmed.
- If the slot is already booked, the system rejects the duplicate booking.
- After successful booking, the appointment status is updated.
- When an appointment is cancelled, its availability can be restored.

---

## 🔮 Future Improvements

- Introduce patient login and account management.
- Improve administrator authentication and password security.
- Implement advanced date and time validation.
- Improve doctor availability and scheduling management.
- Generate daily and monthly appointment reports.
- Add appointment reminders.
- Develop a graphical user interface.
- Explore database integration for future versions.

---

## 👥 Team Information

**Project Name:** Clinic Appointment Scheduling System

**Team Name:** NOVA CORE

**Project Type:** Academic Capstone Project

**Programming Language:** C

### Team Members

1. Sifa Akter
2. Zannatul Mowya Iramoni
3. Shah Tasnim Abid
4. Md. Rakibul Islam
5. Shorna Islam

### Project Supervisor

**Teacher:** Mehedi Hasan Faysal

**Course:** Capstone Project

---

## 🏁 Conclusion

The Clinic Appointment Scheduling System demonstrates how C programming and file handling can be used to develop a practical clinic appointment management application.

By organizing patient records, doctor information, and appointment schedules, the system aims to reduce manual workload and improve appointment management efficiency.

---

**Developed as an academic Capstone Project using C programming.**
