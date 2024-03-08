#include <stdio.h>
#include "cards.h"
#include <time.h>

void shuffleDeck(Deck *deck)
{
    srand(time(NULL));
    for (int i = 51; i > 0; --i)
    {
        int j = rand() % (i + 1);
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}
void printDeck(Deck *deck)
{
    const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *values[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    for (int i = 0; i < deck->curr_size; i++)
    {
        printf("Value : %8s | Symbol : %8s\n", values[deck->cards[i].value - 2], suits[deck->cards[i].suit]);
    }
}
void initializeDeck(Deck *deck)
{
    for (int i = 0; i < 52; i++)
    {
        deck->cards[i].value = i % 13 + 2; // Add 2 to shift the values to match the values array
        deck->cards[i].suit = i / 13;
    }
    deck->curr_size = 52;
}
void printPlayerInfo(Hrac *hracp)
{
    printf("Money: %d\n", hracp->money);
    printf("Balicek:\n");
    printDeck(hracp->balicek_hrace);
}
Card drawCard(Deck *deck, int *size)
{
    int index = rand() % *size;
    Card drawnCard = deck->cards[index];

    // Shift all cards after the drawn card to fill the gap
    for (int i = index; i < *size - 1; ++i)
    {
        deck->cards[i] = deck->cards[i + 1];
    }

    // Decrease the size of the deck
    --(*size);

    return drawnCard;
}
void drawCards(int count, Hrac *player, Deck *deck)
{
    for (int i = 0; i < count; ++i)
    {
        if (deck->curr_size > 0)
        {
            // Draw a card from the main deck
            Card drawnCard = drawCard(deck, &(deck->curr_size));

            // Add the drawn card to the player's deck
            player->balicek_hrace[0].cards[player->balicek_hrace[0].curr_size] = drawnCard;
            player->balicek_hrace[0].curr_size++;
        }
        else
        {
            printf("The deck is empty. Cannot draw more cards.\n");
            break;
        }
    }
}
void drawCardsDeck(int count, Deck *sourceDeck, Deck *targetDeck)
{
    for (int i = 0; i < count; ++i)
    {
        if (sourceDeck->curr_size > 0)
        {
            // Draw a card from the source deck
            Card drawnCard = drawCard(sourceDeck, &(sourceDeck->curr_size));

            // Add the drawn card to the target deck
            targetDeck->cards[targetDeck->curr_size] = drawnCard;
            targetDeck->curr_size++;
        }
        else
        {
            printf("The source deck is empty. Cannot draw more cards.\n");
            break;
        }
    }
}
void printNCardsFromDeck(Deck *deck, int n)
{
    const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *values[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    for (int i = 0; i < n; i++)
    {
        printf("Value : %8s | Symbol : %8s\n", values[deck->cards[i].value - 2], suits[deck->cards[i].suit]);
    }
}