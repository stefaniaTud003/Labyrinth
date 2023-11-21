#include "Matrix.h"

Matrix::Matrix()
= default;

Matrix::~Matrix()
= default;

void Matrix::SetLabyrinthMatrix(const std::vector<std::vector<uint8_t>>& newMat)
{
	m_labyrinthMatrix = newMat;
}

void Matrix::GenerateAdjacencyList()
{
	const int rows = m_labyrinthMatrix.size();
	const int cols = m_labyrinthMatrix[0].size();
	uint8_t labelCount = 1;
	std::vector<std::vector<uint8_t>> nodeLabels(rows, std::vector<uint8_t>(cols, 0));

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (m_labyrinthMatrix[i][j] != 0) 
			{
				nodeLabels[i][j] = labelCount++;
			}
		}
	}
	m_adjacencyLists.resize(labelCount);

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
		{
			if (nodeLabels[i][j] != 0)
			{
				const int currentNode = nodeLabels[i][j];

				if (i - 1 >= 0 && nodeLabels[i - 1][j] != 0)
					m_adjacencyLists[currentNode].push_back(nodeLabels[i - 1][j]);

				if (j - 1 >= 0 && nodeLabels[i][j - 1] != 0)
					m_adjacencyLists[currentNode].push_back(nodeLabels[i][j - 1]);

				if (i + 1 < rows && nodeLabels[i + 1][j] != 0)
					m_adjacencyLists[currentNode].push_back(nodeLabels[i + 1][j]);

				if (j + 1 < cols && nodeLabels[i][j + 1] != 0)
					m_adjacencyLists[currentNode].push_back(nodeLabels[i][j + 1]);

			}
		}

}

std::istream& operator>>(std::istream& matrixInput, Matrix& myMatrix)
{
	char element;
	std::vector<uint8_t> line;
    std::vector < std::vector<uint8_t>> auxMat;
	while(matrixInput.get(element))
	{
		if (std::isdigit(element)) line.emplace_back(element - '0');
		else if (element == '\n')
		{
			auxMat.emplace_back(line);
			line.clear();
		}
	}

	myMatrix.SetLabyrinthMatrix(auxMat);
	return matrixInput;
}
