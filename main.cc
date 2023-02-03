#include<iostream>
#include<vector>
#include<thread>
#include<chrono>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

typedef vector<bool> Fila;
typedef vector<Fila> Matrix;

Matrix read_matrix(int m) {
    Matrix output(m, Fila(m));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if (c == '0') output[i][j] = false;
            else output[i][j] = true;
        }
    }

    return output;
}

void print_matrix(Matrix& m) {
    int matrix_size = m.size();

    cout << endl;
    for (int i = 0; i < matrix_size; ++i) {
        for (int j = 0; j < matrix_size; ++j) {
            if (m[i][j] == true) cout << "*";
            else cout << " ";
        }

        cout << endl;
    }

    cout << endl;
}

int contar_vecinos(const Matrix& m, int i, int j) {
    int matrix_size = m.size();
    int vecinos = 0;

    if (i > 0) {
        if (j > 0) if (m[i-1][j-1] == true) ++vecinos;
        if (m[i-1][j] == true) ++vecinos;
        if (j < matrix_size) if (m[i-1][j+1] == true) ++vecinos;
    }

    if (j > 0) if (m[i][j-1]) ++vecinos;

    if (j < matrix_size) if (m[i][j+1]) ++vecinos;

    if (i < matrix_size-1) {
        if (j > 0) if (m[i+1][j-1] == true) ++vecinos;
        if (m[i+1][j] == true) ++vecinos;
        if (j < matrix_size) if (m[i+1][j+1] == true) ++vecinos;
    }

    return vecinos;
}

Matrix next_step(const Matrix& m) {
    int matrix_size = m.size();
    Matrix output(3, Fila(3));
    output = m;

    for (int i = 0; i < matrix_size; ++i) {
        for (int j = 0; j < matrix_size; ++j) {
            int vecinos = contar_vecinos(m, i, j);
            if (m[i][j] == true and (vecinos != 3 and vecinos != 2)) output[i][j] = false;
            if (m[i][j] == false and vecinos == 3) output[i][j] = true;
        }
    }

    return output;
}

void clear_console() {
    cout << "\x1B[2J\x1B[H";
}

int main() {
    Matrix m(3, Fila(3));
    m = read_matrix(3);
    print_matrix(m);

    for (int i = 0; i < 10; ++i) {
        sleep_for(nanoseconds(500000000));
        clear_console();

        Matrix m2(3, Fila(3));
        m2 = next_step(m);
        print_matrix(m2);
        cout << i << endl;

        m = m2;
    }
}