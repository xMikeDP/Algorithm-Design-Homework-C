// utils.h is used for the distributeBooks function
#include "utils.h"

// stdio.h is used for the printf function
#include <stdio.h>

// math.h is used for the abs function which finds the absolute value
#include <math.h>

// time.h and stdlib.h are used for the random numbers
#include <time.h>
#include <stdlib.h>

int get_random_no_books() {
    time_t t;
    srand((unsigned)time(&t));
    return rand()%20 + 5; // Random number 5 to 25
}

void set_random_books(int *book, int no_books) {
    int i;
    time_t t;
    srand((unsigned)time(&t));
    for(i = 0; i < no_books; i++) {
        book[i] = rand()%10000+1; // Random number 1 to 10000
    }
}

void distribute_books(int *book, int book_count) {
    // Initialize the Total Pages with 0
    int total_pages = 0;

    // Count the total number of pages
    for (int i = 0; i < book_count; i++) {
        total_pages += book[i];
    }

    // Get the average number of pages per employee
    int avg_pages = total_pages / 3;

    // Each employee will represent a section and we initialize them
    int section_pages = 0;
    int section_count = 0;
    int desired_value = -1;

    // Go through every book in the array
    for (int i = 0; i < book_count; i++) {
        // For every book, we add its pages to the section total page sum
        section_pages += book[i];

        // Find the point where adding another book exceeds the average pages count
        if(section_pages + book[i+1] > avg_pages) {
            // Find the number of pages before adding another book
            int before_avg = section_pages;

            // Find the number of pages after adding another book
            int after_avg = section_pages + book[i+1];

            // Find whether it's worth adding another book to the section or not
            if(abs(avg_pages-before_avg) > abs(avg_pages-after_avg)) {
                // If the after_avg page count is closer to avg_pages
                desired_value = after_avg;
            } else {
                // If the before_avg page count is closer to avg_pages
                desired_value = before_avg;
            }
        }

        // Print each book's page count
        printf("%d ", book[i]);

        // If the page count in the current section reaches the desired value, and we have less than 3 sections
        if (section_pages == desired_value && section_count < 2) {
            // Separate sections with a "-"
            printf("- ");

            // Reset pages and desired value
            section_pages = 0;
            desired_value = -1;

            // Move onto the next section
            section_count++;
        }
    }
}
