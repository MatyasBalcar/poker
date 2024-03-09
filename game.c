#include <stdio.h>
#include "cards.h"
int main()
{
    //! Init code
    Deck balicek;
    initializeDeck(&balicek);
    shuffleDeck(&balicek);
    //*********

    //------
    //*balicek = balicek dealera
    //! Player init
    int running = 1;
    Hrac p1 = {
        .money = 10000,
        .balicek_hrace = {0},
        .is_dealer = 0};
    Hrac dealer = {
        .money = 0,
        .balicek_hrace = {0},
        .is_dealer = 1};
    //*game seq
    drawCards(1, &p1, &balicek);
    drawCards(1, &dealer, &balicek);
    while (running)
    {
        printf("dealer\n");
        for (int i = 0; i < dealer.balicek_hrace->curr_size; i++)
        {
            printf("[X]");
        }
        printf("\n");
        printPlayerInfo(&p1);
        char drawAnotherCard;
        printf("Do you want to draw another card? (y/n): ");
        scanf(" %c", &drawAnotherCard);

        if (drawAnotherCard == 'y' || drawAnotherCard == 'Y')
        {
            drawCards(1, &p1, &balicek);
            printPlayerInfo(&p1);
        }
        else
        {
            running = 0;
            printPlayerInfo(&dealer);
        }
    }

    return 0;
}