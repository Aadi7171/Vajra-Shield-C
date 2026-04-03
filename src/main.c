#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utils.h"
#include "sensor_fusion.h"
#include "activity_classifier.h"
#include "forensic_vault.h"
#include "bluetooth_sweeper.h"

int main() {
    srand(time(NULL));
    SensorState state;
    int running = 1;
    char input[10];

    clear_screen();
    print_banner();
    printf("\nBooting Vajra-Shield Edge OS...\n");
    sleep_ms(1000);

    while (running) {
        printf("\n%s--- SIMULATOR MENU ---%s\n", COLOR_CYAN, COLOR_RESET);
        printf("1. Simulate User Idle / Walking (Normal)\n");
        printf("2. Simulate Jogging (High Accel, Rhythm)\n");
        printf("3. Simulate 'The Struggle' (Aperiodic Chaos + HR Spike)\n");
        printf("4. Simulate 'The Smash' (Phone Destroyed)\n");
        printf("5. Exit\n");
        printf("Select Scenario: ");
        
        if (scanf("%s", input) != 1) break;

        if (strcmp(input, "1") == 0) {
            mock_sensor_readings(&state, 0);
            printf("%s[INFO] Normal Activity. Magnitude low. HR: %d BPM%s\n", COLOR_GREEN, state.heart_rate, COLOR_RESET);
        } 
        else if (strcmp(input, "2") == 0) {
            mock_sensor_readings(&state, 1);
            int is_chaos = classify_aperiodic_chaos(&state);
            printf("%s[FFT FILTER] Rhythmic movement detected (Jogging). HR: %d BPM. Ignoring.%s\n", COLOR_YELLOW, state.heart_rate, COLOR_RESET);
        }
        else if (strcmp(input, "3") == 0) {
            mock_sensor_readings(&state, 2);
            int is_chaos = classify_aperiodic_chaos(&state);
            int is_paradox = detect_adrenaline_stillness(&state);
            
            if (is_chaos || is_paradox) {
                printf("\n%s[CRITICAL ALERT] 'Aperiodic Chaos' OR 'Adrenaline-Stillness Paradox' Detected!%s\n", COLOR_RED, COLOR_RESET);
                printf("%s[CRITICAL ALERT] Acceleration Magnitude > 25. HR: %d BPM.%s\n", COLOR_RED, state.heart_rate, COLOR_RESET);
                sleep_ms(1000);
                
                // Human-in-the-loop countdown
                printf("\n%s>>> SOS DEPLOYING IN 15 SECONDS <<<%s\n", COLOR_BOLD, COLOR_RESET);
                printf("Enter Safe PIN to abort (or Duress PIN to comply but escalate):\n");
                printf("PIN (1234=Safe, 4321=Duress, or wait): ");
                
                // Read PIN (blocking call for demo simplicity)
                char pin[10];
                scanf("%s", pin);
                
                if (strcmp(pin, "1234") == 0) {
                    printf("%s[ABORT] Safe PIN entered. SOS cancelled. Returning to idle.%s\n", COLOR_GREEN, COLOR_RESET);
                } 
                else if (strcmp(pin, "4321") == 0) {
                    // Deep Stealth Mode
                    clear_screen();
                    printf("Lock Screen -> Unlocked.\n");
                    sleep_ms(500);
                    printf("Returning to Home Screen...\n");
                    sleep_ms(1000); // Simulate letting the attacker think they won
                    
                    printf("\n%s[DURESS ACTIVATED] Deep Stealth Mode Engaged.%s\n", COLOR_MAGENTA, COLOR_RESET);
                    perform_digital_dna_sweep();
                    emit_last_gasp_canary();
                    printf("%s[POLICE DISPATCHED SILENTLY]%s\n", COLOR_RED, COLOR_RESET);
                } 
                else {
                    printf("%s[TIMEOUT/INVALID] SOS Firing!%s\n", COLOR_RED, COLOR_RESET);
                    perform_digital_dna_sweep();
                    emit_last_gasp_canary();
                }
            }
        }
        else if (strcmp(input, "4") == 0) {
            printf("\n%s[HARDWARE FAILURE] Phone smashed!%s\n", COLOR_RED, COLOR_RESET);
            emit_last_gasp_canary();
        }
        else if (strcmp(input, "5") == 0) {
            running = 0;
            printf("Shutting down.\n");
        } 
        else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}
