#include <stdio.h>
#include "cards.h"
#include <string.h>
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
    int dealer_playing = 1;
    int game_running = 1;
    Hrac p1 = {
        .money = 10000,
        .balicek_hrace = {0},
        .is_dealer = 0};
    Hrac dealer = {
        .money = 0,
        .balicek_hrace = {0},
        .is_dealer = 1};
    //*game seq
    while (game_running)
    {

        drawCards(1, &p1, &balicek);
        drawCards(1, &dealer, &balicek);
        int playerScore = 0;
        int bet = 0;
        printf("How much do you want to bet? ");
        scanf("%d", &bet);
        p1.money -= bet;
        while (running)
        {

            printPlayerInfo(&p1);
            char drawAnotherCard;
            printf("Do you want to draw another card? (y/n): ");
            scanf(" %c", &drawAnotherCard);

            if (drawAnotherCard == 'y' || drawAnotherCard == 'Y')
            {
                drawCards(1, &p1, &balicek);
                printPlayerInfo(&p1);
                DeckValue deckValues = calculateDeckValue(p1.balicek_hrace);
                int value = deckValues.minValue < deckValues.maxValue ? deckValues.minValue : deckValues.maxValue;
                if (value > 21)
                {
                    printf("BUST, dealer wins\n");
                    running = 0;
                    dealer_playing = 0;
                }
            }
            else
            {
                running = 0;
                DeckValue deckValues = calculateDeckValue(p1.balicek_hrace);
                int value = deckValues.minValue < deckValues.maxValue ? deckValues.minValue : deckValues.maxValue;
                printf("Player score : %d \n", value);
                playerScore = value;
            }
        }
        while (dealer_playing)
        {
            DeckValue deckValues = calculateDeckValue(dealer.balicek_hrace);
            int dvalue = deckValues.minValue > deckValues.maxValue ? deckValues.minValue : deckValues.maxValue;
            if (dvalue <= playerScore)
            {
                drawCards(1, &dealer, &balicek);
                printf("Dealer draws \n");
                printDeck(dealer.balicek_hrace);
            }
            else if (dvalue > 21)
            {
                printf("dealer bust on %d, player wins\n", dvalue);
                printDeck(dealer.balicek_hrace);
                p1.money += bet * 2;
                dealer_playing = 0;
            }
            else
            {
                printf("dealer won on %d \n", dvalue);
                printDeck(dealer.balicek_hrace);
                dealer_playing = 0;
            }
        }
        printf("Current player money :%d\n", p1.money);
        char to_continue;
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &to_continue);
        if (to_continue == 'y' || to_continue == 'Y')
        {
            drawCards(1, &p1, &balicek);
            printPlayerInfo(&p1);
            DeckValue deckValues = calculateDeckValue(p1.balicek_hrace);
            int value = deckValues.minValue < deckValues.maxValue ? deckValues.minValue : deckValues.maxValue;
            if (value > 21)
            {
                printf("BUST, dealer wins\n");
                running = 0;
                dealer_playing = 0;
            }
        }
        else
        {
            game_running = 0; // Exit the game when the player chooses not to draw another card
        }
    }
    return 0;
}