#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX 10
#define BOOTHS 5
#define CANDIDATES 3

char name[MAX][30];
char ward[MAX][20];
int age[MAX];
long long phone[MAX];
int voted[MAX];

// 2d array
int boothVotes[CANDIDATES][BOOTHS];
int totalVoters = 0;
int pA = 0, pB = 0, pC = 0;

// upper case
void upper(char s[]) {
    int i;
    for (i = 0; s[i]; i++) {
        s[i] = toupper((unsigned char)s[i]);
    }
}

// searching voter using loop and string func
int searchVoter(char key[]) {
    int i;
    char temp1[30], temp2[30];
    strcpy(temp2, key);
    upper(temp2);
    for (i = 0; i < totalVoters; i++) {
        strcpy(temp1, name[i]);
        upper(temp1);
        if (strcmp(temp1, temp2) == 0) return i;
    }
    return -1;
}

void menu() {
    printf("\n ELECTION MANAGEMENT SYSTEM \n");
    printf("1.Register Voter\n");
    printf("2.Renew Voter\n");
    printf("3.Cast Vote\n");
    printf("4.Display Voters\n");
    printf("5.Result\n");
    printf("6.Election Statistics\n");
    printf("7.Sort Voters\n");
    printf("8.Booth Wise Votes\n");
    printf("9.Exit\n");
}

void apply() {
    // check if voters are full
    if (totalVoters >= MAX) {
        printf("Storage Full\n");
        return;
    }

    // voter details
    printf("Name : ");
    scanf("%29s", name[totalVoters]);

    int *pAge = &age[totalVoters];
    // age valodation using ternary operator
    printf("Age : ");
    scanf("%d", pAge);

    char *eligible;
    eligible = (*pAge >= 18) ? "YES" : "NO";
    printf("Eligible : %s\n", eligible);
    if (strcmp(eligible, "NO") == 0) {
        return;
    }

    // phone validation using while loop
    long long *pPhone = &phone[totalVoters];
    printf("Phone : ");
    scanf("%lld", pPhone);
    while (*pPhone < 1000000000LL || *pPhone > 9999999999LL) {
        printf("Invalid Phone. Re-enter: ");
        scanf("%lld", pPhone);
    }

    printf("Ward : ");
    scanf("%19s", ward[totalVoters]);

    // no one casted the vote
    voted[totalVoters] = 0;

    // stores like name-ward
    char info[60];
    strcpy(info, name[totalVoters]);
    strcat(info, " - ");
    strcat(info, ward[totalVoters]);
    printf("Record : %s\n", info);
    printf("Name Length : %u\n", (unsigned)strlen(name[totalVoters]));

    // increase voter count
    totalVoters++;
    printf("Registration Successful\n");
}

void renewal() {
    // just searching the user and if yes renewal
    char s[30];
    printf("Enter Name : ");
    scanf("%29s", s);
    if (searchVoter(s) >= 0) {
        printf("Renewal Successful\n");
    } else {
        printf("Voter Not Found\n");
    }
}

void trialVote() {
    char s[30];
    int choice, booth, index;
    printf("Enter Name : ");
    scanf("%29s", s);
    index = searchVoter(s);

    // if voter not found
    if (index == -1) {
        printf("Not Registered\n");
        return;
    }

    // if already voted
    if (voted[index]) {
        printf("Already Voted\n");
        return;
    }

    printf("1.CJP\n2.Congress\n3.BJP\nChoice : ");
    scanf("%d", &choice);

    printf("Booth(1-5): ");
    scanf("%d", &booth);

    // booth should be between 1-5
    if (booth < 1 || booth > 5) {
        printf("Invalid Booth\n");
        return;
    }

    // increase vote and boothVote
    switch (choice) {
        case 1:
            pA++;
            boothVotes[0][booth - 1]++;
            break;
        case 2:
            pB++;
            boothVotes[1][booth - 1]++;
            break;
        case 3:
            pC++;
            boothVotes[2][booth - 1]++;
            break;
        default:
            printf("Invalid Candidate\n");
            return;
    }

    // add that voter has voted
    voted[index] = 1;
    printf("Vote Cast Successfully\n");
}

void voterDetails() {
    int i;
    // if there are no voters
    if (totalVoters == 0) {
        printf("No Records\n");
        return;
    }

    // display voters using for loop
    for (i = 0; i < totalVoters; i++) {
        char *p = name[i];
        printf("\nVoter %d\n", i + 1);
        printf("Name : %s\n", p);
        printf("Age : %d\n", *(age + i));
        printf("Phone : %lld\n", *(phone + i));
        printf("Ward : %s\n", ward[i]);
        printf("Status : %s\n", voted[i] ? "Voted" : "Not Voted");
    }
}

// displays the result
void result() {
    printf("\nCJP:%d\nCongress:%d\nBJP:%d\n", pA, pB, pC);
    // if partyA is greater than it wins
    if (pA > pB && pA > pC) {
        printf("Winner:CJP\n");
    }
    // if party B then it wins
    else if (pB > pA && pB > pC) {
        printf("Winner:Congress\n");
    }
    // if party C is greater than it wins
    else if (pC > pA && pC > pB) {
        printf("Winner:BJP\n");
    }
    // otherwise tie
    else {
        printf("Tie\n");
    }
}

void statistics() {
    int i, v = 0;
    for (i = 0; i < totalVoters; i++) {
        // arithematic pointer,* is address of voted where voted + i(0,1,2...) each int is of 4 byte
        // if starting voted is in address 1000 then next will be voted+1 i.e 1000+4=1004
        if (*(voted + i)) {
            v++;
        }
    }
    printf("\nRegistered:%d\n", totalVoters);
    printf("Voted:%d\n", v);
    printf("Not Voted:%d\n", totalVoters - v);
    if (totalVoters) {
        printf("Voting %%: %.2f\n", (float)v * 100 / totalVoters);
    }
}

// sorting voters
void sortVoters() {
    int i, j, t;
    char temp[30], tempWard[20];
    long long ph;

    // selection sort technique
    for (i = 0; i < totalVoters - 1; i++) {
        for (j = i + 1; j < totalVoters; j++) {
            if (strcmp(name[i], name[j]) > 0) {
                strcpy(temp, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);

                strcpy(tempWard, ward[i]);
                strcpy(ward[i], ward[j]);
                strcpy(ward[j], tempWard);

                t = age[i];
                age[i] = age[j];
                age[j] = t;

                ph = phone[i];
                phone[i] = phone[j];
                phone[j] = ph;

                t = voted[i];
                voted[i] = voted[j];
                voted[j] = t;
            }
        }
    }
    printf("Sorted Successfully\n");
}

// booth results in each
void boothResult() {
    int i, j;
    char *cand[] = {"CJP", "Congress", "BJP"};
    printf("\nBooth Wise Votes\n");
    // displays candidates with their boothwise votes
    for (i = 0; i < CANDIDATES; i++) {
        printf("%s : ", cand[i]);
        // boothwise votes
        for (j = 0; j < BOOTHS; j++) {
            printf("%d ", boothVotes[i][j]);
        }
        printf("\n");
    }
}

// main program
int main() {
    int ch;
    do {
        menu();
        printf("Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                apply();
                break;
            case 2:
                renewal();
                break;
            case 3:
                trialVote();
                break;
            case 4:
                voterDetails();
                break;
            case 5:
                result();
                break;
            case 6:
                statistics();
                break;
            case 7:
                sortVoters();
                break;
            case 8:
                boothResult();
                break;
            case 9:
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    } while (ch != 9);

    return 0;
}
