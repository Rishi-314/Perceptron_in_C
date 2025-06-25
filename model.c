#include <stdio.h>
#include <math.h>

#define LEARNING_RATE 0.1
#define EPOCHS 10000

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}
// We just have to change the data set according to the logic gate
// In this case it is ADD 
double inputs[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
double outputs[4] = {0, 0, 0, 1}; 

double w1 = 0.5, w2 = -0.5, bias = 0.0;

void train() {
    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        for (int i = 0; i < 4; i++) {
            double x1 = inputs[i][0], x2 = inputs[i][1], target = outputs[i];
            double prediction = sigmoid(w1 * x1 + w2 * x2 + bias);
            double error = target - prediction;

            w1 += LEARNING_RATE * error * x1;
            w2 += LEARNING_RATE * error * x2;
            bias += LEARNING_RATE * error;
        }
    }
}

double predict(double x1, double x2) {
    return sigmoid(w1 * x1 + w2 * x2 + bias);
}

int main() {
    train();
    double x1, x2;
    printf("Enter two binary values (0 or 1): ");
    scanf("%lf %lf", &x1, &x2);
    printf("AND(%d, %d) = %.2f\n", (int)x1, (int)x2, predict(x1, x2));
    return 0;
}
