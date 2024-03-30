#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep function
#include <stdbool.h> // for boolean type
#include <string.h> // for string manipulation functions
#include <ctype.h> // for character type functions
#define size 3

struct Student {
    char name[50];
    char matricNum[50];
    int TestMark;
    int FinalMark;
};

typedef struct Student Student;

// Function prototypes
void BubbleSort(Student Marks[], int SIZE, bool ascending);
void display(Student Marks[], int SIZE);
void loadingAnimation();

int main() {
    Student StudentArray[size];

    // Data input
    for (int i = 0; i < size; i++) {
        printf("\n<Student %d>\n", i + 1);
        printf("\nPlease enter your name (e.g : Arif): ");
        scanf("%s", &StudentArray[i].name);
        printf("\nPlease enter your matric number (e.g : AI210125): ");
        scanf("%s", &StudentArray[i].matricNum);

        // Input validation and limit for test mark
        do {
            printf("\nPlease enter your Test Mark (Maximum 60%% of full marks): ");
            while (scanf("%d", &StudentArray[i].TestMark) != 1 || StudentArray[i].TestMark < 0 || StudentArray[i].TestMark > 60) {
                printf("Invalid input. Test Mark should be between 0 and 60: ");
                while (getchar() != '\n'); // Clear input buffer
            }
        } while (false);

        // Input validation and limit for final mark
        do {
            printf("\nPlease enter your Final Test Mark (Maximum 40%% of full marks): ");
            while (scanf("%d", &StudentArray[i].FinalMark) != 1 || StudentArray[i].FinalMark < 0 || StudentArray[i].FinalMark > 40) {
                printf("Invalid input. Final Test Mark should be between 0 and 40: ");
                while (getchar() != '\n'); // Clear input buffer
            }
        } while (false);

        printf("\n=====================================================\n");
    }

    int option;

    // Searching
    do {
        printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SEARCHING ~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n\tPress '1' for Good Performance (above 80 marks)");
        printf("\n\tPress '2' for Poor Performance (lower than 50 marks)\n");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

        printf("\n\nPlease enter performance that you want to search : ");

        // Input validation for searching option
        while (scanf("%d", &option) != 1 || (option != 1 && option != 2)) {
            printf("Invalid input. Please enter 1 or 2: ");
            while (getchar() != '\n'); // Clear input buffer
        }

        loadingAnimation(); // Show loading animation

        int idx;
        bool found = false; // Flag to check if any student is found

        for (idx = 0; idx < size; idx++) {
            if ((option == 1 && StudentArray[idx].TestMark > 48 && StudentArray[idx].FinalMark > 32) ||
                (option == 2 && (StudentArray[idx].TestMark < 30 || StudentArray[idx].FinalMark < 20))) {
                found = true;
                printf("\n\nValue is found at index\t: %d", idx);
                printf("\n\nMessage\t\t: Good Performance and Keep This Momentum to Achieve Success");
                printf("\nName\t\t: %s (%d)", StudentArray[idx].name, StudentArray[idx].TestMark);
                printf("\nMatric Number\t: %s", StudentArray[idx].matricNum);
                printf("\nTest Mark\t: %d", StudentArray[idx].TestMark);
                printf("\nFinal Mark\t: %d", StudentArray[idx].FinalMark);
            }
        }

        if (!found) {
            printf("\nThere is no result for the selected performance criteria.");
        }

    } while (option != 1 && option != 2);

    printf("\n\nList of the data that you stored:-\n");
    display(StudentArray, size);

    // Sorting loop
    do {
        // Sorting
        printf("\n\nPress '1' for ascending order and '2' for descending order: ");
        while (scanf("%d", &option) != 1 || (option != 1 && option != 2)) {
            printf("Invalid input. Please enter 1 or 2: ");
            while (getchar() != '\n'); // Clear input buffer
        }

        if (option == 1) {
            printf("\nSorting for Test Mark (Ascending Order): ");
            BubbleSort(StudentArray, size, true);
        } else {
            printf("\nSorting for Test Mark (Descending Order): ");
            BubbleSort(StudentArray, size, false);
        }

        // Prompt to continue sorting or quit
        printf("\n\nPress '1' to sort again or any other key to quit: ");
        scanf("%d", &option);
    } while (option == 1);

    // Option to re-enter or quit the program
    printf("\n\nPress '1' if you want to re-enter data or \nPress '2' to quit the program: ");
    while (scanf("%d", &option) != 1 || (option != 1 && option != 2)) {
        printf("Invalid input. Please enter 1 or 2: ");
        while (getchar() != '\n'); // Clear input buffer
    }

    if (option == 1) {
        // Restart program
        system("cls || clear"); // Clear screen for better visibility
        main();
    } else {
        printf("\n========================END OF PROGRAM============================\n");
    }

    return 0;
}

void display(Student Marks[], int SIZE) {
    int i;
    
    for (i = 0; i < size; i++) {
        printf("\nName\t\t: %s (%d)", Marks[i].name, Marks[i].TestMark);
        printf("\nMatric Number\t: %s", Marks[i].matricNum);
        printf("\nTest Mark\t: %d", Marks[i].TestMark);
        printf("\nFinal Mark\t: %d\n", Marks[i].FinalMark);
    }
}

void BubbleSort(Student Marks[], int SIZE, bool ascending) {
    int i;
    Student temp;
    
    for (i = 0; i < size - 1; i++) {
        int j;
        for (j = 0; j < (size - 1); j++) {
            if ((ascending && Marks[j].TestMark > Marks[j + 1].TestMark) || (!ascending && Marks[j].TestMark < Marks[j + 1].TestMark)) {
                temp = Marks[j];
                Marks[j] = Marks[j + 1];
                Marks[j + 1] = temp;
            }
        }
        
        printf("\n\nTest Mark in %s Order %d\t: ", (ascending ? "Ascending" : "Descending"), i + 1);
        
        for (int k = 0; k < size; k++) {
            printf("   %s (%d)", Marks[k].name, Marks[k].TestMark);
        }
    }
}

void loadingAnimation() {
    printf("\nLoading ");
    fflush(stdout); // Flush output buffer
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        sleep(1); // Sleep for 1 second
    }
    printf("\n");
}
