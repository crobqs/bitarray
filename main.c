/* bit-array */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BIT_ARRAY_SIZE 256
#define BIT_ARRAY_BYTES (BIT_ARRAY_SIZE / 8)

uint8_t bitArray[BIT_ARRAY_BYTES] = {0};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"

static void setBit(uint8_t* a, int i) {
    a[i / 8] |= (1 << (i % 8));
}

static void clearBit(uint8_t* a, int i) {
    a[i / 8] &= ~(1 << (i % 8));
}

static bool isBitSet(const uint8_t* a, int i) {
    return (a[i / 8] & (1 << (i % 8))) != 0;
}

static void toggleBit(uint8_t* a, int i) {
    a[i / 8] ^= (1 << (i % 8));
}

static void unionBitArrays(const uint8_t* a, const uint8_t* b, uint8_t* res) {
    for (int i = 0; i < BIT_ARRAY_BYTES; ++i) {
        res[i] = a[i] | b[i];
    }
}

static void intersectBitArrays(const uint8_t* a, const uint8_t* b, uint8_t* res) {
    for (int i = 0; i < BIT_ARRAY_BYTES; ++i) {
        res[i] = a[i] & b[i];
    }
}

// equivalent to intersectBitArrays
static void bitwiseAnd(const uint8_t* a, const uint8_t* b, uint8_t* res) {
    for (int i = 0; i < BIT_ARRAY_BYTES; ++i) {
        res[i] = a[i] & b[i];
    }
}

// equivalent to unionBitArrays
static void bitwiseOr(const uint8_t* a, const uint8_t* b, uint8_t* res) {
    for (int i = 0; i < BIT_ARRAY_BYTES; ++i) {
        res[i] = a[i] | b[i];
    }
}

static void bitwiseXor(const uint8_t* a, const uint8_t* b, uint8_t* res) {
    for (int i = 0; i < BIT_ARRAY_BYTES; ++i) {
        res[i] = a[i] ^ b[i];
    }
}

static void bitwiseNot(const uint8_t* a, uint8_t* res) {
    for (int i = 0; i < BIT_ARRAY_BYTES; ++i) {
        res[i] = ~a[i];
    }
}

static void printBitArray(const uint8_t* a) {
    for (int i = 0; i < BIT_ARRAY_SIZE; ++i) {
        printf("%d", (a[i / 8] >> (i % 8)) & 1);
        if (i % 8 == 7) {
            printf(" ");
        }
    }
    printf("\n");
}

#pragma GCC diagnostic pop

int main(void) {
    setBit(bitArray, 0);
    setBit(bitArray, 7);
    printBitArray(bitArray);
}