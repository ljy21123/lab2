#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;
    cout << "rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrixA(rows, vector<int>(cols));
    vector<vector<int>> matrixB(rows, vector<int>(cols));
    vector<vector<int>> resultMatrix(rows, vector<int>(cols));

    cout << "Matrix A:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrixA[i][j];
        }
    }

    cout << "Matrix B:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrixB[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    cout << "Result Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << resultMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
