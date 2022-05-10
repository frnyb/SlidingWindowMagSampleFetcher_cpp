#pragma once

#include "../include/BRAM-uio-driver/src/bram_uio.h"
#include "../include/PL-Mag-Sensor/ip/SlidingWindowMagSampleFetcher/drivers/SlidingWindowMagSampleFetcher_v1_0/src/xslidingwindowmagsamplefetcher.h"

#include "stdint.h"

#include <vector>
#include <iostream>
#include <chrono>

#include "mag_sample.h"

class SlidingWindowMagSampleFetcher {
public:
    SlidingWindowMagSampleFetcher(unsigned int bram_uio_number, unsigned int bram_size);
    ~SlidingWindowMagSampleFetcher();

    bool Start(unsigned int n_periods);
    bool Start();

    bool IsRunning();

    bool GetSamples(std::vector<MagSample> *samples);

private:
    BRAM bram;
    XSlidingwindowmagsamplefetcher xmsf;

};

