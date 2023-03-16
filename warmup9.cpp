#include <iostream>
#include <vector>

class NumMatrix {
private:
    int row, col;
    std::vector<std::vector<int>> sums;
public:
    NumMatrix(std::vector<std::vector<int>> &matrix) {
        row = matrix.size();
        col = row>0 ? matrix[0].size() : 0;
        sums = std::vector<std::vector<int>>(row+1, std::vector<int>(col+1, 0));
        for(int i=1; i<=row; i++) {
            for(int j=1; j<=col; j++) {
                sums[i][j] = matrix[i-1][j-1] +
                             sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] ;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
    }
};

int main() {
    int rows, columns, k;
    std::cin >> rows >> columns >> k;
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(columns));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cin >> matrix[i][j];
        }
    }

    NumMatrix nm(matrix);

    int x1, y1, x2, y2;
    for (int i = 0; i < k; i++) {
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << nm.sumRegion(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << std::endl;
    }

    return 0;
}

/*
 Вам необходимо ответить на запросы узнать сумму всех элементов числовой матрицы N×M в прямоугольнике с левым верхним углом
 (x1, y1) и правым нижним (x2, y2)
 */