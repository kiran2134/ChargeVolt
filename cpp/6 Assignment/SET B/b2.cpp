#include <iostream>
using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    int **data;

public:
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
        }
    }

    void acceptMatrix()
    {
        cout << "Enter matrix data:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> data[i][j];
            }
        }
    }

    void displayMatrix()
    {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator-()
    {
        Matrix transpose(cols, rows);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                transpose.data[j][i] = data[i][j];
            }
        }
        return transpose;
    }

    Matrix operator*(const Matrix &m)
    {
        Matrix result(rows, m.cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < m.cols; j++)
            {
                int sum = 0;
                for (int k = 0; k < cols; k++)
                {
                    sum += data[i][k] * m.data[k][j];
                }
                result.data[i][j] = sum;
            }
        }
        return result;
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }
};

int main()
{
    int r1, c1, r2, c2;
    cout << "Enter dimensions of matrix 1: ";
    cin >> r1 >> c1;
    Matrix m1(r1, c1);
    m1.acceptMatrix();

    cout << "Enter dimensions of matrix 2: ";
    cin >> r2 >> c2;
    Matrix m2(r2, c2);
    m2.acceptMatrix();

    Matrix m3 = -m1;
    m3.displayMatrix();

    Matrix m4 = m1 * m2;
    m4.displayMatrix();
    return 0;
}