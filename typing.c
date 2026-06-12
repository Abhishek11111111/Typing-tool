#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define clear() printf("\033[H\033[J")

int seconds = 60;
int stopTimer = 0;

void typing();
void easy();
void medium();
void hard();

void *timerThread(void *arg)
{
    while (seconds > 0 && !stopTimer)
    {
        sleep(1);
        seconds--;
    }
    return NULL;
}

void runGame(char quotes[][500], int count)
{
    clear();

    seconds = 60;
    stopTimer = 0;

    pthread_t tid;
    pthread_create(&tid, NULL, timerThread, NULL);

    int n = rand() % count;

    char input[500];

    printf("\nType the following text:\n\n");
    printf("%s\n\n", quotes[n]);

    getchar(); // clear newline from previous scanf

    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    stopTimer = 1;
    pthread_join(tid, NULL);

    int correct = 0;
    int total = strlen(quotes[n]);

    for (int i = 0; i < total && input[i] != '\0'; i++)
    {
        if (input[i] == quotes[n][i])
            correct++;
    }

    float accuracy = ((float)correct / total) * 100;

    printf("\nAccuracy : %.2f%%", accuracy);
    printf("\nTime Taken : %d seconds\n", 60 - seconds);

    int choice;
    printf("\n\n1. Main Menu");
    printf("\n2. Exit");
    printf("\nEnter choice: ");

    scanf("%d", &choice);

    if (choice == 1)
        typing();
}

void easy()
{
    char quotes[][500] =
    {
        "I blame myself every day for the plan and for meeting you.",
        "I dont need to get a life. I am a gamer. I have lots of lives.",
        "Wisdom is the offspring of suffering and time.",
        "We fail. We break. We fall. But then we rise, heal and overcome."
    };

    runGame(quotes, 4);
}

void medium()
{
    char quotes[][500] =
    {
        "Don't ever stop. Always keep going no matter what happens.",
        "The worst point in my life is when I study all night and nothing comes in the test.",
        "Games always believe that an epic win is possible.",
        "We don't stop playing because we grow old. We grow old because we stop playing.",
        "Money is never a big motivation except as a way to keep score."
    };

    runGame(quotes, 5);
}

void hard()
{
    char quotes[][500] =
    {
        "This in joke for video gamers is said by Ezio uncle Mario after meeting on the road.",
        "The neo noir masterpiece Max Payne is filled with beautiful dreary quotes.",
        "This emotional quote comes at the showdown between Snake and the Boss.",
        "The maniacal Andrew Ryan emphasizes this philosophical line near the end of the game.",
        "You gave them the one thing that was stolen from them. A chance to learn and live."
    };

    runGame(quotes, 5);
}

void typing()
{
    clear();

    int choice;

    printf("=================================\n");
    printf("       TYPING SPEED GAME\n");
    printf("=================================\n\n");

    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    printf("4. Exit\n");

    printf("\nSelect Difficulty: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            easy();
            break;

        case 2:
            medium();
            break;

        case 3:
            hard();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Choice!\n");
            sleep(1);
            typing();
    }
}

int main()
{
    srand(time(NULL));
    typing();
    return 0;
}