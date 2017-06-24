//
// Created by 오민호 on 2017. 6. 24..
//

#include <iostream>
#include <vector>

const int MOD = 1000000;

typedef unsigned long long ull;

struct SquareMatrix {
    std::vector<std::vector<ull> > matrix;
    size_t size;
    SquareMatrix(std::vector<std::vector<ull> > matrix) {
        this->matrix = matrix;
        this->size = matrix.size();
    }

    SquareMatrix operator* (const SquareMatrix& ref) {
        std::vector<std::vector<ull> > returnMatrix(size, std::vector<ull>(size, 0));
        for(int i = 0 ; i < size ; ++i)
            for (int j = 0; j < size; ++j)
                for (int k = 0; k < size; ++k) {
                    returnMatrix[i][j] += ((matrix[i][k]  * ref.matrix[k][j]) % MOD);
                    returnMatrix[i][j] %= MOD;
                }
        return SquareMatrix(returnMatrix);
    }
};

SquareMatrix identity(int n) {
    std::vector<std::vector<ull> > matrix(n, std::vector<ull>(n, 0));
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
    ull n;
    std::cin >> n;
    std::vector<std::vector<ull>> matrix(2, std::vector<ull>(2, 0));
    matrix[0][1] = matrix[1][0] = matrix[1][1] = 1;
    SquareMatrix squareMatrix(matrix);
    std::cout << pow(squareMatrix, n - 1).matrix[1][1] << "\n";
}


