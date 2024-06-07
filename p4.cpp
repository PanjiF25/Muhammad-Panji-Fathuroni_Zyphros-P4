#include <iostream>

class PersegiPanjang {
public:
    float xmin, xmax, ymin, ymax;
    
    PersegiPanjang(float xtengah, float ytengah, float panjang, float lebar) {
        xmin = (xtengah - panjang) / 2;
        xmax = (xtengah + panjang) / 2;
        ymin = (ytengah - lebar) / 2;
        ymax = (ytengah + lebar) / 2;

    }

    bool operator == (const PersegiPanjang& other) const {
        return (this->xmax > other.xmin && this->ymax > other.ymin && this->xmax < other.xmax && this->ymax < other.ymax);
    }
    
    PersegiPanjang operator + (const PersegiPanjang& other) {
        if(this->xmax > other.xmin && this->ymax > other.ymin && this->xmax < other.xmax && this->ymax < other.ymax) {
            xmin = (this->xmin + other.xmin) / 2; 
            xmax = (this->xmax + other.xmax) / 2; 
            ymin = (this->ymin + other.ymin) / 2; 
            ymax = (this->ymax + other.ymax) / 2;
            return PersegiPanjang((xmin+xmax)/2, (ymin+ymax)/2, xmax-xmin, ymax-ymin);
        } else {
            std::cout << "Persegi Panjang tidak beririsan" << std::endl;
            return PersegiPanjang(0,0,0,0);
        }

    }

    PersegiPanjang operator - (const PersegiPanjang& other) {
        if(this->xmax > other.xmin && this->ymax > other.ymin && this->xmax < other.xmax && this->ymax < other.ymax) {
            xmin = (this->xmin - other.xmin) / 2; 
            xmax = (this->xmax - other.xmax) / 2; 
            ymin = (this->ymin - other.ymin) / 2; 
            ymax = (this->ymax - other.ymax) / 2;
            return PersegiPanjang((xmin+xmax)/2, (ymin+ymax)/2, xmax-xmin, ymax-ymin);
        } else {
            std::cout << "Persegi Panjang tidak beririsan" << std::endl;
            return PersegiPanjang(0,0,0,0);
        }

    }

    PersegiPanjang& operator ++ () {
        xmin = xmin;
        xmax += (xmax - xmin); 
        ymin = ymin;
        ymax += (ymax - ymin);

        return *this;

    }

    PersegiPanjang& operator -- () {
        xmin = xmin;
        xmax -= (xmax - xmin) / 2; 
        ymin = ymin;
        ymax -= (ymax - ymin) / 2;

        return *this;

    }
    
    void info() {
        std::cout << "xmin: " << xmin << std::endl;
        std::cout << "Xmax: " << xmax << std::endl;
        std::cout << "ymin: " << ymin << std::endl;
        std::cout << "ymax: " << ymax << std::endl;

    }

    void hitungLuas() {
        std::cout << "Luas Persegi Panjang adalah " << (xmax-xmin) * (ymax-ymin) << "cm" << std::endl;
    }
};

int main() {
    PersegiPanjang pp1(0, 0, 4, 2);
    PersegiPanjang pp2(1, 1, 6, 4);

    // --pp1;
    // pp1.info();
    // pp1.hitungLuas();

    // ++pp1;
    // pp1.info();
    // pp1.hitungLuas();
    
    // bool isEqual = (pp1 == pp2);
    // if(isEqual == 1) {
    //     std::cout << "Persegi Panjang Saling Beririsan" << std::endl;
    // } else {
    //     std::cout << "Persegi Panjang tidak saling beririsan" << std::endl;
    // }

    // std::cout << "Informasi Persegi Panjang" << std::endl;
    // std::cout << "Persegi Panjang 1" << std::endl;
    // pp1.info();
    // std::cout << "Persegi Panjang 2" << std::endl;
    // pp2.info();
    // std::cout << std::endl;

    // PersegiPanjang LuasGabung = pp1 + pp2;
    // std::cout << "Informasi Persegi Panjang" << std::endl;
    // LuasGabung.info();
    // LuasGabung.hitungLuas();
    // std::cout << std::endl;

    // std::cout << "Informasi Persegi Panjang" << std::endl;
    // PersegiPanjang IrisanLuas = pp1 - pp2;
    // IrisanLuas.info();

    // std::cout << std::endl;

}