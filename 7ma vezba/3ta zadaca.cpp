#include <iostream>
#include <cmath> //za funkcija kvadraten koren
using namespace std;

//Definiranje na klasa Shape so protektirani clenski promenlivi width i height
class Shape {
protected:
  float width, height;

public:
  void setDimensions(float w, float h) {
    cout << "Postavuvanje na dimenzii so ,,the parent Class,,: Shape\n";
    cout << "Dimenziite se:" << w << " i " << h << "\n\n";
    width = w;
    height = h;
  }
};

//Definiranje klasa Rectangle kako podklasa na Shape
class Rectangle: public Shape {
public:
  //Definiranje metod za presmetuvanje na perimetar na pravoagolnik
  float perimeter() {
    return 2 * (width + height);
  }
};

//Definiranje klasa Triangle kako podklasa Shape
class Triangle: public Shape {
protected:
  float hypotenuse; //protektirana promenliva za hipotenuza

public:
  //Definiranje metod za presmetuvanje na perimetar i triagolnik
  float perimeter() {
    return width + height + hypotenuse;
  }

  //Definiranje na metod za postavuvanje na hipotenuza
  void setHypotenuse() {
    hypotenuse = sqrt(width * width + height * height);
  }
};

//Definiranje klasa RightTriangle kako podklasa na Triangle
class RightTriangle: public Triangle {
public:
  //Prepisuvanje na metodata SetDimensions za da se postavi i hipotenuzata
  void setDimensions(float w, float h) {
    cout << "Postavuvanje na dimenziite so pomos na podklasata: RightTriangle\n";
    cout << "Dimenziite se: " << w << " i " << h << "\n\n";
    width = w;
    height = h;
    setHypotenuse();
  }
};

// Definiranje na glavna f-ja za pristap do clenskite promenlivi na klasata
int main() {
  cout << "===== Programa za demonstriranje na koncept na nasleduvanje vo CPP =====\n\n";
  
  Rectangle rectangle;
  RightTriangle rightTriangle;
  
  
  rectangle.setDimensions(5, 3);
  cout << "Perimetarot na pravoagolnikot e: " << rectangle.perimeter() << endl;


  rightTriangle.setDimensions(10, 5);
  cout << "Perimetarot na triagolnikot e: " << rightTriangle.perimeter() << endl;

  return 0;
} 
