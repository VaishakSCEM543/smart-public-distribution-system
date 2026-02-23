#include "HX711.h"
#include "scale.h"

#define DOUT 32
#define SCK  33

HX711 scale;
float calibration_factor = 2280.f;

void initScale() {
    scale.begin(DOUT, SCK);
    scale.set_scale(calibration_factor);
    scale.tare();
}

float readWeight() {
    return scale.get_units(10);
}
