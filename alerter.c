#include <stdio.h>
#include <assert.h>

// Global variable to count alert failures
int alertFailureCount = 0;

// Simulated network alert function
// 200 for success, 500 for failure
int networkAlertStub(float celcius) {
    // Simulate a failure based on a condition, e.g., high temperature
    if (celcius > 100.0) {
        return 500; // Simulate failure
    } else {
        return 200; // Simulate success
    }
}

// Function to convert Fahrenheit to Celsius and alert
void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // Increment failure count on non-200 response
        alertFailureCount += 1;
    }
}

int main() {
    // Test cases
    alertInCelcius(400.5);  // This should cause a failure (celcius > 100)
    alertInCelcius(303.6);  // This should cause a failure (celcius > 100)
    alertInCelcius(32.0);   // This should succeed (celcius = 0)
    alertInCelcius(100.0);  // This should succeed (celcius = 37.8, which is <= 100)

    // Expected to have 2 failures
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");

    // Assert to verify the expected behavior
    assert(alertFailureCount == 2);

    return 0;
}
