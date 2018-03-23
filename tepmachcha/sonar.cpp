// Maxbotix Sonar

#define SAMPLES 11

#include "tepmachcha.h"

// insertion sort: https://en.wikipedia.org/wiki/Insertion_sort
void sort (int16_t *a, uint8_t n)
{
  for (uint8_t i = 1; i < n; i++)
  {
    // 'float' the current element up towards the beginning of array
    for (uint8_t j = i; j >= 1 && a[j] < a[j-1]; j--)
    {
      // swap (j, j-1)
      int16_t tmp = a[j];
      a[j] = a[j-1];
      a[j-1] = tmp;
    }
  }
}


// Calculate mode, or median of sorted samples
int16_t mode (int16_t *sample, uint8_t n)
{
    int16_t mode;
    uint8_t count = 1;
    uint8_t max_count = 1;

    for (int i = 1; i < n; i++)
    {
      if (sample[i] == sample[i - 1])
        count++;
      else
        count = 1;

      if (count > max_count)  // current sequence is the longest
      {
        max_count = count;
        mode = sample[i];
      }
      else if (count == max_count)  // no sequence (count == 1), or bimodal
      {
        mode = sample[(n/2)];       // use median
      }
    }
    return mode;
}


// Read Maxbotix MB7363 samples in free-run/filtered mode.
// Don't call this more than 6Hz due to min. 160ms sonar cycle time
void sonarSamples(int16_t *sample)
{
    digitalWrite (RANGE, HIGH);  // sonar on
    wait (1000);

    // wait for and discard first sample (160ms)
    pulseIn (PING, HIGH);

    // read subsequent (filtered) samples into array
    for (uint8_t sampleCount = 0; sampleCount < SAMPLES; sampleCount++)
    {
      // After the PWM pulse, the sonar transmits the reading
      // on the serial pin, which takes ~10ms
      wait (10);

      // 1 µs pulse = 1mm distance
      sample[sampleCount] = pulseIn (PING, HIGH);

      // ~16 chars at 57600baud ~= 3ms delay
      Serial.print (F("Sample "));
      Serial.print (sampleCount);
      Serial.print (F(": "));
      Serial.println (sample[sampleCount]);
    }

    digitalWrite (RANGE, LOW);   // sonar off
}


// One failure mode of the sonar -- if, for example, it is not getting enough power
// is to return the minimum distance the sonar can detect; 50cm for 10m sonars
// or 30cm for 5m.
// This is also waht happens if something blocks the unit.

int16_t sonarRead (void)
{
    int16_t sample[SAMPLES];

    // read from sensor into sample array
		sonarSamples (sample);

    // sort the samples
		sort (sample, SAMPLES);

    // take the mode, or median
    int16_t sampleMode = mode (sample, SAMPLES);

    // convert to cm and offset by hardcoded stream-bed height
    int16_t streamHeight = (SENSOR_HEIGHT - (sampleMode / 10));

    Serial.print (F("Surface distance from sensor is "));
    Serial.print (sampleMode);
    Serial.println (F("mm."));
    Serial.print (F("Calculated surface height is "));
    Serial.print (streamHeight);
    Serial.println (F("cm."));

    return streamHeight;
}
