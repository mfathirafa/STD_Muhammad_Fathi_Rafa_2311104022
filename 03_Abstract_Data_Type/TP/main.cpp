#include <iostream>
#include <cmath>

class Kerucut {
private:
    double jariJari;
    double tinggi;

public:

    Kerucut(double r, double t) : jariJari(r), tinggi(t) {}

    void setJariJari(double r) {
        jariJari = r;
    }

    void setTinggi(double t) {
        tinggi = t;
    }

    double getJariJari() const {
        return jariJari;
    }

    double getTinggi() const {
        return tinggi;
    }

    double hitungLuasPermukaan() const {
        double garisPelukis = sqrt(jariJari * jariJari + tinggi * tinggi);
        return M_PI * jariJari * (jariJari + garisPelukis);
    }

    double hitungVolume() const {
        return (M_PI * jariJari * jariJari * tinggi) / 3;
    }
};

int main() {
    Kerucut kerucut(5.0, 12.0);

    std::cout << "Jari-jari kerucut: " << kerucut.getJariJari() << std::endl;
    std::cout << "Tinggi kerucut: " << kerucut.getTinggi() << std::endl;
    std::cout << "Luas permukaan kerucut: " << kerucut.hitungLuasPermukaan() << std::endl;
    std::cout << "Volume kerucut: " << kerucut.hitungVolume() << std::endl;

    return 0;
}
