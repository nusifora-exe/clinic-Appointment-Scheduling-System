
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DOCTORS 100
#define FILE_NAME "doctor_schedule.dat"

typedef struct {
    int id;
    char name[50];
    char specialization[50];
    char available_time[50];
} Doctor;

Doctor doctors[MAX_DOCTORS];
int doctorCount = 0;

// Function declarations
void loadDoctors();
void saveDoctors();
void setDoctorSchedule();
void viewDoctorSchedules();
void manageTimeSlots();

int main() {
    int choice;

    loadDoctors();

    while (1) {
        printf("\n================================\n");
        printf(" DOCTOR SCHEDULE MANAGEMENT\n");
        printf("          MEMBER 2\n");
        printf("================================\n");

        printf("1. Set Doctor Schedules\n");
        printf("2. View Doctor Schedules\n");
        printf("3. Manage Available Time Slots\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                setDoctorSchedule();
                break;

            case 2:
                viewDoctorSchedules();
                break;

            case 3:
                manageTimeSlots();
                break;

            case 4:
                saveDoctors();
                printf("Thank you!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Load doctor information
void loadDoctors() {
    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp != NULL) {
        doctorCount = (int)fread(
            doctors, sizeof(Doctor), MAX_DOCTORS, fp
        );
        fclose(fp);
    }
}

// Save doctor information
void saveDoctors() {
    FILE *fp = fopen(FILE_NAME, "wb");

    if (fp != NULL) {
        fwrite(doctors, sizeof(Doctor), doctorCount, fp);
        fclose(fp);
    }
}

// Set doctor schedule
void setDoctorSchedule() {
    Doctor d;

    if (doctorCount >= MAX_DOCTORS) {
        printf("Doctor limit reached!\n");
        return;
    }

    d.id = doctorCount + 1;

    printf("\nEnter Doctor Name: ");
    scanf(" %49[^\n]", d.name);

    printf("Enter Specialization: ");
    scanf(" %49[^\n]", d.specialization);

    printf("Enter Available Time: ");
    scanf(" %49[^\n]", d.available_time);

    doctors[doctorCount++] = d;

    saveDoctors();

    printf("\nDoctor schedule saved successfully!\n");
}

// View doctor schedules
void viewDoctorSchedules() {
    int i;

    if (doctorCount == 0) {
        printf("\nNo doctor records found!\n");
        return;
    }

    for (i = 0; i < doctorCount; i++) {
        printf("\nDoctor ID: %d\n", doctors[i].id);
        printf("Name: %s\n", doctors[i].name);
        printf("Specialization: %s\n",
               doctors[i].specialization);
        printf("Available Time: %s\n",
               doctors[i].available_time);
    }
}

// Manage available time slots
void manageTimeSlots() {
    int id, i;
    char newTime[50];

    printf("\nEnter Doctor ID: ");
    scanf("%d", &id);

    for (i = 0; i < doctorCount; i++) {
        if (doctors[i].id == id) {
            printf("Enter New Available Time: ");
            scanf(" %49[^\n]", newTime);

            strcpy(doctors[i].available_time, newTime);

            saveDoctors();

            printf("\nAvailable time updated successfully!\n");
            return;
        }
    }

    printf("\nDoctor not found!\n");
}
