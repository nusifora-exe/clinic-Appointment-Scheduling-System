#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 500
#define MAX_DOCTORS 100
#define MAX_APPOINTMENTS 1000

#define PATIENT_FILE "patients.dat"
#define DOCTOR_FILE "doctors.dat"
#define APPOINTMENT_FILE "appointments.dat"

typedef struct {
    int id;
    char name[50];
    int age;
    char gender[15];
    char phone[20];
    char address[100];
} Patient;

typedef struct {
    int id;
    char name[50];
    char specialization[50];
    char available_time[30];
} Doctor;

typedef struct {
    int id;
    int patient_id;
    int doctor_id;
    char date[20];
    char time[20];
    int status;
} Appointment;

Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
Appointment appointments[MAX_APPOINTMENTS];

int patient_count = 0;
int doctor_count = 0;
int appointment_count = 0;

void load_data(void);
void save_data(void);
void patient_registration(void);
void view_doctors(void);
void add_doctor(void);
void book_appointment(void);
void view_appointments(void);
void search_appointment(void);
void cancel_appointment(void);
void admin_menu(void);
void patient_menu(void);

void load_data(void) {
    FILE *fp;

    fp = fopen(PATIENT_FILE, "rb");
    if (fp != NULL) {
        patient_count = (int)fread(patients, sizeof(Patient), MAX_PATIENTS, fp);
        fclose(fp);
    }

    fp = fopen(DOCTOR_FILE, "rb");
    if (fp != NULL) {
        doctor_count = (int)fread(doctors, sizeof(Doctor), MAX_DOCTORS, fp);
        fclose(fp);
    }

    fp = fopen(APPOINTMENT_FILE, "rb");
    if (fp != NULL) {
        appointment_count = (int)fread(appointments, sizeof(Appointment),
                                       MAX_APPOINTMENTS, fp);
        fclose(fp);
    }
}

void save_data(void) {
    FILE *fp;

    fp = fopen(PATIENT_FILE, "wb");
    if (fp != NULL) {
        fwrite(patients, sizeof(Patient), (size_t)patient_count, fp);
        fclose(fp);
    } else {
        printf("Could not save patient data.\n");
    }

    fp = fopen(DOCTOR_FILE, "wb");
    if (fp != NULL) {
        fwrite(doctors, sizeof(Doctor), (size_t)doctor_count, fp);
        fclose(fp);
    } else {
        printf("Could not save doctor data.\n");
    }

    fp = fopen(APPOINTMENT_FILE, "wb");
    if (fp != NULL) {
        fwrite(appointments, sizeof(Appointment), (size_t)appointment_count, fp);
        fclose(fp);
    } else {
        printf("Could not save appointment data.\n");
    }
}


void patient_registration(void) {
    Patient p;
    int i;
    int valid_phone = 1;

    if (patient_count >= MAX_PATIENTS) {
        printf("\nPatient limit reached!\n");
        return;
    }

    p.id = patient_count + 1;

    printf("\n===== Patient Registration =====\n");

    printf("Enter patient name: ");
    if (scanf(" %49[^\n]", p.name) != 1) {
        printf("Invalid name.\n");
        return;
    }

    printf("Enter age: ");
    if (scanf("%d", &p.age) != 1 || p.age < 1 || p.age > 120) {
        printf("Invalid age. Age must be between 1 and 120.\n");
        return;
    }

    printf("Enter gender (Male/Female/Other): ");
    if (scanf("%14s", p.gender) != 1 ||
        (strcmp(p.gender, "Male") != 0 &&
         strcmp(p.gender, "Female") != 0 &&
         strcmp(p.gender, "Other") != 0)) {
        printf("Invalid gender.\n");
        return;
    }

    printf("Enter phone number: ");
    if (scanf("%19s", p.phone) != 1) {
        printf("Invalid phone number.\n");
        return;
    }

    if (strlen(p.phone) != 11) {
        valid_phone = 0;
    }

    for (i = 0; p.phone[i] != '\0'; i++) {
        if (p.phone[i] < '0' || p.phone[i] > '9') {
            valid_phone = 0;
            break;
        }
    }

    if (!valid_phone) {
        printf("Invalid phone number. Enter exactly 11 digits.\n");
        return;
    }

    printf("Enter address: ");
    if (scanf(" %99[^\n]", p.address) != 1) {
        printf("Invalid address.\n");
        return;
    }

    patients[patient_count++] = p;
    save_data();

    printf("\nRegistration successful! Your Patient ID is: %d\n", p.id);
}


void add_doctor(void) {
    Doctor d;

    if (doctor_count >= MAX_DOCTORS) {
        printf("\nDoctor limit reached!\n");
        return;
    }

    d.id = doctor_count + 1;
    printf("\n===== Add New Doctor =====\n");

    printf("Enter doctor name: ");
    scanf(" %49[^\n]", d.name);

    printf("Enter specialization: ");
    scanf(" %49[^\n]", d.specialization);

    printf("Enter available time: ");
    scanf(" %29[^\n]", d.available_time);

    doctors[doctor_count++] = d;
    save_data();

    printf("\nDoctor added successfully! Doctor ID: %d\n", d.id);
}

void view_doctors(void) {
    int i;

    printf("\n========== Doctor List ==========\n");
    if (doctor_count == 0) {
        printf("No doctors available.\n");
        return;
    }

    for (i = 0; i < doctor_count; i++) {
        printf("\nDoctor ID: %d\n", doctors[i].id);
        printf("Name: %s\n", doctors[i].name);
        printf("Specialization: %s\n", doctors[i].specialization);
        printf("Available Time: %s\n", doctors[i].available_time);
    }
}

int patient_exists(int id) {
    int i;
    for (i = 0; i < patient_count; i++) {
        if (patients[i].id == id) {
            return 1;
        }
    }
    return 0;
}

int doctor_exists(int id) {
    int i;
    for (i = 0; i < doctor_count; i++) {
        if (doctors[i].id == id) {
            return 1;
        }
    }
    return 0;
}

void book_appointment(void) {
    Appointment a;
    int i;

    if (appointment_count >= MAX_APPOINTMENTS) {
        printf("\nAppointment limit reached!\n");
        return;
    }

    if (patient_count == 0 || doctor_count == 0) {
        printf("\nPatient or doctor information is missing.\n");
        return;
    }

    printf("\n===== Book Appointment =====\n");
    printf("Enter Patient ID: ");
    if (scanf("%d", &a.patient_id) != 1 || !patient_exists(a.patient_id)) {
        printf("Patient not found or invalid ID.\n");
        return;
    }

    view_doctors();

    printf("\nEnter Doctor ID: ");
    if (scanf("%d", &a.doctor_id) != 1 || !doctor_exists(a.doctor_id)) {
        printf("Doctor not found or invalid ID.\n");
        return;
    }

    printf("Enter appointment date (DD-MM-YYYY): ");
    scanf(" %19s", a.date);

    printf("Enter appointment time (e.g. 10:00AM): ");
    scanf(" %19s", a.time);

    for (i = 0; i < appointment_count; i++) {
        if (appointments[i].doctor_id == a.doctor_id &&
            strcmp(appointments[i].date, a.date) == 0 &&
            strcmp(appointments[i].time, a.time) == 0 &&
            appointments[i].status == 1) {
            printf("\nSorry! This time slot is already booked.\n");
            return;
        }
    }

    a.id = appointment_count + 1;
    a.status = 1;
    appointments[appointment_count++] = a;
    save_data();

    printf("\nAppointment booked successfully! Appointment ID: %d\n", a.id);
}

void view_appointments(void) {
    int i;

    printf("\n========== Appointment Records ==========\n");
    if (appointment_count == 0) {
        printf("No appointment records found.\n");
        return;
    }

    for (i = 0; i < appointment_count; i++) {
        printf("\nAppointment ID: %d\n", appointments[i].id);
        printf("Patient ID: %d\n", appointments[i].patient_id);
        printf("Doctor ID: %d\n", appointments[i].doctor_id);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("Status: %s\n",
               appointments[i].status == 1 ? "Booked" : "Cancelled");
    }
}

void search_appointment(void) {
    int id, i;

    printf("\nEnter Appointment ID: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid appointment ID.\n");
        return;
    }

    for (i = 0; i < appointment_count; i++) {
        if (appointments[i].id == id) {
            printf("\nAppointment Found!\n");
            printf("Patient ID: %d\n", appointments[i].patient_id);
            printf("Doctor ID: %d\n", appointments[i].doctor_id);
            printf("Date: %s\n", appointments[i].date);
            printf("Time: %s\n", appointments[i].time);
            printf("Status: %s\n",
                   appointments[i].status == 1 ? "Booked" : "Cancelled");
            return;
        }
    }

    printf("\nAppointment not found!\n");
}

void cancel_appointment(void) {
    int id, i;

    printf("\nEnter Appointment ID: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid appointment ID.\n");
        return;
    }

    for (i = 0; i < appointment_count; i++) {
        if (appointments[i].id == id && appointments[i].status == 1) {
            appointments[i].status = 0;
            save_data();
            printf("\nAppointment cancelled successfully!\n");
            return;
        }
    }

    printf("\nActive appointment not found!\n");
}

void admin_menu(void) {
    int choice;
    char username[30], password[30];

    printf("\n===== Administrator Login =====\n");
    printf("Username: ");
    scanf(" %29s", username);
    printf("Password: ");
    scanf(" %29s", password);

    if (strcmp(username, "admin") != 0 || strcmp(password, "1234") != 0) {
        printf("\nInvalid username or password!\n");
        return;
    }

    printf("\nAdmin login successful!\n");

    while (1) {
        printf("\n========== ADMIN MENU ==========\n");
        printf("1. Add Doctor\n");
        printf("2. View Doctors\n");
        printf("3. View Patients\n");
        printf("4. View All Appointments\n");
        printf("5. Search Appointment\n");
        printf("6. Cancel Appointment\n");
        printf("7. Logout\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return;
        }

        switch (choice) {
            case 1:
                add_doctor();
                break;
            case 2:
                view_doctors();
                break;
            case 3: {
                int i;
                printf("\n========== Patient List ==========\n");
                if (patient_count == 0) {
                    printf("No patients registered.\n");
                }
                for (i = 0; i < patient_count; i++) {
                    printf("\nPatient ID: %d\n", patients[i].id);
                    printf("Name: %s\n", patients[i].name);
                    printf("Age: %d\n", patients[i].age);
                    printf("Gender: %s\n", patients[i].gender);
                    printf("Phone: %s\n", patients[i].phone);
                    printf("Address: %s\n", patients[i].address);
                }
                break;
            }
            case 4:
                view_appointments();
                break;
            case 5:
                search_appointment();
                break;
            case 6:
                cancel_appointment();
                break;
            case 7:
                printf("\nAdmin logged out.\n");
                return;
            default:
                printf("\nInvalid choice!\n");
        }
    }
}

void patient_menu(void) {
    int choice;

    while (1) {
        printf("\n========== PATIENT MENU ==========\n");
        printf("1. Register Patient\n");
        printf("2. View Doctors\n");
        printf("3. Book Appointment\n");
        printf("4. Search Appointment\n");
        printf("5. Cancel Appointment\n");
        printf("6. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return;
        }

        switch (choice) {
            case 1:
                patient_registration();
                break;
            case 2:
                view_doctors();
                break;
            case 3:
                book_appointment();
                break;
            case 4:
                search_appointment();
                break;
            case 5:
                cancel_appointment();
                break;
            case 6:
                return;
            default:
                printf("\nInvalid choice!\n");
        }
    }
}

int main(void) {
    int choice;

    load_data();

    printf("\n============================================\n");
    printf("     CLINIC APPOINTMENT SCHEDULING SYSTEM\n");
    printf("============================================\n");

    while (1) {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Administrator\n");
        printf("2. Patient\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please restart the program.\n");
            break;
        }

        switch (choice) {
            case 1:
                admin_menu();
                break;
            case 2:
                patient_menu();
                break;
            case 3:
                save_data();
                printf("\nThank you for using our system!\n");
                return 0;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}