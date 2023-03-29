#include <iostream>
#include <cmath>

using namespace std;


double function(double x) {
    
    return x * x - 2;
}


double derivative(double x) {
    
    return 2 * x;
}


double newtons_method(double x0) {
    double x = x0;
    double tolerance = 1e-8;
    int max_iterations = 1000;
    int iterations = 0;
    
    while (iterations < max_iterations) {
        double fx = function(x);
        double dfx = derivative(x);
        double dx = -fx / dfx;
        x += dx;
        iterations++;
        
        if (abs(dx) < tolerance) {
            break;
        }
    }
    
    return x;
}


double fixed_point_method(double x0) {
    double x = x0;
    double tolerance = 1e-8;
    int max_iterations = 1000;
    int iterations = 0;
    
    while (iterations < max_iterations) {
        double fx = function(x);
        double gx = x - fx;
        x = gx;
        iterations++;
        
        if (abs(gx - x) < tolerance) {
            break;
        }
    }
    
    return x;
}

int main() {
    double x0;
    cout << "Enter a value for x0: ";
    cin >> x0;
    
    double root_newton = newtons_method(x0);
    double root_fixed_point = fixed_point_method(x0);
    
    cout << "The root of the function using Newton's method is: " << root_newton << endl;
    cout << "The root of the function using fixed point method is: " << root_fixed_point << endl;
    
    return 0;
}
