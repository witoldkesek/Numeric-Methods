#include"pch.h"
#include <iostream>
#include <fstream>
class matrix
{
	int rows;
	int columns;
	
public:
	double **data;;
	matrix() {}
	matrix(int size) : matrix(size, size) {}
	matrix(int rows, int columns)
	{
		this->rows = rows;
		this->columns = columns;
		data = new double*[rows];
		for (int i = 0; i < rows; i++)
		{
			data[i] = new double[columns];
			for (int j = 0; j < columns; j++)
			{
				data[i][j] = 0;
			}
		}
	}
	bool loadData()
	{
		std::ifstream input;
		input.open("data.txt");
		if (input.good())
		{
			input >> rows;
			columns = rows + 1;
		}
		else
		{
			return false;

		}
		data = new double *[getRows()];
		for (int i = 0; i < getRows(); i++)
		{
			data[i] = new double[columns];
		}
		int i = 0, j = 0;

		while (input.good())
		{
			input >> data[i][j];
			if (j == getRows())
			{
				i++;
				j = 0;
			}
			else
			{
				j++;
			}
		}
		return true;
	}
	double **getData() 
	{
		return data;
	}
	int getRows() 
	{
		return rows;
	}
	int getColumns() 
	{
		return columns;
	}
	void drukujMacierz(const char s[]) 
	{
		std::cout << s << "\n";
		for (int i = 0; i < getRows(); i++)
		{
			for (int j = 0; j < getColumns(); j++)
			{
				std::cout << data[i][j] << "\t";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}
	matrix** generateSubmatrices() 
	{
		matrix* dolnaigorna = new matrix(getRows());
		matrix* odwroconaDiag = new matrix(getRows());
		for (int i = 0; i < getRows(); i++)
		{
			for (int j = 0; j < getRows(); j++)
			{
				dolnaigorna->getData()[i][j] = getData()[i][j];
				if (i == j) dolnaigorna->getData()[i][j] = 0;
			}
			odwroconaDiag->getData()[i][i] = 1 / getData()[i][i];
		}
		return new matrix*[2]{ dolnaigorna, odwroconaDiag };
	}
	matrix operator*( matrix& second) 
	{
		if (this->getColumns() != second.getRows())
		{
			return NULL;
		}
		matrix out(this->getRows(), second.getColumns());
		for (int i = 0; i < this->getRows(); i++)
		{
			for (int j = 0; j < second.getColumns(); j++)
			{
				for (int k = 0; k < this->getRows(); k++)
				{
					out.getData()[i][j] += this->getData()[i][k] * second.getData()[k][j];
				}
			}
		}
		/*this->drukujMacierz("Multiplication:\nFirst:");
		second.drukujMacierz("Second:");
		out.drukujMacierz("out");
		std::cin.ignore();*/
		return out;
	}
	matrix operator+(const matrix& second) 
	{
		if (this->columns != second.columns || this->rows != second.rows) return NULL;
		matrix out(rows, columns);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				out.data[i][j] = this->data[i][j] + second.data[i][j];
			}
		}
		return out;
	}
	matrix operator-()
	{
		matrix out(this->getRows(), this->getColumns());
			for (int i = 0; i < getRows(); i++)
			{
				for (int j = 0; j < getColumns(); j++)
				{
					out.getData()[i][j] = -this->getData()[i][j];
				}
			}
			return out;
	}
};
matrix jacobi( matrix& poczatkowa,  matrix& odwroconaDiag,  matrix& dolnaigorna,  matrix& prawa,  matrix& startX, int & passes, double E)//righSide refers to "free" numbers that aren't multiplied by x^n
{
	matrix nowyX = -(odwroconaDiag * (dolnaigorna) * (startX))+odwroconaDiag * (prawa);
	passes++;
	for (int i = 0; i < 500; i++)
	{
		
		nowyX = -(odwroconaDiag * (dolnaigorna) * (nowyX))+odwroconaDiag * (prawa);
		//std::cout << poczatkowa.data[0][0] * nowyX.data[0][0] + poczatkowa.data[0][1] * nowyX.data[1][0] + poczatkowa.data[0][2] * nowyX.data[2][0] <<" "<< poczatkowa.data[0][3] << "\n";
		if (abs(poczatkowa.data[0][0] * nowyX.data[0][0] + poczatkowa.data[0][1] * nowyX.data[1][0] + poczatkowa.data[0][2] * nowyX.data[2][0] -poczatkowa.data[0][3])< E && abs(poczatkowa.data[1][0] * nowyX.data[0][0] + poczatkowa.data[1][1] * nowyX.data[1][0] + poczatkowa.data[1][2] * nowyX.data[2][0] - poczatkowa.data[1][3]) < E && abs(poczatkowa.data[2][0] * nowyX.data[0][0] + poczatkowa.data[2][1] * nowyX.data[1][0] + poczatkowa.data[2][2] * nowyX.data[2][0] - poczatkowa.data[2][3]) < E)
			return nowyX;
		passes++;
	}
	return nowyX;
}
int main()
{
	matrix poczatkowa;
	if (!poczatkowa.loadData())
	{
		std::cout << "Blad ladowania danych";
		return 1;
	}
	matrix** submatrices = poczatkowa.generateSubmatrices();
	matrix dolnaigorna = *submatrices[0];
	matrix odwroconaDiag = *submatrices[1];
	matrix prawa(poczatkowa.getRows(), 1);
	for (int i = 0; i < poczatkowa.getRows(); i++)
	{
		prawa.getData()[i][0] = poczatkowa.getData()[i][poczatkowa.getColumns() - 1];
	}

	std::cout << "specify starting point\n";
	matrix startX(poczatkowa.getRows(), 1);
	for (int i = 0; i < startX.getRows(); i++)
	{
		std::cin >> startX.getData()[i][0];
	}
	poczatkowa.drukujMacierz("poczatkowa:");
	odwroconaDiag.drukujMacierz("odwroconaDiag:");
	dolnaigorna.drukujMacierz("dolnaigorna:");
	prawa.drukujMacierz("prawa:");
	startX.drukujMacierz("startX:");
	std::cout << "\nnumber of passes:\n";
	int passes=0;
	jacobi(poczatkowa, odwroconaDiag, dolnaigorna, prawa, startX, passes,(0.01)).drukujMacierz("result:");
	std::cout << "Ilosc iteracji: "<<passes;
}