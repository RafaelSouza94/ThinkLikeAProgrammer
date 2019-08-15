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

void Chapter3::highest_grades() {

    const int ARRAY_SIZE = 10;

    student student_array[ARRAY_SIZE] = {
        {87, 10001, "Fred"},
        {28, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},
        {70, 10008, "Candy"},
        {81, 10009, "Aretha"},
        {68, 10010, "Veronica"}
    };

    int highest_postion = 0;

    for (int i = 1; i < ARRAY_SIZE; i++) {
        if (student_array[i].grade > student_array[highest_postion].grade) {
             highest_postion = i;
        }
    }

    cout << "Highest grade in array: " << student_array[highest_postion].grade << "\nBelongs to: " << student_array[highest_postion].name << endl;

}

double array_average(int int_array[], int ARRAY_SIZE) {

    double sum = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += int_array[i];
    }
    double average = sum / ARRAY_SIZE;
    return average;
}

void Chapter3::highest_sales() {

    const int NUM_AGENTS = 3;
    const int NUM_MONTHS = 12;

    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };
    int highest_sales = sales[0][0];

    for (int agent = 0; agent < NUM_AGENTS; agent++) {
        for (int month = 0; month < NUM_MONTHS; month++) {
            if (sales[agent][month] > highest_sales) {
                highest_sales = sales[agent][month];
            }
        }
    }

    cout << "Highest sales: " << highest_sales << endl;

    double highest_average = array_average(sales[0], 12);
    for (int agent = 1; agent < NUM_AGENTS; agent++) {
        double agent_average = array_average(sales[agent], 12);
        if (agent_average > highest_average)
            highest_average = agent_average;
    }

    cout << "Highest average monthly sales: " << highest_average << endl;
}

void Chapter3::dynamic_survey() {

    const int MAX_RESPONSE = 10;

    vector<int> survey_data;
    int survey_response;
    int histogram[MAX_RESPONSE];
    int vector_size = 0;
    int most_frequent = 0;

    survey_data.reserve(30); // not necessary, but good to prevent the vector to keep resizing as we add values to it

    cout << "Enter the next survey response or -1 to end: ";
    cin >> survey_response;
    while (survey_response != -1) {
        survey_data.push_back(survey_response);
        cout << "Enter the next survey response or -1 to end: ";
        cin >> survey_response;
    }

    vector_size = survey_data.size();
    for (int i = 0; i < MAX_RESPONSE; i++) {
        histogram[i] = 0;
    }

    for (int i = 0; i < vector_size; i++) {
        histogram[survey_data[i] - 1]++;
    }

    for (int i = 1; i < MAX_RESPONSE; i++) {
        if (histogram[i] > histogram[most_frequent])
            most_frequent = i;
    }
    most_frequent++;

    cout << "\nMost frequent answer: " << most_frequent << endl;

}