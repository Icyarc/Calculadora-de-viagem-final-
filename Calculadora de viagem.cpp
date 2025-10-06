#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
#include <limits>

using namespace std;

double read_double(const string& prompt) {
    double value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

void save_report(const string& report) {
    ofstream file("travel_history.txt", ios::app);
    if (file.is_open()) {
        file << report << "\n";
        file.close();
        cout << "\nTravel report saved in travel_history.txt" << endl;
    } else {
        cout << "Error while trying to save the report." << endl;
    }
}

void pause_console() {
    cout << "\nPress ENTER to close...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    double trip_distance, car_consumption, gas_price, avg_speed, budget, time_limit, tank_capacity;

    cout << fixed << setprecision(2);

    cout << "\n--- Travel Calculator ---\n";
    cout << "Enter your car and trip details:\n\n";

    trip_distance = read_double("Trip distance (km): ");
    car_consumption = read_double("Car fuel efficiency (km/l): ");
    tank_capacity = read_double("Fuel tank capacity (liters): ");
    gas_price = read_double("Gasoline price (R$/liter): ");
    avg_speed = read_double("Average speed (km/h): ");
    budget = read_double("Trip budget (R$): ");
    time_limit = read_double("Maximum allowed travel time (hours): ");

    double total_liters = trip_distance / car_consumption;
    double total_cost = total_liters * gas_price;
    double total_time = trip_distance / avg_speed;

    double total_range = car_consumption * tank_capacity;
    int fuel_stops = 0;
    if (total_range > 0) {
        fuel_stops = ceil(trip_distance / total_range) - 1;
    }
    if (fuel_stops < 0) fuel_stops = 0;

    int rest_stops = floor(total_time / 2);

    bool budget_ok = budget >= total_cost;
    bool time_ok = total_time <= time_limit;

    double eco_speed = max(40.0, avg_speed - 20);
    double eco_consumption = car_consumption * 1.10;
    double eco_cost = (trip_distance / eco_consumption) * gas_price;
    double eco_time = trip_distance / eco_speed;

    double fast_speed = avg_speed + 20;
    double fast_consumption = car_consumption * 0.90;
    double fast_cost = (trip_distance / fast_consumption) * gas_price;
    double fast_time = trip_distance / fast_speed;

    cout << "\n===== Trip Summary =====\n";
    cout << "Total travel time: " << total_time << " hours\n";
    cout << "Total fuel needed: " << total_liters << " L\n";
    cout << "Total travel cost: R$ " << total_cost << "\n";
    cout << "Fuel stops: " << fuel_stops << "\n";
    cout << "Rest stops: " << rest_stops << "\n";

    cout << "\n--- Resource Check ---\n";
    if (!budget_ok)
        cout << "-> WARNING: Not enough budget! (Missing R$ " << (total_cost - budget) << ")\n";
    else
        cout << "-> Your budget is sufficient for the trip!\n";

    if (!time_ok)
        cout << "-> WARNING: Not enough time! (Exceeds by " << (total_time - time_limit) << " h)\n";
    else
        cout << "-> You have enough time for the trip!\n";

    cout << "\n--- Alternative Route Simulation ---\n";
    cout << "1. Economy Route: Speed " << eco_speed << " km/h | Cost R$ " << eco_cost << " | Time " << eco_time << " h\n";
    cout << "2. Fast Route   : Speed " << fast_speed << " km/h | Cost R$ " << fast_cost << " | Time " << fast_time << " h\n";

    cout << "\n>>> Suggestion: ";
    if (budget_ok && time_ok) {
        cout << "Your original plan works. However, the ECONOMY ROUTE can save you R$ " << (total_cost - eco_cost) << ".\n";
    } else if (eco_cost <= budget && eco_time <= time_limit) {
        cout << "Your current plan doesn't fit, but the ECONOMY ROUTE is a good option!\n";
    } else if (fast_cost <= budget && fast_time <= time_limit) {
        cout << "Your current plan doesn't fit, but the FAST ROUTE could work!\n";
    } else {
        cout << "None of the routes fit your budget and time. Consider adjusting your plan.\n";
    }

    stringstream ss;
    ss << fixed << setprecision(2);
    ss << "Distance: " << trip_distance << " km"
       << " | Cost: R$ " << total_cost
       << " | Time: " << total_time << " h"
       << " | Fuel Stops: " << fuel_stops
       << " | Rest Stops: " << rest_stops
       << " | Budget OK: " << (budget_ok ? "Yes" : "No")
       << " | Time OK: " << (time_ok ? "Yes" : "No");

    string final_report = ss.str();

    save_report(final_report);

    pause_console();
    return 0;
}