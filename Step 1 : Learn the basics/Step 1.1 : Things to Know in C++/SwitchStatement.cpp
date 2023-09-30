#include <cmath>

double areaSwitchCase(int ch, vector<double> a) {
	// Write your code here
    double r, l, b;
	switch (ch) {
        case 1:
            r = a[0];
            return M_PI * r * r;
        case 2:
            l = a[0];
            b = a[1];
            return l * b;
        default:
            return -1;
    }
}
