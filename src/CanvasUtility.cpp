#include "CanvasUtility.hpp"

CanvasUtility::Position::Position(CardinalDirection setDirection, unsigned int setX, unsigned int setY):
  direction(setDirection), x(setX), y(setY)
{ }

bool CanvasUtility::inBounds(cs225::PNG const &canvas, const unsigned int x, const unsigned int y) {
  return (0 <= x && x < canvas.width()) && (0 <= y && y < canvas.height());
}

void CanvasUtility::paintIfInBounds(cs225::PNG &canvas, cs225::HSLAPixel const paint, unsigned const x, unsigned const y) {
  if (inBounds(canvas, x, y))
    canvas.getPixel(x, y) = paint;
}

void CanvasUtility::drawSquare(cs225::PNG &canvas, cs225::HSLAPixel const paint, double const squareWidth, unsigned const middle_x, unsigned const middle_y) {
  // start corner of square
  const unsigned start_x = middle_x - static_cast<unsigned>(squareWidth / 2.0);
  const unsigned start_y = middle_y - static_cast<unsigned>(squareWidth / 2.0);

  // end corner of square
  const unsigned end_x = middle_x + static_cast<unsigned>(squareWidth / 2.0);
  const unsigned end_y = middle_y + static_cast<unsigned>(squareWidth / 2.0);

  for (unsigned x = start_x; x <= end_x; x++)
    for (unsigned y = start_y; y <= end_y; y++)
      paintIfInBounds(canvas, paint, x, y);
}

void CanvasUtility::drawLine(cs225::PNG &canvas, cs225::HSLAPixel paint, double lineLength, Position position) {
  for (unsigned i = 0; i < lineLength; i++) {
    switch (position.direction) {
      case CardinalDirection::North: ++position.y; break;
      case CardinalDirection::South: --position.y; break;
      case CardinalDirection::East: ++position.x; break;
      case CardinalDirection::West: --position.x; break;
      default: return;
    }
    paintIfInBounds(canvas, paint, position.x, position.y);
  }
}

CanvasUtility::CardinalDirection CanvasUtility::reverse(CardinalDirection direction) {
  switch (direction) {
    case North: return South;
    case South: return North;
    case East: return West;
    case West: return East;
    case Null: return Null;
  }
}
