# include <string>
#include <vector>
#pragma once
using namespace std;

// Fill in here

class Matrix {
    public:
    vector<vector <double> > mat;
    int num_row = 0;
    int num_col = 0;

    Matrix Transpose();

    Matrix operator+ (const Matrix& m);
    Matrix operator- (const Matrix& m);
    Matrix operator* (const Matrix& m);
    Matrix GetSubVectorbyColumn(int column);
    void Print();
    int GetNumRow();
    int GetNumColumn();
    double GetVal(int x, int y);
};

class DataFrame {
    public:
    vector<vector <double> > data_mat;


    int ReadData(std::string FileName, char sep, char comment, bool IsHeader);
    Matrix GetMatrix(int index[], int nColumn);
};

Matrix Cor(Matrix &mat, int method = 1);

Matrix SimpleLinearRegression(Matrix &X, Matrix &Y);