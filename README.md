
# 🏥 Clinic Appointment Scheduling System

A C-based application designed to manage clinic appointments, patient registration, and doctor availability using file handling.

---

## 📌 Project Overview
The Clinic Appointment Scheduling System is a C-based application designed to simplify and organize the appointment management process in clinics. It allows administrators to manage doctor information, patient records, and appointment schedules efficiently. Patients can check doctor availability and book appointments easily. The system uses file handling to maintain records and ensures accurate appointment management by preventing scheduling conflicts.

---

## 🎯 Objectives

- Simplify clinic appointment scheduling.
- Maintain patient registration records.
- Manage doctor schedules and available time slots.
- Provide separate administrative and patient interfaces.
- Prevent duplicate bookings through automatic slot updates.
- Store and retrieve records using C file handling.

---

## 🚀 Key Features

- **Administrative Module:** Manage doctor schedules, time slots, and patient registration.
- **Patient Registration:** Register patients and maintain their information.
- **Doctor Availability:** Display doctors and their available appointment slots.
- **Appointment Scheduling:** Allow patients to select a doctor and book an available time slot.
- **Double Booking Prevention:** Prevent multiple patients from booking the same doctor's time slot.
- **Automatic Slot Updates:** Mark booked slots as unavailable and restore availability when an appointment is cancelled.
- **Appointment Management:** View, search, and cancel appointment records.
- **File Handling:** Save patient, doctor schedule, and appointment information in local files.

---

## 🛠️ Tech Stack & Tools

- **Programming Language:** C (C99 or higher)
- **Compiler:** GCC / MinGW
- **IDE:** Code::Blocks
- **Storage:** C File Handling
- **File Operations:** `fopen()`, `fprintf()`, `fgets()`, `fscanf()`, `fclose()`
- **Version Control:** Git and GitHub

---

## 👨‍💼 Administrative Module

The administrator can:

1. View and manage doctor information.
2. Set doctor availability and working schedules.
3. Create and manage appointment time slots.
4. Register patients.
5. View and manage appointment records.
6. Monitor booked and available slots.

---

## 🧑‍⚕️ Patient Interface

Patients can:

1. Register their information.
2. View available doctors.
3. Check available appointment dates and times.
4. Book an available appointment.
5. Search their appointment details.
6. Cancel an existing appointment.

---

## 📂 Project Structure

```text
ClinicAppointmentSystem/
│
├── main.c
├── README.md
├── patients.txt
├── doctors.txt
├── schedules.txt
└── appointments.txt
```

*Note: The data files can be created automatically by the program when records are saved.*

---

## ⚙️ How to Run

### Using VS CODE
1. Install Visual Studio Code (VS Code) on your computer.
2. Install a C/C++ extension in VS Code.
3. Install a GCC compiler to compile and run C programs.
4. Create a project folder and open it in VS Code.
5. Create a `main.c` file and paste the project source code into it.
6. Open the terminal and compile the program using `gcc main.c -o main`.
7. Run the program using `.\main` in the terminal.
8. Follow the on-screen menu instructions to use the system.


### Using GCC

Compile the program:

```bash
gcc -std=c99 -Wall -Wextra main.c -o clinic
```

Run on Windows:

```bash
clinic.exe
```

Run on Linux or macOS:

```bash
./clinic
```

---

## 💡 C Programming Concepts

- Structures
- Arrays
- Functions
- Pointers
- Conditional Statements
- Loops
- String Handling
- File Handling

---

## 🔒 Double Booking Prevention

Before confirming an appointment, the system checks whether the selected doctor's time slot is already booked.

- If the slot is available, the appointment is confirmed.
- If the slot is already booked, the system rejects the request.
- After successful booking, the slot is marked as unavailable.
- When an appointment is cancelled, the slot can become available again.

---

## 🔮 Future Improvements

- Integrate a MySQL database.
- Add secure administrator and patient login.
- Add appointment reminders.
- Generate daily and monthly reports.
- Develop a graphical user interface.
- Improve date validation and doctor availability management.

---

## 👥 Team Information

- **Project Name:** Clinic Appointment Scheduling System
- **Language:** C
- **Project Type:** Academic Project
- **Team Name:** [NOVA CORE]

### Collaborators

- [Sifa akter]
- [Zannatul Mowya Iramoni]
- [Shah Tasnim Abid]
- [Md Rakibul Islam]
- [Shorna Islam]

### Project Supervisor

- **Teacher:** [Mehedi Hasan Faysal]
- **Course:** [Capstone Project]

---

## 🏁 Conclusion

The Clinic Appointment Scheduling System provides an organized approach to managing patient registration, doctor schedules, and clinic appointments. By using C programming and file handling, the project demonstrates how a computerized system can reduce manual work and prevent appointment scheduling conflicts.

---

**Developed as an academic project using C programming.**

