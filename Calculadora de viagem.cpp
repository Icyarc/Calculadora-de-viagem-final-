#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <limits>
#include <sstream>
#include <algorithm>

using namespace std;

double ler_double(const string& prompt) {
    double value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Entrada invalida. Por favor, digite um numero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

void salvar_relatorio(const string& report) {
    ofstream file("historico_viagens.txt", ios::app);
    if (file.is_open()) {
        file << report << "\n";
        file.close();
        cout << "\nRelatorio da viagem foi salvo em historico_viagens.txt" << endl;
    } else {
        cout << "Erro ao tentar salvar o relatorio." << endl;
    }
}

void pausar_console() {
    cout << "\nPressione ENTER para fechar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    double trip_distance, car_consumption, gas_price, average_speed, budget, time_limit, tank_liters;

    cout << fixed << setprecision(2);

    cout << "\n--- Calculadora de Viagem ---\n";
    cout << "Digite os dados do seu carro e da viagem:\n\n";

    trip_distance = ler_double("Qual a distancia da viagem (km)? ");
    car_consumption = ler_double("Qual o consumo do carro (km/l)? ");
    tank_liters = ler_double("Quantos litros cabem no tanque? ");
    gas_price = ler_double("Qual o preco da gasolina (R$/litro)? ");
    average_speed = ler_double("Qual sera a velocidade media (km/h)? ");
    budget = ler_double("Qual o orcamento para a viagem (R$)? ");
    time_limit = ler_double("Qual o tempo maximo para a viagem (em horas)? ");

    double total_liters = trip_distance / car_consumption;
    double final_cost = total_liters * gas_price;
    double final_time = trip_distance / average_speed;

    double total_autonomy = car_consumption * tank_liters;
    int refuel_stops = 0;
    if (total_autonomy > 0) {
        refuel_stops = ceil(trip_distance / total_autonomy) - 1;
    }
    if (refuel_stops < 0) refuel_stops = 0;

    int rest_stops = floor(final_time / 2);

    bool is_budget_ok = budget >= final_cost;
    bool is_time_ok = final_time <= time_limit;

    double eco_speed = max(40.0, average_speed - 20);
    double eco_consumption = car_consumption * 1.10;
    double eco_cost = (trip_distance / eco_consumption) * gas_price;
    double eco_time = trip_distance / eco_speed;

    double fast_speed = average_speed + 20;
    double fast_consumption = car_consumption * 0.90;
    double fast_cost = (trip_distance / fast_consumption) * gas_price;
    double fast_time = trip_distance / fast_speed;

    cout << "\n===== Resumo do seu Plano de Viagem =====\n";
    cout << "Tempo total de viagem: " << final_time << " horas\n";
    cout << "Total de combustivel: " << total_liters << " L\n";
    cout << "Custo total da viagem: R$ " << final_cost << "\n";
    cout << "Paradas para abastecer: " << refuel_stops << "\n";
    cout << "Paradas para descanso: " << rest_stops << "\n";

    cout << "\n--- Checagem de Recursos ---\n";
    if (!is_budget_ok)
        cout << "-> ATENCAO: Vai faltar dinheiro! (Falta R$ " << (final_cost - budget) << ")\n";
    else
        cout << "-> Seu orcamento e suficiente para a viagem!\n";

    if (!is_time_ok)
        cout << "-> ATENCAO: Voce nao tem tempo suficiente! (Vai passar " << (final_time - time_limit) << " h do limite)\n";
    else
        cout << "-> O tempo e suficiente para a viagem!\n";

    cout << "\n--- Simulacao de Rotas Alternativas ---\n";
    cout << "1. Rota Economica: Vel " << eco_speed << " km/h | Custo R$ " << eco_cost << " | Tempo " << eco_time << " h\n";
    cout << "2. Rota Rapida   : Vel " << fast_speed << " km/h | Custo R$ " << fast_cost << " | Tempo " << fast_time << " h\n";

    cout << "\n>>> Minha Sugestao: ";
    if (is_budget_ok && is_time_ok) {
        cout << "Seu plano original funciona. Se quiser, a ROTA ECONOMICA pode te poupar R$ " << (final_cost - eco_cost) << ".\n";
    } else if (eco_cost <= budget && eco_time <= time_limit) {
        cout << "Seu plano nao funciona, mas a ROTA ECONOMICA e uma boa opcao!\n";
    } else if (fast_cost <= budget && fast_time <= time_limit) {
        cout << "Seu plano nao funciona, mas a ROTA RAPIDA pode ser uma alternativa!\n";
    } else {
        cout << "Nenhuma das rotas parece funcionar com seu orcamento e tempo. E melhor rever o plano.\n";
    }

    stringstream ss;
    ss << fixed << setprecision(2);
    ss << "Distancia: " << trip_distance << " km"
       << " | Custo: R$ " << final_cost
       << " | Tempo: " << final_time << " h"
       << " | Paradas Abastecer: " << refuel_stops
       << " | Paradas Descanso: " << rest_stops
       << " | Orcamento OK: " << (is_budget_ok ? "Sim" : "Nao")
       << " | Tempo OK: " << (is_time_ok ? "Sim" : "Nao");

    string final_report = ss.str();

    salvar_relatorio(final_report);

    pausar_console();
    return 0;
}


}
