#include <iostream>
#include <chrono>

using namespace std;
using  ns = chrono::milliseconds;
using get_time = chrono::steady_clock;

// Fun��o para gerar n�mero aleat�rio
float random(float init, float max) {
	return init + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - init)));
}

// Fun��o de refer�ncia do tor�ide
float function(float x, float y, float z) {
	return pow(z, 2) + pow(sqrt(pow(x, 2) + pow(y, 2)) - 3, 2);
}

// Fun��o que verifica que est� dentro da fun��o
bool isToroide(float result) {
	return result <= 1;
}

int main() {
	int iterations = 10000000;				// Quantidade de itera��es
	float total = 0;					// Total de pontos na fun��o
	float current = 0;					// Vari�vel para guardar resultado do teste atual
	float f = 0;						// Vari�vel para o c�lculo de f
	float f2 = 0;						// Vari�vel para o c�lculo de f ao quadrado
	float V = 0;						// Vari�vel para o c�lculo do volume total
	float error = 0;					// Vari�vel para o c�lculo do erro
	float result = 0;					// Vari�vel para o resultado final
	
	// Vari�veis para receber valores aleat�rios
	float x = 0;
	float y = 0;
	float z = 0;

	// Vari�veis de volume de teste
	float x1 = 1;
	float x2 = 4;

	float y1 = -3;
	float y2 = 4;

	float z1 = -1;
	float z2 = 1;

	// Inicia contagem de tempo de execu��o
	auto startTime = get_time::now();	// Tempo inicial do c�digo

	// Loop para gera��o dos pontos aleat�rios
	for (int i = 0; i <= iterations; i++) {
		x = random(x1, x2);
		y = random(y1, y2);
		z = random(z1, z2);

		result = function(x, y, z);

		// Verifica se o ponto de teste est� dentro do tor�ide e atualiza valores de resultado e erro
		if (isToroide(result))
		{
			total += 1;
			f2 += pow(1, 2);
		}
	}

	// C�lculo do volume de teste
	V = (x2 - x1) * (y2 - y1) * (z2 - z1);

	// C�lculo do resultado
	result = V * (total / iterations);

	// C�lculo do erro
	f = pow((total / iterations), 2);
	f2 = f2 / iterations;
	error = V * sqrt((f2 - f) / iterations);

	// C�lculo do tempo de execu��o
	auto endTime = get_time::now();					// Tempo final do c�digo
	auto totalTime = endTime - startTime;			// Tempo total do c�digo

	// Exibi��o dos resultados
	cout << "Result: " << result << endl;
	cout << "Error: " << error << endl;
	cout << "Time: " << chrono::duration_cast<ns>(totalTime).count() << " ms" << endl;

	cin.get();
}
