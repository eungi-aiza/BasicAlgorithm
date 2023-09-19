#include "Matrix.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Fill in here
int DataFrame::ReadData(std::string FileName, char sep, char comment, bool IsHeader) {
    //cout << "ReadData is running" << endl;
    //vector<vector <int> > mat; //this represents the matrix.
    vector<double> v;
    string line;
    ifstream txtfile (FileName);
    string s;
    int num;
    bool firstline = true;
    if (txtfile.is_open()) {
        while(getline(txtfile, line)) {
            if (line[0] != comment) {
                if (firstline && IsHeader) {
                    //cout << "IsHeader case" << endl;
                    firstline = false;
                }
                else {
                    //cout << line << endl;
                    stringstream ss(line);
                    while (getline(ss, s, sep)) {
                        //cout << stof(s) << endl;
                        v.push_back(stof(s));
                    }
                    data_mat.push_back(v);
                    v.clear();
                }
            }
        }
        txtfile.close();
        //cout << "while loop done" << endl;
    }
    else {
        cout << "Unable to open file";
    }
    /*cout << "ReadData is done, data_mat is made" << endl;
    cout << data_mat.size() << endl;
    cout << data_mat[0].size() << endl;
    for (int i = 0; i < data_mat.size(); i++) {
        for (int j = 0; j < data_mat[i].size(); j++) {
            cout << data_mat[i][j] << " ";
        }
        cout << '\n';
    }*/
    return 0;
}

Matrix DataFrame::GetMatrix(int index[], int nColumn) {
    Matrix m;
    vector<double> v;
    m.num_row = data_mat.size();
    m.num_col = nColumn;
    for (int i = 0; i < m.num_row; ++i) {
        for (int j = 0; j < nColumn; ++j) {
            v.push_back(data_mat[i][index[j]]);
        }
        (m.mat).push_back(v);
        v.clear();
    }
    return m;
}


Matrix Matrix::Transpose() {
    Matrix m_T;
    vector<double> v;
    m_T.num_row = num_col;
    m_T.num_col = num_row;
    for (int j = 0; j < num_col; j++) {
        for (int i = 0; i < num_row; i++) {
            v.push_back(mat[i][j]);
        }
        (m_T.mat).push_back(v);
        v.clear();
    }
    return m_T;
}

Matrix Matrix::operator+ (const Matrix& rhs_m) {
    Matrix result;
    vector <double> v;
    result.num_row = num_row;
    result.num_col = num_col;
    for (int i = 0; i < num_row; i++) {
        for (int j = 0; j < num_col; j++) {
            v.push_back(mat[i][j] + (rhs_m.mat)[i][j]);
        }
        (result.mat).push_back(v);
        v.clear();
	}
    return result;
} 

Matrix Matrix::operator- (const Matrix& rhs_m) {
    Matrix result;
    vector <double> v;
    result.num_row = num_row;
    result.num_col = num_col;
    for (int i = 0; i < num_row; i++) {
        for (int j = 0; j < num_col; j++) {
            v.push_back(mat[i][j] - (rhs_m.mat)[i][j]);
        }
        (result.mat).push_back(v);
        v.clear();
	}
    return result;
} 

Matrix Matrix::operator* (const Matrix& rhs_m) {
    Matrix result;
    vector<double> v;
    int rhs_c_num = (rhs_m.mat)[0].size();  // number of columns of rhs matrix
    result.num_row = num_row;
    result.num_col = rhs_c_num;
    for (int i = 0; i < num_row; ++i) {
        for (int j = 0; j < rhs_c_num; ++j) {
            v.push_back(0);
        }
        (result.mat).push_back(v);
        v.clear();
    }

    for (int k = 0; k < rhs_c_num; ++k) {
        for (int j = 0; j < num_col; ++j) {   
            for (int i = 0; i < num_row; ++i) {
                result.mat[i][k] += mat[i][j] * (rhs_m.mat)[j][k];
            }
        }
    }

    return result;
}

Matrix Matrix::GetSubVectorbyColumn(int column) {
    Matrix result;
    vector <double> v;
    result.num_row = num_row;
    result.num_col = 1;
    for (int i = 0; i < num_row; i++) {
        v.push_back(mat[i][column]);
        (result.mat).push_back(v);
        v.clear();
	}
    return result;
}

void Matrix::Print() {
    for (int i = 0; i < num_row; i++) {
        for (int j = 0; j < num_col; j++) {
            cout << mat[i][j] << " ";
        }
        cout << '\n';
	}
}

int Matrix::GetNumRow() {
    return num_row;
}

int Matrix::GetNumColumn() {
    return num_col;
}

double Matrix::GetVal(int x, int y) {
    return mat[x][y];
}

/*double sum(Matrix v1) {
    int accum = 0;
    for (int i = 0; i < v1.GetNumRow(); ++i) {
        accum = accum + (v1.mat)[i][0];
    }
    return accum;
}*/

/*double calculate_cor(Matrix &v1, Matrix &v2) {
    double A, B, C, D;
    int n = v1.GetNumRow();
    A = n * ((((v1.Transpose())*v2).mat)[0][0]);
    B = sum(v1) * sum(v2);
    C = (n * sum((v1.Transpose())*v1)) - pow(sum(v1), 2);
    D = (n * sum((v2.Transpose())*v2)) - pow(sum(v2), 2);
    cout << A << " " << B << " " << C << " " << D << endl;
    return ((A-B) / sqrt(C*D));
}*/

// I looked at this website https://www.geeksforgeeks.org/program-find-correlation-coefficient/ to implement calculate_cor.
double pearson_cor(Matrix &v1, Matrix &v2) {
    int n = v1.GetNumRow();
    double sum_X = 0, sum_Y = 0, sum_XY = 0;
    double squareSum_X = 0, squareSum_Y = 0;
  
    for (int i = 0; i < n; i++) {
        /*cout << "check v1 values" << endl;
        cout << "(v1.mat)[i][0]: " << (v1.mat)[i][0] << endl;
        cout << "(v2.mat)[i][0]: " << (v2.mat)[i][0] << endl;*/
        sum_X = sum_X + (v1.mat)[i][0];
  
        sum_Y = sum_Y + (v2.mat)[i][0];
  
        sum_XY = sum_XY + ((v1.mat)[i][0] * (v2.mat)[i][0]);
  
        squareSum_X = squareSum_X + ((v1.mat)[i][0] * (v1.mat)[i][0]);
        squareSum_Y = squareSum_Y +  ((v2.mat)[i][0] *  (v2.mat)[i][0]);

        //cout << sum_X << " " << sum_Y << " " << sum_XY << " " << squareSum_X << " " << squareSum_Y << endl;
    }
  
    double corr = ((n * sum_XY) - (sum_X * sum_Y)) / sqrt(((n * squareSum_X) - (sum_X * sum_X)) * ((n * squareSum_Y) - (sum_Y * sum_Y)));
  
    return corr;
}


double kendall_cor(Matrix &v1, Matrix &v2) {
    double concord_num = 0;
    double discord_num = 0;
    int n = v1.GetNumRow();
    double x1, y1, x2, y2;
    //vector<int> v1_rank_vec = convert_to_rank(v1);
    //vector<int> v2_rank_vec = convert_to_rank(v2);
    for (int i = 0; i < n; ++i) {
        x1 = (v1.mat)[i][0];
        y1 = (v2.mat)[i][0];
        for (int j = i+1; j < n; ++j) {
            x2 = (v1.mat)[j][0];
            y2 = (v2.mat)[j][0];
            if ((x1 == x2) || (y1 ==y2)) {
                ++concord_num;
            }
            else if (((x1 > x2) && (y1 > y2)) || ((x1 < x2) && (y1 < y2))) {
                ++concord_num; 
            }
            else if (((x1 > x2) && (y1 < y2)) || ((x1 < x2) && (y1 > y2))) {
                ++discord_num; 
            }
        }
    }
    //cout << "concord_num: " << concord_num << endl;
    //cout << "discord_num: " << discord_num << endl;
    return ((concord_num - discord_num) / (concord_num + discord_num));
}

Matrix Cor(Matrix &mat, int method) {
    Matrix v1;
    Matrix v2;
    int n = mat.GetNumColumn();
    Matrix result;
    result.num_row = n;
    result.num_col = n;
    vector<double> v;
    if (method == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    v.push_back(1);
                }
                else {
                    //cout << i << " " << j << endl;
                    v1 = mat.GetSubVectorbyColumn(i);
                    v2 = mat.GetSubVectorbyColumn(j);
                    v.push_back(pearson_cor(v1, v2));
                    //cout << pearson_cor(v1, v2) << endl;
                }
            }
            (result.mat).push_back(v);
            v.clear();
        }
    }
    else if (method == 2) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    v.push_back(1);
                }
                else {
                    //cout << i << " " << j << endl;
                    v1 = mat.GetSubVectorbyColumn(i);
                    v2 = mat.GetSubVectorbyColumn(j);
                    v.push_back(kendall_cor(v1, v2));
                    //cout << pearson_cor(v1, v2) << endl;
                }
            }
            (result.mat).push_back(v);
            v.clear();
        }
    }
    return result;
}

Matrix SimpleLinearRegression(Matrix &X, Matrix &Y) {
    Matrix result;
    vector<double> v;
    int n = Y.num_row;
    result.num_row = 2;
    result.num_col = 1;
    double b1, b0;
    //double mean_x = (sum(X)/n);
    //double mean_y = (sum(Y)/n);

    double sum_X = 0, sum_Y = 0, sum_XY = 0;
    double squareSum_X = 0, squareSum_Y = 0;

    /*double SS_xy = 0;
    double SS_xx = 0;
    for (int i = 0; i < n; ++i) {
        SS_xy += ((X.mat)[i][0] - mean_x) * ((Y.mat)[i][0] - mean_y);
    }
    for (int i = 0; i < n; ++i) {
        SS_xx += ((X.mat)[i][0] - mean_x) * ((X.mat)[i][0] - mean_x);
    }

    b1 = SS_xy/SS_xx;*/
    for (int i = 0; i < n; ++i) {
        sum_X = sum_X + (X.mat)[i][0];
    
        sum_Y = sum_Y + (Y.mat)[i][0];
    
        sum_XY = sum_XY + ((X.mat)[i][0] * (Y.mat)[i][0]);
    
        squareSum_X = squareSum_X + ((X.mat)[i][0] * (X.mat)[i][0]);
        squareSum_Y = squareSum_Y +  ((Y.mat)[i][0] *  (Y.mat)[i][0]);
    }

    b1 = (squareSum_X*sum_Y - sum_X*sum_XY) / (n*squareSum_X - (sum_X*sum_X));
    b0 = (n*sum_XY - sum_X*sum_Y) / (n*squareSum_X - (sum_X*sum_X));


    v.push_back(b1);
    (result.mat).push_back(v);
    v.clear();
    v.push_back(b0);
    (result.mat).push_back(v);
    return result;
}