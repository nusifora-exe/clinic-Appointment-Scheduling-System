
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DOCTORS 100
#define MAX_SLOTS 20
#define NAME_LEN 50
#define SPEC_LEN 50
#define DAY_LEN 15
#define TIME_LEN 30
#define DATA_FILE "doctor_schedule_v2.dat"

typedef struct {
    char day[DAY_LEN];
    char startTime[TIME_LEN];
    char endTime[TIME_LEN];
    int available;
} Schedule;

typedef struct {
    int id;
    char name[NAME_LEN];
    char specialization[SPEC_LEN];
    int active;
    int slotCount;
    Schedule slots[MAX_SLOTS];
} Doctor;

Doctor doctors[MAX_DOCTORS];
int doctorCount = 0;

void viewSchedules(void);
void manageAvailability(void);

void removeNewline(char str[]) {
    str[strcspn(str, "\n")] = '\0';
}

void readText(const char *message, char *output, int size) {
    while (1) {
        printf("%s", message);

        if (fgets(output, size, stdin) == NULL) {
            output[0] = '\0';
            return;
        }

        removeNewline(output);

        if (strlen(output) > 0) {
            return;
        }

        printf("Input cannot be empty. Try again.\n");
    }
}

int readInt(const char *message, int min, int max) {
    char input[50];
    char *end;
    long value;

    while (1) {
        printf("%s", message);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            return min;
        }

        value = strtol(input, &end, 10);

        while (*end == ' ' || *end == '\t') {
            end++;
        }

        if (end != input &&
            (*end == '\n' || *end == '\0') &&
            value >= min && value <= max) {
            return (int)value;
        }

        printf("Invalid choice. Enter a number from %d to %d.\n",
               min, max);
    }
}

void saveDoctors(void) {
    FILE *file = fopen(DATA_FILE, "wb");

    if (file == NULL) {
        printf("Error: Could not save doctor data.\n");
        return;
    }

    fwrite(&doctorCount, sizeof(int), 1, file);
    fwrite(doctors, sizeof(Doctor), doctorCount, file);

    fclose(file);
    printf("Data saved successfully!\n");
}

void loadDoctors(void) {
    FILE *file = fopen(DATA_FILE, "rb");

    if (file == NULL) {
        doctorCount = 0;
        return;
    }

    if (fread(&doctorCount, sizeof(int), 1, file) != 1 ||
        doctorCount < 0 || doctorCount > MAX_DOCTORS) {
        doctorCount = 0;
        fclose(file);
        return;
    }

    if (fread(doctors, sizeof(Doctor), doctorCount, file)
        != (size_t)doctorCount) {
        doctorCount = 0;
    }

    fclose(file);
}

int findDoctor(int id) {
    for (int i = 0; i < doctorCount; i++) {
        if (doctors[i].id == id) {
            return i;
        }
    }

    return -1;
}

void addDoctor(void) {
    if (doctorCount >= MAX_DOCTORS) {
        printf("Doctor limit reached!\n");
        return;
    }

    Doctor newDoctor = {0};

    newDoctor.id = doctorCount == 0
                   ? 1 : doctors[doctorCount - 1].id + 1;

    printf("\n--- ADD NEW DOCTOR ---\n");

    readText("Enter Doctor Name: ", newDoctor.name, NAME_LEN);

    readText("Enter Specialization: ",
             newDoctor.specialization, SPEC_LEN);

    newDoctor.active = 1;
    newDoctor.slotCount = 0;

    doctors[doctorCount++] = newDoctor;

    saveDoctors();

    printf("Doctor added successfully! Doctor ID: %d\n",
           newDoctor.id);
}

void viewDoctors(void) {
    printf("\n========== DOCTOR LIST ==========\n");

    if (doctorCount == 0) {
        printf("No doctor records found.\n");
        return;
    }

    for (int i = 0; i < doctorCount; i++) {
        printf("\nDoctor ID: %d\n", doctors[i].id);
        printf("Name: %s\n", doctors[i].name);
        printf("Specialization: %s\n",
               doctors[i].specialization);
        printf("Status: %s\n",
               doctors[i].active ? "Active" : "Inactive");
        printf("Total Schedule Slots: %d\n",
               doctors[i].slotCount);
    }
}

void searchDoctor(void) {
    int id = readInt("\nEnter Doctor ID: ", 1, 999999);
    int index = findDoctor(id);

    if (index == -1) {
        printf("Doctor not found!\n");
        return;
    }

    printf("\nDoctor ID: %d\n", doctors[index].id);
    printf("Name: %s\n", doctors[index].name);
    printf("Specialization: %s\n",
           doctors[index].specialization);
    printf("Status: %s\n",
           doctors[index].active ? "Active" : "Inactive");
}

void updateDoctor(void) {
    int id = readInt("\nEnter Doctor ID: ", 1, 999999);
    int index = findDoctor(id);

    if (index == -1) {
        printf("Doctor not found!\n");
        return;
    }

    printf("\n--- UPDATE DOCTOR ---\n");

    readText("Enter New Doctor Name: ",
             doctors[index].name, NAME_LEN);

    readText("Enter New Specialization: ",
             doctors[index].specialization, SPEC_LEN);

    saveDoctors();

    printf("Doctor information updated successfully!\n");
}

int convertTimeToMinutes(const char time[]) {
    int hour, minute;
    char period[3];
    char extra;

    if (sscanf(time, "%d:%d %2s %c",
               &hour, &minute, period, &extra) != 3) {
        return -1;
    }

    if (hour < 1 || hour > 12 ||
        minute < 0 || minute > 59) {
        return -1;
    }

    if (strcmp(period, "AM") != 0 &&
        strcmp(period, "PM") != 0) {
        return -1;
    }

    if (hour == 12) {
        hour = 0;
    }

    if (strcmp(period, "PM") == 0) {
        hour += 12;
    }

    return hour * 60 + minute;
}

void addSchedule(void) {
    int id = readInt("\nEnter Doctor ID: ", 1, 999999);
    int index = findDoctor(id);

    if (index == -1) {
        printf("Doctor not found!\n");
        return;
    }

    if (doctors[index].slotCount >= MAX_SLOTS) {
        printf("Schedule slot limit reached!\n");
        return;
    }

    Schedule slot = {0};

    printf("\n--- ADD SCHEDULE ---\n");
    printf("1. Monday\n2. Tuesday\n3. Wednesday\n");
    printf("4. Thursday\n5. Friday\n6. Saturday\n7. Sunday\n");

    int day = readInt("Select Day: ", 1, 7);

    const char *days[] = {
        "Monday", "Tuesday", "Wednesday", "Thursday",
        "Friday", "Saturday", "Sunday"
    };

    strcpy(slot.day, days[day - 1]);

    readText("Enter Start Time (e.g. 10:00 AM): ",
             slot.startTime, TIME_LEN);

    readText("Enter End Time (e.g. 02:00 PM): ",
             slot.endTime, TIME_LEN);

    int start = convertTimeToMinutes(slot.startTime);
    int end = convertTimeToMinutes(slot.endTime);

    if (start == -1 || end == -1) {
        printf("Invalid time format! Use HH:MM AM/PM.\n");
        return;
    }

    if (end <= start) {
        printf("Invalid time! End time must be after start time.\n");
        return;
    }

    for (int i = 0; i < doctors[index].slotCount; i++) {
        Schedule old = doctors[index].slots[i];

        if (strcmp(old.day, slot.day) == 0) {
            int oldStart = convertTimeToMinutes(old.startTime);
            int oldEnd = convertTimeToMinutes(old.endTime);

            if (oldStart == start && oldEnd == end) {
                printf("Duplicate schedule detected!\n");
                return;
            }

            if (oldStart != -1 && oldEnd != -1 &&
                start < oldEnd && end > oldStart) {
                printf("Schedule conflict! This time overlaps with an existing schedule.\n");
                return;
            }
        }
    }

    slot.available = 1;

    doctors[index].slots[doctors[index].slotCount++] = slot;

    saveDoctors();

    printf("Schedule added successfully!\n");
}

void viewSchedules(void) {
    int id = readInt("\nEnter Doctor ID: ", 1, 999999);
    int index = findDoctor(id);

    if (index == -1) {
        printf("Doctor not found!\n");
        return;
    }

    printf("\n========== DOCTOR SCHEDULE ==========\n");
    printf("Doctor: %s\n", doctors[index].name);
    printf("Specialization: %s\n",
           doctors[index].specialization);

    if (doctors[index].slotCount == 0) {
        printf("No schedules available.\n");
        return;
    }

    for (int i = 0; i < doctors[index].slotCount; i++) {
        Schedule slot = doctors[index].slots[i];

        printf("\nSlot %d\n", i + 1);
        printf("Day: %s\n", slot.day);
        printf("Time: %s - %s\n",
               slot.startTime, slot.endTime);
        printf("Availability: %s\n",
               slot.available ? "Available" : "Unavailable");
    }
}

void manageAvailability(void) {
    int id = readInt("\nEnter Doctor ID: ", 1, 999999);
    int index = findDoctor(id);

    if (index == -1) {
        printf("Doctor not found!\n");
        return;
    }

    if (doctors[index].slotCount == 0) {
        printf("No schedules found.\n");
        return;
    }

    for (int i = 0; i < doctors[index].slotCount; i++) {
        Schedule slot = doctors[index].slots[i];

        printf("\nSlot %d\n", i + 1);
        printf("Day: %s\n", slot.day);
        printf("Time: %s - %s\n",
               slot.startTime, slot.endTime);
        printf("Availability: %s\n",
               slot.available ? "Available" : "Unavailable");
    }

    int slotNo = readInt("\nEnter Slot Number: ",
                         1, doctors[index].slotCount);

    int status = readInt(
        "\n1. Available\n2. Unavailable\nChoose: ", 1, 2);

    doctors[index].slots[slotNo - 1].available = (status == 1);

    saveDoctors();

    printf("Availability updated successfully!\n");
}

void deleteSchedule(void) {
    int id = readInt("\nEnter Doctor ID: ", 1, 999999);
    int index = findDoctor(id);

    if (index == -1) {
        printf("Doctor not found!\n");
        return;
    }

    if (doctors[index].slotCount == 0) {
        printf("No schedules found.\n");
        return;
    }

    for (int i = 0; i < doctors[index].slotCount; i++) {
        Schedule slot = doctors[index].slots[i];

        printf("\nSlot %d\n", i + 1);
        printf("Day: %s\n", slot.day);
        printf("Time: %s - %s\n",
               slot.startTime, slot.endTime);
    }

    int slotNo = readInt(
        "\nEnter Slot Number to Delete: ",
        1, doctors[index].slotCount
    );

    for (int i = slotNo - 1;
         i < doctors[index].slotCount - 1; i++) {
        doctors[index].slots[i] =
            doctors[index].slots[i + 1];
    }

    doctors[index].slotCount--;

    saveDoctors();

    printf("Schedule deleted successfully!\n");
}


void doctorMenu(void) {
    int choice;

    do {
        printf("\n====================================\n");
        printf("     DOCTOR SCHEDULE MANAGEMENT\n");
        printf("              MEMBER 2\n");
        printf("====================================\n");
        printf("1. Add Doctor\n");
        printf("2. View Doctors\n");
        printf("3. Search Doctor\n");
        printf("4. Update Doctor Information\n");
        printf("5. Add Doctor Schedule\n");
        printf("6. View Doctor Schedules\n");
        printf("7. Manage Slot Availability\n");
        printf("8. Delete Doctor Schedule\n");
        printf("9. Exit\n");
        printf("====================================\n");

        choice = readInt("Enter your choice: ", 1, 9);

        
switch (choice) {
    case 1: addDoctor(); break;
    case 2: viewDoctors(); break;
    case 3: searchDoctor(); break;
    case 4: updateDoctor(); break;
    case 5: addSchedule(); break;
    case 6: viewSchedules(); break;
    case 7: manageAvailability(); break;
    case 8: deleteSchedule(); break;

    case 9:
        printf("Exiting Doctor Schedule Management...\n");
        break;
}

    } while (choice != 9);
}

int main(void) {
    loadDoctors();
    doctorMenu();
    return 0;
}
