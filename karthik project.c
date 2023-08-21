#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    char name[50];
    int rollNumber;
};

struct Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount < MAX_STUDENTS) {
        printf("Enter student name: ");
        scanf("%s", students[studentCount].name);
        printf("Enter student roll number: ");
        scanf("%d", &students[studentCount].rollNumber);
        studentCount++;
        printf("Student added successfully!\n");
    } else {
        printf("Maximum student limit reached.\n");
    }
}

void removeStudent() {
    int rollNumber;
    printf("Enter the roll number of the student to remove: ");
    scanf("%d", &rollNumber);

    int foundIndex = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNumber) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        studentCount--;
        printf("Student removed successfully!\n");
    } else {
        printf("Student with the given roll number not found.\n");
    }
}

void searchStudent() {
    int rollNumber;
    printf("Enter the roll number of the student to search: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("Student found:\n");
            printf("Name: %s\n", students[i].name);
            printf("Roll Number: %d\n", students[i].rollNumber);
            return;
        }
    }

    printf("Student with the given roll number not found.\n");
}

int main() {
    int choice;

    do {
        printf("\nCollege Management Program\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                removeStudent();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
