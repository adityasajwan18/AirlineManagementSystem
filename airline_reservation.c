#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME "reservations.txt"
#define MAX_SEATS 50

struct Passenger {
    char pnr[10];
    char name[50];
    int age;
    char gender;
    char source[50];
    char destination[50];
    int seatNo;
};

// Generate Random PNR
char* generatePNR() {
    static char pnr[10];
    srand(time(0) + rand());
    sprintf(pnr, "PNR%04d", rand() % 10000);
    return pnr;
}

// Check if seat is already booked
int isSeatBooked(int seatNo) {
    FILE *fp = fopen(FILENAME, "r");
    struct Passenger p;
    while (fscanf(fp, "%[^|]|%[^|]|%d|%c|%[^|]|%[^|]|%d\n", p.pnr, p.name, &p.age, &p.gender, p.source, p.destination, &p.seatNo) != EOF) {
        if (p.seatNo == seatNo) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void bookTicket() {
    FILE *fp = fopen(FILENAME, "a");
    struct Passenger p;

    printf("Enter Name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Gender (M/F): ");
    scanf(" %c", &p.gender);
    printf("Enter Source: ");
    scanf(" %[^\n]", p.source);
    printf("Enter Destination: ");
    scanf(" %[^\n]", p.destination);

    do {
        printf("Enter Seat No (1-%d): ", MAX_SEATS);
        scanf("%d", &p.seatNo);
        if (isSeatBooked(p.seatNo)) {
            printf("Seat Already Booked! Choose another.\n");
        }
    } while (isSeatBooked(p.seatNo));

    strcpy(p.pnr, generatePNR());

    fprintf(fp, "%s|%s|%d|%c|%s|%s|%d\n", p.pnr, p.name, p.age, p.gender, p.source, p.destination, p.seatNo);
    fclose(fp);

    printf("Ticket Booked Successfully!\nYour PNR: %s\n", p.pnr);
}

void displayTicket() {
    FILE *fp = fopen(FILENAME, "r");
    struct Passenger p;
    char pnr[10];
    int found = 0;

    printf("Enter PNR: ");
    scanf("%s", pnr);

    while (fscanf(fp, "%[^|]|%[^|]|%d|%c|%[^|]|%[^|]|%d\n", p.pnr, p.name, &p.age, &p.gender, p.source, p.destination, &p.seatNo) != EOF) {
        if (strcmp(p.pnr, pnr) == 0) {
            printf("\nPNR: %s\nName: %s\nAge: %d\nGender: %c\nSource: %s\nDestination: %s\nSeat No: %d\n", p.pnr, p.name, p.age, p.gender, p.source, p.destination, p.seatNo);
            found = 1;
            break;
        }
    }

    if (!found) printf("Ticket not found!\n");
    fclose(fp);
}

void cancelTicket() {
    FILE *fp = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    struct Passenger p;
    char pnr[10];
    int found = 0;

    printf("Enter PNR to Cancel: ");
    scanf("%s", pnr);

    while (fscanf(fp, "%[^|]|%[^|]|%d|%c|%[^|]|%[^|]|%d\n", p.pnr, p.name, &p.age, &p.gender, p.source, p.destination, &p.seatNo) != EOF) {
        if (strcmp(p.pnr, pnr) == 0) {
            found = 1;
        } else {
            fprintf(temp, "%s|%s|%d|%c|%s|%s|%d\n", p.pnr, p.name, p.age, p.gender, p.source, p.destination, p.seatNo);
        }
    }
    fclose(fp);
    fclose(temp);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found) {
        printf("Ticket Cancelled Successfully!\n");
    } else {
        printf("Ticket Not Found!\n");
    }
}

void modifyTicket() {
    cancelTicket();
    printf("Re-book your ticket with updated details:\n");
    bookTicket();
}

void showAllBookings() {
    FILE *fp = fopen(FILENAME, "r");
    struct Passenger p;
    printf("\nAll Bookings:\n");

    while (fscanf(fp, "%[^|]|%[^|]|%d|%c|%[^|]|%[^|]|%d\n", p.pnr, p.name, &p.age, &p.gender, p.source, p.destination, &p.seatNo) != EOF) {
        printf("\nPNR: %s | Name: %s | Seat No: %d | Route: %s to %s\n", p.pnr, p.name, p.seatNo, p.source, p.destination);
    }
    fclose(fp);
}

void checkSeatAvailability() {
    int booked = 0;
    FILE *fp = fopen(FILENAME, "r");
    struct Passenger p;

    while (fscanf(fp, "%[^|]|%[^|]|%d|%c|%[^|]|%[^|]|%d\n", p.pnr, p.name, &p.age, &p.gender, p.source, p.destination, &p.seatNo) != EOF) {
        booked++;
    }
    fclose(fp);

    printf("Seats Booked: %d\nSeats Available: %d\n", booked, MAX_SEATS - booked);
}

void menu() {
    int choice;
    do {
        printf("\n====== Airline Reservation Management System by Aditya Sajwan======\n");
        printf("1. Book Ticket\n");
        printf("2. Display Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. Modify Ticket\n");
        printf("5. Show All Bookings\n");
        printf("6. Check Seat Availability\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: bookTicket(); break;
            case 2: displayTicket(); break;
            case 3: cancelTicket(); break;
            case 4: modifyTicket(); break;
            case 5: showAllBookings(); break;
            case 6: checkSeatAvailability(); break;
            case 7: exit(0);
            default: printf("Invalid Choice!\n");
        }
    } while (1);
}

int main() {
    menu();
    return 0;
}
