//
// Created by 오민호 on 2017. 6. 24..
//

#include <iostream>
#include <vector>

const int MOD = 1000;

struct SquareMatrix {
    std::vector<std::vector<int> > matrix;
    size_t size;
    SquareMatrix(std::vector<std::vector<int> > matrix) {
        this->matrix = matrix;
        this->size = matrix.size();
    }

    SquareMatrix operator* (const SquareMatrix& ref) {
        std::vector<std::vector<int> > returnMatrix(size, std::vector<int>(size, 0));
        for(int i = 0 ; i < size ; ++i)
            for (int j = 0; j < size; ++j)
                for (int k = 0; k < size; ++k) {
                    returnMatrix[i][j] += ((matrix[i][k] * ref.matrix[k][j]) % MOD);
                    returnMatrix[i][j] %= MOD;
                }
        return SquareMatrix(returnMatrix);
    }

    void show() {
        for(int i = 0 ; i < size ; ++i) {
            for (int j = 0; j < size; ++j)
                std::cout << matrix[i][j] % MOD << " ";
            std::cout << "\n";
        }
    }
};

SquareMatrix identity(int n) {
    std::vector<std::vector<int> > matrix(n, std::vector<int>(n, 0));
    for(int i = 0 ; i < n ; ++i)
        matrix[i][i] = 1;
    return SquareMatrix(matrix);
}

SquareMatrix pow(SquareMatrix& A, unsigned long long m) {
    if(m == 0) return identity(A.size);
    if(m % 2 > 0) return pow(A, m - 1) * A;
    SquareMatrix half = pow(A, m / 2);
    return half * half;
}

int main() {
    std::ios::sync_with_stdio(false);
    int N;
    unsigned long long B;
    std::cin >> N >> B;
    std::vector<std::vector<int>> matrix(N, std::vector<int>(N, 0));

    for(int i = 0 ; i < N ; ++i)
        for(int j = 0 ; j < N ; ++j)
            std::cin >> matrix[i][j];
    SquareMatrix squareMatrix(matrix);
    SquareMatrix powMatrix = pow(squareMatrix, B);
    powMatrix.show();

}