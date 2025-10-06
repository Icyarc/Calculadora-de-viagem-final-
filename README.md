LINK TRELLO - https://trello.com/invite/b/68e26dbd64a4461019f6590f/ATTI5b6cf5a420e958bb82e872767c9d27e031173CD0/algoritmos-computacionais

SISTEMA DE CONSUMO DE VEÍCULOS

Centro Universitário Ateneu – UNIATENEU 
Curso: Análise e desenvolvimento de sistemas
Disciplina: Algoritmos Computacionais 
Aluno: Matheus Gonçalves Demétrio – Git hub
Matrícula: 20252116968
Aluno: Matheus Ferreira – Desenvolvedor
Matrícula: 20251110818
Aluno: Mateus Lima Monteiro – Tech Leader 
Matrícula: 20252115895
Aluno: Linconl Berg Oliveira Lopes- Documentação
matrícula: 20252116677
Aluno: João Gabriel Amorim Ximenes – Documentação 
Matrícula: 20251113790
Aluno: Keven Almeida Freires-QA
Matrícula: 20252115692

INTRODUÇÃO:
O sistema é uma aplicação em C++ usado para calcular o combustível, tempo e custo de uma viagem, simulando o impacto da variação de velocidade na eficiência do veículo ajudando pessoas que precisam se planejar ao viajar de carro equilibrando autonomia, custo e tempo
OBJETIVO:
O código calcula e planeja uma viagem de carro com base em dados informados pelo usuário, como distância, consumo, preço do combustível, orçamento e tempo disponível. Ele estima o custo, o tempo total, as paradas necessárias e compara rotas econômica e rápida, sugerindo a melhor opção.
Sugestão nos seguintes casos
Rota mais Rápida: prioriza a velocidade.
Rota mais Econômica: prioriza a eficiência.
Viagem Longa: Cálculo de paradas estratégicas
VISÃO GERAL DO CÓDIGO:
A linguagem em que o código foi escrito foi C++, A aplicação é do tipo “Aplicação em console” (roda em terminal de texto sem interface Gráfica), e é estruturado em funções modulares (organização em pequenas partes especializadas)
read_double: Usada para validação de entrada (ler números decimais do usuário garantindo que sejam válidos).
main:lógica de negócio (Onde o processamento principal acontece).
save_report: Usada para persistência de dados (salvar o resultado final, como um relatório).
Bibliotecas Utilizadas (ferramentas extras para realizar tarefas específicas)
iostream: Para entrada e saída de dados via console.
cmath: Essencial para funções matemáticas, como ceil() (arredondar para cima) e floor() (arredondar para baixo).
iomanip e sstream: Usadas para formatar a saída de dados (fixar duas casas decimais) e construir o relatório final.
Princípio Chave: O sistema utiliza lógica booleana (budget_ok e time_ok) e condicionais (if/else if) para validar as restrições do usuário e oferecer uma sugestão algorítmica da melhor rota.

FUNCIONALIDADES E REGRAS DE NEGÓCIO:
O código tem como função planejar uma viagem de carro, calculando automaticamente o tempo, o custo e as paradas necessárias. Ele também compara rotas alternativas (econômica e rápida), ajustando o consumo de combustível conforme a velocidade e sugerindo a melhor opção de viagem conforme o orçamento e o tempo disponíveis.
Modelagem de Variação de Consumo
O sistema aplica uma variação de 10% na eficiência do carro para simular diferentes rotas:
Rota Rápida: fast_consumption = car_consumption × 0.90 → penalidade de 10%, simulando velocidade +20 km/h.
Rota Econômica: eco_consumption = car_consumption × 1.10 → melhora de 10%, simulando velocidade −20 km/h.
Essas variações permitem comparar custo e tempo entre rotas mais rápidas ou mais econômicas.
Lógica de Paradas Estratégicas
O programa calcula automaticamente as paradas necessárias durante a viagem:
Autonomia Total: total_range = car_consumption × tank_capacity → distância máxima com um tanque.
Paradas para Combustível: fuel_stops = ceil(trip_distance / total_range) − 1 → número de reabastecimentos.
Paradas para Descanso: rest_stops = floor(total_time / 2) → 1 pausa a cada 2 horas de viagem.
Essas regras tornam o planejamento mais realista e seguro.
Cálculos de Custos e Tempo
O sistema realiza cálculos automáticos para estimar o custo e a duração da viagem:
Custo Total: total_cost = total_liters × gas_price → indica quanto será gasto em combustível.
Tempo Total: total_time = trip_distance / avg_speed → estima a duração da viagem.
Verificações: compara o custo com o budget e o tempo com o time_limit, indicando se a viagem é viável.
Ao final, o programa gera um relatório completo com todas as informações e salva no arquivo travel_history.txt.

ENTRADA DE DADOS:
detalha os parâmetros de entrada essenciais que o usuário deve fornecer ao sistema. Essas variáveis constituem a base para todos os cálculos subsequentes
trip_distance(Distância da Viagem(km)):Base para tempo e combustível.
car_consumption(Autonomia do Carro(km)):Base para litros e consumo alternativo.
tank_capacity(Capacidade do Tanque em Litros):Usada para calcular o número de paradas.
gas_price(Preço da Gasolina(R$/Litro)):Base para o custo total.
avg_speed(Velocidade Média Desejada(km/h)) Base para tempo e velocidades alternativas.
Budget (Orçamento para a Viagem R$):Restrição primária (Budget Check).
time_limit(Tempo Máximo Permitido em Horas):Restrição secundária (Time Check).
SAÍDA DE DADOS:
O sistena executa etapas para oferecer melhor rota
Verificação de recursos: Valida as restrições (budget_ok e time_ok) e emite alertas se o plano original falhar.
Simulação de rotas alternativas: Mostra lado a lado o Tempo e o Custo das rotas Econômica e Rápida.
Sugestão otimizada: Oferece uma recomendação algorítmica que se encaixa nas restrições do usuário.
Próxima etapa é a persistência dos dados;
Esta seção detalha como o sistema armazena o histórico das viagens realizadas:
Arquivo de Destino: O histórico de todas as viagens processadas é salvo no arquivo de texto chamado: travel_history.txt.
Conteúdo Salvo: A cada viagem, o sistema registra um resumo formatado, contendo informações cruciais para futuras análises:
Distância percorrida.
Custo total da rota.
Tempo total de viagem.
Status de atendimento das restrições de Orçamento e Tempo (indicando se o plano foi cumprido ou excedido).
DETALHAMENTO DAS FUNÇÕES:
trip_distance – Armazena a distância total da viagem, em quilômetros (km).É usada para calcular o tempo de viagem e o consumo de combustível.
 
car_consumption – Representa o consumo médio do carro, em quilômetros por litro (km/l).Serve para determinar quantos litros de combustível serão necessários.
 
tank_capacity – Indica a capacidade do tanque de combustível do carro, em litros.É usada para calcular quantas paradas para abastecer serão necessárias.
 
gas_price – Guarda o preço da gasolina por litro (R$/litro).É usada no cálculo do custo total da viagem.
 
avg_speed – Define a velocidade média prevista durante a viagem, em quilômetros por hora (km/h).Serve para calcular o tempo total da viagem.
 
budget – Representa o valor total que o usuário tem disponível para a viagem, em reais (R$).É comparado com o custo total para verificar se o orçamento é suficiente.
 
time_limit – Indica o tempo máximo permitido para a viagem, em horas.É usado para verificar se o tempo estimado está dentro do limite definido.
 
total_liters – Calcula a quantidade total de combustível necessária para a viagem (em litros).Obtido dividindo a distância total pelo consumo do carro.
 
total_cost – Armazena o custo total estimado da viagem (em reais).Obtido multiplicando o total de litros pelo preço da gasolina.
 
total_time – Guarda o tempo total estimado da viagem, em horas.Obtido dividindo a distância pela velocidade média.
 
total_range – Representa a autonomia total do carro com um tanque cheio, em quilômetros.Obtido multiplicando o consumo do carro pela capacidade do tanque.
 
fuel_stops – Indica quantas paradas para abastecer serão necessárias durante a viagem.É calculada com base na distância total e na autonomia do veículo.
 
rest_stops – Informa o número estimado de paradas para descanso, considerando pausas a cada 2 horas de viagem.
 
budget_ok – Variável lógica (booleana) que indica se o orçamento é suficiente (true) ou não (false).
 
time_ok – Variável lógica (booleana) que indica se o tempo disponível é suficiente (true) ou não (false).
 
eco_speed – Velocidade média estimada para uma rota econômica (20 km/h menor que a média, mínimo de 40 km/h).
 
eco_consumption – Consumo médio ajustado para a rota econômica (10% mais eficiente).
 
eco_cost – Custo total da viagem caso o motorista escolha a rota econômica.
 
eco_time – Tempo total da viagem pela rota econômica.
 
fast_speed – Velocidade média estimada para a rota rápida (20 km/h maior que a média).
 
fast_consumption – Consumo médio ajustado para a rota rápida (10% menos eficiente).
 
fast_cost – Custo total da viagem pela rota rápida.
 
fast_time – Tempo total da viagem pela rota rápida.
 
final_report – Texto final contendo o resumo da viagem (distância, custo, tempo, paradas, etc.), que será salvo no arquivo.

