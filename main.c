#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

/* Gezegen Verileri */
const double g_verileri[] = {3.70, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15};
const char *gezegenler[] = {"Merkur", "Venus", "Dunya", "Mars", "Jupiter", "Saturn", "Uranus", "Neptun"};

/* Fonksiyon Prototipleri */
void serbestDusme(const double *ptr, char *ad);
void yukariAtis(const double *ptr, char *ad);
void agirlikDeneyi(const double *ptr, char *ad);
void potansiyelEnerji(const double *ptr, char *ad);
void hidrostatikBasinc(const double *ptr, char *ad);
void arsimetKaldirma(const double *ptr, char *ad);
void basitSarkac(const double *ptr, char *ad);
void sabitIpGerilmesi(const double *ptr, char *ad);
void asansorDeneyi(const double *ptr, char *ad);

void bufferTemizle() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char bilimInsani[100];
    int secim = 0;

    printf("Bilim insaninin adini giriniz: ");
    if (scanf("%s", bilimInsani) != 1) return 0;

    while (secim != -1) {
        printf("\n--- DENEY MENUSU (%s) ---\n", bilimInsani);
        printf("1. Serbest Dusme\n2. Yukari Atis\n3. Agirlik\n4. Potansiyel Enerji\n");
        printf("5. Hidrostatik Basinc\n6. Arsimet Kaldirma\n7. Basit Sarkac\n");
        printf("8. Ip Gerilmesi\n9. Asansor Deneyi\n-1. CIKIS\nSecim: ");
        
        if (scanf("%d", &secim) != 1) {
            bufferTemizle();
            continue;
        }

        if (secim == -1) break;

        switch (secim) {
            case 1: serbestDusme(g_verileri, bilimInsani); break;
            case 2: yukariAtis(g_verileri, bilimInsani); break;
            case 3: agirlikDeneyi(g_verileri, bilimInsani); break;
            case 4: potansiyelEnerji(g_verileri, bilimInsani); break;
            case 5: hidrostatikBasinc(g_verileri, bilimInsani); break;
            case 6: arsimetKaldirma(g_verileri, bilimInsani); break;
            case 7: basitSarkac(g_verileri, bilimInsani); break;
            case 8: sabitIpGerilmesi(g_verileri, bilimInsani); break;
            case 9: asansorDeneyi(g_verileri, bilimInsani); break;
            default: printf("Gecersiz secim!\n"); break;
        }
    }
    return 0;
}

void serbestDusme(const double *ptr, char *ad) {
    double t, h;
    int i;
    printf("Sure (s): ");
    scanf("%lf", &t);
    t = (t < 0) ? (t * -1.0) : t;
    for (i = 0; i < 8; i++) {
        h = 0.5 * (*(ptr + i)) * t * t;
        printf("%s: %.2f m\n", *(gezegenler + i), h);
    }
}

void yukariAtis(const double *ptr, char *ad) {
    double v0, hmax;
    int i;
    printf("Hiz (m/s): ");
    scanf("%lf", &v0);
    v0 = (v0 < 0) ? (v0 * -1.0) : v0;
    for (i = 0; i < 8; i++) {
        hmax = (v0 * v0) / (2.0 * (*(ptr + i)));
        printf("%s: %.2f m\n", *(gezegenler + i), hmax);
    }
}

void agirlikDeneyi(const double *ptr, char *ad) {
    double m;
    int i;
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    m = (m < 0) ? (m * -1.0) : m;
    for (i = 0; i < 8; i++) {
        printf("%s: %.2f N\n", *(gezegenler + i), (m * (*(ptr + i))));
    }
}

void potansiyelEnerji(const double *ptr, char *ad) {
    double m, h, ep;
    int i;
    printf("Kutle (kg) ve Yukseklik (m): ");
    scanf("%lf %lf", &m, &h);
    m = (m < 0) ? (m * -1.0) : m;
    h = (h < 0) ? (h * -1.0) : h;
    for (i = 0; i < 8; i++) {
        ep = m * (*(ptr + i)) * h;
        printf("%s: %.2f J\n", *(gezegenler + i), ep);
    }
}

void hidrostatikBasinc(const double *ptr, char *ad) {
    double d, h, p;
    int i;
    printf("Yogunluk (kg/m3) ve Derinlik (m): ");
    scanf("%lf %lf", &d, &h);
    d = (d < 0) ? (d * -1.0) : d;
    h = (h < 0) ? (h * -1.0) : h;
    for (i = 0; i < 8; i++) {
        p = d * (*(ptr + i)) * h;
        printf("%s: %.2f Pa\n", *(gezegenler + i), p);
    }
}

void arsimetKaldirma(const double *ptr, char *ad) {
    double d, v, fk;
    int i;
    printf("Sivi Yogunlugu (kg/m3) ve Batan Hacim (m3): ");
    scanf("%lf %lf", &d, &v);
    d = (d < 0) ? (d * -1.0) : d;
    v = (v < 0) ? (v * -1.0) : v;
    for (i = 0; i < 8; i++) {
        fk = d * (*(ptr + i)) * v;
        printf("%s: %.2f N\n", *(gezegenler + i), fk);
    }
}

void basitSarkac(const double *ptr, char *ad) {
    double l, t;
    int i;
    printf("Uzunluk (m): ");
    scanf("%lf", &l);
    l = (l < 0) ? (l * -1.0) : l;
    for (i = 0; i < 8; i++) {
        t = 2.0 * PI * sqrt(l / (*(ptr + i)));
        printf("%s: %.2f s\n", *(gezegenler + i), t);
    }
}

void sabitIpGerilmesi(const double *ptr, char *ad) {
    double m;
    int i;
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    m = (m < 0) ? (m * -1.0) : m;
    for (i = 0; i < 8; i++) {
        printf("%s: %.2f N\n", *(gezegenler + i), (m * (*(ptr + i))));
    }
}

void asansorDeneyi(const double *ptr, char *ad) {
    double m, a, n;
    int d, i;
    printf("Kutle (kg) ve Ivme (m/s2): ");
    scanf("%lf %lf", &m, &a);
    printf("Durum (1: Yukari Hizlanan, 2: Asagi Hizlanan): ");
    scanf("%d", &d);
    m = (m < 0) ? (m * -1.0) : m;
    a = (a < 0) ? (a * -1.0) : a;
    for (i = 0; i < 8; i++) {
        n = (d == 1) ? (m * (*(ptr + i) + a)) : (m * (*(ptr + i) - a));
        printf("%s: %.2f N\n", *(gezegenler + i), n);
    }
}