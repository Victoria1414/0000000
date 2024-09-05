#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
 int n;
  cin >> n;
    
   int min_surface_area = 2 * (n + n + n);
   int best_a = 1, best_b = 1, best_c = n;
    
    for (int a = 1; a * a * a <= n; ++a) {
        if (n % a == 0) {
            for (int b = a; a * b * b <= n; ++b) {
                if (n % (a * b) == 0) {
                  int c = n / (a * b);
                   int surface_area = 2 * (a * b + a * c + b * c);
                      if (surface_area < min_surface_area) {
                         min_surface_area = surface_area;
                          best_a = a;
                          best_b = b;
                          best_c = c;
                    }
                }
            }
        }
    }
    
    int dims[] = {best_a, best_b, best_c};
     sort(dims, dims + 3);
    
    cout << dims[0] << " " << dims[1] << " " << dims[2] << endl;
    
     return 0;
}
