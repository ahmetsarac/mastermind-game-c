// Mastermind 
// Ahmet Saraç 
// 03.03.2020 

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    char colors[] = "RGBYPO";
    char colorsRandom[5] = "";
    char colorsGuess[5] = "";
    int rGuess = 0, gGuess = 0, bGuess = 0, yGuess = 0, pGuess = 0, oGuess = 0;
    int rCounter = 0, gCounter = 0, bCounter = 0, yCounter = 0, pCounter = 0, oCounter = 0;
    int correctColor = 0;
    int posCounter = 0;
    int guessNumber = 0;
    int randIndex = 0;
    int length = 0;
    int status = 1;

    for (int i = 0; i < 4; i++) {
        randIndex = rand() % 6;
        colorsRandom[i] = colors[randIndex];
        switch (colorsRandom[i]) {
        case 'R':
            rCounter++;
            break;
        case 'G':
            gCounter++;
            break;
        case 'B':
            bCounter++;
            break;
        case 'Y':
            yCounter++;
            break;
        case 'P':
            pCounter++;
            break;
        case 'O':
            oCounter++;
        }
    }

    printf("Welcome to the Mastermind. Your target is guessing the correct colors which are randomly selected by computer.\n");
    printf("The colors in the game : R(Red), G(Green), B(Blue), Y(Yellow), P(Purple), O(Orange) \n");
    printf("Guess Number[0 - 100] : ");
    scanf("%d", &guessNumber);

    for(; guessNumber < 0 || !(guessNumber > 0 && guessNumber <= 100); ){
        printf("Please enter a valid number. \nGuess Number[0 - 100]: ");
        fflush(stdin);
        scanf("%d", &guessNumber);
    }
   
    printf("Now you can guess the colors. \n");
    fflush(stdin);

    printf("\n");

    for (int i = 0; i < guessNumber; i++) {
        rGuess = 0, gGuess = 0, bGuess = 0, yGuess = 0, pGuess = 0, oGuess = 0;
        correctColor = 0;
        posCounter = 0;
        status = 1;

        printf("Guess %d : ", i + 1);
        gets(colorsGuess);
        for (length = 0; colorsGuess[length] != '\0'; length++) {};
        for (; length < 4;) {
            printf("Wrong input you must guess 4 colors. Try again. \n");
            break;
        }
        if (length == 4) {
            for (int j = 0; colorsGuess[j] != 0; j++) {
                if (colorsGuess[j] != 'R' && colorsGuess[j] != 'G' && colorsGuess[j] != 'B' && colorsGuess[j] != 'Y' && colorsGuess[j] != 'P' && colorsGuess[j] != 'O') {
                    printf("Wrong input use the given colors. \n");
                    status = 0;
                    break;
                }
            }
        }
        if (length == 4 && status != 0) {
            for (int k = 0; k < 4; k++) {
                switch (colorsGuess[k]) {
                case 'R':
                    rGuess++;
                    break;
                case 'G':
                    gGuess++;
                    break;
                case 'B':
                    bGuess++;
                    break;
                case 'Y':
                    yGuess++;
                    break;
                case 'P':
                    pGuess++;
                    break;
                case 'O':
                    oGuess++;
                }
            }
            if ((rGuess > 0 && rCounter > 0)) {
                if (rGuess >= rCounter) {
                    correctColor += rCounter;
                } else {
                    correctColor += rGuess;
                }
            }
            if ((gGuess > 0 && gCounter > 0)) {
                if (gGuess >= gCounter) {
                    correctColor += gCounter;
                } else {
                    correctColor += gGuess;
                }
            }
            if ((bGuess > 0 && bCounter > 0)) {
                if (bGuess >= bCounter) {
                    correctColor += bCounter;
                } else {
                    correctColor += bGuess;
                }
            }
            if ((yGuess > 0 && yCounter > 0)) {
                if (yGuess >= yCounter) {
                    correctColor += yCounter;
                } else {
                    correctColor += yGuess;
                }
            }
            if ((pGuess > 0 && pCounter > 0)) {
                if (pGuess >= pCounter) {
                    correctColor += pCounter;
                } else {
                    correctColor += pGuess;
                }
            }
            if ((oGuess > 0 && oCounter > 0)) {
                if (oGuess >= oCounter) {
                    correctColor += oCounter;
                } else {
                    correctColor += oGuess;
                }
            }
            for (int k = 0; k < 4; k++) {
                if (colorsGuess[k] == colorsRandom[k]) {
                    posCounter++;
                }
            }

            if (correctColor == 0) {
                printf("No correct guess\n");
            } else if (posCounter > 0 && correctColor > posCounter) {
                printf("%d colors has right position %d colors has wrong position. \n", posCounter, correctColor - posCounter);
            } else if (posCounter > 0) {
                printf("%d color has right position. \n", posCounter);
                if (posCounter == 4) {
                    printf("Selected colors by computer : ");
                    puts(colorsRandom);
                    printf("\n You won the game.");
                    break;
                }

            } else if (posCounter == 0 && correctColor > 0) {
                printf("%d colors has wrong position. \n", correctColor);
            }
        }

        if (i == guessNumber - 1) {
            printf("You lost the game. Game over. \n");
            printf("Selected colors by computer : ");
            puts(colorsRandom);
        }
    }

    getch();
    return 0;
}