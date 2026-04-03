#include "bluetooth_sweeper.h"
#include "utils.h"
#include <stdio.h>

void perform_digital_dna_sweep() {
    printf("%s[BLE MESH] Initiating Digital DNA Sweep near Lat: 28.5670, Long: 77.2100...%s\n", COLOR_YELLOW, COLOR_RESET);
    sleep_ms(1000);
    printf("%s[BLE MESH] Detected Device: Apple Watch (Attacker?) - MAC: 00:1A:7D:DA:71:13%s\n", COLOR_RED, COLOR_RESET);
    printf("%s[BLE MESH] Detected Device: AirPods - MAC: 00:1B:44:11:3A:B7%s\n", COLOR_RED, COLOR_RESET);
}
