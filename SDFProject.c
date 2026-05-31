// FINAL CODE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

void setColor(int colorCode)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}

char *paras[3][3] = {
    {"She wondered if the note had reached him. She scolded herself for not handing it to him in person.\n"
     "She trusted her friend, but so much could happen. She waited impatiently for word.\n",
     "She wondered if the note had reached him. She scolded herself for not handing it to him in person.\n"
     "She trusted her friend, but so much could happen. She waited impatiently for word.\n",
     "She didn't understand how changed worked. When she looked at today compared to yesterday,there was nothing that she could see that was different.\n"
     "Yet, when she looked at today compared to last year, she couldn't see how anything was ever the same.\n"},
    {"Python is known for its simplicity and readability, which makes it a favorite among beginners and professionals alike. Its syntax is clean (no semicolons needed), and it supports multiple programming styles: procedural, object-oriented, and functional. With vast libraries for AI, data science, and automation, Python stands out as a truly versatile language.",
     "JavaScript brings interactivity to the web, allowing dynamic updates on websites without reloading the page. It runs directly in the browser (like Chrome or Firefox) and can also be used on servers through Node.js. What makes it special is its event-driven nature: functions can respond instantly to user actions, creating smooth and responsive experiences.",
     "C++ combines the power of low-level programming with the flexibility of high-level design, making it perfect for performance-critical applications. It supports object-oriented concepts (classes and inheritance) and allows precise control over memory. From gaming engines to operating systems, C++ remains a powerhouse language that balances speed, control, and structure."},
    {"In advanced C programming, dynamic memory allocation plays a crucial role; it allows a program to request memory at runtime using functions like malloc(), calloc(), and realloc(). However, forgetting to use free() leads to memory leaks, which can slow down or even crash a system! Pointers, in this context, are like flexible references - they store addresses (&) rather than direct values, making memory handling efficient but risky if used carelessly.",
     "File handling in C goes beyond just reading and writing text; it's about managing streams efficiently through functions like fopen(), fprintf(), and fclose(). A file pointer (FILE*) connects your program to the file, and you can use modes such as 'r', 'w', or 'a+' to specify reading, writing, or appending. Remember: always check if fopen() returned NULL, or you might end up with a segmentation fault! Handling data securely often involves combining #defines, conditionals, and error flag",
     "Although C wasn't originally designed for threads, libraries like pthread make true parallel execution possible. A thread (pthread_t) can run its own function simultaneously, sharing global data - which introduces the challenge of synchronization. Using mutexes, semaphores, or atomic variables ensures that two threads don’t modify shared resources ($ or @ data) at the same time. Proper synchronization keeps your code efficient, safe, and free from race conditions."}};

char *udetail = NULL;

char *pname()
{
    int size = 0, capacity = 20;
    char ch;
    if (udetail != NULL)
    {
        free(udetail);
        udetail = NULL;
    }
    udetail = (char *)malloc(capacity * sizeof(char));
    if (udetail == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (size >= capacity - 1)
        {
            capacity *= 2;
            char *temp = (char *)realloc(udetail, capacity * sizeof(char));
            if (temp == NULL)
            {
                printf("Memory allocation failed\n");
                free(udetail);
                udetail = NULL;
                return NULL;
            }
            udetail = temp;
        }
        udetail[size++] = ch;
    }
    udetail[size] = '\0';
    return udetail;
}

void gamexit()
{
    int n = 0;
    char arr[] = "*!*!*!*!*!ARIGATOOOO!*!*!*!*!*";
    int l = (int)strlen(arr);
    setColor(1);
    for (int m = 0; m < 40; m++)
    {
        printf("#");
    }
    setColor(14);
    printf("\n\n");
    printf("     ");
    for (n = 0; n < l; n++)
    {
        printf("%c", arr[n]);
        fflush(stdout);
        Sleep(50);
    }
    printf("\n\n");
    setColor(1);
    for (int m = 0; m < 40; m++)
    {
        printf("#");
    }
    printf("\n\n");
    setColor(7);
}

int strlenght_k(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

float accuracy_k(char original[], char typed[])
{
    int correct = 0;
    int len = strlenght_k(original);
    for (int i = 0; i < len; i++)
    {
        if (original[i] == typed[i])
        {
            correct++;
        }
    }
    return ((float)correct / len) * 100.0f;
}

float wpm_k(char typed[], float time_taken)
{
    int char_count = strlenght_k(typed);
    int word_count = char_count / 5;
    if (time_taken <= 0.0f)
        return 0.0f;
    return (word_count / time_taken) * 60.0f;
}

void delaycall()
{
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("\rGAME STARTING IN %02d", (5 - i));
        fflush(stdout);
        Sleep(1000);
    }
    printf("\n");
}

struct Player
{
    char name[50];
    int wpm;
};

struct Player players[100];
int pcount = 0;

void sortLeaderboard()
{
    for (int i = 0; i < pcount - 1; i++)
    {
        for (int j = i + 1; j < pcount; j++)
        {
            if (players[j].wpm > players[i].wpm)
            {
                struct Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
}

void showLeaderboard()
{
    printf("\n===== Typing Speed Leaderboard (TEST MODE) =====\n");
    if (pcount == 0)
    {
        printf("No scores yet.\n");
        return;
    }
    printf("%-5s %-20s %-10s\n", "Rank", "Name", "WPM");
    for (int i = 0; i < pcount; i++)
    {
        printf("%-5d %-20s %-10d\n", i + 1, players[i].name, players[i].wpm);
    }
}

void addScore(const char *name, float wpmValue)
{
    if (pcount >= 100) {return;}
    players[pcount].wpm = (int)(wpmValue + 0.5f);
    strncpy(players[pcount].name, name, 49);
    players[pcount].name[49] = '\0';
    pcount++ ;
    sortLeaderboard();
}

void testmode()
{
    char again = 'Y';
    while (again == 'Y' || again == 'y')
    {
        system("cls");
        setColor(11);
        printf("============================================================\n");
        char s[] = "            ####### TEST MODE #######";
        for (int i = 0; s[i] != '\0'; i++)
        {
            setColor(15);
            printf("%c", s[i]);
            fflush(stdout);
            Sleep(50);
        }
        printf("\n");
        setColor(11);
        printf("============================================================\n");
        setColor(15);
        printf("Enter your player name: ");
        pname();
        int gm;
        setColor(13);
        printf("\nPlease Select your choice for game mode : \n");
        printf("EASY(1)\nMEDIUM(2)\nHARD(3)\n:\t");
        if (scanf("%d", &gm) != 1)
        {
            setColor(4);
            printf("Invalid input.\n");
            return;
        }
        getchar();
        if (gm < 1 || gm > 3)
        {
            setColor(4);
            printf("INVALID INPUT FOR GAME MODE\n");
            Sleep(1500);
            return;
        }
        int seed = rand() % 3;
        char *paragraph = paras[gm - 1][seed];
        delaycall();
        setColor(3);
        printf("\n\nParagraph for you:\n");
        setColor(15);
        printf("------------------------------------------------------------\n");
        printf("%s\n", paragraph);
        printf("------------------------------------------------------------\n");
        setColor(12);
        printf("You can start typing your sentence here:\n");
        char typed[2000];
        clock_t start_time = clock();
        if (fgets(typed, sizeof(typed), stdin) == NULL)
        {
            setColor(4);
            printf("Error reading input.\n");
            return;
        }
        clock_t end_time = clock();
        float time_taken = (float)(end_time - start_time) / CLOCKS_PER_SEC;
        float acc = accuracy_k(paragraph, typed);
        float wpm = wpm_k(typed, time_taken);
        setColor(11);
        printf("\nInput taken successfully\n");
        printf("Player     : %s\n", (udetail != NULL && udetail[0] != '\0') ? udetail : "Unknown");
        printf("Time Taken : %.2f sec\n", time_taken);
        printf("Accuracy   : %.2f%%\n", acc);
        printf("WPM        : %.2f\n", wpm);
        if (udetail != NULL && udetail[0] != '\0')
        {
            addScore(udetail, wpm);
        }
        showLeaderboard();
        setColor(15);
        printf("\nDO YOU WANT TO RETAKE TEST MODE? (Y/N): ");
        scanf(" %c", &again);
        getchar();
    }
}

void practicemode()
{
    char play_again = 'Y';
    while (play_again == 'Y' || play_again == 'y')
    {
        int level, time_choice, duration;
        char easy[9][1000] = {
            "The sun is shining brightly today.",
            "I love to read books every evening.",
            "She is playing with her little cat.",
            "Please close the door before you leave.",
            "The coffee is too hot to drink now.",
            "My father drives to work every day.",
            "It is raining outside, so take an umbrella.",
            "He enjoys hiking in the mountains on weekends.",
            "The flowers in the garden look beautiful."};
        char medium[9][1000] = {
            "The quick brown fox jumps over the lazy dog.",
            "Learning to code is a valuable skill in today's world.",
            "The beautiful garden was filled with colorful flowers.",
            "They decided to take a road trip across the country during the holidays.",
            "The chef prepared a delicious meal for the guests at the restaurant.",
            "She enjoys painting landscapes and portraits in her free time.",
            "The concert last night was an unforgettable experience for everyone.",
            "He is studying hard to pass his final exams next month.",
            "The new technology has revolutionized the way we communicate."};
        char hard[9][1000] = {
            "Success doesn't come overnight it's the result of consistent effort and patience.",
            "If you want to achieve greatness, you must first be willing to make sacrifices.",
            "When creativity meets discipline, extraordinary results are often achieved.",
            "The intricacies of quantum mechanics continue to baffle even the most brilliant minds in physics.",
            "The juxtaposition of light and shadow in the painting created a mesmerizing effect that captivated viewers",
            "In the realm of literature, the exploration of human emotions often leads to profound insights about the human condition.",
            "The advent of artificial intelligence has sparked debates about the ethical implications of machine learning and automation.",
            "The symbiotic relationship between technology and society has transformed the way we live, work, and interact with one another.",
            "The complexities of global economics require a nuanced understanding of market dynamics and international trade policies."};

        system("cls");
        setColor(2);
        printf("============================================================\n");
        char s[] = "            ******* PRACTICE MODE *******";
        for (int i = 0; s[i] != '\0'; i++)
        {
            setColor(15);
            printf("%c", s[i]);
            fflush(stdout);
            Sleep(50);
        }
        printf("\n");
        setColor(2);
        printf("============================================================\n");
        setColor(6);
        printf("Enter your player name: ");
        pname();
        setColor(15);
        printf("SELECT DIFFICULTY LEVEL:\n1. Easy\n2. Medium\n3. Hard\nENTER YOUR CHOICE -> ");
        if (scanf("%d", &level) != 1)
        {
            setColor(4);
            printf("Invalid input.\n");
            return;
        }
        if (level > 3 || level < 1)
        {
            setColor(4);
            printf("==============================\n");
            printf("!!!!!!! INVALID CHOICE !!!!!!!\n");
            printf("==============================\n");
            Sleep(1500);
            return;
        }
        int randIndex = rand() % 9;
        char *paragraph;
        if (level == 1)
            paragraph = easy[randIndex];
        else if (level == 2)
            paragraph = medium[randIndex];
        else
            paragraph = hard[randIndex];
        delaycall();
        getchar();
        setColor(15);
        printf("\n                   Start typing now!!!!\n");
        printf("------------------------------------------------------------\n");
        printf("%s\n", paragraph);
        printf("------------------------------------------------------------\n");
        char typed[1000];
        clock_t start_time = clock();
        if (fgets(typed, sizeof(typed), stdin) == NULL)
        {
            setColor(4);
            printf("Error reading input.\n");
            return;
        }
        clock_t end_time = clock();
        float time_taken = (float)(end_time - start_time) / CLOCKS_PER_SEC;
        float acc = accuracy_k(paragraph, typed);
        float wpm = wpm_k(typed, time_taken);
        setColor(13);
        printf("\n\n==================== RESULTS ====================\n");
        setColor(10);
        printf("Player     : %s\n", (udetail && udetail[0]) ? udetail : "Unknown");
        printf("Typed Line : %s", typed);
        printf("Time Taken : %.2f sec\n", time_taken);
        printf("Accuracy   : %.2f%%\n", acc);
        printf("WPM        : %.2f\n", wpm);
        setColor(13);
        printf("==================================================\n");
        setColor(15);
        printf("DO YOU WANT TO PRACTICE AGAIN? (Y/N): ");
        scanf(" %c", &play_again);
        getchar();
    }
}

int main()
{
    int ch;
    srand((unsigned int)time(NULL));
    while (1)
    {
        system("cls");
        setColor(11);
        printf("Please Select your choice for game type : \n");
        setColor(15);
        printf("TEST(1)\t  PRACTICE(2)\tEXIT(3)\n");
        printf("Enter your choice: ");
        if (scanf("%d", &ch) != 1)
        {
            setColor(4);
            printf("Invalid input.\n");
            return 0;
        }
        getchar();

        if (ch == 1)
        { 
            testmode();
        }
        else if (ch == 2)
        {
            practicemode();
        }
        else if (ch == 3)
        {
            break;
        }
        else
        {
            setColor(4);
            printf("INVALID INPUT\n");
            Sleep(1500);
        }
    }
    gamexit();
    return 0;
}
