#ifndef MATRIZ_H_
#define MATRIZ_H_

#include <tuple>

class Matriz {
private:
	double *vectorMatriz;
	int _filas;
	int _columnas;
	char _transpuesta;

public:
	Matriz(const int filas, const int columnas);
	Matriz(Matriz& otra);
	Matriz(char* fileName);
	~Matriz();

	static Matriz* identidad(int n);
	Matriz* ceros(int n, int m);

	int filas() const;
	int columnas() const;
	void transponer();
	double &elem(const int fila, const int columna);
	void cambiarColumna(Matriz& mat, const int columna);

	double max(); // Máximo elemento de la matriz
	double min(); // Mínimo elemento de la matriz
	double rango(); // max() - min()

	Matriz* operator+(Matriz &m);
	Matriz* operator-(Matriz &m);
	Matriz* operator*(Matriz &m);
	Matriz* operator*(double k);

	Matriz* submatriz(const int desdeFil, const int hastaFil, const int desdeCol, const int hastaCol);
	Matriz* multiplicarPorInversa(Matriz &M);
	void print();
	void save(char* fileName);

	std::tuple <Matriz*, Matriz*> factorizacionHouseHolder();
	std::tuple <Matriz*, Matriz*> diagonalizacionQR(double cota);
	std::tuple <Matriz*, Matriz*> factorizacionGivens();
	Matriz* media();
	Matriz* transformarAMediaCero();
	double normaCuadradoVectorial();
	void cambiarSubmatriz(Matriz& submatriz, const int desdeFil, const int hastaFil, const int desdeCol, const int hastaCol);
	void intercambiarFilas(const int i, const int j);

private:
	double* transponerCabeza();
	void intercambiarFilas(const int i, const int j, const int hasta);
	int filaConMayorAbsEnCol(const int col, const int desde);
	double sumBajoDiagonal();
	std::tuple <Matriz*, Matriz*, Matriz*> factorizacionPLU();
	Matriz* backwardSubstitution(Matriz &b);
	Matriz* forwardSubstitution(Matriz &b);
};

#endif
