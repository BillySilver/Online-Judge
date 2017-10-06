#include <stdio.h>
struct Matrix {
	int Sq[80][80], size;
	inline friend Matrix operator* (Matrix a, Matrix b) {
		int m_i, m_j, m_k;
		Matrix m;
		for (m_i=0; m_i<a.size; m_i++)
			for (m_j=0; m_j<a.size; m_j++)
				for (m.Sq[m_i][m_j]=m_k=0; m_k<a.size; m_k++)
					m.Sq[m_i][m_j] = (m.Sq[m_i][m_j] + a.Sq[m_i][m_k] * b.Sq[m_k][m_j])%10;
		m.size = a.size;
		return m;
	}
} A;

inline Matrix exp(int e) {
	if (e==1) return A;
	Matrix m = exp(e>>1);
	if (e&1) return m * m * A;
	return m * m;
}

int main() {
	int n, k, i, j;
	while (scanf("%d%d",&n,&k), n) {
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++)
				A.Sq[i][j+n] = A.Sq[i+n][j] = A.Sq[i+n][j+n] = !scanf("%d", &A.Sq[i][j]), A.Sq[i][j]%=10;
			A.Sq[i][i+n] = A.Sq[i+n][i+n] = 1;
		}
		A.size = n+n;
		A = exp(k+1);
		for (i=0; i<n; i++) {
			A.Sq[i][i+n] = (A.Sq[i][i+n]+9)%10;
			printf("%d", A.Sq[i][n]);
			for (j=1; j<n; j++)
				printf(" %d", A.Sq[i][j+n]);
			puts("");
		}
		puts("");
	}
}
