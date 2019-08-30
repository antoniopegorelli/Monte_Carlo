#include <iostream>
#include <chrono>

using namespace std;
using  ns = chrono::milliseconds;
using get_time = chrono::steady_clock;

// Função para gerar número aleatório
float random(float init, float max) {
	return init + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - init)));
}

// Função de referência do toróide
float function(float x, float y, float z) {
	return pow(z, 2) + pow(sqrt(pow(x, 2) + pow(y, 2)) - 3, 2);
}

// Função que verifica que está dentro da função
bool isToroide(float result) {
	return result <= 1;
}

int main() {
	int iterations = 10000000;				// Quantidade de iterações
	float total = 0;					// Total de pontos na função
	float current = 0;					// Variável para guardar resultado do teste atual
	float f = 0;						// Variável para o cálculo de f
	float f2 = 0;						// Variável para o cálculo de f ao quadrado
	float V = 0;						// Variável para o cálculo do volume total
	float error = 0;					// Variável para o cálculo do erro
	float result = 0;					// Variável para o resultado final
	
	// Variáveis para receber valores aleatórios
	float x = 0;
	float y = 0;
	float z = 0;

	// Variáveis de volume de teste
	float x1 = 1;
	float x2 = 4;

	float y1 = -3;
	float y2 = 4;

	float z1 = -1;
	float z2 = 1;

	// Inicia contagem de tempo de execução
	auto startTime = get_time::now();	// Tempo inicial do código

	// Loop para geração dos pontos aleatórios
	for (int i = 0; i <= iterations; i++) {
		x = random(x1, x2);
		y = random(y1, y2);
		z = random(z1, z2);

		result = function(x, y, z);

		// Verifica se o ponto de teste está dentro do toróide e atualiza valores de resultado e erro
		if (isToroide(result))
		{
			total += 1;
			f2 += pow(1, 2);
		}
	}

	// Cálculo do volume de teste
	V = (x2 - x1) * (y2 - y1) * (z2 - z1);

	// Cálculo do resultado
	result = V * (total / iterations);

	// Cálculo do erro
	f = pow((total / iterations), 2);
	f2 = f2 / iterations;
	error = V * sqrt((f2 - f) / iterations);

	// Cálculo do tempo de execução
	auto endTime = get_time::now();					// Tempo final do código
	auto totalTime = endTime - startTime;			// Tempo total do código

	// Exibição dos resultados
	cout << "Result: " << result << endl;
	cout << "Error: " << error << endl;
	cout << "Time: " << chrono::duration_cast<ns>(totalTime).count() << " ms" << endl;

	cin.get();
}
