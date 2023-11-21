#pragma once

#include <vector>
#include <list>
#include <iostream>

class Matrix
{
public:
	Matrix();
	~Matrix();
                                                                
	void SetLabyrinthMatrix(const std::vector < std::vector<uint8_t>>& newMat);
	void GenerateAdjacencyList();

	friend std::istream& operator >> (std::istream& matrixInput, Matrix& myMatrix);
private:
	
	std::vector<std::vector<uint8_t>> m_labyrinthMatrix;
	std::vector<std::list<uint8_t>> m_adjacencyLists;
};

