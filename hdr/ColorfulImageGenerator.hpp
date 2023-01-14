#ifndef COLORFUL_IMAGE_GENERATOR_HPP
#define COLORFUL_IMAGE_GENERATOR_HPP

#include "../cs225/PNG.h"
#include "../cs225/HSLAPixel.h"
#include "CanvasUtility.hpp"

namespace ColorfulImageGenerator {
  constexpr double SQUARE_WIDTH = 15;
  constexpr double EDGE_LENGTH = 7;
  constexpr double LINE_LENGTH = 1;

  constexpr double NODE_LUMINANCE_MARKER = 0.0;
  const cs225::HSLAPixel NODE_MARKER(0.0, 1.0, NODE_LUMINANCE_MARKER);
  constexpr double EDGE_LUMINANCE_MARKER = 0.1;
  const cs225::HSLAPixel EDGE_MARKER(0.0, 1.0, EDGE_LUMINANCE_MARKER);

  cs225::PNG generate(unsigned width, unsigned height);
  cs225::PNG generate(unsigned width, unsigned height, unsigned seed);

  void drawGraph(cs225::PNG &image);
  void recursivelyDrawGraph(cs225::PNG &image, bool branching, CanvasUtility::Position const position);
  CanvasUtility::Position drawEdge(cs225::PNG &png, unsigned int edgeLength, CanvasUtility::CardinalDirection d, unsigned int x, unsigned int y);
  void drawBranch(cs225::PNG &image, CanvasUtility::CardinalDirection direction, unsigned int x, unsigned int y);

  bool isNodePixel(cs225::HSLAPixel);
  bool isEdgePixel(cs225::HSLAPixel);

};

#endif