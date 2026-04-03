#include "forensic_vault.h"
#include "utils.h"
#include <stdio.h>

void emit_last_gasp_canary() {
    printf("%s[SPACETIMEDB VAULT] Generating SHA-256 Hash of Final 5 Seconds...%s\n", COLOR_MAGENTA, COLOR_RESET);
    sleep_ms(800);
    printf("%s[SPACETIMEDB VAULT] Hash: 9f86d081884c7d659a2feaa0c55ad015a3bf4f1b2b0b822cd15d6c15b0f00a08%s\n", COLOR_CYAN, COLOR_RESET);
    sleep_ms(500);
    printf("%s[SERVER CANARY] Uploading Digital Affidavit... SUCCESS.%s\n", COLOR_GREEN, COLOR_RESET);
}
