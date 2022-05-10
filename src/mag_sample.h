#include "stdint.h"
#include "time.h"

#include "../include/BRAM-uio-driver/src/bram_uio.h"

typedef struct {
    uint16_t data;
    time_t time_offset;
} sample_t;

class MagSample {
public:
    MagSample(uint32_t data[12]);
    MagSample(BRAM *bram, unsigned int offset);

    sample_t& operator[](unsigned int);

private:
    sample_t samples[12];

    sample_t parseData(uint32_t data);

};
