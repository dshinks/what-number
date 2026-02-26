#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


int main(void){
    int lives = 5;
    bool receivedBonusLife = false;
    int maxRandomNumber = 100;
    int randomNumber;
    int guess;
    int distanceFromRandom;

    srand(time(NULL));
    randomNumber = (rand() % (maxRandomNumber + 1));

    puts("What number am I thinking of?");
    printf("The number is between 0 and %d.\n", maxRandomNumber);
    
    do {
        printf("You have %d guesses\n", lives);
        printf("Enter guess\n?> ");
        scanf("%d", &guess);
        distanceFromRandom = abs(guess - randomNumber);
        if(guess != randomNumber){
            printf("Sorry, my number is not %d.\n", guess);
            
            if(distanceFromRandom < 5){
                if(receivedBonusLife == false) {
                    puts("You're very hot! Have a bonus life!");
                    receivedBonusLife = true;
                    lives ++;            
                } else {
                    puts("You're very hot!");
                    lives --;
                }
            } else if(distanceFromRandom < 10){
                puts("You're quite warm...");
                lives --;
            } else {      
                lives --;
            }
        }

    } while (lives > 0 &&  guess != randomNumber);

    if(guess == randomNumber){
        printf("Well done! My number was %d!\n", randomNumber);
    } else {
        printf("Bad luck! My number was %d!\n", randomNumber);
    }

    puts("Until next time!");
    

}