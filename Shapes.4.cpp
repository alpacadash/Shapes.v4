#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

class Square
{
private:
  const double side;

public:
  Square(const vector<string>& tokens): side(atof(tokens[1].c_str())){}
  Square& operator=(const Square& square)
  {
    Square& host = *this;
    if(this != &square)
    {
      const_cast<double&>(host.side)= square.side;
    }
    return *this;
  }
  void calcSquare(ofstream&) const;
};

class Rectangle
{
private:
  const double length;
  const double width;

public:
  Rectangle(const vector<string>& tokens): length(atof(tokens[1].c_str())), width(atof(tokens[2].c_str())){}
  Rectangle& operator=(const Rectangle& rectangle)
  {
    Rectangle& host = *this;
    if(this != &rectangle)
    {
      const_cast<double&>(host.length)= rectangle.length;
      const_cast<double&>(host.width)= rectangle.width;
    }
    return *this;
  }
  void calcRectangle(ofstream&) const;
};

class Circle
{
private:
  const double radius;

public:
  Circle(const vector<string>& tokens): radius(atof(tokens[1].c_str())){}
  Circle& operator=(const Circle& circle)
  {
    Circle& host = *this;
    if(this != &circle)
    {
      const_cast<double&>(host.radius)= circle.radius;
    }
    return *this;
  }
  void calcCircle(ofstream&) const;
};

class Triangle
{
private:
  const double side;

public:
  Triangle(const vector<string>& tokens): side(atof(tokens[1].c_str())){}
  Triangle& operator=(const Triangle& triangle)
  {
    Triangle& host = *this;
    if(this != &triangle)
    {
      const_cast<double&>(host.side)= triangle.side;
    }
    return *this;
  }
  void calcTriangle(ofstream&) const;
};

class Cube
{
private:
  const double side;

public:
  Cube(const vector<string>& tokens): side(atof(tokens[1].c_str())){}
  Cube& operator=(const Cube& cube)
  {
    Cube& host = *this;
    if(this != &cube)
    {
      const_cast<double&>(host.side)= cube.side;
    }
    return *this;
  }
  void calcCube(ofstream&) const;
};

class Box
{
private:
  const double length;
  const double width;
  const double height;

public:
  Box(const vector<string>& tokens): length(atof(tokens[1].c_str())), width(atof(tokens[2].c_str())), height(atof(tokens[3].c_str())){}
  Box& operator=(const Box& box)
  {
    Box& host = *this;
    if(this != &box)
    {
      const_cast<double&>(host.length)= box.length;
      const_cast<double&>(host.width)= box.width;
      const_cast<double&>(host.height)= box.height;
    }
    return *this;
  }
  void calcBox(ofstream&) const;
};

class Cylinder
{
private:
  const double radius;
  const double height;

public:
  Cylinder(const vector<string>& tokens): radius(atof(tokens[1].c_str())), height(atof(tokens[2].c_str())){}
  Cylinder& operator=(const Cylinder& cylinder)
  {
    Cylinder& host = *this;
    if(this != &cylinder)
    {
      const_cast<double&>(host.radius)= cylinder.radius;
      const_cast<double&>(host.height)= cylinder.height;
    }
    return *this;
  }
  void calcCylinder(ofstream&) const;
};

class Prism
{
private:
  const double side;
  const double height;

public:
  Prism(const vector<string>& tokens): side(atof(tokens[1].c_str())), height(atof(tokens[2].c_str())){}
  Prism& operator=(const Prism& prism)
  {
    Prism& host = *this;
    if(this != &prism)
    {
      const_cast<double&>(host.side)= prism.side;
      const_cast<double&>(host.height)= prism.height;
    }  
    return *this;
  }
  void calcPrism(ofstream&) const;
};

ostream& roundingTwo(ostream&);
ostream& roundingOff(ostream&);
vector<string> parseString(string);
const vector<const void*> bag(ifstream&, ofstream&,const vector<int>&);
void deleteBag(const vector<const void*>&,const vector<int>&);
void readBag(ofstream&,const vector<const void*>&,const vector<int>&);

int main()
{
  cout << "Programmer: Younghyun Kwon\n";
  cout << "Programmer's ID: 1651849\n";
  ifstream fin;
  ofstream fout;
  fin.open("Shapes.input.txt");
  fout.open("Shapes.output.txt");
  const vector<int> bagsType;
  const vector<const void*> bags = bag(fin,fout,bagsType);

  readBag(fout,bags,bagsType);
  deleteBag(bags,bagsType);
  fin.close();
  fout.close();
}

void Square::calcSquare(ofstream& out) const
{
  double side = this->side;
  double area = side*side;
  double perimeter = side*4;
  cout << "SQUARE side=" << side;
  out << "SQUARE side=" << side;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " perimeter=" << perimeter << endl;
  out << " area=" << area << " perimeter=" << perimeter << endl;
  roundingOff(cout);
  roundingOff(out);
}

void Rectangle::calcRectangle(ofstream& out) const
{
  double length = this->length;
  double width = this->width;
  double area = length*width;
  double perimeter = length*2 + width*2;
  cout << "RECTANGLE length=" << length << " width=" << width;
  out << "RECTANGLE length=" << length << " width=" << width;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " perimeter=" << perimeter << endl;
  out << " area=" << area << " perimeter=" << perimeter << endl;
  roundingOff(cout);
  roundingOff(out);
}

void Circle::calcCircle(ofstream& out) const
{
  double radius = this->radius;
  double area = M_PI*radius*radius;
  double perimeter = 2*M_PI*radius;
  cout << "CIRCLE radius=" << radius;
  out << "CIRCLE radius=" << radius;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " perimeter=" << perimeter << endl;
  out << " area=" << area << " perimeter=" << perimeter << endl;
  roundingOff(cout);
  roundingOff(out);
}

void Triangle::calcTriangle(ofstream& out) const
{
  double side = this->side;
  double area = (sqrt(3)*side*side)/4;
  double perimeter = 3*side;
  cout << "TRIANGLE side=" << side;
  out << "TRIANGLE side=" << side;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " perimeter=" << perimeter << endl;
  out << " area=" << area << " perimeter=" << perimeter << endl;
  roundingOff(cout);
  roundingOff(out);
}

void Cube::calcCube(ofstream& out) const
{
  double side = this->side;
  double area = side*side*6;
  double volume = side*side*side;
  cout << "CUBE side=" << side;
  out << "CUBE side=" << side;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " volume=" << volume << endl;
  out << " area=" << area << " volume=" << volume << endl;
  roundingOff(cout);
  roundingOff(out);
}

void Box::calcBox(ofstream& out) const
{
  double length = this->length;
  double width = this->width;
  double height = this->height;
  double area = length*width*2 + width*height*2 + length*height*2;
  double volume = length*width*height;
  cout << "BOX side=" << length << " width=" << width << " height=" << height;
  out << "BOX side=" << length << " width=" << width << " height=" << height;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " volume=" << volume << endl;
  out << " area=" << area << " volume=" << volume << endl;
  roundingOff(cout);
  roundingOff(out);
}

void Cylinder::calcCylinder(ofstream& out) const
{
  double radius = this->radius;
  double height = this->height;
  double area = M_PI*radius*radius*2 + height*2*M_PI*radius;
  double volume = M_PI*radius*radius*height;
  cout << "CYLINDER radius=" << radius << " height=" << height;
  out << "CYLINDER radius=" << radius << " height=" << height;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " volume=" << volume << endl;
  out << " area=" << area << " volume=" << volume << endl;
  roundingOff(cout);
  roundingOff(out);
}

void Prism::calcPrism(ofstream& out) const
{
  double side = this->side;
  double height = this->height;
  double area = (sqrt(3)*side*side*2)/4 + 3*side*height;
  double volume = (sqrt(3)*side*side*height)/4;
  cout << "PRISM side=" << side << " height=" << height;
  out << "PRISM side=" << side << " height=" << height;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " volume=" << volume << endl;
  out << " area=" << area << " volume=" << volume << endl;
  roundingOff(cout);
  roundingOff(out);
}

ostream& roundingTwo(ostream& out)
  {
    out.setf(ios::fixed);
    out.precision(2);
    return out;
  }

ostream& roundingOff(ostream& out)
  {
    out.unsetf(ios::fixed);
    out.precision(6);
    return out;
  }

vector<string> parseString(string str)
{
 stringstream s(str);
 istream_iterator<string> begin(s), end;
 return vector<string>(begin, end);
}

const vector<const void*> bag(ifstream& in, ofstream& out,const vector<int>& bagType)
{
  string shape;
  vector<string> tokens;
  const vector<const void*> myBag;
  while(!in.eof())
  {
    getline(in,shape);
    if(shape.find_first_not_of(" ") != string::npos)
    {
      tokens = parseString(shape);
      if(tokens[0] == "SQUARE")
      {
        if(tokens.size() == 1)
        {
          tokens.resize(2);
          tokens[1] = "0";
        }
        const Square* const square = new Square(tokens);
        const_cast<vector<const void*>&>(myBag).push_back(square);
        const_cast<vector<int>&>(bagType).push_back(1);
      }
      else if(tokens[0] == "RECTANGLE")
      {
        if(tokens.size() == 1)
        {
          tokens.resize(3);
          tokens[1] = "0";
          tokens[2] = "0";
        }
        if(tokens.size() == 2)
        {
          tokens.resize(3);
          tokens[2] = "0";
        }
        const Rectangle* const rectangle = new Rectangle(tokens);
        const_cast<vector<const void*>&>(myBag).push_back(rectangle);
        const_cast<vector<int>&>(bagType).push_back(2);
      }
      else if(tokens[0] == "CIRCLE")
      {
        if(tokens.size() == 1)
        {
          tokens.resize(2);
          tokens[1] = "0";
        }
        Circle* circle = new Circle(tokens);
        const_cast<vector<const void*>&>(myBag).push_back(circle);
        const_cast<vector<int>&>(bagType).push_back(3);
      }
      else if(tokens[0] == "TRIANGLE")
      {
        if(tokens.size() == 1)
        {
          tokens.resize(2);
          tokens[1] = "0";
        }
        const Triangle* const triangle = new Triangle(tokens);
        const_cast<vector<const void*>&>(myBag).push_back(triangle);
        const_cast<vector<int>&>(bagType).push_back(4);
      }
      else if(tokens[0] == "CUBE")
      {
        if(tokens.size() == 1)
        {
          tokens.resize(2);
          tokens[1] = "0";
        }
        const Cube* const cube = new Cube(tokens);
        const_cast<vector<const void*>&>(myBag).push_back(cube);
        const_cast<vector<int>&>(bagType).push_back(5);
      }
      else if(tokens[0] == "BOX")
      {
        if(tokens.size() == 1)
        {
          tokens.resize(4);
          tokens[1] = "0";
          tokens[2] = "0";
          tokens[3] = "0";
        }
        if(tokens.size() == 2)
        {
          tokens.resize(4);
          tokens[2] = "0";
          tokens[3] = "0";
        }
        if(tokens.size() == 3)
        {
          tokens.resize(4);
          tokens[3] = "0";
        }
        const Box* const box = new Box(tokens);
        const_cast<vector<const void*>&>(myBag).push_back(box);
        const_cast<vector<int>&>(bagType).push_back(6);
      }
      else if(tokens[0] == "CYLINDER")
      {
        if(tokens.size() == 1)
        {
          tokens.resize(3);
          tokens[1] = "0";
          tokens[2] = "0";
        }
        if(tokens.size() == 2)
        {
          tokens.resize(3);
          tokens[2] = "0";
        }
        const Cylinder* const cylinder = new Cylinder(tokens);
        const_cast<vector<const void*>&>(myBag).push_back(cylinder);
        const_cast<vector<int>&>(bagType).push_back(7);
      }
      else if(tokens[0] == "PRISM")
      {
        if(tokens.size() == 1)
        {
          tokens.resize(3);
          tokens[1] = "0";
          tokens[2] = "0";
        }
        if(tokens.size() == 2)
        {
          tokens.resize(3);
          tokens[2] = "0";
        }
        const Prism* const prism = new Prism(tokens);
        const_cast<vector<const void*>&>(myBag).push_back(prism);
        const_cast<vector<int>&>(bagType).push_back(8);
      }
      else if(shape.compare("EOF") == 0) break;
      else{ cout << tokens[0] << " invalid object" << endl; }
    }
  }
  return myBag;
}


void deleteBag(const vector<const void*>& myBag,const vector<int>& myBagType)
{
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 1)
    {
      const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
      delete pSquare;
    }
    else if(myBagType[i] == 2)
    {
      const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
      delete pRectangle;
    }
    else if(myBagType[i] == 3)
    {
      const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
      delete pCircle;
    }
    else if(myBagType[i] == 4)
    {
      const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
      delete pTriangle;
    }
    else if(myBagType[i] == 5)
    {
      {
        const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
        delete pCube;
      }
    }
    else if(myBagType[i] == 6)
    {
      const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
      delete pBox;
    }
    else if(myBagType[i] == 7)
    {
      const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
      delete pCylinder;
    }
    else if(myBagType[i] == 8)
    {
      const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]);
      delete pPrism;
    }
  }
}

void readBag(ofstream& out, const vector<const void*>& myBag,const vector<int>& myBagType)
{
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 1)
    {
      const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
      const Square& rSquare = *pSquare;
      rSquare.calcSquare(out);
    }
  }
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 2)
    {
      const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
      const Rectangle& rRectangle = *pRectangle;
      rRectangle.calcRectangle(out);
    }
  }
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 3)
    {
      const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
      const Circle& rCircle = *pCircle;
      rCircle.calcCircle(out);
    }
  }
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 4)
    {
      const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
      const Triangle& rTriangle = *pTriangle;
      rTriangle.calcTriangle(out);
    }
  }
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 5)
    {
      {
        const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
        const Cube& rCube = *pCube;
        rCube.calcCube(out);
      }
    }
  }
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 6)
    {
      const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
      const Box& rBox = *pBox;
      rBox.calcBox(out);
    }
  }
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 7)
    {
      const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
      const Cylinder& rCylinder = *pCylinder;
      rCylinder.calcCylinder(out);
    }
  }
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 8)
    {
      const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]);
      const Prism& rPrism = *pPrism;
      rPrism.calcPrism(out);
    }
  }
}
