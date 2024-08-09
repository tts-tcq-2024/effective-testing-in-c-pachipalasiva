#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok if temperature exceeds a threshold (e.g., 200 degrees Celsius)
    if (celcius > 200) {
        return 500;
    }
    return 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is an error
        // increment the failure count
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(400.5); // Should fail (400.5°F is above 200°C)
    alertInCelcius(303.6); // Should pass (303.6°F is below 200°C)
    assert(alertFailureCount == 0); // This should be 1 if the alertInCelcius function is correct
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
