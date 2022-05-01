#include "mag_sample.h"

MagSample::MagSample(uint32_t data[12]) {
    for (int i = 0; i < 12; i++) {
        samples[i] = parseData(data[i]);
    }
}

MagSample::MagSample(BRAM *bram, unsigned int offset) {
    for (int i = 0; i < 12; i++) {
        samples[i] = parseData((*bram)[offset+i]);
    }
}

sample_t& MagSample::operator[](unsigned int index) {
    return samples[index];
}

sample_t MagSample::parseData(uint32_t data) {
    sample_t sample = {
        .data = data & 0x00000FFF,
        .time_offset = (data >> 12) & 0x000FFFFF
    };

    return sample;
}