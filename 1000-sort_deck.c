#include "deck.h"

int strcmp(const char *str1, const char *str2);
char getValue(deck_node_t *car);
void insertionSortDeckKind(deck_node_t **deck);
void insertionSortDeckValue(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * strcmp - Compare two strings.
 * @str1: The first string to be compared.
 * @str2: The second string to be compared.
 *
 * Return:
 * - An integer less than 0 if str1 is less than str2.
 * - 0 if str1 is equal to str2.
 * - An integer greater than 0 if str1 is greater than str2.
 */
int strcm
