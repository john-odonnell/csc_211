#include <iostream>

const int students = 4;
const int exams = 3;

void studentAvg(int grades[][exams]) {
    for (int i = 0; i < students; i++) {
        int total = 0;
        for (int j = 0; j < exams; j++) {
            total += grades[i][j];
        }
        float average = total / exams;
        std::cout << "Student " << i << " Average: " << average << std::endl;
    }
    std::cout << std::endl;
}

void examAvg(int grades[][exams]) {
    for (int j = 0; j < exams; j++) {
        int total = 0;
        for (int i = 0; i < students; i++) {
            total += grades[i][j];
        }
        float average = total / students;
        std::cout << "Exam " << j << " Average: " << average << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int grades[students][exams] = {{90, 75, 100}, {50, 65, 75},
                                    {100, 100, 100}, {85, 90, 79}};

    studentAvg(grades);
    examAvg(grades);

    return 0;
}