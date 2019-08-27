#include <iostream>
using namespace std;

// Função para gerar número aleatório
float random(float init, float max) {
	return init + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - init)));
}

// Função de referência
float function(float x) {
	return 4 / (1 + pow(x, 2));
}

int main() {
	int iterations = 100000;			// Quantidade de iterações
	float total = 0;					// Total de pontos na função
	float current = 0;					// Variável para guardar resultado do teste atual
	float f = 0;						// Variável para o cálculo de f
	float f2 = 0;						// Variável para o cálculo de f ao quadrado
	float V = 0;						// Variável para o cálculo do volume total
	float error = 0;					// Variável para o cálculo do erro
	float result = 0;					// Variável para o resultado final

	// Variáveis de volume de teste
	float a = 0;
	float b = 1;

	// Loop para geração dos pontos aleatórios
	for (int i = 0; i <= iterations; i++) {
		current = function(random(a, b));
		total += current;					// Cálculo da resultado
		f2 += pow(current, 2);				// Cálculo do erro
	}

	// Cálculo do resultado final
	result = (b - a) * (total / iterations);

	// Cálculo do erro
	V = b - a;
	f = pow((total / iterations), 2);
	f2 = f2 / iterations;
	error = V * sqrt((f2 - f) / iterations);

	// Exibição dos resultados
	cout << "Result: " << result << endl;
	cout << "Error: " << error << endl;

	cin.get();
}
