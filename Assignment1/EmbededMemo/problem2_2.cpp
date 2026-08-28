#include <iostream>
#include <cmath>
using namespace std;

double computeRMS(double* signal, int n) {
    double sum = 0.0;
    double* end = signal + n;

    while (signal < end) {
        sum += (*signal) * (*signal);
        signal++;
    }

    return std::sqrt(sum / n);
}

void normalise(double* signal, int n) {
    if (n <= 0) return;

    double* ptr = signal;
    double* end = signal + n;

    double maxAbs = std::abs(*ptr);
    ptr++;

    while (ptr < end) {
        double currentAbs = std::abs(*ptr);

        if (currentAbs > maxAbs) {
            maxAbs = currentAbs;
        }

        ptr++;
    }

    if (maxAbs == 0.0) return;

    ptr = signal;

    while (ptr < end) {
        *ptr /= maxAbs;
        ptr++;
    }
}

int countZeroCrossings(double* signal, int n) {
    if (n < 2) return 0;

    int count = 0;
    double* ptr = signal;
    double* end = signal + (n - 1);

    while (ptr < end) {
        double current = *ptr;
        double next = *(ptr + 1);

        if ((current > 0 && next < 0) ||
            (current < 0 && next > 0)) {
            count++;
        }

        ptr++;
    }

    return count;
}

void applyGain(double* signal, int n, double gainFactor) {
    double* end = signal + n;

    while (signal < end) {
        *signal *= gainFactor;
        signal++;
    }
}

void printSignal(const double* signal, int n) {
    const double* end = signal + n;

    cout << "{ ";

    while (signal < end) {
        cout << *signal;

        if (signal + 1 < end)
            cout << ", ";

        signal++;
    }

    cout << " }\n";
}

int main() {

    double testSignal[] = {
        0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1
    };

    int n = sizeof(testSignal) / sizeof(testSignal[0]);
    double gainFactor = 1.5;

    cout << "--- Initial Audio Data ---\n";

    cout << "Original Signal: ";
    printSignal(testSignal, n);

    double rmsVal = computeRMS(testSignal, n);

    cout << "\nRMS Value: " << rmsVal << "\n";

    int zeroCrossings = countZeroCrossings(testSignal, n);

    cout << "Zero Crossings Count: "
              << zeroCrossings << "\n";

    cout << "\n--- Applying Normalisation Pipeline ---\n";

    normalise(testSignal, n);

    cout << "Signal After Normalisation: ";
    printSignal(testSignal, n);

    cout << "\n--- Applying Gain Modifier ("
              << gainFactor << "x) ---\n";

    applyGain(testSignal, n, gainFactor);

    cout << "Final Signal After Gain: ";
    printSignal(testSignal, n);

    return 0;
}