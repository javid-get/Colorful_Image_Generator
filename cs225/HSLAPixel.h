/**
 * @file HSLAPixel.h
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#pragma once

#include <iostream>
#include <sstream>

namespace cs225 {
    class HSLAPixel {
        public:
        double h; // Hue of the pixel, in degrees [0, 360).
        double s; // Saturation of the pixel, [0, 1].
        double l; // Luminance of the pixel, [0, 1].
        double a; // Alpha of the pixel, [0, 1].

        /**
         * Constructs a default HSLAPixel.
         * A default pixel is completely opaque (non-transparent) and white.
         * Opaque implies that the alpha component of the pixel is 1.0.
         * Lower alpha values are (semi-)transparent.
         */
        HSLAPixel();

        /**
         * Constructs an opaque HSLAPixel with the given hue, saturation, and luminance values.
         */
        HSLAPixel(double hue, double saturation, double luminance);

        /**
         * Constructs an HSLAPixel with the given hue, saturation, luminance, and alpha values.
         */
        HSLAPixel(double hue, double saturation, double luminance, double alpha);
    };
}
