#include "HX711.h"
#include "scale.h"

// GPIO pins for HX711 data and clock
#define DOUT 32
#define SCK  33

// Number of samples averaged per reading for noise reduction
#define WEIGHT_SAMPLES     10

// Minimum detectable weight (grams) — readings below this are treated as zero
#define WEIGHT_ZERO_THRESHOLD  2.0f

// Acceptable tolerance (grams) for dispensing accuracy
#define WEIGHT_TOLERANCE   5.0f

HX711 scale;
float calibration_factor = 2280.f;

void initScale() {
    scale.begin(DOUT, SCK);
    scale.set_scale(calibration_factor);
    scale.tare();   // Zero out any pre-load on the platform
    Serial.println("[Scale] HX711 initialized and tared.");
}

float readWeight() {
    float raw = scale.get_units(WEIGHT_SAMPLES);
    // Clamp very small negative or near-zero readings to 0
    if (raw < WEIGHT_ZERO_THRESHOLD) {
        raw = 0.0f;
    }
    return raw;
}

bool isWithinTolerance(float dispensed, float target) {
    float deviation = dispensed - target;
    if (deviation < 0) deviation = -deviation;  // abs without <cmath>
    return deviation <= WEIGHT_TOLERANCE;
}

void retare() {
    scale.tare();
    Serial.println("[Scale] Re-tared successfully.");
}
