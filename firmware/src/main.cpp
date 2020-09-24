#include <Arduino.h>
#include "NeuralNetwork.h"

NeuralNetwork *nn;

void setup()
{
  Serial.begin(115200);
  nn = new NeuralNetwork();
}

void loop()
{
  float number1 = random(100) / 100.0;
  float number2 = random(100) / 100.0;

  nn->getInputBuffer()[0] = number1;
  nn->getInputBuffer()[1] = number2;

  float result = nn->predict();

  const char *expected = number2 > number1 ? "True" : "False";

  const char *predicted = result > 0.5 ? "True" : "False";

  Serial.printf("%.2f %.2f - result %.2f - Expected %s, Predicted %s\n", number1, number2, result, expected, predicted);

  delay(1000);
}