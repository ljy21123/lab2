#include <iostream>
#include <string>

struct Student {
    std::string name;
    int midterm_score;
    int final_score;
    Student* left;   // 왼쪽 하위 트리 포인터
    Student* right;  // 오른쪽 하위 트리 포인터
};

class StudentTree {
private:
    Student* root;

    Student* insert(Student* node, const std::string& name, int midterm, int final) {
        if (node == nullptr) {
            node = new Student();
            node->name = name;
            node->midterm_score = midterm;
            node->final_score = final;
            node->left = node->right = nullptr;
        } else if (name < node->name) {
            node->left = insert(node->left, name, midterm, final);
        } else if (name > node->name) {
            node->right = insert(node->right, name, midterm, final);
        }
        return node;
    }

    void inorder(Student* node) {
        if (node != nullptr) {
            inorder(node->left);
            std::cout << node->name << ": Midterm = " << node->midterm_score << ", Final = " << node->final_score << std::endl;
            inorder(node->right);
        }
    }

public:
    StudentTree() : root(nullptr) {}

    void insert(const std::string& name, int midterm, int final) {
        root = insert(root, name, midterm, final);
    }

    void display() {
        inorder(root);
    }
};

int main() {
    StudentTree tree;
    int num_students;
    
    std::cout << "Enter the number of students: ";
    std::cin >> num_students;

    for (int i = 0; i < num_students; i++) {
        std::string name;
        int midterm, final;

        std::cout << "Enter name of student " << i + 1 << ": ";
        std::cin >> name;
        std::cout << "Enter midterm score for " << name << ": ";
        std::cin >> midterm;
        std::cout << "Enter final score for " << name << ": ";
        std::cin >> final;

        tree.insert(name, midterm, final);
    }

    std::cout << "\nDisplaying student scores in alphabetical order:\n";
    tree.display();

    return 0;
}
