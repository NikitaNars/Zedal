#include <iostream>
#include <cmath>
#include <iomanip>

const int MAX_SIZE = 10;  // Максимальное количество уравнений

void ZeidelMethod(double A[MAX_SIZE][MAX_SIZE], double b[MAX_SIZE], double x[MAX_SIZE], int n) {
    const double epsilon = 0.0000001;
    const int maxIter = 500;
    double x_old[MAX_SIZE];
    int iter = 0;

    for (int k = 0; k < maxIter; ++k) {
        for (int i = 0; i < n; ++i) {
            x_old[i] = x[i];

            double sum = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x[i] = (b[i] - sum) / A[i][i];
        }

        double maxDiff = 0.0;
        for (int i = 0; i < n; ++i) {
            maxDiff = std::max(maxDiff, std::abs(x[i] - x_old[i]));
        }

        if (maxDiff < epsilon) {
            iter = k + 1;
            std::cout << "Количество итераций: " << iter << "\n";
            return;
        }
    }

    std::cout << "Достигнуто максимальное число итераций: " << maxIter << "\n";
}

bool IsDiagonallyDominant(double A[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                sum += std::abs(A[i][j]);
            }
        }
        if (std::abs(A[i][i]) <= sum) {
            return false;
        }
    }
    return true;
}




int main() {
    setlocale(LC_ALL, "ru");
    double A[MAX_SIZE][MAX_SIZE] = {
        {16.63, -0.24, -6.10},
        {-3.45, -23.13, 1.11},
        {3.76, -8.72, -27.01}
    };
    double b1[MAX_SIZE] = { 7.29, -3.41, -8.19 };
    double x1[MAX_SIZE] = { 0 }; // Начальные приближения к нулю
    int n1 = 3; // Количество уравнений

    double B[MAX_SIZE][MAX_SIZE] = {
        {-14.95, 0.68, 8.86},
        {0.16, -15.38, 0.53},
        {4.71, -2.84, 24.18}
    };
    double b2[MAX_SIZE] = { -0.76, -8.69, 8.68 };
    double x2[MAX_SIZE] = { 0 }; // Начальные приближения к нулю
    int n2 = 3; // Количество уравнений

    double C[MAX_SIZE][MAX_SIZE] = {
        {-28.93, -7.61, -7.61, -7.29},
        {8.33, 23.48, -6.01, 1.42},
        {8.64, 8.40, -16.51, -7.74},
        {0.91, 6.13, -4.51, -22.76}
    };
    double b3[MAX_SIZE] = { 7.68, -7.32, -0.16, -2.33 };
    double x3[MAX_SIZE] = { 0 }; // Начальные приближения к нулю
    int n3 = 4; // Количество уравнений

    double D[MAX_SIZE][MAX_SIZE] = {
        {24.58, -0.18, -7.14, -5.06, 8.00},
        {6.98, 13.75, 1.10, 7.43, -4.96},
        {-7.20, 1.42, 26.33, 4.35, 0.58},
        {-6.70, -5.30, -1.20, -21.02, 6.55},
        {-6.19, -8.56, -3.08, -6.76, -13.61}
    };
    double b4[MAX_SIZE] = { 4.26, -6.73, -2.19, 8.45, -4.09 };
    double x4[MAX_SIZE] = { 0 }; // Начальные приближения к нулю
    int n4 = 4; // Количество уравнений

    double E[MAX_SIZE][MAX_SIZE] = {
        {22.52, -4.62, -1.41},
        {-5.10, -28.37, 4.58},
        {4.68, -1.91, 23.85}
    };
    double b5[MAX_SIZE] = { 0.53, -8.78, 5.14 };
    double x5[MAX_SIZE] = { 0 }; // Начальные приближения к нулю
    int n5 = 3; // Количество уравнений

    double F[MAX_SIZE][MAX_SIZE] = {
        {23.98, 9.24, -8.78, 7.74},
        {8.70, -28.73, 3.86, 8.08},
        {1.62, 3.88, -18.17, -8.68},
        {-6.97, 1.96, 1.55, -29.54}
    };
    double b6[MAX_SIZE] = { -0.04, 7.86, -0.44, -2.02 };
    double x6[MAX_SIZE] = { 0 }; // Начальные приближения к нулю
    int n6 = 4; // Количество уравнений

    double G[MAX_SIZE][MAX_SIZE] = {
        {-17.01, 6.28, -8.25, -2.57, 3.05},
        {7.98, 18.40, 0.79, -0.35, 8.54},
        {-8.82, 2.07, -15.99, 4.30, 1.03},
        {2.43, -4.29, 0.52, 31.46, 4.78},
        {-5.82, 1.84, 3.11, 6.42, 21.47}
    };
    double b7[MAX_SIZE] = { -6.47, 0.28, -4.39, 5.05, -0.54 };
    double x7[MAX_SIZE] = { 0 }; // Начальные приближения к нулю
    int n7 = 5; // Количество уравнений



    if (IsDiagonallyDominant(A, n1)) {
        std::cout << "Система уравнений имеет обязательное сходимости.\n";
        ZeidelMethod(A, b1, x1, n1);
        // Печать результатов
        std::cout << "Решение:\n";
        for (int i = 0; i < n1; ++i) {
            std::cout << "x[" << i << "] = " << std::setprecision(10) << x1[i] << "\n\n\n";
        }
    }
    else {
        std::cout << "Система уравнений не является диагонально доминирующей.\n\n\n";
    }

    if (IsDiagonallyDominant(B, n2)) {
        std::cout << "Система уравнений имеет обязательное сходимости.\n";
        ZeidelMethod(B, b2, x2, n2);
        // Печать результатов
        std::cout << "Решение:\n";
        for (int i = 0; i < n2; ++i) {
            std::cout << "x[" << i << "] = " << std::setprecision(10) << x2[i] << "\n\n\n";
        }
    }
    else {
        std::cout << "Система уравнений не является диагонально доминирующей.\n\n\n";
    }

    if (IsDiagonallyDominant(C, n3)) {
        std::cout << "Система уравнений имеет обязательное сходимости.\n";
        ZeidelMethod(C, b3, x3, n3);
        // Печать результатов
        std::cout << "Решение:\n";
        for (int i = 0; i < n3; ++i) {
            std::cout << "x[" << i << "] = " << std::setprecision(10) << x3[i] << "\n\n\n";
        }
    }
    else {
        std::cout << "Система уравнений не является диагонально доминирующей.\n\n\n";
    }

    if (IsDiagonallyDominant(D, n4)) {
        std::cout << "Система уравнений имеет обязательное сходимости.\n";
        ZeidelMethod(D, b4, x4, n4);
        // Печать результатов
        std::cout << "Решение:\n";
        for (int i = 0; i < n4; ++i) {
            std::cout << "x[" << i << "] = " << std::setprecision(10) << x4[i] << "\n\n\n";
        }
    }
    else {
        std::cout << "Система уравнений не является диагонально доминирующей.\n\n\n";
    }

    if (IsDiagonallyDominant(E, n5)) {
        std::cout << "Система уравнений имеет обязательное сходимости.\n";
        ZeidelMethod(E, b5, x5, n5);
        // Печать результатов
        std::cout << "Решение:\n";
        for (int i = 0; i < n5; ++i) {
            std::cout << "x[" << i << "] = " << std::setprecision(10) << x5[i] << "\n\n\n";
        }
    }
    else {
        std::cout << "Система уравнений не является диагонально доминирующей.\n\n\n";
    }

    if (IsDiagonallyDominant(F, n6)) {
        std::cout << "Система уравнений имеет обязательное сходимости.\n";
        ZeidelMethod(F, b6, x6, n6);
        // Печать результатов
        std::cout << "Решение:\n";
        for (int i = 0; i < n6; ++i) {
            std::cout << "x[" << i << "] = " << std::setprecision(10) << x6[i] << "\n\n\n";
        }
    }
    else {
        std::cout << "Система уравнений не является диагонально доминирующей.\n\n\n";
    }

    if (IsDiagonallyDominant(G, n7)) {
        std::cout << "Система уравнений имеет обязательное сходимости.\n";
        ZeidelMethod(G, b7, x7, n7);
        // Печать результатов
        std::cout << "Решение:\n";
        for (int i = 0; i < n7; ++i) {
            std::cout << "x[" << i << "] = " << std::setprecision(10) << x7[i] << "\n\n\n";
        }
    }
    else {
        std::cout << "Система уравнений не является диагонально доминирующей.\n\n\n";
    }





    
    



    

    


    return 0;
}