#ifndef SENSOR_FUSION_H
#define SENSOR_FUSION_H

typedef struct {
    double x_accel;
    double y_accel;
    double z_accel;
    double gps_speed; // in m/s
    int heart_rate;   // in BPM
} SensorState;

// Updates the sensor state based on the scenario type
// 0 = Idle/Normal, 1 = Jogging, 2 = "Aperiodic Chaos / The Struggle"
void mock_sensor_readings(SensorState *state, int scenario);

// Implementation of "The Adrenaline-Stillness Paradox"
// Returns 1 if paradox detected, 0 otherwise
int detect_adrenaline_stillness(SensorState *state);

#endif
