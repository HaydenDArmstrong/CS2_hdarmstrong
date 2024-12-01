#include <iostream>
#include <vector>

struct Homework {
    double score;
    double total;
};

int main() {
    std::vector<Homework> homework_assignments = {
        {13.66, 14}, {8, 8}, {6, 7}, {12, 12}, {16, 16}, {12, 12}, {12, 12}, {8, 8},
        {4, 4}, {6, 6}, {13.83, 14}, {10, 10}, {22.49, 25}, {10, 10}, {9.83, 10},
        {14, 14}, {14, 14}, {14, 14}, {8.67, 9}, {9, 9}, {12, 12}, {28, 30},
        {9.25, 10}, {7, 7}, {11.67, 12}, {9, 9}, {12, 13}, {4.53, 5}, {10.4, 13},
        {5, 6}, {11.51, 12}, {27.95, 31}, {8, 8}, {13, 13}, {9, 9}, {9, 9}, {8, 8},
        {16, 17}
    };

    // Add the assignments from homework 5.2 and onwards with a score of 98%
    std::vector<Homework> additional_assignments = {
        { 9, 9}, { 9, 10}, {8.39, 8.39}, {6, 6}, { 15, 16}
    };

    // Combine the two lists of assignments
    homework_assignments.insert(homework_assignments.end(), additional_assignments.begin(), additional_assignments.end());

    // Calculate the weighted score and total possible points
    double weighted_score = 0;
    double weighted_total = 0;

    for (const auto& hw : homework_assignments) {
        weighted_score += hw.score * (hw.total == 20 ? 2 : 1);
        weighted_total += hw.total * (hw.total == 20 ? 2 : 1);
    }

    // Calculate the overall grade percentage
    double overall_grade_percentage = (weighted_score / weighted_total) * 100;

    std::cout << "The overall homework grade is " << overall_grade_percentage << "%" << std::endl;

    return 0;
}