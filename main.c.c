/*
  Clinic Appointment Scheduling System
  Beginner-friendly C project using structures, functions, arrays and file handling.
  Compile: gcc clinic_appointment.c -o clinic_appointment
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SLOTS 100
#define MAX_PATIENTS 100
#define NAME_LEN 50
#define PHONE_LEN 20
#define DATE_LEN 20
#define TIME_LEN 20

#define SLOT_FILE "slots.txt"
#define PATIENT_FILE "patients.txt"

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} Patient;

typedef struct {
    char doctor[NAME_LEN];
    char date[DATE_LEN];
    char time[TIME_LEN];
    int booked;                 /* 0 = available, 1 = booked */
    char patientName[NAME_LEN];
    char patientPhone[PHONE_LEN];
} AppointmentSlot;

Patient patients[MAX_PATIENTS];
AppointmentSlot slots[MAX_SLOTS];
int patientCount = 0;
int slotCount = 0;

/* Read a line safely and remove its newline character. */
void readText(const char prompt[], char value[], int size) {
    printf("%s", prompt);
    if (fgets(value, size, stdin) != NULL) {
        value[strcspn(value, "\n")] = '\0';
    }
}

/* Read a menu number. */
int readNumber(const char prompt[]) {
    char line[30];
    readText(prompt, line, sizeof(line));
    return atoi(line);
}

/* Load saved patient records when the program starts. */
void loadPatients(void) {
    FILE *file = fopen(PATIENT_FILE, "r");
    if (file == NULL) return;

    patientCount = 0;
    while (patientCount < MAX_PATIENTS &&
           fscanf(file, " %49[^|]|%19[^\n]\n",
                  patients[patientCount].name,
                  patients[patientCount].phone) == 2) {
        patientCount++;
    }
    fclose(file);
}

/* Save all patient records. */
void savePatients(void) {
    FILE *file = fopen(PATIENT_FILE, "w");
    if (file == NULL) {
        printf("Could not save patient information.\n");
        return;
    }

    for (int i = 0; i < patientCount; i++) {
        fprintf(file, "%s|%s\n", patients[i].name, patients[i].phone);
    }
    fclose(file);
}

/* Load appointment slots from the file. */
void loadSlots(void) {
    FILE *file = fopen(SLOT_FILE, "r");
    if (file == NULL) return;

    slotCount = 0;
    while (slotCount < MAX_SLOTS &&
           fscanf(file, " %49[^|]|%19[^|]|%19[^|]|%d|%49[^|]|%19[^\n]\n",
                  slots[slotCount].doctor,
                  slots[slotCount].date,
                  slots[slotCount].time,
                  &slots[slotCount].booked,
                  slots[slotCount].patientName,
                  slots[slotCount].patientPhone) == 6) {
        slotCount++;
    }
    fclose(file);
}

/* Save appointment slots, including their current booking status. */
void saveSlots(void) {
    FILE *file = fopen(SLOT_FILE, "w");
    if (file == NULL) {
        printf("Could not save appointment slots.\n");
        return;
    }

    for (int i = 0; i < slotCount; i++) {
        fprintf(file, "%s|%s|%s|%d|%s|%s\n",
                slots[i].doctor, slots[i].date, slots[i].time,
                slots[i].booked, slots[i].patientName,
                slots[i].patientPhone);
    }
    fclose(file);
}

int findPatient(const char phone[]) {
    for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].phone, phone) == 0) return i;
    }
    return -1;
}

/* Patient registration is available from the patient menu. */
void registerPatient(void) {
    if (patientCount >= MAX_PATIENTS) {
        printf("Patient list is full.\n");
        return;
    }

    Patient p;
    readText("Enter your full name: ", p.name, NAME_LEN);
    readText("Enter your phone number: ", p.phone, PHONE_LEN);

    if (strlen(p.name) == 0 || strlen(p.phone) == 0) {
        printf("Name and phone number cannot be empty.\n");
        return;
    }

    if (findPatient(p.phone) != -1) {
        printf("This phone number is already registered.\n");
        return;
    }

    patients[patientCount++] = p;
    savePatients();
    printf("Registration completed successfully.\n");
}

/* Admin adds a doctor's available date and time. */
void addDoctorSlot(void) {
    if (slotCount >= MAX_SLOTS) {
        printf("No more slots can be added.\n");
        return;
    }

    AppointmentSlot newSlot;
    readText("Enter doctor name: ", newSlot.doctor, NAME_LEN);
    readText("Enter date (DD-MM-YYYY): ", newSlot.date, DATE_LEN);
    readText("Enter time (e.g. 10:00 AM): ", newSlot.time, TIME_LEN);

    if (strlen(newSlot.doctor) == 0 ||
        strlen(newSlot.date) == 0 || strlen(newSlot.time) == 0) {
        printf("All fields are required.\n");
        return;
    }

    /* Do not create the same doctor's slot twice. */
    for (int i = 0; i < slotCount; i++) {
        if (strcmp(slots[i].doctor, newSlot.doctor) == 0 &&
            strcmp(slots[i].date, newSlot.date) == 0 &&
            strcmp(slots[i].time, newSlot.time) == 0) {
            printf("This doctor's time slot already exists.\n");
            return;
        }
    }

    newSlot.booked = 0;
    strcpy(newSlot.patientName, "-");
    strcpy(newSlot.patientPhone, "-");

    slots[slotCount++] = newSlot;
    saveSlots();
    printf("Doctor's available time slot added.\n");
}

/* Display all slots, or only the available ones. */
void showSlots(int availableOnly) {
    int found = 0;

    printf("\n--------------- APPOINTMENT SLOTS ---------------\n");
    printf("%-5s %-20s %-12s %-12s %-12s\n",
           "No.", "Doctor", "Date", "Time", "Status");

    for (int i = 0; i < slotCount; i++) {
        if (availableOnly && slots[i].booked) continue;

        printf("%-5d %-20s %-12s %-12s %-12s\n",
               i + 1, slots[i].doctor, slots[i].date,
               slots[i].time, slots[i].booked ? "Booked" : "Available");
        found = 1;
    }

    if (!found) printf("No matching appointment slots found.\n");
}

/* Admin can view every slot and its booking status. */
void viewAllAppointments(void) {
    showSlots(0);
}

/* Patient chooses an available slot and books it. */
void bookAppointment(void) {
    char phone[PHONE_LEN];
    readText("Enter your registered phone number: ", phone, PHONE_LEN);

    int patientIndex = findPatient(phone);
    if (patientIndex == -1) {
        printf("You are not registered. Please register first.\n");
        return;
    }

    showSlots(1);
    if (slotCount == 0) return;

    int choice = readNumber("Enter the slot number you want to book: ");
    if (choice < 1 || choice > slotCount) {
        printf("Invalid slot number.\n");
        return;
    }

    int index = choice - 1;

    /* This check prevents a second patient from booking the same slot. */
    if (slots[index].booked) {
        printf("Sorry, this slot has already been booked.\n");
        return;
    }

    slots[index].booked = 1;
    strcpy(slots[index].patientName, patients[patientIndex].name);
    strcpy(slots[index].patientPhone, patients[patientIndex].phone);
    saveSlots();

    printf("\nAppointment booked successfully!\n");
    printf("Doctor: %s\nDate: %s\nTime: %s\n",
           slots[index].doctor, slots[index].date, slots[index].time);
}

/* Patient can see their own appointments. */
void viewMyAppointments(void) {
    char phone[PHONE_LEN];
    int found = 0;

    readText("Enter your registered phone number: ", phone, PHONE_LEN);
    if (findPatient(phone) == -1) {
        printf("Patient not found. Please register first.\n");
        return;
    }

    printf("\nYour appointments:\n");
    for (int i = 0; i < slotCount; i++) {
        if (slots[i].booked &&
            strcmp(slots[i].patientPhone, phone) == 0) {
            printf("Doctor: %s | Date: %s | Time: %s\n",
                   slots[i].doctor, slots[i].date, slots[i].time);
            found = 1;
        }
    }

    if (!found) printf("You do not have any appointments yet.\n");
}

void adminMenu(void) {
    char password[30];
    readText("Enter admin password: ", password, sizeof(password));

    /* Change this simple password before your project demonstration. */
    if (strcmp(password, "admin123") != 0) {
        printf("Incorrect password.\n");
        return;
    }

    int choice;
    do {
        printf("\n========== ADMIN MENU ==========\n");
        printf("1. Add doctor availability\n");
        printf("2. View all appointments\n");
        printf("3. Register a patient\n");
        printf("0. Back to main menu\n");

        choice = readNumber("Enter your choice: ");

        switch (choice) {
            case 1: addDoctorSlot(); break;
            case 2: viewAllAppointments(); break;
            case 3: registerPatient(); break;
            case 0: break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);
}

void patientMenu(void) {
    int choice;
    do {
        printf("\n========== PATIENT MENU ==========\n");
        printf("1. Register as a patient\n");
        printf("2. View available time slots\n");
        printf("3. Book an appointment\n");
        printf("4. View my appointments\n");
        printf("0. Back to main menu\n");

        choice = readNumber("Enter your choice: ");

        switch (choice) {
            case 1: registerPatient(); break;
            case 2: showSlots(1); break;
            case 3: bookAppointment(); break;
            case 4: viewMyAppointments(); break;
            case 0: break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);
}

int main(void) {
    loadPatients();
    loadSlots();

    int choice;
    printf("========================================\n");
    printf("   CLINIC APPOINTMENT SCHEDULING SYSTEM\n");
    printf("========================================\n");

    do {
        printf("\n============== MAIN MENU ==============\n");
        printf("1. Admin\n");
        printf("2. Patient\n");
        printf("0. Exit\n");

        choice = readNumber("Enter your choice: ");

        switch (choice) {
            case 1: adminMenu(); break;
            case 2: patientMenu(); break;
            case 0: printf("Thank you for using the system.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
