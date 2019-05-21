#include<iostream>
#include<string>
using namespace std;

int x;

class Base
{
	//protected static Scanner scan = new Scanner(System.in);
	//protected static string text;

public: static string SB1; //= "Base:SB1:PublicStaticClassLevelString! \n";
protected: static string SB2;// = "Base:SB2:ProtectedStaticClassLevelString! \n";
private: static string SB3; //= "Base:SB3:PrivateStaticClassLevelString! \n";

public: static void B1()
	{
		string S = "Base:B1():PublicStaticActiveMethodLevelString! \n";
		std::cout<<"Base::public static B1() \n";
		B2();
	}

protected: static void B2()
	{
		string S = "Base:B2():ProtectedStaticActiveMethodLevelString! \n";
		std::cout<<"Base::protected static B2() \n";
		B3();
	}

private: static void B3()
	{
		string S = "Base:B3():PrivateStaticActiveMethodLevelString! \n";
		string s1 = SB1;
		string s2 = SB2;
		string S3 = SB3;

		std::cout<<"Base::private static B3():\n cpp_3.dump \n";
		std::cin>>x;
	}

public: static void B11() { string S = "Base:B11():PublicStaticInActiveMethodLevelString! \n"; }
protected: static void B22() { string S = "Base:B22():ProtectedStaticInActiveMethodLevelString! \n"; }
private: static void B33() { string S = "Base:B33():PrivateStaticInActiveMethodLevelString! \n"; }

	//----------------------------------------------------------------------------------------
public: string sb1;// = "Base:sb1:PublicInstanceLevelString! \n";
protected: string sb2;// = "Base:sb2:ProtectedInstanceLevelString! \n";
private: string sb3;// = "Base:sb3:PrivateInstanceLevelString! \n";

public: Base(){
	sb1 = "Base:sb1:PublicInstanceLevelString! \n";
	sb2 = "Base:sb2:ProtectedInstanceLevelString! \n";
	sb3 = "Base:sb3:PrivateInstanceLevelString! \n";
}


public: void b1()
	{
		string S = "Base:b1():PublicInstanceActiveMethodLevelString! \n";
		std::cout<<"Base::public instance b1() \n";
		b2();
	}

protected: void b2()
	{
		string S = "Base:b2():ProtectedInstanceActiveMethodLevelString! \n";
		std::cout<<"Base::protected instance b2() \n";
		b3();
	}

private: void b3()
	{
		string S = "Base:b3():PrivateInstanceActiveMethodLevelString! \n";
		string s1 = sb1;
		string s2 = sb2;
		string S3 = sb3;
		std::cout<<"Base::private instance b3():\n cpp_9.dump \n";
		std::cin>>x;
	}
public: void b11() { string S = "Base:b11():PublicInstanceInActiveMethodLevelString! \n"; }
protected: void b22() { string S = "Base:b22():ProtectedInstanceInActiveMethodLevelString! \n"; }
private: void b33() { string S = "Base:b33():PrivateInstanceInActiveMethodLevelString! \n"; }

	//----------------------------------------------------------------------------------------
public: virtual void NotUsedVirtualFunc()
	{
		string S = "Base:NotUsedVirtualInstanceMethodLevelString! \n";
		std::cout<<"Base::Override Public instance NotUsedVirtualFunc() \n";
		std::cin>>x;
	}

public: virtual void usedVirtualFunc()
	{
		string S = "Base:UsedVirtualInstanceMethodLevelString! \n";
		std::cout<<"Base::Override Public instance usedVirtualFunc() \n";
		std::cin>>x;
	}
};

string Base::SB1 = "Base:SB1:PublicStaticClassLevelString! \n";
string Base::SB2 = "Base:SB2:ProtectedStaticClassLevelString! \n";
string Base::SB3 = "Base:SB3:PrivateStaticClassLevelString! \n";



class Derived1 : public Base
{

public: string sd1; //= "Derived1:sd1:PublicInstanceLevelString! \n";
protected: string sd2; //= "Derived1:sd2:ProtectedInstanceLevelString! \n";
private: string sd3; //= "Derived1:sd3:PrivateInstanceLevelString! \n";

public: Derived1(){
	sd1 = "Derived1:sd1:PublicInstanceLevelString! \n";
	sd2 = "Derived1:sd2:ProtectedInstanceLevelString! \n";
	sd3 = "Derived1:sd3:PrivateInstanceLevelString! \n";
}


public: void  NotUsedVirtualFunc()
	{
		string S = "Derived1:NotUsedVirtualInstanceMethodLevelString! \n";
		std::cout<<"Derived1::Override Public instance NotUsedVirtualFunc() \n";
		std::cin>>x;
	}

public: void  usedVirtualFunc()
	{
		string S = "Derived1:UsedVirtualInstanceMethodLevelString! \n";
		std::cout<<"Derived1::Override Public instance usedVirtualFunc() \n";
		std::cout<<"FF(): cpp_16.dump";
		std::cin>>x;
	}

public: void newFunc()
	{
		string S = "Derived1:newInstanceMethodLevelString! \n";
		std::cout<<"Derived1::new Public instance method Func():\n cpp_13.dump \n";
		std::cin>>x;
	}
};


/**
*
* @author Ziad
*/
//public
//class Program{
	//static Scanner scan = new Scanner(System.in);
	//static string text;

	//public
static void FF()
	{

		string test1 = Base::SB1;
		std::cout<<"FF(): cpp_2.dump";
		std::cin>>x;

		Base::B1();
		std::cout<<"FF(): cpp_4.dump";
		std::cin>>x;

		Base *BaseObj;
		std::cout<<"FF(): cpp_5.dump";
		std::cin>>x;

		Derived1 *DerivedObj;
		std::cout<<"FF(): cpp_6.dump";
		std::cin>>x;

		BaseObj = new Base();
		std::cout<<"FF(): cpp_7.dump";
		std::cin>>x;

		string test2 = BaseObj->sb1;
		std::cout<<"FF(): cpp_8.dump";
		std::cin>>x;

		BaseObj->b1();          // dump_9 inside base.b1()
		std::cout<<"FF(): cpp_10.dump";
		std::cin>>x;

		DerivedObj = new Derived1();
		std::cout<<"FF(): cpp_11.dump";
		std::cin>>x;

		string test3 = DerivedObj->sd1;
		std::cout<<"FF(): cpp_12.dump";
		std::cin>>x;

		DerivedObj->newFunc();  // dump_13 inside DerivedObj.newFunc()
		std::cout<<"FF(): cpp_14.dump";
		std::cin>>x;

		Base *upcastedObj;
		upcastedObj =new Derived1();
		std::cout<<"FF(): cpp_15.dump";
		std::cin>>x;

		upcastedObj->usedVirtualFunc(); // dump_16 inside DerivedObj.usedVirtualFunc()
		std::cout<<"FF(): cpp_17.dump";
		std::cin>>x;

		upcastedObj = NULL;
		std::cout<<"FF(): cpp_18.dump";
		std::cin>>x;

		delete DerivedObj;
		delete BaseObj;
		//DerivedObj = null;
		//BaseObj = null;
		//System.gc(); // in Java
		//System.GC.Collect();
		//System.GC.WaitForPendingFinalizers();

		std::cout<<"FF(): cpp_19.dump";
		std::cin>>x;
	}


	//public static
int main()
	{
		std::cout<<"Main(): cpp_1.dump";
		std::cin>>x;

		FF();
		std::cout<<"Main(): cpp_20.dump";
		std::cin>>x;


		std::cout<<"Main(): bye";
		return 0;
	}
//}

// dump_21 after program termination
