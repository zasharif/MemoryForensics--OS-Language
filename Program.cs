using System;

class Base
{
    //protected static Scanner scan = new Scanner(System.in);
    //protected static String text;

    public static String SB1 = "Base:SB1:PublicStaticClassLevelString! \n";
    protected static String SB2 = "Base:SB2:ProtectedStaticClassLevelString! \n";
    private static String SB3 = "Base:SB3:PrivateStaticClassLevelString! \n";

    public static void B1()
    {
        String S = "Base:B1():PublicStaticActiveMethodLevelString! \n";
        System.Console.WriteLine("Base::public static B1() \n");
        B2();
    }

    protected static void B2()
    {
        String S = "Base:B2():ProtectedStaticActiveMethodLevelString! \n";
        System.Console.WriteLine("Base::protected static B2() \n");
        B3();
    }

    private static void B3()
    {
        String S = "Base:B3():PrivateStaticActiveMethodLevelString! \n";
        String s1 = SB1;
        String s2 = SB2;
        String S3 = SB3;

        System.Console.WriteLine("Base::private static B3():\n csharp_3.dump \n");
        System.Console.ReadLine();
    }

    public static void B11() { String S = "Base:B11():PublicStaticInActiveMethodLevelString! \n"; }
    protected static void B22() { String S = "Base:B22():ProtectedStaticInActiveMethodLevelString! \n"; }
    private static void B33() { String S = "Base:B33():PrivateStaticInActiveMethodLevelString! \n"; }

    //----------------------------------------------------------------------------------------
    public String sb1 = "Base:sb1:PublicInstanceLevelString! \n";
    protected String sb2 = "Base:sb2:ProtectedInstanceLevelString! \n";
    private String sb3 = "Base:sb3:PrivateInstanceLevelString! \n";

    public void b1()
    {
        String S = "Base:b1():PublicInstanceActiveMethodLevelString! \n";
        System.Console.WriteLine("Base::public instance b1() \n");
        b2();
    }

    protected void b2()
    {
        String S = "Base:b2():ProtectedInstanceActiveMethodLevelString! \n";
        System.Console.WriteLine("Base::protected instance b2() \n");
        b3();
    }

    private void b3()
    {
        String S = "Base:b3():PrivateInstanceActiveMethodLevelString! \n";
        String s1 = sb1;
        String s2 = sb2;
        String S3 = sb3;
        System.Console.WriteLine("Base::private instance b3():\n csharp_9.dump \n");
        System.Console.ReadLine();
    }
    public void b11() { String S = "Base:b11():PublicInstanceInActiveMethodLevelString! \n"; }
    protected void b22() { String S = "Base:b22():ProtectedInstanceInActiveMethodLevelString! \n"; }
    private void b33() { String S = "Base:b33():PrivateInstanceInActiveMethodLevelString! \n"; }

    //----------------------------------------------------------------------------------------
    virtual public void NotUsedVirtualFunc()
    {
        String S = "Base:NotUsedVirtualInstanceMethodLevelString! \n";
        System.Console.WriteLine("Base::Override Public instance NotUsedVirtualFunc() \n");
        System.Console.ReadLine();
    }

    virtual public void usedVirtualFunc()
    {
        String S = "Base:UsedVirtualInstanceMethodLevelString! \n";
        System.Console.WriteLine("Base::Override Public instance usedVirtualFunc() \n");
        System.Console.ReadLine();
    }
}

class Derived1 : Base
{

    public String sd1 = "Derived1:sd1:PublicInstanceLevelString! \n";
    protected String sd2 = "Derived1:sd2:ProtectedInstanceLevelString! \n";
    private String sd3 = "Derived1:sd3:PrivateInstanceLevelString! \n";

    override public void  NotUsedVirtualFunc()
    {
        String S = "Derived1:NotUsedVirtualInstanceMethodLevelString! \n";
        System.Console.WriteLine("Derived1::Override Public instance NotUsedVirtualFunc() \n");
        System.Console.ReadLine();
    }

    override public void  usedVirtualFunc()
    {
        String S = "Derived1:UsedVirtualInstanceMethodLevelString! \n";
        System.Console.WriteLine("Derived1::Override Public instance usedVirtualFunc() \n");
        System.Console.WriteLine("Derived1:: csharp_16.dump");
        System.Console.ReadLine();
    }

    public void newFunc()
    {
        String S = "Derived1:newInstanceMethodLevelString! \n";
        System.Console.WriteLine("Derived1::new Public instance method Func():\n csharp_13.dump \n");
        System.Console.ReadLine();
    }
}


/**
 *
 * @author Ziad
 */
public class Program
{
    //static Scanner scan = new Scanner(System.in);
    //static String text;

    public static void FF()
    {

        String test1 = Base.SB1;
        System.Console.WriteLine("FF(): csharp_2.dump");
        System.Console.ReadLine();

        Base.B1();
        System.Console.WriteLine("FF(): csharp_4.dump");
        System.Console.ReadLine();

        Base BaseObj;
        System.Console.WriteLine("FF(): csharp_5.dump");
        System.Console.ReadLine();

        Derived1 DerivedObj;
        System.Console.WriteLine("FF(): csharp_6.dump");
        System.Console.ReadLine();

        BaseObj = new Base();
        System.Console.WriteLine("FF(): csharp_7.dump");
        System.Console.ReadLine();

        String test2 = BaseObj.sb1;
        System.Console.WriteLine("FF(): csharp_8.dump");
        System.Console.ReadLine();

        BaseObj.b1();          // dump_9 inside base.b1()
        System.Console.WriteLine("FF(): csharp_10.dump");
        System.Console.ReadLine();

        DerivedObj = new Derived1();
        System.Console.WriteLine("FF(): csharp_11.dump");
        System.Console.ReadLine();

        String test3 = DerivedObj.sd1;
        System.Console.WriteLine("FF(): csharp_12.dump");
        System.Console.ReadLine();

        DerivedObj.newFunc();  // dump_13 inside DerivedObj.newFunc()
        System.Console.WriteLine("FF(): csharp_14.dump");
        System.Console.ReadLine();

        Base upcastedObj = new Derived1();
        System.Console.WriteLine("FF(): csharp_15.dump");
        System.Console.ReadLine();

        upcastedObj.usedVirtualFunc(); // dump_16 inside DerivedObj.usedVirtualFunc()
        System.Console.WriteLine("FF(): csharp_17.dump");
        System.Console.ReadLine();

        upcastedObj = null;
        System.Console.WriteLine("FF(): csharp_18.dump");
        System.Console.ReadLine();

        DerivedObj = null;
        BaseObj = null;
        //System.gc(); // in Java
        System.GC.Collect();
        System.GC.WaitForPendingFinalizers();

        System.Console.WriteLine("FF(): csharp_19.dump");
        System.Console.ReadLine();
    }


    public static void Main(String[] args)
    {
        System.Console.WriteLine("Main(): csharp_1.dump");
        System.Console.ReadLine();

        FF();
        System.Console.WriteLine("Main(): csharp_20.dump");
        System.Console.ReadLine();


        System.Console.WriteLine("Main(): bye");
    }
}

// dump_21 after program termination
