
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

void oct_to_bin(const char *oct) {
    int i=0;
    if (oct[0]=='+' || oct[0]=='-') oct++;
    int len = strlen(oct);
    for (i=0;i<len;i++) {
        char c = oct[i];
        if (c < '0' || c > '7') continue;
        switch (c) {
            case '0': printf("000"); break;
            case '1': printf("001"); break;
            case '2': printf("010"); break;
            case '3': printf("011"); break;
            case '4': printf("100"); break;
            case '5': printf("101"); break;
            case '6': printf("110"); break;
            case '7': printf("111"); break;
        }
    }
    printf("\n");
}

void oct_to_hex(const char *oct) {
    char *end;
    long long val = strtoll(oct, &end, 8);
    if (end==oct) {
        printf("\n");
        return;
    }
    if (val==0) { printf("0\n"); return; }
    char buf[64];
    sprintf(buf, "%llX", val);
    printf("%s\n", buf);
}

void hex_to_bin(const char *hex) {
    const char *p = hex;
    if (p[0]=='+'||p[0]=='-') p++;
    while (*p) {
        char c = *p++;
        if (isspace((unsigned char)c)) continue;
        if (!isxdigit((unsigned char)c)) continue;
        switch (toupper(c)) {
            case '0': printf("0000"); break;
            case '1': printf("0001"); break;
            case '2': printf("0010"); break;
            case '3': printf("0011"); break;
            case '4': printf("0100"); break;
            case '5': printf("0101"); break;
            case '6': printf("0110"); break;
            case '7': printf("0111"); break;
            case '8': printf("1000"); break;
            case '9': printf("1001"); break;
            case 'A': printf("1010"); break;
            case 'B': printf("1011"); break;
            case 'C': printf("1100"); break;
            case 'D': printf("1101"); break;
            case 'E': printf("1110"); break;
            case 'F': printf("1111"); break;
        }
    }
    printf("\n");
}

void to_sign_magnitude(long long n) {
    uint32_t out = 0;
    uint32_t sign = 0;
    uint32_t mag = 0;
    if (n < 0) { sign = 1; mag = (uint32_t)(-n); }
    else { sign = 0; mag = (uint32_t)n; }
    for (int i=31;i>=0;i--) {
        if (i==31) { printf("%u", sign); continue; }
        int bit = (mag >> (i)) & 1u;
        printf("%d", bit);
    }
    printf("\n");
}

void to_ones_complement(long long n) {
    uint32_t val = (uint32_t)n;
    if (n >= 0) {
        for (int i=31;i>=0;i--) {
            printf("%d", (val>>i)&1u);
        }
        printf("\n");
    } else {
        uint32_t pos = (uint32_t)(-n);
        uint32_t inv = (~pos) & 0xFFFFFFFFu;
        for (int i=31;i>=0;i--) {
            printf("%d", (inv>>i)&1u);
        }
        printf("\n");
    }
}

void to_twos_complement(long long n) {
    uint32_t val = (uint32_t)n;
    for (int i=31;i>=0;i--) {
        printf("%d", (val>>i)&1u);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc < 2) return 1;
    const char *fn = argv[1];
    if (strcmp(fn,"oct_to_bin")==0) {
        if (argc<3) return 1;
        oct_to_bin(argv[2]);
    } else if (strcmp(fn,"oct_to_hex")==0) {
        if (argc<3) return 1;
        oct_to_hex(argv[2]);
    } else if (strcmp(fn,"hex_to_bin")==0) {
        if (argc<3) return 1;
        hex_to_bin(argv[2]);
    } else if (strcmp(fn,"to_sign_magnitude")==0) {
        if (argc<3) return 1;
        long long n = atoll(argv[2]);
        to_sign_magnitude(n);
    } else if (strcmp(fn,"to_ones_complement")==0) {
        if (argc<3) return 1;
        long long n = atoll(argv[2]);
        to_ones_complement(n);
    } else if (strcmp(fn,"to_twos_complement")==0) {
        if (argc<3) return 1;
        long long n = atoll(argv[2]);
        to_twos_complement(n);
    } else {
        return 1;
    }
    return 0;
}
