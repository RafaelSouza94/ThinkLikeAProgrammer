#include "Chapter3.h"

void Chapter3::finding_mode() {

    cout << "------------- Finding the mode problem.\n";

    const int ARRAY_SIZE = 12;

    int survey_data[ARRAY_SIZE] = {4, 7, 7, 9, 9, 9, 8, 3, 3, 3, 3, 10};
    int most_frequent = 0;
    int highest_frequency = 0;
    int current_frequency = 0;

    // FIX
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << "I: " << i << " Current frequency: " << current_frequency << " Highest Frequency: " << highest_frequency << " Most Frequent: " << most_frequent << endl;
        current_frequency++;
        if (i == ARRAY_SIZE - 1 || survey_data[i] != survey_data[i + 1]) {
            if (current_frequency > highest_frequency) {
                highest_frequency = current_frequency;
                most_frequent = survey_data[i];
            }
        }
    }

    //cout << "Array: " << survey_data << endl;
    cout << "Mode of the array: " << most_frequent << endl;

    //qsort (survey_data, ARRAY_SIZE, sizeof (int), compare_func);

}

int Chapter3::compare_func (const void *void_a, const void *void_b) {

        int *int_a = (int *)(void_b);
        int *int_b = (int *)(void_b);
        return *int_a - *int_b;
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