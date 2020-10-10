#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct Protein
{
	int number;
	float pos[3];
};

struct Matrix
{
	double t[3];
	double u[3][3];
};

void loadProteinFile(fstream& inFile, vector<Protein>& p)
{
	Protein temp;
	if (!inFile)
	{
		cout << "File could not be opened" << endl;
	}
	char numericString[81];
	char buf[10];
	while (inFile.getline(numericString, 81, '\n')) {
		strncpy_s(buf, numericString + 22, 8);
		temp.number = (int)atoi(buf);
		for (int i = 0; i < 3; i++) {
			strncpy_s(buf, numericString + 30 + i * 8, 8);
			temp.pos[i] = (float)atof(buf);
		}
		p.push_back(temp);
	}
}

void loadMatrixFile(fstream& inFile, Matrix& m)
{
	int count = 0, num = 0;
	if (!inFile)
	{
		cout << "File could not be opened" << endl;
	}
	char numericString[90];
	char buf[16];
	while (inFile.getline(numericString, 90, '\n')) {
		count++;
		if (count > 3) {
		strncpy_s(buf, numericString + 5, 15);
		m.t[num] = (float)atof(buf);
		strncpy_s(buf, numericString + 22, 15);
		m.u[num][0] = (float)atof(buf);
		strncpy_s(buf, numericString + 38, 15);
		m.u[num][1] = (float)atof(buf);
		strncpy_s(buf, numericString + 54, 15);
		m.u[num][2] = (float)atof(buf);
		num++;
		}
		if (count > 5)
			break;
	}
}

void transfer(vector<Protein>& p, Matrix m)
{
	vector<Protein> transfered = p;
	for (int j = 0; j < p.size(); j++) {
		for (int i = 0; i < 3; i++) {
			transfered[j].pos[i] = m.t[i] + m.u[i][0] * p[j].pos[0] + m.u[i][1] * p[j].pos[1] + m.u[i][2] * p[j].pos[2];
		}
	}
	p = transfered;
}

int main(int argc, char* argv[])
{
	vector<Protein> protein;
	vector<Protein> DNA;
	vector<int> bindingSites;
	Matrix matrix;

	fstream readFileProtein(argv[1], ios::in);
	fstream readFileDNA(argv[2], ios::in);
	fstream readFileMatrix(argv[3], ios::in);

	loadProteinFile(readFileProtein, protein);
	loadProteinFile(readFileDNA, DNA);
	loadMatrixFile(readFileMatrix, matrix);
	transfer(protein, matrix);

	for (int i = 0; i < protein.size(); i++) {
		if (!bindingSites.empty() && bindingSites.back() == protein[i].number)
			continue;
		for (int j = 0; j < DNA.size(); j++) {
			if ((pow(protein[i].pos[0] - DNA[j].pos[0], 2) + pow(protein[i].pos[1] - DNA[j].pos[1], 2) + pow(protein[i].pos[2] - DNA[j].pos[2], 2)) < pow(4.5, 2)) {
				bindingSites.push_back(protein[i].number);
				break;
			}
		}
	}

	cout << bindingSites.size() << endl;
	for (int i = 0; i < bindingSites.size(); i++)
		cout << bindingSites[i] << " ";

	return 0;
}