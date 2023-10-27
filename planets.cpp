#include <iostream>
#include <tuple>
#include <string>
using namespace std;

tuple<double, string> weight_convert(int planet, double weight) {
    std::tuple<double, string> r (0.0, "");
    double Earth = 9.81;
    double Mercury = 3.7;
    double Venus = 8.87;
    double Mars = 3.71;
    double Jupiter = 24.79;
    double Saturn = 10.44;
    double Uranus = 8.87;
    double Neptune = 11.15;

  if (planet < 0 || planet > 7) {
    std::cout << "That's not a planet, you dummy!\n";
    return r;
  }

  else {
    switch(planet) {
        case 1:
            get<0>(r) = weight * Mercury / Earth;
            get<1>(r) = "Mercury";
            break;
        case 2:
            get<0>(r) = weight * Venus / Earth;
            get<1>(r) = "Venus";
            break;
        case 3:
            get<0>(r) = weight * Mars / Earth;
            get<1>(r) = "Mars";
            break;
        case 4:
            get<0>(r) = weight * Jupiter / Earth;
            get<1>(r) = "Jupiter";
            break;
        case 5:
            get<0>(r) = weight * Saturn / Earth;
            get<1>(r) = "Saturn";
            break;
        case 6:
            get<0>(r) = weight * Uranus / Earth;
            get<1>(r) = "Uranus";
            break;
        case 7:
            get<0>(r) = weight * Neptune / Earth;
            get<1>(r) = "Neptune";
            break;
        }
     }
    return r;
}


int planets() {
  
    double weight;

    std::cout << "Whats your weight?\n";
    std::cin >> weight;

    int planet;
    std::cout << "1 = Mercury\n2 = Venus\n3 = Mars\n4 = Jupiter\n5 = Saturn\n6 = Uranus\n7 = Netune\nOkay, nice! Choose a planet:\n";
    std::cin >> planet;

    tuple<double, string> result;
    result = weight_convert(planet, weight);

    if (get<1>(result) == "") {
        return 0;
    }

    std::cout << "Your weight on " << get<1>(result) << " is " << get<0>(result);
    return 0;
}

extern "C" {
    int planet_convert()
    {
        return planets();
    }
}