#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long hexadecimalToDecimal(const char *hex) {
    return strtol(hex, NULL, 16); 
}

void decimalToBinary(long decimal, char *binary) {
    int index = 0;
    if (decimal == 0) {
        binary[index++] = '0';
    } else {
        for (int i = 63; i >= 0; i--) {
            binary[index++] = (decimal & (1L << i)) ? '1' : '0';
        }
        int start = 0;
        while (binary[start] == '0' && start < index - 1) {
            start++;
        }
        memmove(binary, binary + start, index - start);
        binary[index - start] = '\0';
    }
}

int main() {
    char hex[17];    
    char binary[65]; 

    printf("Enter an hexadecimal number : ");
    scanf("%16s", hex);

    long decimal = hexadecimalToDecimal(hex); 
    decimalToBinary(decimal, binary);         

    printf("Binary : %s\n", binary);

    return 0;
}