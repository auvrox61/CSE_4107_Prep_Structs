#include <stdio.h>

typedef struct {
    char name[30];
    int matches;
    int innings;
    int runs;
    float average;
} batsman;

batsman findBest(batsman batsmen[], int n) {
    for (int i = 0; i < n; i++) {
        batsmen[i].average = (float)batsmen[i].runs / batsmen[i].innings;
    }

    batsman best = batsmen[0];
    for (int i = 1; i < n; i++) {
        if (batsmen[i].average > best.average) {
            best = batsmen[i];
        }
    }
    return best;
}

void displayBest(batsman bestAverage) {
    printf("Best Batsman :\n");
    printf("-----------------------------------------------\n");
    printf("%-25s|%-8s|%-8s|%-6s|%-8s\n", "Name", "Matches", "Innings", "Runs", "Average");
    printf("-----------------------------------------------\n");
    printf("%-25s|%-8d|%-8d|%-6d|%-8.2f\n", bestAverage.name, bestAverage.matches, bestAverage.innings, bestAverage.runs, bestAverage.average);
}

int main() {
    int n;
    scanf("%d", &n);
    batsman batsmen[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Details of Batsman #%d\n", i + 1);
        printf("Enter Name\n");
        scanf(" %[^\n]", batsmen[i].name);
        printf("Enter Matches :\n");
        scanf("%d", &batsmen[i].matches);
        printf("Enter Innings :\n");
        scanf("%d", &batsmen[i].innings);
        printf("Enter Runs :\n");
        scanf("%d", &batsmen[i].runs);
    }
    batsman bestAverage = findBest(batsmen, n);
    displayBest(bestAverage);
    return 0;
}
