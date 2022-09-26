#include <iostream>

using namespace std;

class HomeImprovement;
class Electronics;
class Logistics;

class Visitor {
public:
	virtual void visitHomeImprovement(HomeImprovement* company) = 0;
	virtual void visitElectronics(Electronics* company) = 0;
	virtual void visitLogistics(Logistics* company) = 0;
};


class Companies {
private:
	string name;
	double yearlyIncome;
	int noOfBranches;
	double tax = 0;
public:
	Companies(string n,double y,int no) {
		this->name = n;
		this->yearlyIncome = y;
		this->noOfBranches = no;
	}

	virtual void Accept(Visitor* visit) = 0;

	void setTax(double t) {
		this->tax = t;
		cout << this->name <<" taxes is set to " << t << endl;
	}
};


class HomeImprovement :public Companies {
public:
	HomeImprovement(string name,double yearlyIncome,int noOfBranches) : Companies(name,yearlyIncome,noOfBranches) {}
	void Accept(Visitor* visit) {
		visit->visitHomeImprovement(this);
	}
};

class Electronics :public Companies {
public:
	Electronics(string name, double yearlyIncome, int noOfBranches) : Companies(name, yearlyIncome, noOfBranches) {}
	void Accept(Visitor* visit) {
		visit->visitElectronics(this);
	}
};

class Logistics :public Companies {
public:
	Logistics(string name, double yearlyIncome, int noOfBranches) : Companies(name, yearlyIncome, noOfBranches) {}
	void Accept(Visitor* visit) {
		visit->visitLogistics(this);
	}
};

class TaxVisitor :public Visitor {
public:
	TaxVisitor() {}
	void visitHomeImprovement(HomeImprovement* company) {
		company->setTax(18);
	}
	void visitElectronics(Electronics* company) {
		company->setTax(36);
	}
	void visitLogistics(Logistics* company) {
		company->setTax(8);
	}
};

class IncomePerBranchVisitor :public Visitor {
public:
	IncomePerBranchVisitor() {}
	void visitHomeImprovement(HomeImprovement* company) {

	}

	void visitElectronics(Electronics* company) {

	}
	void visitLogistics(Logistics* company) {

	}
};

int main() {
	HomeImprovement homeImprovement("BEKO",100.0,3);
	Electronics electronics("Apple", 400.0, 40);
	Logistics logistics("ASL", 900.0, 88);

	TaxVisitor* taxVisitor = new TaxVisitor();
	IncomePerBranchVisitor* incomePerBranchVisitor = new IncomePerBranchVisitor();

	homeImprovement.Accept(taxVisitor);
	electronics.Accept(taxVisitor);
	logistics.Accept(taxVisitor);
	return 0;
}