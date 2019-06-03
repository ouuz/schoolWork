#include <iostream>
#include <cstring> 
using namespace std;
class Car{
	private:
		char *brand;
		char *type;
		int year;
		double price;
	public:
		Car(char* = "undefinition", char* = "undefinition",int = 2000,double = 0);
		~Car(); 
		char* GetBrand();
		char* GetType();
		int GetYear();
		double GetPrice();
};
Car::Car(char *brandList , char *typeList ,int trueYear ,double truePrice)
{
	if(brandList){
		brand = new char [strlen(brandList)+1];
		strcpy(brand,brandList);
	}
	if(typeList){
		type = new char [strlen(typeList)+1];
		strcpy(type,typeList);
	}
	year= trueYear ;
	price = truePrice;
}
Car::~Car()
{
	delete []brand;
	delete []type;
}
char* Car::GetBrand()
{
 return brand;	
}
char* Car::GetType()
{
 return type;	
}
int  Car::GetYear()
{
 return year;	
}
double Car::GetPrice()
{
 return price;	
}

int main() 
{ 
Car car1("FIAT","Palio",2007,6.5); 
cout<<car1.GetBrand (  ) <<"|"<<car1.GetType (  ) <<"|"<<car1.GetYear (  ) <<"|" <<car1.GetPrice (  ) <<endl; 
Car car2; 
cout<<car2.GetBrand (  )<<"|"<<car2.GetType (  )<<"|"<<car2.GetYear (  ) <<"|" <<car2.GetPrice (  )<<endl; 
return 0; 
}
