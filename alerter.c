#include <stdio.h>
#include <assert.h>

// Global variable to count alert failures
int alertFailureCount = 0;

// Simulated network alert function
// Return 200 for success, 500 for failure
int networkAlertStub(float celcius) {
    printf("Debug: Checking Celsius value %.2f\n", celcius);
    // Simulate a failure for temperatures above 100 degrees Celsius
    if (celcius > 100.0) {
        return 500; // Simulate failure
    } else {
        return 200; // Simulate success
    }
}

// Function to convert Fahrenheit to Celsius and send alert
void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    printf("Debug: Fahrenheit %.2f converted to Celsius %.2f\n", farenheit, celcius);
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // Increment failure count on non-200 response
        alertFailureCount += 1;
    }
}

int main() {
    // Test cases
    alertInCelcius(400.5);  // Convert to Celsius: 204.7 (Should cause failure)
    alertInCelcius(303.6);  // Convert to Celsius: 151.0 (Should cause failure)
    alertInCelcius(32.0);   // Convert to Celsius: 0.0 (Should succeed)
    alertInCelcius(100.0);  // Convert to Celsius: 37.8 (Should succeed)

    // Print the number of failures
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");

    // Assert to verify the expected behavior
    assert(alertFailureCount == 2);

    return 0;
}
