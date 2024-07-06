#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <windows.h>

// Функція для обчислення мінімальної кількості кроків
int minSteps(int x, int y) {
    int distance = y - x; 
    int steps = 0; 
    int stepSize = 1; 
    int coveredDistance = 0; 

    while (coveredDistance < distance) {
        steps++;
        coveredDistance += stepSize;
        if (coveredDistance < distance) {
            steps++;
            coveredDistance += stepSize;
        }
        stepSize++;
    }

    if (coveredDistance - distance > stepSize - 1) {
        steps--;
    }

    return steps;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int x, y;

    // Введення значень x та y
    printf("Введіть значення x: ");
    scanf("%d", &x);
    printf("Введіть значення y: ");
    scanf("%d", &y);

    // Перевірка на правильність введених даних
    if (x < 0 || y < 0 || x > y || y >= INT_MAX) {
        printf("Неправильні вхідні дані. Переконайтеся, що 0 <= x <= y < 2^31.\n");
        return 1;
    }

    // Виведення мінімальної кількості кроків
    printf("Мінімальна кількість кроків від %d до %d: %d\n", x, y, minSteps(x, y));

    return 0;
}
