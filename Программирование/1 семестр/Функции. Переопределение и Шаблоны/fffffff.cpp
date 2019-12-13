#include <iostream> 

using namespace std; 

int main() { 
int n, m, k; 
cin >> n >> m >> k; 
int **a_1 = new int *[n]; 
for (int i = 0; i < n; i++) { 
a_1[i] = new int [m]; 
} 
int **a_2 = new int *[m]; 
for (int i = 0; i < m; i++) { 
a_2[i] = new int [k]; 
} 
int **a_3 = new int *[n]; 
for (int i = 0; i < n; i++) { 
a_3[i] = new int [k]; 
} 
for (int i = 0; i < n; i++) { 
for (int j = 0; j < m; j++) { 
cin >> a_1[i][j]; 
} 
} 
for (int i = 0; i < m; i++) { 
for (int j = 0; j < k; j++) { 
cin >> a_2[i][j]; 
} 
} 
for (int i = 0; i < n; i++) { 
for (int j = 0; j < k; j++) { 
a_3[i][j] = 0; 
} 
} 
for (int i = 0; i < n; i++) { 
for (int j = 0; j < k; j++) { 
for (int l = 0; l < m; l++) { 
a_3[i][j] += a_1[i][l] * a_2[l][j]; 
} 
} 
} 
for (int i = 0; i < m; i++) { 
for (int j = 0; j < k; j++) { 
cout << a_3[i][j] << ' '; 
} 
cout << '\n'; 
} 

return 0; 
}

