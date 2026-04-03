#include "sensor_fusion.h"
#include "utils.h"
#include <math.h>

void mock_sensor_readings(SensorState *state, int scenario) {
    if (scenario == 0) { // Idle / Walking
        state->x_accel = random_double(-1.0, 1.0);
        state->y_accel = random_double(-1.0, 1.0);
        state->z_accel = 9.8 + random_double(-0.5, 0.5); // Gravity
        state->gps_speed = random_double(0.0, 1.5); // walking speed
        state->heart_rate = (int)random_double(60.0, 80.0);
    } 
    else if (scenario == 1) { // Jogging (Rhythmic, moving)
        state->x_accel = random_double(-3.0, 3.0);
        state->y_accel = random_double(-3.0, 3.0);
        state->z_accel = 9.8 + random_double(-5.0, 5.0);
        state->gps_speed = random_double(2.5, 4.0); // running speed
        state->heart_rate = (int)random_double(120.0, 140.0);
    }
    else if (scenario == 2) { // The Struggle / Abduction
        state->x_accel = random_double(-20.0, 20.0);
        state->y_accel = random_double(-20.0, 20.0);
        state->z_accel = random_double(-20.0, 20.0);
        state->gps_speed = random_double(0.0, 0.2); // GPS shows sitting still (e.g. pinned or trunk)
        state->heart_rate = (int)random_double(150.0, 180.0); // Adrenaline spike
    }
}

int detect_adrenaline_stillness(SensorState *state) {
    // If heart rate > 140 BPM but GPS speed is < 0.5 m/s, it's the Paradox.
    if (state->heart_rate > 140 && state->gps_speed < 0.5) {
        return 1;
    }
    return 0;
}
