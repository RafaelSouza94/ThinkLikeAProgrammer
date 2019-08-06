#include "Chapter3.h"

void Chapter3::finding_mode() {

    cout << "------------- Finding the mode problem.\n";

    const int ARRAY_SIZE = 12;

    int survey_data[ARRAY_SIZE] = {4, 7, 7, 9, 9, 9, 8, 3, 3, 3, 3, 10};
    int most_frequent;
    int highest_frequency = 0;
    int current_frequency = 0;

    // FIX
    for (int i = 0; i < ARRAY_SIZE; i++) {
        current_frequency++;
        if (i == ARRAY_SIZE - 1 || survey_data[i] != survey_data[i + 1]) {
            if (current_frequency > highest_frequency) {
                highest_frequency = current_frequency;
                most_frequent = survey_data[i];
            }
        }
    }

    cout << "Array: " << survey_data << endl;
    cout << "Mode of the array: " << most_frequent << endl;

}