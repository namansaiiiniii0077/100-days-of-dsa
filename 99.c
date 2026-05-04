#include <stdio.h>

struct Car {
    int position;
    int speed;
};

void swap(struct Car *a, struct Car *b) {
    struct Car temp = *a;
    *a = *b;
    *b = temp;
}

void sortCars(struct Car arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].position < arr[j + 1].position) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int target, n;
    scanf("%d %d", &target, &n);

    struct Car cars[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &cars[i].position);

    for (int i = 0; i < n; i++)
        scanf("%d", &cars[i].speed);

    sortCars(cars, n);

    int fleets = 0;
    double maxTime = 0.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        if (time > maxTime) {
            fleets++;
            maxTime = time;
        }
    }

    printf("%d", fleets);

    return 0;
}