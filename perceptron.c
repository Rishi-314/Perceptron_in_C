#include <stdio.h>
#include <math.h>

#define LEARNING_RATE 0.1
#define EPOCHS 10000

double sigmoid(double x) {
    return 1 / (1 + exp(-x));
}

double inputs[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

double outputs_nand[4] = {1, 1, 1, 0};
double outputs_or[4] = {0, 1, 1, 1};
double outputs_nor[4] = {1, 0, 0, 0};
double outputs_and[4] = {0, 0, 0, 1};

double w1 = -0.5, w2 = -0.5, bias = 0.5;

void train_perceptron(double outputs[]) {
    for (int epoch = 0; epoch < EPOCHS; epoch++) {
        for (int i = 0; i < 4; i++) {
            double x1 = inputs[i][0], x2 = inputs[i][1], target = outputs[i];

            double sum = w1 * x1 + w2 * x2 + bias;
            double prediction = sigmoid(sum);

            double error = target - prediction;

            w1 += LEARNING_RATE * error * x1;
            w2 += LEARNING_RATE * error * x2;
            bias += LEARNING_RATE * error;
        }
    }
}

void train_nand() { train_perceptron(outputs_nand); printf("NAND perceptron training completed.\n"); }
void train_or()   { train_perceptron(outputs_or);   printf("OR perceptron training completed.\n"); }
void train_nor()  { train_perceptron(outputs_nor);  printf("NOR perceptron training completed.\n"); }
void train_and()  { train_perceptron(outputs_and);  printf("AND perceptron training completed.\n"); }

double predict(double x1, double x2) {
    return sigmoid(w1 * x1 + w2 * x2 + bias);
}

int main() {
    int choice;
    double x1, x2;

    printf("********** Perceptron Logic Gate Classifier **********\n");
    printf("Choose a logic gate to train and test:\n");
    printf("1. NAND\n2. OR\n3. NOR\n4. AND\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: train_nand(); break;
        case 2: train_or();   break;
        case 3: train_nor();  break;
        case 4: train_and();  break;
        default: printf("Invalid selection.\n"); return 0;
    }

    printf("\nEnter two binary inputs (0 or 1): ");
    scanf("%lf %lf", &x1, &x2);

    double result = predict(x1, x2);
    printf("\nPredicted Output: %.2f\n", result);

    return 0;
}
