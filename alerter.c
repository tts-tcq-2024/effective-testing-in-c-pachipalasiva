#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

// Stub function to simulate network alerts.
// Returns 500 to simulate a failure.
int networkAlertStub(float celsius) {
    printf("ALERT: Temperature is %.1f Celsius.\n", celsius);
    // Simulate failure by returning 500
    return 500;
}

void alertInCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celsius);
    if (returnCode != 200) {
        // Increment failure count if the alert fails
        alertFailureCount += 1;
    }
}

int main() {
    // Simulate alerts and count failures
    alertInCelsius(400.5);  // This should fail and increment the failure count
    alertInCelsius(303.6);  // This should also fail and increment the failure count

    // Check the number of failed alerts
    // We expect the failure count to be 2 because both calls to networkAlertStub return 500
    assert(alertFailureCount == 2);
    
    // Print the number of failed alerts
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
