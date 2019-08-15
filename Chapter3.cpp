#include "Chapter3.h"

int compare_func (const void*, const void*);

void Chapter3::finding_mode() {

    cout << "------------- Finding the mode problem.\n";

    const int ARRAY_SIZE = 12;

    int survey_data[ARRAY_SIZE] = { 4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10 };
    int most_frequent = 0;
    int highest_frequency = 0;
    int current_frequency = 0;

    qsort(survey_data, ARRAY_SIZE, sizeof(int), compare_func);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        current_frequency++;
        if (i == ARRAY_SIZE - 1 || survey_data[i] != survey_data[i + 1]) {
            if (current_frequency > highest_frequency) {
                highest_frequency = current_frequency;
                most_frequent = survey_data[i];
            }
            current_frequency = 0;
        }
    }

    cout << "Mode of the array using qsort: " << most_frequent << endl;

    int* histogram;
    
    most_frequent = 0;
    histogram = get_histogram(survey_data, ARRAY_SIZE);
        

    /********** Print the histogram
    cout << "Printing histogram" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << "Value for " << (i + 1) << ": " << *(histogram + i) << endl;
    }
    */

    // Find the mode of the array using the histogram
    for (int i = 1; i < MAX_RESPONSE; i++) {
        if (*(histogram + i) > * (histogram + most_frequent)) {
            most_frequent = i;
        }
    }
    most_frequent++;
    cout << "Mode of the array using the histogram: " << most_frequent << endl;
}
   
int * Chapter3::get_histogram (int* array, int array_size) {

    const int MAX_RESPONSE = 10;
    static int histogram[MAX_RESPONSE];

    for (int i = 0; i < MAX_RESPONSE; i++) {
        histogram[i] = 0;
    }

    for (int i = 0; i < array_size; i++) {
        histogram[array[i] - 1]++;
    }

    return histogram;
}

int compare_func (const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void Chapter3::insertion_sort (int *array, int ARRAY_SIZE) {

    int start = 0;
    int end = ARRAY_SIZE - 1;
    for (int i = start + 1; i <= end; i++) {
        for (int j = i; j > start && array[j - 1] > array[j]; j--) {
            int temp = array[j - 1];
            array[j - 1] = array[j];
            array[j] = temp;
        }
    }
}

void Chapter3::license_cost (int category, double gross_sales) {

    const int NUM_CATEGORIES = 4;
    const double category_thresholds[NUM_CATEGORIES] = { 0.0, 50000.0, 150000.0, 500000.0 };
    const double license_cost[NUM_CATEGORIES] = { 50.0, 200.0, 1000.0, 5000.0 };

    double cost;

    while (category < NUM_CATEGORIES && category_thresholds[category] <= gross_sales) {
        category++;
    }

    cost = license_cost[category - 1];

    cout << "Cost of business category " << category << " with gross sales of " << gross_sales << " getting a license is " << cost;
}