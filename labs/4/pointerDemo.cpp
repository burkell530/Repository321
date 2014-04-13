class CoffeeShop {
public:
	CoffeeShop() {
		customerCount = 0;
	}
	
	int customerCount;
};

class Chico {
public:
	Chico() {
		temperature = 85;
	}
	
	CoffeeShop peets;
	int temperature;
};

class Gridley {
public:
	Gridley() {
		temperature = 100;
	}
	
	CoffeeShop* peets;
	int temperature;
};

void main() {
	Chico c;
	c.peets.customerCount = 100;

	Gridley g;

	g.peets = new CoffeeShop;
	g.peets->customerCount = 50;
}
