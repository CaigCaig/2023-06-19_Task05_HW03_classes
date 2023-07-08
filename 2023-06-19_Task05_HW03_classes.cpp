#include <iostream>
#include <Windows.h>
#include <string>

class Figure {
protected:
	int sides_count, a, b, c, d, A, B, C, D;
	std::string name;
public:
	Figure() {
		this->sides_count = 0;
		this->name = "Фигура";
	}
	virtual void print_info() {
		std::cout << name << ":" << std::endl;
		switch (check()) {
		case true:
			std::cout << "Правильная" << std::endl;
			break;
		case false:
			std::cout << "Неправильная" << std::endl;
			break;
		}
		std::cout << "Количество сторон: " << sides_count << std::endl;
		switch (sides_count) {
		case 3:
			std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
			std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << std::endl;
			break;
		case 4:
			std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
			std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
			break;
		}
		std::cout << std::endl;
	}
	virtual bool check() {
		if (name == "Фигура" && sides_count == 0) return true; else return false;
	}
	void set_a(int x) { this->a = x; }
	void set_b(int x) { this->b = x; }
	void set_c(int x) { this->c = x; }
	void set_d(int x) { this->d = x; }
	void set_A(int x) { this->A = x; }
	void set_B(int x) { this->B = x; }
	void set_C(int x) { this->C = x; }
	void set_D(int x) { this->D = x; }
};

class Triangle : public Figure {
public:
	Triangle() {};
	Triangle(int a, int b, int c, int A, int B, int C) {
		this->sides_count = 3;
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		this->name = "Треугольник";
	};
	virtual bool check() {
		if ((A + B + C) == 180) return true; else return false;
	}
};

class R_triangle : public Triangle {
public:
	R_triangle(int a, int b, int c, int A, int B) {
		this->sides_count = 3;
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = 90;
		this->name = "Прямоугольный треугольник";
	};
	virtual bool check() override {
		if (A == 90 && ((B + C) == 90)) return true;
		else if (B == 90 && ((A + C) == 90)) return true;
		else if (C == 90 && ((A + B) == 90)) return true;
		else return false;
	}
};

class I_triangle : public Triangle {
public:
	I_triangle(int a, int b, int A, int B) {
		this->sides_count = 3;
		this->a = a;
		this->b = b;
		this->c = a;
		this->A = A;
		this->B = B;
		this->C = A;
		this->name = "Равнобедренный треугольник";
	};
	virtual bool check() override {
		if (A + B + C == 180)
			if (a == b && A == B) return true;
			else if (a == c && A == C) return true;
			else if (b == c && B == C) return true;
			else return false;
		return false;
	}
};

class E_triangle : public Triangle {
public:
	E_triangle(int a) {
		this->sides_count = 3;
		this->a = a;
		this->b = a;
		this->c = a;
		this->A = 60;
		this->B = 60;
		this->C = 60;
		this->name = "Равносторонний треугольник";
	};
	virtual bool check() override {
		if (a == b && a == c && A == B && A == C) return true;
		else return false;
	}
};

class Quadrangle : public Figure {
public:
	Quadrangle() {};
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
		this->sides_count = 4;
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		this->name = "Четырёхугольник";
	};
	virtual bool check() override {
		if ((A + B + C + D) == 360) return true; else return false;
	}
};

class Rectangle_ : public Quadrangle {
public:
	Rectangle_(int a, int b) {
		this->sides_count = 4;
		this->a = a;
		this->b = b;
		this->c = a;
		this->d = b;
		this->A = 90;
		this->B = 90;
		this->C = 90;
		this->D = 90;
		this->name = "Прямоугольник";
	};
	virtual bool check() override {
		if (a == c && b == d && A == 90 && B == 90 && C == 90 && D == 90) return true; else return false;
	}
};

class Square : public Quadrangle {
public:
	Square(int a) {
		this->sides_count = 4;
		this->a = a;
		this->b = a;
		this->c = a;
		this->d = a;
		this->A = 90;
		this->B = 90;
		this->C = 90;
		this->D = 90;
		this->name = "Квадрат";
	};
	virtual bool check() override {
		if (a == b && a == c && a == d && A == 90 && B == 90 && C == 90 && D == 90) return true; else return false;
	}
};

class Parallelogram : public Quadrangle {
public:
	Parallelogram(int a, int b, int A, int B) {
		this->sides_count = 4;
		this->a = a;
		this->b = b;
		this->c = a;
		this->d = b;
		this->A = A;
		this->B = B;
		this->C = A;
		this->D = B;
		this->name = "Параллелограмм";
	};
	virtual bool check() override {
		if (a == c && b == d && A == C && B == D && ((A + B) == 180)) return true; else return false;
	}
};

class Rhomb : public Quadrangle {
public:
	Rhomb(int a, int A, int B) {
		this->sides_count = 4;
		this->a = a;
		this->b = a;
		this->c = a;
		this->d = a;
		this->A = A;
		this->B = B;
		this->C = A;
		this->D = B;
		this->name = "Ромб";
	};
	virtual bool check() override {
		if (a == c && a == c && a == d && A == C && B == D && ((A + B) == 180)) return true; else return false;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Figure figura;
	Triangle triangle{ 10, 20, 30, 50, 60, 70 };				// Треугольник
	R_triangle r_triangle{ 10, 20, 30, 50, 60 };				// Прямоугольный треугольник
	I_triangle i_triangle{ 10, 20, 50, 60 };					// Равнобедренный треугольник
	E_triangle e_triangle{ 30 };								// Равносторонний треугольник
	Quadrangle quadrangle{ 10, 20, 30, 40, 50, 60, 70, 80 };	// Четырёхугольник
	Rectangle_ rectangle{ 10, 20 };								// Прямоугольник
	Square square{ 20 };										// Квадрат
	Parallelogram parallelogram{ 20, 30, 30, 40 };				// Параллелограмм
	Rhomb rhomb{ 30, 30, 40 };									// Ромб

	figura.print_info();
	triangle.print_info();
	r_triangle.print_info();
	r_triangle.set_B(40);
	r_triangle.print_info();
	i_triangle.print_info();
	e_triangle.print_info();
	quadrangle.print_info();
	rectangle.print_info();
	square.print_info();
	parallelogram.print_info();
	rhomb.print_info();
	system("pause");
}