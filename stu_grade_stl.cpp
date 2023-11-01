#include <iostream>
#include <map>
#include <string>

struct Score {
    int midterm;
    int final_exam;
};

int main() {
    int n;
    std::map<std::string, Score> student_scores;
    
    std::cout << "Enter number of students: ";
    std::cin >> n;

    for(int i = 0; i < n; ++i) {
        std::string name;
        Score s;
        std::cout << "Enter student name: ";
        std::cin >> name;
        std::cout << "Enter midterm score: ";
        std::cin >> s.midterm;
        std::cout << "Enter final exam score: ";
        std::cin >> s.final_exam;
        student_scores[name] = s;
    }

    std::string query;
    std::cout << "\nEnter a student name to search: ";
    std::cin >> query;
    if(student_scores.find(query) != student_scores.end()) {
        std::cout << "Midterm Score: " << student_scores[query].midterm << ", Final Exam Score: " << student_scores[query].final_exam << std::endl;
    } else {
        std::cout << "Student not found.\n";
    }

    return 0;
}
