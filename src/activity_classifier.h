#ifndef ACTIVITY_CLASSIFIER_H
#define ACTIVITY_CLASSIFIER_H

#include "sensor_fusion.h"

// Analyzes recent acceleration history to differentiate Rhythm vs Chaos
// Returns 1 if Chaos detected, 0 if Rhythmic/Normal
int classify_aperiodic_chaos(SensorState *state);

#endif
