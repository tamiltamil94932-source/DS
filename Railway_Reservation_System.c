#include <stdio.h>
#include <string.h>
#define MAX 50
struct Ticket {
    int pnr;
    char name[30];
    int age;
    int trainNo;
    char from[20];
    char to[20];
    int seatNo;
    int active;
};
struct Ticket t[MAX];
int count = 0;
int nextPnr = 1001;
void bookTicket() {
    if (count >= MAX) {
        printf("Sorry, no seats available!\n");
        return;
    }
    printf("Enter Passenger Name: ");
    scanf(" %[^\n]", t[count].name);
    printf("Enter Age: ");
    scanf("%d", &t[count].age);
    printf("Enter Train Number: ");
    scanf("%d", &t[count].trainNo);
    printf("Enter From: ");
    scanf(" %[^\n]", t[count].from);
    printf("Enter To: ");
    scanf(" %[^\n]", t[count].to);
    t[count].pnr = nextPnr++;
    t[count].seatNo = count + 1;
    t[count].active = 1;
    printf("Ticket booked! PNR: %d, Seat No: %d\n",
    t[count].pnr, t[count].seatNo);
    count++;
}
void display() {
    int i, found = 0;
    printf("\n%-6s %-14s %-4s %-6s %-10s %-10s %s\n",
    "PNR", "Name", "Age", "Train", "From", "To", "Seat");
    for (i = 0; i < count; i++) {
        if (t[i].active) {
            printf("%-6d %-14s %-4d %-6d %-10s %-10s %d\n",
            t[i].pnr, t[i].name, t[i].age, t[i].trainNo,
            t[i].from, t[i].to, t[i].seatNo);
            found = 1;
        }
    }
    if (!found)
    printf("No reservations found.\n");
}
int find(int pnr) {
    int i;
    for (i = 0; i < count; i++) {
        if (t[i].pnr == pnr && t[i].active)
        return i;
    }
    return -1;
}
void searchTicket() {
    int pnr, p;
    printf("Enter PNR to search: ");
    scanf("%d", &pnr);
    p = find(pnr);
    if (p == -1)
    printf("Ticket not found!\n");
    else
    printf("Found: %s, Train %d, %s to %s, Seat %d\n",
    t[p].name, t[p].trainNo, t[p].from, t[p].to, t[p].seatNo);
}
void cancelTicket() {
    int pnr, p;
    printf("Enter PNR to cancel: ");
    scanf("%d", &pnr);
    p = find(pnr);
    if (p == -1)
    printf("Ticket not found!\n");
    else {
        t[p].active = 0;
        printf("Ticket cancelled successfully!\n");
    }
}
int main() {
    int ch;
    do {
        printf("\n--- RAILWAY RESERVATION SYSTEM ---\n");
        printf("1.Book Ticket  2.Display  3.Search\n");
        printf("4.Cancel Ticket  5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: bookTicket();   break;
            case 2: display();      break;
            case 3: searchTicket(); break;
            case 4: cancelTicket(); break;
            case 5: printf("Thank you!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (ch != 5);
    return 0;
}
