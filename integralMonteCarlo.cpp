#include <iostream>
using namespace std;

// Fun��o para gerar n�mero aleat�rio
float random(float init, float max) {
	return init + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - init)));
}

// Fun��o de refer�ncia
float function(float x) {
	return 4 / (1 + pow(x, 2));
}

int main() {
	int iterations = 100000;			// Quantidade de itera��es
	float total = 0;					// Total de pontos na fun��o
	float current = 0;					// Vari�vel para guardar resultado do teste atual
	float f = 0;						// Vari�vel para o c�lculo de f
	float f2 = 0;						// Vari�vel para o c�lculo de f ao quadrado
	float V = 0;						// Vari�vel para o c�lculo do volume total
	float error = 0;					// Vari�vel para o c�lculo do erro
	float result = 0;					// Vari�vel para o resultado final

	// Vari�veis de volume de teste
	float a = 0;
	float b = 1;

	// Loop para gera��o dos pontos aleat�rios
	for (int i = 0; i <= iterations; i++) {
		current = function(random(a, b));
		total += current;					// C�lculo da resultado
		f2 += pow(current, 2);				// C�lculo do erro
	}

	// C�lculo do resultado final
	result = (b - a) * (total / iterations);

	// C�lculo do erro
	V = b - a;
	f = pow((total / iterations), 2);
	f2 = f2 / iterations;
	error = V * sqrt((f2 - f) / iterations);

	// Exibi��o dos resultados
	cout << "Result: " << result << endl;
	cout << "Error: " << error << endl;

	cin.get();
}
