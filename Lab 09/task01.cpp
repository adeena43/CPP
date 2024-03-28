#include<iostream>
using namespace std;

class Shape{
	public:
		
		virtual double area() const;
		virtual double perimeter() const;
		virtual void displayProperties() const;
		
};

class Circle:public Shape{
	protected:
		double radius;
		const double pi = 3.142;
		double diameter;
	
	public:
		Circle(){
			cout<<"Enter radius: ";
			double rad;
			cin>>rad;
			this->radius=rad;
		}		//perimeter = 2*pi*radius;
		double calcDiam()
		{
			return (2*radius);
		}
		virtual double area() const{
			return (pi*radius*radius);
		}
		virtual double perimeter() const{
			return (2*pi*radius);
		}
		virtual void displayProperties()
		{
			cout<<"Area: "<<area()<<endl;
			cout<<"Perimeter"<<perimeter()<<endl;
			cout<<"Diameter"<<calcDiam()<<endl;
		}
	
};

class Triangle:public Shape{
	protected:
		double a, b, c;
	
	public:
		Triangle(){
			double x, y, z;
			cout<<"Enter the three sides of the triangle: "<<endl;
			cin>>a;
			cin>>b;
			cin>>c;
			this->a=x;
			this->b=y;
			this->c=z;
		}
		virtual double perimeter() const{
			return (a+b+c);
		}
		virtual double area() const{
			
		}
};

class Square:public Shape{
	
};

class Rectangle:public Shape{
};

class EquilateralTriangle:public Triangle{
};

int main()
{
	cout<<"Welcome to the Geometry Competition Calculator!"<<endl;
}#include<iostream>
using namespace std;

class Shape{
	public:
		
		virtual double area() const;
		virtual double perimeter() const;
		virtual void displayProperties() const;
		
};

class Circle:public Shape{
	protected:
		double radius;
		const double pi = 3.142;
		double diameter;
	
	public:
		Circle(){
			cout<<"Enter radius: ";
			double rad;
			cin>>rad;
			this->radius=rad;
		}		//perimeter = 2*pi*radius;
		double calcDiam()
		{
			return (2*radius);
		}
		virtual double area() const{
			return (pi*radius*radius);
		}
		virtual double perimeter() const{
			return (2*pi*radius);
		}
		virtual void displayProperties()
		{
			cout<<"Area: "<<area()<<endl;
			cout<<"Perimeter"<<perimeter()<<endl;
			cout<<"Diameter"<<calcDiam()<<endl;
		}
	
};

class Triangle:public Shape{
	protected:
		double a, b, c;
	
	public:
		Triangle(){
			double x, y, z;
			cout<<"Enter the three sides of the triangle: "<<endl;
			cin>>a;
			cin>>b;
			cin>>c;
			this->a=x;
			this->b=y;
			this->c=z;
		}
		virtual double perimeter() const{
			return (a+b+c);
		}
		virtual double area() const{
			
		}
};

class Square:public Shape{
	
};

class Rectangle:public Shape{
};

class EquilateralTriangle:public Triangle{
};

int main()
{
	cout<<"Welcome to the Geometry Competition Calculator!"<<endl;
}
