#include <stdio.h>
#include "cards.h"
int main()
{
    //! Init code
    Deck balicek;
    initializeDeck(&balicek);
    shuffleDeck(&balicek);
    //*********

    Gamestate hra;
    Deck table;
    drawCardsDeck(5, &balicek, &table);

    hra.pot = 0;
    hra.cur_bet = 100;
    hra.table = table;

        //------
    //! Player init
    // Hrac p1 = {
    //     .money = 10000,
    //     .balicek_hrace = {0}};
    // Hrac p2 = {
    //     .money = 10000,
    //     .balicek_hrace = {0}};

    return 0;
}