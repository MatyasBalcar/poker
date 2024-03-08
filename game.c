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
    Hrac p1 = {
        .money = 10000,
        .balicek_hrace = {0}};
    Hrac dealer = {
        .money = 10000,
        .balicek_hrace = {0}};
    //*game seq
    drawCards(1, &p1, &balicek);
    drawCards(1, &dealer, &balicek);
    printf("dealer\n");
    for (int i = 0; i < dealer.balicek_hrace->curr_size; i++)
    {
        printf("[X]");
    }
    printf("\n");
    printPlayerInfo(&p1);

    return 0;
}