#include <stdio.h>   
#include <math.h>     


double simpson_odhad_integralu(double (*fun)(double), double a, double b, unsigned long k) {
    
    if (k % 2 != 0) {
        printf("Pocet deliacich bodov k musi byt parne cislo! Zvacsim o 1.\n");
        k++;
    }

    double h = (b - a) / k; 
    double suma = fun(a) + fun(b); 

    for (unsigned long i = 1; i < k; i++) {
        double x = a + i * h;

        if (i % 2 == 0) {
            suma += 2 * fun(x);
        } else {
            suma += 4 * fun(x);
        }
    }

    return (h / 3.0) * suma; 
}


double log7(double x) {
    return log(x) / log(7); 
}

int main() {
    unsigned long k = 1000; 

    double vysledok1 = simpson_odhad_integralu(sin, 0, 2 * M_PI, k);
    printf("Priblizny integral sin(x) od 0 do 2pi = %.10f\n", vysledok1);

    double vysledok2 = simpson_odhad_integralu(log7, 1, 7, k);
    printf("Priblizny integral log7(x) od 1 do 7 = %.10f\n", vysledok2);

    return 0;
}
