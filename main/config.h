#define PROJECT_VERSION_MAJOR @PROJECT_VERSION_MAJOR@
#define PROJECT_VERSION_MINOR @PROJECT_VERSION_MINOR@
#define PROJECT_VERSION_PATCH @PROJECT_VERSION_PATCH@
#define PROJECT_VERSION_TWEAK @PROJECT_VERSION_TWEAK@

// CONFIGURATION DEFINITIONS
#define LOG_MODE

// VECTOR LOCATIONS (https://eater.net/datasheets/w65c02s.pdf)[Table 3-1 Vector Locations]
#define IRQB    0xFFFE  // Interupt Vector
#define RESB    0xFFFC  // Reset Vector
#define NMIB    0xFFFA  // Non-Maskable Interrupt

// CPU DEFINITIONS
#define MIN_RAM_ADDR    0x0000
#define MAX_RAM_ADDR    0xFFFF

