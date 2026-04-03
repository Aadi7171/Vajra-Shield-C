#include "activity_classifier.h"
#include <math.h>

int classify_aperiodic_chaos(SensorState *state) {
    // A simplified mock of 1D-CNN + FFT Rhythm Filtering
    double magnitude = sqrt(state->x_accel * state->x_accel + 
                            state->y_accel * state->y_accel + 
                            state->z_accel * state->z_accel);
    
    // In our mock scenario:
    // Jogging has rhythmic spikes (e.g. mag around 11-15)
    // A struggle has huge, aperiodic spikes (mag > 25)
    if (magnitude > 25.0) {
        return 1; // Chaos!
    }
    return 0; // Rhythm or Idle
}
