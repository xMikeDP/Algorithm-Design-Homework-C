// utils.h is used for the distributeBooks function
#include "utils.h"

int main() {
    // Initialize a "book" array which contains the page count of every book
    //int book[] = {100, 100, 100, 100, 100, 100, 100, 100, 100};

    // Initialize a "book" array with random amount of books.
    // Comment this line and uncomment the one above for preset number of books
    int book[get_random_no_books()];
    // Find how many books are in the array
    int book_count = sizeof(book) / sizeof(book[0]);

    // Sets a random number of pages for every book
    // Comment this line for preset book pages
    set_random_books(book, book_count);

    // Call the function that solves the problem
    distribute_books(book, book_count);

    // Return 0 if the code has been executed correctly
    return 0;
}



