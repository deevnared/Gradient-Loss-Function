#include <stdio.h>

float gradW1(float x1, float x2, float y, float w1, float w2) {
    float Y = w1 * x1 + w2 * x2;
    float error = Y - y;
    float gdW1 = -2 * error * x1;
    return gdW1;
}

float gradW2(float x1, float x2, float y, float w1, float w2) {
    float pY = w1 * x1 + w2 * x2;
    float error = pY - y;
    float gdW2 = -2 * error * x2;
    return gdW2;
}

int main() {
    float alpha, x1, x2, y, w1, w2;
    int num_instances;

    printf("Enter the number of instances: ");
    scanf("%d", &num_instances);
    w1 = 0.3 ;
    w2 = 0.6 ;
    
    for (int i = 0; i < num_instances; i++) {
        printf("Instance %d:\n", i+1);
        printf("Enter the learning rate (alpha): ");
        scanf("%f", &alpha);
        printf("Enter the value of x1: ");
        scanf("%f", &x1);
        printf("Enter the value of x2: ");
        scanf("%f", &x2);
        printf("Enter the value of y: ");
        scanf("%f", &y);
        

        w1 = w1 - alpha * gradW1(x1, x2, y, w1, w2);
        w2 = w2 - alpha * gradW2(x1, x2, y, w1, w2);

        printf("New w1 for set %d: %f\n", i+1, w1);
        printf("New w2 for set %d: %f\n", i+1, w2);
    }

    return 0;
}
