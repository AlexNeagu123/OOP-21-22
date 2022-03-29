#include <iostream>
#include "Circuit.h"
#include "Mazda.h"
#include "Dacia.h"
#include "Mercedes.h"
#include "Toyota.h"
#include "Ford.h"
#include "Weather.h"

using namespace std;
int main() {
      Circuit c;
      c.SetLength(500);
      c.SetWeather(Weather::Snow);
      c.AddCar(new Dacia());
      c.AddCar(new Toyota());
      c.AddCar(new Mercedes());
      c.AddCar(new Ford());
      c.AddCar(new Mazda());
      c.Race();
      c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the   slowest.
      c.ShowWhoDidNotFinis(); // it is possible that some cars don't have enough fuel to finish the circuit
    return 0;
}
