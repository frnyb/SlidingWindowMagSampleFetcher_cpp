#include "sliding_window_mag_sample_fetcher.h"

SlidingWindowMagSampleFetcher::SlidingWindowMagSampleFetcher(unsigned int bram_uio_number, unsigned int bram_size) 
        : bram(bram_uio_number, bram_size) {

    XSlidingwindowmagsamplefetcher_Initialize(&xmsf, "SlidingWindowMagSampleFetcher");

}

SlidingWindowMagSampleFetcher::~SlidingWindowMagSampleFetcher() {

    XSlidingwindowmagsamplefetcher_Release(&xmsf);

}

bool SlidingWindowMagSampleFetcher::Start(unsigned int n_periods) {

    if(IsRunning()) {

        return false;

    }

    XSlidingwindowmagsamplefetcher_Set_n_periods(&xmsf, n_periods);

    return Start();

}

bool SlidingWindowMagSampleFetcher::Start() {

    if(IsRunning()) {

        return true;

    }

    bram[0] = (uint32_t)true;

    return true;

}

 bool SlidingWindowMagSampleFetcher::GetSamples(std::vector<MagSample> *samples) {

    if(IsRunning()) {

        return false;

    }

	uint32_t n_samples = XSlidingwindowmagsamplefetcher_Get_n_samples_out(&xmsf);

    uint32_t n_samples_per_ch = n_samples / 12;

    for (int i = 0; i < n_samples_per_ch; i++) {

        MagSample mag_sample(&bram, 1+i*12);
        samples->push_back(mag_sample);

    }

    return true;
}

bool SlidingWindowMagSampleFetcher::IsRunning() {

    return (bool)bram[0];

}