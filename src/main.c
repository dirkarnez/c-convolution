#include <stdio.h>
#include <stdlib.h>

// Function to perform 1D convolution
void convolve1D(float* input, int input_size, float* kernel, int kernel_size, float* output, int output_size) {
    // for (int i = 0; i < output_size; i++) {
    //     output[i] = 0;
    //     for (int j = 0; j < kernel_size; j++) {
    //         output[i] += input[i + j] * kernel[j];
    //     }
    // }
    for (int i = 0; i < input_size; i++) {
        for (int j = 0; j < kernel_size; j++) {
            output[i + j] += input[i] * kernel[j];
        }
    }
}

int main() {
    // Example input and kernel
    float input[] = {1.0, 2.0, 3.0};
    float kernel[] = {4.0, 5.0, 6.0};

    int input_size = sizeof(input) / sizeof(float);
    int kernel_size = sizeof(kernel) / sizeof(float);
    int output_size = input_size + kernel_size - 1;
    float* data = (float*)malloc(output_size * sizeof(float));
    
    // Perform 1D convolution
    convolve1D(input, input_size, kernel, kernel_size, data, output_size);
    
    // Print the output
    for (int i = 0; i < output_size; i++) {
        printf("Output[%d] = %.2f\n", i, data[i]);
    }

    free(data);
    
    return 0;
}