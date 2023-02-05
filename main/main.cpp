#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

#include "pico/stdlib.h"
#include "config.h"
#include "Bus.h"
#include "R6502.h"

const uint LED_PIN = PICO_DEFAULT_LED_PIN;

std::string hex(uint32_t n, uint8_t d)
{
    std::string s(d, '0');
    for (int i = d - 1; i >= 0; i--, n >>= 4)
        s[i] = "0123456789ABCDEF"[n & 0xF];
    return s;
};


int main()
{ 
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    sleep_ms(5000);
    

    Bus nes;
    std::map<uint16_t, std::string> mapAsm;

    // Convert hex string into bytes for RAM
    std::stringstream ss;
    ss << "A2 0A 8E 00 00 A2 03 8E 01 00 AC 00 00 A9 00 18 6D 01 00 88 D0 FA 8D 02 00 EA EA EA";
    uint16_t nOffset = 0x8000;
    while (!ss.eof())
    {
        std::string b;
        ss >> b;
        nes.ram[nOffset++] = (uint8_t)std::stoul(b, nullptr, 16);
    }

    // Set Reset Vector
    nes.ram[RESB]   = 0x00;
    nes.ram[RESB+1] = 0x80;

    // Dont forget to set IRQ and NMI vectors if you want to play with those

    // Extract dissassembly
    mapAsm = nes.cpu.disassemble(0x0000, 0xFFFF);

    // Reset
    nes.cpu.reset();

    while (1) {
        printf("READY\n");
        printf("ram[RESB]   = 0x%0x\n", nes.ram[RESB]);
        printf("ram[RESB+1] = 0x%0x\n", nes.ram[RESB+1]);

        gpio_put(LED_PIN, 0);
        sleep_ms(250);
        gpio_put(LED_PIN, 1);
        sleep_ms(1000);
    }

    return 0;
}