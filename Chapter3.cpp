#include "Chapter3.h"

int compare_func (const void*, const void*);

void Chapter3::finding_mode() {

    cout << "------------- Finding the mode problem.\n";

    const int ARRAY_SIZE = 12;

    int survey_data[ARRAY_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};
    int most_frequent = 0;
    int highest_frequency = 0;
    int current_frequency = 0;

    qsort (survey_data, ARRAY_SIZE, sizeof (int), compare_func);

    /*for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << survey_data[i] << " ";
    }

    cout << "\n";*/

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

    cout << "Mode of the array: " << most_frequent << endl;



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